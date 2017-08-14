function [qtzhair,qtzskin] = qtz_pele_cabelo(lin,col,skin,hair,qtzskin,qtzhair)
for i=3:5:lin-2
      for j=3:5:col-2
         qtd1 = sum(sum(skin(i-2:i+2,j-2:j+2)==1));
         qtd2 = sum(sum(hair(i-2:i+2,j-2:j+2)==1));
         
         if qtd1<12
             qtzskin(i-2:i+2,j-2:j+2)=0;
         elseif qtd1>=12
             qtzskin(i-2:i+2,j-2:j+2)=255;
         end
         
         if qtd2<12
             qtzhair(i-2:i+2,j-2:j+2)=0;
         elseif qtd2>=12
             qtzhair(i-2:i+2,j-2:j+2)=255;
         end
         
      end
end
end