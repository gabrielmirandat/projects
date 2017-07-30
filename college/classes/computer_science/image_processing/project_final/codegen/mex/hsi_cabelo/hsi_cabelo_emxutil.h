/*
 * hsi_cabelo_emxutil.h
 *
 * Code generation for function 'hsi_cabelo_emxutil'
 *
 */

#ifndef __HSI_CABELO_EMXUTIL_H__
#define __HSI_CABELO_EMXUTIL_H__

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
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);
extern void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInit_uint8_T(const emlrtStack *sp, emxArray_uint8_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);

#endif

/* End of code generation (hsi_cabelo_emxutil.h) */
