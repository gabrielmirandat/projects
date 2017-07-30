function [skin,H] = hsi_pele(lin,col,B,G,H,theta,skin,g,w,r)
for i=1:lin
      for j=1:col
          %constroi H
          if(B(i,j)<=G(i,j))
              H(i,j) = theta(i,j);
          elseif(B(i,j)>G(i,j))
             H(i,j) = 360 - theta(i,j);
          end
          %constroi filtro da pele
          if(g(i,j)<F1(r(i,j)) && g(i,j) > F2(r(i,j)) && w(i,j)>0.001 && (H(i,j)>240 || H(i,j)<=20))
                skin(i,j)=1;
          end
      end
end
  
end