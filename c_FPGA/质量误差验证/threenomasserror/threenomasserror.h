/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: threenomasserror.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 21-May-2026 11:01:45
 */

#ifndef THREENOMASSERROR_H
#define THREENOMASSERROR_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void threenomasserror(double target, double x, double y, double theta,
                             double vx, double vy, double omega, double phi,
                             double dot_phi, double deltaf_lastout, double F1,
                             double F2, double F3, double F4, double dist_min,
                             double merror, double *ax_next,
                             double *deltaf_next, double *kp_num);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for threenomasserror.h
 *
 * [EOF]
 */
