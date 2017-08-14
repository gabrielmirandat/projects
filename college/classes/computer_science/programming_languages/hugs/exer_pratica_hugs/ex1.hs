elem4_iguais :: Eq a => [a] -> Bool
elem4_iguais [x,y,z,w] = 
						if x == y && y == z && z == w then True else False
						
elem4_iguais2 :: Eq a => [a] -> Bool
elem4_iguais2 [_] = True 
elem4_iguais2 all@(x:y:_) = x == y && elem4_iguais2 (tail all)