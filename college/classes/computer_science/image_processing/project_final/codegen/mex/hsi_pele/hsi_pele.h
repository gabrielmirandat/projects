/*
 * hsi_pele.h
 *
 * Code generation for function 'hsi_pele'
 *
 */

#ifndef __HSI_PELE_H__
#define __HSI_PELE_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "hsi_pele_types.h"

/* Function Declarations */
extern void hsi_pele(const emlrtStack *sp, real_T lin, real_T col, const
                     emxArray_real_T *B, const emxArray_real_T *G,
                     emxArray_real_T *H, const emxArray_real_T *theta,
                     emxArray_real_T *skin, const emxArray_real_T *g, const
                     emxArray_real_T *w, const emxArray_real_T *r);

#endif

/* End of code generation (hsi_pele.h) */
