clear all
close all
clc

%Contador de manchas e buracos nas manchas.
I1 = imread('../images/mancha1.jpg');
I2 = imread('../images/mancha2.jpg');
I3 = imread('../images/mancha3.jpg');
I4 = imread('../images/mancha4.jpg');

I_1= preprocessamento(I1);
I_2= preprocessamento(I2);
I_3= preprocessamento(I3);
I_4= preprocessamento(I4);

%Para figura 1
[rotulo_manchas,vet_manchas] = trotulador(I_1);

rotulo_buracos = proc_buracos(I_1);

imagem_final_rotulos = juntador_mancha_buraco(rotulo_manchas,rotulo_buracos);

matriz_resultado = detector(imagem_final_rotulos,vet_manchas);


waitfor(msgbox('Aperte OK para ver o resultado da primeira imagem.'));
imshow(uint8(I_1));
resultado(1,matriz_resultado);
close all;

%Para figura 2
[rotulo_manchas,vet_manchas] = trotulador(I_2);

rotulo_buracos = proc_buracos(I_2);

imagem_final_rotulos = juntador_mancha_buraco(rotulo_manchas,rotulo_buracos);

matriz_resultado = detector(imagem_final_rotulos,vet_manchas);

waitfor(msgbox('Aperte OK para ver o resultado da segunda imagem.'));
imshow(uint8(I_2));
resultado(2,matriz_resultado);
close all;

%Para figura 3
[rotulo_manchas,vet_manchas] = trotulador(I_3);

rotulo_buracos = proc_buracos(I_3);

imagem_final_rotulos = juntador_mancha_buraco(rotulo_manchas,rotulo_buracos);

matriz_resultado = detector(imagem_final_rotulos,vet_manchas);

waitfor(msgbox('Aperte OK para ver o resultado da terceira imagem.'));
imshow(uint8(I_3));
resultado(3,matriz_resultado);
close all;

%Para figura 4
[rotulo_manchas,vet_manchas] = trotulador(I_4);

rotulo_buracos = proc_buracos(I_4);

imagem_final_rotulos = juntador_mancha_buraco(rotulo_manchas,rotulo_buracos);

matriz_resultado = detector(imagem_final_rotulos,vet_manchas);

waitfor(msgbox('Aperte OK para ver o resultado da quarta imagem.'));
imshow(uint8(I_4));
resultado(4,matriz_resultado);
close all;
