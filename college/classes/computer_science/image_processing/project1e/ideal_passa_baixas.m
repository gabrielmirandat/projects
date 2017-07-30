function[imagem_de_saida]= ideal_passa_baixas(imagem_de_entrada)

[P,Q]= size(imagem_de_entrada);

filtro = zeros(P,Q);

Do = 60;

for i=1:P
    for j=1:Q
        if((sqrt((i-P/2)^2 + (j-Q/2)^2))<=Do)
            filtro(i,j)=1;
        end
    end
end

ret = times(filtro,imagem_de_entrada);

imagem_de_saida = ret;


