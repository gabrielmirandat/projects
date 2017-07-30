public class Teste{

  public static void main(String[] args){
      Conta conta1 = new Conta();
      Conta conta2 = new Conta();
      
      Cliente cliente1 = new Cliente("Jose", 123456);
      Cliente cliente2 = new Cliente("Maria",987654);
      
      conta1.setSaldo(100);
      conta2.setSaldo(0);
      
      System.out.println("Saldo da conta1: "+conta1.getSaldo());
      System.out.println("Saldo da conta2: "+conta2.getSaldo());
      
      conta1.creditar(10);
      conta2.debitar(10);

      System.out.println("Saldo da conta1: "+conta1.getSaldo());
      System.out.println("Saldo da conta2: "+conta2.getSaldo());
  
      conta1.setCliente(cliente1);
      conta2.setCliente(cliente2);
      
      conta1.transferir(conta2, 100);
      
      System.out.println("\nProprietário da conta 1: ");
      System.out.println(conta1.getCliente().getNome());
      System.out.println(conta1.getCliente().getCPF());
      System.out.println("Saldo da conta1: "+conta1.getSaldo());
      
      System.out.println("\nProprietário da conta 2: ");
      System.out.println(conta2.getCliente().getNome());
      System.out.println(conta2.getCliente().getCPF());
      System.out.println("Saldo da conta2: "+conta2.getSaldo());
      
      conta1.transferir(conta2, 100);
      
      System.out.println("\nProprietário da conta 1: ");
      System.out.println(conta1.getCliente().getNome());
      System.out.println(conta1.getCliente().getCPF());
      System.out.println("Saldo da conta1: "+conta1.getSaldo());
      
      System.out.println("\nProprietário da conta 2: ");
      System.out.println(conta2.getCliente().getNome());
      System.out.println(conta2.getCliente().getCPF());
      System.out.println("Saldo da conta2: "+conta2.getSaldo());
  
  }
}