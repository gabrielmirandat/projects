public class Teste {
     public static final int CONST = 23478; 
	public static void main(String[] args) {
		//CONST = 2;
		Cliente cli1 = new Cliente( "123456789-00", "Sandro");
	        Cliente cli2 = new Cliente( "123456777-22", "Jose");
		
		Conta c1 = new Conta("1", cli1);
		Conta c2 = new Conta("2", cli2);
		
		c2.setSaldo(100);
		
		System.out.println("saldo da conta "+c1.getNumero() +": "+c1.getSaldo());
		System.out.println("saldo da conta "+c2.getNumero() +": "+c2.getSaldo());
 
               c2.creditar(100);		
                System.out.println("saldo da conta "+c1.getNumero() +": "+c1.getSaldo());
		System.out.println("saldo da conta "+c2.getNumero() +": "+c2.getSaldo());
 
	       c2.debitar(50);

		System.out.println("saldo da conta "+c1.getNumero() +": "+c1.getSaldo());
		System.out.println("saldo da conta "+c2.getNumero()+": "+c2.getSaldo());

                c2.transferir(c1, 50);

                System.out.println("saldo da conta "+c1.getNumero()+": "+c1.getSaldo());
		System.out.println("saldo da conta "+c2.getNumero()+": "+c2.getSaldo());

		c1.transferir(c2, 100);

		System.out.println("saldo da conta "+c1.getNumero() +": "+c1.getSaldo());
		System.out.println("saldo da conta "+c2.getNumero() +": "+c2.getSaldo());
                
                Cliente cliente_aux1 = c1.getCliente();
                System.out.println("dados do cliente da conta 1: " + "Nome: " + cliente_aux1.getNome() + "    CPF: " +  cliente_aux1.getCpf());

                Cliente cliente_aux2 = c2.getCliente();
                System.out.println("dados do cliente da conta 2: " + "Nome: " + cliente_aux2.getNome()  + "    CPF: " +  cliente_aux2.getCpf());

		
	}
}
