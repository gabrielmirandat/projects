map f xs = [f x | x <- xs]
map2 f xs ys = [f x y | (x,y) <- zip xs ys]