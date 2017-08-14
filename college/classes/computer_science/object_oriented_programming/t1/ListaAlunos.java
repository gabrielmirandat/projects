public class ListaAlunos {


		
		private RepositorioAlunosArray alunos;
		private int indiceLista;
			
		public ListaAlunos() {
			alunos = new RepositorioAlunosArray();
			setIndiceLista(0);
		}
		
		public boolean hasNext() {
			
			return  getIndiceLista() < alunos.getIndice();
		}
		
		public Aluno next () {
			Aluno alu = alunos.getAlunos()[getIndiceLista()];
			setIndiceLista(getIndiceLista() + 1);
			return alu;
		}
		
		public void insert (Aluno alu) {
			alunos.inserir(alu);
			
		}


		public int getIndiceLista() {
			return indiceLista;
		}


		public void setIndiceLista(int indiceLista) {
			this.indiceLista = indiceLista;
		}



}
