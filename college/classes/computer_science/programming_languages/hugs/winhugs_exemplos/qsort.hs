qsort ls = case ls of
	[] 	-> []
	[x]     -> [x]
	otherwise -> qsort ys ++ [x] ++ qsort zs
	where 
		(x:xs) = ls
		ys = [y | y <- xs, y <  x] 
		zs = [z | z <- xs, z >= x]