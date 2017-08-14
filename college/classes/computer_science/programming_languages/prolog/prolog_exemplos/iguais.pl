iguais([X|Xs],[Zs]):- [Xs]==[],!.					% fato
iguais([X,Y|Ys],[Zs]) :- X==Y, iguais([Y|Ys],[X|Zs).    	% regra
    
