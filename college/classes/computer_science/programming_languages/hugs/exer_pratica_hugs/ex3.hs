somatD :: [Double] -> Double
somatD x = foldl (+) 0 x

somatI :: [Int] -> Int
somatI x = foldl (+) 0 x

tamanho :: [Double] -> Double
tamanho x = somatD [1 | n <- x]	

acima_media :: [Double] -> Int
acima_media x = somatI [1 | n <- x, n > (somatD x / tamanho x)]	
				