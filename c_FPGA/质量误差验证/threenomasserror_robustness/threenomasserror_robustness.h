/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: threenomasserror_robustness.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 21-May-2026 11:21:53
 */

#ifndef THREENOMASSERROR_ROBUSTNESS_H
#define THREENOMASSERROR_ROBUSTNESS_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void threenomasserror_robustness(
    double target, double x, double y, double theta, double vx, double vy,
    double omega, double phi, double dot_phi, double deltaf_lastout, double F1,
    double F2, double F3, double F4, double dist_min, double merror,
    double *ax_next, double *deltaf_next, double *kp_num);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for threenomasserror_robustness.h
 *
 * [EOF]
 */
