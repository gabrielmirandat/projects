function[imagem_de_saida]= juntador_mancha_buraco(img1,img2)
    [~,tam]= size(img1);
    
    img_final=[tam,tam];
    
    for i=1:tam
        for j=1:tam
            img_final(i,j) = max(img1(i,j),img2(i,j));
        end
    end
    
    imagem_de_saida = img_final;