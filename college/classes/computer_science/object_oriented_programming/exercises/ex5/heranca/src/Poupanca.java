
public class Poupanca extends Conta {

	public Poupanca(String numero, double saldo, Cliente cliente) {
		super(numero, saldo, cliente);
		
	}	
	
	public Poupanca(String numero, Cliente cliente){
		super(numero, cliente);
	}
	
	public void renderJuros(double taxa) {
		double saldoAtual = getSaldo();
		super.creditar(saldoAtual * taxa);
	}
}
