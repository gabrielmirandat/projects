Seção2:19

declarations: [ 	// inclui diretivas usadas no app.
					// geralmente incluimos aqui.
	AppComponent,   
],

imports: [ 			// inclui os módulos que serão usados na aplicação.
	 				// Geralmente de imports.
	BrowserModule, 
	FormsModule, 
	HttpModule
],

providers: [		// inclui os serviços usados no app.
	// --
],

// Gera uma component nova
$ ng generate component other

// Gera uma component nova
// g - generate
// c - component
// --flat - para não criar um subdiretório
// -is - para não criar um arquivo de estilos css
// -it - para não criar um arquivo html
$ ng g c another --flat -is -it