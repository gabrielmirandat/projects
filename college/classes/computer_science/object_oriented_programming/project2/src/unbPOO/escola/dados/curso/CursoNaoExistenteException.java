package unbPOO.escola.dados.curso;


public class CursoNaoExistenteException extends Exception{
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public CursoNaoExistenteException (String codigo) {
		super("Curso " + codigo + " nao existente");
	}
    
}
