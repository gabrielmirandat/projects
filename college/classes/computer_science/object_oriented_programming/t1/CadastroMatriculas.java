public class CadastroMatriculas {

	private RepositorioMatriculasArray matriculas;

	public CadastroMatriculas(RepositorioMatriculasArray r) {
		this.matriculas = r;
	}

	public int cadastrar(Matricula c) {
		int r = -1;
		if (!matriculas.existe(c.getAluno().getNome(), c.getCurso().getNome())) {
			matriculas.inserir(c);
			r = 1;
		}
		return r;

	}

	public int descadastrar(String nome_aluno, String nome_curso) {
		return matriculas.remover(nome_aluno, nome_curso);
	}

	public Matricula procurar(String nome_aluno, String nome_curso) {
		return matriculas.procurar(nome_aluno, nome_curso);
	}

	public ListaMatriculas listaMatriculasAluno(String nome) {
		Matricula[]  matriculas = null;
		Matricula matricula = null;
		Aluno aluno = null;
		String nome_aux = null;

		matriculas = this.matriculas.getMatriculas();
		int numeroMatriculas = this.matriculas.getIndice();
		// estamos assumindo que um aluno pode ter mais de uma matricula; neste caso, mostramos todas.
		ListaMatriculas lm = new ListaMatriculas();
		for (int i = 0; i < numeroMatriculas; i++) {
			matricula = matriculas[i];
			aluno = matricula.getAluno();
			nome_aux = aluno.getNome();
			if (nome_aux.equals(nome)) {
				lm.insert(matricula);
			}
		}
		return lm;
	}

	public ListaMatriculas listaMatriculasCurso(String codigo) {
		Matricula[]  matriculas = null;
		Matricula matricula = null;
		Curso curso = null;
		String codigo_aux = null;

		matriculas = this.matriculas.getMatriculas();
		int numeroMatriculas = this.matriculas.getIndice();
		// estamos assumindo que um curso pode ter mais de uma matricula; neste caso, mostramos todas.
		ListaMatriculas lm = new ListaMatriculas();
		for (int i = 0; i < numeroMatriculas; i++) {
			matricula = matriculas[i];
			curso = matricula.getCurso();
			codigo_aux = curso.getCodigo();
			if (codigo_aux.equals(codigo)) {
				lm.insert(matricula);
			}
		}
		return lm;
	}
	
	public ListaMatriculas listaMatriculas() {

		Matricula[]  matriculas = null;
		Matricula matricula = null;
		matriculas = this.matriculas.getMatriculas();
		int numeroMatriculas = this.matriculas.getIndice();
		ListaMatriculas lm = new ListaMatriculas();
		for (int i = 0; i < numeroMatriculas; i++) {
			matricula = matriculas[i];
			lm.insert(matricula);
		}
		return lm;
	}

}
