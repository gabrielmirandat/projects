 package unbPOO.escola.dados.aluno;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import unbPOO.escola.aluno.Aluno;


public class RepositorioAlunosArquivoTexto implements RepositorioAlunos {
	
	private static final int MAXALUNOS = 10000;
	private String nomeArquivo, nomeArquivoAuxiliar;
	private int numeroDeAlunos;
	

	public RepositorioAlunosArquivoTexto(String nomeArquivo) {
		numeroDeAlunos = 0;
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

	public Aluno[] getAlunos() {
		
		String nome, endereco, telefone = null;
                int idade = 0;
		Aluno a = null;
		Aluno[] alunos = new Aluno [MAXALUNOS];
		FileReader ir = null;
		BufferedReader br = null;
		int nAlunos = 0;
		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);
                        //le o nome do cliente
			String linha = br.readLine(); 
	        while (linha != null) {
	        	// guarda o nome lido do cliente
	        	nome = linha;
	        	// le o endereco, telefone, idade do cliente 
	        	endereco = br.readLine();
                        telefone = br.readLine();
                        idade = Integer.parseInt(br.readLine());
	        	a = new Aluno (nome, endereco, telefone, idade);
	        	alunos[nAlunos] = a;
	        	nAlunos = nAlunos + 1;
	        	// le o nome do proximo aluno
	        	linha = br.readLine();
	        }
	        numeroDeAlunos = nAlunos;
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
		
		return alunos;
	}

	public int getIndice() {
		getAlunos();
		return numeroDeAlunos;
	}

