/* Modificada send_row.c -- send third row of a matrix from process 1 to process 0
 * 
 * Input: none
 * Output: the row received by process 0
 *
 * Note:  Program should only be run with 2 processes
 *
 * See Chap 6, p. 96 in PPMPI
 */

// P/ compilar
// mpicc pa1b_send_row.c -o pa1b_send_row
#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[]) {
    int p;
    int my_rank;
    float A[10][10];
    MPI_Status status;
    int i, j;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    if (my_rank == 1) {
        for (i = 0; i < 10; i++)
            for (j = 0; j < 10; j++)
                A[i][j] = (float) i;
        MPI_Send(&(A[2][0]), 10, MPI_FLOAT, 1, 0,
            MPI_COMM_WORLD);
    } else { /* my_rank = 0 */
        MPI_Recv(&(A[2][0]), 10, MPI_FLOAT, 0, 0,
            MPI_COMM_WORLD, &status);
        for (j = 0; j < 10; j++)
            printf("%3.1f ", A[2][j]);
        printf("\n");
    }

    MPI_Finalize();

    return 0;
}  /* main */
