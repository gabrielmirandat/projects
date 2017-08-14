// mpicc ex3.c -o ex3
// mpiexec -n 4 ex3, onde -n representa o número de processos criados
// count, datatype, source, dest
// int MPI_Send( buf, count, datatype, dest, tag, comm )
// int MPI_Recv( buf, count, datatype, source, tag, comm, status )

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

    if (my_rank != 0) {
        /* Create message */
        sprintf(message, "Greetings from process %d!",
            my_rank);
        dest = 0;
        /* Use strlen+1 so that '\0' gets transmitted */
        
        /* 
        int MPI_Send( buf, count, datatype, dest, tag, comm )
        MPI_Send(message, strlen(message)+1, MPI_CHAR, dest, tag, MPI_COMM_WORLD); 
        */

        // MPI_Send(message, 8, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
        // MPI_Send(message, strlen(message)+1, MPI_INT, dest, tag, MPI_COMM_WORLD);
        MPI_Send(message, strlen(message)+1, MPI_CHAR, 1, tag, MPI_COMM_WORLD);
    
    } else { /* my_rank == 0 */
        for (source = 1; source < p; source++) {
            /* 
            int MPI_Recv( buf, count, datatype, source, tag, comm, status )
            MPI_Recv(message, 100, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status); 
            */

            // MPI_Recv(message, 4, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);
            // MPI_Recv(message, 100, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);
            MPI_Recv(message, 100, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
            


            printf("%s\n", message);
        }
    }

    /* Shut down MPI */
    MPI_Finalize();
} /* main */
