clear all
close all


%1. SUBAMOSTRAGEM
%Mudando a resolução espacial de 512 para(256,128,64 e 32)

I1 = imread('../images/Baboon.bmp');
I2 = imread('../images/Lena.bmp');

Imagens=[I1,I2];
imshow(Imagens);
waitfor(msgbox('Imagens escolhidas para o experimentO.'));

I1sub_256=subamostragem(I1,2);
I1sub_256=uint8(I1sub_256);
I1sub_128=subamostragem(I1,4);
I1sub_128=uint8(I1sub_128);
I1sub_064=subamostragem(I1,8);
I1sub_064=uint8(I1sub_064);
I1sub_032=subamostragem(I1,16);
I1sub_032=uint8(I1sub_032);


imshow(I1sub_256);
figure
imshow(I1sub_128);
figure
imshow(I1sub_064);
figure
imshow(I1sub_032);
waitfor(msgbox('SUBAMOSTRAGEM->Baboon'));
close all;

I2sub_256=subamostragem(I2,2);
I2sub_256=uint8(I2sub_256);
I2sub_128=subamostragem(I2,4);
I2sub_128=uint8(I2sub_128);
I2sub_064=subamostragem(I2,8);
I2sub_064=uint8(I2sub_064);
I2sub_032=subamostragem(I2,16);
I2sub_032=uint8(I2sub_032);

imshow(I2sub_256);
figure
imshow(I2sub_128);
figure
imshow(I2sub_064);
figure
imshow(I2sub_032);
waitfor(msgbox('SUBAMOSTRAGEM->Lena'));
close all;

%2. INTERPOLAÇÃO DE VIZINHO MAIS PROXIMO
%Mudando a resolução espacial de (256,128,64 e 32) para 512 


I1int_256=interpolacao(I1sub_256,2);
I1int_256=uint8(I1int_256);
I1int_128=interpolacao(I1sub_128,4);
I1int_128=uint8(I1int_128);
I1int_064=interpolacao(I1sub_064,8);
I1int_064=uint8(I1int_064);
I1int_032=interpolacao(I1sub_032,16);
I1int_032=uint8(I1int_032);

imshow(I1int_256);
figure
imshow(I1int_128);
figure
imshow(I1int_064);
figure
imshow(I1int_032);
waitfor(msgbox('INTERP. VIZINHO MAIS PROXIMO->Baboon'));
close all;

I2int_256=interpolacao(I2sub_256,2);
I2int_256=uint8(I2int_256);
I2int_128=interpolacao(I2sub_128,4);
I2int_128=uint8(I2int_128);
I2int_064=interpolacao(I2sub_064,8);
I2int_064=uint8(I2int_064);
I2int_032=interpolacao(I2sub_032,16);
I2int_032=uint8(I2int_032);

imshow(I2int_256);
figure
imshow(I2int_128);
figure
imshow(I2int_064);
figure
imshow(I2int_032);
waitfor(msgbox('INTERP. VIZINHO MAIS PROXIMO->Lena'));
close all;

%3. QUANTIZAÇÃO EM NÍVEIS DE CINZA
%Reduzindo o numero de bits por pixel de 8 para 4, 2 e 1

I1quant_16=quantizacao(I1,4);
I1quant_16=uint8(I1quant_16);
I1quant_4=quantizacao(I1,2);
I1quant_4=uint8(I1quant_4);
I1quant_2=quantizacao(I1,1);
I1quant_2=uint8(I1quant_2);

imshow(I1quant_16);
figure
imshow(I1quant_4);
figure
imshow(I1quant_2);
waitfor(msgbox('QUANTIZAÇÃO NIVEIS DE CINZA->Baboon'));
close all;

I2quant_16=quantizacao(I2,4);
I2quant_16=uint8(I2quant_16);
I2quant_4=quantizacao(I2,2);
I2quant_4=uint8(I2quant_4);
I2quant_2=quantizacao(I2,1);
I2quant_2=uint8(I2quant_2);

imshow(I2quant_16);
figure
imshow(I2quant_4);
figure
imshow(I2quant_2);
waitfor(msgbox('QUANTIZAÇÃO NIVEIS DE CINZA->Lena'));
close all;




