package unbPOO.escola.dados.matricula;

import unbPOO.escola.dados.matricula.RepositorioMatriculas;
import unbPOO.escola.matricula.Matricula;

//repositorio para a classe básica Matricula
public class RepositorioMatriculasArray implements RepositorioMatriculas{
    // declaracao de atributos 
	private Matricula[] matriculas;
	private int indice;
        //atributo estatico para tamanho do vetor
	private final static int tamanhoCache = 100;
// construtor da classe
	public RepositorioMatriculasArray() {
	  indice = 0;
	  matriculas = new Matricula[tamanhoCache];
	}
// metodos public para retornar atributos
    public Matricula [] getMatriculas() {
        return matriculas;
	}

    public int getIndice() {
        return indice;
    }
    
    // metodos public a serem utilizados na coleçao de negócio CadastroMatriculas
	// metodo atualizar com parametro Matricula m
    public void inserir(Matricula m){
	    matriculas[indice] = m;
	    indice = indice + 1;
	}
 //metodo private a ser utilizado nos metodos da propria classe/retorna indice do array dado codigo do curso
	public int procurarIndice(String nomeAluno, String codigoCurso) throws MatriculaNaoExistenteException{
	  int     i = 0;
	  int     ind = -1;
	  boolean achou = false;

	  while ((i < indice) &&!achou) {
	    if ((((matriculas[i].getAluno()).getNome()).equals(nomeAluno)) && (((matriculas[i].getCurso()).getCodigo()).equals(codigoCurso))) {
		ind = i;
		achou = true;
	    }
	    i = i + 1;
	  }
          if (!achou)
			throw new MatriculaNaoExistenteException(nomeAluno, codigoCurso);
	  return ind;
	}

// metodo existe que retorna se a matricula exite ou não dado o seu codigo de curso e nome do aluno 
	public boolean existe(String nomeAluno, String codigoCurso) {
	  boolean resp = false;

	  try {
			this.procurarIndice(nomeAluno, codigoCurso);
			resp = true;
		} catch (MatriculaNaoExistenteException e) {
			resp = false;
		}

	  return resp;
	}

// metodo atualizar
	public void atualizar(Matricula m) throws MatriculaNaoExistenteException{
	  
	  int i = procurarIndice(((m.getAluno()).getNome()), ((m.getCurso()).getCodigo()));
	  
	    matriculas[i] = m; 
	    
	}

// metodo procurar dado nome do aluno e codigo do curso
	public Matricula procurar(String nomeAluno, String codigoCurso) throws MatriculaNaoExistenteException{
	  Matricula m = null;
	  
  	    int i = this.procurarIndice(nomeAluno, codigoCurso); // i recebe o indice
	    m = matriculas[i]; // m recebe a i-esima matricula
	  
	  return m;
	}

	// metodo remover dado nome do aluno e codigo do curso
	public void remover(String nomeAluno, String codigoCurso) throws MatriculaNaoExistenteException{
	  
  	    int i = this.procurarIndice(nomeAluno, codigoCurso); // i recebe o indice
	    matriculas[i] = matriculas[indice - 1];//o local de memoria da matricula de (i+1)-ésima posiçao recebe a matricula de ultima posiçao
	    matriculas[indice - 1] = null;// a ultima matricula recebe null
	    indice = indice - 1;// o indice é decrementado e o vetor diminui
	    
	}

	
}
