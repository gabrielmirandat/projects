qsort ls = case ls of
	[] 	-> []
	[x]     -> [x]
	otherwise -> qsort ys ++ [x] ++ qsort zs
	where 
		(x:xs) = ls
		ys = [y | y <- xs, y <  x] 
		zs = [z | z <- xs, z >= x]

mesmos_elem x1 x2 = 
			if qsort x1 == qsort x2 then True else False 