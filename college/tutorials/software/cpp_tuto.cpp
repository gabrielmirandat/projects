	#include <iostream> = Este arquivo espec�fico (iostream) inclui as declara��es da biblioteca de entrada-sa�da padr�o 
b�sico em C ++.

	using namespace std; = Todos os elementos da biblioteca padr�o C ++ s�o declarados dentro do que � chamado de namespace, o
namespace com o nome std. Portanto, a fim de acessar a sua funcionalidade, declaramos com esta express�o que iremos utilizar
essas entidades. Esta linha � muito frequente em programas em C ++ que usam a biblioteca padr�o, e na verdade ele ser� 
inclu�do na maioria dos c�digos-fonte inclu�dos nestes tutoriais. 

	cout << "Hello World!"; = 'cout' representa o fluxo(stream) de saida padr�o do C++,a tela. A declara��o tem significado de inserir 
uma sequ�ncia de caracteres no fluxo de saida padr�o.

	cout << result; = printa vari�vel resultado.
	
	
	int a = 0;    //tipo c                      = formas de inicializar vari�veis
	int a (0);    //tipo construtor
	
#	#include <string>                           = uso da classe de string
#       using namespace std;
#	string mystring = "This is a string" ;
#	cout << mystring;

	string mystring = "This is a string";       = formas de inicializar strings 
	string mystring ("This is a string");
	
#	string mystring;                            = printa a vari�vel mystring na tela com um "endl" (fim de lin)
#	mystring ="This is the initial string content";
#	cout << mystring << endl; 

	75    // decimal
	0113  // octal(0 no inicio)
	0x4b  // hexadecimal(0x no inicio) 
	

	    =transformando int em:(Mai ou min) 
	75    // int
	75u   // unsigned int
	75l   // long	
	75ul  // unsigned long 
	
	
	    =formas de representar ponto-flutuante
	3.14159      // 3.14159
	6.02e23      // 6.02 x 10^23
	1.6e.19      // 1.6 x 10^.19
	3.0          // 3.0 
	
	    =transformando double em:(Mai ou min)
	3.14159L  // long double
	6.02e23f  // float 
	
	    =representar ASCII pelos seus c�digos na tabela
	/23  (OCTAL)
	/x4A (HEXA)
	
	
	    =definindo constantes
	#define PI 3.14159
	#define NEWLINE '\n' 
	
	    =definindo constantes de tipo defin�vel
	const int pathwidth = 100;
	const char tabulator = '\t';
	
	Example 1 (prefixo)			Example 2 (sufixo)
#       B=3;                            B=3;
#	A=++B;                          A=B++;
#	// A contains 4, B contains 4   // A contains 3, B contains 4
	

	
	operator		asm equivalent		description

	    &			    AND			 Bitwise AND
	    |			    OR 			Bitwise Inclusive OR
	    ^			    XOR 		Bitwise Exclusive OR
	    ~		    NOT Unary complement 	(bit inversion)
	    <<			    SHL 		Shift Left
	    >>			    SHR 		Shift Right 
	    
	    
	 	    
	cout <<"Hello, "<<"I am "<<"a C++ statement";
	cout <<"Hello, I am "<< age <<" years old and my zipcode is "<< zipcode;             //altera vari�veis e constantes
	
	cout <<"First sentence."<< endl;
        cout <<"Second sentence."<< endl;                                                    //escreve com pula linha "endl",mas tamb�m tem um comportamento adicional quando �
                                                                                             //utilizada com buffered streams: o buffer � descarregado.
                                                                                             
                                                                                             
        int age;
	cin >> age; 
	
	cin >> a >> b; � o mesmo:                                                            //usuario deve fornecer duas entradas
	
	cin >> a;
	cin >> b;
	
	string str;
	cin >> str; 									     //armazena s� uma palavra
	
	getLine(cin,str);								     //armazena uma frase
	
	
	
	
	
	      #include <string>
	      #include <sstream>
	      stringstream

        O arquivo deheader padr�o <sstream> define uma classe chamada stringstream que permite que um objeto com base em string seja tratado como um stream. 
        Dessa forma, podemos realizar opera��es de extra��o ou de inser��o de / para strings, o que � especialmente �til para converter strings para valores 
        num�ricos e vice-versa.
        
# 	string mystr ("1204");								    //joga o valor 1204 p/ o inteiro myint 
#	int myint;
#	stringstream(mystr) >> myint;
    
	    
	    
	    
	'Nomes de macros pre-definidas'
Os seguintes nomes de macro s�o definidos a qualquer momento

		  macro				value
		__LINE__ 		Valor inteiro que representa a linha  corrente no arquivo de c�digo-fonte que est� sendo compilado.
		__FILE__ 		String literal contendo o presente nome do arquivo de origem a ser compilado.
		__DATE__		Uma string literal na forma "Mmm dd yyyy" contendo a data em que o processo de compila��o come�ou.
		__TIME__ 		A string literal no formato 'hh: mm: ss' contendo o momento em que o processo de compila��o come�ou.
		__cplusplus		Um valor inteiro. Todos C++ compiladores t�m esta constante definida para algum valor. Se o compilador � totalmente em conformidade 
					com o padr�o C ++ seu valor ser� igual ou maior do que 199711L, dependendo da vers�o da norma.

					
	'Arquivos stream'
Modos de abertura usando 'open'

		 Modo        		Tipo
	       ios::in 			Open for input operations
	       ios::out 		Open for output operations.
	      ios::binary 		Open in binary mode.
		ios::ate 		Set the initial position at the end of the file.If this flag is not set to any value, the initial position is the beginning of the file.
		ios::app		All output operations are performed at the end of the file, appending the content to the current content of the file. This flag can
					  only be used in streams open for output-only operations.
	      ios::trunc		If the file opened for output operations already existed before, its previous content is deleted and replaced by the new one.
	      
	      
Modo 'defalt' sem especificar parametros ao modo

	      class	default mode parameter
	  ofstream  		ios::out
	  ifstream		ios::in
	  fstream 		ios::in | ios::out
	  
	'Checando flags de estado'
	bad() 				Returns true if a reading or writing operation fails. For example in the case that we try to write to a file that is not open for
					  writing or if the device where we try to write has no space left.
	fail()				Returns true in the same cases as bad(), but also i n the case that a format error happens, like when analphabetical character is 
					  extracted when we are trying to read an integer number.
	eof()				Returns true if a file open for reading has reached the end.
	good()				It is the most generic state flag: it returns false in the same cases in which calling any of the previous functions would return true.
					  In order to reset the state flags checked by any of these member functions we have just seen we can use the member function clear()
					  ,which takes no parameters. 
					  
	'seekg() and seekp()'
	    seekg ( position );
	    seekp ( position );
	    
	    seekg ( offset, direction );
	    seekp ( offset, direction );
	    
	    ios::beg				offset counted from the beginning of the stream
	    ios::cur				offset counted from the current position of the stream pointer
	    ios::end				offset counted from the end of the stream 
	    
	    
	    
	  
	  
	  