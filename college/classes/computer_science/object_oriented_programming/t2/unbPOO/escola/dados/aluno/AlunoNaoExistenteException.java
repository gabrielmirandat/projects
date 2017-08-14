package unbPOO.escola.dados.aluno;


public class AlunoNaoExistenteException extends Exception {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public AlunoNaoExistenteException (String nome) {
		super("Aluno " + nome + " nao existente.");
	}
    
}
