// Insira as linhas abaixo como primeiras linhas em seu programa de teste
// tais linhas garantem que posssamos referenciar as classes Scanner e Locale.
// Explicaremos como isto funciona mais para frente, na aula sobre pacotes.
import java.util.Scanner;
import java.util.Locale;

public class InterfaceTextual {

	private static Scanner sc;
	
	private static Fachada fachada;

	// as constantes abaixo tornam a interface e a logica da aplicacao mais
	// flexiveis.
	// alem disso as constantes sao mneumonicas
	private static final int OP_CADASTRAR_ALUNO = 1;
	private static final int OP_PROCURAR_ALUNO = 2;
	private static final int OP_ATUALIZAR_ALUNO = 3;
	private static final int OP_DESCADASTRAR_ALUNO = 4;
	
	private static final int OP_CADASTRAR_CURSO = 5;
	private static final int OP_PROCURAR_CURSO = 6;
	private static final int OP_ATUALIZAR_CURSO = 7;
	private static final int OP_DESCADASTRAR_CURSO = 8;
	
	private static final int OP_MATRICULAR_ALUNO = 9;
	private static final int OP_PROCURAR_MATRICULA = 10;
	private static final int OP_CANCELAR_MATRICULA = 11;
	
	private static final int OP_LISTAR_MATRICULAS = 12;
	private static final int OP_LISTAR_CURSOS = 13;
	private static final int OP_LISTAR_ALUNOS= 14;
	private static final int OP_LISTAR_ALUNOS_CURSO = 15;
	private static final int OP_LISTAR_ALUNOS_CURSOS = 16;
	private static final int OP_LISTAR_CURSOS_ALUNO = 17;
	private static final int OP_LISTAR_CURSOS_ALUNOS = 18;
	private static final int OP_LISTAR_MATRICULAS_ALUNO = 19;
	private static final int OP_LISTAR_MATRICULAS_CURSO = 20;
	private static final int OP_LISTAR_ALUNOS_SEM_CURSO = 21;
	private static final int OP_LISTAR_CURSOS_SEM_ALUNO = 22;
	private static final int OP_SAIR = 23;
	
	
	public static void reportar_erro(String msg) {
        System.out.println(msg);
		
	}

	public static void main(String[] args) {

		init();
		int opcao = OP_SAIR;
		do {
			imprime_tela();
			opcao = pega_opcao();
			trata_opcao(opcao);
		} while (opcao != OP_SAIR);

	}

	public static void imprime_tela() {

		System.out.println("****************************");
		System.out.println("*** Centro de Ensino XYZ ***");
		System.out.println();
		System.out.println();
		System.out.println(" Operacoes disponiveis: ");
		System.out.println(OP_CADASTRAR_ALUNO + "- Cadastrar aluno ");
		System.out.println(OP_PROCURAR_ALUNO + "- Procurar aluno ");
		System.out.println(OP_ATUALIZAR_ALUNO + "- Atualizar aluno ");
		System.out.println(OP_DESCADASTRAR_ALUNO + "- Descadastrar aluno ");
		System.out.println(OP_CADASTRAR_CURSO + "- Cadastrar curso ");
		System.out.println(OP_PROCURAR_CURSO + "- Procurar curso ");
		System.out.println(OP_ATUALIZAR_CURSO + "- Atualizar curso ");
		System.out.println(OP_DESCADASTRAR_CURSO + "- Descadastrar curso ");
		System.out.println(OP_MATRICULAR_ALUNO + "- Matricular aluno ");
		System.out.println(OP_PROCURAR_MATRICULA + "- Procurar matricula ");
		System.out.println(OP_CANCELAR_MATRICULA + "- Cancelar matricula ");
		System.out.println(OP_LISTAR_MATRICULAS
				+ "- listar todas as matriculas feitas ");
		System.out.println(OP_LISTAR_CURSOS
				+ "- listar todos os cursos cadastrados ");
		System.out.println(OP_LISTAR_ALUNOS
				+ "- listar todos os alunos cadastrados ");
		System.out.println(OP_LISTAR_ALUNOS_CURSO
				+ "- listar todos os alunos de um curso ");
		System.out.println(OP_LISTAR_ALUNOS_CURSOS
				+ "- listar todos os alunos de todos os cursos ");
		System.out.println(OP_LISTAR_CURSOS_ALUNO
				+ "- listar todos os cursos de um aluno ");
		System.out.println(OP_LISTAR_CURSOS_ALUNOS
				+ "- listar todos os cursos de todos os alunos ");
		System.out.println(OP_LISTAR_MATRICULAS_ALUNO 
				+ "- listar todas as matrículas de um aluno ");
		System.out.println( OP_LISTAR_MATRICULAS_CURSO
				+ "- listar todas as matrículas de um curso ");
		System.out.println(OP_LISTAR_ALUNOS_SEM_CURSO
				+ "- listar alunos cadastrados sem curso ");
		System.out.println(OP_LISTAR_CURSOS_SEM_ALUNO 
				+ "- listar cursos cadastrados sem alunos ");
		System.out.println(OP_SAIR  + "- SAIR ");
		System.out.println();
		
		System.out.println(" Favor escolher uma opcao: ");

	}

