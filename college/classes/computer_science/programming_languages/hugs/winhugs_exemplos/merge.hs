merge xs ys = 
     case (xs,ys) of 
         (z:zs,w:ws) | z<=w -> z:merge zs ys
                     | z>w  -> w:merge xs  ws
         ([],ws) 	    -> ws
         (zs,[]) 	    -> zs
