public class ListaCursos {


		
		private RepositorioCursosArray cursos;
		private int indiceCurso;
			
		public ListaCursos() {
			cursos = new RepositorioCursosArray();
			setIndiceCurso(0);
		}
		
		public boolean hasNext() {
			
			return  getIndiceCurso() < cursos.getIndice();
		}
		
		public Curso next () {
			Curso cur = cursos.getCursos()[getIndiceCurso()];
			setIndiceCurso(getIndiceCurso() + 1);
			return cur;
		}
		
		public void insert (Curso cur) {
			cursos.inserir(cur);
			
		}

		public int getIndiceCurso() {
			return indiceCurso;
		}

		public void setIndiceCurso(int indiceCurso) {
			this.indiceCurso = indiceCurso;
		}



}
