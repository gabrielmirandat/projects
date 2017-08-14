public class RepositorioCursosArray {
	private Curso[]  cursos;
	private int indice;
	private final static int tamanhoCache = 100;

	public RepositorioCursosArray() {
	  indice = 0;
	  cursos = new Curso[tamanhoCache];
	}
  
    public Curso [] getCursos () {
       return cursos;
    }

    public int getIndice() {
       return indice;
    }

	public void atualizar(Curso c){
	  int i = procurarIndice(c.getCodigo());
	  if (i != -1) {
	    cursos[i] = c;
	  } else {
		  InterfaceTextual.reportar_erro("Curso nao encontrado");
	  }
	}
	
	public boolean existe(String codigo) {
	  boolean resp = false;

	  int i = this.procurarIndice(codigo);
	  if(i != -1){
		resp = true;
	  }

	  return resp;
	}
	
	public void inserir(Curso c){
	    cursos[indice] = c;
	    indice = indice + 1;
	}
	
	public Curso procurar(String codigo){
		
	  Curso c = null;
	  if (existe(codigo)) {
  	    int i = this.procurarIndice(codigo);
	    c = cursos[i];
	  } else {
		  InterfaceTextual.reportar_erro("Curso nao encontrado");
	  }

	  return c;
	}

	private int procurarIndice(String codigo) {
	  int     i = 0;
	  int     ind = -1;
	  boolean achou = false;

	  while ((i < indice) &&!achou) {
	    if ((cursos[i].getCodigo()).equals(codigo)) {
		ind = i;
		achou = true;
	    }
	    i = i + 1;
	  }
	  return ind;
	}

	public void remover(String codigo){
	  if (existe(codigo)) {
  	    int i = this.procurarIndice(codigo);
	    cursos[i] = cursos[indice - 1];
	    cursos[indice - 1] = null;
	    indice = indice - 1;
	  } else {
		  InterfaceTextual.reportar_erro("Curso nao encontrado");
	  }
	}
}