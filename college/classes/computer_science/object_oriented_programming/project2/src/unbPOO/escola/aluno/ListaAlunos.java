package unbPOO.escola.aluno;
import unbPOO.escola.dados.aluno.RepositorioAlunos;
import unbPOO.escola.dados.aluno.RepositorioAlunosArray;
//classe de lista de alunos
public class ListaAlunos {
		// declaração de atributos
		private RepositorioAlunos alunos;
		private int indiceLista;
			//construtor
		public ListaAlunos() {
			alunos = new RepositorioAlunosArray();
			indiceLista = 0;
		}
		//metodo para ver se há próximo na lista
		public boolean hasNext() {			
			return  (indiceLista < alunos.getIndice());
		}
		//método para pegar o próximo da lista
		public Aluno next () {
			Aluno a = alunos.getAlunos()[indiceLista];
			indiceLista = indiceLista + 1;
			return a;
		}
		//método para inserir na lista
		public void insert (Aluno a) {
			alunos.inserir(a);			
		}
                //metodo para pegar o tamanho da lista
                public int getTamanhoLista() {
		return alunos.getIndice();
	}
}