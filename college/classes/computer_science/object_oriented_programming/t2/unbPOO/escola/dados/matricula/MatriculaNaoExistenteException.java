package unbPOO.escola.dados.matricula;

public class MatriculaNaoExistenteException extends Exception {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public MatriculaNaoExistenteException (String nomeAluno, String codigoCurso) {	
	    super ("Matricula do aluno " + nomeAluno + " no curso" + codigoCurso + "nao existe");
	}  
    
}
