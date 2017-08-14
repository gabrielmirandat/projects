var xs = (sum . map (^2)) xs / fromIntegral(n) - (sum xs / fromIntegral(n))^2
	where n = length xs
