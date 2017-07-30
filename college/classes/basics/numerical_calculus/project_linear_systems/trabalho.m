%Trabalho Cálculo Numérico
close all;
clc

% --------------------------FORMA DE USAR-------------------------- %
%  Se o sistema é:  10x1 +  2x2  +  x3  =  7                        %
%                     x1 +  5x2  +  x3  = -8                        %
%                    2x1 +  3x2  +10x3  =  6 .                      %
%  O erro é E = 0.05.                                               %
%  e a aproximação inicial é x_0 = |0.7 |                           %
%                                  |-1.6|                           %
%                                  |0.6 |                           %
%  Então as entradas devem ser(o que está dentro das aspas simples):%
%  A = '[10 2 1;1 5 1;2 3 10]'                                      %
%  b = '[7;-8;6]'                                                   %
%  x0 = '[0.7;-1.6;0.6]'                                            %
%  tol = '0.05'                                                     %
%                                                                   %

disp('-----------------TRABALHO COMPUTACIONAL-----------------');
disp('1. Apenas Gauss_Jacobi');
disp('2. Apenas Gauss_Seidel');
disp('3. Ambos os métodos');
prompt = 'Faça sua escolha:';
resp = input(prompt);


if(resp~=1 && resp~=2 && resp~=3)
    disp('Entrada inválida. Programa encerrado.');
    exit();
end

prompt = 'Insira a matriz: ';
A = input(prompt);

prompt = 'Insira o resultado do sistema: ';
b = input(prompt);

prompt = 'Insira a aproximacao inicial: ';
x0 = input(prompt);

prompt = 'Insira o erro maximo: ';
tol = input(prompt);

if(resp==1 || resp==3)
    [t_1,iter_1,x_1,converge_1] = gauss_Jacobi_func(A,b,x0,tol);
    if(converge_1==0)
        fprintf('\nO sistema escolhido não converge com Gauss Jacobi\n\n');
    end
end

if(resp==2 || resp==3)
    [t_2,iter_2,x_2,converge_2] = gauss_Seidel_func(A,b,x0,tol,500);
     if(converge_2==0)
        fprintf('\nO sistema escolhido não converge com Gauss Seidel\n\n');
    end
end

if(resp==1)
    printa_resultados(t_1,iter_1,x_1);
elseif(resp==2)
    printa_resultados(t_2,iter_2,x_2);
elseif(resp==3) 
    fprintf('\t\tMétodo\t\t\tTempo\t\tIterações\tResultado\n');
    fprintf('\t\tGauss Jacobi\t%f\t%d\t\t\t%s\n',t_1,iter_1, mat2str(x_1'));
    fprintf('\t\tGauss Seidel\t%f\t%d\t\t\t%s\n',t_2,iter_2, mat2str(x_2'));
    fprintf('\t\tDiferença\t\t\t\t\t\t\t\t%s\n',mat2str(abs(x_1-x_2)'));
end