package  unbPOO.escola.matricula;

import unbPOO.escola.aluno.Aluno;
import unbPOO.escola.curso.Curso;

// classe basica Matricula
public class Matricula {
    
    // declaracao de atributos
    private Aluno aluno;
    private Curso curso;
    private final int numero;
    
    // atributo estatico contador a ser incrementado para dar o numero de matricula; é igual -1 para que  primeira matricula seja 0
    static int CONT = -1;
    
    // construtor da classe Matricula (nao tem como parametro numero, pois esse sera dado pelo incremento do CONT)
    public Matricula(Aluno aluno, Curso curso) {
            this.aluno = aluno;
            this.curso = curso;
            this.numero = gerarNumero();
	}
     
    // metodo estatico para gerar numero de matricula, incrementando CONT
	public static int gerarNumero() {
		CONT++;
		return CONT;
	}
        //metodos public para retornar atributos
	public Aluno getAluno() {
		return aluno;
	}
	public Curso getCurso() {
		return curso;
	}
	public int getNumero() {
		return numero;
	}
        // metodos public para atualizar atributos; não há um para o numero porque ele é constante
	public void setAluno(Aluno aluno) {
		this.aluno = aluno;
	}
	public void setCurso(Curso curso) {
		this.curso = curso;
	}
		
}