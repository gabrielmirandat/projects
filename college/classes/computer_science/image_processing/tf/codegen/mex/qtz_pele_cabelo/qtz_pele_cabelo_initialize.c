/*
 * qtz_pele_cabelo_initialize.c
 *
 * Code generation for function 'qtz_pele_cabelo_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "qtz_pele_cabelo.h"
#include "qtz_pele_cabelo_initialize.h"
#include "qtz_pele_cabelo_data.h"

/* Function Definitions */
void qtz_pele_cabelo_initialize(emlrtContext *aContext)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (qtz_pele_cabelo_initialize.c) */
