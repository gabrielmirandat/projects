/*
 * _coder_qtz_pele_cabelo_api.c
 *
 * Code generation for function '_coder_qtz_pele_cabelo_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "qtz_pele_cabelo.h"
#include "_coder_qtz_pele_cabelo_api.h"
#include "qtz_pele_cabelo_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 1, 1, "_coder_qtz_pele_cabelo_api", "" };

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *skin, const
  char_T *identifier, emxArray_uint8_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_uint8_T *y);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *hair, const
  char_T *identifier, emxArray_real_T *y);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *lin, const
  char_T *identifier);
static void emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_uint8_T *ret);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *skin, const
  char_T *identifier, emxArray_uint8_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  d_emlrt_marshallIn(sp, emlrtAlias(skin), &thisId, y);
  emlrtDestroyArray(&skin);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_uint8_T *y)
{
  h_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *hair, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  f_emlrt_marshallIn(sp, emlrtAlias(hair), &thisId, y);
  emlrtDestroyArray(&hair);
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

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
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
  emlrtMsgIdentifier *msgId, emxArray_uint8_T *ret)
{
  int32_T iv0[2];
  boolean_T bv0[2];
  int32_T i;
  int32_T iv1[2];
  for (i = 0; i < 2; i++) {
    iv0[i] = -1;
    bv0[i] = true;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "uint8", false, 2U, iv0, bv0, iv1);
  ret->size[0] = iv1[0];
  ret->size[1] = iv1[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (uint8_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv2[2];
  boolean_T bv1[2];
  int32_T i;
  int32_T iv3[2];
  for (i = 0; i < 2; i++) {
    iv2[i] = -1;
    bv1[i] = true;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv2, bv1, iv3);
  ret->size[0] = iv3[0];
  ret->size[1] = iv3[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void qtz_pele_cabelo_api(const mxArray *prhs[6], const mxArray *plhs[2])
{
  emxArray_uint8_T *skin;
  emxArray_real_T *hair;
  emxArray_real_T *qtzskin;
  emxArray_real_T *qtzhair;
  real_T lin;
  real_T col;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_uint8_T(&st, &skin, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &hair, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &qtzskin, 2, &emlrtRTEI, true);
  emxInit_real_T(&st, &qtzhair, 2, &emlrtRTEI, true);
  prhs[4] = emlrtProtectR2012b(prhs[4], 4, true, -1);
  prhs[5] = emlrtProtectR2012b(prhs[5], 5, true, -1);

  /* Marshall function inputs */
  lin = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "lin");
  col = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "col");
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "skin", skin);
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "hair", hair);
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "qtzskin", qtzskin);
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "qtzhair", qtzhair);

  /* Invoke the target function */
  qtz_pele_cabelo(&st, lin, col, skin, hair, qtzskin, qtzhair);

  /* Marshall function outputs */
  emlrt_marshallOut(qtzhair, prhs[5]);
  plhs[0] = prhs[5];
  emlrt_marshallOut(qtzskin, prhs[4]);
  plhs[1] = prhs[4];
  qtzhair->canFreeData = false;
  emxFree_real_T(&qtzhair);
  qtzskin->canFreeData = false;
  emxFree_real_T(&qtzskin);
  hair->canFreeData = false;
  emxFree_real_T(&hair);
  skin->canFreeData = false;
  emxFree_uint8_T(&skin);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_qtz_pele_cabelo_api.c) */
