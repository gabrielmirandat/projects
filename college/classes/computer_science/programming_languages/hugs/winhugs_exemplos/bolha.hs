bolhac []  = []
bolhac [x] = [x]
bolhac (x:y:ys)
	| x>y = y:bolhac (x:ys)
	| otherwise = x:bolhac (y:ys)
bolha m (x:xs) 
	| m==1 = bolhac (x:xs)
	| m==0 = (reverse.bolhac) (x:xs)