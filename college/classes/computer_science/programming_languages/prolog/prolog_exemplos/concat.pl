concat([],Ys,Ys).    					% fato
concat([X|Xs],Ys,[X|Zs]) :- concat(Xs,Ys,Zs).    	% regra

