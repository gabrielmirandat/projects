package unb.banco.conta;

import unb.banco.dados.conta.*;
import unb.banco.dados.conta.ContaNaoExistenteException;
import unb.banco.cliente.Cliente;

public class CadastroContas {

	private RepositorioContas contas;

	public CadastroContas(RepositorioContas r) {
		this.contas = r;
	}

	public void atualizar(Conta c) throws ContaNaoExistenteException {
		
		contas.atualizar(c);
	}

	public int cadastrar(Conta c) {
		int r = -1;
		if (!contas.existe(c.getNumero())) {
			contas.inserir(c);
			r = 1;
		}
		return r;

	}

	public void  creditar(String n, double v) throws ContaNaoExistenteException {
		Conta c = contas.procurar(n);
		c.creditar(v);
	}

	public  void debitar(String n, double v) throws SaldoInsuficienteException, ContaNaoExistenteException {
		Conta c = contas.procurar(n);
		c.debitar(v);
	}
	
	public void descadastrar(String n) throws ContaNaoExistenteException {
		 contas.remover(n);
	}

	public Conta procurar(String n) throws ContaNaoExistenteException {
		return contas.procurar(n);
	}

	public void transferir(String origem, String destino, double val) throws SaldoInsuficienteException, ContaNaoExistenteException {
		Conta conta_origem = contas.procurar(origem);
		Conta conta_destino = contas.procurar(destino);
		conta_origem.transferir(conta_destino, val);
	}

	public ListaContas listaContasCliente(String cpf) {
		Conta[]  contas = null;
		Conta conta = null;
		Cliente cliente = null;
		String cpf_aux = null;
		
		contas = this.contas.getContas();
		int numeroContas = this.contas.getIndice();
		// estamos assumino que um cliente pode ter mais de uma conta; neste caso, mostramos todas.
		ListaContas lc = new ListaContas();
		for (int i = 0; i < numeroContas; i++) {
			conta = contas[i];
			cliente = conta.getCliente();
			cpf_aux = cliente.getCpf();
			if (cpf_aux.equals(cpf)) {
				lc.insert(conta);
			}
		}
		return lc;
	}

	public ListaContas listaContas() {

		Conta[]  contas = null;
		Conta conta = null;
		contas = this.contas.getContas();
		int numeroContas = this.contas.getIndice();
		// estamos assumino que um cliente pode ter mais de uma conta; neste caso, mostramos todas.
		ListaContas lc = new ListaContas();
		for (int i = 0; i < numeroContas; i++) {
			conta = contas[i];
			lc.insert(conta);
		}
		return lc;
	}

	public void renderJuros(String numero, double taxa) throws ContaNaoExistenteException {
		Conta c = contas.procurar(numero);
		if (c instanceof Poupanca) {
			Poupanca p = ((Poupanca) c);
			p.renderJuros(taxa);
			contas.atualizar(p);
		}
		
	}

	public void renderBonus(String numero) throws ContaNaoExistenteException {
		Conta c = contas.procurar(numero);
		if (c instanceof ContaBonificada) {
			((ContaBonificada) c).renderBonus();
		}

	}

}
