import cv2
import numpy as np

img = cv2.imread('messi5.jpg')
#Se a imagem for grayscale, acessa só uma intensidade, se for colorida, acessa um vetor rgb do pixel.

px = img[100,100]
print px
#[157 166 200]

# accessing only blue pixel
blue = img[100,100,0]
print blue
#157

img[100,100] = [255,255,255]
print img[100,100]
#[255 255 255]

# accessing RED value
img.item(10,10,2)
#59

# modifying RED value
img.itemset((10,10,2),100)
img.item(10,10,2)
#100

print img.shape
#(342, 548, 3)

print img.size
#562248

print img.dtype
#uint8

ball = img[280:340, 330:390]
img[273:333, 100:160] = ball

b,g,r = cv2.split(img)
img = cv2.merge((b,g,r))

b = img[:,:,0]





