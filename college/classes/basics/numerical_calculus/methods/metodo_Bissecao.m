%Método Bisseção
close all;
clear all;
clc

syms x;

prompt = 'Insira a função ';
func = input(prompt); 

prompt = 'Insira o limite inferior. ';
a = input(prompt);

prompt = 'Insira o limite superior. ';
b = input(prompt);

prompt = 'Insira a precisão ';
prec = input(prompt);

tic;
i=0;
while((b-a)>=prec) %subs(s,old,new)
    syms x;
    
    parcial = (a+b)/2;
    
    f_1 = func;
    f_2 = func;
    f_3 = func;
    
    
    f_1 = subs(f_1,x,a);
    f_2 = subs(f_2,x,b);
    f_3 = subs(f_3,x,parcial);
    
    menor=100;
    
    if(f_1*f_2<0 && abs(f_1*f_2<menor))
        a=min(a,b);
        b=max(a,b);
    end
    if(f_1*f_3<0 && abs(f_1*f_3<menor))
        a=min(a, parcial);
        b=max(a, parcial);
    end
    if(f_2*f_3<0 && abs(f_2*f_3<menor))
        a=min(b, parcial);
        b=max(b, parcial);
    end
i=i+1;    
end

t = toc;
disp('Tempo de processamento(segundos):');
disp(t);

disp(double(parcial));
disp(i);

%ezplot(func);
%grid on;