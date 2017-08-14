package unb.banco.conta;

public class ContaJaExistenteException extends Exception {
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public ContaJaExistenteException (String numero) {
	
	    super ("Conta " +  numero + " ja existe. Nao pode ser cadastrada novamente.");
	}

}
