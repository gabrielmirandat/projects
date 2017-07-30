package unb.banco.dados.conta;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import unb.banco.cliente.Cliente;
import unb.banco.conta.Conta;
import unb.banco.conta.ContaBonificada;
import unb.banco.conta.Poupanca;
import unb.banco.dados.cliente.ClienteNaoExistenteException;
import unb.banco.dados.cliente.RepositorioClientesArquivoTexto;

public class RepositorioContasArquivoTexto implements RepositorioContas {
	private static final int MAXCONTAS = 10000;
	private String nomeArquivo, nomeArquivoAuxiliar, nomeArquivoCliente;
	private int numeroDeContas;
	

	public RepositorioContasArquivoTexto(String nomeArquivo, String nomeArquivoCliente) {
		this.nomeArquivo = nomeArquivo;
		this.nomeArquivoCliente = nomeArquivoCliente;
		nomeArquivoAuxiliar = nomeArquivo + ".bak";
		
		numeroDeContas = 0;

		File f = new File(nomeArquivo);
		File f2 = new File(nomeArquivoAuxiliar);
		try {
			f.createNewFile();
			f2.createNewFile();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public Conta[] getContas() {
		Conta[] contas = new Conta[MAXCONTAS];
		int nContas = 0;
		Conta conta = null;
		FileReader ir = null;
		BufferedReader br = null;
		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);

			// le o numero da conta
			String linha = br.readLine();
			while (linha != null) {
				String numero = linha;
				// le o saldo da conta
				double saldo = Double.parseDouble(br.readLine());
				// le o cpf do cliente da conta
				String cpf = br.readLine();
				// le o tipo da conta
				String tipo = br.readLine();
				double bonus = 0;
				if (tipo.equals("B")) {
					linha = br.readLine();
					bonus = Double.parseDouble(linha);
				}
				RepositorioClientesArquivoTexto repClientes = new RepositorioClientesArquivoTexto(nomeArquivoCliente);
				Cliente cliente;
				try {
					cliente = repClientes.procurar(cpf);
					if (tipo.equals("B")) {
						conta = new ContaBonificada(numero,cliente);
						conta.setSaldo(saldo);
						((ContaBonificada) conta).setBonus(bonus);
					} else if (tipo.equals("P")) {
						conta = new Poupanca(numero,saldo,cliente);
					} else {
						conta = new Conta(numero, saldo, cliente);
					}
					contas[nContas] = conta;
					nContas = nContas + 1;
				} catch (ClienteNaoExistenteException e) {
					// nao deveria acontecer devido a invariante do programa:
					// regra de negocio que diz que so se cadastra conta para
					// cliente cadastrado
					e.printStackTrace();
				}
			   // le o numero da proxima conta
				linha = br.readLine();
			}
            numeroDeContas = nContas;			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				br.close();
				ir.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return contas;
	}

	public int getIndice() {
		//getContas();
		return numeroDeContas;
	}

	public void inserir(Conta c) {
		/*
		 A convencao para escrita de cada conta eh ter em linhas diferentes:   
		 1) numero da conta; 2) saldo da conta; 3) cpf do cliente da conta; 
		 4)tipo da conta; 5) bonus (se for bonificada)
		 */
		FileWriter fout = null;
		BufferedWriter bw = null;
		try {
			// o segundo argumento indica que o arquivo eh aberto
			// para insercao de dados apos o fim do arquivo
			fout = new FileWriter(nomeArquivo, true);
			bw = new BufferedWriter(fout);
			bw.write(c.getNumero());
			bw.newLine();
			bw.write(Double.toString(c.getSaldo()));
			bw.newLine();
			bw.write(c.getCliente().getCpf());
			bw.newLine();
			// escreve o tipo da conta para guiar a leitura no metodo procurar no momento da leitura
			bw.write(tipo(c));
			bw.newLine();
			if (c instanceof ContaBonificada) {
				ContaBonificada cb = (ContaBonificada) c;
				bw.write(Double.toString(cb.getBonus()));
				bw.newLine();
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				bw.close();
				fout.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

	}

	private String tipo(Conta c) {
		String t = null;
		if (c instanceof ContaBonificada)
			t ="B";
		else if (c instanceof Poupanca)
			t ="P";
		else if (c instanceof Conta)
			t = "C";

		return t;
	}

	public boolean existe(String num) {
		boolean resp = false;

		try {
			this.procurar(num);
			resp = true;
		} catch (ContaNaoExistenteException e) {
			resp = false;
		}

		return resp;
	}

	public void atualizar(Conta c) throws ContaNaoExistenteException {
		String numeroConta = c.getNumero();
		FileReader ir = null;
		BufferedReader br = null;
		FileWriter fout = null;
		BufferedWriter bw = null;

		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);
			fout = new FileWriter(nomeArquivoAuxiliar);
			bw = new BufferedWriter(fout);

			String linha = br.readLine();
			while (linha != null && !linha.equals(numeroConta)) {
				// escreve no arquivo auxiliar o numero da conta
				bw.write(linha);
				bw.newLine();
				// le o saldo da conta
				linha = br.readLine();
				// escreve no arquivo auxiliar o saldo da conta
				bw.write(linha);
				bw.newLine();
                // le o cpf do cliente da conta
				linha = br.readLine();
				// escreve no arquivo auxiliar o cpf do cliente da conta
				bw.write(linha);
				bw.newLine();
				
				// le o tipo da conta
				linha = br.readLine();
				// escreve no arquivo auxiliar o tipo da conta
				bw.write(linha);
				bw.newLine();
				// escreve no arquivo auxiliar o bonus se a conta for bonificada
				if (linha.equals("B")) {
					// le o bonus ja que a conta eh bonificada
					linha = br.readLine();
					// escreve no arquivo auxiliar o bonus da conta
					bw.write(linha);
					bw.newLine();
				}

				// le o numero da proxima clienta
				linha = br.readLine();
			}
			if (linha == null) {
				throw new ContaNaoExistenteException(numeroConta);
			} else {
				// achou a  conta, entao escreve o numero da conta no arq auxiliar
				bw.write(linha);
				bw.newLine();
				// pula  o saldo da conta
				linha = br.readLine();
				// escreve no arquivo auxiliar o novo saldo da conta
				bw.write(Double.toString(c.getSaldo()));
				bw.newLine();
				// pula o antigo cpf da conta
				linha = br.readLine();
				// escreve no arquivo auxiliar o cpf novo do cliente
				bw.write(c.getCliente().getCpf());
				bw.newLine();
				
				// le o tipo da conta
				linha = br.readLine();
				// escreve no arquivo auxiliar o tipo da conta
				bw.write(linha);
				bw.newLine();
				// escreve no arquivo auxiliar novo  bonus se a conta for bonificada
				if (linha.equals("B")) {
					// pula o bonus ja que a conta eh bonificada
					linha = br.readLine();
					// escreve no arquivo auxiliar o novo bonus da conta
					bw.write(Double.toString(((ContaBonificada) c).getBonus()));
					bw.newLine();
				}
				
				
				// o resto do arquivo auxiliar deve ser igual ao resto do
				// arquivo original
				// entao escrevemos o resto das contas no arquivo auxiliar
				linha = br.readLine();
				while (linha != null) {
					// escreve no arquivo auxiliar o valor lido (cpf/nome)
					bw.write(linha);
					bw.newLine();
					// le o nome/cpf do cliente
					linha = br.readLine();
				}
				// fechando buffers e arquivos
				br.close();
				ir.close();
				bw.close();
				fout.close();
				// devemos agora trocar o arquivo original pelo auxiliar,
				// que tem o nome do cliente doatualizado
				File arq_original = new File(nomeArquivo);
				File arq_auxiliar = new File(nomeArquivoAuxiliar);
				arq_original.delete();
				arq_auxiliar.renameTo(arq_original);
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				br.close();
				ir.close();
				bw.close();
				fout.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

	}

	public Conta procurar(String num) throws ContaNaoExistenteException {
		/*
		  A convencao leitura de cada conta eh ter em linhas diferentes:   
			 1) numero da conta; 2) saldo da conta; 3) cpf do cliente da conta; 
			 4)tipo da conta; 5) bonus (se for bonificada)
		 */
		
		Conta conta = null;
		FileReader ir = null;
		BufferedReader br = null;
		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);

			// le o numero da conta
			String linha = br.readLine();
			while (linha != null && !linha.equals(num)) {
				// le o saldo da conta
				linha = br.readLine();
				// le o cpf do cliente da conta
				linha = br.readLine();
				// le o tipo da conta
				linha = br.readLine();
				// se o tipo indicar Conta Bonificada, ler o bonus
				if (linha.equals("B")) {
					linha = br.readLine();
				}
				// le o numero da proxima conta
				linha = br.readLine();
			}
			if (linha == null) {
				throw new ContaNaoExistenteException(num);
			} else {
				String numero = linha;
				// achou a conta, entao le o saldo dela, o cliente, o tipo, e cria o
				// objeto correspondente
				double saldo = Double.parseDouble(br.readLine());
				String cpf = br.readLine();
				String tipo = br.readLine();
				double bonus = 0;
				if (tipo.equals("B")) {
					linha = br.readLine();
					bonus = Double.parseDouble(linha);
				}
				RepositorioClientesArquivoTexto repClientes = new RepositorioClientesArquivoTexto(nomeArquivoCliente);
				Cliente cliente;
				try {
					cliente = repClientes.procurar(cpf);
					if (tipo.equals("B")) {
						conta = new ContaBonificada(numero,cliente);
						conta.setSaldo(saldo);
						((ContaBonificada) conta).setBonus(bonus);
					} else if (tipo.equals("P")) {
						conta = new Poupanca(numero,saldo,cliente);
					} else {
						conta = new Conta(numero, saldo, cliente);
					}
				} catch (ClienteNaoExistenteException e) {
					// nao deveria acontecer devido a invariante do programa:
					// regra de negocio que diz que so se cadastra conta para
					// cliente cadastrado
					e.printStackTrace();
				}
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				br.close();
				ir.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		return conta;
	}

	public void remover(String numeroConta) throws ContaNaoExistenteException {
		FileReader ir = null;
		BufferedReader br = null;
		FileWriter fout = null;
		BufferedWriter bw = null;

		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);
			fout = new FileWriter(nomeArquivoAuxiliar);
			bw = new BufferedWriter(fout);

			String linha = br.readLine();
			while (linha != null && !linha.equals(numeroConta)) {
				// escreve no arquivo auxiliar o numero da conta
				bw.write(linha);
				bw.newLine();
				// le o saldo da conta
				linha = br.readLine();
				// escreve no arquivo auxiliar o saldo da conta
				bw.write(linha);
				bw.newLine();
                // le o cpf do cliente da conta
				linha = br.readLine();
				// escreve no arquivo auxiliar o cpf do cliente da conta
				bw.write(linha);
				bw.newLine();
				// le o tipo da conta
				linha = br.readLine();
				// escreve no arquivo auxiliar o tipo da conta
				bw.write(linha);
				bw.newLine();
				// escreve no arquivo auxiliar o bonus se a conta for bonificada
				if (linha.equals("B")) {
					// le o bonus ja que a conta eh bonificada
					linha = br.readLine();
					// escreve no arquivo auxiliar o bonus da conta
					bw.write(linha);
					bw.newLine();
				}

				// le o numero da proxima clienta
				linha = br.readLine();
			}
			if (linha == null) {
				throw new ContaNaoExistenteException(numeroConta);
			} else {
				// achou a  conta, nao entao escreve o numero da conta no arq auxiliar
				// bw.write(linha);
				// bw.newLine();
				// le o saldo da conta
				linha = br.readLine();
				// nao escreve no arquivo auxiliar o saldo da conta
				//bw.write(linha);
				//bw.newLine();
				// pula o antigo cpf da conta
				linha = br.readLine();
				// nao escreve no arquivo auxiliar o cpf do cliente
				//bw.write(c.getCliente().getCpf());
				//bw.newLine();
				
				// checa o tipo da conta para saber se pula o bonus tambem
				linha = br.readLine();
				if (linha.equals("B")) {
					// le e pula o bonus ja que a conta eh bonificada
					linha = br.readLine();
				}
				
				// o resto do arquivo auxiliar deve ser igual ao resto do
				// arquivo original
				// entao escrevemos o resto das contas no arquivo auxiliar
				linha = br.readLine();
				while (linha != null) {
					// escreve no arquivo auxiliar o valor lido (cpf/nome)
					bw.write(linha);
					bw.newLine();
					// le o nome/cpf do cliente
					linha = br.readLine();
				}
				// fechando buffers e arquivos
				br.close();
				ir.close();
				bw.close();
				fout.close();
				// devemos agora trocar o arquivo original pelo auxiliar,
				// que tem o nome do cliente doatualizado
				File arq_original = new File(nomeArquivo);
				File arq_auxiliar = new File(nomeArquivoAuxiliar);
				arq_original.delete();
				arq_auxiliar.renameTo(arq_original);
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				br.close();
				ir.close();
				bw.close();
				fout.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

	}
}
