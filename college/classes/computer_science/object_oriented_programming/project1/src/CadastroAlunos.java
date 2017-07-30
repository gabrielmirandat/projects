public class CadastroAlunos {

	private RepositorioAlunosArray alunos;

	public CadastroAlunos(RepositorioAlunosArray r) {
		this.alunos = r;
	}

	public void atualizar(Aluno al) {
		 Aluno alu = alunos.procurar(al.getNome());
		 if (alu != null) {
			 alu.setEndereco(al.getEndereco());
			 alu.setTelefone(al.getTelefone());
			 alu.setIdade(al.getIdade());
			 alunos.atualizar(al);
		 }else{
			 InterfaceTextual.reportar_erro("Aluno nao encontrado");
		 }
	}

	public void cadastrar(Aluno alu) {
		if (!alunos.existe(alu.getNome())) {
			alunos.inserir(alu);
		} else {
			InterfaceTextual.reportar_erro("Aluno já cadastrado");
		}
	}

	public void descadastrar(String nome) {
		alunos.remover(nome);
	}

	public Aluno procurar(String nome) {
		return alunos.procurar(nome);
	}

	public ListaAlunos listaAlunos() {

		Aluno[] alunos = null;
		Aluno aluno = null;
		alunos = this.alunos.getAlunos();
		int numeroAlunos = this.alunos.getIndice();
		ListaAlunos la = new ListaAlunos();
		for (int i = 0; i < numeroAlunos; i++) {
			aluno = alunos[i];
			la.insert(aluno);
		}
		return la;

	}

}
