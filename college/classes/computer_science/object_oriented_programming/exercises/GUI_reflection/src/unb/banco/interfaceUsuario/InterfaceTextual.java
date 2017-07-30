package unb.banco.interfaceUsuario;

// Insira as linhas abaixo como primeiras linhas em seu programa de teste
// tais linhas garantem que posssamos referenciar as classes Scanner e Locale.
// Explicaremos como isto funciona mais para frente, na aula sobre pacotes.
import java.util.Scanner;
import java.util.Locale;

import unb.banco.Fachada;
import unb.banco.cliente.Cliente;
import unb.banco.cliente.ClienteJaExistenteException;
import unb.banco.cliente.ListaClientes;
import unb.banco.conta.Conta;
import unb.banco.conta.ContaBonificada;
import unb.banco.conta.ContaJaExistenteException;
import unb.banco.conta.ListaContas;
import unb.banco.conta.Poupanca;
import unb.banco.conta.SaldoInsuficienteException;
import unb.banco.dados.cliente.ClienteNaoExistenteException;
import unb.banco.dados.conta.ContaNaoExistenteException;

public class InterfaceTextual implements UI {

	private static Scanner sc;

	private static Fachada fachada;

	// as constantes abaixo tornam a interface e a logica da aplicacao mais
	// flexiveis.
	// alem disso as constantes sao mneumonicas
	private static final int OP_CRIAR_CLIENTE = 1;
	private static final int OP_CONSULTAR_CLIENTE = 2;
	private static final int OP_ATUALIZAR_CLIENTE = 3;
	private static final int OP_REMOVER_CLIENTE = 4;
	private static final int OP_CRIAR_CONTA = 5;
	private static final int OP_CONSULTAR_CONTA = 6;
	private static final int OP_ATUALIZAR_CONTA = 7;
	private static final int OP_REMOVER_CONTA = 8;
	private static final int OP_CREDITAR_CONTA = 9;
	private static final int OP_DEBITAR_CONTA = 10;
	private static final int OP_TRANSFERIR_CONTAS = 11;
	private static final int OP_RENDER_BONUS_CONTAS = 12;
	private static final int OP_RENDER_JUROS_CONTAS = 13;
	private static final int OP_EXIBIR_CONTAS_CLIENTE = 14;
	private static final int OP_EXIBIR_CONTAS = 15;
	private static final int OP_EXIBIR_CLIENTES = 16;
	private static final int OP_SAIR = 17;
	private static final int OP_INICIAL = -1;

	public InterfaceTextual () {
		
		init();
		int opcao = OP_INICIAL;
		do {
			imprime_tela();
			opcao = pega_opcao();
			try {
				trata_opcao(opcao);
			} catch (SaldoInsuficienteException e) {
				System.out.println(e.getMessage() + ". Saldo " + e.getSaldo() + " . Numero  "
						+ e.getNumero());
				System.out.println(e.getStackTrace()[0]);
			} catch (ClienteJaExistenteException e) {
				System.out.println(e.getMessage());
				System.out.println(e.getStackTrace()[0]);
			} catch (ContaNaoExistenteException e) {
				System.out.println(e.getMessage());
				System.out.println(e.getStackTrace()[0]);
			} catch (ClienteNaoExistenteException e) {
				System.out.println(e.getMessage());
				System.out.println(e.getStackTrace()[0]);
			} catch (ContaJaExistenteException e) {
				System.out.println(e.getMessage());
				System.out.println(e.getStackTrace()[0]);
			}
		} while (opcao != OP_SAIR);

	}

	public static void imprime_tela() {

		System.out.println(" ****************************");
		System.out.println(" *** Aplicacao bancaria *** ");
		System.out.println();
		System.out.println();
		System.out.println(" Operacoes disponiveis: ");
		System.out.println(OP_CRIAR_CLIENTE + "- Criar cliente ");
		System.out.println(OP_CONSULTAR_CLIENTE + "- Consultar cliente ");
		System.out.println(OP_ATUALIZAR_CLIENTE + "- Atualizar cliente ");
		System.out.println(OP_REMOVER_CLIENTE + "- Remover cliente ");
		System.out.println(OP_CRIAR_CONTA
				+ "- Criar conta (Conta, Poupanca, ou Conta Bonificada) ");
		System.out.println(OP_CONSULTAR_CONTA + "- Consultar conta ");
		System.out.println(OP_ATUALIZAR_CONTA + "- Atualizar conta ");
		System.out.println(OP_REMOVER_CONTA + "- Remover conta ");
		System.out.println(OP_CREDITAR_CONTA + "- Creditar em conta ");
		System.out.println(OP_DEBITAR_CONTA + "- Debitar de conta ");
		System.out.println(OP_TRANSFERIR_CONTAS + "- Transferir entre contas ");
		System.out.println(OP_RENDER_BONUS_CONTAS
				+ "- Render bonus sobre conta bonificada");
		System.out.println(OP_RENDER_JUROS_CONTAS
				+ "- Render juros sobre uma poupanca");

		System.out.println(OP_EXIBIR_CONTAS_CLIENTE
				+ "- Exibir os dados da conta de um determinado cliente ");
		System.out.println(OP_EXIBIR_CONTAS
				+ "- Exibir os dados de todas as contas ");
		System.out.println(OP_EXIBIR_CLIENTES
				+ "- Exibir os dados de todos os clientes ");
		System.out.println(OP_SAIR + "- Sair da aplicacao ");
		System.out.println();
		System.out.println(" Favor escolher uma opcao: ");

	}

