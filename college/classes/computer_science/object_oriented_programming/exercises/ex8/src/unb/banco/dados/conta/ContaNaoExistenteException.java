package unb.banco.dados.conta;

public class ContaNaoExistenteException extends Exception {

	public ContaNaoExistenteException (String numero) {
		super ("Conta inexistente " + numero);
	}
}
