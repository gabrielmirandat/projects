% Filtro de mínimo e máximo
clear all
close all
clc

I = imread('../images/Fig0334(a)(hubble-original).tif');
imshow(I)

If = I;

[h, w] = size(I);

for i = 2:h-1
    for j = 2:w-1
        Bloco = I(i-1:i+1, j-1:j+1);
        %If(i,j) = min(Bloco(:));
        If(i,j) = max(Bloco(:));
        
    end
end

figure; imshow(If);
