package unb.banco.dados.conta;

public class ContaNaoExistenteException extends Exception {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public ContaNaoExistenteException (String numero) {
		super ("Conta inexistente " + numero);
	}
}
