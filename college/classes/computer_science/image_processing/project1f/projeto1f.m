clear all
close all
clc
I = imread( '../images/building_original.tif');
%imshow(I);
% Filtro Gaussiano
  % fspecial cria filtro gaussiano hg,de tamanho 25x25 e parametro sigma
  % igual a 4.(n�o possui valores negativos, entre 0.0000 e 0.0100).
hg = fspecial( 'gaussian',25,4);
  % conv2 convolui a imagem de entrada com o filtro
  % gaussiano criado.
Ig = conv2(double(I),double(hg));
figure;
  %valor minimo de Ig printado como preto e valor m�ximo como branco, 
  %cinza s�o os valores default intermedi�rios.
imshow(Ig,[]);
% Filtro Laplaciado
hl = [1 1 1;1 -8 1; 1 1 1];
  %convolui Ig com o filtro laplaciano criado.
Ilog = conv2(double(Ig), double(hl));
figure;
imshow(Ilog,[])
% Calcula transi��es por zero
  %Pega o sinal de cada elemento da matriz(matriz de 1's p/n�veis>0, 
  %0's p/n�veis==0 e -1's p/n�veis<0)
sinais = sign(Ilog);
[h, w] = size(sinais);
% Verifica se os sinais de pixels opostos em cada dire��o
% t�m sinais diferentes. Se tiverem, o valor central da regi�o
% 3x3 ser� 0.
  %faz a correla��o de cada possibilidade de cruzamento por zero na imagem
  %e armazena em cada passada em 4 imagens 
t1 = filter2([1 0 0; 0 0 0; 0 0 1],sinais);
t2 = filter2([0 1 0; 0 0 0; 0 1 0],sinais);
t3 = filter2([0 0 1; 0 0 0; 1 0 0],sinais);
t4 = filter2([0 0 0; 1 0 1; 0 0 0],sinais);
% Matriz que tem todas as transi��es por zero.
y = t1==0 | t2==0 | t3==0 | t4 == 0;
% Imagem Ilog mascarada pelo cruzamento em zero
IlogM = Ilog.*y;
% Pegando apenas os valores positivos (maiores que zero)
  %se (IlogM>limiar)==1(verdade),final = 255*1, sen�o � zero.Logo,final �
  %bin�ria.
limiar = 0;
final = uint8(255*(IlogM>limiar));
figure
imshow(final);

%retirar os espaguetes
  %usou-se um limiar de 2% do valor m�ximo da Ilog
limiar2 = 0.02*(max(max(Ilog)));
final2 = uint8(255*(IlogM>limiar2));
  %remove todos os componentes com menos de 7 pixels(ru�dos).
final2 = bwareaopen(final2, 7);
figure
imshow(final2);

im1 = normalizador(Ig);
im2 = normalizador(Ilog);
im3 = normalizador(sinais);
im4 = normalizador(IlogM);
im5 = normalizador(final);
im6 = normalizador(final2);
