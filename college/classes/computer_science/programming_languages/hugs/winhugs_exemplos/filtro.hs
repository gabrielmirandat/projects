par x = x `mod` 2 == 0

impar x = x `mod` 2 == 1

filtro p (x:xs)
 | p x = x:filtro p xs
 | otherwise = filtro p xs
filtro _ [] = []