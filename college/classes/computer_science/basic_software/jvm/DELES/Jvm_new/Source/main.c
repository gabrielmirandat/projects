#include "interpreter.h"

int main(int argc, char **argv) {
	char *nomeDoArquivoDeClasse = argv[1];
	int num_args = argc-2;
	char **offset = argv+2;

	if(argc == 1)
		printf("Uso:\tWIN: Cruzeiro.exe NomeDaClasse.class "
				   "t||a\n\tLINUX: ./Cruzeiro NomeDaClasse.class t||a\n");		
	else if(argc == 2)
		iniciar_jvm(nomeDoArquivoDeClasse, num_args, NULL);
	else
		iniciar_jvm(nomeDoArquivoDeClasse, num_args, offset);
	return 0;
}
