package unbPOO.escola;

import unbPOO.escola.aluno.CadastroAlunos;
import unbPOO.escola.aluno.Aluno;
import unbPOO.escola.aluno.AlunoJaExistenteException;
import unbPOO.escola.aluno.ListaAlunos;

import unbPOO.escola.curso.CadastroCursos;
import unbPOO.escola.curso.Curso;
import unbPOO.escola.curso.CursoJaExistenteException;
import unbPOO.escola.curso.ListaCursos;

import unbPOO.escola.matricula.CadastroMatriculas;
import unbPOO.escola.matricula.Matricula;
import unbPOO.escola.matricula.MatriculaJaExistenteException;
import unbPOO.escola.matricula.ListaMatriculas;

import unbPOO.escola.dados.aluno.RepositorioAlunos;
import unbPOO.escola.dados.aluno.RepositorioAlunosArquivoTexto;
import unbPOO.escola.dados.aluno.AlunoNaoExistenteException;

import unbPOO.escola.dados.curso.RepositorioCursos;
import unbPOO.escola.dados.curso.RepositorioCursosArquivoTexto;
import unbPOO.escola.dados.curso.CursoNaoExistenteException;

import unbPOO.escola.dados.matricula.RepositorioMatriculas;
import unbPOO.escola.dados.matricula.RepositorioMatriculasArquivoTexto;
import unbPOO.escola.dados.matricula.MatriculaNaoExistenteException;

//fachada
public class Fachada {
//declaração de atributos
	private static Fachada instancia;
	private CadastroMatriculas matriculas;
	private CadastroAlunos alunos;
	private CadastroCursos cursos; 
//metodo para obter instancia
	public static Fachada obterInstancia() {
		if (instancia == null) {
			instancia = new Fachada();
		}
		return instancia;
	}
// construtor
	private Fachada() {
		initCadastros();
	}

	private void initCadastros() {
            
               
		String arqAlunos = "arqRepAlunos.txt";
		String arqCursos = "arqRepCursos.txt";
                String arqMatriculas = "arqRepMatriculas.txt";
            
		RepositorioMatriculas repMatriculas = new RepositorioMatriculasArquivoTexto(arqMatriculas,arqAlunos, arqCursos);
		matriculas = new CadastroMatriculas(repMatriculas);
		RepositorioAlunos repAlunos = new RepositorioAlunosArquivoTexto(arqAlunos);
		alunos = new CadastroAlunos(repAlunos);
		RepositorioCursos repCursos = new RepositorioCursosArquivoTexto(arqCursos);
		cursos = new CadastroCursos(repCursos);
	}

	// metodos para manipular alunos, usando CadastroAlunos
	public void atualizarAluno(Aluno a) throws AlunoNaoExistenteException {
		alunos.atualizar(a);
	}

	public Aluno procurarAluno(String nomeAluno) throws AlunoNaoExistenteException {
		return alunos.procurar(nomeAluno);
	}

	public void cadastrarAluno(Aluno a) throws AlunoJaExistenteException {
		alunos.cadastrar(a);
	}

	public void descadastrarAluno(String nomeAluno) throws AlunoNaoExistenteException {
		// descadastra primeiro as matriculas do aluno, pois nao faz sentido matricula sem aluno
		// esta eh uma regra de negocio
		Matricula matricula = null;
		ListaMatriculas lista_matriculas =  listaMatriculasAluno(nomeAluno);
		while (lista_matriculas.hasNext()) {
			matricula = lista_matriculas.next();
                        try {
				matriculas.descadastrar(((matricula.getAluno()).getNome()), matricula.getCurso().getCodigo());
			} catch (MatriculaNaoExistenteException e) {
				// esta excecao nao deveria ser lancada porque sao matriculas do aluno
				// o catch eh usado para que a assinatura do metodo nao tenha que
				// declarar a excecao MatriculaNaoExistenteException 
			}
                }
		// agora sim, descadastra o aluno
		alunos.descadastrar(nomeAluno);
	}
        
	// metodos para manipular cursos, usando CadastroCursos
	public void atualizarCurso(Curso c) throws CursoNaoExistenteException{
		cursos.atualizar(c);
	}

	public Curso procurarCurso(String codigoCurso) throws CursoNaoExistenteException{
		return cursos.procurar(codigoCurso);
	}

	public void cadastrarCurso(Curso c) throws CursoJaExistenteException{
		cursos.cadastrar(c);
	}

