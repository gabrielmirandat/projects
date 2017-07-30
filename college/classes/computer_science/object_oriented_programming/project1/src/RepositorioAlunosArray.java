public class RepositorioAlunosArray {
	private Aluno[]  alunos;
	private int indice;
	private final static int tamanhoCache = 100;

	public RepositorioAlunosArray() {
	  indice = 0;
	  alunos = new Aluno[tamanhoCache];
	}
  
    public Aluno [] getAlunos () {
       return alunos;
    }

    public int getIndice() {
       return indice;
    }

	public void atualizar(Aluno c){
	  int i = procurarIndice(c.getNome());
	  if (i != -1) {
	    alunos[i] = c;
	  } else {
		  InterfaceTextual.reportar_erro("Aluno nao encontrado");
	  }
	}
	
	public boolean existe(String nome) {
	  boolean resp = false;

	  int i = this.procurarIndice(nome);
	  if(i != -1){
		resp = true;
	  }

	  return resp;
	}
	
	public void inserir(Aluno c){
	    alunos[indice] = c;
	    indice = indice + 1;
	}
	
	public Aluno procurar(String nome){
		
	  Aluno c = null;
	  if (existe(nome)) {
  	    int i = this.procurarIndice(nome);
	    c = alunos[i];
	  } else {
		  InterfaceTextual.reportar_erro("Aluno nao encontrado");
	  }

	  return c;
	}

	private int procurarIndice(String nome) {
	  int     i = 0;
	  int     ind = -1;
	  boolean achou = false;

	  while ((i < indice) &&!achou) {
	    if ((alunos[i].getNome()).equals(nome)) {
		ind = i;
		achou = true;
	    }
	    i = i + 1;
	  }
	  return ind;
	}

	public void remover(String nome){
	  if (existe(nome)) {
  	    int i = this.procurarIndice(nome);
	    alunos[i] = alunos[indice - 1];
	    alunos[indice - 1] = null;
	    indice = indice - 1;
	  } else {
		  InterfaceTextual.reportar_erro("aluno nao encontrado");
	  }
	}
}
