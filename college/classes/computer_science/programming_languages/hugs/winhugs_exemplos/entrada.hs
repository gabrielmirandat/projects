entrada = do  putStr "\n dados> " 
              dados <- getLine
              putStr "Digitado: "
	      putStr (concat [dados, "\n"])
              putStr "continua, (s/n)?"
              carac <- getChar
              if carac=='S' || carac=='s' then entrada 
                                          else return ()