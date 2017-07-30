%M�todo Newton
close all;
clear all;
clc

syms x;
prompt = 'Insira a fun��o ';
func = input(prompt); 

prompt = 'Insira o x0. ';
xk = input(prompt);

prompt = 'Insira a precis�o ';
prec = input(prompt);

prompt = 'Insira o limite inferior. ';
a = input(prompt);

prompt = 'Insira o limite superior. ';
b = input(prompt);

%if(xk<a || xk>b)
%    disp('Erro! A fun��o diverge.');
%    exit;
%end

syms x;
func_der = diff(func);

tic;

i=0;
while(true)
  parcial1 = subs(func,x,xk);
  parcial2 = subs(func_der,x,xk);
  
  xk1 = xk - (parcial1/parcial2);
  
  if (abs(xk1-xk)<prec)
      break;
  end
  
  xk = xk1;
  i=i+1;
end

t = toc;
disp('Tempo de processamento(segundos):');
disp(t);

disp('\nO zero da fun��o ');
disp(func);
disp(' �');
disp(double(xk1));
disp(i);
