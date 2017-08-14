package unb.banco.dados.conta;

import unb.banco.conta.Conta;

public interface RepositorioContas {

	Conta[] getContas();

	int getIndice();

	void inserir(Conta c);

	boolean existe(String num);

	void atualizar(Conta c) throws ContaNaoExistenteException;

	Conta procurar (String num) throws ContaNaoExistenteException;

	void remover(String num) throws ContaNaoExistenteException;

}
