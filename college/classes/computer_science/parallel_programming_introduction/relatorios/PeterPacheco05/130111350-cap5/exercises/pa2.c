/* Modified from get_data2.c -- Parallel Trapezoidal Rule.  Uses 3 calls to MPI_Bcast to
 *     distribute input data.
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
 * See Chap. 5, pp. 69 & ff in PPMPI.
 */


/* To compile and run:
 *  mpicc pa2.c -o pa2
 *  mpiexec -n 4 pa2, onde -n representa o número de processos criados
 */

#include <stdio.h>
#include <stdlib.h>
/* We'll be using MPI routines, definitions, etc. */
#include "mpi.h"

int main(int argc, char** argv) {
    int         my_rank;   /* My process rank           */
    int         p;         /* The number of processes   */
    float       a;         /* Left endpoint             */
    float       b;         /* Right endpoint            */
    int         n;         /* Number of trapezoids      */
    float       h;         /* Trapezoid base length     */
    int         local_n;   /* Number of trapezoids for  */
                           /* my calculation            */
    float       total;     /* Total integral            */
    int         source;    /* Process sending integral  */
    int         dest = 0;  /* All messages go to 0      */
    int         tag = 0;
    MPI_Status  status;

    void Get_data2(int* n_ptr, int my_rank);
    float Trap(float local_a, float local_b, int local_n,
              float h);    /* Calculate local integral  */

    /* Let the system do what it needs to start up MPI */
    MPI_Init(&argc, &argv);

    /* Get my process rank */
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    /* set the (evil) random seed */
    srand48( (long int) my_rank ); 

    /* Find out how many processes are being used */
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    Get_data2(&n, my_rank);

    /* each processor should create space to store the generated
       numbers and then send them to the root processor */ 
    double* my_data = (double*) malloc(n*sizeof(int)); 
    for(int in=0; in < n; ++in ){
      my_data[in] = drand48();
    }
    
    
    /* Length of each process' interval of 
     * integration = local_n*h.  So my interval
     * starts at: */
    float local_a = a + my_rank*local_n*h;
    float local_b = local_a + local_n*h;
    float integral = Trap(local_a, local_b, local_n, h);

    /* Add up the integrals calculated by each process */
    if (my_rank == 0) {
        total = integral;
        for (source = 1; source < p; source++) {
            MPI_Recv(&integral, 1, MPI_FLOAT, source, tag, 
                MPI_COMM_WORLD, &status);
            total = total + integral;
        }
    } else {   
        MPI_Send(&integral, 1, MPI_FLOAT, dest, 
            tag, MPI_COMM_WORLD);
    }

    /* Print the result */
    if (my_rank == 0) {
        printf("With n = %d trapezoids, our estimate\n", 
            n);
        printf("of the integral from %f to %f = %f\n", 
            a, b, total); 
    }

    /* Shut down MPI */
    MPI_Finalize();
    return 0;
} /*  main  */



/********************************************************************/
/* Function Get_data2
 * Reads in the user input n.
 * Input parameters:
 *     1.  int my_rank:  rank of current process.
 *     2.  int p:  number of processes.
 * Output parameters:  
 *     1.  int* n:  pointer to the number of random integers each process should generate
 * Algorithm:
 *     1.  Process 0 prompts user for input and
 *         reads in the values.
 *     2.  Process 0 sends input values to other
 *         processes using calls to MPI_Bcast.
 */
void Get_data2(
         int*    n_ptr    /* out */,
         int     my_rank  /* in  */) {

    if (my_rank == 0) {
        printf("Enter *n* the number of integers to generate\n");
        scanf("%d", n_ptr);
    }
    MPI_Bcast(n_ptr, 1, MPI_INT, 0, MPI_COMM_WORLD);
} /* Get_data2 */

/********************************************************************/
float Trap(
          float  local_a   /* in */, 
          float  local_b   /* in */, 
          int    local_n   /* in */, 
          float  h         /* in */) { 

    float integral;   /* Store result in integral  */ 
    float x; 
    int i; 

    float f(float x); /* function we're integrating */

    integral = (f(local_a) + f(local_b))/2.0; 
    x = local_a; 
    for (i = 1; i <= local_n-1; i++) { 
        x = x + h; 
        integral = integral + f(x); 
    } 
    integral = integral*h; 
    return integral;
} /*  Trap  */


/********************************************************************/
float f(float x) { 
    float return_val; 
    /* Calculate f(x). */
    /* Store calculation in return_val. */ 
    return_val = x*x;
    return return_val; 
} /* f */

