--PARTE 1
--questao 1
elem4_iguais :: Eq a => [a] -> Bool
elem4_iguais [x,y,z,w] = 
						if x == y && y == z && z == w then True else False
						
--questao 3
qsort :: Ord a => [a] -> [a]
qsort ls = case ls of
	[] 	-> []
	[x]     -> [x]
	otherwise -> qsort ys ++ [x] ++ qsort zs
	where 
		(x:xs) = ls
		ys = [y | y <- xs, y <  x] 
		zs = [z | z <- xs, z >= x]

mesmos_elem :: Ord a => [a] -> [a] -> Bool
mesmos_elem x1 x2 = 
			if qsort x1 == qsort x2 then True else False 
			
			
--questao 5
palindrome :: [a] -> [a]
palindrome x = x ++(reverse x)

--PARTE 2
--questao 7
(-*-) :: Eq a => [a] -> [a] -> [a]
(-*-) x y =  [a | a <- x ,elem a y]

--questao 8
altura :: (RealFloat a) => a -> String  
altura altura_metros  
    | altura_centimetros <= 150.0 = "Como voce eh baixinho!"  
    | altura_centimetros <= 180.0 = "Voce esta bem na media!"  
    | altura_centimetros <= 200.0 = "Voce eh bem alto"  
    | otherwise   = "Voce eh gigantesco!"  
    where altura_centimetros = altura_metros * 100.0
	
--questao 9
vol_esfera :: Double -> Double
vol_esfera x = (let raio = x in 4.0*3.14*raio^3/3.0)

--questao 10
hipotenusa :: Floating a => [(a,a)] -> [a]
hipotenusa x = map (\(a,b) -> sqrt (a^2 + b^2)) x

--questao 11
pegar_invertido :: Int -> [a] -> [a]
pegar_invertido k x = take k (reverse x)

--questao 12
soma_infinito :: Num a => Int -> [a] -> a
soma_infinito n x  
    | n == 1 = sum (take 1 x)
    | n == 2 = sum (take 2 x)
    | n == 3 = sum (take 3 x)
    | otherwise  = sum (take n x)

--PARTE 3
--questao 13
map3 :: (a -> b) -> [a] -> [a] -> [a] -> [(b,b,b)]
map3 f [] [] [] = []
map3 f (x:xs) (y:ys) (z:zs) = (f x,f y,f z): map3 f xs ys zs