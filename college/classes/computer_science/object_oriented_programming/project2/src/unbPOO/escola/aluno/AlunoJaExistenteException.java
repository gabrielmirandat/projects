
package unbPOO.escola.aluno;


public class AlunoJaExistenteException extends Exception {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public AlunoJaExistenteException (String nome) {
	 super ("Aluno(a) " +nome + " ja existe. Nao pode ser cadastrado novamente.");
	}
    
}
