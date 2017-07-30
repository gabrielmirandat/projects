function[imagem_de_saida]= subamostragem(imagem_de_entrada,inter)
    tam=size(imagem_de_entrada);
    fim=tam(1,1);
    lin=1;
    col=1;
    
    for i= 1:inter:fim
       for j= 1:inter:fim
           imagem(lin,col)=imagem_de_entrada(i,j);
           col=col+1;
       end
       lin=lin+1;
       col=1;
    end
    imagem_de_saida=imagem;