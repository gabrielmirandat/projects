%M�todo PontoFixo
close all;
clear all;
clc

syms x;
prompt = 'Insira a fun��o ';
func = input(prompt); 

syms x;
prompt = 'Insira a fun��o de itera��o ';
func_it = input(prompt); 

prompt = 'Insira o x0. ';
xk = input(prompt);

prompt = 'Insira a precis�o ';
prec = input(prompt);

prompt = 'Insira o limite inferior. ';
a = input(prompt);

prompt = 'Insira o limite superior. ';
b = input(prompt);

if(xk<a || xk>b)
    disp('Erro! A fun��o diverge.');
    exit;
end

tic;

i=0;
while(true)
  syms x;
  xk1 = subs(func_it,x,xk);
  
  if (abs(xk1-xk)<prec)
      disp(xk1-xk);
      disp('\n');
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
