package unb.banco.dados.cliente;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import unb.banco.cliente.Cliente;


public class RepositorioClientesArquivoTexto implements RepositorioClientes {
	
	private static final int MAXCLIENTES = 10000;
	private String nomeArquivo, nomeArquivoAuxiliar;
	private int numeroDeClientes;
	

	public RepositorioClientesArquivoTexto(String nomeArquivo) {
		numeroDeClientes = 0;
        this.nomeArquivo = nomeArquivo;
		nomeArquivoAuxiliar = nomeArquivo + ".bak";
		File f = new File (nomeArquivo);
		File f2 = new File (nomeArquivoAuxiliar);
		try {
			f.createNewFile();
			f2.createNewFile();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}

	public Cliente[] getClientes() {
		
		String cpf, nome = null;
		Cliente c = null;
		Cliente[] clientes = new Cliente [MAXCLIENTES];
		FileReader ir = null;
		BufferedReader br = null;
		int nClientes = 0;
		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);

			String linha = br.readLine(); 
	        while (linha != null) {
	        	// guarda o cpf lido do cliente
	        	cpf = linha;
	        	// le o nome do cliente 
	        	nome = br.readLine();
	        	c = new Cliente (cpf,nome);
	        	clientes[nClientes] = c;
	        	nClientes = nClientes + 1;
	        	// le o cpf do proximo cliente
	        	linha = br.readLine();
	        }
	        numeroDeClientes = nClientes;
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
		
		return clientes;
	}

	public int getIndice() {
		//getClientes();
		return numeroDeClientes;
	}

	public void atualizar(Cliente c) throws ClienteNaoExistenteException {
		String cpf = c.getCpf();
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
	        while (linha != null && !linha.equals(cpf)) {
	        	// escreve no arquivo auxiliar o nome do cpf lido
	        	 bw.write(linha);
	        	 bw.newLine();
	        	// le o nome do cliente e pula este nome
	        	linha = br.readLine();
	        	// escreve no arquivo auxiliar o nome do cliente lido
	        	 bw.write(linha);
	        	 bw.newLine();
	        	// le o cpf do proximo cliente
	        	linha = br.readLine();
	        } 
	        if (linha == null) {
	        	throw new ClienteNaoExistenteException(cpf);
	        }
	        else {
	        	// achou o cliente, entao pula o nome dele  
	        	linha = br.readLine();
	        	// escreve no arquivo auxiliar o cpf do cliente
	        	bw.write (cpf);
	        	bw.newLine();
	        	// escreve no arquivo auxiliar o nome novo do cliente
	        	bw.write (c.getNome());
	        	bw.newLine();
	        	// o resto do arquivo auxiliar deve ser igual ao resto do arquivo original
	        	// entao escrevemos o resto dos clientes no arquivo auxiliar
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
				// que tem o nome do cliente desatualizado
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

	public boolean existe(String cpf) {
		boolean resp = false;

		try {
			this.procurar(cpf);
			resp = true;
		} catch (ClienteNaoExistenteException e) {
			resp = false;
		}

		return resp;
	}

	public void inserir(Cliente c) {
		FileWriter fout = null;
		BufferedWriter bw = null;
		try {
			 // o segundo argumento indica que o arquivo eh aberto
			// para insercao de dados apos o fim do arquivo
			 fout = new FileWriter(nomeArquivo,true);
			 bw = new BufferedWriter(fout);
			 bw.write(c.getCpf()  + "\n");
			 bw.write(c.getNome() + "\n");
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

	public Cliente procurar(String cpf) throws ClienteNaoExistenteException {
		Cliente c = null;
		FileReader ir = null;
		BufferedReader br = null; 
		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);

			String linha = br.readLine(); 
	        while (linha != null && !linha.equals(cpf)) { 
	        	// le o nome do cliente e pula este nome
	        	linha = br.readLine();
	        	// le o cpf do proximo cliente
	        	linha = br.readLine();
	        } 
	        if (linha == null) {
	        	throw new ClienteNaoExistenteException(cpf);
	        }
	        else {
	        	// achou o cliente, entao le o nome dele e cria o objeto correspondente 
	        	linha = br.readLine();
	        	c = new Cliente(cpf,linha);
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
		
		return c;
	}

	public void remover(String cpf) throws ClienteNaoExistenteException {
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
	        while (linha != null && !linha.equals(cpf)) {
	        	// escreve no arquivo auxiliar o nome do cpf lido
	        	 bw.write(linha);
	        	 bw.newLine();
	        	// le o nome do cliente e pula este nome
	        	linha = br.readLine();
	        	// escreve no arquivo auxiliar o nome do cliente lido
	        	 bw.write(linha);
	        	 bw.newLine();
	        	// le o cpf do proximo cliente
	        	linha = br.readLine();
	        } 
	        if (linha == null) {
	        	throw new ClienteNaoExistenteException(cpf);
	        }
	        else {
	        	// achou o cliente, entao pula o nome dele  
	        	linha = br.readLine();
	        	// nao escreve no arquivo auxiliar o cpf do cliente, pois queremos remove-lo
	        	//bw.write (cpf);
	        	//bw.newLine();
	        	// nao escreve no arquivo auxiliar o nome do cliente, pois queremos remove-lo
	        	//bw.write (c.getNome());
	        	//bw.newLine();
	        	
	        	// o resto do arquivo auxiliar deve ser igual ao resto do arquivo original
	        	// entao escrevemos o resto dos clientes no arquivo auxiliar
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
				// que tem o nome do cliente desatualizado
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