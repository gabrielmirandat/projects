Projeto:
  -Tema desenvolvido.
  @' Mineração de dados do twitter usando python.'
  'http://marcobonzanini.com/2015/03/02/mining-twitter-data-with-python-part-1/'

Linguagem: histórico, versão (0,5):
  - Autores,
  @'O Python foi concebido no final de 1989 por Guido van Rossum no Instituto de Pesquisa Nacional 
  para Matemática e Ciência da Computação (CWI), nos Países Baixos. Concebida em 1991.'
  'https://pt.wikipedia.org/wiki/Python'
  
  - motivação para criação,
  @'Necessidade de uma linguagem alto nível para o projeto Amoeba, do qual o autor fazia parte.'
  'http://python-history.blogspot.com.br/2009/01/personal-history-part-1-cwi.html'
  'http://effbot.org/pyfaq/why-was-python-created-in-the-first-place.htm'
  
  - contexto de criação,
  @'Sendo Amoeba um sistema distribuído baseado em microkernel, Guido percebeu que o desenvolvimento de utilitários para a 
  administração do sistema em C estava tomando muito tempo. E fazê-los no shell Bourne não funcionaria por diversas razões. 
  O mais importante foi que, sendo um sistema distribuído de microkernel, as operações primitivas do Amoeba eram bem diferentes
  (e refinadas) que as operações primitivas disponíveis no shell Bourne. Portanto, havia necessidade de uma linguagem que 
  "preencheria o vazio entre C e o shell". Por um tempo longo, esse foi o principal lema de Python.'
  'http://python-history.blogspot.com.br/2009/01/personal-history-part-1-cwi.html'
  'http://effbot.org/pyfaq/why-was-python-created-in-the-first-place.htm'
  
  - versões,
  @'Python 1.0 - January 1994
        Python 1.5 - December 31, 1997
        Python 1.6 - September 5, 2000
    Python 2.0 - October 16, 2000
        Python 2.1 - April 17, 2001
        Python 2.2 - December 21, 2001
        Python 2.3 - July 29, 2003
        Python 2.4 - November 30, 2004
        Python 2.5 - September 19, 2006
        Python 2.6 - October 1, 2008
        Python 2.7 - July 3, 2010
    Python 3.0 - December 3, 2008
        Python 3.1 - June 27, 2009
        Python 3.2 - February 20, 2011
        Python 3.3 - September 29, 2012
        Python 3.4 - March 16, 2014
        Python 3.5 - September 13, 2015'
  'https://en.wikipedia.org/wiki/History_of_Python'
  'https://www.python.org/doc/versions/'
  
  - diferenças entre as versões,
  @'	1.0 - funções funcionais lambda, map, filter and reduce (haskell).
	1.5 - argumentos de teclado inspirados no Modula-3
	    - suporte para números complexos 
	    - parâmetros nomeados (a capacidade de passar parâmetro pelo nome e não pela posição na lista de parâmetros)
	    - forma básica de esconder dados por name mangling
	1.6 - nova licensa CNRI
	2.0 - introduz o  list comprehensions das linguagens funcionais (haskell).	ex.: s = [ 2*x | x <- [0..], x^2 > 3 ]
	    - introduz sistema coletor de lixo capaz de coletar referências cíclicas.
	2.1 - mudança na especificação da linguagem para suportar escopos aninhados como outras linguagens de escopo estático.
	2.2 - unificação de tipos python (escritos em C) e classes (escritas em python) em uma hierarquia, o que tornou python puramente 
	      orientada a objetos.
	    - adicionou generators e Icon.
	2.6 - bibliotecas para multiprocessamento, JSON e entrada/saída.
	    - nova formatação de cadeia de caracteres
	3.0 - correção de falhas fundamentais de projeto 
	    - "reduce feature duplication by removing old ways of doing things"
	    - tornou-se então multiparadigma.
	    - tratamento de print como função e não como palavra reservada.
	    - retirou compatibilidade com 2.x.
	    - mudou a divisão inteira (In Python 2, 5 / 2 is 2. In Python 3, 5 / 2 is 2.5, and 5 // 2 is 2).
  '
  'https://en.wikipedia.org/wiki/History_of_Python'
  'https://pt.wikipedia.org/wiki/Python'
  
  - versão utilizada na implementação do projeto.
  @'Foi usado python 3.x'
  
  
Projeto: premissas, usuário, domínio (0,5):
  - Premissas adotadas na criação da LP, (raciocínio para criar a linguagem)
  @'Python é uma linguagem de programação de alto nível[4] , interpretada, imperativa, orientada a objetos, funcional,
    de tipagem dinâmica e forte. A linguagem foi projetada com a filosofia de enfatizar a importância do esforço do programador sobre o 
    esforço computacional. Prioriza a legibilidade do código sobre a velocidade ou expressividade. Combina uma sintaxe concisa e clara
    com os recursos poderosos de sua biblioteca padrão e por módulos e frameworks desenvolvidos por terceiros. Possui 
    tipagem dinâmica e uma de suas principais características é permitir a fácil leitura do código e exigir poucas linhas de código se
    comparado ao mesmo programa em outras linguagens. Devido as suas características, ela é principalmente utilizada para processamento de 
    textos, dados científicos e criação de CGIs para páginas dinâmicas para a web.'
    'https://pt.wikipedia.org/wiki/Python'
  - caracterização do usuário característico previsto na criação da LP,
  @''
  'https://wiki.python.org/moin/OrganizationsUsingPython'
  'https://en.wikipedia.org/wiki/List_of_Python_software'
  - domínio de aplicação previsto para uso da LP.
  @'Python é usado em vários domínios de aplicações. 
    1) Desenvolvimento WEB e INTERNET: 
    - Oferece várias alternativas para desenvolvimento web:
	  #Frameworks como Django e Pyramid
	  #Micro-frameworks como Flask e Bottle
	  #Sistemas de gerenciamento de conteúdo avançadas, tais como Plone e django CMS.
    - Bibliotecas padrão suportam vários protocolos de internet:
	  #HTML and XML
	  #JSON
	  #Processamento de E-mai
	  #Suporte para  FTP, IMAP, e outros protocolos de internet.
	  #Interface socket de fácil uso.
    - Sendo que o Package Index tem ainda mais bibliotecas:
	  #Requests, poderosa biblioteca de cliente HTTP
	  #BeautifulSoup, um analisador HTML que pode lidar com todos os tipos de excentricidades do HTML
	  #Feedparser, para analisar feeds RSS/Atom
	  #Paramiko, implementa o protocolo SSH2
	  #Twisted Python, framework para programação assíncrona de rede.
    2) Científico e Numérico
    - Amplamente usado em cálculo científico e numérico:
	  #SciPy, coleção de pacotes para matemática, ciência e engenharia.
	  #Panda, biblioteca de análise de dados e modelagem.
	  #IPython, poderosa shell interativa que promove fácil edição e registro de sessões de trabalho, e suporta visualização e 
	   programação paralela.
    3) Educação
    - Python é uma linguagem excelente para o ensino de progração, tanto em um nível introdutório quanto em mais avançados.
    4) Desktop GUIs
    - A biblioteca Tk GUI está inclusa na maior parte das distribuições de python.
    - Algumas ferramentas bastante úteis são disponibilizadas separadamente:
	  #wxWidgets
	  #Kivy, para aplicações multitouch
	  #Qt, via pyqt ou pyside
    - Há também ferramentas específicas de plataformas
	  #GTK+
	  #extensões win32
    5) Desenvolvimento de software
    - Python é frequentemente usado como linguagem de suporte ao desenvolvimento de software, para gerir e controlar a arquitetura, testes
      e muitas outras.
	  #SCons para controlar arquiitetura
	  #Build e Apache Gump para compilação e teste continuo e automatizado
	  #Roundup ou Trac para rastrear bugs e desenvolver projetos.
    '		
  'http://stackoverflow.com/questions/1909512/what-is-python-used-for'
  'https://www.python.org/about/apps/'
  - Paradigma da LP.
  @'Python é uma linguagem de propósito geral de alto nível, multi paradigma, suporta o paradigma orientado a objetos, imperativo, 
    funcional e procedural.'
    'https://pt.wikipedia.org/wiki/Python'
    

