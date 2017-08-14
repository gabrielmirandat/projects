pega n ys = case (n,ys) of
	(0,_)     ->  []
	(_,[])    ->  []
	(n,x:xs) ->  x : pega (n-1)  xs