function[imagem_de_saida]= Butterworth_passa_altas(imagem_de_entrada)

[P,Q]= size(imagem_de_entrada);

filtro = zeros(P,Q);

Do = 60;
n=2;

for i=1:P
    for j=1:Q
        D = (sqrt((i-P/2)^2 + (j-Q/2)^2));
        resp1 = (Do/D)^(2*n);
        resp2 = 1 + resp1;
        resp3 = 1/resp2;
        filtro(i,j) = resp3;
    end
end

ret = times(filtro,imagem_de_entrada);

imagem_de_saida = ret;

