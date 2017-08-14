public class RepositorioContasArray {
	private Conta[] contas;
	private int indice;
	private final static int tamCache = 100;

	public RepositorioContasArray() {
		 indice = 0;
		 contas = new Conta[tamCache];
	}

	public Conta[] getContas(){
		return this.contas;
	}

	public void setContas(Conta[] _contas){
		this.contas = _contas;
	}

	public int getIndice(){
		return this.indice;
	}

	public void setIndice(int indice){
		this.indice = indice;
	}

	public void inserir(Conta c){
		 contas[indice] = c;
		 indice = indice + 1;
	}

	private int procurarIndice(String num) {
		 int i = 0;
		 int ind = -1;
		 boolean achou = false;
		 while ((i < indice) && !achou) {
			 if ((contas[i].getNumero()).equals(num)) {
				 ind = i;
				 achou = true;
			 }
			 i = i + 1;
		 }
		 return ind;
	}

	public boolean existe(String num) {
		 boolean resp = false;
		 int i = this.procurarIndice(num);
		 if(i != -1){
			resp = true;
		 }
		 return resp;
	}

	public void atualizar(Conta c){
		 int i = procurarIndice(c.getNumero());
		 if (i != -1) {
			 contas[i] = c;
		} else {
			 System.out.println("Conta nao encontrada");
		 }
	}

	public Conta procurar(String num){
	    Conta c = null;
	    if (existe(num)) {
			 int i = this.procurarIndice(num);
			 c = contas[i];
		} else {
			 System.out.println("Conta nao encontrada");
	    }
		return c;
	}

	public void remover(String num){
		 if (existe(num)) {
			int i = this.procurarIndice(num);
		    contas[i] = contas[indice - 1];
			contas[indice - 1] = null;
			indice = indice - 1;
		 }else {
			System.out.println("Conta nao encontrada");
		 }
	}
}
