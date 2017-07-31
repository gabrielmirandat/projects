/*
Copyright 2010 The University of New South Wales (UNSW).

This file is part of the 2010 team rUNSWift RoboCup entry. You may
redistribute it and/or modify it under the terms of the GNU General
Public License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version as
modified below. As the original licensors, we add the following
conditions to that license:

In paragraph 2.b), the phrase "distribute or publish" should be
interpreted to include entry into a competition, and hence the source
of any derived work entered into a competition must be made available
to all parties involved in that competition under the terms of this
license.

In addition, if the authors of a derived work publish any conference
proceedings, journal articles or other academic papers describing that
derived work, then appropriate academic citations to the original work
must be included in that publication.

This rUNSWift source is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License along
with this source code; if not, write to the Free Software Foundation,
Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include "motion/MotionAdapter.hpp"

#include <boost/bind.hpp>

/*#ifdef SIMULATION
   #include "motion/touch/SimTouch.hpp"
   #include "motion/effector/SimEffector.hpp"
#else*/
   #include "motion/touch/AgentTouch.hpp"
   #include "motion/effector/AgentEffector.hpp"
//#endif
#include "motion/touch/NullTouch.hpp"
#include "motion/touch/FilteredTouch.hpp"
#include "motion/effector/NullEffector.hpp"
#include "motion/generator/ClippedGenerator.hpp"
#include "motion/generator/DistributedGenerator.hpp"
//#include "blackboard/Blackboard.hpp"
//#include "thread/Thread.hpp"
//#include "utils/Logger.hpp"
#include "utils/body.hpp"
#include "utils/incapacitated.hpp"
#include "types/AbsCoord.hpp"
#include "types/ActionCommand.hpp"
#include "types/JointValues.hpp"
#include "types/SensorValues.hpp"
#include "utils/Timer.hpp"

#include <qi/log.hpp>

#define SENSOR_LAG 6 // buffer the sensors/pose by 8 motion ticks and it synchronises well with vision

using namespace std;

void construct(Touch** touch, std::string name) {
  /*#ifdef SIMULATION
      if (name == "Sim") *touch = (Touch*) new SimTouch();
  #else*/
      if (name == "Agent") *touch = (Touch*) new AgentTouch();
  //#endif
   if (name == "Null") *touch = (Touch*) new NullTouch();
   if (*touch == NULL)
      qiLogFatal("Motion") << "MotionAdapter: NULL " + name + "Touch" << endl;
}

void construct(Effector** effector, std::string name) {
  /*#ifdef SIMULATION
      if (name == "Sim") *effector = (Effector*) new SimEffector();
  #else*/
      if (name == "Agent") *effector = (Effector*) new AgentEffector();
  //#endif
   if (name == "Null") *effector = (Effector*) new NullEffector();
   if (*effector == NULL)
      qiLogFatal("Motion") << "MotionAdapter: NULL " + name + "Effector" << endl;
}

/*-----------------------------------------------------------------------------
 * Motion thread constructor
 *---------------------------------------------------------------------------*/
MotionAdapter::MotionAdapter(const boost::program_options::variables_map& config /*Blackboard *bb*/)
   : /*Adapter(bb),*/ uptime(0) {
   qiLogInfo("Motion") << "Constructing MotionAdapter" << endl;

   sensorBuffer.clear();

   // We only construct the NullTouch/Generators, the rest are done on demand
   touches["Null"] = (Touch*)(new NullTouch());
   if (touches["Null"] == NULL) {
      qiLogFatal("Motion") << "MotionAdapter: NULL NullTouch" << endl;
   }

/*#ifdef SIMULATION
   touches["Sim"] = (Touch*)(NULL);
#else*/
   touches["Agent"] = (Touch*)(NULL);
//#endif

   nakedTouch = touches["Null"];
   touch = (Touch*) new FilteredTouch(touches["Null"]);

   generator = (Generator*) new ClippedGenerator(
      (Generator*) new DistributedGenerator(/*bb*/));
   if (generator == NULL) {
      qiLogFatal("Motion") << "MotionAdapter: NULL Generator" << endl;
   }

   effectors["Null"] = (Effector*)(new NullEffector());
   if (effectors["Null"] == NULL) {
      qiLogFatal("Motion") << "MotionAdapter: NULL NullEffector" << endl;
   }
#ifdef SIMULATION
   effectors["Sim"] = (Effector*)(NULL);
#else
   effectors["Agent"] = (Effector*)(NULL);
#endif
   effector = effectors["Null"];

   readOptions(config);
   touch->readOptions(config); // XXX: Do NOT put this in readOptions or robot will fall

   //writeTo(thread, configCallbacks[Thread::name],
   //        boost::function<void(const boost::program_options::variables_map &)>
   //        (boost::bind(&MotionAdapter::readOptions, this, _1)));

   KinematicsParameters kinParam;
   //kinematics.parameters = readFrom(kinematics, parameters);
   kinematics.parameters.cameraPitchTop = kinParam.cameraPitchTop;
   kinematics.parameters.cameraYawTop = kinParam.cameraYawTop;
   kinematics.parameters.cameraRollTop = kinParam.cameraRollTop;
   kinematics.parameters.cameraYawBottom = kinParam.cameraYawBottom;
   kinematics.parameters.cameraPitchBottom = kinParam.cameraPitchBottom;
   kinematics.parameters.cameraRollBottom = kinParam.cameraRollBottom;
   kinematics.parameters.bodyPitch = kinParam.bodyPitch;

   //Initializing buttons
   ButtonData buttons;
   buttons.button.clear();
   buttonBoard.save(buttons);

   //Inicializing Sonar
   sonarRaw sonar;
  std::vector<int> left;
  std::vector<int> middle;
  std::vector<int> right;
  left.reserve(Sonar::NUMBER_OF_READINGS/2*WINDOW_SIZE);
  middle.reserve(Sonar::NUMBER_OF_READINGS/2*WINDOW_SIZE);
  right.reserve(Sonar::NUMBER_OF_READINGS/2*WINDOW_SIZE);

  sonar.sonarWindow.reserve(3);
  sonar.sonarWindow.push_back(left);
  sonar.sonarWindow.push_back(middle);
  sonar.sonarWindow.push_back(right);

  sonarRawBoard.save(sonar);


   qiLogInfo("Motion") << "MotionAdapater constructed" << std::endl;
}

