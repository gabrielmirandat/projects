++++++++++++++++++++++++++++++++++++++++++++++MATLAB++++++++++++++++++++++++++++++++++++++++++++++
se2 = create homogeneous transformation
/*T1 = se2(1, 2, 30*pi/180)*/ represents a translation of (1, 2) and a rotation of 30°.
							  returns the transformation matrix.
trplot2	= to draw coordinate frames in 2d 
/*trplot2(T3, 'frame', '3', 'color', 'g');*/
//e2h converts Euclidean coordinates to homogeneous and h2e performs the inverse conversion. 
rotx = returns the orthonormal rotation matrices when rotating 
/*R = rotx(pi/2)*/
trplot = to draw coordinate frames in 3d 
/*trplot(R)*/
tranimate = to animate a rotation 
/*tranimate(R)*/
eul2r = returns the matrice when rotating about Euler angles
/*R = eul2r(0.1, 0.2, 0.3) == R = rotz(0.1) * roty(0.2) * rotz(0.3);*/
tr2eul = returns the Euler angles corresponding to same matrice
/*gamma = tr2eul(R)*/
rpy2r = returns the matrice when rotating about Cardan angles
/*R = rpy2r(0.1, 0.2, 0.3)*/
 tr2rpy = returns the Cardan angles corresponding to same matrice
/*gamma = tr2rpy(R)*/
oa2r returns the rotation matrix given by approach and orientation vectors
/*a = [1 0 0]''; o = [0 1 0]''; R = oa2r(o, a)*/
tr2angvec = returns the angle and vector whose relations to 3d frames
This information is encoded in the eigenvalues and eigenvectors of R. Using the builtin MATLAB® function eig
/*[theta, v] = tr2angvec(R)*/
/*[v,lambda] = eig(R)*/
Rodrigues rotational formula
 /*R = angvec2r(pi/2, [1 0 0])*/


++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 

Proprioceptive sensors measure the state of the robot itself: the angle of the joints on a robot arm,
    the number of wheel revolutions on a mobile robot or the current drawn by an electric motor.
    
Exteroceptive sensors measure the state of the world with respect to the robot.

The sensor might be a simple contact switch on a
vacuum cleaner robot to detect collision. It might be a GPS receiver that measures dis-
tances to an orbiting satellite constellation, or a compass that measures the direction of
the Earth’s magnetic field relative to the robot’s heading. It might also be an active sensor
that emits acoustic, optical or radio pulses in order to measure the distance to points
in the world based on the time taken for a reflection to return to the sensor.
A camera is a passive captures patterns of energy reflected from the scene. Our own
experience is that eyes are a very effective sensor for recognition, navigation, obstacle
avoidance and manipulation so vision has long been of interest to robotics research-
ers.

This book is based on two open-source Toolboxes written by the author: the
'Robotics Toolbox' for MATLAB® and the 'Machine Vision Toolbox' for MATLAB®

The 'Robotics Toolbox (RTB)' provides a diverse range of functions for simulating
mobile and arm-type robots. Arbitrary serial-link manipulators could be created and the Toolbox provides
functions for forward and inverse kinematics and dynamics. The Toolbox includes
functions for manipulating and converting between datatypes such as vectors, homo-
geneous transformations, 3-angle representations and unit-quaternions which are nec-
essary to represent 3-dimensional position and orientation.The RTB now includes models 
of car-like vehicles and quadcopters and controllers for these vehicles. It also provides standard algorithms 
for robot path planning, localization and map making.
  
The 'Machine Vision Toolbox (MVTB)' provides a rich collection of functions for
camera modeling, image processing, image feature extraction, multi-view geometry
and vision-based control. This Toolbox is younger than the Robotics Toolbox but it is
not a clone of the MATLAB® Image Processing Toolbox (IPT).The
MVTB contains many functions for image acquisition and display; filtering; blob, point
and line feature extraction; mathematical morphology; image warping; stereo vision;
homography and fundamental matrix estimation; robust estimation; visual Jacobians;
geometric camera models; camera calibration and color space operations. For modest
image sizes on a modern computer the processing rate can be sufficiently “real-time”
to allow for closed-loop control.

2 - Representing Position and Orientation  (pose)
-The position and orientation of a coordinate frame is known as its pose
The relative pose of a frame with respect to a reference coordinate frame is denoted by the symbol ?
-The pose of {B} relative to {A} is A?B (pose de A pra B).
-Ap = A?B*Bp -> where the right-hand side expresses the motion from {A} to {B} and then to P. 
-A?C = A?B (**pose composition operator) B?C.
-Ap = (A?B (**pose composition operator) B?C)*Cp
-(**inverse pose operator) significa trocar os relativos do (**pose composition operator) = inverted arrow.
- rotação não é linear!
- accelerometers medem aceleração gravitacional.
- Converting from angle and vector to a rotation matrix is achieved using Rodrigues’ rotation formula


+ pose 2D =  A?B ou (x,y,theta), sendo x,y vetor deslocamento e theta angulo de B em relação à A
+ vRb = (cos -sin;sin cos) = rotation matrix do frame V ao B.
	- ortonormal (R-1 = Rt)
	- det = 1
+ ?(x,y,theta) = aTb = (cos sin x;-sin cos y;0 0 1) = relative pose

+ pose 3D = 
+ represent rotation:
1) orthonormal rotation matrices,orthonormal matrix aRb
2) Euler and Cardan angles, sendo Euler (XYX, XZX type rotations) ¡= (f, ?, ?) e Cardan (XYZ, XZY type rotations)
Roll, pitch and yaw (also called bank, attitude and heading). /*GIMBAL LOCK PROBLEM!*/
3) rotation axis and angle (approach vector  $ = (ax, ay, az) and orientation vector, & = (ox, oy, oz)),
4) and unit quaternions. 

2.2.1.6 lUnit Quaternions








