public interface RepositorioClientes {

	Cliente[] getClientes();

	int getIndice();

	void atualizar(Cliente c);

	boolean existe(String cpf);

	void inserir(Cliente c);

	Cliente procurar(String cpf);

	void remover(String cpf);

}