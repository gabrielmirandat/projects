package unbPOO.escola.curso;
import unbPOO.escola.dados.curso.RepositorioCursos;
import unbPOO.escola.dados.curso.RepositorioCursosArray;

//classe de lista de cursos
public class ListaCursos {
		// declara��o de atributos
		private RepositorioCursos cursos;
		private int indiceLista;	
                //construtor
		public ListaCursos() {
			cursos = new RepositorioCursosArray();
			indiceLista = 0;
		}	
                //metodo para ver se h� pr�ximo na lista
		public boolean hasNext() {			
			return  indiceLista < cursos.getIndice();
		}	
                //m�todo para pegar o pr�ximo da lista
		public Curso next () {
			Curso c = cursos.getCursos()[indiceLista];
			indiceLista = indiceLista + 1;
			return c;
		}
		//m�todo para inserir na lista
		public void insert (Curso c) {
			cursos.inserir(c);
			
		}
                //metodo para pegar o tamanho da lista
                public int getTamanhoLista() {
		return cursos.getIndice();
	}
}