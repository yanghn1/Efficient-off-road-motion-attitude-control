/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: PCGMRES_slow.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 21-May-2026 10:28:04
 */

#ifndef PCGMRES_SLOW_H
#define PCGMRES_SLOW_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void PCGMRES_slow(double target, double x, double y, double theta,
                         double vx, double vy, double omega,
                         double deltaf_lastout, double *ax_next,
                         double *deltaf_next, double *kp_num, double *ifnum);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for PCGMRES_slow.h
 *
 * [EOF]
 */
