/*
 * hsi_pele.c
 *
 * Code generation for function 'hsi_pele'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "hsi_pele.h"
#include "hsi_pele_data.h"

/* Variable Definitions */
static emlrtRTEInfo b_emlrtRTEI = { 2, 1, "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 3, 7, "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 11, 26, "r", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 11, 28, "r", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 11, 49, "r", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 11, 51, "r", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 5, 16, "B", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 5, 18, "B", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 5, 24, "G", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 5, 26, "G", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 7, 20, "B", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 7, 22, "B", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 7, 27, "G", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 7, 29, "G", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 8, 16, "H", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 8, 18, "H", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 8, 35, "theta", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 8, 37, "theta", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 6, 17, "H", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 6, 19, "H", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 6, 30, "theta", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 6, 32, "theta", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 11, 16, "g", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 11, 18, "g", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 11, 37, "g", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 11, 39, "g", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 11, 60, "w", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 11, 62, "w", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 11, 77, "H", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 11, 79, "H", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 11, 91, "H", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 11, 93, "H", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 12, 22, "skin", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 12, 24, "skin", "hsi_pele",
  "C:\\Users\\JeomanGoes\\Desktop\\Dropbox\\Introducao ao Processamento de Imagens\\Projeto Final\\final\\Final_mex_windows\\hsi_pele.m",
  0 };

/* Function Definitions */
void hsi_pele(const emlrtStack *sp, real_T lin, real_T col, const
              emxArray_real_T *B, const emxArray_real_T *G, emxArray_real_T *H,
              const emxArray_real_T *theta, emxArray_real_T *skin, const
              emxArray_real_T *g, const emxArray_real_T *w, const
              emxArray_real_T *r)
{
  int32_T i;
  int32_T j;
  int32_T i0;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  boolean_T guard1 = false;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, lin, mxDOUBLE_CLASS, (int32_T)lin,
    &b_emlrtRTEI, sp);
  i = 1;
  while (i - 1 <= (int32_T)lin - 1) {
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, col, mxDOUBLE_CLASS, (int32_T)col,
      &c_emlrtRTEI, sp);
    j = 1;
    while (j - 1 <= (int32_T)col - 1) {
      /* constroi H */
      i0 = B->size[0];
      i1 = B->size[1];
      i2 = G->size[0];
      i3 = G->size[1];
      if (B->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &e_emlrtBCI, sp)
                   + B->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
             &f_emlrtBCI, sp) - 1)) - 1] <= G->data
          [(emlrtDynamicBoundsCheckFastR2012b(i, 1, i2, &g_emlrtBCI, sp) +
            G->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i3,
             &h_emlrtBCI, sp) - 1)) - 1]) {
        i0 = H->size[0];
        i1 = H->size[1];
        i2 = theta->size[0];
        i3 = theta->size[1];
        H->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &q_emlrtBCI, sp) +
                 H->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
                   &r_emlrtBCI, sp) - 1)) - 1] = theta->data
          [(emlrtDynamicBoundsCheckFastR2012b(i, 1, i2, &s_emlrtBCI, sp) +
            theta->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i3,
              &t_emlrtBCI, sp) - 1)) - 1];
      } else {
        i0 = B->size[0];
        i1 = B->size[1];
        i2 = G->size[0];
        i3 = G->size[1];
        if (B->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &i_emlrtBCI, sp)
                     + B->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
               &j_emlrtBCI, sp) - 1)) - 1] > G->data
            [(emlrtDynamicBoundsCheckFastR2012b(i, 1, i2, &k_emlrtBCI, sp) +
              G->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i3,
               &l_emlrtBCI, sp) - 1)) - 1]) {
          i0 = H->size[0];
          i1 = H->size[1];
          i2 = theta->size[0];
          i3 = theta->size[1];
          H->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &m_emlrtBCI, sp)
                   + H->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
                     &n_emlrtBCI, sp) - 1)) - 1] = 360.0 - theta->data
            [(emlrtDynamicBoundsCheckFastR2012b(i, 1, i2, &o_emlrtBCI, sp) +
              theta->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i3,
                &p_emlrtBCI, sp) - 1)) - 1];
        }
      }

      /* constroi filtro da pele */
      i0 = r->size[0];
      i1 = (i - 1) + 1;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &emlrtBCI, sp);
      i0 = r->size[1];
      i1 = (j - 1) + 1;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &b_emlrtBCI, sp);
      i0 = g->size[0];
      i1 = g->size[1];
      if (g->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &u_emlrtBCI, sp)
                   + g->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
             &v_emlrtBCI, sp) - 1)) - 1] < (-1.376 * (r->data[(i + r->size[0] *
             (j - 1)) - 1] * r->data[(i + r->size[0] * (j - 1)) - 1]) + 1.0743 *
           r->data[(i + r->size[0] * (j - 1)) - 1]) + 0.2) {
        i0 = r->size[0];
        i1 = (i - 1) + 1;
        emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &c_emlrtBCI, sp);
        i0 = r->size[1];
        i1 = (j - 1) + 1;
        emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &d_emlrtBCI, sp);
        i0 = g->size[0];
        i1 = g->size[1];
        if (g->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &w_emlrtBCI, sp)
                     + g->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
               &x_emlrtBCI, sp) - 1)) - 1] > (-0.776 * (r->data[(i + r->size[0] *
               (j - 1)) - 1] * r->data[(i + r->size[0] * (j - 1)) - 1]) + 0.5601
             * r->data[(i + r->size[0] * (j - 1)) - 1]) + 0.18) {
          i0 = w->size[0];
          i1 = w->size[1];
          if (w->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &y_emlrtBCI,
                sp) + w->size[0] * (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
                 &ab_emlrtBCI, sp) - 1)) - 1] > 0.001) {
            i0 = H->size[0];
            i1 = H->size[1];
            guard1 = false;
            if (H->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0,
                  &bb_emlrtBCI, sp) + H->size[0] *
                         (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
                   &cb_emlrtBCI, sp) - 1)) - 1] > 240.0) {
              guard1 = true;
            } else {
              i0 = H->size[0];
              i1 = H->size[1];
              if (H->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0,
                    &db_emlrtBCI, sp) + H->size[0] *
                           (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
                     &eb_emlrtBCI, sp) - 1)) - 1] <= 20.0) {
                guard1 = true;
              }
            }

            if (guard1) {
              i0 = skin->size[0];
              i1 = skin->size[1];
              skin->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0,
                &fb_emlrtBCI, sp) + skin->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(j, 1, i1,
                &gb_emlrtBCI, sp) - 1)) - 1] = 1.0;
            }
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

/* End of code generation (hsi_pele.c) */
