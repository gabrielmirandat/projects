package unbPOO.escola.aluno;

import unbPOO.escola.dados.aluno.AlunoNaoExistenteException;
import unbPOO.escola.dados.aluno.RepositorioAlunos;


// coleção de negócio para o repositório de alunos
public class CadastroAlunos {

    // declaracao de atributos
	private RepositorioAlunos alunos;
// construtor da classe
	public CadastroAlunos(RepositorioAlunos r) {
		this.alunos = r;
	}

        //metodos public a serem usados na fachada
        // metodo para atualizar Aluno
	public void atualizar(Aluno a) throws AlunoNaoExistenteException {//recebe como parametro o Aluno
		 Aluno alu = alunos.procurar(a.getNome());
		 
			 alu.setEndereco(a.getEndereco());
			 alu.setTelefone(a.getTelefone());
			 alu.setIdade(a.getIdade());
			 alunos.atualizar(alu);
		 
	}
        // metodo para cadastrar Aluno
	public void cadastrar(Aluno a) throws AlunoJaExistenteException {//recebe como parametro o aluno
		if (!alunos.existe(a.getNome())) {// se o aluno nao existe
			alunos.inserir(a);//insere no vetor
		} else {//se existe, ja foi cadastrado
			throw new AlunoJaExistenteException(a.getNome());
		}
	}
// metodo para descadastrar Aluno
	public void descadastrar(String n) throws AlunoNaoExistenteException {
		alunos.remover(n);
	}
// metodo para procurar Aluno
	public Aluno procurar(String n) throws AlunoNaoExistenteException {
		return alunos.procurar(n);
	}
// metodo que retorna a lista de alunos
	public ListaAlunos listaAlunos() {

		Aluno[] alunos = null; // cria vetor
		Aluno aluno = null;
		alunos = this.alunos.getAlunos();
		int numeroAlunos = this.alunos.getIndice();//pega o ultimo indice do vetor
		ListaAlunos la = new ListaAlunos();//construtor de lista
		for (int i = 0; i < numeroAlunos; i++) { // laço para inserir na lista os alunos do vetor
			aluno = alunos[i];
			la.insert(aluno);
		}
		return la;
        }

}