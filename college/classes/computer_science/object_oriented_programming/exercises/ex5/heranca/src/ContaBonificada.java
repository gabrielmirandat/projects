
public class ContaBonificada extends Conta{
	private double bonus;
	
	public ContaBonificada(String numero, Cliente cliente){
		super(numero, cliente);
	}
	
	public void creditar (double valor) {
		 bonus = bonus + (valor * 0.01);
		 super.creditar(valor);
	}
	
	public void renderBonus() {
		super.creditar(bonus);
		bonus = 0;
	}
	
		 
	public double getBonus() {
		return bonus;
	}
}