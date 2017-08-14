package unb.banco.interfaceUsuario;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Choice;
import java.awt.Dialog;
import java.awt.Dimension;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.List;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import unb.banco.cliente.ClienteJaExistenteException;
import unb.banco.dados.cliente.ClienteNaoExistenteException;
import unb.banco.dados.conta.ContaNaoExistenteException;
import unb.banco.Fachada;
import unb.banco.cliente.Cliente;
import unb.banco.cliente.ListaClientes;
import unb.banco.conta.Conta;
import unb.banco.conta.ContaBonificada;
import unb.banco.conta.ContaJaExistenteException;


import unb.banco.conta.ListaContas;
import unb.banco.conta.Poupanca;
import unb.banco.conta.SaldoInsuficienteException;


public class BancoFrame implements ActionListener, UI {

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
	private static final int OP_RENDER_BONUS = 12;
	private static final int OP_RENDER_JUROS = 13;
	private static final int OP_EXIBIR_CONTAS_CLIENTE = 14;
	private static final int OP_EXIBIR_CONTAS = 15;
	private static final int OP_EXIBIR_CLIENTES = 16;
	private static Fachada fachada;
	Frame f = new Frame("Aplicacao Bancaria");
	Panel pChoices = new Panel ();
	Panel pComposto = new Panel();
	Button b = new Button ("Executar");
	//Panel pList = new Panel();
	Panel p6 = new Panel ();
	Panel p7 = new Panel();
	Choice choiceClienteConta = new Choice ();
	Choice choiceOperacao = new Choice ();
	List list = new List ();
	Panel pConta = new Panel();
	Panel pCliente = new Panel();
	Panel pClienteConta = new Panel();
		
	int [][] codigoOperacao = 
	{
			{OP_CRIAR_CLIENTE,OP_CONSULTAR_CLIENTE, OP_ATUALIZAR_CLIENTE, OP_REMOVER_CLIENTE, OP_EXIBIR_CLIENTES},
			{OP_CRIAR_CONTA,OP_CONSULTAR_CONTA,OP_ATUALIZAR_CONTA,OP_REMOVER_CONTA, OP_EXIBIR_CONTAS,
			 OP_CREDITAR_CONTA, OP_DEBITAR_CONTA,OP_TRANSFERIR_CONTAS, OP_EXIBIR_CONTAS_CLIENTE,  OP_RENDER_BONUS,OP_RENDER_JUROS
				}};

	Dialog w = new Dialog(f,true);
	TextField textFieldCPFCliente = new TextField("",20);
	TextField textFieldNomeCliente = new TextField("",30);
	TextField textFieldContaNumero = new TextField("",20);
	TextField textFieldContaSaldo = new TextField("",6);
	private TextField textFieldContaTipo = new TextField("",3);
	private TextField textFieldValor = new TextField("",3);

	

	public void actionPerformed(ActionEvent arg0) {

		//pega opcao
		int opcao = pega_opcao();

		//trata opcao
		try {
			trata_opcao(opcao);
		}
		catch (ContaJaExistenteException e0) {
			System.out.println(e0.getMessage() );
		}
		catch (ContaNaoExistenteException e1) {
			System.out.println(e1.getMessage() );
		} 
		catch (SaldoInsuficienteException e2) {
			System.out.println(e2.getMessage() +  "  " +
					e2.getSaldo() + " na conta: " + e2.getNumero());

		}
		catch (ClienteNaoExistenteException e3 ) {
			System.out.println(e3.getMessage() );

		}
		catch (ClienteJaExistenteException e4 ) {
			System.out.println(e4.getMessage() );
		}
		
		/*
		w.setSize(new Dimension(40,70));
		w.pack();
		w.setVisible(true);
		 */
	}

	private int pega_opcao() {

		int i = choiceClienteConta.getSelectedIndex();
		int j = choiceOperacao.getSelectedIndex();

		int codigo = codigoOperacao [i] [j]; 
		return codigo;
	}


