package unb.banco.cliente;
import unb.banco.dados.cliente.RepositorioClientes;
import unb.banco.dados.cliente.RepositorioClientesArray;



public class ListaClientes {


		
		private RepositorioClientes clientes;
		private int indiceLista;
			
		public ListaClientes() {
			clientes = new RepositorioClientesArray();
			indiceLista = 0;
		}
		
		public boolean hasNext() {
			
			return  indiceLista < clientes.getIndice();
		}
		
		public Cliente next () {
			Cliente c = clientes.getClientes()[indiceLista];
			indiceLista = indiceLista + 1;
			return c;
		}
		
		public void insert (Cliente c) {
			clientes.inserir(c);
			
		}



}
