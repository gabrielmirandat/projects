media [] _ = []
media _ [] = []
media (x:xs) (y:ys) = (x+y)/2:media xs ys
