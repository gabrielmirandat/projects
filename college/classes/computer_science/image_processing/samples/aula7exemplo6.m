% O operador laplaciano

clear all
close all
clc


I = imread('../images/Lena.bmp');
bigImage = imresize(I, 10);
I=bigImage;
figure
imshow(I)

% H = [0 1 0; 1 -4 1; 0 1 0]

H = [1 1 1; 1 -8 1; 1 1 1]

H = -1*H;

If = imfilter(I,H);

for i=1:10
    if H(2,2) < 0
        g = I-If;
    else    
         g = I+If;
    end
end
figure
imshow(g)

