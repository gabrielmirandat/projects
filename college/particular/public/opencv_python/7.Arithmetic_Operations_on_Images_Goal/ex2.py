import cv2
import numpy as np

img1 = cv2.imread('/home/gabriel/Imagens/Captura de tela de 2015-07-24 12:44:33.png')
img2 = cv2.imread('/home/gabriel/Imagens/Captura de tela de 2015-07-25 00:28:45.png')

dst = cv2.addWeighted(img1,0.7,img2,0.3,0)

cv2.imshow('dst',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()