	public  void trata_opcao(int opcao) throws ContaNaoExistenteException, SaldoInsuficienteException, 
	ContaJaExistenteException, ClienteNaoExistenteException, ClienteJaExistenteException  {
		String nome, cpf,  numero;
		nome = numero = cpf = null;
		Cliente cliente = null;
		Conta conta;
		conta = null;

		double valor = 0;

		switch (opcao) {

		case OP_CRIAR_CLIENTE:
			nome = textFieldNomeCliente.getText();
			cpf = textFieldCPFCliente.getText();
			cliente = new Cliente(cpf, nome);
			fachada.cadastrar(cliente);
			textFieldNomeCliente.setText("");
			textFieldCPFCliente.setText("");
			break;

		case OP_CONSULTAR_CLIENTE:
			cpf = textFieldCPFCliente.getText();
			cliente = fachada.procurarCliente(cpf);
			if (cliente != null) {
				textFieldNomeCliente.setText(cliente.getNome());
				textFieldCPFCliente.setText(cliente.getCpf());
			} 
			break;

		case OP_ATUALIZAR_CLIENTE:
			cpf = textFieldCPFCliente.getText();
			nome = textFieldNomeCliente.getText();
			cliente = new Cliente(cpf, nome);
			fachada.atualizar(cliente);
			textFieldNomeCliente.setText("");
			textFieldCPFCliente.setText("");
			break;

		case OP_REMOVER_CLIENTE:
			cpf = textFieldCPFCliente.getText();
			fachada.descadastrarCliente(cpf);
			textFieldCPFCliente.setText("");
			break;
		
		case OP_EXIBIR_CLIENTES:
			ListaClientes lista_clientes = fachada.listaClientes();
			list.removeAll();
			while (lista_clientes.hasNext()) {
			    cliente = lista_clientes.next();
			    list.add("Cliente.  CPF: " + cliente.getCpf()+ " Nome: " + cliente.getNome());
			}
			break;
			
		case OP_CRIAR_CONTA:
			numero = textFieldContaNumero.getText();
			cpf = textFieldCPFCliente.getText();
			int tipo_conta = -1;
			do {
				System.out.println("Entre o tipo de Conta a ser criada ("
						+ 1 +"-Conta;"+
						2 +"-ContaBonificada);" +
						3 +"-Poupanca e  tecle Enter:");
				tipo_conta = Integer.parseInt(textFieldContaTipo.getText());
			} while  (tipo_conta != 1 && tipo_conta != 2 && tipo_conta != 3);
			
			cliente  = new Cliente (cpf,null);
			if (tipo_conta == 3) {
			 Poupanca p = new Poupanca (numero,cliente);
			 conta = p;
			} else if (tipo_conta == 2) {
			  ContaBonificada cb = new ContaBonificada (numero,cliente);
			  conta = cb;
			} else if (tipo_conta == 1) {
			  conta = new Conta (numero,cliente);	
			} 
			fachada.cadastrar(conta);
			break;

		case OP_CONSULTAR_CONTA:
			numero = textFieldContaNumero.getText();
			conta = fachada.procurarConta(numero);
			if (conta != null) {
				textFieldContaSaldo.setText(Double.toString(conta.getSaldo()));
				if (conta instanceof ContaBonificada) {
					textFieldContaTipo.setText("Bonificada");
					ContaBonificada cb = (ContaBonificada)conta;
					System.out.println("O valor do bonus eh:" + cb.getBonus());
				} else if (conta instanceof Poupanca) {
					textFieldContaTipo.setText("Poupanca");
				} else if (conta instanceof Conta) {
					textFieldContaTipo.setText("Conta");
				}
				cliente = conta.getCliente();
				textFieldNomeCliente.setText(cliente.getNome());
				textFieldCPFCliente.setText(cliente.getCpf());
			} else {
				System.out.println("Conta nao existente");
			}
			break;

		case OP_ATUALIZAR_CONTA:
			numero = textFieldContaNumero.getText();
			cpf = textFieldCPFCliente.getText();
			cliente = new Cliente(cpf, null);
			// preserva o numero da conta e atualiza o cliente dela
			conta = new Conta(numero, cliente);
			fachada.atualizar(conta);
			break;

		case OP_REMOVER_CONTA:
			numero = textFieldContaNumero.getText();
			fachada.descadastrarConta(numero);
			break;

		case OP_CREDITAR_CONTA:
			numero = textFieldContaNumero.getText();
			valor = Double.parseDouble(textFieldValor.getText());
			fachada.creditar(numero, valor);
			break;

		case OP_DEBITAR_CONTA:
			numero = textFieldContaNumero.getText();
			valor = Double.parseDouble(textFieldValor.getText());
			fachada.debitar(numero, valor);
			break;

		/*
		case OP_TRANSFERIR_CONTAS:
			System.out.println("Favor entre numero da conta origem e tecle Enter:");
			origem = sc.next();
			System.out.println("Favor entre numero da conta destino e tecle Enter:");
			destino = sc.next();
			System.out.println("Favor entre o valor a ser transferido e  tecle Enter:");
			valor = sc.nextDouble();
			fachada.transferir(origem, destino, valor);
			System.out.println(">> tranferir executado com sucesso:");

			break;

		case OP_RENDER_BONUS:
			System.out.println("Favor entre numero da conta e  tecle Enter:");
			numero = sc.next();
			fachada.renderBonus(numero);

			break;

		case OP_RENDER_JUROS:
			System.out.println("Favor entre numero da conta e  tecle Enter:");
			numero = sc.next();
			System.out.println("Favor entre a taxa de juros e tecle Enter:");
			valor = sc.nextDouble();
			fachada.renderJuros(numero,valor);
			break;

		case OP_EXIBIR_CONTAS_CLIENTE:
			System.out.println("Favor entre CPF do cliente e  tecle Enter:");
			cpf = sc.next();
			cliente = fachada.procurarCliente(cpf);
			if (cliente != null) {
				System.out.println("Nome do cliente: " + cliente.getNome());
				System.out.println("CPF do cliente: " + cliente.getCpf());
				ListaContas lista_contas = fachada.listaContasCliente(cpf);
				while (lista_contas.hasNext()) {
					System.out.println("---------------------------------------------");
					conta = lista_contas.next();
					System.out.println("Numero da conta: " + conta.getNumero());
					System.out.println("Saldo da conta: " + conta.getSaldo());
					if (conta instanceof ContaBonificada) {
						System.out.println("A conta eh do tipo Conta Bonificada");
						System.out.println("A conta eh do tipo Conta Bonificada");
						ContaBonificada cb = (ContaBonificada)conta;
						System.out.println("O valor do bonus eh:" + cb.getBonus());
					} else if (conta instanceof Poupanca) {
						System.out.println("A conta eh do tipo Poupanca.");
					} else if (conta instanceof Conta) {
						System.out.println("A conta eh do tipo Conta.");
					}
				}
				System.out.println("----------------*******-----------------------");
			} 

			break;

   */
		case OP_EXIBIR_CONTAS:
			ListaContas lista_contas = fachada.listaContas();
			list.removeAll();
			while (lista_contas.hasNext()) {
				conta = lista_contas.next();
				cliente = conta.getCliente();
				list.add("Conta: " + conta.getNumero()+ "  Saldo: " + conta.getSaldo() + " Cliente: " + cliente.getCpf() + cliente.getNome());
			}
			break;

  

		}

	}




