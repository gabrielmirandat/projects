/*
 * qtz_pele_cabelo.c
 *
 * Code generation for function 'qtz_pele_cabelo'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "qtz_pele_cabelo.h"
#include "sum.h"
#include "qtz_pele_cabelo_data.h"

/* Variable Definitions */
static emlrtRTEInfo b_emlrtRTEI = { 3, 7, "qtz_pele_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\qtz_pele_cabelo"
  ".m" };

static emlrtRTEInfo c_emlrtRTEI = { 2, 1, "qtz_pele_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\qtz_pele_cabelo"
  ".m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 4, 30, "skin", "qtz_pele_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\qtz_pele_cabelo"
  ".m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 4, 38, "skin", "qtz_pele_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\qtz_pele_cabelo"
  ".m", 0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 5, 30, "hair", "qtz_pele_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\qtz_pele_cabelo"
  ".m", 0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 5, 38, "hair", "qtz_pele_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\qtz_pele_cabelo"
  ".m", 0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 10, 22, "qtzskin", "qtz_pele_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\qtz_pele_cabelo"
  ".m", 0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 10, 30, "qtzskin", "qtz_pele_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\qtz_pele_cabelo"
  ".m", 0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 8, 22, "qtzskin", "qtz_pele_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\qtz_pele_cabelo"
  ".m", 0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 8, 30, "qtzskin", "qtz_pele_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\qtz_pele_cabelo"
  ".m", 0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 16, 22, "qtzhair", "qtz_pele_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\qtz_pele_cabelo"
  ".m", 0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 16, 30, "qtzhair", "qtz_pele_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\qtz_pele_cabelo"
  ".m", 0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 14, 22, "qtzhair", "qtz_pele_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\qtz_pele_cabelo"
  ".m", 0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 14, 30, "qtzhair", "qtz_pele_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\qtz_pele_cabelo"
  ".m", 0 };

