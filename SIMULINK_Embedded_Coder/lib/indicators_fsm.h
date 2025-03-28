/*
 * File: indicators_fsm.h
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

#ifndef RTW_HEADER_indicators_fsm_h_
#define RTW_HEADER_indicators_fsm_h_
#ifndef indicators_fsm_COMMON_INCLUDES_
# define indicators_fsm_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* indicators_fsm_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T count;                        /* '<Root>/indicator_fsm_block' */
  uint8_T is_active_c3_indicators_fsm; /* '<Root>/indicator_fsm_block' */
  uint8_T is_c3_indicators_fsm;        /* '<Root>/indicator_fsm_block' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T rin_bit;                      /* '<Root>/rin_bit' */
  real_T lin_bit;                      /* '<Root>/lin_bit' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Rout;                         /* '<Root>/Rout' */
  real_T Lout;                         /* '<Root>/Lout' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void indicators_fsm_initialize(void);
extern void indicators_fsm_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'indicators_fsm'
 * '<S1>'   : 'indicators_fsm/indicator_fsm_block'
 */
#endif                                 /* RTW_HEADER_indicators_fsm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
