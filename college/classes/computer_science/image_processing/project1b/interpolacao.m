function[imagem_de_saida]= interpolacao(imagem_de_entrada,inter)
    saida=[512,512];
    tam=size(imagem_de_entrada);
    fim=tam(1,1);
    
    
    for i=1:fim
        for j=1:fim
            saida((inter*i - inter + 1):(i*inter),(inter*j - inter + 1):(j*inter))= imagem_de_entrada(i,j);
        end
    end
imagem_de_saida=saida;    