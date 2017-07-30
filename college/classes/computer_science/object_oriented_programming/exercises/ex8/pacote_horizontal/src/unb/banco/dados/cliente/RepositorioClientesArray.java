package unb.banco.dados.cliente;

import unb.banco.cliente.Cliente;
import unb.banco.interfaceUsuario.*;

public class RepositorioClientesArray implements RepositorioClientes{
	private Cliente[]  clientes;
	private int indice;
	private final static int tamanhoCache = 100;

	public RepositorioClientesArray() {
	  indice = 0;
	  clientes = new Cliente[tamanhoCache];
	}
  
     /* (non-Javadoc)
	 * @see RepositorioClientes#getClientes()
	 */
    public Cliente [] getClientes () {
       return clientes;
     }

     /* (non-Javadoc)
	 * @see RepositorioClientes#getIndice()
	 */
    public int getIndice() {
       return indice;
     }

	/* (non-Javadoc)
	 * @see RepositorioClientes#atualizar(Cliente)
	 */
	public void atualizar(Cliente c) throws ClienteNaoExistenteException{
	  int i = procurarIndice(c.getCpf());
	  clientes[i] = c;
	}
	/* (non-Javadoc)
	 * @see RepositorioClientes#existe(java.lang.String)
	 */
	public boolean existe(String cpf) {
		boolean resp = false;

		try {
			this.procurarIndice(cpf);
			resp = true;
		} catch (ClienteNaoExistenteException e) {
			resp = false;
		}

		return resp;
	}
	/* (non-Javadoc)
	 * @see RepositorioClientes#inserir(Cliente)
	 */
	public void inserir(Cliente c){
	    clientes[indice] = c;
	    indice = indice + 1;
	}
	/* (non-Javadoc)
	 * @see RepositorioClientes#procurar(java.lang.String)
	 */
	public Cliente procurar(String cpf) throws ClienteNaoExistenteException {
	  Cliente c = null;
	  int i = this.procurarIndice(cpf);
	  c = clientes[i];
	  return c;
	}

	private int procurarIndice(String cpf) throws ClienteNaoExistenteException {
	  int     i = 0;
	  int     ind = -1;
	  boolean achou = false;

	  while ((i < indice) &&!achou) {
	    if ((clientes[i].getCpf()).equals(cpf)) {
	    	ind = i;
	    	achou = true;
	    }
	    i = i + 1;
	  }
	  if (!achou)
		  throw new ClienteNaoExistenteException(cpf);
	  return ind;
	}

	/* (non-Javadoc)
	 * @see RepositorioClientes#remover(java.lang.String)
	 */
	public void remover(String cpf) throws ClienteNaoExistenteException{

  	    int i = this.procurarIndice(cpf);
	    clientes[i] = clientes[indice - 1];
	    clientes[indice - 1] = null;
	    indice = indice - 1;
	  
	}
}