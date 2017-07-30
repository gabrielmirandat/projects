function [ x ] = iterative_gauss_method( A,b,n )
%%check if gauss-seidel method is applicable

[si,sj]=size(A);
if si~=sj
    disp('error matrix is not square');
    return
end
if prod(diag(A))==0
    disp('gauss-seidel iterative method is not applicable');
    return
end
E=tril(A,-1);
F=triu(A,1);
D=A-E-F
Bj=-inv(D)*(E+F);
rho=max(abs(eig(Bj))); %spectral radius
if rho>=1
    disp('gauss-seidel method do not converge');
    return
end
y=zeros(si,n);
tic
for i=[1:1:n]
 y(:,i+1)=inv(D+E)*(b-F*y(:,i));
end
x=y(:,n);
execution_time=toc
end