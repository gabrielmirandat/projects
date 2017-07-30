%Método PontoFixo
close all;
clear all;
clc

syms x;
prompt = 'Insira a função ';
func = input(prompt); 

syms x;
prompt = 'Insira a função de iteração ';
func_it = input(prompt); 

prompt = 'Insira o x0. ';
xk = input(prompt);

prompt = 'Insira a precisão ';
prec = input(prompt);

prompt = 'Insira o limite inferior. ';
a = input(prompt);

prompt = 'Insira o limite superior. ';
b = input(prompt);

if(xk<a || xk>b)
    disp('Erro! A função diverge.');
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

disp('\nO zero da função ');
disp(func);
disp(' é');
disp(double(xk1));
disp(i);
