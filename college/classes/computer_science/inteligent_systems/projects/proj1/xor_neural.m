%xor
%%
nep=2000; 									% Número de épocas
eta=0.7; 									% Taxa de aprendizado
%%
w1=rand(4,3)*.2-.1;
w2=rand(1,5)*.2-.1 ;
%%
x=[0 0 1 1 ; 0 1 0 1; 1 1 1 1]; 			%Entradas
d=[0.1 0.9 0.9 0.1]; 						%Saídas desejadas
sse=zeros(nep,1); 							%Soma de erros quadráticos
err=zeros(nep,1); 							%Total de padrões errados
%%
for i=1:nep
	for j=1:4
		%Propagação
  		s1=w1*x(:,j);
  		y1=1.0./(1+exp(-s1));
  		s2=w2*[y1;1];
  		y2=1/(1+exp(-s2));  
		sse(i)=sse(i)+(d(j)-y2)^2; % Calcula erro
		if (y2>0.5 && d(j)==0.1)||(y2<0.5 && d(j)==0.9)  
			err(i)=err(i)+1; 
        end %Verifica classificação errada

		%Retropropagação
		e=(d(j)-y2)*y2*(1-y2); %Erro na saída
  		dw2=e*transpose([y1;1]);
		e1=transpose(w2(1:4))*e.*y1.*(1-y1); % Propagação do erro para 1a camada
 		dw1=e1*transpose(x(:,j));
		w1=w1+eta*dw1; % Atualização
 		w2=w2+eta*dw2; 
    end
end