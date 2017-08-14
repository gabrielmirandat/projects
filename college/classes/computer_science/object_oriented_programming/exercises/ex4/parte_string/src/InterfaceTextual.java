import java.util.Scanner;
import java.util.Locale;

public class InterfaceTextual {
	private static Scanner sc;
	private static RepositorioClientesArray repClientes;
	private static RepositorioContasArray   repContas;


	public static void main (String [] args) {
		init();
		int opcao = -1;
		do {
			imprime_tela();
			opcao = pega_opcao();
			trata_opcao(opcao);
		} while (opcao != 15);

	}



	public static void imprime_tela() {
		System.out.println(" *** Aplicacao bancaria *** ");
		System.out.println();
		System.out.println();
		System.out.println(" Operacoes disponiveis: ");
		System.out.println(" 1- Criar cliente ");
		System.out.println(" 2- Consultar cliente ");
		System.out.println(" 3- Atualizar cliente ");
		System.out.println(" 4- Remover cliente ");
		System.out.println(" 5- Criar conta ");
		System.out.println(" 6- Consultar conta ");
		System.out.println(" 7- Atualizar conta ");
		System.out.println(" 8- Remover conta ");
		System.out.println(" 9- Creditar em conta ");
		System.out.println(" 10- Debitar de conta ");
		System.out.println(" 11- Transferir entre contas ");
		System.out.println(" 12- Exibir os dados da conta de um determinado cliente ");
		System.out.println(" 13- Exibir os dados de todas as contas ");
		System.out.println(" 14- Exibir os dados de todos os clientes ");
		System.out.println(" 15- Sair da aplicacao ");
		System.out.println();
		System.out.println(" Favor escolher uma opcao: ");

   }


	public static void init () {
		sc = new Scanner(System.in);

		/* use a linha abaixo para garantir que valores em ponto flutuante sao lidos esperando-se
		um ponto e nao uma virgula para a parte decimal:
		por exemplo, sera esperado 2.3 e nao 2,3
		*/

       sc.useLocale(Locale.US);

       repContas   = new RepositorioContasArray ();
       repClientes = new RepositorioClientesArray();

	}


	public static int pega_opcao() {
		int i = sc.nextInt();
		return i;

	}



