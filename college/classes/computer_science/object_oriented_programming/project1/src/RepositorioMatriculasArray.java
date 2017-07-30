public class RepositorioMatriculasArray {
	private Matricula[]  matriculas;
	private int indice;
	private final static int tamanhoCache = 100;

	public RepositorioMatriculasArray() {
	  indice = 0;
	  matriculas = new Matricula[tamanhoCache];
	}

    public Matricula [] getMatriculas() {
        return matriculas;
	}

    public int getIndice() {
        return indice;
    }

   	public boolean existe(String nome_aluno, String nome_curso) {
		  boolean resp = false;

		  int i = this.procurarIndice(nome_aluno, nome_curso);
		  if(i != -1){
			resp = true;
		  }

		  return resp;
	}

   	public void inserir(Matricula c){
	    matriculas[indice] = c;
	    indice = indice + 1;
	}
	
    public Matricula procurar(String nome_aluno, String nome_curso){
		  Matricula c = null;
		  if (existe(nome_aluno, nome_curso)) {
	  	    int i = this.procurarIndice(nome_aluno, nome_curso);
		    c = matriculas[i];
		  } else {
		    InterfaceTextual.reportar_erro("Matricula nao encontrada.");
		  }
		  return c;
	}	
    
    private int procurarIndice(String nome_aluno, String nome_curso) {
	  int     i = 0;
	  int     ind = -1;
	  boolean achou = false;

	  while ((i < indice) &&!achou) {
	    if ((nome_aluno == null || (matriculas[i].getAluno().getNome()).equals(nome_aluno)) 
	    		&& (nome_curso==null || (matriculas[i].getCurso().getNome()).equals(nome_curso))) {
	    	ind = i;
	    	achou = true;
	    }
	    i = i + 1;
	  }
	  return ind;
	}

    public int remover(String nome_aluno, String nome_curso){
	  int r = -1;
	  if (existe(nome_aluno, nome_curso)) {
  	    int i = this.procurarIndice(nome_aluno, nome_curso);
	    matriculas[i] = matriculas[indice - 1];
	    matriculas[indice - 1] = null;
	    indice = indice - 1;
	    r = 1;
	  } 
	  return r;
	}
}
