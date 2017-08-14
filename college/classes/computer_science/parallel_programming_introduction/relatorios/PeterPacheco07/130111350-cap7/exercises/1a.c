/* Modified comm_create.c -- builds a communicator from the first q processes
 *     in a communicator containing p = q^2 processes.
 *
 * Input: none
 * Output: q -- program tests correct creation of new communicator
 *     by broadcasting the value 1 to its members -- all other 
 *     processes have the value 0 -- global sum computed across
 *     all the processes.
 *
 * Note:  Assumes that MPI_COMM_WORLD contains p = q^2 processes
 *
 * See Chap 7, pp. 117 & ff in PPMPI
 */

// Execute script.sh para compilar e rodar

#include <stdio.h>
#include "mpi.h"
#include <math.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int        p;
    int        q; /* = sqrt(p) */
    int        my_rank;
    MPI_Group  group_world;
    MPI_Group  first_col_group;
    MPI_Comm   first_col_comm;
    int*       process_ranks;
    int        proc;
    int        test = 0;
    int        sum;
    int        my_rank_in_first_col;


    MPI_Init(&argc, &argv);
    // pega a qtd de processos no comunicador
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    // pega rank do processo atual
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    // como eh uma malha virtual, a raiz dá um lado da malha
    q = (int) sqrt((double) p);

    /* Make a list of the processes in the new communicator*/
    // Aloca memória para os ranks do processo pertencente ao novo comunicador
    process_ranks = (int*) malloc(q*sizeof(int));
    // associa ranks aos processos. {0,n,2n,...}
    int counter=0;
    for (proc = 0; proc < (q*q)-1; proc+=q)
    {
        process_ranks[counter] = proc;
        counter++;
    }

    /* Get the group underlying MPI_COMM_WORLD */
    // pega o grupo pertencente ao MPI_COMM_WORLD
    // e armazena em group_world
    MPI_Comm_group(MPI_COMM_WORLD, &group_world);

    /* Create the new group */
    // cria novo grupo, sendo o antigo group_world e o novo first_col_group,
    // com os ranks associados
    MPI_Group_incl(group_world, q, process_ranks, &first_col_group);

    /* Create the new communicator */
    // cria novo comunicador com novo grupo, first_col_comm
    MPI_Comm_create(MPI_COMM_WORLD, first_col_group, &first_col_comm);

    /* Now check whether we can do collective ops in first_col_comm */
    if (my_rank%q==0 && my_rank < (q*q)-1) {
        MPI_Comm_rank(first_col_comm, &my_rank_in_first_col);
        if (my_rank_in_first_col == 0)
        {
        	test = 1;
        }
        MPI_Bcast(&test, 1, MPI_INT, 0, first_col_comm);
    }
    
    MPI_Reduce(&test, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (my_rank == 0) {
        printf("q = %d, sum = %d\n", q, sum);
    }

    MPI_Finalize();
    return 0;
}  /* main */

// exemplo malha 4x4
// 0  1  2  3
// 4  5  6  7
// 8  9  10 11
// 12 13 14 15