/*-----------------------------------------------------------------------------
 * Motion thread destructor
 *---------------------------------------------------------------------------*/
MotionAdapter::~MotionAdapter() {
   qiLogInfo("Motion") << "Destroying MotionAdapter" << endl;

   //writeTo(thread, configCallbacks[Thread::name], boost::function<void(const boost::program_options::variables_map &)>());

   for (std::map<std::string, Touch*>::iterator it = touches.begin();
        it != touches.end(); it++) {
      delete it->second;
   }

   delete generator;

   for (std::map<std::string, Effector*>::iterator it = effectors.begin();
        it != effectors.end(); it++) {
      delete it->second;
   }
}

/*-----------------------------------------------------------------------------
 * read motion options
 *---------------------------------------------------------------------------*/
void MotionAdapter::readOptions(const boost::program_options::variables_map& config) {
   std::string e = config["motion.effector"].as<string>();
   std::string t = config["motion.touch"].as<string>();
   qiLogInfo("Motion") << "MotionAdapter using effector " << e << " and touch " << t;

   // Look through the list of touches for the one requested,
   // initialize it if it exists.
   if (touches.count(t)) {
      if (touches[t] == NULL) {
         construct(&touches[t], t);
      }
      nakedTouch = touches[t];
      touch = (Touch*) new FilteredTouch(touches[t]);
   }

   // Look through the list of effectors for the one requested,
   // initialize it if it exists.
   if (effectors.count(e)) {
      if (effectors[e] == NULL) { 
         construct(&effectors[e], e);
      }
      effector = effectors[e];
   }

   // Read the generator options
   generator->readOptions(config);
}

/*-----------------------------------------------------------------------------
 * Motion thread tick function
 *---------------------------------------------------------------------------*/
