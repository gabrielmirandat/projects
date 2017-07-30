package  unbPOO.escola.interfaceUsuario;

// tais linhas garantem que posssamos referenciar as classes Scanner e Locale.
import java.util.Scanner;
import java.util.Locale;

import unbPOO.escola.Fachada;
import unbPOO.escola.aluno.Aluno;
import unbPOO.escola.aluno.ListaAlunos;
import unbPOO.escola.aluno.AlunoJaExistenteException;

import unbPOO.escola.curso.Curso;
import unbPOO.escola.curso.ListaCursos;
import unbPOO.escola.curso.CursoJaExistenteException;

import unbPOO.escola.matricula.Matricula;
import unbPOO.escola.matricula.ListaMatriculas;
import unbPOO.escola.matricula.MatriculaJaExistenteException;

import unbPOO.escola.dados.aluno.AlunoNaoExistenteException;
import unbPOO.escola.dados.curso.CursoNaoExistenteException;
import unbPOO.escola.dados.matricula.MatriculaNaoExistenteException;

//classe de InterfaceTextual com o usuario
public class InterfaceTextual {
//declaração de atributos
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
	
	private static final int OP_CADASTRAR_MATRICULA = 9;
	private static final int OP_PROCURAR_MATRICULA = 10;
	private static final int OP_DESCADASTRAR_MATRICULA = 11;

