// mpicc assig1.c -o assig1
// mpiexec -n 4 assig1, onde -n representa o número de processos criados

#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int         my_rank;       /* rank of process      */
    int         p;             /* number of processes  */
    int         source;        /* rank of sender       */
    int         dest;          /* rank of receiver     */
    int         tag = 0;       /* tag for messages     */
    char        message[100];  /* storage for message  */
    MPI_Status  status;        /* return status for    */
                               /* receive              */

    /* Start up MPI */
    MPI_Init(&argc, &argv);

    /* Find out process rank  */
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    /* Find out number of processes */
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    // se p=4, 0->1, 1->2, 2->3, 3->0
    // 0 recebe de 3, 3 recebe de 2, 2 recebe de 1, 1 recebe de 0

    dest = (my_rank+1)%p;

    if(my_rank==0) source = p-1;
    else source = my_rank-1;
    
    /* Create message */
    sprintf(message, "Greetings from process %d!", my_rank);
    /* Use strlen+1 so that '\0' gets transmitted */
    MPI_Send(message, strlen(message)+1, MPI_CHAR, dest , tag, MPI_COMM_WORLD);
    MPI_Recv(message, 100, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);

    printf("%s\n", message);
    //printf("%d\n", my_rank);
    
    /* Shut down MPI */
    MPI_Finalize();
} /* main */
