package unb.banco.conta;

import unb.banco.dados.conta.*;
import unb.banco.cliente.Cliente;

public class CadastroContas {

	private RepositorioContas contas;

	public CadastroContas(RepositorioContas r) {
		this.contas = r;
	}

	public int atualizar(Conta c) {
		
		return contas.atualizar(c);
	}

	public int cadastrar(Conta c) {
		int r = -1;
		if (!contas.existe(c.getNumero())) {
			contas.inserir(c);
			r = 1;
		}
		return r;

	}

	public int creditar(String n, double v) {
		int r = -1;
		Conta c = contas.procurar(n);
		if (c != null) {
			c.creditar(v);
			r = 1;
		}
		return r;
	}

	public int debitar(String n, double v) {
		int r = -1;
		Conta c = contas.procurar(n);
		if (c != null) {
			r = c.debitar(v);
			r = 1;
		}
		return r;
	}

	public int descadastrar(String n) {
		return contas.remover(n);
	}

	public Conta procurar(String n) {
		return contas.procurar(n);
	}

	public int transferir(String origem, String destino, double val) {
		int r = -1;
		Conta conta_origem = contas.procurar(origem);
		Conta conta_destino = contas.procurar(destino);
		if (conta_origem != null && conta_destino != null) {
			r = conta_origem.transferir(conta_destino, val);
		}
		return r;
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

	public int renderJuros(String numero, double taxa) {
		int r = -1;
		Conta c = contas.procurar(numero);
		if (c != null) {
			if (c instanceof Poupanca) {
				Poupanca p = ((Poupanca) c);
				p.renderJuros(taxa);
				contas.atualizar(p);
				r = 1;
			}
		}
		return r;
		
		
	}

	public int renderBonus(String numero) {
		
		int r = -1;
		Conta c = contas.procurar(numero);
		if (c != null) {
			if (c instanceof ContaBonificada) {
				((ContaBonificada) c).renderBonus();
				r = 1;
			}
		}
		return r;
		
		
	}

}
