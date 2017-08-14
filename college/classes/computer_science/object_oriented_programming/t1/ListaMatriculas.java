
public class ListaMatriculas {
	
	private RepositorioMatriculasArray matriculas;
	private int indice;
		
	public ListaMatriculas() {
		matriculas = new RepositorioMatriculasArray();
		setIndice(0);
	}
	
	public boolean hasNext() {
		
		return  getIndice() < matriculas.getIndice();
	}
	
	public Matricula next () {
		Matricula c = matriculas.getMatriculas()[getIndice()];
		setIndice(getIndice() + 1);
		return c;
	}
	
	public void insert (Matricula m) {
		matriculas.inserir(m);
		
	}

	public int getIndice() {
		return indice;
	}

	public void setIndice(int indice) {
		this.indice = indice;
	}

}
