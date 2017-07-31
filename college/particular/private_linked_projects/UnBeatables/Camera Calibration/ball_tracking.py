#19cm
#radius is: 45.949528
#distance is (first): 197.959549 - camera
#
#focal_length is: 315.355224
#distance is (second): 229.913136 - triangulo

#30.8
#radius is: 33.994377
#distance is (first): 267.578010 
#
#focal_length is: 315.355224
#distance is (second): 310.769042

#40
#radius is: 28.298786
#distance is (first): 321.432437 
#
#focal_length is: 315.355224
#distance is (second): 373.316366 

#60
#radius is: 17.754835
#distance is (first): 512.319474 
#
#focal_length is: 315.355224
#distance is (second): 595.015382

#70
#radius is: 15.214779
#distance is (first): 597.849489 
#
#focal_length is: 315.355224
#distance is (second): 694.351201

# import the necessary packages
from collections import deque
import numpy as np
import argparse
import imutils
import cv2
 
# construct the argument parse and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-v", "--video",
	help="path to the (optional) video file")
ap.add_argument("-b", "--buffer", type=int, default=64,
	help="max buffer size")
args = vars(ap.parse_args())

# define the lower and upper boundaries of the "green"
# ball in the HSV color space, then initialize the
# list of tracked points
greenLower = (26, 73, 0)
greenUpper = (64, 188, 255)
pts = deque(maxlen=args["buffer"])
 
# if a video path was not supplied, grab the reference
# to the webcam
if not args.get("video", False):
	camera = cv2.VideoCapture(0)
 
# otherwise, grab a reference to the video file
else:
	camera = cv2.VideoCapture(args["video"])

# keep looping
while True:
	# grab the current frame
	(grabbed, frame) = camera.read()
 
	# if we are viewing a video and we did not grab a frame,
	# then we have reached the end of the video
	if args.get("video") and not grabbed:
		break
 
	# resize the frame, blur it, and convert it to the HSV
	# color space
	frame = imutils.resize(frame, width=320, height=240)
	# blurred = cv2.GaussianBlur(frame, (11, 11), 0)
	hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
 
	# construct a mask for the color "green", then perform
	# a series of dilations and erosions to remove any small
	# blobs left in the mask
	mask = cv2.inRange(hsv, greenLower, greenUpper)
	mask = cv2.erode(mask, None, iterations=2)
	mask = cv2.dilate(mask, None, iterations=2)

	# find contours in the mask and initialize the current
	# (x, y) center of the ball
	cnts = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL,
		cv2.CHAIN_APPROX_SIMPLE)[-2]
	center = None
 
	# only proceed if at least one contour was found
	if len(cnts) > 0:
		# find the largest contour in the mask, then use
		# it to compute the minimum enclosing circle and
		# centroid
		c = max(cnts, key=cv2.contourArea)
		((x, y), radius) = cv2.minEnclosingCircle(c)
		M = cv2.moments(c)
		center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))
 
		# only proceed if the radius meets a minimum size
		if radius > 15:
			# draw the circle and centroid on the frame,
			# then update the list of tracked points
			cv2.circle(frame, (int(x), int(y)), int(radius),
				(0, 255, 255), 2)
			cv2.circle(frame, center, 5, (0, 0, 255), -1)
			print "radius is: %f" %radius #34.3
			
			#method1
			F_X = 275.84193859
			F_Y = 275.4397455

			M = (F_X + F_Y)/2

			BALL_SIZE_REAL= 66	#66

			BALL_SIZE_SENSOR = 2*radius/M;
			
			BALL_DISTANCE = BALL_SIZE_REAL/BALL_SIZE_SENSOR

			print "distance is (first): %f \n" %BALL_DISTANCE

			#method2

			know_width = 67;
			know_distance = 308.0;

			#the first term is the well know width in pixels for the know distance (a constant)
			focal_length = (68.6 * know_distance)/know_width
			print "focal_length is: %f" %focal_length

			distance_to_camera = (know_width*focal_length)/(2*radius)
			print "distance is (second): %f \n" %distance_to_camera

	# update the points queue
	pts.appendleft(center)

	# loop over the set of tracked points
	for i in xrange(1, len(pts)):
		# if either of the tracked points are None, ignore
		# them
		if pts[i - 1] is None or pts[i] is None:
			continue
 
		# otherwise, compute the thickness of the line and
		# draw the connecting lines
		thickness = int(np.sqrt(args["buffer"] / float(i + 1)) * 2.5)
		cv2.line(frame, pts[i - 1], pts[i], (0, 0, 255), thickness)
 
	# show the frame to our screen
	cv2.imshow("Frame", frame)
	key = cv2.waitKey(1) & 0xFF
 
	# if the 'q' key is pressed, stop the loop
	if key == ord("q"):
		break
 
# cleanup the camera and close any open windows
camera.release()
cv2.destroyAllWindows()