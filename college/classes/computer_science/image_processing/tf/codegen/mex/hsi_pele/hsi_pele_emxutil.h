/*
 * hsi_pele_emxutil.h
 *
 * Code generation for function 'hsi_pele_emxutil'
 *
 */

#ifndef __HSI_PELE_EMXUTIL_H__
#define __HSI_PELE_EMXUTIL_H__

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
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);

#endif

/* End of code generation (hsi_pele_emxutil.h) */
