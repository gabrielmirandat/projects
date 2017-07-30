/*
 * hsi_pele_terminate.c
 *
 * Code generation for function 'hsi_pele_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "hsi_pele.h"
#include "hsi_pele_terminate.h"

/* Function Definitions */
void hsi_pele_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void hsi_pele_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (hsi_pele_terminate.c) */
