%Método Secante
close all;
clear all;
clc

syms x;
prompt = 'Insira a função ';
func = input(prompt); 

prompt = 'Insira o x0. ';
x0 = input(prompt);

prompt = 'Insira o x1. ';
x1 = input(prompt);

prompt = 'Insira a precisão ';
prec = input(prompt);

tic;

i=0;
while(true)
  parcial0 = subs(func,x,x0);
  parcial1 = subs(func,x,x1);
  
  x2 = (x0*parcial1 - x1*parcial0)/(parcial1 - parcial0);
  
  if (abs(x1-x0)<prec)
      break;
  end
  
  x0 = x1;
  x1 = x2;
  i=i+1;
end

t = toc;
disp('Tempo de processamento(segundos):');
disp(t);

disp('\nO zero da função ');
disp(func);
disp(' é');
disp(double(x2));
disp(i);
