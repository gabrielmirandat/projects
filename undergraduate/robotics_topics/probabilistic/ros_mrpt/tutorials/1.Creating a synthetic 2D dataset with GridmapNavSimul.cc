GridmapNavSimul (Grid map navigation simulator) is a GUI program that takes an occupancy gridmap and let you move a robot 
around simulating a laser scanner. The robot can be guided manually with keystrokes, with a joystick or reproduce a sequence
of fixed poses given in a file.

The intention of the program is to save all the sensor data as dataset files: laser scans and odometry. That is, the program is
a generator of synthetic robotics data sets.

Source in MRPT/apps/
Executable in MRPT/build/bin/
Run with GridmapNavSimul in terminal
Main classes
	mrpt::maps::COccupancyGridMap2D: The 2D grid map.
	mrpt::obs::CObservation2DRangeScan: The 2D laser scan observation data.
	mrpt::utils::CRobotSimulator: A very basic 2D robot motion simulator.


Tuto

Gimp -> New -> Grayscale
	 -> Fill all with mid gray
	 -> Draw walls and obstacles with black brush
	 -> Flood free space with white
	 -> save as cic_test.png in my ros_mrpt/tutorials/resources path
	 ...
GridmapNavSimul	 
	 -> set dataset name ./cic_test_simul.rawlog
	 -> save in ros_mrpt/tutorials/resources path
	 -> enable act+sf mode
	 -> START ..STOP
	 -> Open saved with RawLogViewer

RawLogViewer
	-> Emulate
	-> Raw map -> Map from odometry

