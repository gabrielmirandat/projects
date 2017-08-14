function[imagem_de_saida,vetsaida]= trotulador(imagem_de_entrada)
    [a,b]=size(imagem_de_entrada);
    int_rot=2;
    rotulo=[a+2,b+1];
    imagem=[a+2,b+1];
    
    imagem(2:a+1,2:b+1)=imagem_de_entrada;
    imagem(1:a+2,1)=255;
    imagem(1,2:b+1)=255;
    imagem(a+2,2:b+1)=255;
    
    for i=1:a+2
        for j=1:b+1
            if imagem(i,j)==255
                rotulo(i,j)=1;
            else 
                rotulo(i,j)=0;
            end
        end
    end
    
    
    vet = zeros(1,4);
    for i=2:a+1
        for j=2:b+1
            p = imagem(i,j); 
            if p==0
                t = imagem(i-1,j);
                r = imagem(i,j-1);
                v = imagem(i-1,j-1);
                z = imagem(i+1,j-1);
                
                tr = rotulo(i-1,j);
                rr = rotulo(i,j-1);
                vr = rotulo(i-1,j-1);
                zr = rotulo(i+1,j-1);
                
                vet=[tr,rr,vr,zr];
                
                if (t==255) && (r==255) && (v==255) && (z==255)%parei aqui
                    rotulo(i,j) = int_rot;
                    int_rot=int_rot+1;
                elseif ((t==0)&&(r==0)&&(v==0)&&(z==0)&&(tr==rr && tr==vr && tr==zr && rr==vr && rr==zr && vr==zr ))
                    rotulo(i,j) = rr;
                elseif((t==0)&&(r==0)&&(v==0)&&(z==0)&&(tr~=rr || tr~=vr || tr~=zr || rr~=vr || rr~=zr || vr~=zr ))
                    rotulo(i,j) = min(vet);
                    for k=1:i
                        for z=1:j
                            if rotulo(k,z)== max(vet)
                                rotulo(k,z)=rotulo(i,j);
                            end
                        end
                    end
                else
                    if t==0
                        rotulo(i,j)=tr;
                    elseif r==0
                        rotulo(i,j)=rr;
                    elseif v==0
                        rotulo(i,j)=vr;
                    elseif z==0
                        rotulo(i,j)=zr;
                    end
                end    
            end
        end
    end
    
    vet=0;
    val=1;
    for i=2:a+1
        for j=2:b+1
            if (rotulo(i,j)~=1 && rotulo(i,j)~=0)
                if rotulo(i,j)~= vet
                    vet(val)=rotulo(i,j);
                    val=val+1;
                end
            end
        end
    end
    
    for i=2:a+1
        for j=2:b+1
            if rotulo(i,j)~=1
                if any(rotulo(i,j)==vet)
                    indice = find(vet==rotulo(i,j));
                    rotulo(i,j)= indice+1;
                end
            end
        end
    end
    
    [~,c]= size(vet);
   
    for i=1:c
        vet(i)=i+1;
    end
    
    imagem_de_saida = rotulo(2:a,2:b);
    vetsaida = vet;
    
    
    
    
    
    
    
    
    
    