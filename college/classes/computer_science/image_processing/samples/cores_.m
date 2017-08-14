red = [1 0; 1 0.7];

green = [0 0; 1 0.7];

blue = [0 1; 0 0.7];

truecolor_image = cat(3, red, green, blue);

image(truecolor_image)
axis equal % Display the image using square pixels

clear all;
close all;

plane_1 = [1 0 0];
plane_2 = [0 0 1];
plane_3 = [0 1 0];
rgb = cat(3, plane_1, plane_2, plane_3);
size(rgb)

image(rgb)
axis image
title('Truecolor image with one red, one blue, and one yellow pixel')