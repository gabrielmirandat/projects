/*
 * _coder_hsi_pele_api.c
 *
 * Code generation for function '_coder_hsi_pele_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "hsi_pele.h"
#include "_coder_hsi_pele_api.h"
#include "hsi_pele_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 1, 1, "_coder_hsi_pele_api", "" };

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *B, const
  char_T *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *lin, const
  char_T *identifier);
static void emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *B, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  d_emlrt_marshallIn(sp, emlrtAlias(B), &thisId, y);
  emlrtDestroyArray(&B);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
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

static void emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y)
{
  mxSetData((mxArray *)y, (void *)u->data);
  emlrtSetDimensions((mxArray *)y, u->size, 2);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
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

void hsi_pele_api(const mxArray *prhs[10], const mxArray *plhs[2])
{
  emxArray_real_T *B;
  emxArray_real_T *G;
  emxArray_real_T *H;
  emxArray_real_T *theta;
  emxArray_real_T *skin;
  emxArray_real_T *g;
  emxArray_real_T *w;
  emxArray_real_T *r;
  real_T lin;
  real_T col;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &B, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &G, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &H, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &theta, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &skin, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &g, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &w, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &r, 2, &emlrtRTEI, true);
  prhs[4] = emlrtProtectR2012b(prhs[4], 4, true, -1);
  prhs[6] = emlrtProtectR2012b(prhs[6], 6, true, -1);

  /* Marshall function inputs */
  lin = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "lin");
  col = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "col");
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "B", B);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "G", G);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "H", H);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "theta", theta);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "skin", skin);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "g", g);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "w", w);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "r", r);

  /* Invoke the target function */
  hsi_pele(&st, lin, col, B, G, H, theta, skin, g, w, r);

  /* Marshall function outputs */
  emlrt_marshallOut(skin, prhs[6]);
  plhs[0] = prhs[6];
  emlrt_marshallOut(H, prhs[4]);
  plhs[1] = prhs[4];
  r->canFreeData = false;
  emxFree_real_T(&r);
  w->canFreeData = false;
  emxFree_real_T(&w);
  g->canFreeData = false;
  emxFree_real_T(&g);
  skin->canFreeData = false;
  emxFree_real_T(&skin);
  theta->canFreeData = false;
  emxFree_real_T(&theta);
  H->canFreeData = false;
  emxFree_real_T(&H);
  G->canFreeData = false;
  emxFree_real_T(&G);
  B->canFreeData = false;
  emxFree_real_T(&B);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_hsi_pele_api.c) */
