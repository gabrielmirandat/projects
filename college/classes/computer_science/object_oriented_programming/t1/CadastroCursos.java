public class CadastroCursos {

	private RepositorioCursosArray cursos;

	public CadastroCursos(RepositorioCursosArray r) {
		this.cursos = r;
	}

	public void atualizar(Curso cu) {
		 Curso cur = cursos.procurar(cu.getCodigo());
		 if (cur != null) {
			 cur.setNome(cu.getNome());
			 cur.setInstrutor(cu.getInstrutor());
			 cursos.atualizar(cu);
		 }
	}

	public void cadastrar(Curso cur) {
		if (!cursos.existe(cur.getNome())) {
			cursos.inserir(cur);
		} else {
			InterfaceTextual.reportar_erro("Curso já cadastrado");
		}
	}

	public void descadastrar(String codigo) {
		cursos.remover(codigo);
	}

	public Curso procurar(String codigo) {
		return cursos.procurar(codigo);
	}

	public ListaCursos listaCursos() {

		Curso[] cursos = null;
		Curso curso = null;
		cursos = this.cursos.getCursos();
		int numeroCursos = this.cursos.getIndice();
		ListaCursos lc = new ListaCursos();
		for (int i = 0; i < numeroCursos; i++) {
			curso = cursos[i];
			lc.insert(curso);
		}
		return lc;

	}

}
