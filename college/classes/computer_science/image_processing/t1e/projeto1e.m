clear all
close all

%lê imagem
f = imread('characters_test_pattern.tif');

%realiza preenchimento
fpa = preenchimento(f);

%DFT da imagem preenchida
Fpa = fft2(fpa);

%deslocar a imagem no dominio da frequencia
Fpad = fftshift(Fpa);

%IDEAL PASSA BAIXAS
Gpad_1 = ideal_passa_baixas(Fpad);

%desfazer deslocamento
Gpa_1 = ifftshift(Gpad_1);

%DFT inversa na imagem
gpa_1 = ifft2(Gpa_1);

%desfazer preenchimento
g_1 = despreenchimento(gpa_1);

%normaliza
g_1 = normalizador(g_1);

%imagem filtrada
imshow(g_1);
figure;

%IDEAL PASSA ALTAS
Gpad_2 = ideal_passa_altas(Fpad);

%desfazer deslocamento
Gpa_2 = ifftshift(Gpad_2);

%DFT inversa na imagem
gpa_2 = ifft2(Gpa_2);

%desfazer preenchimento
g_2 = despreenchimento(gpa_2);

%normaliza
g_2 = normalizador(g_2);

%imagem filtrada
imshow(g_2);
figure;

%BUTTERWORTH PASSA BAIXAS
Gpad_3 = Butterworth_passa_baixas(Fpad);

%desfazer deslocamento
Gpa_3 = ifftshift(Gpad_3);

%DFT inversa na imagem
gpa_3 = ifft2(Gpa_3);

%desfazer preenchimento
g_3 = despreenchimento(gpa_3);

%normaliza
g_3 = normalizador(g_3);

%imagem filtrada
imshow(g_3);
figure;

%BUTTERWORTH PASSA ALTAS
Gpad_4 = Butterworth_passa_altas(Fpad);

%desfazer deslocamento
Gpa_4 = ifftshift(Gpad_4);

%DFT inversa na imagem
gpa_4 = ifft2(Gpa_4);

%desfazer preenchimento
g_4 = despreenchimento(gpa_4);

%normaliza
g_4 = normalizador(g_4);

%imagem filtrada
imshow(g_4);






