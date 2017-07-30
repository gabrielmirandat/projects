import numpy as np
import cv2

cap = cv2.VideoCapture(0)

# Define the codec and create VideoWriter object
#fourcc = cv2.VideoWriter_fourcc(*'XVID')
fourcc = cv2.cv.CV_FOURCC(*'XVID')
#out = cv2.VideoWriter('output.avi',fourcc, 20.0, (640,480))
out = cv2.VideoWriter('output.avi',cv2.cv.CV_FOURCC('M','J','P','G'), 20.0, (640,480))
i=0

while(cap.isOpened()):
    ret, frame = cap.read()
    if ret==True:
	i=i+1
	if i%2==0:
	  frame = cv2.flip(frame,1)
	else:
	  frame = cv2.flip(frame,0)

        # write the flipped frame
        out.write(frame)

        cv2.imshow('frame',frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    else:
        break

# Release everything if job is finished
cap.release()
out.release()
cv2.destroyAllWindows()