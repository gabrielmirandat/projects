public class Fachada {

	private static Fachada instancia;
	private CadastroAlunos alunos;
	private CadastroCursos cursos;
	private CadastroMatriculas matriculas;


	public static Fachada obterInstancia() {
		if (instancia == null) {
			instancia = new Fachada();
		}
		return instancia;
	}

	private Fachada() {
		initCadastros();
	}

	private void initCadastros() {
		RepositorioAlunosArray repAlunos = new RepositorioAlunosArray();
		alunos = new CadastroAlunos(repAlunos);
		RepositorioCursosArray repCursos = new RepositorioCursosArray();
		cursos = new CadastroCursos(repCursos);
		RepositorioMatriculasArray repMatriculas = new RepositorioMatriculasArray();
		matriculas = new CadastroMatriculas(repMatriculas);

	}

	// metodos para manipular alunos
	public void atualizar(Aluno c) {
		alunos.atualizar(c);
	}

	public Aluno procurarAluno(String nome) {
		return alunos.procurar(nome);
	}

	public void cadastrar(Aluno c) {
		alunos.cadastrar(c);
	}

	public void descadastrarAluno(String nome) {
		// descadastra primeiro as matriculas do aluno, pois nao faz sentido matricula sem aluno
		// esta eh uma regra de negocio
		Matricula matricula = null;
		ListaMatriculas lista_matriculas =  listaMatriculasAluno(nome);
		while (lista_matriculas.hasNext()) {
			matricula = lista_matriculas.next();
			matriculas.descadastrar(matricula.getAluno().getNome(), null);
		}
		// agora sim, descadastra o aluno
		alunos.descadastrar(nome);
	}

	// metodos para manipular cursos
		public void atualizar(Curso c) {
			cursos.atualizar(c);
		}

		public Curso procurarCurso(String codigo) {
			return cursos.procurar(codigo);
		}

		public void cadastrar(Curso c) {
			cursos.cadastrar(c);
		}

		public void descadastrarCurso(String codigo) {
			// descadastra primeiro as matriculas do curso, pois nao faz sentido matricula sem curso
			// esta eh uma regra de negocio
			Matricula matricula = null;
			ListaMatriculas lista_matriculas =  listaMatriculasCurso(codigo);
			while (lista_matriculas.hasNext()) {
				matricula = lista_matriculas.next();
				matriculas.descadastrar(null, matricula.getCurso().getNome());
			}
			// agora sim, descadastra o curso
			cursos.descadastrar(codigo);
		}	
	
	
	// metodos para manipular matriculas
	public Matricula procurarMatricula(String nome_aluno, String nome_curso) {
		return matriculas.procurar(nome_aluno, nome_curso);
	}

	public int cadastrar(Matricula c) {
		int r = -1;
		Aluno aluno_lido = null;
		Curso curso_lido = null;
		aluno_lido = c.getAluno();
		curso_lido = c.getCurso();
		
		if (aluno_lido != null && curso_lido != null) {
			if (matriculas.cadastrar(c)==1)
				r = 1;
		} 
		return r;
	}
	
	public int descadastrarMatricula(String nome_aluno, String nome_curso){
		return matriculas.descadastrar(nome_aluno,nome_curso);
	}

	public ListaMatriculas listaMatriculasAluno(String nome) {
		ListaMatriculas lm = null;
		Aluno aluno = alunos.procurar(nome);
		if (aluno != null) {
			lm = matriculas.listaMatriculasAluno(nome);
			
		} 
		return lm;
	}

	public ListaMatriculas listaMatriculasCurso(String codigo) {
		ListaMatriculas lm = null;
		Curso curso = cursos.procurar(codigo);
		if (curso != null) {
			lm = matriculas.listaMatriculasCurso(codigo);
		} 
		return lm;
	}
	
	public ListaMatriculas listaMatriculas() {

		return matriculas.listaMatriculas();
		
	}

	public ListaAlunos listaAlunos() {
		// 
		return alunos.listaAlunos();
	}
	
	public ListaCursos listaCursos() {
		// 
		return cursos.listaCursos();
	}



}
