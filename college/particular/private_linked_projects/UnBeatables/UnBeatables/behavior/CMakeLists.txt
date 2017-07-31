cmake_minimum_required(VERSION 2.8)
project(behavior)

#########################################################
# FINDING QIBUILD
#########################################################
find_package(qibuild)

#########################################################
# INCLUDE DIRECTORIES
#########################################################
get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} PATH)
include_directories(
${CMAKE_CURRENT_SOURCE_DIR}/include
${PARENT_DIR}/common
${PARENT_DIR}/motion_integracao/runswift
)

#########################################################
# INCLUDE FILES
#########################################################
set(SOURCES
  ${PARENT_DIR}/common/motionAuxiliarFunctions.cpp
  ${PARENT_DIR}/common/ledAuxiliarFunctions.cpp
  ${PARENT_DIR}/common/motionData.cpp
  "src/Sonar.cpp"
  "src/turnLeft.cpp"
  "src/GmCtrlPenalized.cpp"
  "src/GmCtrlInitial.cpp"
  "src/refPickup.cpp"
  "src/Start.cpp"
  "src/walk.cpp"
  "src/ReadyMachine.cpp"
  "src/getUpBack.cpp"
  "src/GmCtrlSet.cpp"
  "src/getUpFront.cpp"
  "src/GmCtrlReady.cpp"
  #"src/Align.cpp"
  "src/Kick.cpp"
  "src/turnRight.cpp"
  "src/deadStiffness.cpp"
  "src/sonarMiddle.cpp"
  #"src/turnToBall.cpp"
  "src/behavior.cpp"
  #"src/walkToBall.cpp"
  "src/sonarRight.cpp"
  "src/BehaviorBase.cpp"
  "src/LookForBall.cpp"
  "src/GmCtrlPlaying.cpp"
  #"src/seekBall.cpp"
  "src/GmCtrlFinished.cpp"
  #"src/newWalk.cpp"
  "src/sonarLeft.cpp"
  "src/stayStill.cpp"
  "src/vira90.cpp"
	)

set(MATADOR_SRC
    src/matador.cpp
    )
# Note: We do not recommend using GLOB to collect a list of source files from your source tree. If no CMakeLists.txt
# file changes when a source is added or removed then the generated build system cannot know when to ask CMake to regenerate.

# The main file
qi_create_bin(${PROJECT_NAME} main.cpp ${SOURCES})
qi_use_lib(${PROJECT_NAME} ALCOMMON ALPROXIES BOOST)

#matador binary
qi_create_bin(matador ${MATADOR_SRC})
qi_use_lib(matador ALCOMMON ALPROXIES BOOST)

#########################################################
# OTHER THINGS
#########################################################
#Disable BOOST Useless warning
add_definitions(-DBOOST_SIGNALS_NO_DEPRECATION_WARNING)
