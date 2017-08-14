/* Modificada get_data4.c -- Parallel Trapezoidal Rule.  Uses MPI_Pack/Unpack in
 *     distribution of input data.
 *
 * Input: 
 *    a, b: limits of integration.
 *    n: number of trapezoids.
 * Output:  Estimate of the integral from a to b of f(x) 
 *    using the trapezoidal rule and n trapezoids.
 *
 * Notes:  
 *    1.  f(x) is hardwired.
 *    2.  the number of processes (p) should evenly divide
 *        the number of trapezoids (n).
 *
 * See Chap 6., pp. 100 & ff in PPMPI
 */
 
// P/ compilar
// mpicc ex3_send_matrix_entry.c -o ex3_send_matrix_entry
#include <stdio.h>

/* We'll be using MPI routines, definitions, etc. */
#include "mpi.h"

int main(int argc, char** argv) {
    int       my_rank;   /* My process rank           */
    int       p;         /* The number of processes   */
    int       a;         /* Left endpoint             */
    int       b;         /* Right endpoint            */
    float     value;     /* Matrix value              */
    int       source;    /* Process sending integral  */
    int       tag = 0;
    MPI_Status status;

    // Chama get_data4 e Trap
    void Get_data4(int* a_ptr, int* b_ptr, float* value_ptr, int my_rank);

    /* Let the system do what it needs to start up MPI */
    MPI_Init(&argc, &argv);

    /* Get my process rank */
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    /* Find out how many processes are being used */
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    Get_data4(&a, &b, &value, my_rank);

    /* Shut down MPI */
    MPI_Finalize();

    return 0;
} /*  main  */


/********************************************************************/
// Envio de dados através de MPI_Pack e MPI_Unpack
// usando um buffer. O processo 0 dá Pack nos itens
// e envia como Broadcast usando a flag MPI_PACKED.
// Os outros processos recebem o buffer e o desfazem 
// em variaveis usando MPI_Unpack.
void Get_data4(
         int*   a_ptr        /* out */, 
         int*   b_ptr        /* out */, 
         float* value_ptr    /* out */,
         int    my_rank      /* in  */) {

    char  buffer[100];  /* Store data in buffer        */
    int   position;     /* Keep track of where data is */    
                        /*     in the buffer           */

    if (my_rank == 0){
        printf("Enter a, b, and value\n");
        scanf("%d %d %f", a_ptr, b_ptr, value_ptr);

        /* Now pack the data into buffer.  Position = 0 */
        /* says start at beginning of buffer.           */
        position = 0;  

        /* Position is in/out */
        MPI_Pack(a_ptr, 1, MPI_INT, buffer, 100,
            &position, MPI_COMM_WORLD);
        /* Position has been incremented: it now refer- */
        /* ences the first free location in buffer.     */

        MPI_Pack(b_ptr, 1, MPI_INT, buffer, 100,
            &position, MPI_COMM_WORLD);
        /* Position has been incremented again. */

        MPI_Pack(value_ptr, 1, MPI_FLOAT, buffer, 100,
            &position, MPI_COMM_WORLD);
        /* Position has been incremented again. */

        /* Now broadcast contents of buffer */
        MPI_Bcast(buffer, 100, MPI_PACKED, 0,
            MPI_COMM_WORLD);
    } else {
        MPI_Bcast(buffer, 100, MPI_PACKED, 0,
            MPI_COMM_WORLD);

        /* Now unpack the contents of buffer */
        position = 0;
        MPI_Unpack(buffer, 100, &position, a_ptr, 1,
            MPI_INT, MPI_COMM_WORLD);
        /* Once again position has been incremented: */
        /* it now references the beginning of b.     */

        MPI_Unpack(buffer, 100, &position, b_ptr, 1,
            MPI_INT, MPI_COMM_WORLD);
        MPI_Unpack(buffer, 100, &position, value_ptr, 1,
            MPI_FLOAT, MPI_COMM_WORLD);
    }
} /* Get_data4 */
