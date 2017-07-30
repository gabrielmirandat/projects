package unb.banco.conta;

import unb.banco.cliente.Cliente;


public class Conta {

    private String numero;

    private double saldo;

    private Cliente cliente;

    public Conta(String numero, double saldo, Cliente cliente) {
            this.numero = numero;
            this.saldo = saldo;
            this.cliente = cliente;
	}


     public Conta(String numero, Cliente cliente) {

            this(numero, 0.0, cliente);	

         //  this.numero = numero;
         //  this.saldo = 0.0;
         //  this.cliente = cliente;

        
	}


	public Cliente getCliente() {
		return cliente;
	}


	public String getNumero() {
		return numero;
	}


	public double getSaldo() {
		return saldo;
	}


	public void setCliente(Cliente cliente) {
		this.cliente = cliente;
	}


	public void setNumero(String string) {
		numero = string;
	}


	public void setSaldo(double d) {
		saldo = d;
	}

	public void creditar(double valor) {
		this.saldo = this.saldo + valor;
	}


	public void debitar(double valor) throws SaldoInsuficienteException {
			if (valor <= saldo) {
				saldo = saldo - valor;
			} else {
				throw new SaldoInsuficienteException(saldo, numero);
			}
	}

	public void transferir(Conta c, double v) throws SaldoInsuficienteException{
		    this.debitar(v);
		    c.creditar(v);
		
		
		

	}

}

