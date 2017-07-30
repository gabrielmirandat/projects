%Método de Gauss-Seidel
function [t,iter,x,converge] = gauss_Seidel_func(A,b,x0,tol,maximo)

%A - matriz
%b - resultado
%x0 - aproxiamcao inicial
%tol - erro minimo    
%maximo - qtd maxima de iteracoes

n = length(A);
x = x0;
converge = 1;

tic;
for iter=1:maximo                           %entra num loop que vai até o maximo caso esteja divergindo
  xk=x;
  for i = 1:n                       %método propriamente dito
    x(i) = (1/A(i, i))*(b(i) - A(i, 1:n)*x + A(i, i)*x(i));
  end
  
  if(abs((max(x-xk)/max(x))< tol))  %critério de parada
          break;                    %Se ele for atingido, sai do loop infinito
  end
end

t = toc;

for i = 1:n 
  if isnan(x(i)) || isinf(x(i))
    converge = 0;
  end
end
