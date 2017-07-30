/* Modified cio.h -- header file for use with cio.c -- basic collective I/O functions
 *
 * See Chap 8, pp. 142 & ff in PPMPI
 */
#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "mpi.h"
#include "vsscanf.h"

// MPI_Keyval_create - para criar chave, 
//                     retorna ponteiro pra chave
//                     util pra achar rank do processo de I/O
// MPI_Comm_dup      - duplicar comunicador
//                     MPI_DUP_FN
// MPI_Comm_free     - deletar comunicador
//                     MPI_NULL_DELETE_FN 
// MPI_Attr_delete   - deletar atributo
// MPI_Attr_get      - determina valor de atributo
// MPI_Attr_put      - para colocar rank na cache com 
//                     comunicador
// MPI_Comm_compare  - comparar grupos e contextos de 
//                     dois comunicadores                     

/* All process ranks < HUGE */
#define HUGE 32768
#define NO_IO_ATTR -1

extern int IO_KEY;

int Cache_io_rank(
        MPI_Comm   orig_comm   /* in     */,
        MPI_Comm   io_comm     /* in/out */);

int Copy_attr(
        MPI_Comm   comm1       /* in     */,
        MPI_Comm   comm2       /* in/out */,
        int        KEY         /* in     */);

void Get_corresp_rank(
        MPI_Comm   comm1       /* in  */,
        int        rank1       /* in  */,
        MPI_Comm   comm2       /* in  */,
        int*       rank2_ptr   /* out */);

int Get_io_rank(
        MPI_Comm io_comm      /* in  */,
        int*     io_rank_ptr  /* out */);

int Cscanf(
        MPI_Comm  io_comm  /* in  */,
        char*     prompt   /* in  */,
        char*     format   /* in  */,
                  ...      /* out */);

int Cprintf(
        MPI_Comm  io_comm  /* in */,
        char*     title    /* in */,
        char*     format   /* in */,
                  ...      /* in */);

int Cerror_test(
        MPI_Comm  io_comm       /* in */,
        char*     routine_name  /* in */,
        int       error         /* in */);
#endif
/* End of io.h */

// 1. Ok. As funções são Cache_io_rank, Copy_attr, Get_corresp_rank, Get_io_rank, Cscanf, 
//    Cprintf e Cerror_test.