	public static void init() {

		/*
		 * A classe Scanner ajuda a ler dados da entrada, represtentada pelo
		 * objeto System.in. A documentacao desta classe esta na URL abaixo:
		 * http
		 * ://download.oracle.com/javase/1.5.0/docs/api/java/util/Scanner.html
		 * inserir a linha abaixo
		 */

		sc = new Scanner(System.in);

		/*
		 * use a linha abaixo para garantir que valores em ponto flutuante sao
		 * lidos esperando-se um ponto e nao uma virgula para a parte decimal:
		 * por exemplo, sera esperado 2.3 e nao 2,3
		 */

		sc.useLocale(Locale.US);

		fachada = Fachada.obterInstancia();

	}

	public static int pega_opcao() {

		// pega a opcao escolhida pelo usuario
		int i = sc.nextInt();

		// pula o ENTER que o usuario digitou.
		sc.nextLine();

		return i;

	}

	public static void trata_opcao(int opcao)
			throws SaldoInsuficienteException, ContaNaoExistenteException,
			ClienteNaoExistenteException, ClienteJaExistenteException,
			ContaJaExistenteException {
		String nome, cpf, numero, origem, destino;
		nome = numero = cpf = origem = destino = null;
		int tipo;
		double valor = 0;
		Cliente cliente = null;
		Conta conta = null;
		ContaBonificada bonificada = null;
		ListaContas  lista_contas = null;

		switch (opcao) {

		case OP_CRIAR_CLIENTE:
			System.out.println("Favor entre nome do cliente e  tecle Enter:");
			nome = sc.nextLine();
			System.out.println("Favor entre CPF do cliente e  tecle Enter:");
			cpf = sc.nextLine();
			cliente = new Cliente(cpf, nome);
			fachada.cadastrar(cliente);
			break;

		case OP_CONSULTAR_CLIENTE:
			System.out.println("Favor entre CPF do cliente e tecle Enter:");
			cpf = sc.nextLine();
			cliente = fachada.procurarCliente(cpf);
			System.out.println("Nome do cliente: " + cliente.getNome());
			System.out.println("CPF do cliente: " + cliente.getCpf());
			break;

		case OP_ATUALIZAR_CLIENTE:
			System.out.println("Favor entre CPF do cliente e  tecle Enter:");
			cpf = sc.nextLine();
			System.out.println("Favor entre nome do cliente e  tecle Enter:");
			nome = sc.nextLine();
			cliente = new Cliente(cpf, nome);
			fachada.atualizar(cliente);
			break;

		case OP_REMOVER_CLIENTE:
			System.out.println("Favor entre CPF do cliente e  tecle Enter:");
			cpf = sc.nextLine();
			fachada.descadastrarCliente(cpf);
			break;

		case OP_CRIAR_CONTA:
			System.out.println("Favor entre o tipo da conta (1-Conta/2-Poupanca/3-Conta Bonificada) e tecle Enter:");
			tipo = sc.nextInt();
			sc.nextLine();
			if (tipo != 1 && tipo != 2 && tipo != 3) {
				System.out.println("Tipo de conta invalida");
			} else {
				System.out.println("Favor entre numero da conta e  tecle Enter:");
				numero = sc.nextLine();
				System.out.println("Favor entre CPF do cliente da conta e  tecle Enter:");
				cpf = sc.nextLine();
				cliente = new Cliente(cpf, null);
				switch (tipo) {
				case 1:
					conta = new Conta(numero, cliente);
					break;
				case 2:
					conta = new Poupanca(numero, cliente);
					break;
				case 3:
					conta = new ContaBonificada(numero, cliente);
					break;
				default:
				}
				
				fachada.cadastrar(conta);
				System.out.println(">> Conta cadastrada com sucesso:");
			}
			break;

		case OP_CONSULTAR_CONTA:
			System.out.println("Favor entre numero da conta e  tecle Enter:");
			numero = sc.nextLine();
			conta = fachada.procurarConta(numero);
			System.out.println("Numero da conta: " + conta.getNumero());
			System.out.println("Saldo da conta: " + conta.getSaldo());
			if (conta instanceof ContaBonificada) {
				bonificada = (ContaBonificada) conta;
				System.out.println("Bonus da conta: " + bonificada.getBonus());
			} else if (conta instanceof Poupanca) {
				System.out.println("OBS: A conta eh uma poupanca.");
			}
			cliente = conta.getCliente();
			System.out.println("Nome do cliente: " + cliente.getNome());
			System.out.println("CPF do cliente: " + cliente.getCpf());			
			break;
			
		case OP_ATUALIZAR_CONTA:
			System.out.println("Favor entre numero da conta e  tecle Enter:");
			numero = sc.nextLine();
			System.out.println("Favor entre CPF do cliente da conta e  tecle Enter:");
			cpf = sc.nextLine();
			cliente = new Cliente(cpf, null);
			// preserva o numero da conta e atualiza o cliente dela
			conta = new Conta(numero, cliente);
			fachada.atualizar(conta);
			System.out.println(">> Conta atualizada com sucesso:");
			break;

		case OP_REMOVER_CONTA:
			System.out.println("Favor entre numero da conta e  tecle Enter:");
			numero = sc.nextLine();
			fachada.descadastrarConta(numero);
			System.out.println(">> Conta removida com sucesso:");
			break;

		case OP_CREDITAR_CONTA:
			System.out.println("Favor entre numero da conta e  tecle Enter:");
			numero = sc.nextLine();
			System.out.println("Favor entre o valor a ser creditado e  tecle Enter:");
			valor = sc.nextDouble();
			fachada.creditar(numero, valor);
			System.out.println(">> creditar executado com sucesso:");
			break;

		case OP_DEBITAR_CONTA:
			System.out.println("Favor entre numero da conta e  tecle Enter:");
			numero = sc.nextLine();
			System.out.println("Favor entre o valor a ser debitado e  tecle Enter:");
			valor = sc.nextDouble();
			fachada.debitar(numero, valor);
			System.out.println(">> debitar executado com sucesso:");
			break;

		case OP_TRANSFERIR_CONTAS:
			System.out.println("Favor entre numero da conta origem e tecle Enter:");
			origem = sc.nextLine();
			System.out.println("Favor entre numero da conta destino e tecle Enter:");
			destino = sc.nextLine();
			System.out.println("Favor entre o valor a ser transferido e  tecle Enter:");
			valor = sc.nextDouble();
			fachada.transferir(origem, destino, valor);
			System.out.println(">> tranferir executado com sucesso:");
			break;

		case OP_RENDER_JUROS_CONTAS:
			System.out.println("Favor entre numero da conta e  tecle Enter:");
			numero = sc.nextLine();
			System.out.println("Favor entre o valor da taxa de juros e tecle Enter:");
			valor = sc.nextDouble();
			fachada.renderJuros(numero, valor);
			System.out.println(">> render juros executado com sucesso:");
			break;

		case OP_RENDER_BONUS_CONTAS:
			System.out.println("Favor entre numero da conta e  tecle Enter:");
			numero = sc.nextLine();
			fachada.renderBonus(numero);
			System.out.println(">> render bonus executado com sucesso:");
			break;

		case OP_EXIBIR_CONTAS_CLIENTE:
			System.out.println("Favor entre CPF do cliente e  tecle Enter:");
			cpf = sc.next();
			cliente = fachada.procurarCliente(cpf);
			System.out.println("Nome do cliente: " + cliente.getNome());
			System.out.println("CPF do cliente: " + cliente.getCpf());
			lista_contas= fachada.listaContasCliente(cpf);
			while (lista_contas.hasNext()) {
				conta = lista_contas.next();
				System.out.println("Numero da conta: " + conta.getNumero());
				System.out.println("Saldo da conta: " + conta.getSaldo());
				if (conta instanceof ContaBonificada) {
					bonificada = (ContaBonificada) conta;
					System.out.println("Bonus da conta: "
							+ bonificada.getBonus());
				} else if (conta instanceof Poupanca) {
					System.out.println("OBS: A conta eh uma poupanca.");
				}
			}
			break;

		case OP_EXIBIR_CONTAS:
			lista_contas = fachada.listaContas();
			System.out.println("---->>> DADOS DE TODAS AS CONTAS <<<-----");
			while (lista_contas.hasNext()) {
				conta = lista_contas.next();
				cliente = conta.getCliente();
				System.out.println("Numero da conta: " + conta.getNumero());
				System.out.println("Saldo da conta: " + conta.getSaldo());
				if (conta instanceof ContaBonificada) {
					bonificada = (ContaBonificada) conta;
					System.out.println("Bonus da conta: "
							+ bonificada.getBonus());
				} else if (conta instanceof Poupanca) {
					System.out.println("OBS: A conta eh uma poupanca.");
				}
				System.out.println("Nome do cliente desta conta: "
						+ cliente.getNome());
				System.out.println("CPF do cliente desta: " + cliente.getCpf());
				System.out.println("---------------------------------------------");
			}
			break;

		case OP_EXIBIR_CLIENTES:
			System.out.println("---->>> DADOS DE TODOS OS CLIENTES <<<-----");
			ListaClientes lista_clientes = fachada.listaClientes();
			while (lista_clientes.hasNext()) {
				cliente = lista_clientes.next();
				System.out.println("Nome do cliente: " + cliente.getNome());
				System.out.println("CPF do cliente: " + cliente.getCpf());
				System.out.println("---------------------------------------------");
			}
			break;

		case OP_SAIR:
			System.out.println("******OBRIGADO POR USAR A APLICACAO BANCARIA*******");
			break;

		default:
			System.out.println("Opcao invalida! Favor entrar uma opcao entre 1 e 15");

		}

	}

}