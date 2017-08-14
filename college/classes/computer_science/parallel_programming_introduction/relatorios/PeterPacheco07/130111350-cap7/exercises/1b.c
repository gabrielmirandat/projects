/* Modified comm_split.c -- build a collection of q communicators using MPI_Comm_split
 *
 * Input: none
 * Output:  Results of doing a broadcast across each of the q communicators.
 *     
 * Note:  Assumes the number of processes, p = q^2
 *
 * See Chap. 7, pp. 120 & ff in PPMPI
 */

#include <stdio.h>
#include "mpi.h"
#include <math.h>

int main(int argc, char* argv[]) {
    int       p;
    int       my_rank;
    MPI_Comm  my_col_comm;
    int       my_col;
    int       q;
    int       test;
    int       my_rank_in_col;

    MPI_Init(&argc, &argv);
    // pega n de processos no comm global
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    // pega rank do processo atual
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    // pega lado da malha em q
    q = (int) sqrt((double) p);

    /* my_rank is rank in MPI_COMM_WORLD.
     * q*q = p */
    my_col = my_rank%q;
    MPI_Comm_split(MPI_COMM_WORLD, my_col, my_rank, &my_col_comm);

    /* Test the new communicators */
    MPI_Comm_rank(my_col_comm, &my_rank_in_col);
    
    if (my_rank_in_col == 0)
        test = my_col;
    else
        test = 0;

    MPI_Bcast(&test, 1, MPI_INT, 0, my_col_comm);

    printf("Process %d > my_col = %d, my_rank_in_col = %d, test = %d\n", my_rank, my_col, my_rank_in_col, test);

    MPI_Finalize();

    return 0;
}  /* main */

// exemplo malha 4x4
// 0  1  2  3
// 4  5  6  7
// 8  9  10 11
// 12 13 14 15