Construtores: tipos, declarações e comandos (2):
  - Tipos de dados,
  @'Tipo de dado 	Descrição 				 			Exemplo da sintaxe
    str, unicode 	Uma cadeia de caracteres imutável 				'Wikipedia', u'Wikipedia'
    list 		Lista heterogênea mutável 					[4.0, 'string', True]
    tuple 		Tupla imutável 							(4.0, 'string', True)
    set, frozenset 	Conjunto não ordenado, não contém elementos duplicados 		set([4.0, 'string', True])
											frozenset([4.0, 'string', True])
    dict 		conjunto associativo 						{'key1': 1.0, 'key2': False}
    int 		Número de precisão fixa, é transparentemente convertido 
			para long caso não caiba em um int. 				42, 2147483648L
    float 		Ponto flutuante 						3.1415927
    complex 		Número complexo 						3+2j
    bool 		Booleano 							True ou False

    Python também permite a definição dos tipos de dados próprios, através de classes. Instâncias são construídas invocando a classe (FooClass()),
    e as classes são instância da classe type, o que permite metaprogramação e reflexão. Métodos são definidos como funções anexadas à classe, e a
    sintaxe instância.método(argumento) é um atalho para Classe.método(instância, argumento). Os métodos devem referenciar explicitamente a
    referência para o objeto incluindo o parâmetro self como o primeiro argumento do método.[23]
    Antes da versão 3.0, Python possuía dois tipos de classes: "old-style" e "new-style". Classes old-style foram eliminadas no Python 3.0, e 
    todas são new-style. Em versões entre 2.2 e 3.0, ambos tipos de classes podiam ser usadas. A sintaxe de ambos estilos é a mesma, a diferença 
    acaba sendo de onde objeto da classe é herdado, direta ou indiretamente (todas classes new-style herdam de object e são instancias de type). 
    As classes new-styles nada mais são que tipos definidos pelo usuário.'
    'https://pt.wikipedia.org/wiki/Python'
    
   @'Tipos primitivos: são aqueles já embutidos no núcleo da linguagem
      Simples: números (int, long, float, complex) e cadeias de caracteres (strings)
      Compostos: listas, dicionários, tuplas e conjuntos
      Tipos definidos pelo usuário: são correspondentes a classes (orientação objeto)'
    'http://www.dcc.ufrj.br/~fabiom/mab225/02tipos.pdf'
    
   @'
    Tipo inteiro:
    >>> a = 1
    >>> type(a)
    <type 'int'>
    
    
    Tipo ponto flutuante:
    >>> a = 1.0
    >>> type(a)
    <type 'float'>
    
    
    Tipo booleano:
    >>> a = True
    >>> type(a)
    <type 'bool'>
    
    
    Tipo complexo:
    >>> a = 4+3j
    >>> type(a)
    <type 'complex'>
    
    Podem mudar dinamicamente:
    >>> a = 1
    >>> type(a)
    <type 'int'>
    >>> a = 1.0
    >>> type(a)
    <type 'float'>
  ' 
  'https://pt.wikibooks.org/wiki/Python/Conceitos_b%C3%A1sicos/Tipos_e_operadores'
  'http://www.diveintopython3.net/native-datatypes.html'
  'https://en.wikibooks.org/wiki/Python_Programming/Data_Types'
  
  - declarações e comandos implementados na LP.
  @'Como python possui tipagem dinâmica, não exige declarações de tipos de dados, pois é capaz de escolher que tipo utilizar dinamicamente para 
  cada variável, podendo alterá-lo durante a compilação ou a execução do programa'
  'http://lpunb.wikia.com/wiki/Linguagem_Python_-_2/2012_Grupo_2'
  @'Python tem variáveis ​​locais e globais, como a maioria das outras linguagens , mas não tem declarações de variável explícitas. Variáveis ​​vão à 
  existência por ser atribuído um valor , e eles são automaticamente destruídos quando eles saem do escopo.'
  'http://www.diveintopython.net/native_data_types/declaring_variables.html'
  @'Operadores são símbolos que atuam sobre variáveis e valores. Existem:
      
      Operadores aritméticos (+, -, *, /, %, **, +=, -=, *=, /=, %=, **=):
	>>> a = 1
	>>> b = 2
	>>> print a + b
	3

	ou

	>>> a = 5
	>>> print a**2
	25
	
	
    Operadores de comparação (>, <, ==, >=, <=, <>, !=, is, in):
	>>> a = 1
	>>> b = 2
	>>> a == b
	False
	>>> print a > b
	False
	
    
    Operadores lógicos (and, or, not):
	>>> nome = "leonardo"
	>>> idade = 22
	>>> nome == "leonardo" and idade < 23
	True


    Operadores de atribuição (=):
	>>> a = 1'
  'https://pt.wikibooks.org/wiki/Python/Conceitos_b%C3%A1sicos/Tipos_e_operadores'
  
  @'funções embutidas.Por default: são as funções embutidas (built­in)
    Na verdade, fazem parte do módulo __builtins__, que é sempre importado em toda aplicação.
      Ex.: abs(x) retorna o valor absoluto do número x
      chr(x) retorna uma string com um único caractere cujo código ASCII éx 
      ord(s) retorna o código ASCII do caracteres'
  'http://www.dcc.ufrj.br/~fabiom/mab225/02tipos.pdf'
  
  - Focar conceitos que não são disponíveis em C e associá-los com situações em que são úteis na programação.
  @'A sintaxe de python enfatiza a leitura do código permitindo ao programador usar 10% do código requerido por outras linguagens, como C.
    Python é frequentemente usada como linguagem de script, porém é tambem extremamente eficiente quando autônomo (standalone). Permite, 
    por exemplo, aplicações baseadas na web, cois que C não é capaz de fazer.
    
    C não é uma linguagem dinâmica facilmente adaptavel para programação de scripts.'
    
   @'Aqui tem uma tabela cabulosa.' 
  'http://www.rapidprogramming.com/questions-answers/difference-between-c-and-python-c-vs-python-1426'
  
