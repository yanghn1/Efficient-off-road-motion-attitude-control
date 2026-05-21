/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: cond.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 21-May-2026 10:31:54
 */

/* Include Files */
#include "cond.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xrotg.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[400]
 * Return Type  : double
 */
double cond(const double A[400])
{
  double b_A[400];
  double b_s[20];
  double s[20];
  double work[20];
  double c;
  double nrm;
  double sqds;
  double ztest;
  int i;
  int ii;
  int k;
  int m;
  int q;
  boolean_T apply_transform;
  apply_transform = true;
  for (k = 0; k < 400; k++) {
    if (apply_transform) {
      nrm = A[k];
      if (rtIsInf(nrm) || rtIsNaN(nrm)) {
        apply_transform = false;
      }
    } else {
      apply_transform = false;
    }
  }
  if (apply_transform) {
    double rt;
    double snorm;
    int iter;
    int nmqp1_tmp;
    int qp1;
    int qs;
    memcpy(&b_A[0], &A[0], 400U * sizeof(double));
    memset(&b_s[0], 0, 20U * sizeof(double));
    memset(&s[0], 0, 20U * sizeof(double));
    memset(&work[0], 0, 20U * sizeof(double));
    for (q = 0; q < 19; q++) {
      qp1 = q + 2;
      qs = q + 20 * q;
      i = qs + 1;
      nmqp1_tmp = 19 - q;
      apply_transform = false;
      nrm = xnrm2(20 - q, b_A, qs + 1);
      if (nrm > 0.0) {
        apply_transform = true;
        if (b_A[qs] < 0.0) {
          nrm = -nrm;
        }
        b_s[q] = nrm;
        if (fabs(nrm) >= 1.0020841800044864E-292) {
          nrm = 1.0 / nrm;
          ii = (qs - q) + 20;
          for (k = i; k <= ii; k++) {
            b_A[k - 1] *= nrm;
          }
        } else {
          ii = (qs - q) + 20;
          for (k = i; k <= ii; k++) {
            b_A[k - 1] /= b_s[q];
          }
        }
        b_A[qs]++;
        b_s[q] = -b_s[q];
      } else {
        b_s[q] = 0.0;
      }
      for (m = qp1; m < 21; m++) {
        i = q + 20 * (m - 1);
        if (apply_transform) {
          nrm = 0.0;
          for (k = 0; k <= nmqp1_tmp; k++) {
            nrm += b_A[qs + k] * b_A[i + k];
          }
          nrm = -(nrm / b_A[qs]);
          if (!(nrm == 0.0)) {
            for (k = 0; k <= nmqp1_tmp; k++) {
              iter = i + k;
              b_A[iter] += nrm * b_A[qs + k];
            }
          }
        }
        s[m - 1] = b_A[i];
      }
      if (q + 1 <= 18) {
        nrm = b_xnrm2(19 - q, s, q + 2);
        if (nrm == 0.0) {
          s[q] = 0.0;
        } else {
          if (s[q + 1] < 0.0) {
            s[q] = -nrm;
          } else {
            s[q] = nrm;
          }
          nrm = s[q];
          if (fabs(s[q]) >= 1.0020841800044864E-292) {
            nrm = 1.0 / s[q];
            for (k = qp1; k < 21; k++) {
              s[k - 1] *= nrm;
            }
          } else {
            for (k = qp1; k < 21; k++) {
              s[k - 1] /= nrm;
            }
          }
          s[q + 1]++;
          s[q] = -s[q];
          for (ii = qp1; ii < 21; ii++) {
            work[ii - 1] = 0.0;
          }
          for (m = qp1; m < 21; m++) {
            nrm = s[m - 1];
            if (!(nrm == 0.0)) {
              i = q + 20 * (m - 1);
              ii = 18 - q;
              for (k = 0; k <= ii; k++) {
                qs = (q + k) + 1;
                work[qs] += nrm * b_A[(i + k) + 1];
              }
            }
          }
          for (m = qp1; m < 21; m++) {
            nrm = -s[m - 1] / s[q + 1];
            if (!(nrm == 0.0)) {
              i = (q + 20 * (m - 1)) + 1;
              ii = 18 - q;
              for (k = 0; k <= ii; k++) {
                iter = i + k;
                b_A[iter] += nrm * work[(q + k) + 1];
              }
            }
          }
        }
      }
    }
    m = 18;
    b_s[19] = b_A[399];
    s[18] = b_A[398];
    s[19] = 0.0;
    iter = 0;
    snorm = 0.0;
    for (q = 0; q < 20; q++) {
      nrm = b_s[q];
      ztest = nrm;
      if (nrm != 0.0) {
        rt = fabs(nrm);
        ztest = rt;
        b_s[q] = rt;
        if (q + 1 < 20) {
          s[q] /= nrm / rt;
        }
      }
      if (q + 1 < 20) {
        nrm = s[q];
        if (nrm != 0.0) {
          rt = fabs(nrm);
          s[q] = rt;
          b_s[q + 1] *= rt / nrm;
        }
      }
      snorm = fmax(snorm, fmax(fabs(ztest), fabs(s[q])));
    }
    while ((m + 2 > 0) && (iter < 75)) {
      boolean_T exitg1;
      nmqp1_tmp = m + 1;
      ii = m + 1;
      exitg1 = false;
      while (!(exitg1 || (ii == 0))) {
        nrm = fabs(s[ii - 1]);
        if ((nrm <=
             2.2204460492503131E-16 * (fabs(b_s[ii - 1]) + fabs(b_s[ii]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((iter > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          s[ii - 1] = 0.0;
          exitg1 = true;
        } else {
          ii--;
        }
      }
      if (ii == m + 1) {
        i = 4;
      } else {
        qs = m + 2;
        i = m + 2;
        exitg1 = false;
        while ((!exitg1) && (i >= ii)) {
          qs = i;
          if (i == ii) {
            exitg1 = true;
          } else {
            nrm = 0.0;
            if (i < m + 2) {
              nrm = fabs(s[i - 1]);
            }
            if (i > ii + 1) {
              nrm += fabs(s[i - 2]);
            }
            ztest = fabs(b_s[i - 1]);
            if ((ztest <= 2.2204460492503131E-16 * nrm) ||
                (ztest <= 1.0020841800044864E-292)) {
              b_s[i - 1] = 0.0;
              exitg1 = true;
            } else {
              i--;
            }
          }
        }
        if (qs == ii) {
          i = 3;
        } else if (qs == m + 2) {
          i = 1;
        } else {
          i = 2;
          ii = qs;
        }
      }
      switch (i) {
      case 1: {
        ztest = s[m];
        s[m] = 0.0;
        for (k = nmqp1_tmp; k >= ii + 1; k--) {
          double sm;
          sm = xrotg(&b_s[k - 1], &ztest, &sqds);
          if (k > ii + 1) {
            rt = s[k - 2];
            ztest = -sqds * rt;
            s[k - 2] = rt * sm;
          }
        }
      } break;
      case 2: {
        ztest = s[ii - 1];
        s[ii - 1] = 0.0;
        for (k = ii + 1; k <= m + 2; k++) {
          double sm;
          sm = xrotg(&b_s[k - 1], &ztest, &sqds);
          rt = s[k - 1];
          ztest = -sqds * rt;
          s[k - 1] = rt * sm;
        }
      } break;
      case 3: {
        double scale;
        double sm;
        nrm = b_s[m + 1];
        scale = fmax(fmax(fmax(fmax(fabs(nrm), fabs(b_s[m])), fabs(s[m])),
                          fabs(b_s[ii])),
                     fabs(s[ii]));
        sm = nrm / scale;
        nrm = b_s[m] / scale;
        ztest = s[m] / scale;
        sqds = b_s[ii] / scale;
        rt = ((nrm + sm) * (nrm - sm) + ztest * ztest) / 2.0;
        c = sm * ztest;
        c *= c;
        if ((rt != 0.0) || (c != 0.0)) {
          nrm = sqrt(rt * rt + c);
          if (rt < 0.0) {
            nrm = -nrm;
          }
          nrm = c / (rt + nrm);
        } else {
          nrm = 0.0;
        }
        ztest = (sqds + sm) * (sqds - sm) + nrm;
        nrm = sqds * (s[ii] / scale);
        for (k = ii + 1; k <= nmqp1_tmp; k++) {
          sm = xrotg(&ztest, &nrm, &sqds);
          if (k > ii + 1) {
            s[k - 2] = ztest;
          }
          nrm = s[k - 1];
          rt = b_s[k - 1];
          s[k - 1] = sm * nrm - sqds * rt;
          ztest = sqds * b_s[k];
          b_s[k] *= sm;
          b_s[k - 1] = sm * rt + sqds * nrm;
          sm = xrotg(&b_s[k - 1], &ztest, &sqds);
          rt = s[k - 1];
          ztest = sm * rt + sqds * b_s[k];
          b_s[k] = -sqds * rt + sm * b_s[k];
          nrm = sqds * s[k];
          s[k] *= sm;
        }
        s[m] = ztest;
        iter++;
      } break;
      default:
        if (b_s[ii] < 0.0) {
          b_s[ii] = -b_s[ii];
        }
        qp1 = ii + 1;
        while ((ii + 1 < 20) && (b_s[ii] < b_s[qp1])) {
          rt = b_s[ii];
          b_s[ii] = b_s[qp1];
          b_s[qp1] = rt;
          ii = qp1;
          qp1++;
        }
        iter = 0;
        m--;
        break;
      }
    }
    memcpy(&s[0], &b_s[0], 20U * sizeof(double));
  } else {
    for (i = 0; i < 20; i++) {
      s[i] = rtNaN;
    }
  }
  if (s[19] == 0.0) {
    c = rtInf;
  } else {
    c = s[0] / s[19];
  }
  return c;
}

/*
 * File trailer for cond.c
 *
 * [EOF]
 */