	public static void  trata_opcao (int opcao)  {
		String nome, cpf, numero, origem, destino;
		nome = numero = cpf = origem = destino = null;
		Cliente cliente = null;
		Conta conta, c_origem, c_destino;
		conta = c_origem = c_destino  = null;
		int ind;
		boolean ok=false;

		double valor = 0;


		switch (opcao) {
			case 1 :
				System.out.println ("Favor entre nome do cliente e  tecle Enter:");
		        nome = sc.nextLine();
		        nome = sc.nextLine();
		        System.out.println ("***read nome: " + nome);
		        System.out.println ("Favor entre CPF do cliente e  tecle Enter:");
		        cpf = sc.next();
		        System.out.println ("***read cpf: " + cpf);
		        cliente = new Cliente (cpf, nome);
		        repClientes.inserir(cliente);
		        System.out.println ("Cliente inserido com sucesso:");
		        break;
			case 2:
		        System.out.println ("Favor entre CPF do cliente e  tecle Enter:");
		        cpf = sc.next();
			    System.out.println ("***read cpf: " + cpf);
		        cliente = repClientes.procurar(cpf);
		        if (cliente != null) {
		              System.out.println("Nome do cliente: " + cliente.getNome());
		              System.out.println("CPF do cliente: "  + cliente.getCpf());
		        }
		        break;
			case 3:
				System.out.println ("Favor entre CPF do cliente e  tecle Enter:");
		        cpf = sc.next();
		        System.out.println ("***read cpf: " + cpf);
		        System.out.println ("Favor entre nome do cliente e  tecle Enter:");
		        nome = sc.nextLine();
		        nome = sc.nextLine();
		        cliente = repClientes.procurar(cpf);
		        if (cliente != null) {
		           cliente = new Cliente (cpf, nome);
		           repClientes.atualizar(cliente);

		        }
		        break;
		    case 4:
		    	System.out.println ("Favor entre CPF do cliente e  tecle Enter:");
		        cpf = sc.next();
		        repClientes.remover(cpf);
		        break;

		    case 5:
		    	System.out.println ("Favor entre numero da conta e  tecle Enter:");
		        numero = sc.next();
		        //numero = sc.nextLine();
		        System.out.println ("***read numero: " + numero);
		        System.out.println ("Favor entre CPF do cliente da conta e  tecle Enter:");
		        cpf = sc.next();
		        System.out.println ("***read cpf: " + cpf);
		        if (repClientes.existe(cpf)) {
		           cliente  = repClientes.procurar(cpf);
		           conta = new Conta (numero, cliente);
		           repContas.inserir(conta);
		           System.out.println ("Conta inserida com sucesso:");
		        }else {
		            System.out.println ("CPF de cliente nao existente. Criacao de conta nao concluida");
				}
		        break;

		    case 6:
		        System.out.println ("Favor entre numero da conta e  tecle Enter:");
		        numero = sc.next();
		        if(repContas.existe(numero)){
		        	conta = repContas.procurar(numero);
		        	System.out.println("----Conta numero: "+conta.getNumero()+"----");
		        	System.out.println("saldo: "+conta.getNumero());
		        	System.out.println("nome: "+conta.getCliente().getNome());
		        	System.out.println("cpf: "+conta.getCliente().getCpf());
		        }else{
		        	System.out.println("--Conta nao existente.---");
		        }
		        break;

		    case 7:
		        System.out.println ("Favor entre numero da conta e  tecle Enter:");
		        numero = sc.next();
		        System.out.println ("***read numero: " + numero);
		        System.out.println ("Favor entre CPF do cliente e  tecle Enter:");
		        cpf = sc.next();
		        System.out.println ("***read cpf: " + cpf);
		        System.out.println ("Favor entre nome do cliente e  tecle Enter:");
		        nome = sc.nextLine();
		        nome = sc.nextLine();
		        if(repContas.existe(numero)){
		        	cliente = new Cliente (cpf, nome);
		        	conta = new Conta(numero,cliente);
		        	repContas.atualizar(conta);
		        }
		        break;

		    case 8:
		        System.out.println ("Favor entre numero da conta e  tecle Enter:");
		        numero = sc.next();
		        repContas.remover(numero);
		        break;

		    case 9:
		        System.out.println ("Favor entre numero da conta e  tecle Enter:");
		        numero = sc.next();
		        //numero = sc.nextLine();
		        System.out.println ("***read numero: " + numero);
		        System.out.println ("Favor entre o valor a ser creditado e  tecle Enter:");
		        valor = sc.nextDouble();
		        if (repContas.existe(numero)) {
		           conta = repContas.procurar(numero);
		           conta.creditar(valor);
		        }
		        else {
		           System.out.println ("Conta nao existente. Operacao nao concluida");
			    }
		        break;

		    case 10 :
		        System.out.println ("Favor entre numero da conta e  tecle Enter:");
		        numero = sc.next();
		        //numero = sc.nextLine();
		        System.out.println ("***read numero: " + numero);
		        System.out.println ("Favor entre o valor a ser debitado e  tecle Enter:");
		        valor = sc.nextDouble();
		        if (repContas.existe(numero)) {
		           conta = repContas.procurar(numero);
		           conta.debitar(valor);
		        }
		        else {
		           System.out.println ("Conta nao existente. Operacao nao concluida");
			    }
		        break;

		    case 11:
		    	System.out.println ("Favor entre numero da conta origem e tecle Enter:");
		        origem = sc.next();
		        // origem = sc.nextLine();
		        System.out.println ("***read numero: " + origem);
		        System.out.println ("Favor entre numero da conta destino e tecle Enter:");
		        destino = sc.next();
		        // destino = sc.nextLine();
		        System.out.println ("***read numero: " + destino);
		        System.out.println ("Favor entre o valor a ser transferido e  tecle Enter:");
		        valor = sc.nextDouble();
		        if (repContas.existe(origem) && repContas.existe(destino)) {
		           c_origem  = repContas.procurar(origem);
		           c_destino = repContas.procurar(destino);
		           c_origem.transferir(c_destino,valor);
		        }
		        else {
		           System.out.println (" Alguma conta nao existente. Operacao nao concluida");
			    }
		        break;

		    case 12:
		        System.out.println ("Favor entre CPF do cliente e  tecle Enter:");
		        cpf = sc.next();
		        System.out.println ("***read cpf: " + cpf);
		        Conta[] contas = repContas.getContas();
		        ind = repContas.getIndice();
		        if(ind==0){
		        	System.out.println("---Ainda nao ha contas cadastradas.---");
		        	break;
		        }
		        ok = repClientes.existe(cpf);
		        if(ok!=false){
		        	ind = repContas.getIndice();
		        	while(ind>0){
		        		if(contas[ind-1].getCliente().getCpf().equals(cpf)){
		        			System.out.println("conta:"+ contas[ind-1].getNumero());
		        			System.out.println("saldo:"+ contas[ind-1].getSaldo()+"\n");
		        			ok = true;
		        		}
		        		ind--;
		        	}
		        }else{
		        	System.out.println("---Cliente nao cadastrado ou nao possui conta.---");
		        }
		        break;

		    case 13:
		       Conta [] arr_conta = repContas.getContas();
		       int n_arr_conta = repContas.getIndice();
		       for (int i = 0; i < n_arr_conta ; i++) {
		          conta = arr_conta[i];
		          System.out.println("Numero da conta: " + conta.getNumero());
		          System.out.println("Saldo da conta: "  + conta.getSaldo ());
		          cliente = conta.getCliente();
		          System.out.println("Nome do cliente: " + cliente.getNome());
		          System.out.println("CPF do cliente: "  + cliente.getCpf());
		       }
		       break;

		    case 14:
		       Cliente [] arr_cli = repClientes.getClientes();
		       int n_arr_cli = repClientes.getIndice();
		       for (int i = 0; i < n_arr_cli ; i++) {
		          cliente = arr_cli[i];
		          System.out.println("Nome do cliente: " + cliente.getNome());
		          System.out.println("CPF do cliente: "  + cliente.getCpf());
		       }
		       break;

		    case 15 :
		       break;


		    default: System.out.println ("Opcao invalida! Favor entrar uma opcao entre 1 e 15");

		}
	}
}