	public BancoFrame ()  {

        
        	fachada = Fachada.obterInstancia();
		
		f.add(BorderLayout.NORTH,pChoices);
		f.add(pComposto);

	
		choiceClienteConta.add("Cliente");
		choiceClienteConta.add("Conta");

		choiceOperacao.add("Criar");
		choiceOperacao.add("Procurar");
		choiceOperacao.add("Alterar");
		choiceOperacao.add("Remover");
		choiceOperacao.add("Listar");
		choiceOperacao.add("Creditar");
		choiceOperacao.add("Debitar");
		choiceOperacao.add("Contas-de-cliente");

		pChoices.add(choiceClienteConta);
		pChoices.add(choiceOperacao);
		pChoices.add(b);
		Button bLimpar = new Button("Limpar");
		bLimpar.addActionListener( new ActionListener () {

			@Override
			public void actionPerformed(ActionEvent arg0) {
				textFieldNomeCliente.setText("");
				textFieldCPFCliente.setText("");
				list.removeAll();
				
			}});
		pChoices.add(bLimpar);

		Label l1 = new Label("Conta");
		Label l2 = new Label("Tipo (0,1,2)" );
		Label l3 = new Label("Numero");
		Label l4 = new Label("Saldo");
		Label l44 = new Label("Valor");
		

		pConta.add(l1);
		pConta.add(l2);
		pConta.add(textFieldContaTipo);
		pConta.add(l3);
		pConta.add(textFieldContaNumero);
		pConta.add(l4);
		pConta.add(textFieldContaSaldo);
		pConta.add(l44);
		pConta.add(textFieldValor);

		Label l5 = new Label("Cliente");
		Label l6 = new Label("CPF");
		
		Label l7 = new Label("Nome");
		

		pCliente.add(l5);
		pCliente.add(l6);
		pCliente.add(textFieldCPFCliente);
		pCliente.add(l7);
		pCliente.add(textFieldNomeCliente);

		pClienteConta.setLayout(new GridLayout(2,1));
		pClienteConta.add(pConta);
		pClienteConta.add(pCliente);



		//pList.add(list);

		pComposto.setLayout(new BorderLayout());
		pComposto.add(BorderLayout.NORTH,pClienteConta);
		//pComposto.add(pList);
		pComposto.add(list);


		b.addActionListener(this);

		f.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});


		f.setSize(new Dimension(40,70));
		f.pack();
		f.setVisible(true);


	}




}
