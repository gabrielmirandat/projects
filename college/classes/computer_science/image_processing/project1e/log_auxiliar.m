function[imagem_de_saida]= log_auxiliar(imagem_de_entrada)

[a,b] = size(imagem_de_entrada);
z = ones(a,b);


for i = 1:a
   for j = 1:b
           m=double(imagem_de_entrada(i,j));
           z(i,j)=1000000.*log10(1+m);
   end
end

imagem_de_saida = z;