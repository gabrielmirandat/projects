public class Curso {

    private String codigo;

    private String nome;

    private String instrutor;

    public Curso(String codigo, String nome, String instrutor) {
            this.codigo = codigo;
            this.nome = nome;
            this.instrutor = instrutor;
	}

	public String getCodigo() {
		return codigo;
	}


	public String getNome() {
		return nome;
	}


	public String getInstrutor() {
		return instrutor;
	}


	public void setCodigo(String codigo) {
		this.codigo = codigo;
	}


	public void setNome(String nome) {
		this.nome = nome;
	}


	public void setInstrutor(String instrutor) {
		this.instrutor = instrutor;
	}
}

