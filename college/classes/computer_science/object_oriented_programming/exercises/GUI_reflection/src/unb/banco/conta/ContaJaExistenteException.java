package unb.banco.conta;

public class ContaJaExistenteException extends Exception {
	
	public ContaJaExistenteException (String numero) {
	
	    super ("Conta " +  numero + " ja existe. Nao pode ser cadastrada novamente.");
	}

}
