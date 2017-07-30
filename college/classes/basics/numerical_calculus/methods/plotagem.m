close all;
clear all;

%syms x;
%ezplot(x^3 - 9*x +3);
%grid on;

old = digits(25);

digits(old)



x= 1.5;
func = vpa('exp(-x^2) - cos(x)');
disp(func);

func2 =vpa(' -2*x*exp(-x^2) + sen(x)');
disp(func2);


digits(old)