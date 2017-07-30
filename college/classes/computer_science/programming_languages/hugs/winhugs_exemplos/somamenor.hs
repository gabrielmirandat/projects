somamenor m xs
	| length xs <= 1 = []
	| z < m        = (x,y,z):somamenor m (y:t)
	| otherwise    = somamenor m (y:t) where (x:y:t) = xs; z = x+y
