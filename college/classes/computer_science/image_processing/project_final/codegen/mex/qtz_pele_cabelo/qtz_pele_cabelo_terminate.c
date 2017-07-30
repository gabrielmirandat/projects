/*
 * qtz_pele_cabelo_terminate.c
 *
 * Code generation for function 'qtz_pele_cabelo_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "qtz_pele_cabelo.h"
#include "qtz_pele_cabelo_terminate.h"

/* Function Definitions */
void qtz_pele_cabelo_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void qtz_pele_cabelo_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (qtz_pele_cabelo_terminate.c) */
