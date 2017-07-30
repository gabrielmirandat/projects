package  unbPOO.escola.aluno;

public class Aluno {

    private String nome;

    private String endereco;

    private String telefone;

    private int idade;



	public Aluno(String nome, String endereco, String telefone,int idade) {

	        this.nome = nome;
        	this.endereco = endereco;
        	this.telefone = telefone;
        	this.idade = idade;
    }


	public String getNome() {
		return nome;
	}


	public String getEndereco() {
		return endereco;
	}

	public String getTelefone() {
		return telefone;
	}

	public int getIdade() {
		return idade;
	}


	public void setNome(String nome) {
		this.nome = nome;
	}


	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}

	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}

	public void setIdade(int idade) {
		this.idade = idade;
	}

}
