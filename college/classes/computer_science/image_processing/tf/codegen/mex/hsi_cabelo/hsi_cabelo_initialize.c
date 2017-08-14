/*
 * hsi_cabelo_initialize.c
 *
 * Code generation for function 'hsi_cabelo_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "hsi_cabelo.h"
#include "hsi_cabelo_initialize.h"
#include "hsi_cabelo_data.h"

/* Function Definitions */
void hsi_cabelo_initialize(emlrtContext *aContext)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (hsi_cabelo_initialize.c) */
