package unb.banco.dados.cliente;

public class ClienteNaoExistenteException extends Exception {
	public ClienteNaoExistenteException (String cpf) {
		super("Cliente inexistente " + cpf);
	}
}
