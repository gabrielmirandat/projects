%Método de Gauss-Jacobi
function [t,iter,x,converge] = gauss_Jacobi_func(A,b,x0,tol)

%A - matriz
%b - resultado
%x0 - aproximcao inicial
%tol - erro minimo
%objetivo: transformar Ax + b em x = Cx + g     

tic;
n = length(A);
L=-tril(A,-1); % extrai a parte triangular inferior da matriz
U=-triu(A,1); % extrai a parte triangular superior da matriz
D=diag(diag(A)); % extrai os elementos da diagonal principal da matriz
N=L+U;
C=D\N;
G=D\b;
iter=1;
x = C*x0 + G;
converge = 1;

while norm(x-x0)>tol*norm(x0)
    x0 = x;
    x = C*x0 + G;
    iter = iter + 1;
end

t = toc;

for i = 1:n 
  if isnan(x(i)) || isinf(x(i)) || iter>1000
    converge = 0;
  end
end