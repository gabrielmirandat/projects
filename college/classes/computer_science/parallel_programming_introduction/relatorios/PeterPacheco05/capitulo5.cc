Collective Communication

Do exemplo anterior, vimos que o processo 0 fica muito sobrecarregado (Faz a maior parte do trabalho), 
isto não é desejável, queremos que eles trabalhem em conjunto (problema de I/O e soma ao final).

Se temos p processos, podemos distribuir dados de entrada em log2(p) em vez de p-1 estágios.
A ordem e quem envia pra quem não importa.

Broadcast: um manda pra todos. Mas vimos que é melhor mandar em árvore, mas depende da topologia.
int MPI_Bcast: in no root, out nos outros (message), bem mais rápido que o convencional - tem regras
			   sem tags.
			   Podem chegar na ordem errada.

Problema de buffer do sistema: deadlock

Também é possível distribuir cálculo da soma. Através de operações de redução.
int MPI_Reduce: soma ou outra op. em result. Não armazenar na mesma var. - problema de aliasing.
				resposta apenas no processo 0.

dot product com redução.

E se queremos que todos tenham a resposta? Redução com broadcast? Sim, mas eficiente.
É o AllReduce com butterfly.

int MPI_Allreduce

Produto matricial
Distribuição block-row ou panel, um panel pra cada processo.
A primeira coleção de sends é o gather.
A segunda é o scatter.
int MPI_Gatter: minerar
int MPI_Scatter: espalhar
int MPI_Allgather, já faz gather total.


http://alunosonline.uol.com.br/matematica/area-trapezio.html