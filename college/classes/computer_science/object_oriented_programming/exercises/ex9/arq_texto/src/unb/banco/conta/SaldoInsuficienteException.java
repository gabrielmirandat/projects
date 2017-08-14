package unb.banco.conta;

public class SaldoInsuficienteException extends Exception {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String numero;
	private double saldo;
	
	public SaldoInsuficienteException (double saldo, String numero) {
		super("Saldo Insuficiente: ");
		this.saldo = saldo;
		this.numero = numero;
	}

	public String getNumero() {
		return numero;
	}


	public double getSaldo() {
		return saldo;
	}

	

}
