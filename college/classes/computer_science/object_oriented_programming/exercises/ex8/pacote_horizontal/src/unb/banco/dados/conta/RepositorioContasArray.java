package unb.banco.dados.conta;

import unb.banco.conta.Conta;
import unb.banco.interfaceUsuario.*;

public class RepositorioContasArray implements RepositorioContas{
	private Conta[]  contas;
	private int indice;
	private final static int tamanhoCache = 100;

	public RepositorioContasArray() {
	  indice = 0;
	  contas = new Conta[tamanhoCache];
	}

    public Conta [] getContas() {
        return contas;
	}

    public int getIndice() {
        return indice;
    }
    public void inserir(Conta c){
	    contas[indice] = c;
	    indice = indice + 1;
	}

	private int procurarIndice(String num) throws ContaNaoExistenteException {
	  int     i = 0;
	  int     ind = -1;
	  boolean achou = false;

	  while ((i < indice) &&!achou) {
	    if ((contas[i].getNumero()).equals(num)) {
		ind = i;
		achou = true;
	    }
	    i = i + 1;
	  }
	  if (!achou)
		  throw new ContaNaoExistenteException(num);
	  return ind;
	}

	public boolean existe(String num) {
		boolean resp = false;

		try {
			this.procurarIndice(num);
			resp = true;
		} catch (ContaNaoExistenteException e) {
			resp = false;
		}

		return resp;
	}

	public void atualizar(Conta c) throws ContaNaoExistenteException {
		int i = procurarIndice(c.getNumero());
		contas[i] = c;
	}

	public Conta procurar(String num) throws ContaNaoExistenteException {
		Conta c = null;
		int i = this.procurarIndice(num);
		c = contas[i];
		return c;
	}

	public void remover(String num) throws ContaNaoExistenteException {
  	    int i = this.procurarIndice(num);
	    contas[i] = contas[indice - 1];
	    contas[indice - 1] = null;
	    indice = indice - 1;
	}
}
