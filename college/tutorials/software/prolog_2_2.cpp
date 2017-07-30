##############################################################################################################################
.  			    			|parada cheia. Sem ela o Prolog não avalia a query.

cabeça_regra -: corpo_regra 			|pode ser lido como if. 
					        |se o corpo da regra é verdadeira, então sua cabeça é verdadeira.
					        
,						|conjunção lógica. AND	
;						|disjunção lógica. OR

:-						|implicação
##############################################################################################################################




Chapter 1
Facts, Rules, and Queries 

-3 construções base em Prolog: Fatos, regras e queries.
-base de conhecimentos: conjunto de fatos e regras.
-claúsulas = fatos e regras contidas numa base de conhecimentos.	.ex: 2 fatos, 3 regras = 5 cláusulas

#happy(yolanda).
#listens2Music(mia).
#listens2Music(yolanda):-  happy(yolanda).
#playsAirGuitar(mia):-  listens2Music(mia).
#playsAirGuitar(yolanda):-  listens2Music(yolanda). 

Esta base tem 3 predicados: 
'listens2Music'
'happy'
'playsAirGuitar'

#?-  loves(marsellus,X),  woman(X).		//X = mia
Existe algum individuo X que marsellus ama e que é mulher? 

1-1.2



   
   
   