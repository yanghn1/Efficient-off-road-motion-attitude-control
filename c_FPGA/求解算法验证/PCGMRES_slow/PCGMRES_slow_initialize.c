/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: PCGMRES_slow_initialize.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 21-May-2026 10:28:04
 */

/* Include Files */
#include "PCGMRES_slow_initialize.h"
#include "CoderTimeAPI.h"
#include "PCGMRES_slow_data.h"
#include "rt_nonfinite.h"
#include "timeKeeper.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void PCGMRES_slow_initialize(void)
{
  savedTime_not_empty_init();
  freq_not_empty_init();
  isInitialized_PCGMRES_slow = true;
}

/*
 * File trailer for PCGMRES_slow_initialize.c
 *
 * [EOF]
 */
