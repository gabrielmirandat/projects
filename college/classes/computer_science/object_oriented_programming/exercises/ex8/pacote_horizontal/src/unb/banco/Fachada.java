package unb.banco;

import unb.banco.cliente.CadastroClientes;
import unb.banco.cliente.Cliente;
import unb.banco.cliente.ClienteJaExistenteException;
import unb.banco.cliente.ListaClientes;
import unb.banco.conta.CadastroContas;
import unb.banco.conta.Conta;
import unb.banco.conta.ContaJaExistenteException;
import unb.banco.conta.ListaContas;
import unb.banco.conta.SaldoInsuficienteException;
import unb.banco.dados.cliente.ClienteNaoExistenteException;
import unb.banco.dados.cliente.RepositorioClientes;
import unb.banco.dados.cliente.RepositorioClientesArray;
import unb.banco.dados.conta.ContaNaoExistenteException;
import unb.banco.dados.conta.RepositorioContas;
import unb.banco.dados.conta.RepositorioContasArray;
import unb.banco.conta.*;
import unb.banco.dados.cliente.*;
import unb.banco.dados.conta.*;

public class Fachada {

	private static Fachada instancia;
	private CadastroContas contas;
	private CadastroClientes clientes;

	public static Fachada obterInstancia() {
		if (instancia == null) {
			instancia = new Fachada();
		}
		return instancia;
	}

	private Fachada() {
		initCadastros();
	}

	private void initCadastros() {
		RepositorioContas rep = new RepositorioContasArray();
		contas = new CadastroContas(rep);
		RepositorioClientes repClientes = new RepositorioClientesArray();
		clientes = new CadastroClientes(repClientes);
	}

	// metodos para manipular clientes
	public void atualizar(Cliente c) throws ClienteNaoExistenteException {
		clientes.atualizar(c);
	}

	public Cliente procurarCliente(String cpf) throws ClienteNaoExistenteException {
		return clientes.procurar(cpf);
	}

	public void cadastrar(Cliente c) throws ClienteJaExistenteException {
		clientes.cadastrar(c);
	}

	public void descadastrarCliente(String cpf) throws ClienteNaoExistenteException {
		// descadastra primeiro as contas do cliente, pois nao faz sentido conta sem cliente
		// esta eh uma regra de negocio
		Conta conta = null;
		ListaContas lista_contas =  listaContasCliente(cpf);
		while (lista_contas.hasNext()) {
			conta = lista_contas.next();
			try {
				contas.descadastrar(conta.getNumero());
			} catch (ContaNaoExistenteException e) {
				// esta excecao nao deveria ser lancada porque sao contas do cliente
				// o catch eh usado para que a assinatura do metodo nao tenha que
				// declarar a excecao ContaNaoExistenteException 
			}
		}
		// agora sim, descadastra o cliente
		clientes.descadastrar(cpf);
	}

	// metodos para manipular contas
	public void atualizar(Conta c) throws ContaNaoExistenteException, ClienteNaoExistenteException {
		// pega a conta cadastrada com o numero informado pelo usuario
		Conta ct = contas.procurar(c.getNumero());
		// pega o cliente cadastrado com o cpf informado pelo usuario
		Cliente cli = clientes.procurar(c.getCliente().getCpf());
		// muda o cliente da conta com o cliente que tem o cpf informado pelo
		// usuario
		ct.setCliente(cli);

		// informa a mudanca ao cadastro: isto eh importante para fins de
		// consistencia do estado da conta
		// o cadastro eh responsavel por esta consistencia
		contas.atualizar(ct);
	}

	public Conta procurarConta(String n) throws ContaNaoExistenteException {
		return contas.procurar(n);
	}

	public void cadastrar(Conta c) throws ClienteNaoExistenteException, ContaJaExistenteException {
		Cliente cliente_lido, cliente_existente = null;
		cliente_lido = c.getCliente();
		if (cliente_lido != null) {
			cliente_existente = clientes.procurar(cliente_lido.getCpf());
			c.setCliente(cliente_existente);
			contas.cadastrar(c);
			 
		} 
		
	}

	public void descadastrarConta(String n) throws ContaNaoExistenteException {
		contas.descadastrar(n);
	}

	public void creditar(String n, double v) throws ContaNaoExistenteException {
		contas.creditar(n, v);
	}

	public void  debitar(String n, double v) throws SaldoInsuficienteException, ContaNaoExistenteException {
		 contas.debitar(n, v);
	}

	public void transferir(String origem, String destino, double val) throws SaldoInsuficienteException, ContaNaoExistenteException {
		 contas.transferir(origem, destino, val);
	}

	public ListaContas listaContasCliente(String cpf) throws ClienteNaoExistenteException {
		ListaContas lc = null;
		Cliente cliente = clientes.procurar(cpf);
		lc = contas.listaContasCliente(cpf);
		return lc;
	}

	public ListaContas listaContas() {

		return contas.listaContas();
		
	}

	public ListaClientes listaClientes() {
		// 
		return clientes.listaClientes();
	}

	public void renderJuros(String numero, double taxa) throws ContaNaoExistenteException {
		
		contas.renderJuros(numero, taxa);
	}

	public void renderBonus(String numero) throws ContaNaoExistenteException {
		
		contas.renderBonus(numero);
	}

}
