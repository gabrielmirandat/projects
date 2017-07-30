package unb.banco.dados.cliente;

public class ClienteNaoExistenteException extends Exception {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public ClienteNaoExistenteException (String cpf) {
		super("Cliente inexistente " + cpf);
	}
}
