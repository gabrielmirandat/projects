package unbPOO.escola.matricula;
import unbPOO.escola.dados.matricula.RepositorioMatriculasArray;

//classe de lista de matriculas
public class ListaMatriculas {
		// declaraçao de atributos
		private RepositorioMatriculasArray matriculas;
		private int indiceLista;
			//construtor
		public ListaMatriculas() {
			matriculas = new RepositorioMatriculasArray();
			indiceLista = 0;
		}
		//metodo para ver se há próximo na lista
		public boolean hasNext() {			
			return  indiceLista < matriculas.getIndice();
		}
		//método para pegar o próximo da lista
		public Matricula next () {
			Matricula m = matriculas.getMatriculas()[indiceLista];
			indiceLista = indiceLista + 1;
			return m;
		}
		//método para inserir na lista
		public void insert (Matricula m) {
			matriculas.inserir(m);			
		}
}
