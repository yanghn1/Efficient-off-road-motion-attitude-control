/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: iCGMRES_initialize.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 21-May-2026 10:20:52
 */

/* Include Files */
#include "iCGMRES_initialize.h"
#include "CoderTimeAPI.h"
#include "iCGMRES_data.h"
#include "rt_nonfinite.h"
#include "timeKeeper.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void iCGMRES_initialize(void)
{
  savedTime_not_empty_init();
  freq_not_empty_init();
  isInitialized_iCGMRES = true;
}

/*
 * File trailer for iCGMRES_initialize.c
 *
 * [EOF]
 */
