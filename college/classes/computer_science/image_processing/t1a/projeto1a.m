clear all
close all


%Experimento dos quadrados(discriminação dos níveis de cinza)
disc_cinza=0;
i=0;
tam=1024;
x = zeros(tam,tam);
imshow(uint8(x));
ini=0;
fim=1024;
while(i<256 && tam>32),
    ini=ini+8;
    fim=fim-8;
    tam=tam-8;
    percebeu=2;
    while(percebeu==2 && i<256 && tam>32),
        for lin = ini:fim
            for col = ini:fim
               x(lin,col)=i;
            end
        end
        imshow(uint8(x));
        percebeu = menu('Percebeu mudança?','Sim','Não');
        if(percebeu==1)
            disc_cinza= disc_cinza+1;
            break;
        end
        i=i+1;
    end
end 
waitfor(msgbox(sprintf('O usuario foi capaz de perceber %d mudanças de intensidade.',disc_cinza)));
close all;
 