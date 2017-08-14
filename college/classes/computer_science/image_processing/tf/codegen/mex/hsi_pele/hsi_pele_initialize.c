/*
 * hsi_pele_initialize.c
 *
 * Code generation for function 'hsi_pele_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "hsi_pele.h"
#include "hsi_pele_initialize.h"
#include "hsi_pele_data.h"

/* Function Definitions */
void hsi_pele_initialize(emlrtContext *aContext)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (hsi_pele_initialize.c) */
