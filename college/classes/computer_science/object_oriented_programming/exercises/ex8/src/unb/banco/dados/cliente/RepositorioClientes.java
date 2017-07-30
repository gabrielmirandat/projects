package unb.banco.dados.cliente;

import unb.banco.cliente.Cliente;

public interface RepositorioClientes {

	Cliente[] getClientes();

	int getIndice();

	void atualizar(Cliente c) throws ClienteNaoExistenteException;

	boolean existe(String cpf);

	void inserir(Cliente c);

	Cliente procurar(String cpf) throws ClienteNaoExistenteException;

	void remover(String cpf) throws ClienteNaoExistenteException;

}