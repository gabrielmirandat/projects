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
-Axes are denoted by thick lines with an open arrow, 
-vectors by thin lines with a swept arrow head and a 
-pose by a thick line with a solid head.
-The position and orientation of a coordinate frame is known as its pose
and is shown graphically as a set of coordinate axes. The relative pose of a
frame with respect to a reference coordinate frame is denoted by the symbol ξ
-The pose of {B} relative to {A} is AξB (pose de A pra B).
-Ap = AξB*Bp -> where the right-hand side expresses the motion from {A} to {B} and then to P. 
-AξC = AξB (**pose composition operator) BξC.
-Ap = (AξB (**pose composition operator) BξC)*Cp
-node = pose
 edge = relative pose
-Each side of the equation represents
a path through the network, a sequence of edges (arrows) that are written  in head to
tail order. Both sides of the equation start and end at the same node.
-(**inverse pose operator) significa trocar os relativos do (**pose composition operator) = inverted arrow.
-AξB ~ (x,y,theta) = representa a translação e rotação do frame A indo pro frame B em 2D.

relations in 20







