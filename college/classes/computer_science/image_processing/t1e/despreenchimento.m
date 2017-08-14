function[imagem_de_saida]= preenchimento(imagem_de_entrada)

[P,Q]= size(imagem_de_entrada);

ret = zeros(P/2,Q/2);

ret = imagem_de_entrada((P/4+1):(3*P/4),(Q/4+1):(3*Q/4));

imagem_de_saida = ret;