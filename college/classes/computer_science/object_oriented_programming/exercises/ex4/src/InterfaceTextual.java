// Insira as linhas abaixo como primeiras linhas em seu programa de teste
// tais linhas garantem que posssamos referenciar as classes Scanner e Locale.
// Explicaremos como isto funciona mais para frente, na aula sobre pacotes.
import java.util.Scanner;
import java.util.Locale;

public class InterfaceTextual {

	private static Scanner sc;
	private static RepositorioClientesArray repClientes;
	private static RepositorioContasArray repContas;
	
	// as constantes abaixo tornam a interface e a logica da aplicacao mais flexiveis.
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
	private static final int OP_EXIBIR_CONTAS_CLIENTE = 12;
	private static final int OP_EXIBIR_CONTAS = 13;
	private static final int OP_EXIBIR_CLIENTES = 14;
	private static final int OP_SAIR = 15;
	private static final int OP_INICIAL = -1;
	

	public static void main(String[] args) {

		init();
		int opcao = OP_INICIAL;
		do {
			imprime_tela();
			opcao = pega_opcao();
			trata_opcao(opcao);
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
		System.out.println(OP_CRIAR_CONTA + "- Criar conta ");
		System.out.println(OP_CONSULTAR_CONTA + "- Consultar conta ");
		System.out.println(OP_ATUALIZAR_CONTA + "- Atualizar conta ");
		System.out.println(OP_REMOVER_CONTA + "- Remover conta ");
		System.out.println(OP_CREDITAR_CONTA + "- Creditar em conta ");
		System.out.println(OP_DEBITAR_CONTA + "- Debitar de conta ");
		System.out.println(OP_TRANSFERIR_CONTAS + "- Transferir entre contas ");
		System.out.println(OP_EXIBIR_CONTAS_CLIENTE + "- Exibir os dados da conta de um determinado cliente ");
		System.out.println(OP_EXIBIR_CONTAS + "- Exibir os dados de todas as contas ");
		System.out.println(OP_EXIBIR_CLIENTES + "- Exibir os dados de todos os clientes ");
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

		repContas = new RepositorioContasArray();
		repClientes = new RepositorioClientesArray();

	}

	public static int pega_opcao() {

		int i = sc.nextInt();

		return i;

	}

	public static void trata_opcao(int opcao) {
		String nome, cpf, cpf_aux, numero, origem, destino;
		nome = numero = cpf = origem = destino = cpf_aux = null;
		Cliente cliente = null;
		Conta conta, c_origem, c_destino;
		conta = c_origem = c_destino = null;
		Conta[] contas = null;

		double valor = 0;

		switch (opcao) {

		case OP_CRIAR_CLIENTE:

			System.out.println("Favor entre nome do cliente e  tecle Enter:");
			nome = sc.nextLine();
			nome = sc.nextLine();
			System.out.println("Favor entre CPF do cliente e  tecle Enter:");
			cpf = sc.next();
			if (!repClientes.existe(cpf)) {
				cliente = new Cliente(cpf, nome);
				repClientes.inserir(cliente);
				System.out.println(">> Cliente inserido com sucesso:");
			} else {
				System.out.println("!!! Cliente ja existe!!!");
			}

			break;

		case OP_CONSULTAR_CLIENTE:
			System.out.println("Favor entre CPF do cliente e  tecle Enter:");
			cpf = sc.next();
			if (repClientes.existe(cpf)) {
				cliente = repClientes.procurar(cpf);
				System.out.println("Nome do cliente: " + cliente.getNome());
				System.out.println("CPF do cliente: " + cliente.getCpf());
			}
			else {
				System.out.println("!!!Cliente inexistente!!!");
			}


			break;

		case OP_ATUALIZAR_CLIENTE:

			System.out.println("Favor entre CPF do cliente e  tecle Enter:");
			cpf = sc.next();
			System.out.println("Favor entre nome do cliente e  tecle Enter:");
			nome = sc.nextLine();
			nome = sc.nextLine();
			if (repClientes.existe(cpf)) {
				cliente = new Cliente(cpf, nome);
				repClientes.atualizar(cliente);
				System.out.println(">> Cliente atualizado com sucesso:");
			}
			else {
				System.out.println("!!!Cliente inexistente!!!");
			}

			break;

		case OP_REMOVER_CLIENTE:

			System.out.println("Favor entre CPF do cliente e  tecle Enter:");
			cpf = sc.next();
			if (repClientes.existe(cpf)) {
			   repClientes.remover(cpf);
			   System.out.println(">> Cliente removido com sucesso:");
			} else {
				System.out.println("!!! Cliente inexistente!!!");
			}

			break;

		case OP_CRIAR_CONTA:

			System.out.println("Favor entre numero da conta e  tecle Enter:");
			numero = sc.next();
			if (! repContas.existe(numero)) {
				System.out.println("Favor entre CPF do cliente da conta e  tecle Enter:");
				cpf = sc.next();
				if (repClientes.existe(cpf)) {
					cliente = repClientes.procurar(cpf);
					conta = new Conta(numero, cliente);
					repContas.inserir(conta);
					System.out.println(">> Conta inserida com sucesso:");
				} else {
					System.out.println("CPF de cliente nao existente. Criacao de conta nao concluida");
				}
			} else {
				System.out.println("!!!Conta ja existe!!!");
			}
						
			break;

		case OP_CONSULTAR_CONTA:
			System.out.println("Favor entre numero da conta e  tecle Enter:");
			numero = sc.next();
			if (repContas.existe(numero)) {
				conta = repContas.procurar(numero);
				System.out.println("Numero da conta: " + conta.getNumero());
				System.out.println("Saldo da conta: " + conta.getSaldo());
				cliente = conta.getCliente();
				System.out.println("Nome do cliente: " + cliente.getNome());
				System.out.println("CPF do cliente: " + cliente.getCpf());
			} else {
				System.out.println("!!! Conta inexistente!!!");
			}

			break;

		case OP_ATUALIZAR_CONTA:

			System.out.println("Favor entre numero da conta e  tecle Enter:");
			numero = sc.next();
			if (repContas.existe(numero)) {
				System.out.println("Favor entre CPF do cliente da conta e  tecle Enter:");
				cpf = sc.next();
			    if (repClientes.existe(cpf)) {
					cliente = repClientes.procurar(cpf);
					// preserva o numero da conta e atualiza o cliente dela
					conta = new Conta(numero, cliente);
					repContas.atualizar(conta);
					System.out.println(">> Conta atualizada com sucesso:");
				} else {
					System.out.println("CPF de cliente nao existente. Atualizacao de conta nao concluida");
				}
			} else {
				System.out.println("!!! Conta inexistente!!!");
			}

			break;

		case OP_REMOVER_CONTA:

			System.out.println("Favor entre numero da conta e  tecle Enter:");
			numero = sc.next();
			if (repContas.existe(numero)) {
			   repContas.remover(numero);
			   System.out.println(">> Conta removida com sucesso:");
			} else {
				System.out.println("!!! Conta inexistente!!!");
			}

			break;

		case OP_CREDITAR_CONTA:
			System.out.println("Favor entre numero da conta e  tecle Enter:");
			numero = sc.next();
			System.out.println("Favor entre o valor a ser creditado e  tecle Enter:");
			valor = sc.nextDouble();
			if (repContas.existe(numero)) {
				conta = repContas.procurar(numero);
				conta.creditar(valor);
				System.out.println(">> Credito executado com sucesso:");
			} else {
				System.out.println("Conta nao existente. Operacao nao concluida");
			}

			break;

		case OP_DEBITAR_CONTA:
			System.out.println("Favor entre numero da conta e  tecle Enter:");
			numero = sc.next();
			System.out.println("Favor entre o valor a ser debitado e  tecle Enter:");
			valor = sc.nextDouble();
			if (repContas.existe(numero)) {
				conta = repContas.procurar(numero);
				conta.debitar(valor);
			} else {
				System.out.println("Conta nao existente. Operacao nao concluida");
			}

			break;

		case OP_TRANSFERIR_CONTAS:

			System.out.println("Favor entre numero da conta origem e tecle Enter:");
			origem = sc.next();
			System.out.println("Favor entre numero da conta destino e tecle Enter:");
			destino = sc.next();
			System.out.println("Favor entre o valor a ser transferido e  tecle Enter:");
			valor = sc.nextDouble();
			if (repContas.existe(origem) && repContas.existe(destino)) {
				c_origem = repContas.procurar(origem);
				c_destino = repContas.procurar(destino);
				c_origem.transferir(c_destino, valor);
			} else {
				System.out.println(" Alguma conta nao existente. Operacao nao concluida");
			}

			break;

		case OP_EXIBIR_CONTAS_CLIENTE:
			System.out.println("Favor entre CPF do cliente e  tecle Enter:");
			cpf = sc.next();
			if (repClientes.existe(cpf)) {
				cliente = repClientes.procurar(cpf);
				System.out.println("Nome do cliente: " + cliente.getNome());
				System.out.println("CPF do cliente: " + cliente.getCpf());
				contas = repContas.getContas();
				int numeroContas = repContas.getIndice();
				// estamos assumino que um cliente pode ter mais de uma conta; neste caso, mostramos todas.
				for (int i = 0; i < numeroContas; i++) {
					conta = contas[i];
					cliente = conta.getCliente();
					cpf_aux = cliente.getCpf();
					if (cpf_aux.equals(cpf)) {
						System.out.println("Numero da conta: " + conta.getNumero());
						System.out.println("Saldo da conta: " + conta.getSaldo());
					}
				}

			} else {
				System.out.println("!!!Cliente inexistente!!!");
			}

			break;

		case OP_EXIBIR_CONTAS:
			Conta[] arr_conta = repContas.getContas();
			int n_arr_conta = repContas.getIndice();
			for (int i = 0; i < n_arr_conta; i++) {
				conta = arr_conta[i];
				System.out.println("Numero da conta: " + conta.getNumero());
				System.out.println("Saldo da conta: " + conta.getSaldo());
				cliente = conta.getCliente();
				System.out.println("Nome do cliente: " + cliente.getNome());
				System.out.println("CPF do cliente: " + cliente.getCpf());
			}

			break;

		case OP_EXIBIR_CLIENTES:
			Cliente[] arr_cli = repClientes.getClientes();
			int n_arr_cli = repClientes.getIndice();
			for (int i = 0; i < n_arr_cli; i++) {
				cliente = arr_cli[i];
				System.out.println("Nome do cliente: " + cliente.getNome());
				System.out.println("CPF do cliente: " + cliente.getCpf());
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