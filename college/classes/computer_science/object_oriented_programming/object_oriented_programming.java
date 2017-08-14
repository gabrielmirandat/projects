  Ambiente: J2SE SDK (Java 2 Standard Edition Software Development Kit)
	//compilar java normal
  javac *.java - Compila todos os arquivos java de um diretório.
  javac *.java –d c:\MinhasClasses - especifica diretório onde arquivos .class vão ficar ("-d = indicar o compilador onde colocar arquivos"
      "gerados").
  javac -verbose  src/AloMundo.java - visualizar as mensagens adicionais do compilador.
	//executa de outro diretório
  java -cp /bin ByteCodes - especificar a origem do .class à máquina virtual.
	//documentação javadoc
  javadoc Nome_Arquivo.java - geração da documentação do programa na internet.
  javadoc –d nome_do_diretorio *.java - gera a documentação online de todos os .java do diretório atual e armazena-os em outro diretório.
  javadoc -author -d docs/ src/AloMundo.java - salva no diretório docs partindo de src.
	//utilizando jar
  java -jar bancoDatasus.jar - executa arquivo .jar
  jar cf arquivo.jar *.class - cria arquivo .jar que contém todos os .class ou .java do diretório.
  jar cf arquivo.jar *.java.
  jar tf arquivo.jar - lista conteúdo de um arquivo.jar.
  jar xf arquivo.jar - extrai todo o conteúdo de um arquivo.jar.
	//utilizando o desconstrutor
  javap MinhaClasse - mostra definições dos métodos do .class.
  javap -c MinhaClasse - mostra definições e bytecodes do .class.
	//applet
  appletviewer pagina.html - testa pagina.html sem necessidade de browser.
    //.bat
  contém o executável do arquivo jar, é só clicar e ele abre o programa no prompt.
  type arquivo.bat

  "Javadoc"
    -@author define autor
    -@param define parâmetros

  "Essenciais"
    − javac: compila programas Java
    − java: executa programas Java

  "Importantes"
    − javadoc: gera documentação automática
    − jar:  manipula arquivos “Java Archive” (JAR) , é uma coleção de de vários .class (nos jogos, também possui recursos de imagens e som)

  "Outras"
    − javap: vai dos .class para os .java (processo inverso da compilação - Java class disassembler(decompilador))
    − appletviewer: Usado para testar Applets sem a necessidade de um browser. Mais eficiente do que se usado em browser.

  http://docs.oracle.com/javase/8/docs/

  "objetivo Java": Fazer dispositivos comunicarem entre si.

  "o que é": É uma infra-estrutura para programação baseada no poder das redes de computadores e na idéia de que uma mesma aplicação possa
	      executar em diferentes máquinas,aparelhos e dispositivos eletrônicos.

   Cresce em aplicações web e aplicações para dispositivos móveis.
   Suporte de alto nível para acesso à Internet/Web.
   Suporte para acesso a arquivos remotos, banco de dados, etc.
   Objetos distribuídos com RMI, CORBA e EJB.
      O RMI (Remote Method Invocation) é uma interface de programação que permite a execução de chamadas remotas no estilo RPC em aplicações
      desenvolvidas em Java. É uma das abordagens da plataforma Java para prover as funcionalidades de uma plataforma de objetos distribuídos.
      Esse sistema de objetos distribuídos faz parte do núcleo básico de Java desde a versão JDK 1.1, com sua API sendo especificada através do
      pacote java.rmi e seus subpacotes. Através da utilização da arquitetura RMI, é possível que um objeto ativo em uma máquina virtual Java
      possa interagir com objetos de outras máquinas virtuais Java, independentemente da localização dessas máquinas virtuais. A API RMI
      fornece ferramentas para que seja possível ao programador desenvolver uma aplicação sem se preocupar com detalhes de comunicação entre
      os diversos possíveis elementos (hosts) de um sistema.
   Ausência de ponteiros
   Simplicidade
   Portabilidade
   Distribuição
   Robustez
    Tolerante a erros.
    Compilação tipada.
   Concorrência
      Uso de multithreading.
      Métodos sincronizados
      Monitores (construções essenciais para o controle de concorrência)
   Performance
   Paradigma de Orientação a Objetos
   Fortemente tipada

  "garbage colletion" - Não é necessário gerenciar memória explicitamente. São destruídos automaticamente pelo coletor de lixo.

  "compiladores JIT" - Just in Time (aumenta performance, mas perde em portabilidade).

  Versões
    "J2ME" Celulares e dispositivos inteligentes
    "J2SE" Convencional e Applets
    "J2EE" Web, aplicações distribuídas e transacionais

  "JVM - Java Virtual Machine" - assegura independência entre aplicações em diferentes plataformas.
	- É uma espécie de tradutor existente nos dispositivos para traduzir comandos da linguagem Java para a linguagem da máquina nativa.

  "JSDK - Java Software Development Kit" - Conjunto de ferramentas, bibliotecas e exemplos para o desenvolvimento em Java.
	 - Compila os .java tranformando-os em .class (bytecodes)
	 - "Não precisamos recompilar software, apenas ter o bytecode e a JVM instada"

  Interpretador
    − Executar arquivos .class(gerados após a compilação, a partir dos arquivos .java)
    − Executar arquivos .jar

  Tipos primitivos
    boolean	true ou false
    char	caractere (16 bits Unicode)
    byte	inteiro (8 bits)	//menor inteiro
    short	inteiro (16 bits)
    int		inteiro (32 bits)
    long	inteiro (64 bits)	//maior inteiro
    float	ponto flutuante (32 bits)
    double	ponto flutuante (64 bits)

  Operador de concatenação. ("ocorre conversão implícita para string")
    mensagem = “Este é o cliente número ” + x;

  Unários
    y=++x;	//incrementa x e depois atribui a y
    y=x++;	//atribui a y e depois incrementa x

  Conversões entre tipos primitivos
    - Widening conversion -Conversão para um tipo de maior capacidade.
			  -Não precisa de cast explícito.
    - Narrowing conversion -Conversão para um tipo de menor capacidade
			   -Pode haver perda de informação
			   -Precisa de cast explícito.
    -Ocorre conversão implícita para o tipo de maior tamanho em expressões aritméticas.
    -Casts envolvendo o tipo boolean não são permitidos!

  "POO"
  -Olhar o mundo como se tudo pudesse ser representado por objetos.
    − Facilidade de manutenção
    − Maior extensibilidade
    − Maior reuso

    "Classes e objetos"
       Classes especificam a estrutura e o comportamento dos objetos
       Classes são como "moldes" para a criação de objetos
       Objetos são instâncias de classes.
       Um objeto representa uma entidade do mundo real
       Todo objeto tem: "Identidade","Estado" e "Comportamento"
	   Identidade − Todo objeto é único e pode ser distinguido de outros objetos
	   Estado − Todo objeto tem estado, que é determinado pelos dados contidos no objeto
	   Comportamento − O comportamento de um objeto é definido pelos serviços/operações que ele oferece

    "Métodos"
      Métodos são operações que realizam ações e modificam os valores dos atributos do objeto responsável pela sua execução.
	− realizar simples atualizações dos atributos de um objeto
	− retornar valores
	− executar ações mais complexas como chamar métodos d e outros objetos
	 Métodos são invocados em instâncias (objeto) de alguma classe.
	  − Podem também ser invocados a partir da própria classe (métodos estáticos).

    "Modificadores"
      -Controlam o acesso aos membros de uma classe
      -Não são aplicados a variáveis.
      -Membros de uma classe: pŕopria classe
			      atributos
			      métodos e construtores

      public
	-uma classe public pode ser instanciada por qualquer classe
	-atributos public podem ser acessados por objetos de qualquer classe
	-métodos public podem ser chamados por métodos de qualquer classe

      protected
	-usado somente para atributos e métodos
	-atributos podem ser acessados por objetos de classes dentro do mesmo pacote ou de qualquer subclasse da classe ao qual ele pertence.
	-métodos podem ser chamados por objetos de classes dentro do mesmo pacote ou de qualquer subclasse da classe ao qual ele pertence.

      default(friendly)
	-a classe é visível somente por classes do mesmo pacote
	-atributos só são visíveis para objetos de classes do mesmo pacote
	-métodos só podem ser chamados a partir de objetos de classes do mesmo pacote.

      private
	-atributos podem ser acessados somente por objetos da mesma classe.
	-métodos private só podem ser chamados por métodos da classe onde são declarados.

      final
	-utilizado em qualquer membro de uma classe
	-torna o atributo constante, ou seja, não pode ser alterado. (geralmente são declarados como static também)
	-métodos não podem ser redefinidos.
	-classe não pode ser estendida.

      static
	-utilizado em atributos ou métodos.
	-atributos pertencem à classe, e não ao objeto.(só uma cópia na memória ram)
	-atributos são muito usados para constantes.
	-acesso é feito usando o nome da classe.
	-métodos pertencem a classes e não a objetos. Podem ser usados mesmo sem criar objetos e só pode acessar diretamente atributos
	 estáticos.

      O Garbage Collector (coletor de lixo) de Java elimina objetos da memória quando eles não são mais referenciados
	 Você não pode obrigar que a coleta de lixo seja feita
	 A máquina virtual Java decide a hora da coleta de lixo

    "Tipos de referência"
    Em Java não se trabalha diretamente com os objetos e sim com referências a objetos.
    Isso tem implicações na maneira em que objetos são comparados e copiados.
      "String"
	 String s1 = "George";
	 String s2 = "George";	--> Ambos apontam para o mesmo objeto criado na memória.

	 s1 = s1 + "Bush";
	 s2 = s2 + "Bush";	-->Ao manipular estas strings, dois novos String objeto são criados na memória, sendo que o anterior ainda
				   continua a existir como George.

	 String s3 = new String("George");
	 String s4 = new String("George");	--> Ambas as referências apontam para um objeto diferente na memória.

	 s1==s2;	-->Testa se as referências apontam para o mesmo objeto;
			   Não testa se o conteúdo das strings é igual.

	 s1.equals(s2);	-->Testa se o conteúdo entre as duas strings é igual.
   booleanequalsIgnoreCase(umString); --> testa se é igual ignorando maiúscula e minúscula.
   intlength(); --> retorna tamanho da string.
   StringtoLowerCase(); --> transforma todas as maiúsculas em minúsculas.
   StringtoUpperCase(); --> transforma todas as minúsculas em maiúsculas.
   Stringtrim(); --> retira os espeços das extremidades da string.
   intindexOf(umString); --> retorna o indice onde umString ocorre na string que chamou este método.
   Stringsubstring(int indiceInicio, int indiceFinal); --> retorna uma substring formada de indiceInicio até (indiceFinal - 1) da string que chamou.
   charcharAt(int indice); --> retorna o caractere determinado pelo índice indice da string que chamou.

      "Arrays"
   -São tipos especiais de Java. Objetos especiais
   -Arrays também são tipos referência

   int[] a = new int[100];  //cria array de int
   String[] nomes = new String[200];  //cria array de strings
   int[] primosPequenos = {2, 3, 5, 7, 11,13};  //inicializa array com valores conhecidos

   int[][] matriz = new int[10][5]; //array multidirecinal
   long[][] x = { {0,1}, {2,3}, {4,5} };  //inicia array multidirecional com valores já conhecidos

   - IndexOutOfBoundsException  //exceção gerada se é tentado acessar um valor inválido do array

      "Repositorio ou conjunto de contas"
   - Uma classe que guarda contas num array de contas.
   -Métodos para inserção, procura, remoção e atualização dos objetos.

      "Arquitetura em Camadas"
      -Modularidade= reusabilidade e extensabilidade.
      -Mudança em uma camada não afeta as outras, desde que as interfaces sejam preservadas.
      -Propósito das camadas= fornecer suporte para alguma camada superior.
			      abstrair camadas superiores de detalhes específicos.

      "Camadas
      Interface com usuário(GUI) -> Comunicação -> Negócio -> Dados
				     (Fachada)

      Comunicaçao = concorrência, distribuição roda em computadores diferentes.
      Negócio = implemetar a lógica do negócio (realiza os procedimentos em função dos Dados) .
	  ● Classes do domínio da aplicação (Conta e Cliente)
	  ● Classes básicas do negócio
	  ● Coleções de negócio (conjuntos de objetos. Responsáveis pela inclusão, remoção, atualização e consultas a instâncias das classes
				 básicas)
	  ● Fachada do sistema (padrão de projeto facade. Centraliza as instâncias das coleções de negócio). "Singleton. Só uma instância"

      Dados = manipulação da estrutura de armazenamento dos dados.
	  ● Classes de coleções de dados.
	  ● Executam inclusões, remoções, atualizações e consultas no meio de armazenamento usado.


      "Herança"
      Herança introduz os conceitos de:
      − Superclasse e Subclasse
      − Redefinição de Métodos
      − Polimorfismo de subtipo

      1)Reuso de Código:
      − Tudo que a superclasse tem, a subclasse também tem
      − O desenvolvimento pode se basear em o que já está pronto.

      2)Extensibilidade:
      − Algumas operações da superclasse podem ser redefinidas na subclasse.

      3)Comportamento:
      − Objetos da subclasse comportam-se como os objetos da superclasse

      4)Princípio da Substituição:
      − Objetos da subclasse podem ser usados no lugar de objetos da superclasse.
      − Toda Poupanca é uma Conta mas nem toda conta é uma Poupança.

      class Poupanca extends Conta {
	public Poupanca (String num , Cliente c ) {
	  super(num , c );	//construtor da superclasse. Se não for definido, chama super(). Se não estiver definido na superclasse, erro!
	}

	Conta c;
	c = new Poupanca(“21.342-7”);

	( (Poupanca) c).renderJuros(0.01);

      • O operador instanceof verifica a classe de um objeto (retorna true ou false).
      • Recomenda-se o uso de instanceof antes de se realizar um cast para evitar erros.
      - Se não for usado "extends", a classe estende a classe "Object" de Java.

    Overriding
    -Na redefinição de um método, o compilador prefere chamar o método mais especifico. No caso, o da subclasse.
     Para que haja a redefinição de métodos, o novo método deve tera mesma assinatura (nome e parâmetros) que o método da
         super classe
     Se o nome for o mesmo, mas os parâmetros forem de tipos diferentes haveráoverloading e não redefinição.

     O método é escolhido dinamicamente (em tempo de execução), nãoestaticamente (em tempo de compilação).
     A escolha é baseada no tipo do objeto que recebe a chamada do método e não da variável.
     Overloading permite a definição de vários métodos com o mesmo nome em uma classe. O mesmo vale para construtores
     A escolha do método a ser executado é baseada no tipo dos parâmetros passados

     Atributos e métodos com o modificador protected podem ser acessados na classe em que são declarados e nas suassubclasses.
     Os membros private de uma superclasse são acessíveis apenas em métodos dessa superclasse.

     Classes declaradas com o modificador final não podem ter subclasses.

      "Classes abstratas e interfaces"
         Objetos dasubclasse devem se comportar como os objetos dasuperclasse
         Redefinições de métodos devem preservar o comportamento (semântica) do método original
         Grande impacto sobre manutenção e evolução de software

        -Classes Abstratas
         Devem ser declaradas com a palavra-chave abstract
         Podem declarar métodos abstratos
        − Métodos sem implementação
        − Implementação fornecida na subclasse
         Podem declarar métodos com implementação

         Uma classe abstrata é declarada com o modificador 'abstract'
         Um método é definido abstrato também usando o modificado abstract.

         Uma classe abstrata não pode ser instanciada
         Mesmo sem poder ser instanciada, pode definir construtores para permitir reuso
         Qualquer classe com um ou mais métodos abstratos é automaticamente uma classe abstrata
         Se uma classe herdar de uma classe abstrata, deve redefinir todos os métodos abstratos. Caso contrário, deve ser declarada
        como abstrata.

         Métodos private, static efinal não podem ser abstratos.
         Uma classe final não pode conter métodos abstratos.
         Uma classe pode ser declarada como abstract, mesmo se não tiver métodos abstratos.

         Definem "contratos" a serem realizados por subclasses.
         Tornam o polimorfismo mais claro. Só podemos herdar de UMA classe abstrata!!

        -Interfaces
         Casos em que as classes envolvidas não estão relacionadas através de uma hierarquia de herança.
         Caso especial de classes abstratas.
         Definem tipo de forma abstrata, apenas indicando a assinatura dos métodossuportados pelos objetos do tipo.
         Não têm construtores. Não se pode criar objetos já que métodos não estão implementados.

        Uma interface define um “contrato” a ser seguido.

        interface Nome_Interface {...}
        class Nome_classe implements Nome_Interface{

         Classes e Interfaces são tipos
         Os termos subtipo e supertipo também são usados
          − supertipo : interface
          − subtipo: classe que implementa a interface ou interface que estende outra interface
         Interfaces utilizam o conceito de herança múltipla
          − Herança múltipla de assinatura

         Apesar de não suportar herança múltipla de classes, uma classe pode implementar mais de uma interface (pode ter
        vários supertipos).

         Todos os métodos de uma interface são implicitamente abstratos e públicos.
         métodos de interfaces não podem ser :
            − static
            − final
            − private
            − protected

         Interfaces não podem conter atributos
         A única exceção são os atributos static final (constantes).
         Interfaces são excelentes repositórios para constantes.

         Evita duplicação de código através da definição de um tipo genérico, tendo como subtipos várias classes não relacionadas
         Uma interface agrupa objetos de várias classes definidas independentemente, sem compartilhar código via herança, tendo
            implementações totalmente diferentes.

    "Pacotes"
    Tipos de Módulos em Java
    
    +Classes e interfaces
      − agrupam definições de métodos, atributos, construtores, etc.
      − definem tipos
    +Pacotes
      − agrupam definições de classes e interfaces relacionadas
      − estruturam sistemas extensos, facilitando a localização das classes e interfaces
      − oferecem um nível mais alto de abstração: há mais classes do que pacotes

    Pacotes e Diretórios
    +As classes de um pacote são definidas em arquivos com o mesmo cabeçalho:
			      package nomeDoPacote;
    +Cada pacote é associado a um diretório do sistema operacional:
      - Os arquivos .class das classes compiladas do pacote são colocados neste diretório
      - É recomendável que o código fonte das classes do pacote também esteja neste diretório
      
    Nomes de Pacotes
    +O nome de um pacote é parte do nome do seu diretório associado: o pacote
			      qualiti.banco.conta
     deve estar no diretório
			      c:\java\qualiti\banco\conta
     assumindo que o compilador Java foi informado para procurar pacotes em 
			      c:\java
			      
    Pacotes e Subdiretórios
    +Subdiretórios não correspondem a "subpacotes". São subdiretórios como outros quaisquer
    +Por exemplo, não existe nenhuma relação entre exemplos e exemplos.banco:
			      package exemplos;
			      import exemplos.banco.*;
			      /*...*/
			      
			      package exemplos.banco;
			      /*...*/
			      
    Pacotes e modificadores de acesso
    + public: Elementos com este modificador podem ser utilizados (são visíveis) em qualquer lugar, mesmo em pacotes diferentes
    + protected: Elementos com este modificador só podem ser utilizados no pacote onde são declarados, ou nas subclasses da classe onde são 
      declarados
    + "fliendly" (sem modificador): Elementos com nível de acesso default só podem ser utilizados no pacote onde estão declarados
    + private: Elementos declarados com este modificador só podem ser utilizados na classe onde estão declarados
    
    Reuso de Declarações
    +As declarações feitas em um arquivo são visíveis em qualquer outro arquivo do mesmo pacote, a menos que elas sejam private
    +Qualquer arquivo de um pacote pode usar as definições visíveis de outros pacotes, através do mecanismo de importação de pacotes
    
    Importação de Pacotes
    
    +Importação de definição de tipo específica:
			      package segundo.pacote;
			      import primeiro.pacote.NomeDaClasse;
			      /*...*/	
    +Importação de todas as definições de tipo públicas:(ou geral)
			      package segundo.pacote;
			      import primeiro.pacote.*;
			      /*...*/
    
    Importação de Pacotes: Detalhes
    +Tanto NomeDaClasse quanto primeiro.pacote.NomeDaClasse podem ser usadas no corpo de classes pertencentes a segundo.pacote
    +Em segundo.pacote, não pode ser definida uma classe com o nome NomeDaClasse, caso a importação tenha sido específica
    
    Se ambos tem uma classe NomeDaClasse
    
    1. import segundo.pacote.*;		//ERRO! DUAS GERAIS
       import primeiro.pacote.*;
       
    2. import segundo.pacote.NomeDaClasse;	//OK! UMA ESPECIFICA E UMA GERAL. A ESPECIFICA TEM PRIORIDADE
       import primeiro.pacote.*;
    
    3. import segundo.pacote.NomeDaClasse;	//ERRO! DUAS ESPECIFICAS
       import primeiro.pacote.NomeDaClasse;

    Estruturando Aplicações com Pacotes
    + Agrupar classes relacionadas, com dependência (de implementação ou conceitual) entre as mesmas
    + Evitar dependência mútua entre pacotes:
			     package a;			package b;
			     import b.*;		import a.*;
			     /*...*/			/*...*/
    + Estruturação típica de um sistema de informação:
      - Vários pacotes para as classes da interfaces de GUI, um para cada conjunto de telas associadas
      - Um pacote para a classe fachada e exceções associadas
      - Um pacote para cada coleção de negócio, incluindo as classes básicas, coleções de dados, interfaces, e exceções associadas
      - Um pacote (sistema).util contendo classes auxiliares de propósito geral
    
    Pacotes da Biblioteca Padrão de Java
    + Acesso a Internet e WWW (java.net)
    + Applets (java.applet)
    + Definição de interfaces gráficas (java.awt)
    + Suporte a objetos distribuídos (java.rmi)
    + Interface com Banco de Dados (java.sql)
    + Básicos: threads e manipulação de strings (java.lang), entrada e saída (java.io), coleções e utilitários de propósito geral (java.util)
    + Dezenas de outros...

    APIs de Java
    +Pacote 'java.lang'
      - É o principal pacote de Java
      - Contém as classes fundamentais da plataforma
      - É importado automaticamente em todas as classes criadas
      - Classes essenciais:Object, Throwable, Exception, String,Thread, Runnable, Math, System, Runtime
      
      +Classe Object
        - É a superclasse de todas as classes de Java
        - É a única classe sem superclasse
	  •boolean equals(Object obj): verifica se dois objetos são iguais
	  •String toString(): retorna um String descrevendo o objeto
	  •Object clone(): retorna uma cópia do objeto (mas só se a interface Cloneable for implementada)
	- A maioria dos métodos de Object é redefinida nas subclasses	//A maioria dos métodos de Object é redefinida nas subclasses.
	
      +Throwable e Exception
	- Throwable é a superclasse de todas as exceções
	- Exception herda de Throwable. É a classe que deve ser usada como base para a definição de novas exceções
	  •String getMessage(): retorna a mensagem encapsulada na exceção (retorno pode ser nulo)
	  •void printStackTrace(): mostra a pilha de exceção (a seqüência de chamadas de métodos que resultaram na exceção)
	  
      +String
	- Encapsula cadeias de caracteres e muitas operações de manipulação
	- Vista detalhadamente na aula sobre Strings e Arrays
	
      +Thread e Runnable
	- A classe Thread e a interface Runnable são essenciais para a implementação de aplicações com concorrência em Java
	//Classe Thread e interface Runnable = necessários para implementar concorrência em Java
      
	  +System
	- Define uma interface padrão, independente de plataforma, para recursos do sistema operacional:
	  •out: saída padrão
	  •in: entrada padrão
	  •currentTimeMillis(): hora atual em milisegundos desde 1 de Janeiro, 1970, GMT
	  •arrayCopy(Object origem, int origem_pos, Object destino, int destino_pos, int comprimento): copia um array ou parte de um array para 
	   outro
	  •exit(): força a saída da aplicação
	  
    +Pacote java.util
      - Define classes e interfaces de coleções e outras classes utilitárias
      - Coleções
	• Collection
	• List
	• Set, SortedSet
	• Vector, Stack
	• ArrayList, LinkedList
	• Map
	• Hashtable
	• Arrays
	• Iterator
	• Date, Calendar e GregorianCalendar
	• Timer e TimerTask
	• Random
	• Properties
	• StringTokenizer

    "Exceções"
    
    +Robustez
    Sistemas robustos devem:
      −	Fornecer formas eficientes para recuperação de falhas
      − Fornecer mensagens apropriadas de erros
      − Fazer validação dos dados
      − Evitar que situações indesejadas ocorram
      − Garantir a consistência das operações
      
      Em debitar, como evitar débitos acima do limite permitido?
      Possíveis soluções
	
	- Desconsiderar operação
		      public void debitar(double valor) {
			if (valor <= saldo)
			  saldo = saldo - valor;
		      }
		      
		      + quem solicita a operação não tem como saber se ela foi realizada ou não
		      + nenhuma informação é dada ao usuário do sistema
	
	- Mostrar mensagem de erro
		      void debitar(double valor) {
			if (valor <= saldo)
			  saldo = saldo - valor;
			else System.out.print(msgErro);
		      }
		      
		      + O usuário do sistema recebe uma mensagem, mas nenhuma sinalização é fornecida para métodos que invocam debitar
		      + Há uma forte dependência entre a classe Conta e sua interface com o usuário
			(Não há uma separação clara entre código da camada de negócio e código da camada de interface com o usuário Java Básico)
	
	- Retornar código de erro
		      boolean debitar(double valor) {
			boolean r = false;
			if (valor <= saldo) {
			  saldo = saldo - valor; r = true;
			} else r = false;
			  return r;
		      }
			
		      + dificulta a definição e uso do método:
			-métodos que invocam debitar têm que testar resultado retornado para decidir o que deve ser feito
			-A situação é pior em métodos que retornam códigos de erro. 
		      + a dificuldade é ainda maior quando o método já retorna algum tipo:
			-o retorno pode ser o resultado da operação ou um código de erro. 
			 O que fazer quando o tipo retornado não é primitivo?
			 
	"Exceções são o mecanismo utilizado por Java para tratamento de erros ou situações indesejadas"
	− Erros de programação: Acesso a uma posição inválida de um array, divisão por zero, invocação de um método em uma referência nula.
	− Situações indesejadas: Uma conexão de rede indisponível durante uma comunicação remota, a ausência de um arquivo procurado localmente

	+ Exceções são declaradas como classes Java
	
	+ Os objetos de uma exceção encapsulam informações relevantes sobre o erro ocorrido
	
	+ Exceções podem ser:
	  − declaradas
	  − lançadas
	  − tratadas
	  
	  +java.lang.Throwable : A classe Throwable é a superclasse de todas as exceções
	      +java.lang.Error : Exceçoes que estendem Error representam erros internos da máquina virtual
	      +java.lang.Exception : Exceções que estendem Exception devem ser declaradas e tratadas. As exceções que você cria devem partir
	                             daqui
		  +java.lang.RuntimeException : Exceções que estendem RuntimeException representam erros de programação. Não precisam ser 
		                                declaradas em métodos
						    
	
	+ Exceções não checadas (unchecked exceptions)
	  -Exceções que estendem RuntimeException indicam erros de programação e normalmente não são declaradas. Por exemplo, uma divisão por 
	   zero.
	  -Qualquer método pode gerar essas exceções apesar de não explicitar isto na sua definição.
	  -Tratar exceções deste tipo é como tentar corrigir um erro de programação durante a programação. Não faz muito sentido.
			//Tratá-las significa tentar corrigir um erro de programação durante a programação. Não faz sentido;
	  -O que se faz é capturar a exceção e apresentar uma mensagem de erro agradável ao usuário indicando esta ocorrência.

	+ Exceções checadas (checked exceptions)
	  -Exceções checadas são todas as exceções que são subclasses de Exception, exceto RuntimeException e suas subclasses.
	  -Devem ser declaradas e tratadas no código.
	  
	Exceções
	  -Exceções podem ser definidas pelo programador e devem ser subclasses de java.lang.Exception.
	  -Definem-se novas exceções para:
	      − oferecer informações extra sobre o erro.
	      − distinguir os vários tipos de erro/situação indesejada
	      − Específicas para uma dada aplicação (exceções de negócio)
	      
	Formato da declaração de exceções
	class Nome_Excecao_Exception extends Exception {
	    public Nome_Excecao_Exception () {
	    }
	    /*...*/	
	}
	
	"Por convenção, é aconselhável que o nome de qualquer exceção definida pelo programador tenha o sufixo Exception:"
	"SaldoInsuficienteException, ObjetoInvalidoException, etc"
	
	Exemplo de definição de Exceções
	class SaldoInsuficenteException extends Exception {
	  public SaldoInsuficienteException() {
	    super("Saldo Insuficiente!");
	  }
	  /*...*/
	}
	
	Declaração e lançamento
	- Exceções são declaradas na assinatura dos métodos, que devem tratar um dado processamento, usando o comando throws.
	- Exceções são lançadas no corpo dos métodos usando o comando throw.
		  void metodo(...) throws Exc1, Exc2, ExcN {
		      ...
		      throw new Exc1(...);
		  }
	- Exceções lançadas no corpo de um método, e não tratadas, devem ser declaradas.
	- Quando uma exceção é lançada e não é tratada, o fluxo de controle passa para o método invocador e sobe pelas chamadas de métodos até
	  que a exceção seja tratada
	- Se a exceção não for tratada em lugar nenhum, Java assume o controle e pára o programa.
		  void debitar(double valor) throws SaldoInsuficienteException {
		    if (valor <= saldo) {
		      saldo = saldo - valor;
		    }
		    else {
		      SaldoInsuficienteException sie;
		      sie = new SaldoInsuficienteException(numero ,saldo );
		      throw sie;
		    }
		  }
		  
		  void transferir(Conta c, double v) throws SaldoInsuficienteException{	//debitar levanta uma exceção!
		    this.debitar(v);	//Exceções levantadas indiretamente também devem ser declaradas.
		    c.creditar(v);
		  }
	
	Quando exceções são lançadas
	- Exceções são lançadas quando:
	     − um método que lança exceções é chamado
	     − você detecta uma situação de erro e levanta uma exceção com throw
	     − você comete um erro de programação como, por exemplo, tentar acessar uma posição inválida de um array: a[-1]. Neste caso, Java
	       levanta a exceção indicando o erro.
	     − um erro interno ocorre em Java.
	
	Tratamento de exceções
	- Exceções são tratadas usando blocos try-catch
					try { 
					    // chamada aos métodos que podem lançar exceções
					}
					catch (Exc1 e1) {
					    // código para tratar um tipo de exceção
					}
					catch (ExcN eN) {
					    // código para tratar outro tipo de exceção
					}
	
	
	class CadastroContas {
	    /* ... */
	    void debitar(String n, double v) throws SaldoInsuficienteException,
	      ContaInexistenteException {
	      Conta c = contas.procurar(n);
	      c.debito(v);
	    }
	}
	
	public static void main(String args[]){
	    try {
		contas.debitar("123-4",90.00);
		System.out.println("Débito efetuado");
	    } catch (SaldoInsuficienteException sie) {
		System.out.println(sie.getMessage());
		System.out.print("Conta/saldo: ");
		System.out.print(sie.getNumero() + "/" +
		e.getSaldo());
	    } catch(ContaInexistenteException cie) {
		System.out.print(cie.getMessage());
	    }
	    finally {
		// Este código é sempre executado
		System.out.println("Obrigado, volte sempre!");
	    }
	    ...
	  
	- A execução do try termina ao final do bloco ou assim que uma exceção é levantada
	- O primeiro catch de um supertipo da exceção é executado e o fluxo de controle passa para o código seguinte ao último catch
	- Exceções mais específicas devem ser capturadas primeiro. Caso contrário, um erro de compilação é gerado
	- Se não houver nenhum catch compatível, a exceção e o fluxo de controle são passados para o método que invocou
	- um trecho de código com finally é sempre executado, havendo ou não exceções
	
	Exceções e redefinição de métodos
	- Métodos redefinidos não devem declarar exceções que não sejam as mesmas ou subclasses das exceções declaradas no método original.
	- Métodos redefinidos podem declarar um número menor ou maior de exceções que o declarado no método original contanto que a condição
	  acima se verifique
	  
    "Arquivos"
    + A classe File
      - A classe java.io.File representa um arquivo ou um diretório que pode ou não existir no sistema de arquivos da plataforma em uso.
      - Encapsula um String com o nome do arquivo/diretório.
      - Não inclui o conteúdo do arquivo associado.
      
      +Construtores
      ● File(String pathname)
      ● File(String dir, String subpath)
      ● File(File dir, String subpath)
      
      +File: propriedades de arquivos e pastas
      ● String getName()
      ● String getPath()
      ● String getAbsolutePath()
      ● String getParent()
      ● long length()
      ● boolean exists()
      ● boolean isFile()
      ● boolean isDirectory()
      ● boolean canWrite()
      ● boolean canRead()

      public class DetalheArquivo {
	public static void main(java.lang.String[] args) {
	  String nomeArquivo = "c:\\winnt\\notepad.exe";
	  File arq = new File(nomeArquivo);
	  if (!arq.exists()) {
	    System.out.print("Arquivo nao existe: "+nomeArquivo);
	  } else {
	    System.out.println("Nome: " + arq.getName());
	    System.out.println("Caminho absoluto: " + arq.getAbsolutePath());
	    System.out.println("Tamanho:"+arq.length()+"bytes");
	    long horaMod = arq.lastModified();
	    System.out.println("Hora de modificacao: " + new Date(horaMod));
	  }
	}
      }
      
      +File: ações comuns
      ● Listar o conteúdo de um diretório
	  String[] list();
          File[] listFiles()
      ● Criar um novo arquivo
          boolean createNewFile()
      ● Criar novos diretórios
	  boolean mkdir()
	  boolean mkdirs()
      ● Mudar nome de um arquivo ou diretório
	  boolean renameTo(File arq)
      ● Remover um arquivo ou diretório
	  boolean delete()
	  - Um diretório deve estar vazio para que possa ser removido!

      public class ListarDiretorio {
	public static void main(java.lang.String[] args) {
	  String nomeDiretorio = ".";
	  File dir = new File(nomeDiretorio);
	  if (!dir.exists()) {
	    System.out.println("Diretorio " + dir.getAbsolutePath() + " nao encontrado");
	  } else if (dir.isDirectory()) {
	    String[] listaArquivos = dir.list();
	    if (listaArquivos != null) {
	      for(int i=0; i < listaArquivos.length; i++)
		System.out.println(listaArquivos[i]);
	    }
	  }
	}
      }
      
      +File: independência do sistema
      ● O separador de arquivos pode não ser “\”
	Use File.separator
      ● O diretório atual pode não ser “.”
	use System.getProperty("user.dir")
      ● O diretório pai pode não ser “..”
	use o método getParent() da classe File
      ● O diretório de arquivos temporários pode não ser “c:\windows\temp”:
	Use File.createTempFile()

      +Streams
      ● Streams são seqüências de bytes
      ● São lidos de forma seqüencial
      ● Streams estão sempre associados a “fontes de dados”
	  - Arquivos, outros streams, áreas de memória

      Tipos de streams
      ● Stream de alto nível
	  Tipos primitivos(ints, floats, ...)
      ● Stream de baixo nível
	  Bytes
      ● Dispositivo de E/S
	  Bytes
	  
      Streams de baixo nível
      ● Leitura e escrita de bytes sem processamento
      ● Estendem diretamente InputStream ou OutputStream
      ● Mais importantes
	-FileInputStream
	-FileOutputStream
	
      Streams de alto nível
      ● Processamento dos bytes lidos/escritos
      ● Leitura e escrita de tipos primitivos e objetos
      ● Lêem e escrevem em outros streams
      ● Mais importantes:
	-BufferedInputStream, BufferedOutputStream
	-DataOutputStream, DataInputStream
	-ObjectOutputStream, ObjectInputStream
      ● Streams de alto nível não lêem nem escrevem diretamente em dispositivos de entrada e saída
      
      Streams com filtros
      ● Fazem algum processamento nos bytes lidos/escritos
      ● Subclasses de FilterInputStream e FilterOutputStream
      ● Mais importantes
	-DataInputStream, DataOutputStream
	    ->Leitura e escrita de tipos primitivos
	-BufferedInputStream, BufferedOutputStream
	    ->Leitura e escrita de bytes com buffering (para eficiência)
	-ObjectInputStream, ObjectOutputStream
	    ->Leitura e escrita de objetos

      Exemplo com DataOutputStream
      Cliente[] clientes = { new Cliente("111","Joao da Silva"),new Cliente("222","Carlos Filho"),new Cliente("333","Paulo Cornelli")};
      try {
	String tempDir = System.getProperty("user.home");
	FileOutputStream file = new FileOutputStream(tempDir + File.separator + "clientes.txt");
	DataOutputStream dos = new DataOutputStream(file);
	for (int i=0; i < clientes.length; i++) {
	  dos.writeBytes(clientes[i].getCpf());
	  dos.writeByte('\n');
	  dos.writeBytes(clientes[i].getNome());
	  dos.writeByte('\n');
	}
	dos.close();
	file.close();
	System.out.println("Arquivo salvo em: " + tempDir);
      
      Exemplo com DataInputStream
      FileInputStream fileIn = new FileInputStream(tempDir + File.separator + "clientes.txt");
      DataInputStream dis = new DataInputStream(fileIn);
      String line = dis.readLine();
      while(line != null) {
	System.out.println("CPF: " + line + " - Nome: " + dis.readLine());
	line = dis.readLine();
      }
      
      Exemplo: leitura de um arquivo de propriedades
      public class LerPropriedades {
	public static void main(String[] args) {
	  try{
	    String arquivo = "sistema.properties";
	    Properties p = new Properties();
	    FileInputStream fin = new FileInputStream(arquivo);
	    p.load(fin);
	    p.list(System.out);
	  }catch(Exception e){
	    e.printStackTrace();
	  }
	}
      }
      
      +Readers e Writers
      ● São streams que se diferenciam dos demais por lidar com caracteres Unicode
      ● Devem ser usados para leitura de caracteres (mais completos e eficientes)
      ● Readers/Writers de baixo nível
	- FileReader
	- FileWriter
      ● Readers/Writes de alto nível
	- BufferedReader
	- BufferedWriter
	- PrintWriter
	
      Exemplo: listar um arquivo texto
      public static void lerArquivo(InputStream is) throws IOException{
	InputStreamReader ir = new InputStreamReader(is);
	//Buffer para leitura linha a linha
	BufferedReader br = new BufferedReader(ir);
	String linha = br.readLine();
	while (linha != null) {
	  System.out.println(linha);
	  linha = br.readLine();
	}
      }
      
      Exemplo: escrita em arquivo texto
      public static void escreverArquivo(String name) throws IOException{
	FileWriter fout = new FileWriter(name);
	BufferedWriter bw = new BufferedWriter(fout);
	bw.write("texto");
	bw.close();
	fout.close();
      }
      
      +Acesso aleatório
      ● RandomAccessFile
	-Define um ponteiro para acessar posições aleatórias do arquivo, relativas ao início.
	+Construtores
	  ● RandomAccessFile(String file, String mode)
	  ● RandomAccessFile(File file, String mode)
	+A criação de um objeto RandomAccessFile pode gerar uma FileNotFoundException (modo de leitura) ou criar o arquivo (modo de escrita)
	caso o arquivo não exista.

	● long getFilePointer
	  - retorna a posição atual do ponteiro
	● long length()
	  - retorna o tamanho do arquivo em bytes
	● void seek(long position)
	  - posiciona o ponteiro no arquivo
	  
	● Métodos para leitura e escrita de tipos de dados comuns
	Tipo de dado			Métodos			
			  Leitura			Escrita
	  boolean 	  boolean readBoolean() 	void writeBoolean(boolean b)
	  byte 		  byte readByte()		void writeByte(byte b)
	  char 		  char readChar() 		void writeChar(char c)
	  double	  double readDouble() 		void writeDouble(double d)
	  float 	  float readFloat()		void writeFloat(float f)
	  int 		  int readInt() 		void writeInt(int i)
	  long 		  long readLong()		void writeLong(long l)
	  short		  short readShort() 		void writeShort(short s)
	  String 	  String readLine()		-
	  
	  RandomAccessFile: exemplo
	  //escrever
	  RandomAccessFile rf = new RandomAccessFile("teste.dat", "rw");
	  for(int i = 0; i < 10; i++) {
	    double num = i*3.00;
	    rf.writeDouble(num);
	    System.out.println(num);
	  }
	  //ler
	  int bytesLidos = 0;
	  long totalBytes = rf.length();
	  rf.seek(bytesLidos);
	  
	  while(bytesLidos*8 < totalBytes) {
	    double num = rf.readDouble();
	    System.out.println(num);
	    bytesLidos++;
	    rf.seek(bytesLidos*8);
	  }
	  
	  Serialização de Objetos
	  ● Objetos podem ser lidos e escritos no disco
	    - ObjectOutputStream
	      – void writeObject(Object objeto)
	    - ObjectInputStream
	      – Object readObject()
	  ● Classes devem implementar a interface Serializable para que seus objetos possam ser escritos/lidos

	  Exemplo de Serialização
	  public static void gravarCliente(Cliente c, String arquivo) throws FileNotFoundException, IOException {
	    FileOutputStream fos = new FileOutputStream(arquivo);
	    ObjectOutputStream oos = new ObjectOutputStream(fos);
	    oos.writeObject(c);
	  }
	  public static Cliente lerCliente(String arquivo) throws FileNotFoundException,IOException,ClassNotFoundException {
	    FileInputStream fis = new FileInputStream(arquivo);
	    ObjectInputStream ois = new ObjectInputStream(fis);
	    Cliente c = (Cliente) ois.readObject();
	    return c;
	  }
	  
	  ● Se um objeto tem referências a outros objetos, esses objetos também são serializados
	  ● Um atributo de um objeto pode ser marcado como não-serializável com a palavra-chave transient
	  
	  import java.io.*;
	  public class Usuario implements Serializable{
	    private String ID;
	    private HistoricoAcessos historico;
	    private transient String senha;	//atributo não serializable
	  }

	  ● Objetos e suas referências formam um grafo
	  ● Para que um objeto possa ser serializado, ele e o resto dos objetos do grafo de objetos devem implementar Serializable
	    -java.io.NotSerializableException

    'Software Product Line Development'
		Compilação condicional - 
	
	