	public static void init() {

		/*
		 * A classe Scanner ajuda a ler dados da entrada, represtentada pelo
		 * objeto System.in. A documentacao desta classe esta na URL abaixo:
		 * http
		 * ://download.oracle.com/javase/1.5.0/docs/api/java/util/Scanner.html
		 * inserir a linha abaixo
		 */

		sc = new Scanner(System.in);

		/*
		 * use a linha abaixo para garantir que valores em ponto flutuante sao
		 * lidos esperando-se um ponto e nao uma virgula para a parte decimal:
		 * por exemplo, sera esperado 2.3 e nao 2,3
		 */

		sc.useLocale(Locale.US);

	
		fachada = Fachada.obterInstancia();

	}

	public static int pega_opcao() {

		//pega a opcao escolhida pelo usuario
		int i = sc.nextInt();
		
		//pula o ENTER que o usuario digitou. 
		sc.nextLine();

		return i;

	}

	public static void trata_opcao(int opcao) {
		String nome_aluno , nome_curso, endereco, telefone;
		int idade;
		String codigo, instrutor;
		nome_aluno = endereco = telefone = codigo = instrutor = null;
		Aluno aluno = null;
		Curso curso = null;
		Matricula matricula = null;
		ListaMatriculas lista_matriculas = null;
		ListaCursos lista_cursos = null;
		ListaAlunos lista_alunos = null;
		
		int cod_retorno = -1;


		switch (opcao) {

		case OP_CADASTRAR_ALUNO:
			System.out.println("Favor entre nome do aluno e  tecle Enter:");
			nome_aluno = sc.nextLine();
			System.out.println("Favor entre endereco do aluno e  tecle Enter:");
			endereco = sc.nextLine();
			System.out.println("Favor entre telefone do aluno e  tecle Enter:");
			telefone = sc.nextLine();
			System.out.println("Favor entre idade do aluno e  tecle Enter:");
			idade = sc.nextInt();
			
			
			aluno = new Aluno(nome_aluno, endereco, telefone, idade);
			fachada.cadastrar(aluno);
			break;

		case OP_PROCURAR_ALUNO:
			System.out.println("Favor entre nome do aluno e  tecle Enter:");
			nome_aluno = sc.nextLine();
			aluno = fachada.procurarAluno(nome_aluno);
			if (aluno != null) {
				System.out.println("Nome do aluno: " + aluno.getNome());
				System.out.println("Endereco do aluno: " + aluno.getEndereco());
				System.out.println("Telefone do aluno: " + aluno.getTelefone());
				System.out.println("Idade do aluno: " + aluno.getIdade());
			}
			break;

		case OP_ATUALIZAR_ALUNO:

			System.out.println("Favor entre nome do aluno e  tecle Enter:");
			nome_aluno = sc.nextLine();
			System.out.println("Favor entre endereco do aluno e  tecle Enter:");
			endereco = sc.nextLine();
			System.out.println("Favor entre telefone do aluno e  tecle Enter:");
			telefone = sc.nextLine();
			System.out.println("Favor entre idade do aluno e  tecle Enter:");
			idade = sc.nextInt();
			
			aluno = new Aluno(nome_aluno, endereco, telefone, idade);
			fachada.atualizar(aluno);
			break;

		case OP_DESCADASTRAR_ALUNO:

			System.out.println("Favor entre nome do aluno e  tecle Enter:");
			nome_aluno = sc.nextLine();
			fachada.descadastrarAluno(nome_aluno);
			break;

		case OP_CADASTRAR_CURSO:

			System.out.println("Favor entre codigo do curso e  tecle Enter:");
			codigo = sc.nextLine();
			System.out.println("Favor entre nome do curso e tecle Enter:");
			nome_curso = sc.nextLine();
			System.out.println("Favor entre instrutor do curso e tecle Enter:");
			instrutor = sc.nextLine();
			
			curso = new Curso(codigo, nome_curso, instrutor);
			fachada.cadastrar(curso);
			break;

		case OP_PROCURAR_CURSO:
			System.out.println("Favor entre codigo do curso e  tecle Enter:");
			codigo = sc.nextLine();
			curso = fachada.procurarCurso(codigo);
			if (curso != null) {
				System.out.println("Codigo do curso: " + curso.getCodigo());
				System.out.println("Nome do curso: " + curso.getNome());
				System.out.println("Instrutor do curso: " + curso.getInstrutor());
			}
			break;

		case OP_ATUALIZAR_CURSO:
			System.out.println("Favor entre codigo do curso e  tecle Enter:");
			codigo = sc.nextLine();
			System.out.println("Favor entre nome do curso e tecle Enter:");
			nome_curso = sc.nextLine();
			System.out.println("Favor entre instrutor do curso e tecle Enter:");
			instrutor = sc.nextLine();
			
			curso = new Curso(codigo, nome_curso, instrutor);
			fachada.atualizar(curso);
			break;

		case OP_DESCADASTRAR_CURSO:

			System.out.println("Favor entre codigo da curso e  tecle Enter:");
			codigo = sc.nextLine();
			fachada.descadastrarCurso(codigo);
			break;

		case OP_MATRICULAR_ALUNO:
			int max = 100;
			int qtd = 0;
			Curso curso_escolhido = null;
			
			System.out.println("1. Inserir Aluno e Curso.	2.Inserir so Aluno");
			int tipo = sc.nextInt();
			nome_aluno = sc.nextLine();
			System.out.println("Insira o nome do Aluno.");
			nome_aluno = sc.nextLine();
			if(tipo==1){
				System.out.println("Insira o codigo do curso.");
				codigo = sc.nextLine();
				aluno = fachada.procurarAluno(nome_aluno);
				curso = fachada.procurarCurso(codigo);

			}else if(tipo==2){
				lista_cursos = null; 
				lista_matriculas = null;
				lista_cursos = fachada.listaCursos();
				
				while(lista_cursos.hasNext()){
					qtd = 0;
					curso = lista_cursos.next();
					
					lista_matriculas = fachada.listaMatriculasCurso(curso.getCodigo());
					while(lista_matriculas.hasNext())
						qtd=qtd+1;
					
					if(qtd<max){
						curso_escolhido = curso;
						max = qtd;
					}
				}
			curso = curso_escolhido;
			}else{
				InterfaceTextual.reportar_erro("Opcao invalida.");
				break;
			}
			
			if(aluno == null || curso == null){
				InterfaceTextual.reportar_erro("Aluno ou curso nao cadastrado.");
				break;
			}
			else{
				
				Matricula matri = new Matricula(aluno, curso);
				fachada.cadastrar(matri);
			}

			break;

		case OP_PROCURAR_MATRICULA:
			System.out.println("Favor entre nome do aluno e tecle enter:");
			nome_aluno = sc.nextLine();
			
			System.out.println("Favor entre nome do curso e tecle enter:");
			nome_curso = sc.nextLine();
			
			matricula = fachada.procurarMatricula(nome_aluno, nome_curso);
			
			if (matricula != null) {
				System.out.println("Numero da matricula:"+ matricula.getNumero());
				System.out.println("Nome do aluno:"+ matricula.getAluno().getNome());
				System.out.println("Nome do curso:"+ matricula.getCurso().getNome());
			} else {
				InterfaceTextual.reportar_erro("Matricula inexistente.");
			}

			break;

		case OP_CANCELAR_MATRICULA:

			System.out.println("Favor entre nome do aluno e tecle enter:");
			nome_aluno = sc.nextLine();
			
			System.out.println("Favor entre nome do curso e tecle enter:");
			nome_curso = sc.nextLine();
			
			cod_retorno = fachada.descadastrarMatricula(nome_aluno, nome_curso);
			if (cod_retorno == 1) {
				System.out.println(">> matricula cancelada com sucesso.");
			} else {
				InterfaceTextual.reportar_erro("Matricula inexistente.");
			}

			break;

		
		case OP_LISTAR_MATRICULAS:
			lista_matriculas = null;
			lista_matriculas = fachada.listaMatriculas();
			System.out.println("---->>> DADOS DE TODAS AS MATRICULAS FEITAS <<<-----");
			while (lista_matriculas.hasNext()) {
				matricula = lista_matriculas.next();
				System.out.println("Numero da matricula: " + matricula.getNumero());
				if(matricula.getAluno()!=null) System.out.println("Nome do aluno: " + matricula.getAluno().getNome());
				if(matricula.getCurso()!=null) System.out.println("Nome do curso: " + matricula.getCurso().getNome());
				System.out.println("---------------------------------------------");
			}

			break;

		case OP_LISTAR_CURSOS:
			lista_cursos = null;
			lista_cursos = fachada.listaCursos();
			System.out.println("---->>> DADOS DE TODOS OS CURSOS CADASTRADOS <<<-----");
			while (lista_cursos.hasNext()) {
				curso = lista_cursos.next();
				System.out.println("Codigo do curso: " + curso.getCodigo());
				System.out.println("Nome do curso: " + curso.getNome());
				System.out.println("Instrutor do curso: " + curso.getInstrutor());
				System.out.println("---------------------------------------------");
				
			}
			break;

		case OP_LISTAR_ALUNOS:
			lista_alunos = null;
			lista_alunos = fachada.listaAlunos();
			System.out.println("---->>> DADOS DE TODOS OS ALUNOS CADASTRADOS <<<-----");
			while (lista_alunos.hasNext()) {
				aluno = lista_alunos.next();
				System.out.println("Nome do aluno: " + aluno.getNome());
				System.out.println("Endereco do aluno: " + aluno.getEndereco());
				System.out.println("Telefone do aluno: " + aluno.getTelefone());
				System.out.println("Idade do aluno: " + aluno.getIdade());
				System.out.println("---------------------------------------------");
			}

		break;

		case OP_LISTAR_ALUNOS_CURSO:
			System.out.println("Favor entre codigo do curso e  tecle Enter:");
			codigo = sc.nextLine();
			lista_matriculas = null;
			lista_matriculas = fachada.listaMatriculasCurso(codigo);	
			if (lista_matriculas != null)
			{
			System.out.println("---->>> DADOS DE TODOS OS ALUNOS DE UM CURSO <<<-----");
			while (lista_matriculas.hasNext()) {
				matricula = lista_matriculas.next();
				System.out.println("Nome do aluno: " + matricula.getAluno().getNome());
				System.out.println("Endereco do aluno: " + matricula.getAluno().getEndereco());
				System.out.println("Telefone do aluno: " + matricula.getAluno().getTelefone());
				System.out.println("Idade do aluno: " + matricula.getAluno().getIdade());
				System.out.println("---------------------------------------------");
			}
			}
			else {
				InterfaceTextual.reportar_erro("Nao ha alunos para este codigo");
			}

		break;

		case OP_LISTAR_ALUNOS_CURSOS:
			lista_matriculas = null;
			lista_matriculas = fachada.listaMatriculas();			
			System.out.println("---->>> DADOS DE TODOS OS ALUNOS DE TODOS OS CURSOS <<<-----");
			while (lista_matriculas.hasNext()) {
				matricula = lista_matriculas.next();
				if((matricula.getCurso())!= null){
					System.out.println("Nome do curso: " + matricula.getCurso().getNome());					
					System.out.println("Nome do aluno: " + matricula.getAluno().getNome());
					System.out.println("Endereco do aluno: " + matricula.getAluno().getEndereco());
					System.out.println("Telefone do aluno: " + matricula.getAluno().getTelefone());
					System.out.println("Idade do aluno: " + matricula.getAluno().getIdade());
					System.out.println("---------------------------------------------");
				}
				
			}

		break;

		case OP_LISTAR_CURSOS_ALUNO:
			System.out.println("Favor entre nome do aluno e tecle Enter:");
			nome_aluno = sc.nextLine();
			lista_matriculas = null;
			lista_matriculas = fachada.listaMatriculasAluno(nome_aluno);
			if (lista_matriculas != null)
			{
			System.out.println("---->>> DADOS DE TODOS OS CURSOS DE UM ALUNO <<<-----");
			while (lista_matriculas.hasNext()) {
				matricula = lista_matriculas.next();
				System.out.println("Nome do aluno: " + matricula.getAluno().getNome());
				System.out.println("Codigo do curso: " + matricula.getCurso().getCodigo());
				System.out.println("Nome do curso: " + matricula.getCurso().getNome());
				System.out.println("Instrutor do curso: " + matricula.getCurso().getInstrutor());
				System.out.println("---------------------------------------------");
			}
			}
			else {
				InterfaceTextual.reportar_erro("Não há cursos para esse aluno!");
			}
		break;

		case OP_LISTAR_CURSOS_ALUNOS:
			lista_matriculas = null;
			lista_matriculas = fachada.listaMatriculas();			
			System.out.println("---->>> DADOS DE TODOS OS CURSOS DE TODOS OS ALUNOS <<<-----");
			while (lista_matriculas.hasNext()) {
				matricula = lista_matriculas.next();
				if((matricula.getAluno())!= null){
					System.out.println("Nome do aluno: " + matricula.getCurso().getNome());					
					System.out.println("Nome do aluno: " + matricula.getAluno().getNome());
					System.out.println("Endereco do aluno: " + matricula.getAluno().getEndereco());
					System.out.println("Telefone do aluno: " + matricula.getAluno().getTelefone());
					System.out.println("Idade do aluno: " + matricula.getAluno().getIdade());
					System.out.println("---------------------------------------------");
				}
				
			}

		break;

		case OP_LISTAR_MATRICULAS_ALUNO:
			System.out.println("Favor entre nome_aluno do aluno e  tecle Enter:");
			nome_aluno = sc.nextLine();
			lista_matriculas = fachada.listaMatriculasAluno(nome_aluno);			
			if(lista_matriculas != null)
			{
			System.out.println("---->>> DADOS DE TODOS AS MATRICULAS DE UM ALUNO <<<-----");
			while (lista_matriculas.hasNext()) {
				matricula = lista_matriculas.next();
				System.out.println("Numero da matricula: " + matricula.getNumero());
			}
			} else {
				InterfaceTextual.reportar_erro("ERRO!");
			}
		break;

		case OP_LISTAR_MATRICULAS_CURSO:
			System.out.println("Favor entre codigo do curso e  tecle Enter:");
			codigo = sc.nextLine();
			lista_matriculas = fachada.listaMatriculasCurso(codigo);
			if (lista_matriculas != null)
			{
			System.out.println("---->>> DADOS DE TODOS AS MATRICULAS DE UM CURSO <<<-----");
			while (lista_matriculas.hasNext()) {
				matricula = lista_matriculas.next();
				System.out.println("Numero da matricula: " + matricula.getNumero());
				System.out.println("Nome do aluno: " + matricula.getAluno().getNome());
				System.out.println("Endereco do aluno: " + matricula.getAluno().getEndereco());
				System.out.println("Telefone do aluno: " + matricula.getAluno().getTelefone());
				System.out.println("Idade do aluno: " + matricula.getAluno().getIdade());
				System.out.println("---------------------------------------------");
			}}
			else {
				InterfaceTextual.reportar_erro("ERRO");
			}

		break;

		case OP_LISTAR_ALUNOS_SEM_CURSO:
			lista_alunos = fachada.listaAlunos();
			if(lista_alunos != null){
			    System.out.println("---->>> LISTA DE ALUNOS SEM CURSO <<<-----");
			    while(lista_alunos.hasNext()){
					aluno = lista_alunos.next();
					lista_matriculas = fachada.listaMatriculasAluno(aluno.getNome());
					lista_matriculas.next();
					if(lista_alunos.hasNext()==false)
						System.out.println(aluno.getNome());
				}
			}
		break;

		case OP_LISTAR_CURSOS_SEM_ALUNO:
			lista_matriculas = fachada.listaMatriculasAluno(null);
			System.out.println("---->>> LISTA DE ALUNOS SEM CURSO <<<-----");
			while (lista_matriculas.hasNext()) {
				matricula = lista_matriculas.next();
				
				System.out.println("Nome do curso: " + matricula.getCurso().getNome());
			}
		break;

		case OP_SAIR:
			System.out.println("******OBRIGADO POR USAR A APLICACAO DE MATRICULA*******");
			break;

		default:
			System.out.println("Opcao invalida! Favor entrar uma opcao entre 1 e 23");

		}

	}

	
}