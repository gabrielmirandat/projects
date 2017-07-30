clear all
close all
clc

 espera = waitbar(0,'Por favor,espere ..');

fismat = readfis('realce_fuzzy');
I = imread('../images/characters_test_pattern.tif');

[a,b]= size(I);
imshow(I);

I2=ones(a,b);

for i=1:a
    for j=1:b
        I2(i,j)=uint8(evalfis(double(I(i,j)),fismat));
    end
    waitbar(i/a,espera);  
end

close(espera);
I2=uint8(I2);
figure;
imshow(I2);
