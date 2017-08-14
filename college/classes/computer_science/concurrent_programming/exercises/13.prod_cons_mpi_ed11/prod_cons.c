// produtor e consumidor com mpi
// mpicc prod_cons.c -o prod_cons
// mpiexec -n 4 prod_cons, onde -n representa o número de processos criados
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <mpi.h>

int produz_item();
void consome_item();

// numero de slots no buffer
#define N 10 

// int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status)
//     MPI_Recv(       &a,         1,               MPI_INT,          1,      99,MPI_COMM_WORLD,            &status);
//     MPI_Recv(       &a,         1,               MPI_INT,          0,      99,MPI_COMM_WORLD,            &status);

// int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
//     MPI_Send(             &a,         1,               MPI_INT,        1,      99,MPI_COMM_WORLD);
//     MPI_Send(             &a,         1,               MPI_INT,        0,      99,MPI_COMM_WORLD);

int main(int argc, char *argv[]) {
    int         meu_rank;       /* rank of process      */
    int         num_proc;       /* number of processes  */
    int         source;         /* rank of sender       */
    int         dest;           /* rank of receiver     */
    int         tag = 0;        /* tag for messages     */
    int         buffer;         /* storage for message  */
    MPI_Status  status;         /* return status for    */
                                /* receive              */

    int item, confirmacao;

   
    // inicia MPI e obtem id (rank)
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &meu_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_proc); 

    if(num_proc!=2)
    {
        printf("use apenas 2 processos.\n");
        // finaliza
        MPI_Finalize();
        return 0;
    }
    
    // produtor eh o processo zero
    if (meu_rank == 0) 
    {
        srand48(time(NULL));
        // message m;

        while(1)
        {
            item = produz_item();
            // receive(consumer, &m);
            MPI_Recv(/*buf*/     &confirmacao, 
                     /*count*/   1, 
                     /*datatype*/MPI_INT, 
                     /*source*/  1, 
                     /*tag*/     99, 
                     /*comm*/    MPI_COMM_WORLD, 
                     /*status*/  &status);

            printf("prod::recebi %d\n", confirmacao);
            
            // build_message(&m, item);
            // send(consumer, &m);
            MPI_Send(/*buf*/      &item,
                     /*count*/    1,
                     /*datatype*/ MPI_INT,
                     /*dest*/     1,
                     /*tag*/      99,
                     /*comm*/     MPI_COMM_WORLD);
        }
    } 
    // consumidor eh o processo 1
    else 
    {
        int i;
        // message m;

        for(i=0;i<N; i++) //send(producer, &m);
            MPI_Send(/*buf*/      &i,
                     /*count*/    1,
                     /*datatype*/ MPI_INT,
                     /*dest*/     0,
                     /*tag*/      99,
                     /*comm*/     MPI_COMM_WORLD);
        
        while(1)
        {
            // receive(producer, &m);
            // item = extract_item(&m);
            MPI_Recv(/*buf*/     &item, 
                     /*count*/   1, 
                     /*datatype*/MPI_INT, 
                     /*source*/  0, 
                     /*tag*/     99, 
                     /*comm*/    MPI_COMM_WORLD, 
                     /*status*/  &status);

            printf("\t\t\t\tcons::recebi %d\n", item);

            MPI_Send(/*buf*/      &i,
                     /*count*/    1,
                     /*datatype*/ MPI_INT,
                     /*dest*/     0,
                     /*tag*/      99,
                     /*comm*/     MPI_COMM_WORLD);

            // send(producer, &m);
            consome_item(item);
        }
    }

    // finaliza
    MPI_Finalize();
    return 0;
}

int produz_item()
{
   sleep(1);
   printf("Item produzido\n");
   return (int) (drand48()*1000);
}

void consome_item()
{
   sleep(1);
   printf("\t\t\t\tItem consumido\n");
}