package unbPOO.escola.dados.aluno;

import unbPOO.escola.dados.aluno.RepositorioAlunos;
import unbPOO.escola.aluno.Aluno;

//repositorio para a classe básica Aluno
public class RepositorioAlunosArray implements RepositorioAlunos{
    // declaracao de atributos
	private Aluno[]  alunos;
	private int indice;
        //atributo estatico para tamanho do vetor
	private final static int tamanhoCache = 100;
// construtor da classe
	public RepositorioAlunosArray() {
	  indice = 0;
	  alunos = new Aluno[tamanhoCache];
	}
  // metodos public para retornar atributos
     public Aluno [] getAlunos () {
       return alunos;
     }

     public int getIndice() {
       return indice;
     }
// metodos public a serem utilizados na coleção de negócio CadastroAlunos
	// metodo atualizar com parametro Aluno a
	public void atualizar(Aluno a) throws AlunoNaoExistenteException{
	  int i = procurarIndice(a.getNome());
	  
	    alunos[i] = a;
	  
	}
        
        // metodo existe que retorna se o aluno existe ou não dado o seu nome 
	public boolean existe(String nome) {
	  boolean resp = false;

	  try {
			this.procurarIndice(nome);
			resp = true;
		} catch (AlunoNaoExistenteException e) {
			resp = false;
		}

	  return resp;
	}
        // metodo inserir que coloca o Aluno a no vetor de cursos começando do indice 0 e incrementando-o
	public void inserir(Aluno a){
	    alunos[indice] = a;//coloca o aluno no vetor 
	    indice = indice + 1;// incrementa o indice de forma tal que "indice" é o último índice, ou o tamanho do vetor+1, já que começa de 0
	}
	//metodo procurar dado nome do aluno
        public Aluno procurar(String nome) throws AlunoNaoExistenteException{		
	  Aluno a = null;
	  
  	    int i = this.procurarIndice(nome);// i recebe o indice de tal aluno
	    a = alunos[i];//a recebe o aluno da iésima posição
	  
	  return a;
	}
//metodo private a ser utilizado nos metodos da propria classe/retorna indice do array dado nome do aluno
	public int procurarIndice(String nome) throws AlunoNaoExistenteException {
	  int     i = 0;
	  int     ind = -1;
	  boolean achou = false;

	  while ((i < indice) &&!achou) {//laco que percorre o vetor enquanto nao acha o aluno
	    if ((alunos[i].getNome()).equals(nome)) {// se o nome do aluno de i-esima posição tem mesmo conteudo que o parametro passado
		ind = i;
		achou = true;
	    }
	    i = i + 1;
	  }
          if (!achou)
			throw new AlunoNaoExistenteException(nome);
	  return ind;
	}
// metodo public para remover curso do vetor
	public void remover(String nome) throws AlunoNaoExistenteException{
	  
  	    int i = this.procurarIndice(nome);// i recebe o indice do curso
	    alunos[i] = alunos[indice - 1];// o local de memoria do aluno de (i+1)-esima posicao agora recebe o ultimo aluno
	    alunos[indice - 1] = null;// o ultimo aluno recebe null
	    indice = indice - 1;// o indice é decrementado
	  
	}
        
}