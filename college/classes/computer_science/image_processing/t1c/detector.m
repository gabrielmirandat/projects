function[matriz_de_saida]= detector(imagem, vetor)
    [~,tam]=size(imagem);
    
    vetor(2,1)=0;
    vet_aux=0;
    cont_aux=1;
    for i=2:tam
        for j=2:tam
            if imagem(i,j)>20
                if imagem(i,j)~=vet_aux
                     mancha_ass = imagem(i,j-1);
                     [~,ind2] = find(vetor==mancha_ass);
                     vetor(2,ind2)= vetor(2,ind2)+1;
                     vet_aux(cont_aux)=imagem(i,j);
                     cont_aux=cont_aux+1;
                end
            end
        end
    end
    
    matriz_de_saida=vetor;

    