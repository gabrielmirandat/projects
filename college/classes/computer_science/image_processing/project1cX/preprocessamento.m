function[imagem_de_saida]= preprocessamento(imagem_de_entrada)
    [a,b]=size(imagem_de_entrada);
    tam=a;
    s=[tam,tam];
    
    for i=1:tam
        for j=1:tam
            if imagem_de_entrada(i,j)<= 128
                s(i,j)=0;
            else
                s(i,j)=255;
            end
        end
    end
    
    imagem_de_saida=s;