/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: svd.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 21-May-2026 13:27:44
 */

/* Include Files */
#include "svd.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xswap.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[400]
 *                double U[400]
 *                double s[20]
 *                double V[400]
 * Return Type  : void
 */
void svd(const double A[400], double U[400], double s[20], double V[400])
{
  double Vf[400];
  double b_A[400];
  double b_s[20];
  double e[20];
  double work[20];
  double nrm;
  double rt;
  double snorm;
  double sqds;
  int ii;
  int jj;
  int k;
  int m;
  int q;
  int qjj;
  int qp1;
  int qp1jj;
  int qq;
  memcpy(&b_A[0], &A[0], 400U * sizeof(double));
  memset(&b_s[0], 0, 20U * sizeof(double));
  memset(&e[0], 0, 20U * sizeof(double));
  memset(&work[0], 0, 20U * sizeof(double));
  memset(&U[0], 0, 400U * sizeof(double));
  memset(&Vf[0], 0, 400U * sizeof(double));
  for (q = 0; q < 19; q++) {
    boolean_T apply_transform;
    qp1 = q + 2;
    qp1jj = q + 20 * q;
    qq = qp1jj + 1;
    apply_transform = false;
    nrm = xnrm2(20 - q, b_A, qp1jj + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qp1jj] < 0.0) {
        nrm = -nrm;
      }
      b_s[q] = nrm;
      if (fabs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        qjj = (qp1jj - q) + 20;
        for (k = qq; k <= qjj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qjj = (qp1jj - q) + 20;
        for (k = qq; k <= qjj; k++) {
          b_A[k - 1] /= b_s[q];
        }
      }
      b_A[qp1jj]++;
      b_s[q] = -b_s[q];
    } else {
      b_s[q] = 0.0;
    }
    for (jj = qp1; jj < 21; jj++) {
      qjj = q + 20 * (jj - 1);
      if (apply_transform) {
        xaxpy(20 - q,
              -(xdotc(20 - q, b_A, qp1jj + 1, b_A, qjj + 1) / b_A[qp1jj]),
              qp1jj + 1, b_A, qjj + 1);
      }
      e[jj - 1] = b_A[qjj];
    }
    for (ii = q + 1; ii < 21; ii++) {
      qjj = (ii + 20 * q) - 1;
      U[qjj] = b_A[qjj];
    }
    if (q + 1 <= 18) {
      nrm = b_xnrm2(19 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }
        nrm = e[q];
        if (fabs(e[q]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[q];
          for (k = qp1; k < 21; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 21; k++) {
            e[k - 1] /= nrm;
          }
        }
        e[q + 1]++;
        e[q] = -e[q];
        for (ii = qp1; ii < 21; ii++) {
          work[ii - 1] = 0.0;
        }
        for (jj = qp1; jj < 21; jj++) {
          b_xaxpy(19 - q, e[jj - 1], b_A, (q + 20 * (jj - 1)) + 2, work, q + 2);
        }
        for (jj = qp1; jj < 21; jj++) {
          c_xaxpy(19 - q, -e[jj - 1] / e[q + 1], work, q + 2, b_A,
                  (q + 20 * (jj - 1)) + 2);
        }
      }
      for (ii = qp1; ii < 21; ii++) {
        Vf[(ii + 20 * q) - 1] = e[ii - 1];
      }
    }
  }
  m = 18;
  b_s[19] = b_A[399];
  e[18] = b_A[398];
  e[19] = 0.0;
  memset(&U[380], 0, 20U * sizeof(double));
  U[399] = 1.0;
  for (q = 18; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 20 * q;
    if (b_s[q] != 0.0) {
      for (jj = qp1; jj < 21; jj++) {
        qjj = (q + 20 * (jj - 1)) + 1;
        xaxpy(20 - q, -(xdotc(20 - q, U, qq + 1, U, qjj) / U[qq]), qq + 1, U,
              qjj);
      }
      for (ii = q + 1; ii < 21; ii++) {
        qjj = (ii + 20 * q) - 1;
        U[qjj] = -U[qjj];
      }
      U[qq]++;
      for (ii = 0; ii < q; ii++) {
        U[ii + 20 * q] = 0.0;
      }
    } else {
      memset(&U[q * 20], 0, 20U * sizeof(double));
      U[qq] = 1.0;
    }
  }
  for (q = 19; q >= 0; q--) {
    if ((q + 1 <= 18) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + 20 * q) + 2;
      for (jj = qp1; jj < 21; jj++) {
        qp1jj = (q + 20 * (jj - 1)) + 2;
        xaxpy(19 - q, -(xdotc(19 - q, Vf, qjj, Vf, qp1jj) / Vf[qjj - 1]), qjj,
              Vf, qp1jj);
      }
    }
    memset(&Vf[q * 20], 0, 20U * sizeof(double));
    Vf[q + 20 * q] = 1.0;
  }
  qq = 0;
  snorm = 0.0;
  for (q = 0; q < 20; q++) {
    nrm = b_s[q];
    if (nrm != 0.0) {
      rt = fabs(nrm);
      nrm /= rt;
      b_s[q] = rt;
      if (q + 1 < 20) {
        e[q] /= nrm;
      }
      qp1jj = 20 * q;
      qjj = qp1jj + 20;
      for (k = qp1jj + 1; k <= qjj; k++) {
        U[k - 1] *= nrm;
      }
    }
    if (q + 1 < 20) {
      nrm = e[q];
      if (nrm != 0.0) {
        rt = fabs(nrm);
        nrm = rt / nrm;
        e[q] = rt;
        b_s[q + 1] *= nrm;
        qp1jj = 20 * (q + 1);
        qjj = qp1jj + 20;
        for (k = qp1jj + 1; k <= qjj; k++) {
          Vf[k - 1] *= nrm;
        }
      }
    }
    snorm = fmax(snorm, fmax(fabs(b_s[q]), fabs(e[q])));
  }
  while ((m + 2 > 0) && (qq < 75)) {
    boolean_T exitg1;
    jj = m + 1;
    ii = m + 1;
    exitg1 = false;
    while (!(exitg1 || (ii == 0))) {
      nrm = fabs(e[ii - 1]);
      if ((nrm <=
           2.2204460492503131E-16 * (fabs(b_s[ii - 1]) + fabs(b_s[ii]))) ||
          (nrm <= 1.0020841800044864E-292) ||
          ((qq > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
        e[ii - 1] = 0.0;
        exitg1 = true;
      } else {
        ii--;
      }
    }
    if (ii == m + 1) {
      qjj = 4;
    } else {
      qp1jj = m + 2;
      qjj = m + 2;
      exitg1 = false;
      while ((!exitg1) && (qjj >= ii)) {
        qp1jj = qjj;
        if (qjj == ii) {
          exitg1 = true;
        } else {
          nrm = 0.0;
          if (qjj < m + 2) {
            nrm = fabs(e[qjj - 1]);
          }
          if (qjj > ii + 1) {
            nrm += fabs(e[qjj - 2]);
          }
          rt = fabs(b_s[qjj - 1]);
          if ((rt <= 2.2204460492503131E-16 * nrm) ||
              (rt <= 1.0020841800044864E-292)) {
            b_s[qjj - 1] = 0.0;
            exitg1 = true;
          } else {
            qjj--;
          }
        }
      }
      if (qp1jj == ii) {
        qjj = 3;
      } else if (qp1jj == m + 2) {
        qjj = 1;
      } else {
        qjj = 2;
        ii = qp1jj;
      }
    }
    switch (qjj) {
    case 1: {
      rt = e[m];
      e[m] = 0.0;
      for (k = jj; k >= ii + 1; k--) {
        double sm;
        sm = xrotg(&b_s[k - 1], &rt, &sqds);
        if (k > ii + 1) {
          double b;
          b = e[k - 2];
          rt = -sqds * b;
          e[k - 2] = b * sm;
        }
        xrot(Vf, 20 * (k - 1) + 1, 20 * (m + 1) + 1, sm, sqds);
      }
    } break;
    case 2: {
      rt = e[ii - 1];
      e[ii - 1] = 0.0;
      for (k = ii + 1; k <= m + 2; k++) {
        double b;
        double sm;
        sm = xrotg(&b_s[k - 1], &rt, &sqds);
        b = e[k - 1];
        rt = -sqds * b;
        e[k - 1] = b * sm;
        xrot(U, 20 * (k - 1) + 1, 20 * (ii - 1) + 1, sm, sqds);
      }
    } break;
    case 3: {
      double b;
      double scale;
      double sm;
      nrm = b_s[m + 1];
      scale = fmax(
          fmax(fmax(fmax(fabs(nrm), fabs(b_s[m])), fabs(e[m])), fabs(b_s[ii])),
          fabs(e[ii]));
      sm = nrm / scale;
      nrm = b_s[m] / scale;
      rt = e[m] / scale;
      sqds = b_s[ii] / scale;
      b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
      nrm = sm * rt;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        rt = sqrt(b * b + nrm);
        if (b < 0.0) {
          rt = -rt;
        }
        rt = nrm / (b + rt);
      } else {
        rt = 0.0;
      }
      rt += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[ii] / scale);
      for (k = ii + 1; k <= jj; k++) {
        sm = xrotg(&rt, &nrm, &sqds);
        if (k > ii + 1) {
          e[k - 2] = rt;
        }
        nrm = e[k - 1];
        b = b_s[k - 1];
        e[k - 1] = sm * nrm - sqds * b;
        rt = sqds * b_s[k];
        b_s[k] *= sm;
        qjj = 20 * (k - 1) + 1;
        qp1jj = 20 * k + 1;
        xrot(Vf, qjj, qp1jj, sm, sqds);
        b_s[k - 1] = sm * b + sqds * nrm;
        sm = xrotg(&b_s[k - 1], &rt, &sqds);
        b = e[k - 1];
        rt = sm * b + sqds * b_s[k];
        b_s[k] = -sqds * b + sm * b_s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        xrot(U, qjj, qp1jj, sm, sqds);
      }
      e[m] = rt;
      qq++;
    } break;
    default:
      if (b_s[ii] < 0.0) {
        b_s[ii] = -b_s[ii];
        qp1jj = 20 * ii;
        qjj = qp1jj + 20;
        for (k = qp1jj + 1; k <= qjj; k++) {
          Vf[k - 1] = -Vf[k - 1];
        }
      }
      qp1 = ii + 1;
      while ((ii + 1 < 20) && (b_s[ii] < b_s[qp1])) {
        rt = b_s[ii];
        b_s[ii] = b_s[qp1];
        b_s[qp1] = rt;
        qjj = 20 * ii + 1;
        qp1jj = 20 * (ii + 1) + 1;
        xswap(Vf, qjj, qp1jj);
        xswap(U, qjj, qp1jj);
        ii = qp1;
        qp1++;
      }
      qq = 0;
      m--;
      break;
    }
  }
  for (k = 0; k < 20; k++) {
    s[k] = b_s[k];
    memcpy(&V[k * 20], &Vf[k * 20], 20U * sizeof(double));
  }
}

/*
 * File trailer for svd.c
 *
 * [EOF]
 */
