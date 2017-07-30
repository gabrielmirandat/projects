%Forma de Lagrange
clear; 
clc;

prompt = 'Insira os valores de X:'; %devem ser lidos no formato [x1 x2 x3]
X = input(prompt);

prompt = 'Insira os valores de Y:'; %devem ser lidos no formato [y1 y2 y3]
Y = input(prompt);

prompt = 'Insira o valor de x a ser estimado:'; %devem ser lidos no formato [y1 y2 y3]
ini = input(prompt);

tic;

n=length(X); %A base do polinomio de Lagrange é de ordem n-1 e tem n coeficientes

lj = zeros(1,n); %armazena numeradores do polinomio
Lj = zeros(n); %armazena coeficientes da matriz base de Lagrange
L  = zeros(1,n); %os coeficientes finais propriamente ditos

jr=1:n; %j-range: 1<=j<=n
for j=jr
    mr=jr(jr~=j); %m-range: 1<=m<=n, m~=j
    lj=poly(X(mr)); %numerador de lj(x)
    mult=1/polyval(lj,X(j)); %denominador of lj(x)
    Lj(j,:) = mult * lj; %jth lj(x) do polinômio base de Lagrange
end
L = Y*Lj; %coeficientes do polinômio de Lagrange L(x)

t = toc;
disp('Tempo de processamento(segundos):');
disp(t);

disp('Coeficientes encontrados:');
disp(L);

disp('Valor no ponto selecionado:');
disp(polyval(L,ini));


%jr=1:n; %j-range: 1<=j<=n
%for j=jr %my j is your k
%    multiplier = 1;
%   outputConv = 1; %numerator of lj(x)
%    mr=jr(jr~=j); %m-range: 1<=m<=n, m~=j
%    for m = mr %my m is your index
%        outputConv = conv(outputConv,[1 -X(m)]);
%        multiplier = multiplier * ((X(j) - X(m))^-1);
%    end
%    Lj(j,:) = multiplier * outputConv; %jth Lagrange basis polinomial lj(x)
%end
%L = Y*Lj; %coefficients of Lagrange polinomial L(x)

