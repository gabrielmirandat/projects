package unbPOO.escola.aluno;
import unbPOO.escola.dados.aluno.RepositorioAlunos;
import unbPOO.escola.dados.aluno.RepositorioAlunosArray;
//classe de lista de alunos
public class ListaAlunos {
		// declara��o de atributos
		private RepositorioAlunos alunos;
		private int indiceLista;
			//construtor
		public ListaAlunos() {
			alunos = new RepositorioAlunosArray();
			indiceLista = 0;
		}
		//metodo para ver se h� pr�ximo na lista
		public boolean hasNext() {			
			return  (indiceLista < alunos.getIndice());
		}
		//m�todo para pegar o pr�ximo da lista
		public Aluno next () {
			Aluno a = alunos.getAlunos()[indiceLista];
			indiceLista = indiceLista + 1;
			return a;
		}
		//m�todo para inserir na lista
		public void insert (Aluno a) {
			alunos.inserir(a);			
		}
                //metodo para pegar o tamanho da lista
                public int getTamanhoLista() {
		return alunos.getIndice();
	}
}