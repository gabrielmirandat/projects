package unb.banco.dados.conta;

import unb.banco.conta.Conta;

public interface RepositorioContas {

	Conta[] getContas();

	int getIndice();

	void inserir(Conta c);

	boolean existe(String num);

	int atualizar(Conta c);

	Conta procurar(String num);

	int remover(String num);

}
