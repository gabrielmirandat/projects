/* Modificada get_data3.c -- Parallel Trapezoidal Rule.  Builds a derived type
 *     for use with the distribution of the input data.
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
 * See Chap 6, pp. 90 & ff in PPMPI
 */

 // P/ compilar
 // mpicc ex1_get_data3.c -o ex1_get_data3

#include <stdio.h>

/* We'll be using MPI routines, definitions, etc. */
#include "mpi.h"

void Build_derived_type(
         float*         a_ptr           /* in   */,
         float*         b_ptr           /* in   */,
         int*           n_ptr           /* in   */,
         MPI_Datatype*  mesg_mpi_t_ptr  /* out  */);

int main(int argc, char** argv) {
    int         my_rank;   /* My process rank           */
    int         p;         /* The number of processes   */
    float       a;         /* Left endpoint             */
    float       b;         /* Right endpoint            */
    int         n;         /* Number of trapezoids      */
    float       h;         /* Trapezoid base length     */
    float       local_a;   /* Left endpoint my process  */
    float       local_b;   /* Right endpoint my process */
    int         local_n;   /* Number of trapezoids for  */
                           /* my calculation            */
    float       integral;  /* Integral over my interval */
    float       total;     /* Total integral            */
    int         source;    /* Process sending integral  */
    int         dest = 0;  /* All messages go to 0      */
    int         tag = 0;
    MPI_Status  status;

    // Get_data3 e Trap sao chamadas aqui
    void Get_data3(float* a_ptr, float* b_ptr, int* n_ptr, int my_rank);
    float Trap(float local_a, float local_b, int local_n,
              float h);    /* Calculate local integral  */

    /* Let the system do what it needs to start up MPI */
    MPI_Init(&argc, &argv);

    /* Get my process rank */
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    /* Find out how many processes are being used */
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    // todos os processos constroem o novo tipo
    Get_data3(&a, &b, &n, my_rank);

    h = (b-a)/n;    /* h is the same for all processes */
    local_n = n/p;  /* So is the number of trapezoids */

    /* Length of each process' interval of 
     * integration = local_n*h.  So my interval
     * starts at: */
    local_a = a + my_rank*local_n*h;
    local_b = local_a + local_n*h;
    integral = Trap(local_a, local_b, local_n, h);

    /* Add up the integrals calculated by each process */
    // soma as integrais de todos os processos
    MPI_Reduce(&integral, &total, 1, MPI_FLOAT,
        MPI_SUM, 0, MPI_COMM_WORLD);

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
// criaçao de um tipo derivado composto de dois floats e um int
// 
void Build_derived_type(
         float*         a_ptr           /* in   */,
         float*         b_ptr           /* in   */,
         int*           n_ptr           /* in   */,
         MPI_Datatype*  mesg_mpi_t_ptr  /* out  */) {
                        /* pointer to new MPI type */

    /* The number of elements in each "block" of the   */
    /*     new type.  For us, 1 each.                  */
    int block_lengths[3];      

    /* Displacement of each element from start of new  */
    /*     type.  The "d_i's."                         */   
    /* MPI_Aint ("address int") is an MPI defined C    */
    /*     type.  Usually an int.                      */
    MPI_Aint displacements[3];

    /* MPI types of the elements.  The "t_i's."        */
    MPI_Datatype typelist[3];  
                              
    /* Use for calculating displacements               */
    MPI_Aint start_address; 
    MPI_Aint address;

    block_lengths[0] = block_lengths[1] 
                     = block_lengths[2] = 1;

    /* Build a derived datatype consisting of  */
    /* two floats and an int                   */
    typelist[0] = MPI_FLOAT;
    typelist[1] = MPI_FLOAT;
    typelist[2] = MPI_INT;

    /* First element, a, is at displacement 0      */
    displacements[0] = 0;

    /* Calculate other displacements relative to a */
    MPI_Address(a_ptr, &start_address);

    /* Find address of b and displacement from a   */
    MPI_Address(b_ptr, &address);
    displacements[1] = address - start_address;

    /* Find address of n and displacement from a   */
    MPI_Address(n_ptr, &address);
    displacements[2] = address - start_address;

    /* Build the derived datatype */
    // para localizaçoes arbitrarias na memoria
    MPI_Type_struct(3, block_lengths, displacements, 
        typelist, mesg_mpi_t_ptr);

    /* Commit it -- tell system we'll be using it for */
    /* communication.                                 */
    // commita novo tipo
    MPI_Type_commit(mesg_mpi_t_ptr);
} /* Build_derived_type */


/********************************************************************/
// usa Build_derived_type
// cria um tipo derivado mesg_mpi_t composto de a, b e n e manda pra 
// todos os outros processos
void Get_data3(
         float*  a_ptr    /* out */,
         float*  b_ptr    /* out */,
         int*    n_ptr    /* out */,
         int     my_rank  /* in  */) {
    MPI_Datatype  mesg_mpi_t; /* MPI type corresponding */
                              /* to 3 floats and an int */
    
    if (my_rank == 0){
        printf("Enter a, b, and n\n");
        scanf("%f %f %d", a_ptr, b_ptr, n_ptr);
    }

    Build_derived_type(a_ptr, b_ptr, n_ptr, &mesg_mpi_t);
    MPI_Bcast(a_ptr, 1, mesg_mpi_t, 0, MPI_COMM_WORLD);
} /* Get_data3 */


/********************************************************************/
// retorna a integral da funçao f nos limites de 'a' a 'b'
// usando 'n' trapezios
float Trap(
          float  local_a   /* in */, 
          float  local_b   /* in */, 
          int    local_n   /* in */, 
          float  h         /* in */) { 

    float integral;   /* Store result in integral  */ 
    float x; 
    int i; 

    // f eh chamada aqui
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
// recebe x e retorna x ao quadrado
float f(float x) { 
    float return_val; 
    /* Calculate f(x). */
    /* Store calculation in return_val. */ 
    return_val = x*x;
    return return_val; 
} /* f */


