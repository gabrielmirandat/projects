package unb.banco.cliente;

public class ClienteJaExistenteException extends Exception {

	public ClienteJaExistenteException (String cpf) {
	 super ("Cliente " +cpf + " ja existe. Nao pode ser cadastrado novamente.");
	}
}
