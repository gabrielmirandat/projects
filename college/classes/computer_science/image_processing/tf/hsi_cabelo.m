function [im4,im5,im6,hair] = hsi_cabelo(lin,col,hair,I,B,G,R,H,im4,im5,im6)
for i=1:lin
      for j=1:col
          %constroi FILTRO DO CABELO
          if((I(i,j)<30 && ((B(i,j)-G(i,j))<15 || (B(i,j)-R(i,j))<15)) || (H(i,j)>20 && H(i,j)<=40))
                hair(i,j)=1;
          
          else 
             im4(i,j)=255;
             im5(i,j)=255; 
             im6(i,j)=255;
          end
      end
end
end