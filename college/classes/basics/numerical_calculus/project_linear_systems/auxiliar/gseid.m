function [P,dP,Z] = gseid(A,B,P,delta,max1)
%---------------------------------------------------------------------------
%GSEID   Gauss-Seidel iteration for solving a linear system.
% Sample call
%   [X,dX] = gseid(A,B,P,delta,max1)
%   [X,dX,Z] = gseid(A,B,P,delta,max1)
% Inputs
%   A       coefficient matrix
%   B       right hand side vector
%   P       starting vector
%   delta   convergence tolerance
%   max1    maximum number of iterations
% Return
%   X       solution vector
%   dX      error estimate vector
%   Z       History matrix of the iterations
%
% NUMERICAL METHODS: MATLAB Programs, (c) John H. Mathews 1995
% To accompany the text:
% NUMERICAL METHODS for Mathematics, Science and Engineering, 2nd Ed, 1992
% Prentice Hall, Englewood Cliffs, New Jersey, 07632, U.S.A.
% Prentice Hall, Inc.; USA, Canada, Mexico ISBN 0-13-624990-6
% Prentice Hall, International Editions:   ISBN 0-13-625047-5
% This free software is compliments of the author.
% E-mail address:      in%"mathews@fullerton.edu"
%
% Algorithm 3.5 (Gauss-Seidel Iteration).
% Section	3.7, Iterative Methods for Linear Systems, Page 187
%---------------------------------------------------------------------------

Z = P';
n = length(B);
Pold = P;
for k=1:max1,
  for r = 1:n,
    Sum1 = B(r) - A(r,[1:r-1,r+1:n])*P([1:r-1,r+1:n]);
    P(r) = Sum1/A(r,r);
  end
  dP = abs(Pold-P);
  err = norm(dP);
  relerr = err/(norm(P)+eps);
  Pold = P;
  Z = [Z;P'];
  if (err<delta)|(relerr<delta), break, end
end
