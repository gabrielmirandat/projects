%Forma de Newton
clear; 
clc;

prompt = 'Insira os valores de X:'; %devem ser lidos no formato [x1 x2 x3]
x = input(prompt);

prompt = 'Insira os valores de Y:'; %devem ser lidos no formato [y1 y2 y3]
y = input(prompt);

prompt = 'Insira o valor de x a ser estimado:'; %devem ser lidos no formato [y1 y2 y3]
ini = input(prompt);

tic;
n = length(x);
a(1) = y(1);

for k = 1 : n - 1
   d(k, 1) = (y(k+1) - y(k))/(x(k+1) - x(k));
end

for j = 2 : n - 1
   for k = 1 : n - j
      d(k, j) = (d(k+1, j - 1) - d(k, j - 1))/(x(k+j) - x(k));
   end
end

for j = 2 : n
   a(j) = d(1, j-1);
end

Df(1) = 1;
c(1) = a(1);

for j = 2 : n
   Df(j)=(ini - x(j-1)) .* Df(j-1);
   c(j) = a(j) .* Df(j);
end
fp=sum(c);

t = toc;
disp('Tempo de processamento(segundos):');
disp(t);

disp('Operadores de diferenças divididas:');
disp(a);

disp('Valor no ponto selecionado:');
disp(fp);