void MotionAdapter::tick() {
   Timer t;

   // Get the motion request from behaviours
   CommandIndex index = indexBoard.load();
   Command command;
   if(index.index)
   {
       command = CommandBoard1.load();
   }
   else
   {
       command = CommandBoard0.load();
   }
   //ActionCommand::All request = readFrom(behaviour, request[behaviourReadBuf]).actions;
   ActionCommand::All request(command.head, command.body, command.leds, command.sonar);
   // Get sensor information from kinematics
   SensorValues sensors;
   /*if(request.body.actionType == Body::MOTION_CALIBRATE){
       // raw sensor values are sent to offnao for calibration
       // these values are straight forward copy paste into pos files
       sensors = nakedTouch->getSensors(kinematics);
       sensors.sensors[Sensors::InertialSensor_AngleX] = -RAD2DEG(sensors.sensors[Sensors::InertialSensor_AngleX]);
       sensors.sensors[Sensors::InertialSensor_AngleY] = -RAD2DEG(sensors.sensors[Sensors::InertialSensor_AngleY]);
       sensors.sensors[Sensors::InertialSensor_GyrX] = -sensors.sensors[Sensors::InertialSensor_GyrX];
       sensors.sensors[Sensors::InertialSensor_GyrY] = -sensors.sensors[Sensors::InertialSensor_GyrY];
   } else {*/
       sensors = touch->getSensors(kinematics);
   //}

   sensorBoard.save(sensors);

   // For kinematics, give it the lagged sensorValues with the most recent lean angles (because they already
   // have a lag in them) unless it's the very first one otherwise it will propagate nans everywhere
   SensorValues sensorsLagged;
   if (sensorBuffer.size() > 0) {
      sensorsLagged = sensorBuffer.back(); 
   } else {
      sensorsLagged = sensors; 
   }
   sensorsLagged.sensors[Sensors::InertialSensor_AngleX] = sensors.sensors[Sensors::InertialSensor_AngleX];
   sensorsLagged.sensors[Sensors::InertialSensor_AngleY] = sensors.sensors[Sensors::InertialSensor_AngleY];
   kinematics.setSensorValues(sensorsLagged);
   /*KinematicsParameters kinParam;
   //kinematics.parameters = readFrom(kinematics, parameters);
   kinematics.parameters.cameraPitchTop = kinParam.cameraPitchTop;
   kinematics.parameters.cameraYawTop = kinParam.cameraYawTop;
   kinematics.parameters.cameraRollTop = kinParam.cameraRollTop;
   kinematics.parameters.cameraYawBottom = kinParam.cameraYawBottom;
   kinematics.parameters.cameraPitchBottom = kinParam.cameraPitchBottom;
   kinematics.parameters.cameraRollBottom = kinParam.cameraRollBottom;
   kinematics.parameters.bodyPitch = kinParam.bodyPitch;*/
   // Calculate the Denavit-Hartenberg chain
   kinematics.updateDHChain();
   //writeTo(motion, pose, kinematics.getPose()); //Not necessary

   bool standing = touch->getStanding();
   ButtonData buttonData;
   buttonData.button = touch->getButtons(); //Figure this out
   qiLogVerbose("Motion") << "touch->getSensors took "
                 << t.elapsed_ms() << "ms" << std::endl;
   t.restart();

   // Keep a running time for standing
   if (standing) {
      uptime = 0.0f;
   } else {
      uptime += 0.01f;
   }
   /*writeTo(motion, uptime, uptime); //Not necessary

    //Sensors are lagged so it correctly synchronises with vision
   sensorBuffer.insert(sensorBuffer.begin(), sensors);
   writeTo(motion, sensors, sensors); //Lagged); //Change in here and KinematicsCalibrationSkill.cpp
   writeTo(kinematics, sensorsLagged, sensorsLagged); //Not Necessary. Used in vision
   std::cout << "live = " << sensors.joints.angles[Joints::HeadYaw]
             << " delayed = " << sensorsLagged.joints.angles[Joints::HeadYaw]
             << std::endl;

   if (sensorBuffer.size() > SENSOR_LAG) {
      sensorBuffer.pop_back();
   }*/

   // sonar recorder gets and update and returns the next sonar request
   request.sonar = sonarRecorder.update(sensors.sonar);
   sonarRaw sonarRawData;
   sonarRawData.sonarWindow = sonarRecorder.sonarWindow;
   sonarRawBoard.save(sonarRawData);
   //writeTo(motion, sonarWindow, sonarRecorder.sonarWindow); //Adapt for our way -> Done

   if (isIncapacitated(request.body.actionType)) {
      qiLogInfo("Motion") << "Incapacitated" << std::endl;
      uptime = 0.0f;
   }
   buttonData.button |= (buttonBoard.load()).button; //Figure buttons out
   buttonBoard.save(buttonData);
   //writeTo(motion, buttons, buttons); //Not necessary i think. Only for Game controller. Check later.

   qiLogVerbose("Motion") << "writeTo / readFrom took "
                 << t.elapsed_ms() << "ms" << std::endl;
   t.restart();

   if (standing) {
      qiLogInfo("Motion") << "Is Standing" << std::endl;
      generator->reset();
      request.body = ActionCommand::Body::INITIAL;
      odometry.clear();
   }

   // Get the position of the ball in robot relative cartesian coordinates
   
   /*AbsCoord robotPose = readFrom(localisation, robotPos); //Use dummy values, later get real values from our modules
   AbsCoord ballAbs = readFrom(localisation, ballPos);//Use dummy values, later get real values from our modules
   AbsCoord ball = ballAbs.convertToRobotRelativeCartesian(robotPose);//Use dummy values, later get real values from our modules*/
   AbsCoord ball(command.body.ballX, command.body.ballY, 0.0);

   // Update the body model
   bodyModel.kinematics = &kinematics;
   bodyModel.update(&odometry, sensors);
   // Get the joints requested by whichever generator we're using
   JointValues joints = generator->makeJoints(&request, &odometry, sensors, bodyModel, ball.x(), ball.y());

   // Save the body model Center of Mass
   /*writeTo(motion, com, bodyModel.getCoM()); //Not necessary. Offnao only

   writeTo(motion, active, request); //Not necessary. Localization and offnao only. Check later

    Odometry is lagged by walk's estimations, and it also correctly synchronises with vision

   writeTo(motion, odometry, Odometry(odometry)); //Change for conversion of our data

    Save the pendulum model
   writeTo(motion, pendulumModel, bodyModel.getPendulumModel()); //Not Necessary. Offnao only
   qiLogVerbose("Motion") << "generator->makeJoints took "
                 << t.elapsed_ms() << "ms" << std::endl;*/
   //odometryBoard.save(Odometry(odometry));
   t.restart();

   // Actuate joints as requested.
   effector->actuate(joints, request.leds, request.sonar);
   qiLogVerbose("Motion") << "effector->actuate took "
                 << t.elapsed_ms() << "ms" << std::endl;
}