	public void descadastrarCurso(String codigoCurso) throws CursoNaoExistenteException {
		// descadastra primeiro as matriculas do curso, pois nao faz sentido matricula sem curso
		// esta eh uma regra de negocio
		Matricula matricula = null;
		ListaMatriculas lista_matriculas =  listaMatriculasCurso(codigoCurso);
		while (lista_matriculas.hasNext()) {
			matricula = lista_matriculas.next();
                        try {
			matriculas.descadastrar(matricula.getAluno().getNome(), ((matricula.getCurso()).getCodigo()));
			} catch (MatriculaNaoExistenteException e) {
				// esta excecao nao deveria ser lancada porque sao contas do cliente
				// o catch eh usado para que a assinatura do metodo nao tenha que
				// declarar a excecao ContaNaoExistenteException 
			}
		}
		
		// agora sim, descadastra o curso
		cursos.descadastrar(codigoCurso);
	}

	// metodos para manipular matriculas, usando CadastroMatriculas
	public Matricula procurarMatricula(String nomeAluno, String codigoCurso) throws MatriculaNaoExistenteException{
		return matriculas.procurar(nomeAluno, codigoCurso);
	}	

	public void cadastrarMatricula(Matricula m) throws AlunoNaoExistenteException, CursoNaoExistenteException, MatriculaJaExistenteException{		
		
		Aluno aluno_lido, aluno_existente = null;
		aluno_lido = m.getAluno();

		Curso curso_lido, curso_existente = null;
		curso_lido = m.getCurso();

		if ((aluno_lido != null) && (curso_lido != null)) {
			aluno_existente = alunos.procurar(aluno_lido.getNome());
			curso_existente = cursos.procurar(curso_lido.getCodigo());			
			m.setAluno(aluno_existente);
			m.setCurso(curso_existente);
                        matriculas.cadastrar(m);			
		} 		
	}

	public void descadastrarMatricula(String nomeAluno, String codigoCurso) throws MatriculaNaoExistenteException {
             matriculas.descadastrar(nomeAluno, codigoCurso);
	}	

	public ListaMatriculas listaMatriculasAluno(String nome) throws AlunoNaoExistenteException{
		ListaMatriculas lm = null;
		lm = matriculas.listaMatriculasAluno(nome);
		
		return lm;
	}

	public ListaMatriculas listaMatriculasCurso(String codigo) throws CursoNaoExistenteException {
		ListaMatriculas lm = null;
		lm = matriculas.listaMatriculasCurso(codigo);
		
		return lm;
	}
//metodos para retornar listas
	public ListaAlunos listaAlunosCurso(String codigo) throws CursoNaoExistenteException {
		ListaAlunos la = null;
		la = matriculas.listaAlunosCurso(codigo);
		
		return la;
	}

	public ListaCursos listaCursosAluno(String nome) throws AlunoNaoExistenteException {
		ListaCursos lc = null;
		lc = matriculas.listaCursosAluno(nome);
		
		return lc;
	}

	public ListaMatriculas listaMatriculas() {

		return matriculas.listaMatriculas();
		
	}

	public ListaAlunos listaAlunos() {
		return alunos.listaAlunos();
	}

	public ListaCursos listaCursos() {
		return cursos.listaCursos();
	}
        // metodo para pegar o curso com menos alunos cadastrados, a fim de ser utilizado na Interface Textual
        public Curso menorCurso() throws CursoNaoExistenteException{
            int i = 100;
            Curso curso = null;            
            ListaCursos lista_cursos = listaCursos();
            if (lista_cursos.getTamanhoLista() != 0){
            while (lista_cursos.hasNext()){ // enquanto a lista não acaba
            curso = lista_cursos.next();//pega o proximo curso             
            String codigo = curso.getCodigo();//pega o codigo do curso    
            ListaAlunos lista_alunos = listaAlunosCurso(codigo);//cria lista 
            int tamanho = lista_alunos.getTamanhoLista();//pega o tamanho
            if (tamanho < i) {//se o tamanho for menor que i
                i = tamanho;// i recebe o tamanho, de modo que i será o menor tamanho
                curso = new Curso(codigo, null, null);  // curso será aquele de menor tamanho
            }           
            }
            return curso;
            }
            else {
                String codigo = "vazio";
                throw new CursoNaoExistenteException(codigo);}
        }

}