Avaliação da linguagem (2):
  - Análise da LP com base nos conceitos de legibilidade, capacidade de escrita, confiabilidade, custos e outros.
  - Focar os fatores que influenciam esses critérios e apresentar exemplos para justificar a avaliação.
  - Concluir, para cada critério, de forma objetiva o nível em que o critério é atendido pela LP.
  
 @' ->Legibilidade 
  
      - Simplicidade Geral 
É fácil de usar e muito simples, possui um conjunto pequeno, mas expressivo de tipos primitivos (maior simplicidade) e as estruturas de 
controle e lógicas colaboram para o bom entendimento do código. Python, de forma geral é uma linguagem simples.

      - Ortogonalidade 
Conjunto reduzido, mas completo de tipos primitivos e estruturas de controle. Além disso, Python, permite ligações entre tipos de dados
diferentes, (checagem de tipo dinâmica). Possui uma boa ortogonalidade. 

      - Estrutura de controle 
São básicas e suficientes para solucionar a maioria dos problemas e englobam o tratamento de exceções. Isso influência na queda 
legibilidade, porém como a quantidade de estruturas de controle não são tão extensas, ela não é um fator tão decisivo. 

      - Estruturas de dados e construtores: 
Formam um conjunto pequeno, mas completo e possui tipo de dado objeto, que permite abstração. Por não precisar de declaração de variáveis
a sua existência depende de uma expressão, o que pode prejudicar a interpretação do código. No conjunto, esses recursos afetam a 
legibilidade, entretanto não tornam a linguagem com baixa legibilidade.

      - Sintaxe 
