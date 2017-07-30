import Hugs.Char (ord, chr)
tecla = do putStr "\n Qual a tecla? > "
	   carac <- getChar 
	   putStr (show (ord carac))
	   if carac == '\ESC' then (return ()) 
                             else tecla