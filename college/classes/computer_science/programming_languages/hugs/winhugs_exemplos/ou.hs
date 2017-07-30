membro z [] = False
membro z (w:ws) = z==w || membro z ws

[] \/ ys = ys
(x:xs) \/ ys 	| membro x ys  = xs \/ ys
		| otherwise    = x: xs \/ ys	