package unbPOO.escola.dados.aluno;

import unbPOO.escola.aluno.Aluno;

public interface RepositorioAlunos {

	Aluno[] getAlunos();

	int getIndice();

	void atualizar(Aluno a) throws AlunoNaoExistenteException;

	boolean existe(String nome);

	void inserir(Aluno a);

	Aluno procurar(String nome) throws AlunoNaoExistenteException;
        
        //int procurarIndice(String nome) throws AlunoNaoExistenteException;

	void remover(String nome) throws AlunoNaoExistenteException;

}