	public void atualizar(Aluno a) throws AlunoNaoExistenteException {
		String nome = a.getNome();
		FileReader ir = null;
		BufferedReader br = null;
		FileWriter fout = null;
		BufferedWriter bw = null;
		
		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);
			fout = new FileWriter(nomeArquivoAuxiliar);
			 bw = new BufferedWriter(fout);
                         //le o nome do aluno
			String linha = br.readLine(); 
	        while (linha != null && !linha.equals(nome)) {
	        	// escreve no arquivo auxiliar o nome do aluno lido
	        	 bw.write(linha);
	        	 bw.newLine();
	        	// le o endereco do aluno e pula este nome
	        	linha = br.readLine();
	        	// escreve no arquivo auxiliar o endereco do aluno lido
	        	 bw.write(linha);
	        	 bw.newLine();
	        	// le o telefone do aluno e pula
	        	linha = br.readLine();
                        
                        // escreve no arquivo auxiliar o telefone
	        	 bw.write(linha);
	        	 bw.newLine();
	        	// le a idade do aluno e pula
	        	linha = br.readLine();
	        	// escreve no arquivo auxiliar a idade do aluno
	        	 bw.write(linha);
	        	 bw.newLine();
	        	// le o nome do proximo aluno
	        	linha = br.readLine();
	        } 
	        if (linha == null) {
	        	throw new AlunoNaoExistenteException(nome);
	        }
	        else {
	        	// achou o aluno, entao pula o endereco, o telefone e a idade dele  
	        	linha = br.readLine();
                        linha = br.readLine();
                        linha = br.readLine();
	        	// escreve no arquivo auxiliar o nome do aluno
	        	bw.write (nome);
	        	bw.newLine();
	        	// escreve no arquivo auxiliar os novos endereco, telefone e idade do aluno
	        	bw.write (a.getEndereco());
	        	bw.newLine();
                        bw.write (a.getTelefone());
	        	bw.newLine();
                        bw.write (Integer.toString(a.getIdade()));
	        	bw.newLine();
	        	// o resto do arquivo auxiliar deve ser igual ao resto do arquivo original
	        	// entao escrevemos o resto dos alunos no arquivo auxiliar
	        	linha = br.readLine();
	        	while (linha != null) {
	        		// escreve no arquivo auxiliar o valor lido (nome/endereco/telefone/idade)
		        	 bw.write(linha);
		        	 bw.newLine();
		        	// le o nome/endereco/telefone/idade do aluno
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

	public boolean existe(String nome) {
		boolean resp = false;

		try {
			this.procurar(nome);
			resp = true;
		} catch (AlunoNaoExistenteException e) {
			resp = false;
		}

		return resp;
	}

	public void inserir(Aluno a) {
		FileWriter fout = null;
		BufferedWriter bw = null;
		try {
			 // o segundo argumento indica que o arquivo eh aberto
			// para insercao de dados apos o fim do arquivo
			 fout = new FileWriter(nomeArquivo,true);
			 bw = new BufferedWriter(fout);
			 bw.write(a.getNome());
                         bw.newLine();
			 bw.write(a.getEndereco());
                         bw.newLine();
                         bw.write(a.getTelefone());
                         bw.newLine();
                         bw.write(Integer.toString(a.getIdade()));
                         bw.newLine();
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

	public Aluno procurar(String nome) throws AlunoNaoExistenteException {
		Aluno a = null;
		FileReader ir = null;
		BufferedReader br = null; 
		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);
                        //le o nome do alnuo
			String linha = br.readLine(); 
                        String linha1,linha2, linha3 = null;
	        while (linha != null && !linha.equals(nome)) { 
	        	// le o endereço, telefone, idade e pula
	        	linha1 = br.readLine();
                        linha2 = br.readLine();
                        linha3 = br.readLine();
	        	// le o cpf do proximo cliente
	        	linha = br.readLine();
                        
	        } 
	        if (linha == null) {
	        	throw new AlunoNaoExistenteException(nome);
	        }
	        else {
	        	// achou o aluno, entao le o endereco, telefone e idade dele e cria o objeto correspondente 
	        	linha1 = br.readLine();
                        linha2 = br.readLine();
                        linha3 = br.readLine();
                        int idadeAluno = Integer.parseInt(linha3);
                        
	        	a = new Aluno(nome, linha1, linha2, idadeAluno);
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
		
		return a;
	}

	public void remover(String nome) throws AlunoNaoExistenteException {
		FileReader ir = null;
		BufferedReader br = null;
		FileWriter fout = null;
		BufferedWriter bw = null;
		
		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);
			fout = new FileWriter(nomeArquivoAuxiliar);
			 bw = new BufferedWriter(fout);
                         //le o nome do aluno
			String linha = br.readLine(); 
	        while (linha != null && !linha.equals(nome)) {
	        	// escreve no arquivo auxiliar o nome do aluno lido
	        	 bw.write(linha);
	        	 bw.newLine();
	        	// le o endereco do aluno e pula este nome
	        	linha = br.readLine();
	        	// escreve no arquivo auxiliar o endereco lido
	        	 bw.write(linha);
	        	 bw.newLine();
	        	// le o telefone do aluno e pula
	        	linha = br.readLine();
                        //escreve no arquivo auxiliar o telefone lido
                        bw.write(linha);
	        	 bw.newLine();
	        	// le a idade e pula
	        	linha = br.readLine();
	        	// escreve no arquivo auxiliar a idade
	        	 bw.write(linha);
	        	 bw.newLine();
	        	// le o nome do proximo aluno
	        	linha = br.readLine();
	        } 
	        if (linha == null) {
	        	throw new AlunoNaoExistenteException(nome);
	        }
	        else {
	        	// achou o aluno, entao pula o endereco, o telefone e a idade
	        	linha = br.readLine();
                        linha = br.readLine();
                        linha = br.readLine();
	        	// nao escreve no arquivo auxiliar o nome do aluno, pois queremos remove-lo
	        	//bw.write (nome);
	        	//bw.newLine();
	        	// nao escreve no arquivo auxiliar o endereco, nem telefone nem idade pois queremos remove-lo
	        	//bw.write (c.getEndereco());
	        	//bw.newLine();
                        //bw.write (c.getTelefone());
	        	//bw.newLine();
                        //bw.write (c.getIdade());
	        	//bw.newLine();
	        	
	        	// o resto do arquivo auxiliar deve ser igual ao resto do arquivo original
	        	// entao escrevemos o resto dos clientes no arquivo auxiliar
	        	linha = br.readLine();
	        	while (linha != null) {
	        		// escreve no arquivo auxiliar o valor lido (nome/endereco/telefone/idade)
		        	 bw.write(linha);
		        	 bw.newLine();
		        	// le os nome/endereco/telefone/idade do aluno
		        	linha = br.readLine();
	        	}
	        	// fechando buffers e arquivos
	        	br.close();
				ir.close();
				bw.close();
				fout.close();
	        	// devemos agora trocar o arquivo original pelo auxiliar, 
				// que tem os dados do aluno atualizados
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
