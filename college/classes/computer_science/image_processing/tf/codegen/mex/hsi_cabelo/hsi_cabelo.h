/*
 * hsi_cabelo.h
 *
 * Code generation for function 'hsi_cabelo'
 *
 */

#ifndef __HSI_CABELO_H__
#define __HSI_CABELO_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "hsi_cabelo_types.h"

/* Function Declarations */
extern void hsi_cabelo(const emlrtStack *sp, real_T lin, real_T col,
  emxArray_real_T *hair, const emxArray_real_T *I, const emxArray_real_T *B,
  const emxArray_real_T *G, const emxArray_real_T *R, const emxArray_real_T *H,
  emxArray_uint8_T *im4, emxArray_uint8_T *im5, emxArray_uint8_T *im6);

#endif

/* End of code generation (hsi_cabelo.h) */
