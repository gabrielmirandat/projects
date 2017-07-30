mdc a b          
	| b == 0  = a          
	| otherwise  = mdc b (a `mod` b)
