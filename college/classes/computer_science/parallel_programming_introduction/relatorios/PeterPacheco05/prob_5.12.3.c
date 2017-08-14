#include <stdio.h>
#include "mpi.h"

/* 

Exercise 5.12.3, see Chap 5, p. 87 & ff in PPMPI.
by John Weatherwax

Here we input/create the matrices A & B distributed by block rows.

*/ 

#define MAX_ORDER 100

typedef float LOCAL_MATRIX_T[MAX_ORDER][MAX_ORDER];

main( int argc, char* argv[] ){
    int             my_rank;
    int             p;
    LOCAL_MATRIX_T  local_A; 
    LOCAL_MATRIX_T  local_B; 
    LOCAL_MATRIX_T  local_C; 
    float           global_x[MAX_ORDER];
    float           local_x[MAX_ORDER];
    int             m, n, r, i, j, k;
    int             local_m;

    /* declarations: */ 
    void Gen_matrix(LOCAL_MATRIX_T local_A, int local_m, int n);
    void Gen_vector(float local_x[], int local_m); 
    void Print_matrix(char* title,LOCAL_MATRIX_T local_A,int local_m,int m,int n,int my_rank); 
    void Print_vector(char* title,float local_x[MAX_ORDER],int local_m,int m,int my_rank); 
    void Pack_A_Column(LOCAL_MATRIX_T local_B, int local_m, int j, float local_x[] ); 

    MPI_Init(&argc,&argv); 
    MPI_Comm_size(MPI_COMM_WORLD,&p);
    MPI_Comm_rank(MPI_COMM_WORLD,&my_rank); 
  
    if( my_rank==0 ){
      printf("Enter the size of the matrix A (m x n):\n"); 
      scanf("%d %d",&m,&n);
      printf("Enter the number of columns of the matrix B (r):\n"); 
      scanf("%d",&r); 
      if( m > MAX_ORDER || n > MAX_ORDER || r > MAX_ORDER ){
	printf("m or n is too large...exiting\n"); 
	exit(1); 
      }
    }
    MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD); 
    MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD); 
    MPI_Bcast(&r,1,MPI_INT,0,MPI_COMM_WORLD); 

    local_m = m/p;

    Gen_matrix(local_A,local_m,n); 
    Print_matrix("The matrix A is: ",local_A,local_m,m,n,my_rank); 
    Gen_matrix(local_B,local_m,r); 
    Print_matrix("The matrix B is: ",local_B,local_m,n,r,my_rank); 

    /* Loop over the columns of B; performing a dot product with all rows of A: */ 
    for( j = 0; j < r; j++ ){
      /* Extract the column of matrix B into the array global_x 
         - by packing into a contigious array local_x
         - calling MPI_Allgather into global_x
      */ 
      Pack_A_Column(local_B,local_m,j,local_x); 
      MPI_Allgather(local_x,local_m,MPI_FLOAT,
		    global_x,local_m,MPI_FLOAT,MPI_COMM_WORLD); 
      /* Multiply global_x with the rows of local_A: */ 
      for( i = 0; i < local_m; i++ ){
	local_C[i][j] = 0; 
	for( k=0; k < n; k++ ) local_C[i][j] = local_C[i][j] + local_A[i][k] * global_x[k]; 
      }
    } /* end column loop */ 

    Print_matrix("The matrix C is: ", local_C,local_m,m,r,my_rank); 

    MPI_Finalize(); 
}


/**********************************************************************/
void Pack_A_Column(
         LOCAL_MATRIX_T  local_B   /* in  */, 
         int             local_m   /* in  */, 
         int             j         /* in  */,
	 float           local_x[] /* out */) {

  int i;

  for( i=0; i < local_m; i++ ){
    local_x[i] = local_B[i][j];
  }
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

    int   i;

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
    MPI_Gather(local_A, local_m*MAX_ORDER, MPI_FLOAT, temp, 
         local_m*MAX_ORDER, MPI_FLOAT, 0, MPI_COMM_WORLD);

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
    MPI_Gather(local_x, local_m, MPI_FLOAT, temp, local_m, MPI_FLOAT,
        0, MPI_COMM_WORLD);

    if (my_rank == 0) {
        printf("%s\n", title);
        for (i = 0; i < m; i++)
            printf("%4.1f ", temp[i]);
        printf("\n");
    } 
}  /* Print_vector */