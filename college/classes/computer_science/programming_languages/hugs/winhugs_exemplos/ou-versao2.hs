membro z [] = False
membro z (w:ws) = z==w || membro z ws

(x:xs) \/ ys 	| xs == [] = ys
		| membro x ys = resto
		| otherwise = x:resto
	where resto = xs \/ ys