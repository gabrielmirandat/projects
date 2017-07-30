import { Injectable } from '@angular/core';
import { Hero } from './hero';
import { HEROES } from './mock-heroes'; /*Importa esse array desse arquivo*/

@Injectable() export class HeroService 
{
	getHeroes(): 
	Promise<Hero[]> /*Retorno de Promessa de um array de herois*/
	{
		return Promise.resolve(HEROES);
	}

	getHeroesSlowly():
	Promise<Hero[]>  /*Retorno de Promessa de um array de herois*/
	{
  		return new Promise(resolve => 	{	// Simulate server latency with 2 second delay
    										setTimeout(() => resolve(this.getHeroes()), 2000);
  									  	}
  						   );
	}
}

