public class Matricula {
	private Aluno aluno;
	private Curso curso;
	private final int  numero;
	private static int auxiliar=9999;
	
	public Matricula(Aluno aluno, Curso curso){
		this.aluno = aluno;
		this.curso = curso;
		setaNumero();
		numero = auxiliar;
	}

	public Aluno getAluno(){
		return this.aluno;
	}
	
	public Curso getCurso(){
		return this.curso;
	}
	
	public int getNumero(){
		return numero;
	}

	private static void setaNumero(){
		auxiliar = auxiliar + 1;
	}
}
