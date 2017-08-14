package unbPOO.escola.matricula;

public class MatriculaJaExistenteException extends Exception {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public MatriculaJaExistenteException (String nomeAluno, String codigoCurso) {	
	    super ("Matricula do aluno " + nomeAluno + "no curso" + codigoCurso + " ja existe. Nao pode ser cadastrada novamente.");
	}  
}
