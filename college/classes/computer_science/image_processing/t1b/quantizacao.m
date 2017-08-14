function[imagem_de_saida]=quantizacao(imagem_de_entrada,pixels)
    s=[512,512];
    m=imagem_de_entrada;
    if pixels==4
        for i=1:512
            for j=1:512
                if m(i,j)<=16
                    s(i,j)=0;
                elseif m(i,j)<=32
                    s(i,j)=24;
                elseif m(i,j)<=48       
                    s(i,j)=40;    
                elseif m(i,j)<=64    
                    s(i,j)=56;   
                elseif m(i,j)<=80
                    s(i,j)=72;
                elseif m(i,j)<=96       
                    s(i,j)=88;
                elseif m(i,j)<=112         
                    s(i,j)=109;
                elseif m(i,j)<=128
                    s(i,j)=120;    
                elseif m(i,j)<=144
                    s(i,j)=136;
                elseif m(i,j)<=160   
                    s(i,j)=152;
                elseif m(i,j)<=176
                    s(i,j)=168;
                elseif m(i,j)<=192
                    s(i,j)=184;
                elseif m(i,j)<=208
                    s(i,j)=200;
                elseif m(i,j)<=224
                    s(i,j)=216;
                elseif m(i,j)<=240
                    s(i,j)=232;
                else
                    s(i,j)=255;
                end  
            end
        end
    end
    
    
    if pixels==2
        for i=1:512
            for j=1:512
                if m(i,j)<=64
                    s(i,j)=0;
                elseif m(i,j)<=128
                    s(i,j)=96;
                elseif m(i,j)<=192       
                    s(i,j)=160;
                else
                    s(i,j)=255;
                end
            end
        end
    end
         
   
    
   if pixels==1
        for i=1:512
            for j=1:512
                if m(i,j)<=128
                   s(i,j)=0;
                else
                   s(i,j)=255;
                end
            end
        end  
   end
    
   imagem_de_saida = s;