package  unb.banco.conta;

import unb.banco.cliente.Cliente;
import unb.banco.dados.conta.ContaNaoExistenteException;
import unb.banco.dados.conta.RepositorioContas;

public class CadastroContas {

	private RepositorioContas contas;

	public CadastroContas(RepositorioContas r) {
		this.contas = r;
	}

	public void  creditar(String n, double v) throws ContaNaoExistenteException {
		Conta c = contas.procurar(n);
		c.creditar(v);
		contas.atualizar(c);
	}

	public  void debitar(String n, double v) throws SaldoInsuficienteException, ContaNaoExistenteException {
		Conta c = contas.procurar(n);
		c.debitar(v);
		contas.atualizar(c);
	}
	
	public void transferir(String origem, String destino, double val) throws SaldoInsuficienteException, ContaNaoExistenteException {
		Conta conta_origem = contas.procurar(origem);
		Conta conta_destino = contas.procurar(destino);
		conta_origem.transferir(conta_destino, val);
		contas.atualizar(conta_origem);
		contas.atualizar(conta_destino);
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
			ContaBonificada cb = (ContaBonificada) c;
			cb.renderBonus();
			contas.atualizar(cb);
		}

	}

	
	public void atualizar(Conta c) throws ContaNaoExistenteException {
		
		contas.atualizar(c);
	}

	public void cadastrar(Conta c) throws ContaJaExistenteException {
		if (!contas.existe(c.getNumero())) 
			contas.inserir(c);
		else throw new ContaJaExistenteException(c.getNumero());
	}


	public void descadastrar(String n) throws ContaNaoExistenteException {
		 contas.remover(n);
	}

	public Conta procurar(String n) throws ContaNaoExistenteException {
		return contas.procurar(n);
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

	
}
