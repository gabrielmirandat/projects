import { Component } from '@angular/core';
import { HeroesComponent }  from './heroes.component';

import { RouterModule }   from '@angular/router';

@Component({
	selector: 'my-app',

	template:
	`
		<h1>{{title}}</h1>

		<my-heroes></my-heroes>
	`,
	
})

RouterModule.forRoot([
  {
    path: 'heroes',
    component: HeroesComponent
  }
])

export class AppComponent
{
	title = 'Tour of Heroes';
}