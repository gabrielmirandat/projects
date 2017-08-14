#include <stdio.h>
#include "mpi.h"

/* 
 * Exercise 5.12.1, see Chap 5, p. 87 & ff in PPMPI.
 * Modified from John Weathewax
 *
 * Here we input/create a matrix distributed by block rows.
 */ 

/* To compile and run:
 *  mpicc pa1.c -o pa1
 *  mpiexec -n 4 pa1, onde -n representa o número de processos criados
 */

#define MAX_ORDER 100

// Matrix of order 100
typedef float LOCAL_MATRIX_T[MAX_ORDER][MAX_ORDER];

// void Gen_matrix(LOCAL_MATRIX_T local_A, int local_m, int n);
// void Gen_vector(float local_x[], int local_m); 
// void Print_matrix(char* title,LOCAL_MATRIX_T local_A,int local_m,int m,int n,int my_rank); 
// void Print_vector(char* title,float local_x[MAX_ORDER],int local_m,int m,int my_rank); 

int main( int argc, char* argv[] ){
    int             my_rank;
    int             p;
    LOCAL_MATRIX_T  local_A; 
    float           local_x[MAX_ORDER];
    int             m, n;
    int             local_m;

    /* declarations: */ 
    void Gen_matrix(LOCAL_MATRIX_T local_A, int local_m, int n);
    void Gen_vector(float local_x[], int local_m); 
    void Print_matrix(char* title,LOCAL_MATRIX_T local_A,int local_m,int m,int n,int my_rank); 
    void Print_vector(char* title,float local_x[MAX_ORDER],int local_m,int m,int my_rank); 

    MPI_Init(&argc,&argv); 
    MPI_Comm_size(MPI_COMM_WORLD,&p);
    MPI_Comm_rank(MPI_COMM_WORLD,&my_rank); 
  
    if( my_rank==0 )
    {
      printf("Enter the size of the matrix (m x n):\n"); 
      scanf("%d %d",&m,&n);
      if( m > MAX_ORDER || n > MAX_ORDER )
      {
	       printf("m or n is too large...exiting\n"); 
	       return 1; 
      }
    }

    // int MPI_Bcast ( message, count, datatype, root, comm )
    // processo zero manda ordem da matriz para todos os outros processos 
    MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD); 
    MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD); 

    local_m = m/p; 

    /* Fill the matrix/vector in each process: */ 
    Gen_matrix(local_A,local_m,n); 
    Gen_vector(local_x,local_m); 

    /* Print the matrix/vector from each process: */ 
    Print_matrix("The matrix A is: ",local_A,local_m,m,n,my_rank); 
    Print_vector("The vector x is: ",local_x,local_m,m,  my_rank); 

    MPI_Finalize(); 
    return 0;
}

/**********************************************************************/
void Gen_matrix(
    LOCAL_MATRIX_T  local_A  /* out */, 
    int             local_m  /* in  */, 
    int             n        /* in  */) {

    int             i, j;

    for (i = 0; i < local_m; i++)
        for (j = 0; j < n; j++)
            local_A[i][j] = 1.0;
}


/**********************************************************************/
void Gen_vector(
    float  local_x[]  /* out */, 
    int    local_m    /* in  */) {

    int    i;

    for (i = 0; i < local_m; i++)
        local_x[i] = 1.0;
}


/**********************************************************************/
void Print_matrix(
    char*           title      /* in */, 
    LOCAL_MATRIX_T  local_A    /* in */, 
    int             local_m    /* in */, 
	  int             m          /* in */,
    int             n          /* in */,
    int             my_rank    /* in */) {

    int   i, j;
    float temp[MAX_ORDER][MAX_ORDER];

    /* Gather all local_A's into the array temp at the root: */ 
    // int MPI_Gather(send_data, send_count, send_type, recv_data, recv_count, recv_type, root, comm)
    // Reúne todos os dados locais no processo zero
    MPI_Gather(local_A, local_m*MAX_ORDER, MPI_FLOAT, temp,local_m*MAX_ORDER, MPI_FLOAT, 0, MPI_COMM_WORLD);

    if (my_rank == 0) {
        printf("%s\n", title);
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++)
                printf("%4.1f ", temp[i][j]);
            printf("\n");
        }
    } 
}  /* Print_matrix */


/**********************************************************************/
void Print_vector(
    char*  title      /* in */, 
    float  local_x[]  /* in */, 
    int    local_m    /* in */, 
	  int    m          /* in */, 
    int    my_rank    /* in */) {

    int   i;
    float temp[MAX_ORDER];

    /* Gather all local_x's into the array temp at the root: */ 
    // int MPI_Gather(send_data, send_count, send_type, recv_data, recv_count, recv_type, root, comm)
    // Reúne todos os dados locais no processo zero
    MPI_Gather(local_x, local_m, MPI_FLOAT, temp, local_m, MPI_FLOAT, 0, MPI_COMM_WORLD);

    if (my_rank == 0) 
    {
        printf("%s\n", title);
        for (i = 0; i < m; i++)
            printf("%4.1f ", temp[i]);
        printf("\n");
    } 
}  /* Print_vector */