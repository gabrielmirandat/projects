function[imagem_de_saida]= normalizador(imagem_de_entrada)

[a,b] = size(imagem_de_entrada);

%alocando as matrizes
mat_absol = ones(a,b);
aux = ones(a,b);
ret = ones(a,b);

mat_absol = abs(imagem_de_entrada);

maximo = max(max(mat_absol));

aux = mat_absol ./ maximo;

ret = aux .* 255;

imagem_de_saida = uint8(ret);

