I = imread('../images/cameraman.tif');
[X,map] = gray2ind(I,16);
II = ind2gray(X,map);
imshow(II);