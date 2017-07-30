fib(N,F) :- fibx(N,1,1,F), !. 
fibx(0,A,_,A). 
fibx(N,A,B,F) :- N1 is N - 1, AB is A + B, fibx(N1,B,AB,F).
