package unbPOO.escola.dados.curso;

import unbPOO.escola.dados.curso.RepositorioCursos;
import unbPOO.escola.curso.Curso;


//repositorio para a classe básica Curso
public class RepositorioCursosArray implements RepositorioCursos{
     // declaracao de atributos    
	private Curso[]  cursos;
	private int indice;
        //atributo estatico para tamanho do vetor
	private final static int tamanhoCache = 100;
        // construtor da classe
	public RepositorioCursosArray() {
	  indice = 0;
	  cursos = new Curso[tamanhoCache];
	}
  // metodos public para retornar atributos
     public Curso [] getCursos () {
       return cursos;
     }

     public int getIndice() {
       return indice;
     }

     // metodos public a serem utilizados na coleção de negócio CadastroCursos
	// metodo atualizar com parametro curso c
     public void atualizar(Curso c) throws CursoNaoExistenteException{
	  int i = procurarIndice(c.getCodigo());
	  
	    cursos[i] = c;
	  
	}
      // metodo existe que retorna se o curso exite ou não dado o seu codigo 
	public boolean existe(String codigo) {
	  boolean resp = false;

	  try {
			this.procurarIndice(codigo);
			resp = true;
		} catch (CursoNaoExistenteException e) {
			resp = false;
		}

	  return resp;
	}
        // metodo inserir que coloca o Curso c no vetor de cursos começando do indice 0 e incrementando-o
	public void inserir(Curso c){
	    cursos[indice] = c; // coloca o Curso c no vetor
	    indice = indice + 1; // incrementa o indice de forma tal que "indice" é o último índice, ou o tamanho do vetor+1, já que começa de 0
	}
	
        //metodo procurar dado codigo do curso
	public Curso procurar(String codigo) throws CursoNaoExistenteException{		
	  Curso c = null;
	  
  	    int i = this.procurarIndice(codigo);// i é o indice de tal curso
	    c = cursos[i]; // c recebe o curso da i-esima posição
	  
	  return c; // retorna o curso
	}

        //metodo private a ser utilizado nos metodos da propria classe/retorna indice do array dado codigo do curso
	public int procurarIndice(String codigo) throws CursoNaoExistenteException {
	  int     i = 0;
	  int     ind = -1;
	  boolean achou = false;

	  while ((i < indice) && !achou) { //laço que percorre o vetor enquanto não acha o curso
	    if ((cursos[i].getCodigo()).equals(codigo)) { // se o codigo de i-esima posiço tem mesmo conteudo que o parametro passado
		ind = i;
		achou = true;
	    }
	    i = i + 1;
	  }
          if (!achou)
			throw new CursoNaoExistenteException(codigo);
	  return ind;
	}
// metodo public para remover curso do vetor
	public void remover(String codigo) throws CursoNaoExistenteException{
	  
  	    int i = this.procurarIndice(codigo); // i recebe o indice do curso 
	    cursos[i] = cursos[indice - 1];// o local de memoria do curso de (i+1)-esima posicao agora recebe o ultimo curso
	    cursos[indice - 1] = null;// o ultimo curso recebe null
	    indice = indice - 1;// o indice é decrementado
	  
	}
}