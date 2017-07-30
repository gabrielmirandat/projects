import cv2
import numpy as np
import time

img1 = cv2.imread('../imagens/im2.jpg')

#e1 = time.time();
e1 = cv2.getTickCount()
for i in xrange(5,49,2):
    img1 = cv2.medianBlur(img1,i)
#e2 = time.time();
e2 = cv2.getTickCount()
t = (e2 - e1)/cv2.getTickFrequency()
print t

# Com time = 1.37047052383e-10
# Com getTickCount = 0.137067029