Tem restrição para a identificação de variáveis, possui restrição para palavras reservadas e sua semântica é consistente com seu contexto.
Isso contribui para uma boa legibilidade.

Analisando em um todo, o Python é uma linguagem com boa legibilidade.

   -> Capacidade de escrita 

      - Simplicidade e ortogonalidade 
Simplicidade dos tipos primitivos e possui uma boa ortogonalidade.

      - Suporte à abstração 
Permite a abstração de processos com a criação de subprogramas e possui classes e objetos pré-construídos.

      - Expressividade 
O fato de ser OO implica em ser extensível.

      - Sintaxe 
Possui delimitadores e operadores.

Todas esses características contribuem para uma boa capacidade de escrita.

    -> Confiabilidade 
      
      - Verificação de tipo 
Não tem declaração formal de tipos de variáveis e além disso, toda verificação é dinâmica o que prejudica a confiabilidade da linguagem.

      - Tratamento de exceções 
Possui tratamento como visto acima.

      - Locação de memória simultânea 
Permite a alocação de variável por referência.

      - Legibilidade e capacidade de escrita 
Como ela possui uma boa legibilidade e capacidade de escrita isso afeta na sua confiabilidade, tornando mais vulnerável com relação ao
surgimento de termos ambiguos.

Apesar de Python ter tratamento de exceções e alocação de memória simultânea, ele possui uma baixa confiabilidade principalmente devido 
a sua verificação de tipo.

   -> Custo 

     - Treinamento 
