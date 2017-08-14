public class Conta
{
  private short numero;
  private double saldo;
  private Cliente cliente;
  
  public Conta(){
  }
  
  public Conta(short numero , Cliente cliente){
    this.numero = numero;
    this.cliente = cliente;
  }
  
  public Conta(short numero , Cliente cliente, double saldo){
    this.numero = numero;
    this.cliente = cliente;
    this.saldo = saldo;
  }
  
  public short getNumero(){
    return this.numero;
  }

  public void setNumero(short numero){
    this.numero = numero;
  }
  
  public double getSaldo(){
    return this.saldo;
  }
  
  public void setSaldo(double saldo){
    this.saldo = saldo;
  }

  public Cliente getCliente(){
    return this.cliente;
  }
  
  public void setCliente(Cliente cliente){
    this.cliente = cliente;
  }
  
  public void creditar(double credito){
      this.saldo = this.saldo + credito;
  }
  
  public boolean debitar(double debito){
      if(this.saldo>=debito){
	this.saldo = this.saldo - debito;
	return true;
      }else{
	System.out.println("\nImpossível debitar este valor. Operação não finalizada.");
	return false;
      }
  }
  
  public void transferir(Conta conta, double transferido){
      if(this.debitar(transferido)==true){
	conta.creditar(transferido);
      }else{
	System.out.println("\nTransferência não finalizada.");
      }
  }
}