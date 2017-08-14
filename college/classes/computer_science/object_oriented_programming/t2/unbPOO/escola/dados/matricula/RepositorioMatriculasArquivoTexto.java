package unbPOO.escola.dados.matricula;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import unbPOO.escola.matricula.Matricula;

import unbPOO.escola.aluno.Aluno;
import unbPOO.escola.curso.Curso;

import unbPOO.escola.dados.aluno.AlunoNaoExistenteException;
import unbPOO.escola.dados.aluno.RepositorioAlunosArquivoTexto;

import unbPOO.escola.dados.curso.CursoNaoExistenteException;
import unbPOO.escola.dados.curso.RepositorioCursosArquivoTexto;


public class RepositorioMatriculasArquivoTexto implements RepositorioMatriculas {
	
	private static final int MAXMATRICULAS = 10000;
	private String nomeArquivo, nomeArquivoAuxiliar, nomeArquivoAluno, nomeArquivoCurso;
	private int numeroDeMatriculas;
	

	public RepositorioMatriculasArquivoTexto(String nomeArquivo, String nomeArquivoAluno, String nomeArquivoCurso) {
		this.nomeArquivo = nomeArquivo;
		this.nomeArquivoAluno = nomeArquivoAluno;
                this.nomeArquivoCurso = nomeArquivoCurso;
                
		nomeArquivoAuxiliar = nomeArquivo + ".bak";
		
		numeroDeMatriculas = 0;

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

	public Matricula[] getMatriculas() {
		Matricula[] matriculas = new Matricula[MAXMATRICULAS];
		int nMatriculas = 0;
		Matricula matricula = null;
		FileReader ir = null;
		BufferedReader br = null;
		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);

			// le o numero da matricula
			String linha = br.readLine();
			while (linha != null) {
				// le o cpf do cliente da conta
				String nomeAluno = br.readLine();
				// le o tipo da conta
				String codigo = br.readLine();
                        
				RepositorioAlunosArquivoTexto repAlunos = new RepositorioAlunosArquivoTexto(nomeArquivoAluno);
				Aluno aluno;
                                RepositorioCursosArquivoTexto repCursos = new RepositorioCursosArquivoTexto(nomeArquivoCurso);
				Curso curso;
				try {
					aluno = repAlunos.procurar(nomeAluno);
                                        curso = repCursos.procurar(codigo);
                                        matricula = new Matricula(aluno, curso);
					
					matriculas[nMatriculas] = matricula;
					nMatriculas = nMatriculas + 1;
				} catch (AlunoNaoExistenteException e) {
					// nao deveria acontecer devido a invariante do programa:
					// regra de negocio que diz que so se cadastra conta para
					// cliente cadastrado
					e.printStackTrace();
				}
                                catch (CursoNaoExistenteException e) {
					// nao deveria acontecer devido a invariante do programa:
					// regra de negocio que diz que so se cadastra conta para
					// cliente cadastrado
					e.printStackTrace();
				}
			   // le o numero da proxima matricula
				linha = br.readLine();
			}
            numeroDeMatriculas = nMatriculas;			
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
		return matriculas;
	}

	public int getIndice() {
		getMatriculas();
		return numeroDeMatriculas;
	}

