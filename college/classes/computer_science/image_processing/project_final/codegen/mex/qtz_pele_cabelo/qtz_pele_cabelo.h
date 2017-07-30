/*
 * qtz_pele_cabelo.h
 *
 * Code generation for function 'qtz_pele_cabelo'
 *
 */

#ifndef __QTZ_PELE_CABELO_H__
#define __QTZ_PELE_CABELO_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "qtz_pele_cabelo_types.h"

/* Function Declarations */
extern void qtz_pele_cabelo(const emlrtStack *sp, real_T lin, real_T col, const
  emxArray_uint8_T *skin, const emxArray_real_T *hair, emxArray_real_T *qtzskin,
  emxArray_real_T *qtzhair);

#endif

/* End of code generation (qtz_pele_cabelo.h) */
