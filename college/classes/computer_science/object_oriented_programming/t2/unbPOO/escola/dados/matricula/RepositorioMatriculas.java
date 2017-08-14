package unbPOO.escola.dados.matricula;

import unbPOO.escola.matricula.Matricula;

public interface RepositorioMatriculas {

	Matricula[] getMatriculas();

	int getIndice();

	void atualizar(Matricula m) throws MatriculaNaoExistenteException;

	boolean  existe(String nomeAluno, String codigocurso);

	void inserir(Matricula m);

	Matricula procurar(String nomeAluno, String codigoCurso) throws MatriculaNaoExistenteException;
        
       // int procurarIndice(String nomealuno, String codigocurso) throws MatriculaNaoExistenteException;

	public void remover(String nomeAluno, String codigoCurso) throws MatriculaNaoExistenteException;

}