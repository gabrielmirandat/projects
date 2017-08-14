package unb.banco.conta;
import unb.banco.dados.conta.RepositorioContas;
import unb.banco.dados.conta.RepositorioContasArray;


public class ListaContas {
	
	private RepositorioContas contas;
	private int indice;
		
	public ListaContas() {
		contas = new RepositorioContasArray();
		indice = 0;
	}
	
	public boolean hasNext() {
		
		return  indice < contas.getIndice();
	}
	
	public Conta next () {
		Conta c = contas.getContas()[indice];
		indice = indice + 1;
		return c;
	}
	
	public void insert (Conta c) {
		contas.inserir(c);
		
	}

}