	public void inserir(Matricula m) {
		/*
		 A convencao para escrita de cada matricula eh ter em linhas diferentes:   
		 1) numero da matricula; 2) nome do aluno; 3) codigo do curso; 
		  */
		FileWriter fout = null;
		BufferedWriter bw = null;
		try {
			// o segundo argumento indica que o arquivo eh aberto
			// para insercao de dados apos o fim do arquivo
			fout = new FileWriter(nomeArquivo, true);
			bw = new BufferedWriter(fout);
			bw.write(Integer.toString(m.getNumero()));
			bw.newLine();
			bw.write(m.getAluno().getNome());
			bw.newLine();
			bw.write(m.getCurso().getCodigo());
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
	
	public boolean existe(String nomeAluno, String codigo) {
		boolean resp = false;

		try {
			this.procurar(nomeAluno, codigo);
			resp = true;
		} catch (MatriculaNaoExistenteException e) {
			resp = false;
		}

		return resp;
	}

	public void atualizar(Matricula m) throws MatriculaNaoExistenteException {
		String numeroMatricula = new Integer(m.getNumero()).toString();
		FileReader ir = null;
		BufferedReader br = null;
		FileWriter fout = null;
		BufferedWriter bw = null;

		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);
			fout = new FileWriter(nomeArquivoAuxiliar);
			bw = new BufferedWriter(fout);
                        //le o numero da matricula
			String linha = br.readLine();
			while (linha != null && !linha.equals(numeroMatricula)) {
				// escreve no arquivo auxiliar o numero da matricula
				bw.write(linha);
				bw.newLine();
				// le o nome do aluno
				linha = br.readLine();
				// escreve no arquivo auxiliar o nome do aluno da matricula
				bw.write(linha);
				bw.newLine();
                                // le o codigo do curso
				linha = br.readLine();
				// escreve no arquivo auxiliar o codigo do curso da matricula
				bw.write(linha);
				bw.newLine();
						
				// le o numero da proxima matricula
				linha = br.readLine();
			}
			if (linha == null) {
				throw new MatriculaNaoExistenteException(m.getAluno().getNome(), m.getCurso().getCodigo());
			} else {
				// achou a matricula, entao escreve o numero da matricula no arq auxiliar
				bw.write(linha);
				bw.newLine();
				// pula  o nome do aluno
				linha = br.readLine();
				// escreve no arquivo auxiliar o novo nome do aluno
				bw.write(m.getAluno().getNome());
				bw.newLine();
				// pula o antigo codigo do curso
				linha = br.readLine();
				// escreve no arquivo auxiliar o codigo novo do curso
				bw.write(m.getCurso().getCodigo());
				bw.newLine();
											
				// o resto do arquivo auxiliar deve ser igual ao resto do
				// arquivo original
				// entao escrevemos o resto das matriculas no arquivo auxiliar
				linha = br.readLine();
				while (linha != null) {
					// escreve no arquivo auxiliar o valor lido (nome/codigo)
					bw.write(linha);
					bw.newLine();
					// le o nome/codigo das matriculas
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

	public Matricula procurar(String nomeAluno, String codigoCurso) throws MatriculaNaoExistenteException {
		/*
		 A convencao para escrita de cada matricula eh ter em linhas diferentes:   
		 1) numero da matricula; 2) nome do aluno; 3) codigo do curso; 
		  */
		
		Matricula matricula= null;
		FileReader ir = null;
		BufferedReader br = null;
                                
		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);

			// le o numero da matricula
			String linha = br.readLine();                        
                        
			while (linha != null) {
				// le o nome do aluno da matricula
				String nomeAlunolido = br.readLine();
				// le o codigo do curso da matricula
				String codigolido = br.readLine();
				// se forem os mesmos que estamos procurando, sai do laco
				if (nomeAlunolido.equals(nomeAluno) && codigolido.equals(codigoCurso)) {
					break;
				}
				// le o numero da proxima matricula
				linha = br.readLine();
			}
			if (linha == null) {
				throw new MatriculaNaoExistenteException(nomeAluno, codigoCurso);
			} else {
								
				RepositorioAlunosArquivoTexto repAlunos = new RepositorioAlunosArquivoTexto(nomeArquivoAluno);
                                RepositorioCursosArquivoTexto repCursos = new RepositorioCursosArquivoTexto(nomeArquivoCurso);
				Aluno aluno;
                                Curso curso;
				try {
					aluno = repAlunos.procurar(nomeAluno);
                                        curso = repCursos.procurar(codigoCurso);
                                        matricula = new Matricula(aluno, curso);
					
				} catch (AlunoNaoExistenteException e) {
					// nao deveria acontecer devido a invariante do programa:
					// regra de negocio que diz que so se cadastra conta para
					// cliente cadastrado
					e.printStackTrace();
				} catch (CursoNaoExistenteException e) {
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

		return matricula;
	}

	public void remover(String nomeAluno, String codigoCurso) throws MatriculaNaoExistenteException {
		FileReader ir = null;
		BufferedReader br = null;
		FileWriter fout = null;
		BufferedWriter bw = null;

		try {
			ir = new FileReader(nomeArquivo);
			br = new BufferedReader(ir);
			fout = new FileWriter(nomeArquivoAuxiliar);
			bw = new BufferedWriter(fout);
                        //le o numero da matricula
			String linha = br.readLine();
			while (linha != null) {
				
				// le o nome do aluno
				String nomeAlunoLido = br.readLine();
				
                                // le o codigo do curso
				String codigoCursoLido = br.readLine();
								
				if (nomeAlunoLido.equals(nomeAluno) && codigoCursoLido.equals(codigoCurso)) {
					break;
				}
                                // escreve no arquivo auxiliar o numero da matricula
				bw.write(linha);
				bw.newLine();
                                // escreve no arquivo auxiliar o nome do aluno
				bw.write(nomeAlunoLido);
				bw.newLine();
                                // escreve no arquivo auxiliar o codigo do curso
				bw.write(codigoCursoLido);
				bw.newLine();
				

				// le o numero da proxima matricula
				linha = br.readLine();
			}
			if (linha == null) {
				throw new MatriculaNaoExistenteException(nomeAluno, codigoCurso);
			} else {
				// achou a  conta, entao nao escreve nem numero da conta, nem o nome do aluno, nem o codigo do curso no arq auxiliar
								
				// o resto do arquivo auxiliar deve ser igual ao resto do
				// arquivo original
				// entao escrevemos o resto das contas no arquivo auxiliar
				linha = br.readLine();
				while (linha != null) {
					// escreve no arquivo auxiliar os valores lidos
					bw.write(linha);
					bw.newLine();
					// le os valores lidos
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
