package unbPOO.escola.dados.curso;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import unbPOO.escola.curso.Curso;


public class RepositorioCursosArquivoTexto implements RepositorioCursos {
	
	private static final int MAXCURSOS = 10000;
	private String nomeArquivo, nomeArquivoAuxiliar;
	private int numeroDeCursos;
	

	public RepositorioCursosArquivoTexto(String nomeArquivo) {
		numeroDeCursos = 0;
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

	public Curso[] getCursos() {
		
		String codigo, nomeCurso, instrutor = null;
		Curso c = null;
		Curso[] cursos = new Curso [MAXCURSOS];
		FileReader ir = null;
		BufferedReader br = null;
		int nCursos = 0;
		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);
                        // le o codigo do curso
			String linha = br.readLine(); 
	        while (linha != null) {
	        	// guarda o codigo do curso
	        	codigo = linha;
	        	// le o nome e o instrutor do curso 
	        	nomeCurso = br.readLine();
                        instrutor = br.readLine();
	        	c = new Curso (codigo, nomeCurso, instrutor);
	        	cursos[nCursos] = c;
	        	nCursos = nCursos + 1;
	        	// le o codigo do proximo curso
	        	linha = br.readLine();
	        }
	        numeroDeCursos = nCursos;
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
		
		return cursos;
	}

	public int getIndice() {
		getCursos();
		return numeroDeCursos;
	}

	public void atualizar(Curso c) throws CursoNaoExistenteException {
		String codigo = c.getCodigo();
		FileReader ir = null;
		BufferedReader br = null;
		FileWriter fout = null;
		BufferedWriter bw = null;
		
		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);
			fout = new FileWriter(nomeArquivoAuxiliar);
			 bw = new BufferedWriter(fout);
                         //le o codigo do curso
			String linha = br.readLine(); 
	        while (linha != null && !linha.equals(codigo)) {
	        	// escreve no arquivo auxiliar o codigo do curso lido
	        	 bw.write(linha);
	        	 bw.newLine();
	        	// le o nome do curso e pula este nome
	        	linha = br.readLine();
	        	// escreve no arquivo auxiliar o nome do curso lido
	        	 bw.write(linha);
	        	 bw.newLine();
	        	// le o instrutor e pula
	        	linha = br.readLine();
                        //escreve no arquivo auxiliar o instrutor
                        bw.write(linha);
	        	 bw.newLine();
	        	// le o codigo do proximo curso
	        	linha = br.readLine();
	        } 
	        if (linha == null) {
	        	throw new CursoNaoExistenteException(codigo);
	        }
	        else {
	        	// achou o curso, entao pula o nome e o instrutor dele 
	        	linha = br.readLine();
                        linha = br.readLine();
	        	// escreve no arquivo auxiliar o codigo do curso
	        	bw.write (codigo);
	        	bw.newLine();
	        	// escreve no arquivo auxiliar o nome e  o instrutor novos do curso
	        	bw.write (c.getNome());
	        	bw.newLine();
                        bw.write (c.getInstrutor());
	        	bw.newLine();
	        	// o resto do arquivo auxiliar deve ser igual ao resto do arquivo original
	        	// entao escrevemos o resto dos clientes no arquivo auxiliar
	        	linha = br.readLine();
	        	while (linha != null) {
	        		// escreve no arquivo auxiliar o valor lido (codigo/nome/instrutor)
		        	 bw.write(linha);
		        	 bw.newLine();
		        	// le o codigo/nome/instrutor do curso
		        	linha = br.readLine();
	        	}
	        	// fechando buffers e arquivos
	        	br.close();
				ir.close();
				bw.close();
				fout.close();
	        	// devemos agora trocar o arquivo original pelo auxiliar, 
				// que tem os dados do curso atualizados
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

	public boolean existe(String codigo) {
		boolean resp = false;

		try {
			this.procurar(codigo);
			resp = true;
		} catch (CursoNaoExistenteException e) {
			resp = false;
		}

		return resp;
	}

	public void inserir(Curso c) {
		FileWriter fout = null;
		BufferedWriter bw = null;
		try {
			 // o segundo argumento indica que o arquivo eh aberto
			// para insercao de dados apos o fim do arquivo
			 fout = new FileWriter(nomeArquivo,true);
			 bw = new BufferedWriter(fout);
			 bw.write(c.getCodigo());
                         bw.newLine();
			 bw.write(c.getNome());
                         bw.newLine();
                         bw.write(c.getInstrutor());
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

	public Curso procurar(String codigo) throws CursoNaoExistenteException {
		Curso c = null;
		FileReader ir = null;
		BufferedReader br = null; 
		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);
                        // le o codigo do curso
			String linha = br.readLine(); 
                        String linha1, linha2 = null;
	        while (linha != null && !linha.equals(codigo)) { 
	        	// le o nome e instrutor do curso e pula
	        	linha1 = br.readLine();
                        linha2= br.readLine();
	        	// le o codigo do proximo curso
	        	linha = br.readLine();
	        } 
	        if (linha == null) {
	        	throw new CursoNaoExistenteException(codigo);
	        }
	        else {
	        	// achou o cliente, entao le o nome dele e cria o objeto correspondente 
	        	linha1 = br.readLine();
                        linha2 = br.readLine();
	        	c = new Curso(codigo, linha1, linha2);
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

	public void remover(String codigo) throws CursoNaoExistenteException {
		FileReader ir = null;
		BufferedReader br = null;
		FileWriter fout = null;
		BufferedWriter bw = null;
		
		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);
			fout = new FileWriter(nomeArquivoAuxiliar);
			 bw = new BufferedWriter(fout);
                         // le o codigo do curso
			String linha = br.readLine(); 
	        while (linha != null && !linha.equals(codigo)) {
	        	// escreve no arquivo auxiliar o codigo do curso lido
	        	 bw.write(linha);
	        	 bw.newLine();
	        	// le o nome do curso e pula este nome
	        	linha = br.readLine();
	        	// escreve no arquivo auxiliar o nome do curso lido
	        	 bw.write(linha);
	        	 bw.newLine();
	        	// le o instrutor e pula
	        	linha = br.readLine();
                        //escreve no arquivo auxiliar o instrutor lido
                        bw.write(linha);
	        	 bw.newLine();
	        	// le o codigo do proximo curso
	        	linha = br.readLine();
	        } 
	        if (linha == null) {
	        	throw new CursoNaoExistenteException(codigo);
	        }
	        else {
	        	// achou o curso, entao pula o nome e o instrutor dele  
	        	linha = br.readLine();
                        linha = br.readLine();
	        	// nao escreve no arquivo auxiliar o codigo do curso, pois queremos remove-lo
	        	//bw.write (codigo);
	        	//bw.newLine();
	        	// nao escreve no arquivo auxiliar nem o nome nem o instrutor, pois queremos remove-lo
	        	//bw.write (c.getNome());
	        	//bw.newLine();
                        //bw.write (c.getIstrutor());
	        	//bw.newLine();
                        	        	
	        	// o resto do arquivo auxiliar deve ser igual ao resto do arquivo original
	        	// entao escrevemos o resto dos cursos no arquivo auxiliar
	        	linha = br.readLine();
	        	while (linha != null) {
	        		// escreve no arquivo auxiliar o valor lido (codigo/nome/instrutor)
		        	 bw.write(linha);
		        	 bw.newLine();
		        	// le o codigo/nome/instrutor do curso
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
