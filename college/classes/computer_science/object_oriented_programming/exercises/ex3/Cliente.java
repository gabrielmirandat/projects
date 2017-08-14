public class Cliente
{
  private String nome;
  private int cpf;
  
  public Cliente(){
  }
  
  public Cliente(String nome_cliente, int cpf_cliente){
    this.nome = nome_cliente;
    this.cpf = cpf_cliente;
  }
  
  public String getNome(){
    return this.nome;
  }

  public void setNome(String novo){
    this.nome = novo;
  }
  
  public int getCPF(){
    return this.cpf;
  }
  
  public void setCPF(int novo){
    this.cpf = novo;
  }






}