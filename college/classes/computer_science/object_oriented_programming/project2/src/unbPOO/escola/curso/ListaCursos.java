package unbPOO.escola.curso;
import unbPOO.escola.dados.curso.RepositorioCursos;
import unbPOO.escola.dados.curso.RepositorioCursosArray;

//classe de lista de cursos
public class ListaCursos {
		// declaração de atributos
		private RepositorioCursos cursos;
		private int indiceLista;	
                //construtor
		public ListaCursos() {
			cursos = new RepositorioCursosArray();
			indiceLista = 0;
		}	
                //metodo para ver se há próximo na lista
		public boolean hasNext() {			
			return  indiceLista < cursos.getIndice();
		}	
                //método para pegar o próximo da lista
		public Curso next () {
			Curso c = cursos.getCursos()[indiceLista];
			indiceLista = indiceLista + 1;
			return c;
		}
		//método para inserir na lista
		public void insert (Curso c) {
			cursos.inserir(c);
			
		}
                //metodo para pegar o tamanho da lista
                public int getTamanhoLista() {
		return cursos.getIndice();
	}
}