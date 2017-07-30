public class RepositorioClientesArray {
	private Cliente[] clientes;
	private int indice;
	public final static int tamCache = 100;

	public RepositorioClientesArray() {
		 indice = 0;
		 clientes = new Cliente[tamCache];
	}

	public Cliente[] getClientes(){
		return this.clientes;
	}

	public void setClientes(Cliente[] clientes){
		this.clientes = clientes;
	}

	public int getIndice(){
		return this.indice;
	}

	public void setIndice(int indice){
		this.indice = indice;
	}

	public void inserir(Cliente c){
		 clientes[indice] = c;
		 indice = indice + 1;
	}

	private int procurarIndice(String cpf) {
		 int i = 0;
		 int ind = -1;
		 boolean achou = false;
		 while ((i < indice) && !achou) {
			 if ((clientes[i].getCpf()).equals(cpf)) {
				 ind = i;
				 achou = true;
			 }
			 i = i + 1;
		 }
		 return ind;
	}

	public boolean existe(String cpf) {
		 boolean resp = false;
		 int i = this.procurarIndice(cpf);
		 if(i != -1){
			resp = true;
		 }
		 return resp;
	}

	public Cliente procurar(String cpf){
	    Cliente c = null;
	    if (existe(cpf)) {
			 int i = this.procurarIndice(cpf);
			 c = clientes[i];
		} else {
			 System.out.println("Cliente nao encontrada");
	    }
		return c;
	}

	public void atualizar(Cliente c){
		 int i = procurarIndice(c.getCpf());
		 if (i != -1) {
			 clientes[i] = c;
		} else {
			 System.out.println("Cliente nao encontrada");
		 }
	}

	public void remover(String cpf){
		 if (existe(cpf)) {
			int i = this.procurarIndice(cpf);
		    clientes[i] = clientes[indice - 1];
			clientes[indice - 1] = null;
			indice = indice - 1;
		 }else {
			System.out.println("Cliente nao encontrado");
		 }
	}
}
