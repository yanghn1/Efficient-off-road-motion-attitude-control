/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: MC_initialize.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 21-May-2026 10:36:39
 */

/* Include Files */
#include "MC_initialize.h"
#include "CoderTimeAPI.h"
#include "MC_data.h"
#include "rt_nonfinite.h"
#include "timeKeeper.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void MC_initialize(void)
{
  savedTime_not_empty_init();
  freq_not_empty_init();
  isInitialized_MC = true;
}

/*
 * File trailer for MC_initialize.c
 *
 * [EOF]
 */
