function[imagem_de_saida]= preenchimento(imagem_de_entrada)

[N,M] = size(imagem_de_entrada);

Im = zeros(2*N,2*M);

Im((N/2+1):(3*N/2),(M/2+1):(3*M/2)) = imagem_de_entrada;

imagem_de_saida = Im;