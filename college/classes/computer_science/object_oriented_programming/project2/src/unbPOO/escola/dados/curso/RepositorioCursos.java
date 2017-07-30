package unbPOO.escola.dados.curso;

import unbPOO.escola.curso.Curso;

public interface RepositorioCursos {

	Curso[] getCursos();

	int getIndice();

	void atualizar(Curso c) throws CursoNaoExistenteException;

	boolean existe(String codigo);

	void inserir(Curso c);

	Curso procurar(String codigo) throws CursoNaoExistenteException;
        
        //int procurarIndice(String codigo) throws CursoNaoExistenteException;

	void remover(String codigo) throws CursoNaoExistenteException;

}