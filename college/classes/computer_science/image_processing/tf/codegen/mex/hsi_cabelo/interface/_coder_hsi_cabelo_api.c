/*
 * _coder_hsi_cabelo_api.c
 *
 * Code generation for function '_coder_hsi_cabelo_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "hsi_cabelo.h"
#include "_coder_hsi_cabelo_api.h"
#include "hsi_cabelo_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 1, 1, "_coder_hsi_cabelo_api", "" };

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void b_emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *hair, const
  char_T *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *im4, const
  char_T *identifier, emxArray_uint8_T *y);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *lin, const
  char_T *identifier);
static void emlrt_marshallOut(const emxArray_uint8_T *u, const mxArray *y);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_uint8_T *y);
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_uint8_T *ret);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void b_emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y)
{
  mxSetData((mxArray *)y, (void *)u->data);
  emlrtSetDimensions((mxArray *)y, u->size, 2);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *hair, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  d_emlrt_marshallIn(sp, emlrtAlias(hair), &thisId, y);
  emlrtDestroyArray(&hair);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  h_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *im4, const
  char_T *identifier, emxArray_uint8_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  f_emlrt_marshallIn(sp, emlrtAlias(im4), &thisId, y);
  emlrtDestroyArray(&im4);
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *lin, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(sp, emlrtAlias(lin), &thisId);
  emlrtDestroyArray(&lin);
  return y;
}

static void emlrt_marshallOut(const emxArray_uint8_T *u, const mxArray *y)
{
  mxSetData((mxArray *)y, (void *)u->data);
  emlrtSetDimensions((mxArray *)y, u->size, 2);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_uint8_T *y)
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv0[2];
  boolean_T bv0[2];
  int32_T i;
  int32_T iv1[2];
  for (i = 0; i < 2; i++) {
    iv0[i] = -1;
    bv0[i] = true;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv0, bv0, iv1);
  ret->size[0] = iv1[0];
  ret->size[1] = iv1[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_uint8_T *ret)
{
  int32_T iv2[2];
  boolean_T bv1[2];
  int32_T i;
  int32_T iv3[2];
  for (i = 0; i < 2; i++) {
    iv2[i] = -1;
    bv1[i] = true;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "uint8", false, 2U, iv2, bv1, iv3);
  ret->size[0] = iv3[0];
  ret->size[1] = iv3[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (uint8_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void hsi_cabelo_api(const mxArray *prhs[11], const mxArray *plhs[4])
{
  emxArray_real_T *hair;
  emxArray_real_T *I;
  emxArray_real_T *B;
  emxArray_real_T *G;
  emxArray_real_T *R;
  emxArray_real_T *H;
  emxArray_uint8_T *im4;
  emxArray_uint8_T *im5;
  emxArray_uint8_T *im6;
  real_T lin;
  real_T col;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &hair, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &I, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &B, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &G, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &R, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &H, 2, &emlrtRTEI, true);
  emxInit_uint8_T(&st, &im4, 2, &emlrtRTEI, true);
  emxInit_uint8_T(&st, &im5, 2, &emlrtRTEI, true);
  emxInit_uint8_T(&st, &im6, 2, &emlrtRTEI, true);
  prhs[2] = emlrtProtectR2012b(prhs[2], 2, true, -1);
  prhs[8] = emlrtProtectR2012b(prhs[8], 8, true, -1);
  prhs[9] = emlrtProtectR2012b(prhs[9], 9, true, -1);
  prhs[10] = emlrtProtectR2012b(prhs[10], 10, true, -1);

  /* Marshall function inputs */
  lin = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "lin");
  col = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "col");
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "hair", hair);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "I", I);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "B", B);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "G", G);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "R", R);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "H", H);
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "im4", im4);
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "im5", im5);
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "im6", im6);

  /* Invoke the target function */
  hsi_cabelo(&st, lin, col, hair, I, B, G, R, H, im4, im5, im6);

  /* Marshall function outputs */
  emlrt_marshallOut(im4, prhs[8]);
  plhs[0] = prhs[8];
  emlrt_marshallOut(im5, prhs[9]);
  plhs[1] = prhs[9];
  emlrt_marshallOut(im6, prhs[10]);
  plhs[2] = prhs[10];
  b_emlrt_marshallOut(hair, prhs[2]);
  plhs[3] = prhs[2];
  im6->canFreeData = false;
  emxFree_uint8_T(&im6);
  im5->canFreeData = false;
  emxFree_uint8_T(&im5);
  im4->canFreeData = false;
  emxFree_uint8_T(&im4);
  H->canFreeData = false;
  emxFree_real_T(&H);
  R->canFreeData = false;
  emxFree_real_T(&R);
  G->canFreeData = false;
  emxFree_real_T(&G);
  B->canFreeData = false;
  emxFree_real_T(&B);
  I->canFreeData = false;
  emxFree_real_T(&I);
  hair->canFreeData = false;
  emxFree_real_T(&hair);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_hsi_cabelo_api.c) */