/* Function Definitions */
void qtz_pele_cabelo(const emlrtStack *sp, real_T lin, real_T col, const
                     emxArray_uint8_T *skin, const emxArray_real_T *hair,
                     emxArray_real_T *qtzskin, emxArray_real_T *qtzhair)
{
  int32_T i0;
  int32_T i;
  real_T b_i;
  int32_T i1;
  int32_T j;
  real_T b_j;
  boolean_T b_skin[25];
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T k;
  int32_T b_qtzskin;
  real_T x[5];
  real_T qtd1;
  real_T qtd2;
  i0 = (int32_T)(((lin - 2.0) + 2.0) / 5.0);
  emlrtForLoopVectorCheckR2012b(3.0, 5.0, lin - 2.0, mxDOUBLE_CLASS, i0,
    &c_emlrtRTEI, sp);
  i = 0;
  while (i <= i0 - 1) {
    b_i = 3.0 + (real_T)i * 5.0;
    i1 = (int32_T)(((col - 2.0) + 2.0) / 5.0);
    emlrtForLoopVectorCheckR2012b(3.0, 5.0, col - 2.0, mxDOUBLE_CLASS, i1,
      &b_emlrtRTEI, sp);
    j = 0;
    while (j <= i1 - 1) {
      b_j = 3.0 + (real_T)j * 5.0;
      for (i2 = 0; i2 < 5; i2++) {
        for (i3 = 0; i3 < 5; i3++) {
          i4 = skin->size[0];
          i5 = (int32_T)(b_i + (-2.0 + (real_T)i3));
          k = skin->size[1];
          b_qtzskin = (int32_T)(b_j + (-2.0 + (real_T)i2));
          b_skin[i3 + 5 * i2] = (skin->data[(emlrtDynamicBoundsCheckFastR2012b
            (i5, 1, i4, &emlrtBCI, sp) + skin->size[0] *
            (emlrtDynamicBoundsCheckFastR2012b(b_qtzskin, 1, k, &b_emlrtBCI, sp)
             - 1)) - 1] == 1);
        }
      }

      sum(b_skin, x);
      qtd1 = x[0];
      for (k = 0; k < 4; k++) {
        qtd1 += x[k + 1];
      }

      for (i2 = 0; i2 < 5; i2++) {
        for (i3 = 0; i3 < 5; i3++) {
          i4 = hair->size[0];
          i5 = (int32_T)(b_i + (-2.0 + (real_T)i3));
          k = hair->size[1];
          b_qtzskin = (int32_T)(b_j + (-2.0 + (real_T)i2));
          b_skin[i3 + 5 * i2] = (hair->data[(emlrtDynamicBoundsCheckFastR2012b
            (i5, 1, i4, &c_emlrtBCI, sp) + hair->size[0] *
            (emlrtDynamicBoundsCheckFastR2012b(b_qtzskin, 1, k, &d_emlrtBCI, sp)
             - 1)) - 1] == 1.0);
        }
      }

      sum(b_skin, x);
      qtd2 = x[0];
      for (k = 0; k < 4; k++) {
        qtd2 += x[k + 1];
      }

      if (qtd1 < 12.0) {
        k = qtzskin->size[0];
        b_qtzskin = qtzskin->size[1];
        for (i2 = 0; i2 < 5; i2++) {
          for (i3 = 0; i3 < 5; i3++) {
            i4 = (int32_T)(b_i + (-2.0 + (real_T)i3));
            i5 = (int32_T)(b_j + (-2.0 + (real_T)i2));
            qtzskin->data[(emlrtDynamicBoundsCheckFastR2012b(i4, 1, k,
              &g_emlrtBCI, sp) + qtzskin->size[0] *
                           (emlrtDynamicBoundsCheckFastR2012b(i5, 1, b_qtzskin,
              &h_emlrtBCI, sp) - 1)) - 1] = 0.0;
          }
        }
      } else {
        k = qtzskin->size[0];
        b_qtzskin = qtzskin->size[1];
        for (i2 = 0; i2 < 5; i2++) {
          for (i3 = 0; i3 < 5; i3++) {
            i4 = (int32_T)(b_i + (-2.0 + (real_T)i3));
            i5 = (int32_T)(b_j + (-2.0 + (real_T)i2));
            qtzskin->data[(emlrtDynamicBoundsCheckFastR2012b(i4, 1, k,
              &e_emlrtBCI, sp) + qtzskin->size[0] *
                           (emlrtDynamicBoundsCheckFastR2012b(i5, 1, b_qtzskin,
              &f_emlrtBCI, sp) - 1)) - 1] = 255.0;
          }
        }
      }

      if (qtd2 < 12.0) {
        k = qtzhair->size[0];
        b_qtzskin = qtzhair->size[1];
        for (i2 = 0; i2 < 5; i2++) {
          for (i3 = 0; i3 < 5; i3++) {
            i4 = (int32_T)(b_i + (-2.0 + (real_T)i3));
            i5 = (int32_T)(b_j + (-2.0 + (real_T)i2));
            qtzhair->data[(emlrtDynamicBoundsCheckFastR2012b(i4, 1, k,
              &k_emlrtBCI, sp) + qtzhair->size[0] *
                           (emlrtDynamicBoundsCheckFastR2012b(i5, 1, b_qtzskin,
              &l_emlrtBCI, sp) - 1)) - 1] = 0.0;
          }
        }
      } else {
        k = qtzhair->size[0];
        b_qtzskin = qtzhair->size[1];
        for (i2 = 0; i2 < 5; i2++) {
          for (i3 = 0; i3 < 5; i3++) {
            i4 = (int32_T)(b_i + (-2.0 + (real_T)i3));
            i5 = (int32_T)(b_j + (-2.0 + (real_T)i2));
            qtzhair->data[(emlrtDynamicBoundsCheckFastR2012b(i4, 1, k,
              &i_emlrtBCI, sp) + qtzhair->size[0] *
                           (emlrtDynamicBoundsCheckFastR2012b(i5, 1, b_qtzskin,
              &j_emlrtBCI, sp) - 1)) - 1] = 255.0;
          }
        }
      }

      j++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
    }

    i++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }
}

/* End of code generation (qtz_pele_cabelo.c) */
