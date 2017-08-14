function[imagem_de_saida,vetman]= proc_manchas(imagem_de_entrada)
    [~,a]=size(imagem_de_entrada);
    tam=a;
    int_rot=2;
    rotulo=[tam+1,tam+1];
    imagem=[tam+1,tam+1];
    
    imagem(2:tam+1,2:tam+1)=imagem_de_entrada;
    imagem(1:tam+1,1)=255;
    imagem(1,2:tam+1)=255;
    
    for i=1:tam+1
        for j=1:tam+1
            if imagem(i,j)==255
                rotulo(i,j)=1;
            else 
                rotulo(i,j)=0;
            end
        end
    end
    
    
    
    for i=2:tam+1
        for j=2:tam+1
            p = imagem(i,j); 
            if p==0
                t = imagem(i-1,j);
                r = imagem(i,j-1);
                tr = rotulo(i-1,j);
                rr = rotulo(i,j-1);
                if (t==255) && (r==255)
                    rotulo(i,j) = int_rot;
                    int_rot=int_rot+1;
                elseif ((t==0)&& (r==0) && tr==rr)
                    rotulo(i,j) = rr;
                elseif((t==0)&& (r==0) && tr~=rr)
                    rotulo(i,j) = min(tr,rr);
                    for k=1:i
                        for z=1:j
                            if rotulo(k,z)== max(tr,rr)
                                rotulo(k,z)=rotulo(i,j);
                            end
                        end
                    end
                else
                    if t==0
                        rotulo(i,j)=tr;
                    else
                        rotulo(i,j)=rr;
                    end
                end    
            end
        end
    end
    
    vet=0;
    val=1;
    for i=2:tam+1
        for j=2:tam+1
            if (rotulo(i,j)~=1 && rotulo(i,j)~=0)
                if rotulo(i,j)~= vet
                    vet(val)=rotulo(i,j);
                    val=val+1;
                end
            end
        end
    end
    
    for i=2:tam+1
        for j=2:tam+1
            if rotulo(i,j)~=1
                if any(rotulo(i,j)==vet)
                    indice = find(vet==rotulo(i,j));
                    rotulo(i,j)= indice+1;
                end
            end
        end
    end
    
    [~,b]= size(vet);
   
    for i=1:b
        vet(i)=i+1;
    end
    
    imagem_de_saida = rotulo;
    vetman = vet;
    
    
    
    
    
    
    
    
    
    