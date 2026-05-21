/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: PCGMRES_fast_initialize.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 21-May-2026 10:31:54
 */

/* Include Files */
#include "PCGMRES_fast_initialize.h"
#include "CoderTimeAPI.h"
#include "PCGMRES_fast_data.h"
#include "rt_nonfinite.h"
#include "timeKeeper.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void PCGMRES_fast_initialize(void)
{
  savedTime_not_empty_init();
  freq_not_empty_init();
  isInitialized_PCGMRES_fast = true;
}

/*
 * File trailer for PCGMRES_fast_initialize.c
 *
 * [EOF]
 */
