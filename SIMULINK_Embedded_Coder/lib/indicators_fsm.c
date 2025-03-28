/*
 * File: indicators_fsm.c
 *
 * Code generated for Simulink model 'indicators_fsm'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Mar 28 06:24:09 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (8-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "indicators_fsm.h"

/* Named constants for Chart: '<Root>/indicator_fsm_block' */
#define IN_BothON                      ((uint8_T)1U)
#define IN_Count                       ((uint8_T)2U)
#define IN_LeftON                      ((uint8_T)3U)
#define IN_OFF                         ((uint8_T)4U)
#define IN_RightON                     ((uint8_T)5U)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void indicators_fsm_step(void)
{
  boolean_T guard1 = false;

  /* Chart: '<Root>/indicator_fsm_block' incorporates:
   *  Inport: '<Root>/lin_bit'
   *  Inport: '<Root>/rin_bit'
   */
  if (rtDW.is_active_c3_indicators_fsm == 0U) {
    rtDW.is_active_c3_indicators_fsm = 1U;
    rtDW.is_c3_indicators_fsm = IN_OFF;

    /* Outport: '<Root>/Lout' */
    rtY.Lout = 0.0;

    /* Outport: '<Root>/Rout' */
    rtY.Rout = 0.0;
    rtDW.count = 0.0;
  } else {
    guard1 = false;
    switch (rtDW.is_c3_indicators_fsm) {
     case IN_BothON:
      if ((rtU.lin_bit == 1.0) || (rtU.rin_bit == 1.0)) {
        rtDW.is_c3_indicators_fsm = IN_Count;

        /* Outport: '<Root>/Lout' */
        rtY.Lout = 0.0;

        /* Outport: '<Root>/Rout' */
        rtY.Rout = 0.0;
        rtDW.count++;
      } else {
        /* Outport: '<Root>/Lout' */
        rtY.Lout = 1.0;

        /* Outport: '<Root>/Rout' */
        rtY.Rout = 1.0;
        rtDW.count = 0.0;
      }
      break;

     case IN_Count:
      if ((rtU.lin_bit == 0.0) && (rtU.rin_bit == 0.0)) {
        rtDW.is_c3_indicators_fsm = IN_OFF;

        /* Outport: '<Root>/Lout' */
        rtY.Lout = 0.0;

        /* Outport: '<Root>/Rout' */
        rtY.Rout = 0.0;
        rtDW.count = 0.0;
      } else if (rtDW.count == 10.0) {
        if ((rtU.lin_bit == 1.0) && (rtU.rin_bit == 1.0)) {
          rtDW.is_c3_indicators_fsm = IN_BothON;

          /* Outport: '<Root>/Lout' */
          rtY.Lout = 1.0;

          /* Outport: '<Root>/Rout' */
          rtY.Rout = 1.0;
          rtDW.count = 0.0;
        } else if (rtU.lin_bit == 1.0) {
          rtDW.is_c3_indicators_fsm = IN_LeftON;

          /* Outport: '<Root>/Lout' */
          rtY.Lout = !(rtY.Lout != 0.0);

          /* Outport: '<Root>/Rout' */
          rtY.Rout = 0.0;
          rtDW.count = 0.0;
        } else if (rtU.rin_bit == 1.0) {
          rtDW.is_c3_indicators_fsm = IN_RightON;

          /* Outport: '<Root>/Lout' */
          rtY.Lout = 0.0;

          /* Outport: '<Root>/Rout' */
          rtY.Rout = !(rtY.Rout != 0.0);
          rtDW.count = 0.0;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;

     case IN_LeftON:
      if ((rtU.lin_bit == 1.0) || (rtU.rin_bit == 1.0)) {
        rtDW.is_c3_indicators_fsm = IN_Count;

        /* Outport: '<Root>/Lout' */
        rtY.Lout = 0.0;

        /* Outport: '<Root>/Rout' */
        rtY.Rout = 0.0;
        rtDW.count++;
      }
      break;

     case IN_OFF:
      if ((rtU.lin_bit == 1.0) || (rtU.rin_bit == 1.0)) {
        rtDW.is_c3_indicators_fsm = IN_Count;

        /* Outport: '<Root>/Lout' */
        rtY.Lout = 0.0;

        /* Outport: '<Root>/Rout' */
        rtY.Rout = 0.0;
        rtDW.count++;
      } else {
        /* Outport: '<Root>/Lout' */
        rtY.Lout = 0.0;

        /* Outport: '<Root>/Rout' */
        rtY.Rout = 0.0;
        rtDW.count = 0.0;
      }
      break;

     default:
      /* case IN_RightON: */
      if ((rtU.lin_bit == 1.0) || (rtU.rin_bit == 1.0)) {
        rtDW.is_c3_indicators_fsm = IN_Count;

        /* Outport: '<Root>/Lout' */
        rtY.Lout = 0.0;

        /* Outport: '<Root>/Rout' */
        rtY.Rout = 0.0;
        rtDW.count++;
      }
      break;
    }

    if (guard1) {
      /* Outport: '<Root>/Lout' */
      rtY.Lout = 0.0;

      /* Outport: '<Root>/Rout' */
      rtY.Rout = 0.0;
      rtDW.count++;
    }
  }

  /* End of Chart: '<Root>/indicator_fsm_block' */
}

/* Model initialize function */
void indicators_fsm_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
