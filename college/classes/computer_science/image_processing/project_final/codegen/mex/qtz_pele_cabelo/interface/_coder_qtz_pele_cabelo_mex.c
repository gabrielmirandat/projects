/*
 * _coder_qtz_pele_cabelo_mex.c
 *
 * Code generation for function 'qtz_pele_cabelo'
 *
 */

/* Include files */
#include "mex.h"
#include "_coder_qtz_pele_cabelo_api.h"
#include "qtz_pele_cabelo_initialize.h"
#include "qtz_pele_cabelo_terminate.h"

/* Function Declarations */
static void qtz_pele_cabelo_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "qtz_pele_cabelo", NULL, false, {2045744189U,2170104910U,2743257031U,4284093946U}, NULL };
void *emlrtRootTLSGlobal = NULL;

/* Function Definitions */
static void qtz_pele_cabelo_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  const mxArray *outputs[2];
  const mxArray *inputs[6];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  int nInputs = nrhs;
  emlrtStack st = { NULL, NULL, NULL };
  /* Module initialization. */
  qtz_pele_cabelo_initialize(&emlrtContextGlobal);
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, mxINT32_CLASS, 6, mxCHAR_CLASS, 15, "qtz_pele_cabelo");
  } else if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, mxCHAR_CLASS, 15, "qtz_pele_cabelo");
  }
  /* Temporary copy for mex inputs. */
  for (n = 0; n < nInputs; ++n) {
    inputs[n] = prhs[n];
  }
  /* Call the function. */
  qtz_pele_cabelo_api(inputs, outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  qtz_pele_cabelo_terminate();
}

void qtz_pele_cabelo_atexit_wrapper(void)
{
   qtz_pele_cabelo_atexit();
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(qtz_pele_cabelo_atexit_wrapper);
  /* Dispatch the entry-point. */
  qtz_pele_cabelo_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (_coder_qtz_pele_cabelo_mex.c) */
