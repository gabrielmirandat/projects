/*
 * hsi_cabelo.c
 *
 * Code generation for function 'hsi_cabelo'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "hsi_cabelo.h"
#include "hsi_cabelo_data.h"

/* Variable Definitions */
static emlrtRTEInfo b_emlrtRTEI = { 2, 1, "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 3, 7, "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 5, 17, "I", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 5, 19, "I", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 5, 32, "B", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 5, 34, "B", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 5, 39, "G", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 5, 41, "G", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 5, 54, "B", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 5, 56, "B", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 5, 61, "R", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 5, 63, "R", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 5, 78, "H", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 5, 80, "H", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 5, 91, "H", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 5, 93, "H", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 9, 18, "im4", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 9, 20, "im4", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 10, 18, "im5", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 10, 20, "im5", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 11, 18, "im6", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 11, 20, "im6", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 6, 22, "hair", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 6, 24, "hair", "hsi_cabelo",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_cabelo.m",
  0 };

/* Function Definitions */
void hsi_cabelo(const emlrtStack *sp, real_T lin, real_T col, emxArray_real_T
                *hair, const emxArray_real_T *I, const emxArray_real_T *B, const
                emxArray_real_T *G, const emxArray_real_T *R, const
                emxArray_real_T *H, emxArray_uint8_T *im4, emxArray_uint8_T *im5,
                emxArray_uint8_T *im6)
{
  int32_T i;
  int32_T j;
  int32_T i0;
  int32_T i1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  int32_T i2;
  int32_T i3;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, lin, mxDOUBLE_CLASS, (int32_T)lin,
    &b_emlrtRTEI, sp);
  i = 1;
  while (i - 1 <= (int32_T)lin - 1) {
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, col, mxDOUBLE_CLASS, (int32_T)col,
      &c_emlrtRTEI, sp);
    j = 1;
    while (j - 1 <= (int32_T)col - 1) {
      /* constroi FILTRO DO CABELO */
      i0 = I->size[0];
      i1 = I->size[1];
      guard1 = false;
      guard2 = false;
      guard3 = false;
      if (I->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &emlrtBCI, sp) +
                   I->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
             &b_emlrtBCI, sp) - 1)) - 1] < 30.0) {
        i0 = B->size[0];
        i1 = B->size[1];
        i2 = G->size[0];
        i3 = G->size[1];
        if (B->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &c_emlrtBCI, sp)
                     + B->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
               &d_emlrtBCI, sp) - 1)) - 1] - G->data
            [(emlrtDynamicBoundsCheckFastR2012b(i, 1, i2, &e_emlrtBCI, sp) +
              G->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i3,
               &f_emlrtBCI, sp) - 1)) - 1] < 15.0) {
          guard2 = true;
        } else {
          i0 = B->size[0];
          i1 = B->size[1];
          i2 = R->size[0];
          i3 = R->size[1];
          if (B->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &g_emlrtBCI,
                sp) + B->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
                 &h_emlrtBCI, sp) - 1)) - 1] - R->data
              [(emlrtDynamicBoundsCheckFastR2012b(i, 1, i2, &i_emlrtBCI, sp) +
                R->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i3,
                 &j_emlrtBCI, sp) - 1)) - 1] < 15.0) {
            guard2 = true;
          } else {
            guard3 = true;
          }
        }
      } else {
        guard3 = true;
      }

      if (guard3) {
        i0 = H->size[0];
        i1 = H->size[1];
        if (H->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &k_emlrtBCI, sp)
                     + H->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
               &l_emlrtBCI, sp) - 1)) - 1] > 20.0) {
          i0 = H->size[0];
          i1 = H->size[1];
          if (H->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &m_emlrtBCI,
                sp) + H->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
                 &n_emlrtBCI, sp) - 1)) - 1] <= 40.0) {
            guard2 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
      }

      if (guard2) {
        i0 = hair->size[0];
        i1 = hair->size[1];
        hair->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &u_emlrtBCI, sp)
                    + hair->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1,
          i1, &v_emlrtBCI, sp) - 1)) - 1] = 1.0;
      }

      if (guard1) {
        i0 = im4->size[0];
        i1 = im4->size[1];
        im4->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &o_emlrtBCI, sp)
                   + im4->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
          &p_emlrtBCI, sp) - 1)) - 1] = MAX_uint8_T;
        i0 = im5->size[0];
        i1 = im5->size[1];
        im5->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &q_emlrtBCI, sp)
                   + im5->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
          &r_emlrtBCI, sp) - 1)) - 1] = MAX_uint8_T;
        i0 = im6->size[0];
        i1 = im6->size[1];
        im6->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &s_emlrtBCI, sp)
                   + im6->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
          &t_emlrtBCI, sp) - 1)) - 1] = MAX_uint8_T;
      }

      j++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
    }

    i++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }
}

/* End of code generation (hsi_cabelo.c) */
