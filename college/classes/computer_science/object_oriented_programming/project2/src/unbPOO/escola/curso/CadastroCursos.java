package unbPOO.escola.curso;

import unbPOO.escola.dados.curso.CursoNaoExistenteException;
import unbPOO.escola.dados.curso.RepositorioCursos;


// coleção de negócio para o repositório de cursos
public class CadastroCursos {
// declaracao de atributos
	private RepositorioCursos cursos;
// construtor da classe
	public CadastroCursos(RepositorioCursos r) {
		this.cursos = r;
	}
//metodos public a serem usados na fachada
        // metodo para atualizar curso c 
	public void atualizar(Curso c) throws CursoNaoExistenteException{
		 Curso cur = cursos.procurar(c.getCodigo());// alu recebe o aluno do vetor alunos cujo nome é o nome do Aluno a
		 
			 cur.setNome(c.getNome());
			 cur.setInstrutor(c.getInstrutor());
			 cursos.atualizar(cur);
		 
	}
// metodo para cadastrar curso c
	public void cadastrar(Curso c) throws CursoJaExistenteException{
		if (!cursos.existe(c.getCodigo())) {
			cursos.inserir(c);
		} else {
			throw new CursoJaExistenteException(c.getCodigo());
		}
	}
// metodo para descadastrar curso de codigo c
	public void descadastrar(String c) throws CursoNaoExistenteException {
		cursos.remover(c);
	}
// metodo para procurar curso de codigo c
	public Curso procurar(String c) throws CursoNaoExistenteException {
		return cursos.procurar(c);
	}
// metodo que retorna a lista de cursos
	public ListaCursos listaCursos() {

		Curso[] cursos = null;// cria vetor
		Curso curso = null;
		cursos = this.cursos.getCursos();
		int numeroCursos = this.cursos.getIndice();//pega o ultimo indice do vetor
		ListaCursos lc = new ListaCursos();//construtor de lista
		for (int i = 0; i < numeroCursos; i++) {// laço para inserir na lista os cursos do vetor
			curso = cursos[i];
			lc.insert(curso);
		}
		return lc;

	}

}