	private static final int OP_EXIBIR_MATRICULAS = 12;
	private static final int OP_EXIBIR_CURSOS = 13;
	private static final int OP_EXIBIR_ALUNOS = 14;
	private static final int OP_EXIBIR_ALUNOSDEUMCURSO = 15;
	private static final int OP_EXIBIR_ALUNOSDETODOSOSCURSOS = 16;
	private static final int OP_EXIBIR_CURSOSDEUMALUNO = 17;
	private static final int OP_EXIBIR_CURSOSDETODOSALUNOS = 18;
	private static final int OP_EXIBIR_MATRICULASDEUMALUNO = 19;
	private static final int OP_EXIBIR_MATRICULASDEUMCURSO = 20;
	private static final int OP_EXIBIR_ALUNOSSEMCURSO = 21;
	private static final int OP_EXIBIR_CURSOS_SEM_ALUNOS = 22;
	private static final int OP_SAIR = 23;
	private static final int OP_INICIAL = -1;
        
	
// main do projeto
	public static void main(String[] args) {
		init();
		int opcao = OP_INICIAL;
		do {
			imprime_tela();
			opcao = pega_opcao();
                        
            try {
				trata_opcao(opcao);			
			} catch (AlunoJaExistenteException e) {
				System.out.println(e.getMessage());
				System.out.println(e.getStackTrace()[0]);
                                
                        } catch (CursoJaExistenteException e) {
				System.out.println(e.getMessage());
				System.out.println(e.getStackTrace()[0]);
                        
			} catch (MatriculaNaoExistenteException e) {
				System.out.println(e.getMessage());
				System.out.println(e.getStackTrace()[0]);
                        
			} catch (AlunoNaoExistenteException e) {
				System.out.println(e.getMessage());
				System.out.println(e.getStackTrace()[0]);
                        } catch (CursoNaoExistenteException e) {
				System.out.println(e.getMessage());
				System.out.println(e.getStackTrace()[0]);
			} catch (MatriculaJaExistenteException e) {
				System.out.println(e.getMessage());
				System.out.println(e.getStackTrace()[0]);
			}
		} while (opcao != OP_SAIR);
			

	}
//metodo para imprimir tela
	public static void imprime_tela() {

		System.out.println(" ****************************");
		System.out.println(" *** Centro de Ensino XYZ *** ");
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
		System.out.println(OP_CADASTRAR_MATRICULA + "- Matricular aluno ");
		System.out.println(OP_PROCURAR_MATRICULA + "- Procurar matricula ");
		System.out.println(OP_DESCADASTRAR_MATRICULA + "- Cancelar matricula ");
		System.out.println(OP_EXIBIR_MATRICULAS + "- Listar todas as matriculas feitas ");
		System.out.println(OP_EXIBIR_CURSOS + "- Listar todos os cursos cadastrados ");
		System.out.println(OP_EXIBIR_ALUNOS + "- Listar todos os alunos cadastrados ");
		System.out.println(OP_EXIBIR_ALUNOSDEUMCURSO + "- Listar todos os alunos de um curso ");
		System.out.println(OP_EXIBIR_ALUNOSDETODOSOSCURSOS + "- Listar todos os alunos de todos os cursos ");
		System.out.println(OP_EXIBIR_CURSOSDEUMALUNO + "- Listar todos os cursos de um aluno ");
		System.out.println(OP_EXIBIR_CURSOSDETODOSALUNOS + "- Listar todos os cursos de todos os alunos ");
		System.out.println(OP_EXIBIR_MATRICULASDEUMALUNO + "- Listar todas as matriculas de um aluno ");
		System.out.println(OP_EXIBIR_MATRICULASDEUMCURSO + "- Listar todos as matriculas de um curso ");
		System.out.println(OP_EXIBIR_ALUNOSSEMCURSO + "- Listar alunos cadastrados sem curso ");
		System.out.println(OP_EXIBIR_CURSOS_SEM_ALUNOS + "- Listar cursos cadastrados sem alunos. ");
		System.out.println(OP_SAIR + "- SAIR ");
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
//metodo para tratar a opção escolhida
	public static void trata_opcao(int opcao) throws MatriculaNaoExistenteException, AlunoNaoExistenteException, CursoNaoExistenteException, AlunoJaExistenteException,
			AlunoJaExistenteException, MatriculaJaExistenteException, CursoJaExistenteException {
            //variaveis
		String nomeAluno, endereco, telefone;
		int idade = 0;
		String nomeCurso, codigo, instrutor;
		
		//int numero = 0;
		nomeAluno = endereco = telefone = null;
		nomeCurso = codigo = instrutor = null;
		
		Aluno aluno = null;
		Curso curso = null;
		Matricula matricula;
		matricula = null;
                   
		// switch para tratar a opção desejada		
		switch (opcao) {
//cadastrar aluno
		case OP_CADASTRAR_ALUNO:
			System.out.println("Favor entre nome do aluno e  tecle Enter:");
			nomeAluno = sc.nextLine();
			System.out.println("Favor entre endereco do aluno e  tecle Enter:");
			endereco = sc.nextLine();
			System.out.println("Favor entre telefone do aluno e  tecle Enter:");
			telefone = sc.nextLine();
			System.out.println("Favor entre idade do aluno e  tecle Enter:");
			idade = sc.nextInt();

			aluno = new Aluno(nomeAluno, endereco, telefone, idade);
			fachada.cadastrarAluno(aluno);
			break;
//procurar aluno
		case OP_PROCURAR_ALUNO:
			System.out.println("Favor entre nome do aluno e  tecle Enter:");
			nomeAluno = sc.nextLine();
			aluno = fachada.procurarAluno(nomeAluno);
			if (aluno != null) {
				System.out.println("Nome do aluno: " + aluno.getNome());
				System.out.println("Endereco do aluno: " + aluno.getEndereco());
				System.out.println("Telefone do aluno: " + aluno.getTelefone());
				System.out.println("Idade do aluno: " + aluno.getIdade());
			} 
			break;
//ATUALIZAR_ALUNO
		case OP_ATUALIZAR_ALUNO:

			System.out.println("Favor entre nome do aluno e  tecle Enter:");
			nomeAluno = sc.nextLine();
			System.out.println("Favor entre endereco do aluno e  tecle Enter:");
			endereco = sc.nextLine();
			System.out.println("Favor entre telefone do aluno e  tecle Enter:");
			telefone = sc.nextLine();
			System.out.println("Favor entre idade do aluno e  tecle Enter:");
			idade = sc.nextInt();

			aluno = new Aluno(nomeAluno, endereco, telefone, idade);
			fachada.atualizarAluno(aluno);
			break;
//DESCADASTRAR_ALUNO
		case OP_DESCADASTRAR_ALUNO:

			System.out.println("Favor entre nome do aluno e  tecle Enter:");
			nomeAluno = sc.nextLine();
			fachada.descadastrarAluno(nomeAluno);
			break;

//CADASTRAR_CURSO
		case OP_CADASTRAR_CURSO:
			System.out.println("Favor entre codigo do curso e  tecle Enter:");
			codigo = sc.nextLine();
			System.out.println("Favor entre nome do curso e  tecle Enter:");
			nomeCurso = sc.nextLine();
			System.out.println("Favor entre instrutor do curso e  tecle Enter:");
			instrutor = sc.nextLine();
			
			curso = new Curso(codigo, nomeCurso, instrutor);
			fachada.cadastrarCurso(curso);
			break;
// procurar curso
		case OP_PROCURAR_CURSO:
			System.out.println("Favor entre codigo do curso e  tecle Enter:");
			codigo = sc.nextLine();
			curso = fachada.procurarCurso(codigo);
			if (curso != null) {
				System.out.println("Codigo do curso: " + curso.getCodigo());
				System.out.println("Nome do curso: " + curso.getNome());
				System.out.println("Instrutor: " + curso.getInstrutor());
				
			} 
			break;
// atualizar curso
		case OP_ATUALIZAR_CURSO:

			System.out.println("Favor entre codigo do curso e  tecle Enter:");
			codigo = sc.nextLine();
			System.out.println("Favor entre nome do curso e  tecle Enter:");
			nomeCurso = sc.nextLine();
			System.out.println("Favor entre instrutor do curso e  tecle Enter:");
			instrutor = sc.nextLine();
			
			curso = new Curso(codigo, nomeCurso, instrutor);
			fachada.atualizarCurso(curso);
			break;
// descadastrar curso
		case OP_DESCADASTRAR_CURSO:

			System.out.println("Favor entre codigo do curso e  tecle Enter:");
			codigo = sc.nextLine();
			fachada.descadastrarCurso(codigo);
			break;
//cadastrar matricula
		case OP_CADASTRAR_MATRICULA:

			System.out.println("Favor entre nome do aluno e  tecle Enter:");
			nomeAluno = sc.nextLine();
			aluno = new Aluno(nomeAluno, null, null, 0);

			System.out.println("Favor entre codigo do curso (opcional) e  tecle Enter:");
			codigo = sc.nextLine();
                        if (codigo.length() != 0){// se foi escolhido codigo
			curso = new Curso(codigo, null, null);
			matricula = new Matricula(aluno, curso);
                        } else 
                            if(codigo.length() == 0) { // se nÃ£o foi escolhido codigo do curso, cadastra no curso de menor tamanho
                        curso = fachada.menorCurso();
                        matricula = new Matricula(aluno, curso);                        
                        }
			fachada.cadastrarMatricula(matricula);
			System.out.println(">> Matricula realizada com sucesso:");

			break;
//procurar matricula
		case OP_PROCURAR_MATRICULA:
			System.out.println("Favor entre nome do aluno e  tecle Enter:");
			nomeAluno = sc.nextLine();
			System.out.println("Favor entre codigo do curso e  tecle Enter:");
			codigo = sc.nextLine();
			matricula = fachada.procurarMatricula(nomeAluno, codigo);
			if (matricula != null) {
				System.out.println("Numero da matricula: " + matricula.getNumero());
				
				aluno = matricula.getAluno();
				curso = matricula.getCurso();

				System.out.println("Nome do aluno: " + aluno.getNome());
				System.out.println("Endereco do aluno: " + aluno.getEndereco());
				System.out.println("Telefone do aluno: " + aluno.getTelefone());
				System.out.println("Idade do aluno: " + aluno.getIdade());
				System.out.println("Nome do curso: " + curso.getNome());
				System.out.println("Codigo do curso: " + curso.getCodigo());
				System.out.println("Instrutor do curso: " + curso.getInstrutor());
				
				
			} 
			break;

// descadastra matricula
		case OP_DESCADASTRAR_MATRICULA:

			System.out.println("Favor entre nome do aluno e  tecle Enter:");
			nomeAluno = sc.nextLine();
			System.out.println("Favor entre codigo do curso e  tecle Enter:");
			codigo = sc.nextLine();
			fachada.descadastrarMatricula(nomeAluno, codigo);
			System.out.println(">> Matricula cancelada com sucesso:");
			
			break;
//exibe todas as matriculas
		case OP_EXIBIR_MATRICULAS:
			
			ListaMatriculas lista_matriculas = fachada.listaMatriculas();
			System.out.println("---->>> DADOS DE TODAS AS MATRICULAS <<<-----");
			while (lista_matriculas.hasNext()) {
				matricula = lista_matriculas.next();
				aluno = matricula.getAluno();
				curso = matricula.getCurso();
				System.out.println("Numero da matricula: " + matricula.getNumero());
				
				System.out.println("Nome do aluno desta matricula: " + aluno.getNome());
				System.out.println("Codigo do curso desta: " + curso.getCodigo());
				System.out.println("---------------------------------------------");
				
			}
			break;
//exibe todos os cursos
		case OP_EXIBIR_CURSOS:
			System.out.println("---->>> DADOS DE TODOS OS CURSOS <<<-----");
			ListaCursos lista_cursos = fachada.listaCursos();
			while (lista_cursos.hasNext()) {
				curso = lista_cursos.next();
				System.out.println("Nome do curso: " + curso.getNome());
				System.out.println("Codigo do curso: " + curso.getCodigo());
				System.out.println("Instrutor do curso: " + curso.getInstrutor());
				
				System.out.println("---------------------------------------------");
			}

		break;
// exibe todos os alunos
		case OP_EXIBIR_ALUNOS:
			System.out.println("---->>> DADOS DE TODOS OS ALUNOS <<<-----");
			ListaAlunos lista_alunos = fachada.listaAlunos();
			while (lista_alunos.hasNext()) {
				aluno = lista_alunos.next();
				System.out.println("Nome do aluno: " + aluno.getNome());
				System.out.println("Endereco do aluno: " + aluno.getEndereco());
				System.out.println("Telefone do aluno: " + aluno.getTelefone());
				System.out.println("Idade do aluno: " + aluno.getIdade());
				System.out.println("---------------------------------------------");
			}

		break;

//exibe todos os alunos de um curso
		case OP_EXIBIR_ALUNOSDEUMCURSO:
			System.out.println("Favor entre codigo do curso e  tecle Enter:");
			codigo = sc.next();
			curso = fachada.procurarCurso(codigo);
			if (curso != null) {
				System.out.println("Nome do curso: " + curso.getNome());
				System.out.println("Codigo do curso: " + curso.getCodigo());
				
				ListaAlunos lista_alunos1 = fachada.listaAlunosCurso(codigo);
				while (lista_alunos1.hasNext()) {
					aluno = lista_alunos1.next();
					System.out.println("Nome do Aluno: " + aluno.getNome());
					
				}
			} 
			break;
//exibe todos os alunos de todos os cursos
		case OP_EXIBIR_ALUNOSDETODOSOSCURSOS:
			System.out.println("---->>> ALUNOS DE TODOS OS CURSOS <<<-----");
			ListaCursos lista_cursos1 = fachada.listaCursos();
			while (lista_cursos1.hasNext()) {
				curso = lista_cursos1.next();
				System.out.println("Nome do curso: " + curso.getNome());
				System.out.println("Codigo do curso: " + curso.getCodigo());
				codigo = curso.getCodigo();
				ListaAlunos lista_alunos2 = fachada.listaAlunosCurso(codigo);
				while (lista_alunos2.hasNext()) {
					aluno = lista_alunos2.next();
					System.out.println("Nome do Aluno: " + aluno.getNome());					
				}				
				System.out.println("---------------------------------------------");
			}

		break;
//exibe todos os cursos de uma aluno
		case OP_EXIBIR_CURSOSDEUMALUNO:
			System.out.println("Favor entre nome do aluno e  tecle Enter:");
			nomeAluno = sc.next();
			aluno = fachada.procurarAluno(nomeAluno);
			if (aluno != null) {
				System.out.println("Nome do aluno: " + aluno.getNome());
				
				ListaCursos lista_cursos3 = fachada.listaCursosAluno(nomeAluno);
				while (lista_cursos3.hasNext()) {
					curso = lista_cursos3.next();
					
					System.out.println("Codigo do curso: " + curso.getCodigo());
				}
			} else {
				System.out.println("Nome do aluno: " + nomeAluno + " nao existe");
			}

			break;
//EXIBIR_CURSOSDETODOSALUNOS
		case OP_EXIBIR_CURSOSDETODOSALUNOS:
			System.out.println("---->>> CURSOS DE TODOS OS ALUNOS <<<-----");
			ListaAlunos lista_alunos4 = fachada.listaAlunos();
			while (lista_alunos4.hasNext()) {
				aluno = lista_alunos4.next();
				System.out.println("Nome do aluno: " + aluno.getNome());
				nomeAluno = aluno.getNome();

				ListaCursos lista_cursos5 = fachada.listaCursosAluno(nomeAluno);
				while (lista_cursos5.hasNext()) {
					curso = lista_cursos5.next();
					
				System.out.println("Codigo do curso: " + curso.getCodigo());
				
				System.out.println("---------------------------------------------");
			
                                }
                        }
		break;
                                
//OP_EXIBIR_MATRICULASDEUMALUNO
		case OP_EXIBIR_MATRICULASDEUMALUNO:
			System.out.println("Favor entre nome do aluno e  tecle Enter:");
			nomeAluno = sc.next();
			aluno = fachada.procurarAluno(nomeAluno);
			if (aluno != null) {
				System.out.println("Nome do aluno: " + aluno.getNome());
				
				ListaMatriculas lista_matriculas6 = fachada.listaMatriculasAluno(nomeAluno);
				while (lista_matriculas6.hasNext()) {
					matricula = lista_matriculas6.next();
					System.out.println("Numero da matricula: " + matricula.getNumero());
					System.out.println("Codigo do curso dessa matricula: " + ((matricula.getCurso()).getCodigo()));
				}
			} else {
				System.out.println("Nome do aluno: " + nomeAluno + " nao existe");
			}

			break;

//OP_EXIBIR_MATRICULASDEUMCURSO
		case OP_EXIBIR_MATRICULASDEUMCURSO:
			System.out.println("Favor entre codigo do curso e  tecle Enter:");
			codigo = sc.next();
			curso = fachada.procurarCurso(codigo);
			if (curso != null) {
				System.out.println("Nome do curso: " + curso.getNome());
				System.out.println("Codigo do curso: " + curso.getCodigo());
				
				ListaMatriculas lista_matriculas7 = fachada.listaMatriculasCurso(codigo);
				while (lista_matriculas7.hasNext()) {
					matricula = lista_matriculas7.next();
					System.out.println("Numero da matricula: " + matricula.getNumero());
					System.out.println("Nome do aluno dessa matricula: " + ((matricula.getAluno()).getNome()));
				}
			} else {
				System.out.println("Codigo do curso: " + codigo + " nao existe");
			}

			break;

//ALUNOS SEM CURSO
		case OP_EXIBIR_ALUNOSSEMCURSO:
			System.out.println("---->>> ALUNOS SEM CURSO <<<-----");
			ListaAlunos lista_alunos8 = fachada.listaAlunos();
			while (lista_alunos8.hasNext()) {
				aluno = lista_alunos8.next();

				nomeAluno = aluno.getNome();
				ListaCursos lista_cursos9 = fachada.listaCursosAluno(nomeAluno);
				if (lista_cursos9.getTamanhoLista() == 0) { // SE A LISTA TEM TAMANHO 0
				System.out.println("Nome do aluno: " + nomeAluno);
				}
			}

		break;
// CURSOS SEM ALUNO
		case OP_EXIBIR_CURSOS_SEM_ALUNOS:
			System.out.println("---->>> CURSOS SEM ALUNOS <<<-----");
			ListaCursos lista_cursos10 = fachada.listaCursos();
			while (lista_cursos10.hasNext()) {
				curso = lista_cursos10.next();

				codigo = curso.getCodigo();
				ListaAlunos lista_alunos11 = fachada.listaAlunosCurso(codigo);
				if (lista_alunos11.getTamanhoLista() == 0) {// SE A LISTA TEM TAMANHO 0
				System.out.println("Nome do curso: " + curso.getNome() + ", Codigo: " + curso.getCodigo());
				}
			}

		break;		
// PARA SAIR
		case OP_SAIR:
			System.out.println("******OBRIGADO POR USAR A APLICACAO DE MATRICULA*******");
			break;
// SE NÃƒO FOI ESCOLHIDA UMA OPÃ‡ÃƒO VÃLIDA
		default:
			System.out.println("Opcao invalida! Favor entrar uma opcao entre 1 e 23");

		}

	}	
}