Possui uma ampla comunidade de desenvolvedores, boa documentação e grande quantidade de exemplos e tutoriais.

    - Desenvolvimento 
Sua legibilidade e capacidade de escrita influenciam no fácil desenvolvimento e manutenção.

    - Compilação 
Gera byte code portável (interpretação híbrida).

    - Execução 
Verificação de tipo durante o tempo de execução, a execução depende praticamente de quão rápido é o interpretador.

    - Sistema de implementação 
Python é open source.

    - Confiabilidade 
Possui alocação de variável por referência o que prejudica a confiabilidade do sistema.

    - Manutenção 
Python possui boa legibilidade e é orientada a objetos o que facilita a manutenção do sistema já que o código também pode ser encapsulado.

Com essas características python possui um baixo custo.

    -> Portabilidade 
  
      - Padronização 
CPython é padronização da implementação da linguagem. O que pode servir como referência para o desenvolvimento de programas. 
No entanto, a padronização do código não é tão forte e unificada como o java.

Logo, python não possui muita portabilidade. 
 '
 'http://lpunb.wikia.com/wiki/Semin%C3%A1rioLP-Linguagem_Python_2/2014_-_Diego_Marques_e_Gabriel_Barbosa'
 
 @'Legibilidade
 
 Python é uma linguagem altamente legível. É facil de usar, dado que desde a sua concepção houve uma preocupação em não sobrecarregar a 
 sintaxe do Python com caracteres não alfabéticos, mantida nas versoes atuais. Possui um visual agradavel, frequentemente usando palavras e 
 não pontuações como em outras linguagens. Para a separação de blocos de código, a linguagem usa espaços em branco e indentação ao invés 
 de delimitadores visuais como chaves (C, Java) ou palavras (BASIC, Fortran, Pascal). Diferente de linguagens com delimitadores visuais 
 de blocos, em Python a indentação é obrigatória. O aumento da indentação indica o início de um novo bloco, que termina da diminuição da 
 indentação.
 
  Capacidade de escrita
    - Simplicidade e ortogonalidade
      Python é simples. 
 
 
 
 
 
 
 
 '
 'https://pt.wikipedia.org/wiki/Python' 
Justificativa para uso da linguagem (0,5):
  - Explicar as vantagens de utilizar a linguagem em questão na implementação deste projeto.
  - Comparar essas vantagens em relação ao uso de outras linguagens.
  
Especificidades (0,5):
  - Citar os frameworks, ferramentas e aplicativos complementares que foram usados no projeto,
  - tais como banco de dados, gerenciadores de rede, bibliotecas específicas, etc.
  
Paradigmas (0,5):
  - Citar quais paradigmas de programa foram utilizados no projeto e apresentar o código correspondente.
  
Implementação (3):
  - Mostrar código e saber explicar.
  - Avaliar a complexidade, a metodologia usada, a forma de trabalho em equipe, as ferramentas e especificidades.
  
Utilização de threads (0,5):
  - Citar se usou threads e mostrar onde, como e porque foi necessário o uso de threads.  
  
'https://docs.python.org/2/reference/lexical_analysis.html#indentation'


  
  
