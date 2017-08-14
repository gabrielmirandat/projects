%   Limpar terminal, janelas e variáveis;
clear all;
close all;
clc;

%   Inicialização da Webcam;
cam = webcam(1);
img_aux = snapshot(cam);
[lin_cam,col_cam,dimensao] = size(img_aux);
fator_redimensionamento = 0.2; 
img_aux = imresize(img_aux,fator_redimensionamento);
   
%	Definindo o tamanho do frame a ser trabalhado;
lin = lin_cam*fator_redimensionamento;
col = col_cam*fator_redimensionamento;

%   Inicializando a imagem a ser mostrada;
figure(1);
handler_is = imshow(zeros([lin_cam col_cam]));

%   Definindo tempo de execução;
segundos = 30;
finalTime = datenum(clock + [0, 0, 0, 0, 0, segundos]);
contador_frames = 0;

while datenum(clock) < finalTime
  
  %     Contando número de frames processados;
  contador_frames = contador_frames + 1;
  
  %     Capturando imagem da câmera;
  imgO = snapshot(cam);
  frame_final = imgO;
  imgO = imresize(imgO,fator_redimensionamento);                
           
  %     Adquire os planos rgb da imagem;
  R = imgO(:,:,1);
  G = imgO(:,:,2);  
  B = imgO(:,:,3);

  %     Convertendo para Double;
  R=double(R);
  G=double(G);
  B=double(B);
  
  %     Planos RGB normalizados;
  r = R ./(R+G+B);  
  g = G ./(R+G+B); 
  w = ((r-0.33).*(r-0.33) + (g-0.33).*(g-0.33)); %pixel branco
  
  %     Convertendo para o sistema de cores HSI;
  denominador = sqrt((R-G).*(R-G) + (R-B).*(G-B));
  numerador = (0.5).*((R-G) + (R-B));
  theta = acosd(numerador./denominador);
  
  %     Cria o filtro da pele;
  skin = zeros(lin,col);
  H = zeros(lin,col);
  [skin,H] = hsi_pele(lin,col,B,G,H,theta,skin,g,w,r);
  skin = uint8(skin);
  R = uint8(R);
  G = uint8(G);
  B = uint8(B);
  im1 = R.*skin;
  im2 = G.*skin;
  im3 = B.*skin;
  imskin=cat(3,im1,im2,im3);
  

  %     Cria o filtro do cabelo;
  R=double(R);
  G=double(G);
  B=double(B);
  I = (R+G+B)./3;
  im4 =uint8(R); 
  im5 =uint8(G); 
  im6 =uint8(B);
  hair = zeros(lin,col);
  [im4,im5,im6,hair] = hsi_cabelo(lin,col,hair,I,B,G,R,H,im4,im5,im6);
  imhair=cat(3,im4,im5,im6);
  
  %     Cria a quantização da pele e do cabelo;
  qtzskin = zeros(lin,col);
  qtzhair = zeros(lin,col);
  [qtzhair,qtzskin] = qtz_pele_cabelo(lin,col,skin,hair,qtzskin,qtzhair);
  qtzskin=uint8(qtzskin);
  qtzhair=uint8(qtzhair);
  
  %     CALCULANDO AS PROPRIEDADES NAS COMPONENTES;
  CC = bwconncomp(qtzskin); %default é conectividade de 8
  S = regionprops(CC,'basic'); %area, centroid e bounding box
  %o numero de linhas de S(que tem apenas um dimensao) eh o numero de
  %componentes.
  
  CC2 = bwconncomp(qtzhair); %default é conectividade de 8
  S2 = regionprops(CC2,'basic'); %area, centroid e bounding box
  
  %     Buscar areas maiores que 1000 pixels;
  cont=find([S.Area]>400);
  cont2=find([S2.Area]>200);
  
  %     Achar bounding box que se cruzam;  
  [~, coluna1] = size(cont);
  [~, coluna2] = size(cont2);
  i3=1;
  contbb = [];
  for i=1:coluna1
       for j=1:coluna2
           if(rectint(S(cont(i)).BoundingBox,S2(cont2(j)).BoundingBox)>0)
               contbb(i3)= cont(i);
               i3=i3+1;
               break;
           end
       end
  end
  
  
   %    Achar índice cujo objeto possui a maior area;
   maximo=1;
   for n=1:(size(S,1)-1)
       if (S(n+1).Area > S(maximo).Area)
          maximo = n+1;
        end    
   end
    
    %   Encontrar objetos com area maior que 1000 pixels; 
    [~, coluna] = size(contbb);
    for contador = 1:coluna
        %   Colocar Bounding box ao redor das faces;
        frame_final = insertObjectAnnotation(frame_final,'rectangle',S(contbb(contador)).BoundingBox.*(1/fator_redimensionamento),'face');
    end
  
  %     Atualizar os dados do Imshow;
  set(handler_is,'CData',frame_final);
end

%   Desligar câmera;
clear cam;