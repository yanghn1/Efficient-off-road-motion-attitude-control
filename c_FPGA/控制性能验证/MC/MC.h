/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: MC.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 21-May-2026 10:36:39
 */

#ifndef MC_H
#define MC_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void MC(double target, double x, double y, double theta, double vx,
               double vy, double omega, double deltaf_lastout, double *ax_next,
               double *deltaf_next, double *kp_num, double *ifnum);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for MC.h
 *
 * [EOF]
 */
