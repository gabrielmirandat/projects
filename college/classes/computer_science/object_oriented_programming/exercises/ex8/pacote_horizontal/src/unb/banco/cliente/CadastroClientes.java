package unb.banco.cliente;

import unb.banco.dados.cliente.ClienteNaoExistenteException;
import unb.banco.dados.cliente.*;
import unb.banco.interfaceUsuario.*;


public class CadastroClientes {

	private RepositorioClientes clientes;

	public CadastroClientes(RepositorioClientes r) {
		this.clientes = r;
	}

	public void atualizar(Cliente c) throws ClienteNaoExistenteException {
		Cliente cli = clientes.procurar(c.getCpf());
		cli.setNome(c.getNome());
		clientes.atualizar(cli);

	}

	public void cadastrar(Cliente c) throws ClienteJaExistenteException {
		if (!clientes.existe(c.getCpf())) {
			clientes.inserir(c);
		} else throw new ClienteJaExistenteException(c.getCpf());
	}

	public void descadastrar(String n) throws ClienteNaoExistenteException {
		clientes.remover(n);
	}

	public Cliente procurar(String n) throws ClienteNaoExistenteException {
		return clientes.procurar(n);
	}

	public ListaClientes listaClientes() {

		Cliente[] clientes = null;
		Cliente cliente = null;
		clientes = this.clientes.getClientes();
		int numeroClientes = this.clientes.getIndice();
		ListaClientes lc = new ListaClientes();
		for (int i = 0; i < numeroClientes; i++) {
			cliente = clientes[i];
			lc.insert(cliente);
		}
		return lc;

	}

}
