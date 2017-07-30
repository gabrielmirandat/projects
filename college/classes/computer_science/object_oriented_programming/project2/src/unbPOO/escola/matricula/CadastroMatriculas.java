package  unbPOO.escola.matricula;

import unbPOO.escola.aluno.Aluno;
import unbPOO.escola.curso.Curso;
import unbPOO.escola.matricula.Matricula;
import unbPOO.escola.dados.matricula.MatriculaNaoExistenteException;
import unbPOO.escola.dados.matricula.RepositorioMatriculas;
import unbPOO.escola.aluno.ListaAlunos;
import unbPOO.escola.curso.ListaCursos;

// coleçao de negócio para o repositório de matriculas
public class CadastroMatriculas {
// declaracao de atributos
	private RepositorioMatriculas matriculas;
// construtor da classe
	public CadastroMatriculas(RepositorioMatriculas r) {
		this.matriculas = r;
	}

	//metodos public a serem usados na fachada
      // metodo para cadastrar Matricula m
	public void cadastrar(Matricula m) throws MatriculaJaExistenteException {
                
		if (!matriculas.existe(((m.getAluno()).getNome()), ((m.getCurso()).getCodigo()))) {
			matriculas.inserir(m);
                        
		} 
                else {//se existe, ja foi cadastrado
			throw new MatriculaJaExistenteException(((m.getAluno()).getNome()), ((m.getCurso()).getCodigo()));
		}
	}
// metodo para descadastrar Matricula m
	public void descadastrar(String nomeAluno, String codigo) throws MatriculaNaoExistenteException{
             matriculas.remover(nomeAluno, codigo);
	}
// metodo para procurar Matricula m
	public Matricula procurar(String nomeAluno, String codigoCurso) throws MatriculaNaoExistenteException{
		return matriculas.procurar(nomeAluno, codigoCurso);
	}
// metodo que retorna a lista de matriculas
	public ListaMatriculas listaMatriculas() {

		Matricula[] matriculas = null; // cria vetor
		Matricula matricula = null;
		matriculas = this.matriculas.getMatriculas();
		int numeroMatriculas = this.matriculas.getIndice();//pega o ultimo indice do vetor
		ListaMatriculas lm = new ListaMatriculas();//construtor de lista
		for (int i = 0; i < numeroMatriculas; i++) {// laço para inserir na lista as matriculas do vetor
			matricula = matriculas[i];
			lm.insert(matricula);
		}
		return lm;

	}
        // metodo que retorna a lista de matriculas de um aluno
        public ListaMatriculas listaMatriculasAluno(String nomeAluno) {
		Matricula[]  matriculas = null;
		Matricula matricula = null;
		Aluno aluno = null;
		String nome_aux = null;
		
		matriculas = this.matriculas.getMatriculas();
		int numeroMatriculas = this.matriculas.getIndice();
		// estamos assumindo que um aluno pode ter mais de uma matricula; neste caso, mostramos todas.
		ListaMatriculas lm = new ListaMatriculas();//construtor
		for (int i = 0; i < numeroMatriculas; i++) {//laco para inserir matriculas na lista
			matricula = matriculas[i];
			aluno = matricula.getAluno();//pega o aluno da matricula
			nome_aux = aluno.getNome();//nome_aux recebe o nome do aluno
			if (nome_aux.equals(nomeAluno)) {// se esse nome é o mesmo daquele passado por parametro
				lm.insert(matricula);//insere na lista
			}
		}
		return lm;
	}
 // metodo que retorna a lista de matriculas de um curso
	public ListaMatriculas listaMatriculasCurso(String codigo) {
		Matricula[]  matriculas = null;
		Matricula matricula = null;
		Curso curso = null;
		String codigo_aux = null;
		
		matriculas = this.matriculas.getMatriculas();
		int numeroMatriculas = this.matriculas.getIndice();
		// estamos assumindo que um curso pode ter mais de uma matricula; neste caso, mostramos todas.
		ListaMatriculas lm = new ListaMatriculas();//construtor
		for (int i = 0; i < numeroMatriculas; i++) {//laco para inserir matriculas na lista
			matricula = matriculas[i];
			curso = matricula.getCurso();//pega o curso da matricula
			codigo_aux = curso.getCodigo();//codigo_aux recebe o codigo do curso
			if (codigo_aux.equals(codigo)) {// se esse codigo é o mesmo daquele passado por parametro
				lm.insert(matricula);//insere na lista
			}
		}
		return lm;
	}
  // metodo que retorna a lista de alunos de um curso       
        public ListaAlunos listaAlunosCurso(String codigo) {
		
		Matricula[]  matriculas = null;
		Matricula matricula = null;
		Curso curso = null;
		String codigo_aux = null;
		
		matriculas = this.matriculas.getMatriculas();
		int numeroMatriculas = this.matriculas.getIndice();
		// estamos assumindo que um curso pode ter mais de uma matricula; neste caso, mostramos todas.
		ListaAlunos la = new ListaAlunos();//construtor
                
		for (int i = 0; i < numeroMatriculas; i++) {//laco para inserir matriculas na lista
			matricula = matriculas[i];
			curso = matricula.getCurso();//pega o curso da matricula
			codigo_aux = curso.getCodigo();//codigo_aux recebe o codigo do curso
			if (codigo_aux.equals(codigo)) {// se esse codigo é o mesmo daquele passado por parametro
				la.insert(matricula.getAluno());//insere o  aluno na lista de alunos
			}
		}
		return la;
	}

// metodo que retorna a lista de cursos de uma aluno 
	public ListaCursos listaCursosAluno(String nomeAluno) {
		Matricula[]  matriculas = null;
		Matricula matricula = null;
		Aluno aluno = null;
		String nome_aux = null;		
		matriculas = this.matriculas.getMatriculas();
		int numeroMatriculas = this.matriculas.getIndice();
		// estamos assumindo que um aluno pode ter mais de uma matricula; neste caso, mostramos todas.
		ListaCursos lc = new ListaCursos();          // construtor      
		for (int i = 0; i < numeroMatriculas; i++) {//laco para inserir matriculas na lista
			matricula = matriculas[i];
			aluno = matricula.getAluno();// pega o aluno
			nome_aux = aluno.getNome();//nome_aux recebe o nome do aluno
			if (nome_aux.equals(nomeAluno)) {// se esse nome é o mesmo daquele passado por parametro
				lc.insert(matricula.getCurso());//insere
			}
		}
		return lc;
	}


}
