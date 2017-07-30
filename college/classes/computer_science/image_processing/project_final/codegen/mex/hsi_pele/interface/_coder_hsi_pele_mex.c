/*
 * _coder_hsi_pele_mex.c
 *
 * Code generation for function 'hsi_pele'
 *
 */

/* Include files */
#include "mex.h"
#include "_coder_hsi_pele_api.h"
#include "hsi_pele_initialize.h"
#include "hsi_pele_terminate.h"

/* Function Declarations */
static void hsi_pele_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "hsi_pele", NULL, false, {2045744189U,2170104910U,2743257031U,4284093946U}, NULL };
void *emlrtRootTLSGlobal = NULL;

/* Function Definitions */
static void hsi_pele_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  const mxArray *outputs[2];
  const mxArray *inputs[10];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  int nInputs = nrhs;
  emlrtStack st = { NULL, NULL, NULL };
  /* Module initialization. */
  hsi_pele_initialize(&emlrtContextGlobal);
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 10) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, mxINT32_CLASS, 10, mxCHAR_CLASS, 8, "hsi_pele");
  } else if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, mxCHAR_CLASS, 8, "hsi_pele");
  }
  /* Temporary copy for mex inputs. */
  for (n = 0; n < nInputs; ++n) {
    inputs[n] = prhs[n];
  }
  /* Call the function. */
  hsi_pele_api(inputs, outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  hsi_pele_terminate();
}

void hsi_pele_atexit_wrapper(void)
{
   hsi_pele_atexit();
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(hsi_pele_atexit_wrapper);
  /* Dispatch the entry-point. */
  hsi_pele_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (_coder_hsi_pele_mex.c) */
