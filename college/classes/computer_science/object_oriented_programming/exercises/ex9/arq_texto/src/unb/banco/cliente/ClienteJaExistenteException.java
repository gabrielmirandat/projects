package unb.banco.cliente;

public class ClienteJaExistenteException extends Exception {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public ClienteJaExistenteException (String cpf) {
	 super ("Cliente " +cpf + " ja existe. Nao pode ser cadastrado novamente.");
	}
}
