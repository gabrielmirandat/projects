package unbPOO.escola.curso;


public class CursoJaExistenteException extends Exception {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public CursoJaExistenteException (String codigo) {
	 super ("Curso " +codigo + " ja existe. Nao pode ser cadastrado novamente.");
	}
    
}
