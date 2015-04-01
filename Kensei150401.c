/*
 * Kensei150401.c
 *
 * Code generation for model "Kensei150401".
 *
 * Model version              : 1.550
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Wed Apr 01 11:49:03 2015
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Kensei150401_trc_ptr.h"
#include "Kensei150401.h"
#include "Kensei150401_private.h"

/* Named constants for Chart: '<S49>/Chart (AWS FWS)' */
#define Kensei150401_IN_AWS            ((uint8_T)1U)
#define Kensei150401_IN_FWS            ((uint8_T)2U)
#define Kensei150401_IN_NO_ACTIVE_CHILD ((uint8_T)0U)

/* Named constants for Chart: '<S49>/Chart (Propulsion Modes)' */
#define Kensei150401_IN_Forward        ((uint8_T)1U)
#define Kensei150401_IN_Parking        ((uint8_T)2U)
#define Kensei150401_IN_Reverse        ((uint8_T)3U)
#define Kensei150401_IN_ZPT            ((uint8_T)4U)
#define Kensei150401_IN_ZPTccl         ((uint8_T)1U)
#define Kensei150401_IN_ZPTcl          ((uint8_T)2U)
#define Kensei150401_IN_d              ((uint8_T)1U)
#define Kensei150401_IN_disabled       ((uint8_T)1U)
#define Kensei150401_IN_eco            ((uint8_T)1U)
#define Kensei150401_IN_enabled        ((uint8_T)2U)
#define Kensei150401_IN_fromZPT_warning ((uint8_T)5U)
#define Kensei150401_IN_off_warn       ((uint8_T)1U)
#define Kensei150401_IN_off_warn1      ((uint8_T)1U)
#define Kensei150401_IN_p              ((uint8_T)2U)
#define Kensei150401_IN_r              ((uint8_T)3U)
#define Kensei150401_IN_sport          ((uint8_T)2U)
#define Kensei150401_IN_toZPT_warning  ((uint8_T)6U)
#define Kensei150401_IN_wait           ((uint8_T)2U)
#define Kensei150401_IN_wait1          ((uint8_T)2U)
#define Kensei150401_IN_wait_angle     ((uint8_T)7U)

const real_T Kensei150401_RGND = 0.0;  /* real_T ground */

/* Exported block states */
real_T deltaT;                         /* '<S66>/deltaT Memory' */
real_T flipflop;                       /* '<S66>/flipflop Memory' */
real_T oldTime;                        /* '<S66>/oldTime Memory' */
real_T pulse;                          /* '<S66>/pulse Memory' */

/* Block signals (auto storage) */
BlockIO_Kensei150401 Kensei150401_B;

/* Continuous states */
ContinuousStates_Kensei150401 Kensei150401_X;

/* Block states (auto storage) */
D_Work_Kensei150401 Kensei150401_DWork;

/* Real-time model */
RT_MODEL_Kensei150401 Kensei150401_M_;
RT_MODEL_Kensei150401 *const Kensei150401_M = &Kensei150401_M_;

/* Forward declaration for local functions */
static void Kensei150401_enter_atomic_ZPT(void);
static void Kensei150401_Reverse(void);
static void Kensei150401_ZPT(void);
static void Kensei150401_toZPT_warning(void);
static void Kensei150401_gearmode(void);
static void rate_monotonic_scheduler(void);
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(Kensei150401_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(Kensei150401_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Kensei150401_M->Timing.TaskCounters.TID[2])++;
  if ((Kensei150401_M->Timing.TaskCounters.TID[2]) > 49) {/* Sample time: [0.05s, 0.0s] */
    Kensei150401_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 14;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Kensei150401_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Start for function-call system: '<S46>/fl encoder interrupt function' */
void flencoderinterruptfunctio_Start(void)
{
  /* Start for DataStoreMemory: '<S66>/deltaT Memory' */
  deltaT = Kensei150401_P.deltaTMemory_InitialValue;

  /* Start for DataStoreMemory: '<S66>/flipflop Memory' */
  flipflop = Kensei150401_P.flipflopMemory_InitialValue;

  /* Start for DataStoreMemory: '<S66>/oldTime Memory' */
  oldTime = Kensei150401_P.oldTimeMemory_InitialValue;

  /* Start for DataStoreMemory: '<S66>/pulse Memory' */
  pulse = Kensei150401_P.pulseMemory_InitialValue;
}

/* Output and update for function-call system: '<S46>/fl encoder interrupt function' */
void Kens_flencoderinterruptfunction(int_T controlPortIdx)
{
  {
    /* user code (Output function Header for TID3) */

    /* System '<S46>/fl encoder interrupt function' */
    // declare local variable
    double currentTime;

    // read timestamp
    currentTime = ts_time_read();

    // calculate difference to previous step
    deltaT = currentTime - oldTime;

    // save new timestamp
    oldTime = currentTime;

    // pulse counter
    pulse = pulse +1;

    // flipflop
    flipflop = !flipflop;

    /* RateTransition: '<S66>/Rate Transition3' */
    Kensei150401_B.RateTransition3_j = Kensei150401_B.RateTransition;

    /* DataStoreRead: '<S66>/deltaT Read' */
    Kensei150401_B.deltaTRead = deltaT;

    /* Product: '<S66>/Divide' */
    Kensei150401_B.Divide_m = Kensei150401_B.RateTransition3_j /
      Kensei150401_B.deltaTRead;

    /* RateTransition: '<S66>/Rate Transition2' */
    Kensei150401_B.RateTransition2 = Kensei150401_B.Divide_m;

    /* DataStoreRead: '<S66>/flipflop Read' */
    Kensei150401_B.flipflopRead = flipflop;

    /* DataStoreRead: '<S66>/pulse Read' */
    Kensei150401_B.pulseRead = pulse;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = -0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

uint32_T MWDSP_EPH_E_D(real_T evt, uint32_T *sta)
{
  uint32_T retVal;
  int32_T curState;
  int32_T newState;
  int32_T newStateR;
  int32_T lastzcevent;
  uint32_T previousState;

  /* S-Function (sdspcount2): '<S46>/Counter' */
  /* Detect rising or falling edge events */
  previousState = *sta;
  retVal = 0U;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt > 0.0) {
    curState = 2;
  } else if (evt < 0.0) {
    curState = 0;
  } else {
    curState = 1;
  }

  if (previousState == 5U) {
    newStateR = curState;
  } else {
    if ((uint32_T)curState != previousState) {
      if (previousState == 3U) {
        if ((uint32_T)curState == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 2;
          previousState = 1U;
        }
      }

      if (previousState == 4U) {
        if ((uint32_T)curState == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 3;
          previousState = 1U;
        }
      }

      if (previousState == 2U) {
        retVal = 3U;
      }

      if (previousState == 1U) {
        if ((uint32_T)curState == 2U) {
          retVal = 2U;
        }

        if ((uint32_T)curState == 0U) {
          retVal = 3U;
        }
      }

      if (previousState == 0U) {
        retVal = 2U;
      }

      if (retVal == (uint32_T)lastzcevent) {
        retVal = 0U;
      }

      if ((uint32_T)curState == 1U) {
        if (retVal == 2U) {
          newState = 3;
        } else if (retVal == 3U) {
          newState = 4;
        } else {
          newState = 1;
        }
      } else {
        newState = curState;
      }
    }
  }

  if ((uint32_T)newStateR != 5U) {
    *sta = (uint32_T)newStateR;
    retVal = 0U;
  }

  if ((uint32_T)newState != 5U) {
    *sta = (uint32_T)newState;
  }

  /* End of S-Function (sdspcount2): '<S46>/Counter' */
  return retVal;
}

/* Function for Chart: '<S49>/Chart (Propulsion Modes)' */
static void Kensei150401_enter_atomic_ZPT(void)
{
  /* Entry 'ZPT': '<S78>:30' */
  Kensei150401_B.mode = 4.0;
  Kensei150401_B.prop = 0.0;
  Kensei150401_B.pedalprop = 0.0;
  Kensei150401_B.steerprop = 0.0;
  Kensei150401_B.sport = 0.0;

  /* Constant: '<S1>/FRdegcomm' */
  Kensei150401_B.FRdeg = Kensei150401_P.FRdegcomm_Value;

  /* Constant: '<S1>/FLdegcomm' */
  Kensei150401_B.FLdeg = Kensei150401_P.FLdegcomm_Value;

  /* Constant: '<S1>/RLdegcomm' */
  Kensei150401_B.RLdeg = Kensei150401_P.RLdegcomm_Value;

  /* Constant: '<S1>/RRdegcomm' */
  Kensei150401_B.RRdeg = Kensei150401_P.RRdegcomm_Value;
  Kensei150401_B.zptrate = 1.0;
  Kensei150401_B.clear2go = 1.0;
}

/* Function for Chart: '<S49>/Chart (Propulsion Modes)' */
static void Kensei150401_Reverse(void)
{
  boolean_T guard = FALSE;

  /* Constant: '<S1>/Modecomm' */
  /* During 'Reverse': '<S78>:20' */
  if (Kensei150401_P.Modecomm_Value == 1.0) {
    /* Transition: '<S78>:25' */
    /* Exit Internal 'Reverse': '<S78>:20' */
    Kensei150401_DWork.is_Reverse = Kensei150401_IN_NO_ACTIVE_CHILD;
    Kensei150401_DWork.is_gearmode = Kensei150401_IN_Forward;

    /* Entry 'Forward': '<S78>:8' */
    Kensei150401_B.prop = 1.0;
    Kensei150401_B.pedalprop = 1.0;
    Kensei150401_B.revR = TRUE;
    Kensei150401_B.revL = FALSE;
    Kensei150401_B.mode = 1.0;
    Kensei150401_B.zptrate = 0.0;

    /* Entry Internal 'Forward': '<S78>:8' */
    /* Transition: '<S78>:254' */
    Kensei150401_DWork.is_Forward = Kensei150401_IN_wait;
    Kensei150401_DWork.temporalCounter_i1 = 0U;
  } else {
    if (Kensei150401_P.Modecomm_Value == 4.0) {
      /* Transition: '<S78>:35' */
      if ((Kensei150401_B.Limit80kmh <= 0.0) && ((Kensei150401_B.Gain1 >= -0.2) &&
           (Kensei150401_B.Gain1 <= 0.2))) {
        /* Transition: '<S78>:61' */
        Kensei150401_B.zptwarn = 0.0;

        /* Exit Internal 'Reverse': '<S78>:20' */
        Kensei150401_DWork.is_Reverse = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_gearmode = Kensei150401_IN_ZPT;
        Kensei150401_enter_atomic_ZPT();

        /* Entry Internal 'ZPT': '<S78>:30' */
        Kensei150401_DWork.is_active_throt = 1U;

        /* Entry Internal 'throt': '<S78>:292' */
        /* Transition: '<S78>:119' */
        Kensei150401_DWork.is_throt = Kensei150401_IN_disabled;
        Kensei150401_DWork.temporalCounter_i1 = 0U;

        /* Entry 'disabled': '<S78>:123' */
        Kensei150401_B.steerprop = 0.0;
        Kensei150401_DWork.is_active_fromzptwarn = 1U;

        /* Entry Internal 'fromzptwarn': '<S78>:294' */
        /* Transition: '<S78>:296' */
        Kensei150401_DWork.is_fromzptwarn = Kensei150401_IN_wait1;
        Kensei150401_DWork.temporalCounter_i2 = 0U;
      } else if ((Kensei150401_B.Limit80kmh > 0.0) || (Kensei150401_B.Gain1 <
                  -0.2) || (Kensei150401_B.Gain1 > 0.2)) {
        /* Transition: '<S78>:63' */
        /* Exit Internal 'Reverse': '<S78>:20' */
        Kensei150401_DWork.is_Reverse = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_gearmode = Kensei150401_IN_toZPT_warning;

        /* Entry 'toZPT_warning': '<S78>:62' */
        Kensei150401_B.zptwarn = 1.0;
        Kensei150401_DWork.is_toZPT_warning = Kensei150401_IN_r;
      } else {
        guard = TRUE;
      }
    } else {
      guard = TRUE;
    }

    if (guard) {
      if (Kensei150401_P.Modecomm_Value == 2.0) {
        /* Transition: '<S78>:16' */
        /* Exit Internal 'Reverse': '<S78>:20' */
        Kensei150401_DWork.is_Reverse = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_gearmode = Kensei150401_IN_Parking;

        /* Entry 'Parking': '<S78>:15' */
        Kensei150401_B.prop = 0.0;
        Kensei150401_B.pedalprop = 0.0;
        Kensei150401_B.steerprop = 0.0;
        Kensei150401_B.revR = TRUE;
        Kensei150401_B.revL = FALSE;
        Kensei150401_B.mode = 2.0;
        Kensei150401_B.zptrate = 0.0;

        /* Entry Internal 'Parking': '<S78>:15' */
        /* Transition: '<S78>:259' */
        Kensei150401_DWork.is_Parking = Kensei150401_IN_wait;
        Kensei150401_DWork.temporalCounter_i1 = 0U;
      } else {
        switch (Kensei150401_DWork.is_Reverse) {
         case Kensei150401_IN_off_warn1:
          break;

         default:
          /* During 'wait': '<S78>:260' */
          if (Kensei150401_DWork.temporalCounter_i1 >= 5000U) {
            /* Transition: '<S78>:262' */
            Kensei150401_DWork.is_Reverse = Kensei150401_IN_off_warn1;

            /* Entry 'off_warn1': '<S78>:261' */
            Kensei150401_B.zptwarn = 0.0;
          }
          break;
        }
      }
    }
  }

  /* End of Constant: '<S1>/Modecomm' */
}

/* Function for Chart: '<S49>/Chart (Propulsion Modes)' */
static void Kensei150401_ZPT(void)
{
  boolean_T guard = FALSE;
  boolean_T guard_0 = FALSE;
  boolean_T guard_1 = FALSE;

  /* Constant: '<S1>/Modecomm' */
  /* During 'ZPT': '<S78>:30' */
  if (Kensei150401_P.Modecomm_Value == 2.0) {
    /* Transition: '<S78>:40' */
    if ((Kensei150401_B.Limit80kmh <= 0.0) && ((Kensei150401_B.Gain1 >= -0.2) &&
         (Kensei150401_B.Gain1 <= 0.2))) {
      /* Transition: '<S78>:95' */
      /* Exit Internal 'ZPT': '<S78>:30' */
      /* Exit Internal 'fromzptwarn': '<S78>:294' */
      Kensei150401_DWork.is_fromzptwarn = Kensei150401_IN_NO_ACTIVE_CHILD;
      Kensei150401_DWork.is_active_fromzptwarn = 0U;

      /* Exit Internal 'throt': '<S78>:292' */
      Kensei150401_DWork.is_throt = Kensei150401_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'enabled': '<S78>:122' */
      Kensei150401_DWork.is_enabled = Kensei150401_IN_NO_ACTIVE_CHILD;
      Kensei150401_DWork.is_active_throt = 0U;
      Kensei150401_DWork.is_gearmode = Kensei150401_IN_wait_angle;

      /* Entry 'wait_angle': '<S78>:271' */
      Kensei150401_B.prop = 0.0;
      Kensei150401_B.steerprop = 0.0;

      /* Constant: '<S1>/sportcomm' */
      Kensei150401_B.sport = Kensei150401_P.sportcomm_Value;
      Kensei150401_B.clear2go = 0.0;
      Kensei150401_B.zptwarn = 0.0;
      Kensei150401_DWork.is_wait_angle = Kensei150401_IN_p;
      Kensei150401_DWork.temporalCounter_i1 = 0U;
    } else if ((Kensei150401_B.Limit80kmh > 0.0) || (Kensei150401_B.Gain1 < -0.2)
               || (Kensei150401_B.Gain1 > 0.2)) {
      /* Transition: '<S78>:97' */
      /* Exit Internal 'ZPT': '<S78>:30' */
      /* Exit Internal 'fromzptwarn': '<S78>:294' */
      Kensei150401_DWork.is_fromzptwarn = Kensei150401_IN_NO_ACTIVE_CHILD;
      Kensei150401_DWork.is_active_fromzptwarn = 0U;

      /* Exit Internal 'throt': '<S78>:292' */
      Kensei150401_DWork.is_throt = Kensei150401_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'enabled': '<S78>:122' */
      Kensei150401_DWork.is_enabled = Kensei150401_IN_NO_ACTIVE_CHILD;
      Kensei150401_DWork.is_active_throt = 0U;
      Kensei150401_DWork.is_gearmode = Kensei150401_IN_fromZPT_warning;

      /* Entry 'fromZPT_warning': '<S78>:96' */
      Kensei150401_B.zptwarn = 2.0;
      Kensei150401_DWork.is_fromZPT_warning = Kensei150401_IN_p;
    } else {
      guard_1 = TRUE;
    }
  } else {
    guard_1 = TRUE;
  }

  if (guard_1) {
    /* Constant: '<S1>/Modecomm' */
    if (Kensei150401_P.Modecomm_Value == 3.0) {
      /* Transition: '<S78>:29' */
      if ((Kensei150401_B.Limit80kmh <= 0.0) && ((Kensei150401_B.Gain1 >= -0.2) &&
           (Kensei150401_B.Gain1 <= 0.2))) {
        /* Transition: '<S78>:99' */
        /* Exit Internal 'ZPT': '<S78>:30' */
        /* Exit Internal 'fromzptwarn': '<S78>:294' */
        Kensei150401_DWork.is_fromzptwarn = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_active_fromzptwarn = 0U;

        /* Exit Internal 'throt': '<S78>:292' */
        Kensei150401_DWork.is_throt = Kensei150401_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'enabled': '<S78>:122' */
        Kensei150401_DWork.is_enabled = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_active_throt = 0U;
        Kensei150401_DWork.is_gearmode = Kensei150401_IN_wait_angle;

        /* Entry 'wait_angle': '<S78>:271' */
        Kensei150401_B.prop = 0.0;
        Kensei150401_B.steerprop = 0.0;

        /* Constant: '<S1>/sportcomm' */
        Kensei150401_B.sport = Kensei150401_P.sportcomm_Value;
        Kensei150401_B.clear2go = 0.0;
        Kensei150401_B.zptwarn = 0.0;
        Kensei150401_DWork.is_wait_angle = Kensei150401_IN_r;
        Kensei150401_DWork.temporalCounter_i1 = 0U;
      } else if ((Kensei150401_B.Limit80kmh > 0.0) || (Kensei150401_B.Gain1 <
                  -0.2) || (Kensei150401_B.Gain1 > 0.2)) {
        /* Transition: '<S78>:101' */
        /* Exit Internal 'ZPT': '<S78>:30' */
        /* Exit Internal 'fromzptwarn': '<S78>:294' */
        Kensei150401_DWork.is_fromzptwarn = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_active_fromzptwarn = 0U;

        /* Exit Internal 'throt': '<S78>:292' */
        Kensei150401_DWork.is_throt = Kensei150401_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'enabled': '<S78>:122' */
        Kensei150401_DWork.is_enabled = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_active_throt = 0U;
        Kensei150401_DWork.is_gearmode = Kensei150401_IN_fromZPT_warning;

        /* Entry 'fromZPT_warning': '<S78>:96' */
        Kensei150401_B.zptwarn = 2.0;
        Kensei150401_DWork.is_fromZPT_warning = Kensei150401_IN_r;
      } else {
        guard_0 = TRUE;
      }
    } else {
      guard_0 = TRUE;
    }
  }

  if (guard_0) {
    /* Constant: '<S1>/Modecomm' */
    if (Kensei150401_P.Modecomm_Value == 1.0) {
      /* Transition: '<S78>:41' */
      if ((Kensei150401_B.Limit80kmh > 0.0) || (Kensei150401_B.Gain1 < -0.2) ||
          (Kensei150401_B.Gain1 > 0.2)) {
        /* Transition: '<S78>:100' */
        /* Exit Internal 'ZPT': '<S78>:30' */
        /* Exit Internal 'fromzptwarn': '<S78>:294' */
        Kensei150401_DWork.is_fromzptwarn = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_active_fromzptwarn = 0U;

        /* Exit Internal 'throt': '<S78>:292' */
        Kensei150401_DWork.is_throt = Kensei150401_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'enabled': '<S78>:122' */
        Kensei150401_DWork.is_enabled = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_active_throt = 0U;
        Kensei150401_DWork.is_gearmode = Kensei150401_IN_fromZPT_warning;

        /* Entry 'fromZPT_warning': '<S78>:96' */
        Kensei150401_B.zptwarn = 2.0;
        Kensei150401_DWork.is_fromZPT_warning = Kensei150401_IN_d;
      } else if ((Kensei150401_B.Limit80kmh <= 0.0) && ((Kensei150401_B.Gain1 >=
        -0.2) && (Kensei150401_B.Gain1 <= 0.2))) {
        /* Transition: '<S78>:98' */
        /* Exit Internal 'ZPT': '<S78>:30' */
        /* Exit Internal 'fromzptwarn': '<S78>:294' */
        Kensei150401_DWork.is_fromzptwarn = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_active_fromzptwarn = 0U;

        /* Exit Internal 'throt': '<S78>:292' */
        Kensei150401_DWork.is_throt = Kensei150401_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'enabled': '<S78>:122' */
        Kensei150401_DWork.is_enabled = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_active_throt = 0U;
        Kensei150401_DWork.is_gearmode = Kensei150401_IN_wait_angle;

        /* Entry 'wait_angle': '<S78>:271' */
        Kensei150401_B.prop = 0.0;
        Kensei150401_B.steerprop = 0.0;

        /* Constant: '<S1>/sportcomm' */
        Kensei150401_B.sport = Kensei150401_P.sportcomm_Value;
        Kensei150401_B.clear2go = 0.0;
        Kensei150401_B.zptwarn = 0.0;
        Kensei150401_DWork.is_wait_angle = Kensei150401_IN_d;
        Kensei150401_DWork.temporalCounter_i1 = 0U;
      } else {
        guard = TRUE;
      }
    } else {
      guard = TRUE;
    }
  }

  if (guard) {
    /* During 'throt': '<S78>:292' */
    if (Kensei150401_DWork.is_throt == Kensei150401_IN_disabled) {
      /* During 'disabled': '<S78>:123' */
      if (Kensei150401_DWork.temporalCounter_i1 >= 8000U) {
        /* Transition: '<S78>:125' */
        Kensei150401_DWork.is_throt = Kensei150401_IN_enabled;

        /* Entry 'enabled': '<S78>:122' */
        Kensei150401_B.prop = 1.0;
        Kensei150401_B.steerprop = 1.0;

        /* Entry Internal 'enabled': '<S78>:122' */
        /* Transition: '<S78>:153' */
        Kensei150401_DWork.is_enabled = Kensei150401_IN_ZPTcl;

        /* Entry 'ZPTcl': '<S78>:118' */
        Kensei150401_B.revR = FALSE;
        Kensei150401_B.revL = FALSE;
      }
    } else {
      /* During 'enabled': '<S78>:122' */
      if (Kensei150401_DWork.is_enabled == Kensei150401_IN_ZPTccl) {
        /* During 'ZPTccl': '<S78>:120' */
        if (Kensei150401_B.Gain1 < 0.0) {
          /* Transition: '<S78>:121' */
          Kensei150401_DWork.is_enabled = Kensei150401_IN_ZPTcl;

          /* Entry 'ZPTcl': '<S78>:118' */
          Kensei150401_B.revR = FALSE;
          Kensei150401_B.revL = FALSE;
        }
      } else {
        /* During 'ZPTcl': '<S78>:118' */
        if (Kensei150401_B.Gain1 > 0.0) {
          /* Transition: '<S78>:117' */
          Kensei150401_DWork.is_enabled = Kensei150401_IN_ZPTccl;

          /* Entry 'ZPTccl': '<S78>:120' */
          Kensei150401_B.revR = TRUE;
          Kensei150401_B.revL = TRUE;
        }
      }
    }

    /* During 'fromzptwarn': '<S78>:294' */
    switch (Kensei150401_DWork.is_fromzptwarn) {
     case Kensei150401_IN_off_warn1:
      break;

     default:
      /* During 'wait1': '<S78>:297' */
      if (Kensei150401_DWork.temporalCounter_i2 >= 5000U) {
        /* Transition: '<S78>:295' */
        Kensei150401_DWork.is_fromzptwarn = Kensei150401_IN_off_warn1;

        /* Entry 'off_warn1': '<S78>:298' */
        Kensei150401_B.zptwarn = 0.0;
      }
      break;
    }
  }
}

/* Function for Chart: '<S49>/Chart (Propulsion Modes)' */
static void Kensei150401_toZPT_warning(void)
{
  /* During 'toZPT_warning': '<S78>:62' */
  switch (Kensei150401_DWork.is_toZPT_warning) {
   case Kensei150401_IN_d:
    /* During 'd': '<S78>:251' */
    /* Transition: '<S78>:247' */
    Kensei150401_DWork.is_toZPT_warning = Kensei150401_IN_NO_ACTIVE_CHILD;
    Kensei150401_DWork.is_gearmode = Kensei150401_IN_Forward;

    /* Entry 'Forward': '<S78>:8' */
    Kensei150401_B.prop = 1.0;
    Kensei150401_B.pedalprop = 1.0;
    Kensei150401_B.revR = TRUE;
    Kensei150401_B.revL = FALSE;
    Kensei150401_B.mode = 1.0;
    Kensei150401_B.zptrate = 0.0;

    /* Entry Internal 'Forward': '<S78>:8' */
    /* Transition: '<S78>:254' */
    Kensei150401_DWork.is_Forward = Kensei150401_IN_wait;
    Kensei150401_DWork.temporalCounter_i1 = 0U;
    break;

   case Kensei150401_IN_p:
    /* During 'p': '<S78>:241' */
    /* Transition: '<S78>:265' */
    /* Transition: '<S78>:266' */
    Kensei150401_DWork.is_toZPT_warning = Kensei150401_IN_NO_ACTIVE_CHILD;
    Kensei150401_DWork.is_gearmode = Kensei150401_IN_Parking;

    /* Entry 'Parking': '<S78>:15' */
    Kensei150401_B.prop = 0.0;
    Kensei150401_B.pedalprop = 0.0;
    Kensei150401_B.steerprop = 0.0;
    Kensei150401_B.revR = TRUE;
    Kensei150401_B.revL = FALSE;
    Kensei150401_B.mode = 2.0;
    Kensei150401_B.zptrate = 0.0;

    /* Entry Internal 'Parking': '<S78>:15' */
    /* Transition: '<S78>:259' */
    Kensei150401_DWork.is_Parking = Kensei150401_IN_wait;
    Kensei150401_DWork.temporalCounter_i1 = 0U;
    break;

   default:
    /* During 'r': '<S78>:242' */
    /* Transition: '<S78>:268' */
    /* Transition: '<S78>:269' */
    Kensei150401_DWork.is_toZPT_warning = Kensei150401_IN_NO_ACTIVE_CHILD;
    Kensei150401_DWork.is_gearmode = Kensei150401_IN_Reverse;

    /* Entry 'Reverse': '<S78>:20' */
    Kensei150401_B.prop = 1.0;
    Kensei150401_B.pedalprop = 1.0;
    Kensei150401_B.revR = FALSE;
    Kensei150401_B.revL = TRUE;
    Kensei150401_B.mode = 3.0;
    Kensei150401_B.zptrate = 0.0;

    /* Entry Internal 'Reverse': '<S78>:20' */
    /* Transition: '<S78>:263' */
    Kensei150401_DWork.is_Reverse = Kensei150401_IN_wait;
    Kensei150401_DWork.temporalCounter_i1 = 0U;
    break;
  }
}

/* Function for Chart: '<S49>/Chart (Propulsion Modes)' */
static void Kensei150401_gearmode(void)
{
  boolean_T guard = FALSE;
  boolean_T guard_0 = FALSE;

  /* During 'gearmode': '<S78>:302' */
  switch (Kensei150401_DWork.is_gearmode) {
   case Kensei150401_IN_Forward:
    /* Constant: '<S1>/Modecomm' */
    /* During 'Forward': '<S78>:8' */
    if (Kensei150401_P.Modecomm_Value == 2.0) {
      /* Transition: '<S78>:10' */
      /* Exit Internal 'Forward': '<S78>:8' */
      Kensei150401_DWork.is_Forward = Kensei150401_IN_NO_ACTIVE_CHILD;
      Kensei150401_DWork.is_gearmode = Kensei150401_IN_Parking;

      /* Entry 'Parking': '<S78>:15' */
      Kensei150401_B.prop = 0.0;
      Kensei150401_B.pedalprop = 0.0;
      Kensei150401_B.steerprop = 0.0;
      Kensei150401_B.revR = TRUE;
      Kensei150401_B.revL = FALSE;
      Kensei150401_B.mode = 2.0;
      Kensei150401_B.zptrate = 0.0;

      /* Entry Internal 'Parking': '<S78>:15' */
      /* Transition: '<S78>:259' */
      Kensei150401_DWork.is_Parking = Kensei150401_IN_wait;
      Kensei150401_DWork.temporalCounter_i1 = 0U;
    } else if (Kensei150401_P.Modecomm_Value == 3.0) {
      /* Transition: '<S78>:2' */
      /* Exit Internal 'Forward': '<S78>:8' */
      Kensei150401_DWork.is_Forward = Kensei150401_IN_NO_ACTIVE_CHILD;
      Kensei150401_DWork.is_gearmode = Kensei150401_IN_Reverse;

      /* Entry 'Reverse': '<S78>:20' */
      Kensei150401_B.prop = 1.0;
      Kensei150401_B.pedalprop = 1.0;
      Kensei150401_B.revR = FALSE;
      Kensei150401_B.revL = TRUE;
      Kensei150401_B.mode = 3.0;
      Kensei150401_B.zptrate = 0.0;

      /* Entry Internal 'Reverse': '<S78>:20' */
      /* Transition: '<S78>:263' */
      Kensei150401_DWork.is_Reverse = Kensei150401_IN_wait;
      Kensei150401_DWork.temporalCounter_i1 = 0U;
    } else if (Kensei150401_P.Modecomm_Value == 4.0) {
      /* Transition: '<S78>:4' */
      if ((Kensei150401_B.Limit80kmh <= 0.0) && ((Kensei150401_B.Gain1 >= -0.2) &&
           (Kensei150401_B.Gain1 <= 0.2))) {
        /* Transition: '<S78>:89' */
        Kensei150401_B.zptwarn = 0.0;

        /* Exit Internal 'Forward': '<S78>:8' */
        Kensei150401_DWork.is_Forward = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_gearmode = Kensei150401_IN_ZPT;
        Kensei150401_enter_atomic_ZPT();

        /* Entry Internal 'ZPT': '<S78>:30' */
        Kensei150401_DWork.is_active_throt = 1U;

        /* Entry Internal 'throt': '<S78>:292' */
        /* Transition: '<S78>:119' */
        Kensei150401_DWork.is_throt = Kensei150401_IN_disabled;
        Kensei150401_DWork.temporalCounter_i1 = 0U;

        /* Entry 'disabled': '<S78>:123' */
        Kensei150401_B.steerprop = 0.0;
        Kensei150401_DWork.is_active_fromzptwarn = 1U;

        /* Entry Internal 'fromzptwarn': '<S78>:294' */
        /* Transition: '<S78>:296' */
        Kensei150401_DWork.is_fromzptwarn = Kensei150401_IN_wait1;
        Kensei150401_DWork.temporalCounter_i2 = 0U;
      } else if ((Kensei150401_B.Limit80kmh > 0.0) || (Kensei150401_B.Gain1 <
                  -0.2) || (Kensei150401_B.Gain1 > 0.2)) {
        /* Transition: '<S78>:90' */
        /* Exit Internal 'Forward': '<S78>:8' */
        Kensei150401_DWork.is_Forward = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_gearmode = Kensei150401_IN_toZPT_warning;

        /* Entry 'toZPT_warning': '<S78>:62' */
        Kensei150401_B.zptwarn = 1.0;
        Kensei150401_DWork.is_toZPT_warning = Kensei150401_IN_d;
      } else {
        guard = TRUE;
      }
    } else {
      guard = TRUE;
    }
    break;

   case Kensei150401_IN_Parking:
    /* Constant: '<S1>/Modecomm' */
    /* During 'Parking': '<S78>:15' */
    if ((Kensei150401_P.Modecomm_Value == 1.0) && (Kensei150401_B.PedalLimit100 ==
         0.0)) {
      /* Transition: '<S78>:6' */
      /* Exit Internal 'Parking': '<S78>:15' */
      Kensei150401_DWork.is_Parking = Kensei150401_IN_NO_ACTIVE_CHILD;
      Kensei150401_DWork.is_gearmode = Kensei150401_IN_Forward;

      /* Entry 'Forward': '<S78>:8' */
      Kensei150401_B.prop = 1.0;
      Kensei150401_B.pedalprop = 1.0;
      Kensei150401_B.revR = TRUE;
      Kensei150401_B.revL = FALSE;
      Kensei150401_B.mode = 1.0;
      Kensei150401_B.zptrate = 0.0;

      /* Entry Internal 'Forward': '<S78>:8' */
      /* Transition: '<S78>:254' */
      Kensei150401_DWork.is_Forward = Kensei150401_IN_wait;
      Kensei150401_DWork.temporalCounter_i1 = 0U;
    } else if ((Kensei150401_P.Modecomm_Value == 3.0) &&
               (Kensei150401_B.PedalLimit100 == 0.0)) {
      /* Transition: '<S78>:19' */
      /* Exit Internal 'Parking': '<S78>:15' */
      Kensei150401_DWork.is_Parking = Kensei150401_IN_NO_ACTIVE_CHILD;
      Kensei150401_DWork.is_gearmode = Kensei150401_IN_Reverse;

      /* Entry 'Reverse': '<S78>:20' */
      Kensei150401_B.prop = 1.0;
      Kensei150401_B.pedalprop = 1.0;
      Kensei150401_B.revR = FALSE;
      Kensei150401_B.revL = TRUE;
      Kensei150401_B.mode = 3.0;
      Kensei150401_B.zptrate = 0.0;

      /* Entry Internal 'Reverse': '<S78>:20' */
      /* Transition: '<S78>:263' */
      Kensei150401_DWork.is_Reverse = Kensei150401_IN_wait;
      Kensei150401_DWork.temporalCounter_i1 = 0U;
    } else if (Kensei150401_P.Modecomm_Value == 4.0) {
      /* Transition: '<S78>:9' */
      if ((Kensei150401_B.Limit80kmh <= 0.0) && ((Kensei150401_B.Gain1 >= -0.2) &&
           (Kensei150401_B.Gain1 <= 0.2))) {
        /* Transition: '<S78>:60' */
        Kensei150401_B.zptwarn = 0.0;

        /* Exit Internal 'Parking': '<S78>:15' */
        Kensei150401_DWork.is_Parking = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_gearmode = Kensei150401_IN_ZPT;
        Kensei150401_enter_atomic_ZPT();

        /* Entry Internal 'ZPT': '<S78>:30' */
        Kensei150401_DWork.is_active_throt = 1U;

        /* Entry Internal 'throt': '<S78>:292' */
        /* Transition: '<S78>:119' */
        Kensei150401_DWork.is_throt = Kensei150401_IN_disabled;
        Kensei150401_DWork.temporalCounter_i1 = 0U;

        /* Entry 'disabled': '<S78>:123' */
        Kensei150401_B.steerprop = 0.0;
        Kensei150401_DWork.is_active_fromzptwarn = 1U;

        /* Entry Internal 'fromzptwarn': '<S78>:294' */
        /* Transition: '<S78>:296' */
        Kensei150401_DWork.is_fromzptwarn = Kensei150401_IN_wait1;
        Kensei150401_DWork.temporalCounter_i2 = 0U;
      } else if ((Kensei150401_B.Limit80kmh > 0.0) || (Kensei150401_B.Gain1 <
                  -0.2) || (Kensei150401_B.Gain1 > 0.2)) {
        /* Transition: '<S78>:64' */
        /* Exit Internal 'Parking': '<S78>:15' */
        Kensei150401_DWork.is_Parking = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_gearmode = Kensei150401_IN_toZPT_warning;

        /* Entry 'toZPT_warning': '<S78>:62' */
        Kensei150401_B.zptwarn = 1.0;
        Kensei150401_DWork.is_toZPT_warning = Kensei150401_IN_p;
      } else {
        guard_0 = TRUE;
      }
    } else {
      guard_0 = TRUE;
    }
    break;

   case Kensei150401_IN_Reverse:
    Kensei150401_Reverse();
    break;

   case Kensei150401_IN_ZPT:
    Kensei150401_ZPT();
    break;

   case Kensei150401_IN_fromZPT_warning:
    /* During 'fromZPT_warning': '<S78>:96' */
    switch (Kensei150401_DWork.is_fromZPT_warning) {
     case Kensei150401_IN_d:
      /* During 'd': '<S78>:275' */
      /* Transition: '<S78>:279' */
      /* Transition: '<S78>:280' */
      Kensei150401_DWork.is_fromZPT_warning = Kensei150401_IN_NO_ACTIVE_CHILD;
      Kensei150401_DWork.is_gearmode = Kensei150401_IN_ZPT;
      Kensei150401_enter_atomic_ZPT();

      /* Entry Internal 'ZPT': '<S78>:30' */
      Kensei150401_DWork.is_active_throt = 1U;

      /* Entry Internal 'throt': '<S78>:292' */
      /* Transition: '<S78>:119' */
      Kensei150401_DWork.is_throt = Kensei150401_IN_disabled;
      Kensei150401_DWork.temporalCounter_i1 = 0U;

      /* Entry 'disabled': '<S78>:123' */
      Kensei150401_B.steerprop = 0.0;
      Kensei150401_DWork.is_active_fromzptwarn = 1U;

      /* Entry Internal 'fromzptwarn': '<S78>:294' */
      /* Transition: '<S78>:296' */
      Kensei150401_DWork.is_fromzptwarn = Kensei150401_IN_wait1;
      Kensei150401_DWork.temporalCounter_i2 = 0U;
      break;

     case Kensei150401_IN_p:
      /* During 'p': '<S78>:274' */
      /* Transition: '<S78>:284' */
      /* Transition: '<S78>:281' */
      Kensei150401_DWork.is_fromZPT_warning = Kensei150401_IN_NO_ACTIVE_CHILD;
      Kensei150401_DWork.is_gearmode = Kensei150401_IN_ZPT;
      Kensei150401_enter_atomic_ZPT();

      /* Entry Internal 'ZPT': '<S78>:30' */
      Kensei150401_DWork.is_active_throt = 1U;

      /* Entry Internal 'throt': '<S78>:292' */
      /* Transition: '<S78>:119' */
      Kensei150401_DWork.is_throt = Kensei150401_IN_disabled;
      Kensei150401_DWork.temporalCounter_i1 = 0U;

      /* Entry 'disabled': '<S78>:123' */
      Kensei150401_B.steerprop = 0.0;
      Kensei150401_DWork.is_active_fromzptwarn = 1U;

      /* Entry Internal 'fromzptwarn': '<S78>:294' */
      /* Transition: '<S78>:296' */
      Kensei150401_DWork.is_fromzptwarn = Kensei150401_IN_wait1;
      Kensei150401_DWork.temporalCounter_i2 = 0U;
      break;

     default:
      /* During 'r': '<S78>:273' */
      /* Transition: '<S78>:283' */
      /* Transition: '<S78>:282' */
      Kensei150401_DWork.is_fromZPT_warning = Kensei150401_IN_NO_ACTIVE_CHILD;
      Kensei150401_DWork.is_gearmode = Kensei150401_IN_ZPT;
      Kensei150401_enter_atomic_ZPT();

      /* Entry Internal 'ZPT': '<S78>:30' */
      Kensei150401_DWork.is_active_throt = 1U;

      /* Entry Internal 'throt': '<S78>:292' */
      /* Transition: '<S78>:119' */
      Kensei150401_DWork.is_throt = Kensei150401_IN_disabled;
      Kensei150401_DWork.temporalCounter_i1 = 0U;

      /* Entry 'disabled': '<S78>:123' */
      Kensei150401_B.steerprop = 0.0;
      Kensei150401_DWork.is_active_fromzptwarn = 1U;

      /* Entry Internal 'fromzptwarn': '<S78>:294' */
      /* Transition: '<S78>:296' */
      Kensei150401_DWork.is_fromzptwarn = Kensei150401_IN_wait1;
      Kensei150401_DWork.temporalCounter_i2 = 0U;
      break;
    }
    break;

   case Kensei150401_IN_toZPT_warning:
    Kensei150401_toZPT_warning();
    break;

   default:
    /* During 'wait_angle': '<S78>:271' */
    switch (Kensei150401_DWork.is_wait_angle) {
     case Kensei150401_IN_d:
      /* During 'd': '<S78>:285' */
      if (Kensei150401_DWork.temporalCounter_i1 >= 8000U) {
        /* Transition: '<S78>:299' */
        Kensei150401_DWork.is_wait_angle = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_gearmode = Kensei150401_IN_Forward;

        /* Entry 'Forward': '<S78>:8' */
        Kensei150401_B.prop = 1.0;
        Kensei150401_B.pedalprop = 1.0;
        Kensei150401_B.revR = TRUE;
        Kensei150401_B.revL = FALSE;
        Kensei150401_B.mode = 1.0;
        Kensei150401_B.zptrate = 0.0;

        /* Entry Internal 'Forward': '<S78>:8' */
        /* Transition: '<S78>:254' */
        Kensei150401_DWork.is_Forward = Kensei150401_IN_wait;
        Kensei150401_DWork.temporalCounter_i1 = 0U;
      }
      break;

     case Kensei150401_IN_p:
      /* During 'p': '<S78>:286' */
      if (Kensei150401_DWork.temporalCounter_i1 >= 8000U) {
        /* Transition: '<S78>:300' */
        Kensei150401_DWork.is_wait_angle = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_gearmode = Kensei150401_IN_Parking;

        /* Entry 'Parking': '<S78>:15' */
        Kensei150401_B.prop = 0.0;
        Kensei150401_B.pedalprop = 0.0;
        Kensei150401_B.steerprop = 0.0;
        Kensei150401_B.revR = TRUE;
        Kensei150401_B.revL = FALSE;
        Kensei150401_B.mode = 2.0;
        Kensei150401_B.zptrate = 0.0;

        /* Entry Internal 'Parking': '<S78>:15' */
        /* Transition: '<S78>:259' */
        Kensei150401_DWork.is_Parking = Kensei150401_IN_wait;
        Kensei150401_DWork.temporalCounter_i1 = 0U;
      }
      break;

     default:
      /* During 'r': '<S78>:287' */
      if (Kensei150401_DWork.temporalCounter_i1 >= 8000U) {
        /* Transition: '<S78>:301' */
        Kensei150401_DWork.is_wait_angle = Kensei150401_IN_NO_ACTIVE_CHILD;
        Kensei150401_DWork.is_gearmode = Kensei150401_IN_Reverse;

        /* Entry 'Reverse': '<S78>:20' */
        Kensei150401_B.prop = 1.0;
        Kensei150401_B.pedalprop = 1.0;
        Kensei150401_B.revR = FALSE;
        Kensei150401_B.revL = TRUE;
        Kensei150401_B.mode = 3.0;
        Kensei150401_B.zptrate = 0.0;

        /* Entry Internal 'Reverse': '<S78>:20' */
        /* Transition: '<S78>:263' */
        Kensei150401_DWork.is_Reverse = Kensei150401_IN_wait;
        Kensei150401_DWork.temporalCounter_i1 = 0U;
      }
      break;
    }
    break;
  }

  if (guard_0) {
    switch (Kensei150401_DWork.is_Parking) {
     case Kensei150401_IN_off_warn:
      break;

     default:
      /* During 'wait': '<S78>:256' */
      if (Kensei150401_DWork.temporalCounter_i1 >= 5000U) {
        /* Transition: '<S78>:258' */
        Kensei150401_DWork.is_Parking = Kensei150401_IN_off_warn;

        /* Entry 'off_warn': '<S78>:257' */
        Kensei150401_B.zptwarn = 0.0;
      }
      break;
    }
  }

  if (guard) {
    switch (Kensei150401_DWork.is_Forward) {
     case Kensei150401_IN_off_warn:
      break;

     default:
      /* During 'wait': '<S78>:252' */
      if (Kensei150401_DWork.temporalCounter_i1 >= 5000U) {
        /* Transition: '<S78>:255' */
        Kensei150401_DWork.is_Forward = Kensei150401_IN_off_warn;

        /* Entry 'off_warn': '<S78>:253' */
        Kensei150401_B.zptwarn = 0.0;
      }
      break;
    }
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model output function for TID0 */
void Kensei150401_output0(void)        /* Sample time: [0.0s, 0.0s] */
{
  real_T tmp;
  real_T u;
  real_T u_0;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* set solver stop time */
    if (!(Kensei150401_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Kensei150401_M->solverInfo,
                            ((Kensei150401_M->Timing.clockTickH0 + 1) *
        Kensei150401_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Kensei150401_M->solverInfo,
                            ((Kensei150401_M->Timing.clockTick0 + 1) *
        Kensei150401_M->Timing.stepSize0 + Kensei150401_M->Timing.clockTickH0 *
        Kensei150401_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Kensei150401_M)) {
    Kensei150401_M->Timing.t[0] = rtsiGetT(&Kensei150401_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Constant: '<S1>/offset' */
    Kensei150401_B.offset = Kensei150401_P.offset_Value;

    /* Constant: '<S1>/kmh1' */
    Kensei150401_B.kmh1 = Kensei150401_P.kmh1_Value;

    /* S-Function (rti_commonblock): '<S9>/S-Function1' */
    /* This comment workarounds a code generation problem */
    {
      /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
      adc_tp4_single_new_read(ADC_TP4_1_MODULE_ADDR,
        ADC_TP4_CH1,
                              (dsfloat *)&Kensei150401_B.SFunction1);
      Kensei150401_B.SFunction1 = (Kensei150401_B.SFunction1 - 0.5) * 2;
    }

    /* Gain: '<S2>/inADC1' */
    Kensei150401_B.inADC1 = Kensei150401_P.inADC1_Gain *
      Kensei150401_B.SFunction1;

    /* S-Function (rti_commonblock): '<S10>/S-Function1' */
    /* This comment workarounds a code generation problem */
    {
      /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
      adc_tp4_single_new_read(ADC_TP4_1_MODULE_ADDR,
        ADC_TP4_CH2,
                              (dsfloat *)&Kensei150401_B.SFunction1_f);
      Kensei150401_B.SFunction1_f = (Kensei150401_B.SFunction1_f - 0.5) * 2;
    }

    /* Gain: '<S2>/inADC2' */
    Kensei150401_B.inADC2 = Kensei150401_P.inADC2_Gain *
      Kensei150401_B.SFunction1_f;

    /* S-Function (rti_commonblock): '<S11>/S-Function1' */
    /* This comment workarounds a code generation problem */
    {
      /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
      adc_tp4_single_new_read(ADC_TP4_1_MODULE_ADDR,
        ADC_TP4_CH3,
                              (dsfloat *)&Kensei150401_B.SFunction1_e);
      Kensei150401_B.SFunction1_e = (Kensei150401_B.SFunction1_e - 0.5) * 2;
    }

    /* Gain: '<S2>/inADC3' */
    Kensei150401_B.inADC3 = Kensei150401_P.inADC3_Gain *
      Kensei150401_B.SFunction1_e;

    /* S-Function (rti_commonblock): '<S12>/S-Function1' */
    /* This comment workarounds a code generation problem */
    {
      /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
      adc_tp4_single_new_read(ADC_TP4_1_MODULE_ADDR,
        ADC_TP4_CH4,
                              (dsfloat *)&Kensei150401_B.SFunction1_o);
      Kensei150401_B.SFunction1_o = (Kensei150401_B.SFunction1_o - 0.5) * 2;
    }

    /* Gain: '<S2>/inADC4' */
    Kensei150401_B.inADC4 = Kensei150401_P.inADC4_Gain *
      Kensei150401_B.SFunction1_o;

    /* S-Function (rti_commonblock): '<S13>/S-Function1' */
    /* This comment workarounds a code generation problem */
    {
      /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
      adc_tp4_single_new_read(ADC_TP4_1_MODULE_ADDR,
        ADC_TP4_CH5,
                              (dsfloat *)&Kensei150401_B.SFunction1_os);
      Kensei150401_B.SFunction1_os = (Kensei150401_B.SFunction1_os - 0.5) * 2;
    }

    /* Gain: '<S2>/inADC5' */
    Kensei150401_B.inADC5 = Kensei150401_P.inADC5_Gain *
      Kensei150401_B.SFunction1_os;

    /* S-Function (rti_commonblock): '<S14>/S-Function1' */
    /* This comment workarounds a code generation problem */
    {
      /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
      adc_tp4_single_new_read(ADC_TP4_1_MODULE_ADDR,
        ADC_TP4_CH6,
                              (dsfloat *)&Kensei150401_B.SFunction1_c);
      Kensei150401_B.SFunction1_c = (Kensei150401_B.SFunction1_c - 0.5) * 2;
    }

    /* Gain: '<S2>/inADC6' */
    Kensei150401_B.inADC6 = Kensei150401_P.inADC6_Gain *
      Kensei150401_B.SFunction1_c;

    /* S-Function (rti_commonblock): '<S15>/S-Function1' */
    /* This comment workarounds a code generation problem */
    {
      /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
      adc_tp4_single_new_read(ADC_TP4_1_MODULE_ADDR,
        ADC_TP4_CH7,
                              (dsfloat *)&Kensei150401_B.SFunction1_cu);
      Kensei150401_B.SFunction1_cu = (Kensei150401_B.SFunction1_cu - 0.5) * 2;
    }

    /* Gain: '<S2>/inADC7' */
    Kensei150401_B.inADC7 = Kensei150401_P.inADC7_Gain *
      Kensei150401_B.SFunction1_cu;

    /* S-Function (rti_commonblock): '<S16>/S-Function1' */
    /* This comment workarounds a code generation problem */
    {
      /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
      adc_tp4_single_new_read(ADC_TP4_1_MODULE_ADDR,
        ADC_TP4_CH8,
                              (dsfloat *)&Kensei150401_B.SFunction1_d);
      Kensei150401_B.SFunction1_d = (Kensei150401_B.SFunction1_d - 0.5) * 2;
    }

    /* Gain: '<S2>/inADC8' */
    Kensei150401_B.inADC8 = Kensei150401_P.inADC8_Gain *
      Kensei150401_B.SFunction1_d;

    /* S-Function (rti_commonblock): '<S17>/S-Function1' */
    /* This comment workarounds a code generation problem */
    {
      /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
      adc_tp4_single_new_read(ADC_TP4_1_MODULE_ADDR,
        ADC_TP4_CH9,
                              (dsfloat *)&Kensei150401_B.SFunction1_h);
      Kensei150401_B.SFunction1_h = (Kensei150401_B.SFunction1_h - 0.5) * 2;
    }

    /* Gain: '<S2>/inADC9' */
    Kensei150401_B.inADC9 = Kensei150401_P.inADC9_Gain *
      Kensei150401_B.SFunction1_h;

    /* S-Function (rti_commonblock): '<S18>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S19>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S20>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S21>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S22>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S23>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S24>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S25>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S26>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S27>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S28>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S29>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S30>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Constant: '<S2>/PC_On_Off_Touch_Button' */
    Kensei150401_B.PC_On_Off_Touch_Button =
      Kensei150401_P.PC_On_Off_Touch_Button_Value;

    /* Constant: '<S2>/Touch_Button_Forward_1_Reverse_0' */
    Kensei150401_B.Touch_Button_Forward_1_Reverse_ =
      Kensei150401_P.Touch_Button_Forward_1_Reverse_;

    /* Constant: '<S2>/ZPT_Touch_Button' */
    Kensei150401_B.ZPT_Touch_Button = Kensei150401_P.ZPT_Touch_Button_Value;

    /* Constant: '<S108>/FRwm' */
    Kensei150401_B.FRwm = Kensei150401_P.FRwm_Value;

    /* Constant: '<S108>/Switch_FR' */
    Kensei150401_B.Switch_FR = Kensei150401_P.Switch_FR_Value;

    /* Math: '<S115>/Math Function' incorporates:
     *  Constant: '<S115>/b'
     */
    Kensei150401_B.MathFunction = Kensei150401_P.b_Value *
      Kensei150401_P.b_Value;

    /* Math: '<S115>/Math Function1' incorporates:
     *  Constant: '<S115>/c'
     */
    Kensei150401_B.MathFunction1 = Kensei150401_P.c_Value *
      Kensei150401_P.c_Value;

    /* Math: '<S115>/Math Function2' incorporates:
     *  Constant: '<S115>/d'
     */
    Kensei150401_B.MathFunction2 = Kensei150401_P.d_Value *
      Kensei150401_P.d_Value;

    /* Sum: '<S115>/Sum' */
    Kensei150401_B.Sum = (Kensei150401_B.MathFunction +
                          Kensei150401_B.MathFunction1) -
      Kensei150401_B.MathFunction2;

    /* Product: '<S115>/Divide2' incorporates:
     *  Constant: '<S115>/b'
     *  Constant: '<S115>/c'
     *  Constant: '<S115>/constant'
     */
    Kensei150401_B.Divide2 = Kensei150401_P.constant_Value *
      Kensei150401_P.c_Value * Kensei150401_P.b_Value;

    /* Product: '<S115>/Divide' */
    Kensei150401_B.Divide = Kensei150401_B.Sum / Kensei150401_B.Divide2;

    /* Fcn: '<S115>/Epsilon' */
    tmp = Kensei150401_B.Divide;
    if (tmp >= 1.0) {
      tmp = 1.0;
    } else {
      if (tmp <= -1.0) {
        tmp = -1.0;
      }
    }

    tmp = acos(tmp);
    Kensei150401_B.Epsilon = tmp;

    /* End of Fcn: '<S115>/Epsilon' */

    /* Gain: '<S135>/pulse_to_degree' */
    Kensei150401_B.pulse_to_degree = Kensei150401_P.pulse_to_degree_Gain *
      Kensei150401_B.SFunction1_o1;

    /* Saturate: '<S135>/limit rotation data' */
    tmp = Kensei150401_B.pulse_to_degree;
    u = Kensei150401_P.limitrotationdata_LowerSat;
    u_0 = Kensei150401_P.limitrotationdata_UpperSat;
    if (tmp >= u_0) {
      Kensei150401_B.limitrotationdata = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.limitrotationdata = u;
    } else {
      Kensei150401_B.limitrotationdata = tmp;
    }

    /* End of Saturate: '<S135>/limit rotation data' */

    /* Rounding: '<S135>/Rounding Function2' */
    Kensei150401_B.RoundingFunction2 = rt_roundd_snf
      (Kensei150401_B.limitrotationdata);

    /* Gain: '<S79>/Gain1' */
    Kensei150401_B.Gain1 = Kensei150401_P.Gain1_Gain_h *
      Kensei150401_B.RoundingFunction2;

    /* UnitDelay: '<S65>/Unit Delay' */
    Kensei150401_B.UnitDelay = Kensei150401_DWork.UnitDelay_DSTATE;

    /* Sum: '<S65>/Sum' incorporates:
     *  Constant: '<S65>/Constant'
     */
    Kensei150401_B.Sum_i = Kensei150401_P.Constant_Value -
      Kensei150401_B.UnitDelay;

    /* Product: '<S46>/Divide' incorporates:
     *  Constant: '<S46>/if to rad = 2*pi'
     *  Constant: '<S46>/pulses per revolution'
     */
    Kensei150401_B.Divide_a = Kensei150401_P.iftorad2pi_Value /
      Kensei150401_P.pulsesperrevolution_Value;

    /* RateTransition: '<S46>/Rate Transition' */
    switch (Kensei150401_DWork.RateTransition_read_buf) {
     case 0:
      Kensei150401_DWork.RateTransition_write_buf = 1;
      break;

     case 1:
      Kensei150401_DWork.RateTransition_write_buf = 0;
      break;

     default:
      Kensei150401_DWork.RateTransition_write_buf = (int8_T)
        (Kensei150401_DWork.RateTransition_last_buf_wr == 0);
      break;
    }

    if (Kensei150401_DWork.RateTransition_write_buf != 0) {
      Kensei150401_DWork.RateTransition_Buffer1 = Kensei150401_B.Divide_a;
    } else {
      Kensei150401_DWork.RateTransition_Buffer0 = Kensei150401_B.Divide_a;
    }

    Kensei150401_DWork.RateTransition_last_buf_wr =
      Kensei150401_DWork.RateTransition_write_buf;
    Kensei150401_DWork.RateTransition_write_buf = -1;

    /* End of RateTransition: '<S46>/Rate Transition' */
    if (rtmIsMajorTimeStep(Kensei150401_M)) {
      /* This comment workarounds a code generation problem */
    }

    /* RateTransition: '<S46>/Rate Transition4' */
    switch (Kensei150401_DWork.RateTransition4_write_buf) {
     case 0:
      Kensei150401_DWork.RateTransition4_read_buf = 1;
      break;

     case 1:
      Kensei150401_DWork.RateTransition4_read_buf = 0;
      break;

     default:
      Kensei150401_DWork.RateTransition4_read_buf =
        Kensei150401_DWork.RateTransition4_last_buf_wr;
      break;
    }

    if (Kensei150401_DWork.RateTransition4_read_buf != 0) {
      Kensei150401_B.RateTransition4 =
        Kensei150401_DWork.RateTransition4_Buffer1;
    } else {
      Kensei150401_B.RateTransition4 =
        Kensei150401_DWork.RateTransition4_Buffer0;
    }

    Kensei150401_DWork.RateTransition4_read_buf = -1;

    /* End of RateTransition: '<S46>/Rate Transition4' */

    /* S-Function (sdspcount2): '<S46>/Counter' */
    if (MWDSP_EPH_E_D(Kensei150401_B.RateTransition4,
                      &Kensei150401_DWork.Counter_RstEphState) != 0U) {
      Kensei150401_DWork.Counter_Count = Kensei150401_P.Counter_InitialCount;
    }

    if (MWDSP_EPH_E_D(Kensei150401_B.Sum_i,
                      &Kensei150401_DWork.Counter_ClkEphState) != 0U) {
      Kensei150401_DWork.Counter_Count++;
    }

    Kensei150401_B.Counter = (real_T)Kensei150401_DWork.Counter_Count;

    /* End of S-Function (sdspcount2): '<S46>/Counter' */

    /* RateTransition: '<S46>/Rate Transition1' */
    switch (Kensei150401_DWork.RateTransition1_write_buf) {
     case 0:
      Kensei150401_DWork.RateTransition1_read_buf = 1;
      break;

     case 1:
      Kensei150401_DWork.RateTransition1_read_buf = 0;
      break;

     default:
      Kensei150401_DWork.RateTransition1_read_buf =
        Kensei150401_DWork.RateTransition1_last_buf_wr;
      break;
    }

    if (Kensei150401_DWork.RateTransition1_read_buf != 0) {
      Kensei150401_B.RateTransition1 =
        Kensei150401_DWork.RateTransition1_Buffer1;
    } else {
      Kensei150401_B.RateTransition1 =
        Kensei150401_DWork.RateTransition1_Buffer0;
    }

    Kensei150401_DWork.RateTransition1_read_buf = -1;

    /* End of RateTransition: '<S46>/Rate Transition1' */

    /* Switch: '<S46>/Switch1' incorporates:
     *  Constant: '<S46>/0 rps'
     */
    if (Kensei150401_B.Counter >= Kensei150401_P.Switch1_Threshold_l) {
      Kensei150401_B.Switch1 = Kensei150401_P.rps_Value;
    } else {
      Kensei150401_B.Switch1 = Kensei150401_B.RateTransition1;
    }

    /* End of Switch: '<S46>/Switch1' */

    /* Gain: '<S46>/RPSec to w' */
    Kensei150401_B.RPSectow = Kensei150401_P.RPSectow_Gain *
      Kensei150401_B.Switch1;

    /* Gain: '<S46>/Tyre radius' */
    Kensei150401_B.ms = Kensei150401_P.Tyreradius_Gain * Kensei150401_B.RPSectow;

    /* Gain: '<S46>/m//s to km//h' */
    Kensei150401_B.mstokmh = Kensei150401_P.mstokmh_Gain * Kensei150401_B.ms;

    /* Rounding: '<S46>/Rounded fl_kmh' */
    Kensei150401_B.Roundedfl_kmh = rt_roundd_snf(Kensei150401_B.mstokmh);

    /* Saturate: '<S46>/Limit 80km//h' */
    tmp = Kensei150401_B.Roundedfl_kmh;
    u = Kensei150401_P.Limit80kmh_LowerSat;
    u_0 = Kensei150401_P.Limit80kmh_UpperSat;
    if (tmp >= u_0) {
      Kensei150401_B.Limit80kmh = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.Limit80kmh = u;
    } else {
      Kensei150401_B.Limit80kmh = tmp;
    }

    /* End of Saturate: '<S46>/Limit 80km//h' */

    /* Lookup_n-D: '<S8>/Throttle Map1' */
    Kensei150401_B.ThrottleMap1 = look1_binlxpw(Kensei150401_B.inADC2,
      Kensei150401_P.ThrottleMap1_bp01Data,
      Kensei150401_P.ThrottleMap1_tableData, 8U);

    /* Gain: '<S8>/to percent' */
    Kensei150401_B.topercent = Kensei150401_P.topercent_Gain *
      Kensei150401_B.ThrottleMap1;

    /* Rounding: '<S8>/Rounding Function2' */
    Kensei150401_B.RoundingFunction2_d = rt_roundd_snf(Kensei150401_B.topercent);

    /* Saturate: '<S8>/Pedal Limit 100%' */
    tmp = Kensei150401_B.RoundingFunction2_d;
    u = Kensei150401_P.PedalLimit100_LowerSat;
    u_0 = Kensei150401_P.PedalLimit100_UpperSat;
    if (tmp >= u_0) {
      Kensei150401_B.PedalLimit100 = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.PedalLimit100 = u;
    } else {
      Kensei150401_B.PedalLimit100 = tmp;
    }

    /* End of Saturate: '<S8>/Pedal Limit 100%' */

    /* Chart: '<S49>/Chart (Propulsion Modes)' incorporates:
     *  Constant: '<S1>/sportcomm'
     */
    Kensei150401_DWork.presentTicks = Kensei150401_M->Timing.clockTick1;
    Kensei150401_DWork.elapsedTicks = Kensei150401_DWork.presentTicks -
      Kensei150401_DWork.previousTicks;
    Kensei150401_DWork.previousTicks = Kensei150401_DWork.presentTicks;
    if ((uint32_T)Kensei150401_DWork.temporalCounter_i1 +
        Kensei150401_DWork.elapsedTicks <= 8191U) {
      Kensei150401_DWork.temporalCounter_i1 = (uint16_T)((uint32_T)
        Kensei150401_DWork.temporalCounter_i1 + Kensei150401_DWork.elapsedTicks);
    } else {
      Kensei150401_DWork.temporalCounter_i1 = 8191U;
    }

    if ((uint32_T)Kensei150401_DWork.temporalCounter_i2 +
        Kensei150401_DWork.elapsedTicks <= 8191U) {
      Kensei150401_DWork.temporalCounter_i2 = (uint16_T)((uint32_T)
        Kensei150401_DWork.temporalCounter_i2 + Kensei150401_DWork.elapsedTicks);
    } else {
      Kensei150401_DWork.temporalCounter_i2 = 8191U;
    }

    /* Gateway: Peripherals/Stateflow/Chart (Propulsion Modes) */
    /* During: Peripherals/Stateflow/Chart (Propulsion Modes) */
    if (Kensei150401_DWork.is_active_c3_Kensei150401 == 0U) {
      /* Entry: Peripherals/Stateflow/Chart (Propulsion Modes) */
      Kensei150401_DWork.is_active_c3_Kensei150401 = 1U;

      /* Entry Internal: Peripherals/Stateflow/Chart (Propulsion Modes) */
      Kensei150401_DWork.is_active_response = 1U;

      /* Entry Internal 'response': '<S78>:303' */
      /* Transition: '<S78>:305' */
      Kensei150401_DWork.is_response = Kensei150401_IN_eco;

      /* Entry 'eco': '<S78>:306' */
      Kensei150401_B.sport = 1.0;
      Kensei150401_DWork.is_active_gearmode = 1U;

      /* Entry Internal 'gearmode': '<S78>:302' */
      /* Transition: '<S78>:12' */
      Kensei150401_DWork.is_gearmode = Kensei150401_IN_Parking;

      /* Entry 'Parking': '<S78>:15' */
      Kensei150401_B.prop = 0.0;
      Kensei150401_B.pedalprop = 0.0;
      Kensei150401_B.steerprop = 0.0;
      Kensei150401_B.revR = TRUE;
      Kensei150401_B.revL = FALSE;
      Kensei150401_B.mode = 2.0;
      Kensei150401_B.zptrate = 0.0;

      /* Entry Internal 'Parking': '<S78>:15' */
      /* Transition: '<S78>:259' */
      Kensei150401_DWork.is_Parking = Kensei150401_IN_wait;
      Kensei150401_DWork.temporalCounter_i1 = 0U;
    } else {
      /* During 'response': '<S78>:303' */
      if (Kensei150401_DWork.is_response == Kensei150401_IN_eco) {
        /* During 'eco': '<S78>:306' */
        if ((Kensei150401_P.sportcomm_Value == 0.0) &&
            (!(Kensei150401_DWork.is_gearmode == Kensei150401_IN_ZPT))) {
          /* Transition: '<S78>:308' */
          Kensei150401_DWork.is_response = Kensei150401_IN_sport;

          /* Entry 'sport': '<S78>:307' */
          Kensei150401_B.sport = 0.0;
        }
      } else {
        /* During 'sport': '<S78>:307' */
        if ((Kensei150401_P.sportcomm_Value == 1.0) &&
            (!(Kensei150401_DWork.is_gearmode == Kensei150401_IN_ZPT))) {
          /* Transition: '<S78>:304' */
          Kensei150401_DWork.is_response = Kensei150401_IN_eco;

          /* Entry 'eco': '<S78>:306' */
          Kensei150401_B.sport = 1.0;
        }
      }

      Kensei150401_gearmode();
    }

    /* End of Chart: '<S49>/Chart (Propulsion Modes)' */

    /* Gain: '<S86>/Gain1' incorporates:
     *  Constant: '<S86>/Wheel track'
     */
    Kensei150401_B.Gain1_i = Kensei150401_P.Gain1_Gain_i *
      Kensei150401_P.Wheeltrack_Value;

    /* Gain: '<S86>/Gain' incorporates:
     *  Constant: '<S86>/Wheel base'
     */
    Kensei150401_B.Gain = Kensei150401_P.Gain_Gain_n *
      Kensei150401_P.Wheelbase_Value;

    /* Math: '<S86>/Math Function1' */
    Kensei150401_B.MathFunction1_o = Kensei150401_B.Gain * Kensei150401_B.Gain;

    /* Product: '<S135>/Product' incorporates:
     *  Constant: '<S135>/Steering Ratio'
     */
    Kensei150401_B.Product = Kensei150401_B.limitrotationdata /
      Kensei150401_P.SteeringRatio_Value;

    /* Gain: '<S135>/ratio1' */
    Kensei150401_B.ratio1 = Kensei150401_P.ratio1_Gain * Kensei150401_B.Product;

    /* Rounding: '<S135>/Rounding Function1' */
    Kensei150401_B.RoundingFunction1 = rt_roundd_snf(Kensei150401_B.ratio1);

    /* Gain: '<S135>/ratio2' */
    Kensei150401_B.ratio2 = Kensei150401_P.ratio2_Gain *
      Kensei150401_B.RoundingFunction1;

    /* Gain: '<S117>/Gain1' */
    Kensei150401_B.Gain1_f = Kensei150401_P.Gain1_Gain_a * Kensei150401_B.ratio2;

    /* Abs: '<S86>/Abs' */
    Kensei150401_B.Abs = fabs(Kensei150401_B.Gain1_f);

    /* Fcn: '<S86>/tan' */
    Kensei150401_B.tan_d = tan(Kensei150401_B.Abs);

    /* Product: '<S86>/Product' incorporates:
     *  Constant: '<S86>/Wheel base'
     */
    Kensei150401_B.Product_l = Kensei150401_P.Wheelbase_Value /
      Kensei150401_B.tan_d;

    /* Math: '<S86>/Math Function' */
    Kensei150401_B.MathFunction_l = Kensei150401_B.Product_l *
      Kensei150401_B.Product_l;

    /* Sum: '<S86>/Sum' */
    Kensei150401_B.Sum_a = Kensei150401_B.MathFunction1_o +
      Kensei150401_B.MathFunction_l;

    /* Sqrt: '<S86>/R' */
    Kensei150401_B.R = sqrt(Kensei150401_B.Sum_a);

    /* Sum: '<S86>/Sum1' */
    Kensei150401_B.Sum1 = Kensei150401_B.Gain1_i + Kensei150401_B.R;

    /* Product: '<S86>/outertyre' incorporates:
     *  Constant: '<S86>/Wheel base'
     */
    Kensei150401_B.outertyre = Kensei150401_P.Wheelbase_Value /
      Kensei150401_B.Sum1;

    /* Sum: '<S86>/Sum2' */
    Kensei150401_B.Sum2 = Kensei150401_B.R - Kensei150401_B.Gain1_i;

    /* Product: '<S86>/innertyre ' incorporates:
     *  Constant: '<S86>/Wheel base'
     */
    Kensei150401_B.innertyre = Kensei150401_P.Wheelbase_Value /
      Kensei150401_B.Sum2;

    /* Gain: '<S86>/Gain2' */
    Kensei150401_B.Gain2 = Kensei150401_P.Gain2_Gain_g *
      Kensei150401_B.innertyre;

    /* Fcn: '<S86>/switching' */
    Kensei150401_B.switching = (real_T)(Kensei150401_B.ratio2 >= 0.0) *
      Kensei150401_B.outertyre + (real_T)(Kensei150401_B.ratio2 < 0.0) *
      Kensei150401_B.Gain2;

    /* Gain: '<S118>/Gain' */
    Kensei150401_B.Gain_e = Kensei150401_P.Gain_Gain_h *
      Kensei150401_B.switching;

    /* Gain: '<S91>/Gain1' */
    Kensei150401_B.Gain1_h = Kensei150401_P.Gain1_Gain_m * Kensei150401_B.ratio2;

    /* Abs: '<S83>/Abs1' */
    Kensei150401_B.Abs1 = fabs(Kensei150401_B.Gain1_h);

    /* Gain: '<S87>/km//h to m//s' incorporates:
     *  Constant: '<S1>/kmh'
     */
    Kensei150401_B.kmhtoms = Kensei150401_P.kmhtoms_Gain *
      Kensei150401_P.kmh_Value;

    /* Math: '<S87>/Math Function' */
    Kensei150401_B.MathFunction_m = Kensei150401_B.kmhtoms *
      Kensei150401_B.kmhtoms;

    /* Product: '<S87>/Product' incorporates:
     *  Constant: '<S87>/A'
     *  Constant: '<S87>/m'
     */
    Kensei150401_B.Product_o = Kensei150401_P.A_Value * Kensei150401_P.m_Value;

    /* Product: '<S87>/Product2' incorporates:
     *  Constant: '<S87>/Cr'
     *  Constant: '<S87>/L'
     */
    Kensei150401_B.Product2 = Kensei150401_P.L_Value * Kensei150401_P.Cr_Value;

    /* Product: '<S87>/Product1' */
    Kensei150401_B.Product1 = Kensei150401_B.Product_o / Kensei150401_B.Product2;

    /* Product: '<S87>/Product3' */
    Kensei150401_B.Product3 = Kensei150401_B.MathFunction_m *
      Kensei150401_B.Product1;

    /* Sum: '<S87>/Sum' incorporates:
     *  Constant: '<S87>/B'
     */
    Kensei150401_B.Sum_d = Kensei150401_B.Product3 - Kensei150401_P.B_Value;

    /* Product: '<S87>/Product5' incorporates:
     *  Constant: '<S87>/B'
     *  Constant: '<S87>/m'
     */
    Kensei150401_B.Product5 = Kensei150401_P.m_Value * Kensei150401_P.B_Value;

    /* Product: '<S87>/Product6' incorporates:
     *  Constant: '<S87>/Cf'
     *  Constant: '<S87>/L'
     */
    Kensei150401_B.Product6 = Kensei150401_P.L_Value * Kensei150401_P.Cf_Value;

    /* Product: '<S87>/Product7' */
    Kensei150401_B.Product7 = Kensei150401_B.Product5 / Kensei150401_B.Product6;

    /* Product: '<S87>/Product8' */
    Kensei150401_B.Product8 = Kensei150401_B.MathFunction_m *
      Kensei150401_B.Product7;

    /* Sum: '<S87>/Sum1' incorporates:
     *  Constant: '<S87>/A'
     */
    Kensei150401_B.Sum1_a = Kensei150401_P.A_Value + Kensei150401_B.Product8;

    /* Product: '<S87>/K_ratio' */
    Kensei150401_B.K_ratio = Kensei150401_B.Sum_d / Kensei150401_B.Sum1_a;

    /* Saturate: '<S87>/Saturation' */
    tmp = Kensei150401_B.K_ratio;
    u = Kensei150401_P.Saturation_LowerSat_k;
    u_0 = Kensei150401_P.Saturation_UpperSat_f;
    if (tmp >= u_0) {
      Kensei150401_B.Saturation = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.Saturation = u;
    } else {
      Kensei150401_B.Saturation = tmp;
    }

    /* End of Saturate: '<S87>/Saturation' */

    /* Product: '<S87>/Product4' */
    Kensei150401_B.Product4 = Kensei150401_B.ratio2 * Kensei150401_B.Saturation;

    /* Gain: '<S87>/ratio1' */
    Kensei150401_B.ratio1_g = Kensei150401_P.ratio1_Gain_l *
      Kensei150401_B.Product4;

    /* Rounding: '<S87>/Rounding Function1' */
    Kensei150401_B.RoundingFunction1_l = rt_roundd_snf(Kensei150401_B.ratio1_g);

    /* Gain: '<S87>/ratio2' */
    Kensei150401_B.ratio2_m = Kensei150401_P.ratio2_Gain_d *
      Kensei150401_B.RoundingFunction1_l;

    /* Gain: '<S92>/Gain1' */
    Kensei150401_B.Gain1_o = Kensei150401_P.Gain1_Gain_b *
      Kensei150401_B.ratio2_m;

    /* Abs: '<S83>/Abs' */
    Kensei150401_B.Abs_j = fabs(Kensei150401_B.Gain1_o);

    /* Fcn: '<S83>/Lf' incorporates:
     *  Constant: '<S83>/Wheel base'
     */
    Kensei150401_B.Lf = ((real_T)(tan(Kensei150401_B.Abs1) == 0.0) *
                         2.2204460492503131e-16 + tan(Kensei150401_B.Abs1)) /
      ((real_T)(Kensei150401_B.Abs_j == 0.0) * 2.2204460492503131e-16 + tan
       (Kensei150401_B.Abs_j)) * Kensei150401_P.Wheelbase_Value_e / ((real_T)
      (tan(Kensei150401_B.Abs1) / ((real_T)(Kensei150401_B.Abs_j == 0.0) *
      2.2204460492503131e-16 + tan(Kensei150401_B.Abs_j)) + 1.0 == 0.0) *
      2.2204460492503131e-16 + (tan(Kensei150401_B.Abs1) / ((real_T)
      (Kensei150401_B.Abs_j == 0.0) * 2.2204460492503131e-16 + tan
      (Kensei150401_B.Abs_j)) + 1.0));

    /* Fcn: '<S83>/Rc' */
    Kensei150401_B.Rc = Kensei150401_B.Lf / ((real_T)(tan(Kensei150401_B.Abs1) ==
      0.0) * 2.2204460492503131e-16 + tan(Kensei150401_B.Abs1));

    /* Fcn: '<S83>/angle_Fi' incorporates:
     *  Constant: '<S83>/Wheel track'
     */
    Kensei150401_B.angle_Fi = atan(Kensei150401_B.Lf / (Kensei150401_B.Rc -
      Kensei150401_P.Wheeltrack_Value_o / 2.0));

    /* Fcn: '<S83>/angle_Fo' incorporates:
     *  Constant: '<S83>/Wheel track'
     */
    Kensei150401_B.angle_Fo = atan(Kensei150401_B.Lf /
      (Kensei150401_P.Wheeltrack_Value_o / 2.0 + Kensei150401_B.Rc));

    /* Fcn: '<S83>/switching4' */
    Kensei150401_B.switching4 = (real_T)(Kensei150401_B.Gain1_o >= 0.0) *
      Kensei150401_B.angle_Fi - (real_T)(Kensei150401_B.Gain1_o < 0.0) *
      Kensei150401_B.angle_Fo;

    /* Gain: '<S96>/Gain' */
    Kensei150401_B.Gain_h = Kensei150401_P.Gain_Gain_d *
      Kensei150401_B.switching4;

    /* Gain: '<S83>/Gain3' */
    Kensei150401_B.Gain3 = Kensei150401_P.Gain3_Gain_d * Kensei150401_B.Gain_h;

    /* Chart: '<S49>/Chart (AWS FWS)' incorporates:
     *  Constant: '<S1>/AWScomm'
     */
    /* Gateway: Peripherals/Stateflow/Chart (AWS FWS) */
    /* During: Peripherals/Stateflow/Chart (AWS FWS) */
    if (Kensei150401_DWork.is_active_c1_Kensei150401 == 0U) {
      /* Entry: Peripherals/Stateflow/Chart (AWS FWS) */
      Kensei150401_DWork.is_active_c1_Kensei150401 = 1U;

      /* Entry Internal: Peripherals/Stateflow/Chart (AWS FWS) */
      /* Transition: '<S77>:7' */
      Kensei150401_DWork.is_c1_Kensei150401 = Kensei150401_IN_AWS;

      /* Entry 'AWS': '<S77>:1' */
      Kensei150401_B.AWS = 1.0;
    } else if (Kensei150401_DWork.is_c1_Kensei150401 == Kensei150401_IN_AWS) {
      /* During 'AWS': '<S77>:1' */
      if (Kensei150401_P.AWScomm_Value == 0.0) {
        /* Transition: '<S77>:5' */
        Kensei150401_DWork.is_c1_Kensei150401 = Kensei150401_IN_FWS;

        /* Entry 'FWS': '<S77>:2' */
        Kensei150401_B.AWS = 0.0;
      }
    } else {
      /* During 'FWS': '<S77>:2' */
      if (Kensei150401_P.AWScomm_Value == 1.0) {
        /* Transition: '<S77>:6' */
        Kensei150401_DWork.is_c1_Kensei150401 = Kensei150401_IN_AWS;

        /* Entry 'AWS': '<S77>:1' */
        Kensei150401_B.AWS = 1.0;
      }
    }

    /* End of Chart: '<S49>/Chart (AWS FWS)' */

    /* Fcn: '<S7>/switching4' */
    Kensei150401_B.switching4_i = (real_T)(Kensei150401_B.AWS == 1.0) *
      Kensei150401_B.Gain3 + (real_T)(Kensei150401_B.AWS == 0.0) *
      Kensei150401_B.Gain_e;

    /* Gain: '<S109>/ratio3' */
    Kensei150401_B.ratio3 = Kensei150401_P.ratio3_Gain *
      Kensei150401_B.switching4_i;

    /* Rounding: '<S109>/Rounding Function2' */
    Kensei150401_B.RoundingFunction2_a = rt_roundd_snf(Kensei150401_B.ratio3);

    /* Gain: '<S109>/ratio4' */
    Kensei150401_B.ratio4 = Kensei150401_P.ratio4_Gain *
      Kensei150401_B.RoundingFunction2_a;

    /* Saturate: '<S85>/FR_ref degree' */
    tmp = Kensei150401_B.ratio4;
    u = Kensei150401_P.FR_refdegree_LowerSat;
    u_0 = Kensei150401_P.FR_refdegree_UpperSat;
    if (tmp >= u_0) {
      Kensei150401_B.FR_refdegree = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.FR_refdegree = u;
    } else {
      Kensei150401_B.FR_refdegree = tmp;
    }

    /* End of Saturate: '<S85>/FR_ref degree' */

    /* Switch: '<S85>/Switch2' */
    if (Kensei150401_B.zptrate >= Kensei150401_P.Switch2_Threshold_g) {
      /* Switch: '<S85>/Switch' */
      if (Kensei150401_B.clear2go >= Kensei150401_P.Switch_Threshold_c) {
        Kensei150401_B.Switch_p = Kensei150401_B.FRdeg;
      } else {
        Kensei150401_B.Switch_p = Kensei150401_B.FR_refdegree;
      }

      /* End of Switch: '<S85>/Switch' */
      Kensei150401_B.Switch2 = Kensei150401_B.Switch_p;
    } else {
      Kensei150401_B.Switch2 = Kensei150401_B.FR_refdegree;
    }

    /* End of Switch: '<S85>/Switch2' */

    /* Gain: '<S115>/direction' */
    Kensei150401_B.direction = Kensei150401_P.direction_Gain *
      Kensei150401_B.Switch2;

    /* Gain: '<S115>/degree to rad' */
    Kensei150401_B.degreetorad = Kensei150401_P.degreetorad_Gain *
      Kensei150401_B.direction;

    /* Sum: '<S115>/Sum4' */
    Kensei150401_B.Sum4 = Kensei150401_B.Epsilon + Kensei150401_B.degreetorad;

    /* Fcn: '<S115>/Fcn1' */
    Kensei150401_B.Fcn1 = cos(Kensei150401_B.Sum4);

    /* Product: '<S115>/Divide1' */
    Kensei150401_B.Divide1 = Kensei150401_B.Fcn1 * Kensei150401_B.Divide2;

    /* Sum: '<S115>/Sum3' */
    Kensei150401_B.Sum3 = (Kensei150401_B.MathFunction +
      Kensei150401_B.MathFunction1) - Kensei150401_B.Divide1;

    /* Sqrt: '<S115>/Sqrt' */
    Kensei150401_B.Sqrt = sqrt(Kensei150401_B.Sum3);

    /* Sum: '<S115>/Sum2' incorporates:
     *  Constant: '<S115>/d'
     */
    Kensei150401_B.Sum2_o = Kensei150401_B.Sqrt - Kensei150401_P.d_Value;

    /* Gain: '<S115>/m to mm' */
    Kensei150401_B.mtomm = Kensei150401_P.mtomm_Gain * Kensei150401_B.Sum2_o;

    /* Gain: '<S112>/FR_Volt per mm2' incorporates:
     *  Constant: '<S112>/FR ADC Center'
     */
    Kensei150401_B.FR_Voltpermm2 = Kensei150401_P.FR_Voltpermm2_Gain *
      Kensei150401_P.FRADCCenter_Value;

    /* Sum: '<S112>/Sum1' */
    Kensei150401_B.Sum1_o = Kensei150401_B.mtomm + Kensei150401_B.FR_Voltpermm2;

    /* Gain: '<S112>/FR_mm to volt' */
    Kensei150401_B.FR_mmtovolt = Kensei150401_P.FR_mmtovolt_Gain *
      Kensei150401_B.Sum1_o;

    /* Saturate: '<S85>/FR_ref input Saturation' */
    tmp = Kensei150401_B.FR_mmtovolt;
    u = Kensei150401_P.FR_refinputSaturation_LowerSat;
    u_0 = Kensei150401_P.FR_refinputSaturation_UpperSat;
    if (tmp >= u_0) {
      Kensei150401_B.FR_refinputSaturation = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.FR_refinputSaturation = u;
    } else {
      Kensei150401_B.FR_refinputSaturation = tmp;
    }

    /* End of Saturate: '<S85>/FR_ref input Saturation' */

    /* Gain: '<S110>/ratio3' */
    Kensei150401_B.ratio3_l = Kensei150401_P.ratio3_Gain_g *
      Kensei150401_B.FR_refinputSaturation;

    /* Rounding: '<S110>/Rounding Function2' */
    Kensei150401_B.RoundingFunction2_n = rt_roundd_snf(Kensei150401_B.ratio3_l);

    /* Gain: '<S110>/ratio4' */
    Kensei150401_B.ratio4_j = Kensei150401_P.ratio4_Gain_i *
      Kensei150401_B.RoundingFunction2_n;
  }

  /* StateSpace: '<S85>/Analog Filter_FR_Pos' */
  {
    Kensei150401_B.AnalogFilter_FR_Pos = Kensei150401_P.AnalogFilter_FR_Pos_C*
      Kensei150401_X.AnalogFilter_FR_Pos_CSTATE;
  }

  /* Gain: '<S111>/ratio3' */
  Kensei150401_B.ratio3_c = Kensei150401_P.ratio3_Gain_l *
    Kensei150401_B.AnalogFilter_FR_Pos;

  /* Rounding: '<S111>/Rounding Function2' */
  Kensei150401_B.RoundingFunction2_dz = rt_roundd_snf(Kensei150401_B.ratio3_c);

  /* Gain: '<S111>/ratio4' */
  Kensei150401_B.ratio4_g = Kensei150401_P.ratio4_Gain_f *
    Kensei150401_B.RoundingFunction2_dz;

  /* Sum: '<S85>/Sum1' */
  Kensei150401_B.Sum1_d = Kensei150401_B.ratio4_j - Kensei150401_B.ratio4_g;

  /* Integrator: '<S107>/Integrator' */
  Kensei150401_B.Integrator = Kensei150401_X.Integrator_CSTATE;

  /* Gain: '<S107>/Derivative Gain' */
  Kensei150401_B.DerivativeGain = Kensei150401_P.DerivativeGain_Gain *
    Kensei150401_B.Sum1_d;

  /* Integrator: '<S107>/Filter' */
  Kensei150401_B.Filter = Kensei150401_X.Filter_CSTATE;

  /* Sum: '<S107>/SumD' */
  Kensei150401_B.SumD = Kensei150401_B.DerivativeGain - Kensei150401_B.Filter;

  /* Gain: '<S107>/Filter Coefficient' */
  Kensei150401_B.FilterCoefficient = Kensei150401_P.FilterCoefficient_Gain *
    Kensei150401_B.SumD;

  /* Sum: '<S107>/Sum' */
  Kensei150401_B.Sum_h = (Kensei150401_B.Sum1_d + Kensei150401_B.Integrator) +
    Kensei150401_B.FilterCoefficient;

  /* Gain: '<S107>/Proportional Gain' */
  Kensei150401_B.ProportionalGain = Kensei150401_P.ProportionalGain_Gain *
    Kensei150401_B.Sum_h;

  /* Saturate: '<S107>/Saturation' */
  tmp = Kensei150401_B.ProportionalGain;
  u = Kensei150401_P.Saturation_LowerSat_b;
  u_0 = Kensei150401_P.Saturation_UpperSat_m;
  if (tmp >= u_0) {
    Kensei150401_B.Saturation_h = u_0;
  } else if (tmp <= u) {
    Kensei150401_B.Saturation_h = u;
  } else {
    Kensei150401_B.Saturation_h = tmp;
  }

  /* End of Saturate: '<S107>/Saturation' */

  /* Abs: '<S85>/Abs' */
  Kensei150401_B.Abs_c = fabs(Kensei150401_B.Sum1_d);
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Constant: '<S85>/Constant' */
    Kensei150401_B.Constant = Kensei150401_P.Constant_Value_m;
  }

  /* Switch: '<S85>/Switch1' */
  if (Kensei150401_B.Abs_c > Kensei150401_P.Switch1_Threshold_c) {
    /* Switch: '<S108>/Switch2' */
    if (Kensei150401_B.Switch_FR >= Kensei150401_P.Switch2_Threshold) {
      Kensei150401_B.Switch2_lr = Kensei150401_B.FRwm;
    } else {
      /* Abs: '<S108>/Abs' */
      Kensei150401_B.Abs_ht = fabs(Kensei150401_B.Saturation_h);
      Kensei150401_B.Switch2_lr = Kensei150401_B.Abs_ht;
    }

    /* End of Switch: '<S108>/Switch2' */

    /* Gain: '<S108>/RealPWMin' */
    Kensei150401_B.RealPWMin_c = Kensei150401_P.RealPWMin_Gain *
      Kensei150401_B.Switch2_lr;
    Kensei150401_B.Switch1_e = Kensei150401_B.RealPWMin_c;
  } else {
    Kensei150401_B.Switch1_e = Kensei150401_B.Constant;
  }

  /* End of Switch: '<S85>/Switch1' */
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Constant: '<S7>/Offset5' */
    Kensei150401_B.Offset5 = Kensei150401_P.Offset5_Value;
  }

  /* Sum: '<S7>/Sum5' */
  Kensei150401_B.Sum5 = Kensei150401_B.Switch1_e + Kensei150401_B.Offset5;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* S-Function (rti_commonblock): '<S39>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* write PWM Period and DutyCycle for output channel 1 on port 1 */
    dio_tp4_pwm_update(DIO_TP4_1_MODULE_ADDR , 1, 1, (real_T)
                       Kensei150401_P.u000Hz_Value, (real_T) Kensei150401_B.Sum5);

    /* Constant: '<S98>/FLpwm' */
    Kensei150401_B.FLpwm = Kensei150401_P.FLpwm_Value;

    /* Math: '<S105>/Math Function' incorporates:
     *  Constant: '<S105>/b'
     */
    Kensei150401_B.MathFunction_o = Kensei150401_P.b_Value_m *
      Kensei150401_P.b_Value_m;

    /* Math: '<S105>/Math Function1' incorporates:
     *  Constant: '<S105>/c'
     */
    Kensei150401_B.MathFunction1_m = Kensei150401_P.c_Value_n *
      Kensei150401_P.c_Value_n;

    /* Math: '<S105>/Math Function2' incorporates:
     *  Constant: '<S105>/d'
     */
    Kensei150401_B.MathFunction2_b = Kensei150401_P.d_Value_i *
      Kensei150401_P.d_Value_i;

    /* Sum: '<S105>/Sum' */
    Kensei150401_B.Sum_b = (Kensei150401_B.MathFunction_o +
      Kensei150401_B.MathFunction1_m) - Kensei150401_B.MathFunction2_b;

    /* Product: '<S105>/Divide2' incorporates:
     *  Constant: '<S105>/b'
     *  Constant: '<S105>/c'
     *  Constant: '<S105>/constant'
     */
    Kensei150401_B.Divide2_b = Kensei150401_P.constant_Value_h *
      Kensei150401_P.c_Value_n * Kensei150401_P.b_Value_m;

    /* Product: '<S105>/Divide' */
    Kensei150401_B.Divide_b = Kensei150401_B.Sum_b / Kensei150401_B.Divide2_b;

    /* Fcn: '<S105>/Epsilon' */
    tmp = Kensei150401_B.Divide_b;
    if (tmp >= 1.0) {
      tmp = 1.0;
    } else {
      if (tmp <= -1.0) {
        tmp = -1.0;
      }
    }

    tmp = acos(tmp);
    Kensei150401_B.Epsilon_d = tmp;

    /* End of Fcn: '<S105>/Epsilon' */

    /* Switch: '<S86>/Switch1' */
    if (Kensei150401_B.ratio2 >= Kensei150401_P.Switch1_Threshold_p) {
      Kensei150401_B.Switch1_j = Kensei150401_B.innertyre;
    } else {
      /* Gain: '<S86>/Gain3' */
      Kensei150401_B.Gain3_n = Kensei150401_P.Gain3_Gain *
        Kensei150401_B.outertyre;
      Kensei150401_B.Switch1_j = Kensei150401_B.Gain3_n;
    }

    /* End of Switch: '<S86>/Switch1' */

    /* Gain: '<S119>/Gain' */
    Kensei150401_B.Gain_o = Kensei150401_P.Gain_Gain_kz *
      Kensei150401_B.Switch1_j;

    /* Fcn: '<S83>/switching2' */
    Kensei150401_B.switching2 = (real_T)(Kensei150401_B.Gain1_o >= 0.0) *
      Kensei150401_B.angle_Fo - (real_T)(Kensei150401_B.Gain1_o < 0.0) *
      Kensei150401_B.angle_Fi;

    /* Gain: '<S95>/Gain' */
    Kensei150401_B.Gain_m = Kensei150401_P.Gain_Gain_c3 *
      Kensei150401_B.switching2;

    /* Gain: '<S83>/Gain2' */
    Kensei150401_B.Gain2_c = Kensei150401_P.Gain2_Gain_d * Kensei150401_B.Gain_m;

    /* Fcn: '<S7>/switching3' */
    Kensei150401_B.switching3 = (real_T)(Kensei150401_B.AWS == 1.0) *
      Kensei150401_B.Gain2_c + (real_T)(Kensei150401_B.AWS == 0.0) *
      Kensei150401_B.Gain_o;

    /* Gain: '<S99>/ratio3' */
    Kensei150401_B.ratio3_k = Kensei150401_P.ratio3_Gain_n *
      Kensei150401_B.switching3;

    /* Rounding: '<S99>/Rounding Function2' */
    Kensei150401_B.RoundingFunction2_df = rt_roundd_snf(Kensei150401_B.ratio3_k);

    /* Gain: '<S99>/ratio4' */
    Kensei150401_B.ratio4_gb = Kensei150401_P.ratio4_Gain_l *
      Kensei150401_B.RoundingFunction2_df;

    /* Saturate: '<S84>/FL_ref degree' */
    tmp = Kensei150401_B.ratio4_gb;
    u = Kensei150401_P.FL_refdegree_LowerSat;
    u_0 = Kensei150401_P.FL_refdegree_UpperSat;
    if (tmp >= u_0) {
      Kensei150401_B.FL_refdegree = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.FL_refdegree = u;
    } else {
      Kensei150401_B.FL_refdegree = tmp;
    }

    /* End of Saturate: '<S84>/FL_ref degree' */

    /* Switch: '<S84>/Switch2' */
    if (Kensei150401_B.zptrate >= Kensei150401_P.Switch2_Threshold_i) {
      /* Switch: '<S84>/Switch' */
      if (Kensei150401_B.clear2go >= Kensei150401_P.Switch_Threshold) {
        Kensei150401_B.Switch_o = Kensei150401_B.FLdeg;
      } else {
        Kensei150401_B.Switch_o = Kensei150401_B.FL_refdegree;
      }

      /* End of Switch: '<S84>/Switch' */
      Kensei150401_B.Switch2_p = Kensei150401_B.Switch_o;
    } else {
      Kensei150401_B.Switch2_p = Kensei150401_B.FL_refdegree;
    }

    /* End of Switch: '<S84>/Switch2' */

    /* Gain: '<S105>/degree to rad' */
    Kensei150401_B.degreetorad_d = Kensei150401_P.degreetorad_Gain_i *
      Kensei150401_B.Switch2_p;

    /* Sum: '<S105>/Sum4' */
    Kensei150401_B.Sum4_b = Kensei150401_B.Epsilon_d +
      Kensei150401_B.degreetorad_d;

    /* Fcn: '<S105>/Fcn1' */
    Kensei150401_B.Fcn1_k = cos(Kensei150401_B.Sum4_b);

    /* Product: '<S105>/Divide1' */
    Kensei150401_B.Divide1_p = Kensei150401_B.Fcn1_k * Kensei150401_B.Divide2_b;

    /* Sum: '<S105>/Sum3' */
    Kensei150401_B.Sum3_m = (Kensei150401_B.MathFunction_o +
      Kensei150401_B.MathFunction1_m) - Kensei150401_B.Divide1_p;

    /* Sqrt: '<S105>/Sqrt' */
    Kensei150401_B.Sqrt_h = sqrt(Kensei150401_B.Sum3_m);

    /* Sum: '<S105>/Sum2' incorporates:
     *  Constant: '<S105>/d'
     */
    Kensei150401_B.Sum2_h = Kensei150401_B.Sqrt_h - Kensei150401_P.d_Value_i;

    /* Gain: '<S105>/m to mm' */
    Kensei150401_B.mtomm_k = Kensei150401_P.mtomm_Gain_k * Kensei150401_B.Sum2_h;

    /* Gain: '<S102>/FL_Volt per mm2' incorporates:
     *  Constant: '<S102>/FL ADC Center'
     */
    Kensei150401_B.FL_Voltpermm2 = Kensei150401_P.FL_Voltpermm2_Gain *
      Kensei150401_P.FLADCCenter_Value;

    /* Sum: '<S102>/Sum1' */
    Kensei150401_B.Sum1_k = Kensei150401_B.mtomm_k +
      Kensei150401_B.FL_Voltpermm2;

    /* Gain: '<S102>/FL_mm to volt' */
    Kensei150401_B.FL_mmtovolt = Kensei150401_P.FL_mmtovolt_Gain *
      Kensei150401_B.Sum1_k;

    /* Saturate: '<S84>/FL_ref input Saturation' */
    tmp = Kensei150401_B.FL_mmtovolt;
    u = Kensei150401_P.FL_refinputSaturation_LowerSat;
    u_0 = Kensei150401_P.FL_refinputSaturation_UpperSat;
    if (tmp >= u_0) {
      Kensei150401_B.FL_refinputSaturation = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.FL_refinputSaturation = u;
    } else {
      Kensei150401_B.FL_refinputSaturation = tmp;
    }

    /* End of Saturate: '<S84>/FL_ref input Saturation' */

    /* Gain: '<S100>/ratio3' */
    Kensei150401_B.ratio3_h = Kensei150401_P.ratio3_Gain_j *
      Kensei150401_B.FL_refinputSaturation;

    /* Rounding: '<S100>/Rounding Function2' */
    Kensei150401_B.RoundingFunction2_nv = rt_roundd_snf(Kensei150401_B.ratio3_h);

    /* Gain: '<S100>/ratio4' */
    Kensei150401_B.ratio4_j0 = Kensei150401_P.ratio4_Gain_d *
      Kensei150401_B.RoundingFunction2_nv;
  }

  /* StateSpace: '<S84>/Analog Filter_FL_Pos' */
  {
    Kensei150401_B.AnalogFilter_FL_Pos = Kensei150401_P.AnalogFilter_FL_Pos_C*
      Kensei150401_X.AnalogFilter_FL_Pos_CSTATE;
  }

  /* Gain: '<S101>/ratio3' */
  Kensei150401_B.ratio3_j = Kensei150401_P.ratio3_Gain_nn *
    Kensei150401_B.AnalogFilter_FL_Pos;

  /* Rounding: '<S101>/Rounding Function2' */
  Kensei150401_B.RoundingFunction2_e = rt_roundd_snf(Kensei150401_B.ratio3_j);

  /* Gain: '<S101>/ratio4' */
  Kensei150401_B.ratio4_p = Kensei150401_P.ratio4_Gain_ls *
    Kensei150401_B.RoundingFunction2_e;

  /* Sum: '<S84>/Sum' */
  Kensei150401_B.Sum_o = Kensei150401_B.ratio4_j0 - Kensei150401_B.ratio4_p;

  /* Integrator: '<S97>/Integrator' */
  Kensei150401_B.Integrator_k = Kensei150401_X.Integrator_CSTATE_d;

  /* Gain: '<S97>/Derivative Gain' */
  Kensei150401_B.DerivativeGain_o = Kensei150401_P.DerivativeGain_Gain_k *
    Kensei150401_B.Sum_o;

  /* Integrator: '<S97>/Filter' */
  Kensei150401_B.Filter_e = Kensei150401_X.Filter_CSTATE_f;

  /* Sum: '<S97>/SumD' */
  Kensei150401_B.SumD_c = Kensei150401_B.DerivativeGain_o -
    Kensei150401_B.Filter_e;

  /* Gain: '<S97>/Filter Coefficient' */
  Kensei150401_B.FilterCoefficient_n = Kensei150401_P.FilterCoefficient_Gain_e *
    Kensei150401_B.SumD_c;

  /* Sum: '<S97>/Sum' */
  Kensei150401_B.Sum_f = (Kensei150401_B.Sum_o + Kensei150401_B.Integrator_k) +
    Kensei150401_B.FilterCoefficient_n;

  /* Gain: '<S97>/Proportional Gain' */
  Kensei150401_B.ProportionalGain_l = Kensei150401_P.ProportionalGain_Gain_n *
    Kensei150401_B.Sum_f;

  /* Saturate: '<S97>/Saturation' */
  tmp = Kensei150401_B.ProportionalGain_l;
  u = Kensei150401_P.Saturation_LowerSat_g;
  u_0 = Kensei150401_P.Saturation_UpperSat_ib;
  if (tmp >= u_0) {
    Kensei150401_B.Saturation_f = u_0;
  } else if (tmp <= u) {
    Kensei150401_B.Saturation_f = u;
  } else {
    Kensei150401_B.Saturation_f = tmp;
  }

  /* End of Saturate: '<S97>/Saturation' */

  /* Abs: '<S84>/Abs' */
  Kensei150401_B.Abs_g = fabs(Kensei150401_B.Sum_o);
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Constant: '<S84>/Constant' */
    Kensei150401_B.Constant_c = Kensei150401_P.Constant_Value_f;
  }

  /* Switch: '<S84>/Switch1' */
  if (Kensei150401_B.Abs_g > Kensei150401_P.Switch1_Threshold_j) {
    Kensei150401_B.Switch1_h = Kensei150401_B.Saturation_f;
  } else {
    Kensei150401_B.Switch1_h = Kensei150401_B.Constant_c;
  }

  /* End of Switch: '<S84>/Switch1' */

  /* Switch: '<S98>/Switch2' incorporates:
   *  Constant: '<S98>/Switch_FL'
   */
  if (Kensei150401_P.Switch_FL_Value >= Kensei150401_P.Switch2_Threshold_m) {
    Kensei150401_B.Switch2_l = Kensei150401_B.FLpwm;
  } else {
    /* Abs: '<S98>/Abs' */
    Kensei150401_B.Abs_f = fabs(Kensei150401_B.Switch1_h);
    Kensei150401_B.Switch2_l = Kensei150401_B.Abs_f;
  }

  /* End of Switch: '<S98>/Switch2' */

  /* Gain: '<S98>/RealPWMin' */
  Kensei150401_B.RealPWMin = Kensei150401_P.RealPWMin_Gain_n *
    Kensei150401_B.Switch2_l;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Constant: '<S7>/Offset6' */
    Kensei150401_B.Offset6 = Kensei150401_P.Offset6_Value;
  }

  /* Sum: '<S7>/Sum6' */
  Kensei150401_B.Sum6 = Kensei150401_B.RealPWMin + Kensei150401_B.Offset6;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* S-Function (rti_commonblock): '<S40>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* write PWM Period and DutyCycle for output channel 2 on port 1 */
    dio_tp4_pwm_update(DIO_TP4_1_MODULE_ADDR , 1, 2, (real_T)
                       Kensei150401_P.u000Hz_Value, (real_T) Kensei150401_B.Sum6);

    /* Constant: '<S128>/RRpwm' */
    Kensei150401_B.RRpwm = Kensei150401_P.RRpwm_Value;

    /* Constant: '<S128>/Switch_RR' */
    Kensei150401_B.Switch_RR = Kensei150401_P.Switch_RR_Value;

    /* Math: '<S132>/Math Function' incorporates:
     *  Constant: '<S132>/b'
     */
    Kensei150401_B.MathFunction_n = Kensei150401_P.b_Value_h *
      Kensei150401_P.b_Value_h;

    /* Math: '<S132>/Math Function1' incorporates:
     *  Constant: '<S132>/c'
     */
    Kensei150401_B.MathFunction1_l = Kensei150401_P.c_Value_g *
      Kensei150401_P.c_Value_g;

    /* Math: '<S132>/Math Function2' incorporates:
     *  Constant: '<S132>/d'
     */
    Kensei150401_B.MathFunction2_c = Kensei150401_P.d_Value_p *
      Kensei150401_P.d_Value_p;

    /* Sum: '<S132>/Sum' */
    Kensei150401_B.Sum_m = (Kensei150401_B.MathFunction_n +
      Kensei150401_B.MathFunction1_l) - Kensei150401_B.MathFunction2_c;

    /* Product: '<S132>/Divide2' incorporates:
     *  Constant: '<S132>/b'
     *  Constant: '<S132>/c'
     *  Constant: '<S132>/constant'
     */
    Kensei150401_B.Divide2_l = Kensei150401_P.constant_Value_f *
      Kensei150401_P.c_Value_g * Kensei150401_P.b_Value_h;

    /* Product: '<S132>/Divide' */
    Kensei150401_B.Divide_p = Kensei150401_B.Sum_m / Kensei150401_B.Divide2_l;

    /* Fcn: '<S132>/Epsilon' */
    tmp = Kensei150401_B.Divide_p;
    if (tmp >= 1.0) {
      tmp = 1.0;
    } else {
      if (tmp <= -1.0) {
        tmp = -1.0;
      }
    }

    tmp = acos(tmp);
    Kensei150401_B.Epsilon_g = tmp;

    /* End of Fcn: '<S132>/Epsilon' */

    /* Fcn: '<S83>/Lr' incorporates:
     *  Constant: '<S83>/Wheel base'
     */
    Kensei150401_B.Lr = Kensei150401_P.Wheelbase_Value_e - ((real_T)(tan
      (Kensei150401_B.Abs1) == 0.0) * 2.2204460492503131e-16 + tan
      (Kensei150401_B.Abs1)) / ((real_T)(Kensei150401_B.Abs_j == 0.0) *
      2.2204460492503131e-16 + tan(Kensei150401_B.Abs_j)) *
      Kensei150401_P.Wheelbase_Value_e / ((real_T)(tan(Kensei150401_B.Abs1) /
      ((real_T)(Kensei150401_B.Abs_j == 0.0) * 2.2204460492503131e-16 + tan
       (Kensei150401_B.Abs_j)) + 1.0 == 0.0) * 2.2204460492503131e-16 + (tan
      (Kensei150401_B.Abs1) / ((real_T)(Kensei150401_B.Abs_j == 0.0) *
      2.2204460492503131e-16 + tan(Kensei150401_B.Abs_j)) + 1.0));

    /* Fcn: '<S83>/angle_Ri' incorporates:
     *  Constant: '<S83>/Wheel track'
     */
    Kensei150401_B.angle_Ri = atan(Kensei150401_B.Lr / (Kensei150401_B.Rc -
      Kensei150401_P.Wheeltrack_Value_o / 2.0));

    /* Fcn: '<S83>/angle_Ro' incorporates:
     *  Constant: '<S83>/Wheel track'
     */
    Kensei150401_B.angle_Ro = atan(Kensei150401_B.Lr /
      (Kensei150401_P.Wheeltrack_Value_o / 2.0 + Kensei150401_B.Rc));

    /* Switch: '<S89>/Switch' */
    if (Kensei150401_B.clear2go >= Kensei150401_P.Switch_Threshold_k) {
      Kensei150401_B.Switch = Kensei150401_B.RRdeg;
    } else {
      /* Fcn: '<S83>/switching1' */
      Kensei150401_B.switching1 = (real_T)(Kensei150401_B.Gain1_h >= 0.0) *
        Kensei150401_B.angle_Ro - (real_T)(Kensei150401_B.Gain1_h < 0.0) *
        Kensei150401_B.angle_Ri;

      /* Gain: '<S94>/Gain' */
      Kensei150401_B.Gain_a = Kensei150401_P.Gain_Gain_k *
        Kensei150401_B.switching1;

      /* Gain: '<S83>/Gain1' */
      Kensei150401_B.Gain1_m = Kensei150401_P.Gain1_Gain * Kensei150401_B.Gain_a;

      /* Fcn: '<S7>/switching2' */
      Kensei150401_B.switching2_b = (real_T)(Kensei150401_B.AWS == 1.0) *
        Kensei150401_B.Gain1_m + (real_T)(Kensei150401_B.AWS == 0.0) *
        Kensei150401_B.AWS;

      /* Saturate: '<S89>/RR_ref degree' */
      tmp = Kensei150401_B.switching2_b;
      u = Kensei150401_P.RR_refdegree_LowerSat;
      u_0 = Kensei150401_P.RR_refdegree_UpperSat;
      if (tmp >= u_0) {
        Kensei150401_B.RR_refdegree = u_0;
      } else if (tmp <= u) {
        Kensei150401_B.RR_refdegree = u;
      } else {
        Kensei150401_B.RR_refdegree = tmp;
      }

      /* End of Saturate: '<S89>/RR_ref degree' */
      Kensei150401_B.Switch = Kensei150401_B.RR_refdegree;
    }

    /* End of Switch: '<S89>/Switch' */

    /* Gain: '<S132>/degree to rad' */
    Kensei150401_B.degreetorad_b = Kensei150401_P.degreetorad_Gain_c *
      Kensei150401_B.Switch;

    /* Sum: '<S132>/Sum4' */
    Kensei150401_B.Sum4_c = Kensei150401_B.Epsilon_g +
      Kensei150401_B.degreetorad_b;

    /* Fcn: '<S132>/Fcn1' */
    Kensei150401_B.Fcn1_f = cos(Kensei150401_B.Sum4_c);

    /* Product: '<S132>/Divide1' */
    Kensei150401_B.Divide1_k = Kensei150401_B.Fcn1_f * Kensei150401_B.Divide2_l;

    /* Sum: '<S132>/Sum3' */
    Kensei150401_B.Sum3_f = (Kensei150401_B.MathFunction_n +
      Kensei150401_B.MathFunction1_l) - Kensei150401_B.Divide1_k;

    /* Sqrt: '<S132>/Sqrt' */
    Kensei150401_B.Sqrt_n = sqrt(Kensei150401_B.Sum3_f);

    /* Sum: '<S132>/Sum2' incorporates:
     *  Constant: '<S132>/d'
     */
    Kensei150401_B.Sum2_n = Kensei150401_B.Sqrt_n - Kensei150401_P.d_Value_p;

    /* Gain: '<S132>/m to mm' */
    Kensei150401_B.mtomm_g = Kensei150401_P.mtomm_Gain_h * Kensei150401_B.Sum2_n;

    /* Gain: '<S129>/RR_Volt per mm2' incorporates:
     *  Constant: '<S129>/RR ADC Center'
     */
    Kensei150401_B.RR_Voltpermm2 = Kensei150401_P.RR_Voltpermm2_Gain *
      Kensei150401_P.RRADCCenter_Value;

    /* Sum: '<S129>/Sum1' */
    Kensei150401_B.Sum1_i = Kensei150401_B.mtomm_g +
      Kensei150401_B.RR_Voltpermm2;

    /* Gain: '<S129>/RR_mm to volt' */
    Kensei150401_B.RR_mmtovolt = Kensei150401_P.RR_mmtovolt_Gain *
      Kensei150401_B.Sum1_i;

    /* Saturate: '<S89>/RR_ref input Saturation' */
    tmp = Kensei150401_B.RR_mmtovolt;
    u = Kensei150401_P.RR_refinputSaturation_LowerSat;
    u_0 = Kensei150401_P.RR_refinputSaturation_UpperSat;
    if (tmp >= u_0) {
      Kensei150401_B.RR_refinputSaturation = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.RR_refinputSaturation = u;
    } else {
      Kensei150401_B.RR_refinputSaturation = tmp;
    }

    /* End of Saturate: '<S89>/RR_ref input Saturation' */
  }

  /* StateSpace: '<S89>/Analog Filter_RR_Pos' */
  {
    Kensei150401_B.AnalogFilter_RR_Pos = Kensei150401_P.AnalogFilter_RR_Pos_C*
      Kensei150401_X.AnalogFilter_RR_Pos_CSTATE;
  }

  /* Sum: '<S89>/Sum1' */
  Kensei150401_B.Sum1_i0 = Kensei150401_B.RR_refinputSaturation -
    Kensei150401_B.AnalogFilter_RR_Pos;

  /* Integrator: '<S127>/Integrator' */
  Kensei150401_B.Integrator_o = Kensei150401_X.Integrator_CSTATE_p;

  /* Gain: '<S127>/Derivative Gain' */
  Kensei150401_B.DerivativeGain_e = Kensei150401_P.DerivativeGain_Gain_g *
    Kensei150401_B.Sum1_i0;

  /* Integrator: '<S127>/Filter' */
  Kensei150401_B.Filter_h = Kensei150401_X.Filter_CSTATE_i;

  /* Sum: '<S127>/SumD' */
  Kensei150401_B.SumD_g = Kensei150401_B.DerivativeGain_e -
    Kensei150401_B.Filter_h;

  /* Gain: '<S127>/Filter Coefficient' */
  Kensei150401_B.FilterCoefficient_i = Kensei150401_P.FilterCoefficient_Gain_c *
    Kensei150401_B.SumD_g;

  /* Sum: '<S127>/Sum' */
  Kensei150401_B.Sum_n = (Kensei150401_B.Sum1_i0 + Kensei150401_B.Integrator_o)
    + Kensei150401_B.FilterCoefficient_i;

  /* Gain: '<S127>/Proportional Gain' */
  Kensei150401_B.ProportionalGain_p = Kensei150401_P.ProportionalGain_Gain_o *
    Kensei150401_B.Sum_n;

  /* Saturate: '<S127>/Saturation' */
  tmp = Kensei150401_B.ProportionalGain_p;
  u = Kensei150401_P.Saturation_LowerSat_m;
  u_0 = Kensei150401_P.Saturation_UpperSat_p;
  if (tmp >= u_0) {
    Kensei150401_B.Saturation_m = u_0;
  } else if (tmp <= u) {
    Kensei150401_B.Saturation_m = u;
  } else {
    Kensei150401_B.Saturation_m = tmp;
  }

  /* End of Saturate: '<S127>/Saturation' */

  /* Abs: '<S89>/Abs' */
  Kensei150401_B.Abs_o = fabs(Kensei150401_B.Sum1_i0);
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Constant: '<S89>/Constant' */
    Kensei150401_B.Constant_j = Kensei150401_P.Constant_Value_j;
  }

  /* Switch: '<S89>/Switch1' */
  if (Kensei150401_B.Abs_o > Kensei150401_P.Switch1_Threshold_i) {
    Kensei150401_B.Switch1_i = Kensei150401_B.Saturation_m;
  } else {
    Kensei150401_B.Switch1_i = Kensei150401_B.Constant_j;
  }

  /* End of Switch: '<S89>/Switch1' */

  /* Switch: '<S128>/Switch2' */
  if (Kensei150401_B.Switch_RR >= Kensei150401_P.Switch2_Threshold_j) {
    Kensei150401_B.Switch2_h = Kensei150401_B.RRpwm;
  } else {
    /* Abs: '<S128>/Abs' */
    Kensei150401_B.Abs_b = fabs(Kensei150401_B.Switch1_i);
    Kensei150401_B.Switch2_h = Kensei150401_B.Abs_b;
  }

  /* End of Switch: '<S128>/Switch2' */

  /* Gain: '<S128>/RealPWMin' */
  Kensei150401_B.RealPWMin_b = Kensei150401_P.RealPWMin_Gain_b *
    Kensei150401_B.Switch2_h;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Constant: '<S7>/Offset7' */
    Kensei150401_B.Offset7 = Kensei150401_P.Offset7_Value;
  }

  /* Sum: '<S7>/Sum7' */
  Kensei150401_B.Sum7 = Kensei150401_B.RealPWMin_b + Kensei150401_B.Offset7;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* S-Function (rti_commonblock): '<S41>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* write PWM Period and DutyCycle for output channel 3 on port 1 */
    dio_tp4_pwm_update(DIO_TP4_1_MODULE_ADDR , 1, 3, (real_T)
                       Kensei150401_P.u000Hz_Value, (real_T) Kensei150401_B.Sum7);

    /* Constant: '<S121>/RLpwm' */
    Kensei150401_B.RLpwm = Kensei150401_P.RLpwm_Value;

    /* Math: '<S125>/Math Function' incorporates:
     *  Constant: '<S125>/b'
     */
    Kensei150401_B.MathFunction_f = Kensei150401_P.b_Value_o *
      Kensei150401_P.b_Value_o;

    /* Math: '<S125>/Math Function1' incorporates:
     *  Constant: '<S125>/c'
     */
    Kensei150401_B.MathFunction1_l3 = Kensei150401_P.c_Value_k *
      Kensei150401_P.c_Value_k;

    /* Math: '<S125>/Math Function2' incorporates:
     *  Constant: '<S125>/d'
     */
    Kensei150401_B.MathFunction2_bb = Kensei150401_P.d_Value_h *
      Kensei150401_P.d_Value_h;

    /* Sum: '<S125>/Sum' */
    Kensei150401_B.Sum_c = (Kensei150401_B.MathFunction_f +
      Kensei150401_B.MathFunction1_l3) - Kensei150401_B.MathFunction2_bb;

    /* Product: '<S125>/Divide2' incorporates:
     *  Constant: '<S125>/b'
     *  Constant: '<S125>/c'
     *  Constant: '<S125>/constant'
     */
    Kensei150401_B.Divide2_lb = Kensei150401_P.constant_Value_e *
      Kensei150401_P.c_Value_k * Kensei150401_P.b_Value_o;

    /* Product: '<S125>/Divide' */
    Kensei150401_B.Divide_bn = Kensei150401_B.Sum_c / Kensei150401_B.Divide2_lb;

    /* Fcn: '<S125>/Epsilon' */
    tmp = Kensei150401_B.Divide_bn;
    if (tmp >= 1.0) {
      tmp = 1.0;
    } else {
      if (tmp <= -1.0) {
        tmp = -1.0;
      }
    }

    tmp = acos(tmp);
    Kensei150401_B.Epsilon_l = tmp;

    /* End of Fcn: '<S125>/Epsilon' */

    /* Switch: '<S88>/Switch' */
    if (Kensei150401_B.clear2go >= Kensei150401_P.Switch_Threshold_g) {
      Kensei150401_B.Switch_h = Kensei150401_B.RLdeg;
    } else {
      /* Fcn: '<S83>/switching' */
      Kensei150401_B.switching_h = (real_T)(Kensei150401_B.Gain1_h >= 0.0) *
        Kensei150401_B.angle_Ri - (real_T)(Kensei150401_B.Gain1_h < 0.0) *
        Kensei150401_B.angle_Ro;

      /* Gain: '<S93>/Gain' */
      Kensei150401_B.Gain_os = Kensei150401_P.Gain_Gain *
        Kensei150401_B.switching_h;

      /* Gain: '<S83>/Gain' */
      Kensei150401_B.Gain_g4 = Kensei150401_P.Gain_Gain_f *
        Kensei150401_B.Gain_os;

      /* Fcn: '<S7>/switching1' */
      Kensei150401_B.switching1_p = (real_T)(Kensei150401_B.AWS == 1.0) *
        Kensei150401_B.Gain_g4 + (real_T)(Kensei150401_B.AWS == 0.0) *
        Kensei150401_B.AWS;

      /* Saturate: '<S88>/RL_ref degree' */
      tmp = Kensei150401_B.switching1_p;
      u = Kensei150401_P.RL_refdegree_LowerSat;
      u_0 = Kensei150401_P.RL_refdegree_UpperSat;
      if (tmp >= u_0) {
        Kensei150401_B.RL_refdegree = u_0;
      } else if (tmp <= u) {
        Kensei150401_B.RL_refdegree = u;
      } else {
        Kensei150401_B.RL_refdegree = tmp;
      }

      /* End of Saturate: '<S88>/RL_ref degree' */
      Kensei150401_B.Switch_h = Kensei150401_B.RL_refdegree;
    }

    /* End of Switch: '<S88>/Switch' */

    /* Gain: '<S125>/gain' */
    Kensei150401_B.gain = Kensei150401_P.gain_Gain * Kensei150401_B.Switch_h;

    /* Gain: '<S125>/degree to rad' */
    Kensei150401_B.degreetorad_h = Kensei150401_P.degreetorad_Gain_m *
      Kensei150401_B.gain;

    /* Sum: '<S125>/Sum4' */
    Kensei150401_B.Sum4_n = Kensei150401_B.Epsilon_l +
      Kensei150401_B.degreetorad_h;

    /* Fcn: '<S125>/Fcn1' */
    Kensei150401_B.Fcn1_kl = cos(Kensei150401_B.Sum4_n);

    /* Product: '<S125>/Divide1' */
    Kensei150401_B.Divide1_h = Kensei150401_B.Fcn1_kl *
      Kensei150401_B.Divide2_lb;

    /* Sum: '<S125>/Sum3' */
    Kensei150401_B.Sum3_k = (Kensei150401_B.MathFunction_f +
      Kensei150401_B.MathFunction1_l3) - Kensei150401_B.Divide1_h;

    /* Sqrt: '<S125>/Sqrt' */
    Kensei150401_B.Sqrt_d = sqrt(Kensei150401_B.Sum3_k);

    /* Sum: '<S125>/Sum2' incorporates:
     *  Constant: '<S125>/d'
     */
    Kensei150401_B.Sum2_c = Kensei150401_B.Sqrt_d - Kensei150401_P.d_Value_h;

    /* Gain: '<S125>/m to mm' */
    Kensei150401_B.mtomm_l = Kensei150401_P.mtomm_Gain_ky *
      Kensei150401_B.Sum2_c;

    /* Gain: '<S122>/RL_Volt per mm2' incorporates:
     *  Constant: '<S122>/RL ADC Center'
     */
    Kensei150401_B.RL_Voltpermm2 = Kensei150401_P.RL_Voltpermm2_Gain *
      Kensei150401_P.RLADCCenter_Value;

    /* Sum: '<S122>/Sum1' */
    Kensei150401_B.Sum1_h = Kensei150401_B.mtomm_l +
      Kensei150401_B.RL_Voltpermm2;

    /* Gain: '<S122>/RL_mm to volt' */
    Kensei150401_B.RL_mmtovolt = Kensei150401_P.RL_mmtovolt_Gain *
      Kensei150401_B.Sum1_h;

    /* Saturate: '<S88>/RL_ref input Saturation' */
    tmp = Kensei150401_B.RL_mmtovolt;
    u = Kensei150401_P.RL_refinputSaturation_LowerSat;
    u_0 = Kensei150401_P.RL_refinputSaturation_UpperSat;
    if (tmp >= u_0) {
      Kensei150401_B.RL_refinputSaturation = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.RL_refinputSaturation = u;
    } else {
      Kensei150401_B.RL_refinputSaturation = tmp;
    }

    /* End of Saturate: '<S88>/RL_ref input Saturation' */
  }

  /* StateSpace: '<S88>/Analog Filter_RL_Pos' */
  {
    Kensei150401_B.AnalogFilter_RL_Pos = Kensei150401_P.AnalogFilter_RL_Pos_C*
      Kensei150401_X.AnalogFilter_RL_Pos_CSTATE;
  }

  /* Sum: '<S88>/Sum1' */
  Kensei150401_B.Sum1_b = Kensei150401_B.RL_refinputSaturation -
    Kensei150401_B.AnalogFilter_RL_Pos;

  /* Integrator: '<S120>/Integrator' */
  Kensei150401_B.Integrator_g = Kensei150401_X.Integrator_CSTATE_c;

  /* Gain: '<S120>/Derivative Gain' */
  Kensei150401_B.DerivativeGain_eq = Kensei150401_P.DerivativeGain_Gain_h *
    Kensei150401_B.Sum1_b;

  /* Integrator: '<S120>/Filter' */
  Kensei150401_B.Filter_o = Kensei150401_X.Filter_CSTATE_c;

  /* Sum: '<S120>/SumD' */
  Kensei150401_B.SumD_h = Kensei150401_B.DerivativeGain_eq -
    Kensei150401_B.Filter_o;

  /* Gain: '<S120>/Filter Coefficient' */
  Kensei150401_B.FilterCoefficient_o = Kensei150401_P.FilterCoefficient_Gain_p *
    Kensei150401_B.SumD_h;

  /* Sum: '<S120>/Sum' */
  Kensei150401_B.Sum_k = (Kensei150401_B.Sum1_b + Kensei150401_B.Integrator_g) +
    Kensei150401_B.FilterCoefficient_o;

  /* Gain: '<S120>/Proportional Gain' */
  Kensei150401_B.ProportionalGain_a = Kensei150401_P.ProportionalGain_Gain_d *
    Kensei150401_B.Sum_k;

  /* Saturate: '<S120>/Saturation' */
  tmp = Kensei150401_B.ProportionalGain_a;
  u = Kensei150401_P.Saturation_LowerSat_l;
  u_0 = Kensei150401_P.Saturation_UpperSat_j;
  if (tmp >= u_0) {
    Kensei150401_B.Saturation_fk = u_0;
  } else if (tmp <= u) {
    Kensei150401_B.Saturation_fk = u;
  } else {
    Kensei150401_B.Saturation_fk = tmp;
  }

  /* End of Saturate: '<S120>/Saturation' */

  /* Abs: '<S88>/Abs' */
  Kensei150401_B.Abs_p = fabs(Kensei150401_B.Sum1_b);
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Constant: '<S88>/Constant' */
    Kensei150401_B.Constant_h = Kensei150401_P.Constant_Value_l;
  }

  /* Switch: '<S88>/Switch1' */
  if (Kensei150401_B.Abs_p > Kensei150401_P.Switch1_Threshold_o) {
    Kensei150401_B.Switch1_d = Kensei150401_B.Saturation_fk;
  } else {
    Kensei150401_B.Switch1_d = Kensei150401_B.Constant_h;
  }

  /* End of Switch: '<S88>/Switch1' */

  /* Switch: '<S121>/Switch2' incorporates:
   *  Constant: '<S121>/Switch_RL'
   */
  if (Kensei150401_P.Switch_RL_Value >= Kensei150401_P.Switch2_Threshold_mi) {
    Kensei150401_B.Switch2_k = Kensei150401_B.RLpwm;
  } else {
    /* Abs: '<S121>/Abs' */
    Kensei150401_B.Abs_e = fabs(Kensei150401_B.Switch1_d);
    Kensei150401_B.Switch2_k = Kensei150401_B.Abs_e;
  }

  /* End of Switch: '<S121>/Switch2' */

  /* Gain: '<S121>/RealPWMin' */
  Kensei150401_B.RealPWMin_f = Kensei150401_P.RealPWMin_Gain_i *
    Kensei150401_B.Switch2_k;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Constant: '<S7>/Offset4' */
    Kensei150401_B.Offset4 = Kensei150401_P.Offset4_Value;
  }

  /* Sum: '<S7>/Sum8' */
  Kensei150401_B.Sum8 = Kensei150401_B.RealPWMin_f + Kensei150401_B.Offset4;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* S-Function (rti_commonblock): '<S42>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* write PWM Period and DutyCycle for output channel 4 on port 1 */
    dio_tp4_pwm_update(DIO_TP4_1_MODULE_ADDR , 1, 4, (real_T)
                       Kensei150401_P.u000Hz_Value, (real_T) Kensei150401_B.Sum8);

    /* Gain: '<S136>/Gain1' */
    Kensei150401_B.Gain1_p = Kensei150401_P.Gain1_Gain_a3 *
      Kensei150401_B.RoundingFunction2;

    /* Lookup_n-D: '<S90>/Feedback Map ZPT' */
    Kensei150401_B.FeedbackMapZPT = look1_binlxpw(Kensei150401_B.Gain1_p,
      Kensei150401_P.FeedbackMapZPT_bp01Data,
      Kensei150401_P.FeedbackMapZPT_tableData, 8U);

    /* Saturate: '<S90>/Saturation2' */
    tmp = Kensei150401_B.FeedbackMapZPT;
    u = Kensei150401_P.Saturation2_LowerSat;
    u_0 = Kensei150401_P.Saturation2_UpperSat;
    if (tmp >= u_0) {
      Kensei150401_B.Saturation2 = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.Saturation2 = u;
    } else {
      Kensei150401_B.Saturation2 = tmp;
    }

    /* End of Saturate: '<S90>/Saturation2' */

    /* Gain: '<S90>/Gain2' */
    Kensei150401_B.Gain2_l = Kensei150401_P.Gain2_Gain_o *
      Kensei150401_B.Saturation2;

    /* Gain: '<S90>/Gain3' */
    Kensei150401_B.Gain3_h = Kensei150401_P.Gain3_Gain_n *
      Kensei150401_B.Gain1_p;

    /* Saturate: '<S90>/Saturation1' */
    tmp = Kensei150401_B.Limit80kmh;
    u = Kensei150401_P.Saturation1_LowerSat;
    u_0 = Kensei150401_P.Saturation1_UpperSat;
    if (tmp >= u_0) {
      Kensei150401_B.Saturation1 = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.Saturation1 = u;
    } else {
      Kensei150401_B.Saturation1 = tmp;
    }

    /* End of Saturate: '<S90>/Saturation1' */

    /* Switch: '<S90>/Switch5' */
    if (Kensei150401_B.clear2go >= Kensei150401_P.Switch5_Threshold) {
      /* Saturate: '<S143>/Saturation' */
      tmp = Kensei150401_B.RoundingFunction2;
      u = Kensei150401_P.Saturation_LowerSat_c;
      u_0 = Kensei150401_P.Saturation_UpperSat_i;
      if (tmp >= u_0) {
        Kensei150401_B.Saturation_l = u_0;
      } else if (tmp <= u) {
        Kensei150401_B.Saturation_l = u;
      } else {
        Kensei150401_B.Saturation_l = tmp;
      }

      /* End of Saturate: '<S143>/Saturation' */

      /* Abs: '<S143>/Abs' */
      Kensei150401_B.Abs_l = fabs(Kensei150401_B.Saturation_l);

      /* Sqrt: '<S143>/Sqrt' */
      Kensei150401_B.Sqrt_j = sqrt(Kensei150401_B.Abs_l);

      /* Switch: '<S143>/Switch' incorporates:
       *  Constant: '<S1>/Ka'
       */
      if (Kensei150401_B.Saturation_l >= Kensei150401_P.Switch_Threshold_n) {
        Kensei150401_B.Switch_g = Kensei150401_P.Ka_Value;
      } else {
        /* Gain: '<S143>/Gain' incorporates:
         *  Constant: '<S1>/Ka'
         */
        Kensei150401_B.Gain_n = Kensei150401_P.Gain_Gain_e *
          Kensei150401_P.Ka_Value;
        Kensei150401_B.Switch_g = Kensei150401_B.Gain_n;
      }

      /* End of Switch: '<S143>/Switch' */

      /* Gain: '<S143>/GainKA' */
      Kensei150401_B.GainKA = Kensei150401_P.GainKA_Gain_h *
        Kensei150401_B.Switch_g;

      /* Product: '<S143>/Product' */
      Kensei150401_B.Product_lu = Kensei150401_B.GainKA * Kensei150401_B.Sqrt_j;

      /* Gain: '<S143>/Gain1' */
      Kensei150401_B.Gain1_c = Kensei150401_P.Gain1_Gain_d *
        Kensei150401_B.Product_lu;

      /* RelationalOperator: '<S142>/Compare' incorporates:
       *  Constant: '<S142>/Constant'
       */
      Kensei150401_B.Compare_e = (Kensei150401_B.RoundingFunction2 >=
        Kensei150401_P.Constant_Value_e);

      /* Switch: '<S138>/Switch1' incorporates:
       *  Constant: '<S138>/Constant1'
       */
      if (Kensei150401_B.Compare_e) {
        Kensei150401_B.Switch1_l = Kensei150401_P.Constant1_Value_h;
      } else {
        /* Gain: '<S138>/Gain1' incorporates:
         *  Constant: '<S138>/Constant1'
         */
        Kensei150401_B.Gain1_fd = Kensei150401_P.Gain1_Gain_gw *
          Kensei150401_P.Constant1_Value_h;
        Kensei150401_B.Switch1_l = Kensei150401_B.Gain1_fd;
      }

      /* End of Switch: '<S138>/Switch1' */

      /* Fcn: '<S144>/Fcn' */
      tmp = Kensei150401_B.Saturation1;
      tmp = rt_powd_snf(tmp, 2.0);
      Kensei150401_B.Fcn_e = tmp;

      /* Product: '<S144>/Product' incorporates:
       *  Constant: '<S1>/Kb'
       */
      Kensei150401_B.Product_n = Kensei150401_P.Kb_Value * Kensei150401_B.Fcn_e;

      /* Gain: '<S144>/Gain' */
      Kensei150401_B.Gain_j = Kensei150401_P.Gain_Gain_c *
        Kensei150401_B.Saturation1;

      /* Sum: '<S144>/Sum' incorporates:
       *  Constant: '<S144>/Constant1'
       */
      Kensei150401_B.Sum_br = Kensei150401_B.Gain_j -
        Kensei150401_P.Constant1_Value_o;

      /* Product: '<S144>/Product1' */
      Kensei150401_B.Product1_o = Kensei150401_B.Sum_br *
        Kensei150401_B.Product_n;

      /* Gain: '<S144>/GainKB' */
      Kensei150401_B.GainKB = Kensei150401_P.GainKB_Gain_p *
        Kensei150401_B.Product1_o;

      /* Sum: '<S144>/Sum1' */
      Kensei150401_B.Sum1_g = Kensei150401_B.GainKB + Kensei150401_B.Switch1_l;

      /* Product: '<S138>/Product' */
      Kensei150401_B.Product_j = Kensei150401_B.Sum1_g * Kensei150401_B.Gain1_c;

      /* Gain: '<S138>/Gain' */
      Kensei150401_B.Gain_g = Kensei150401_P.Gain_Gain_l *
        Kensei150401_B.Product_j;

      /* Gain: '<S138>/Gain2' */
      Kensei150401_B.Gain2_k = Kensei150401_P.Gain2_Gain_h *
        Kensei150401_B.Gain_g;

      /* Gain: '<S90>/RealPWMin2' */
      Kensei150401_B.RealPWMin2 = Kensei150401_P.RealPWMin2_Gain *
        Kensei150401_B.Gain2_k;
      Kensei150401_B.Switch5 = Kensei150401_B.RealPWMin2;
    } else {
      /* Saturate: '<S140>/Saturation' */
      tmp = Kensei150401_B.RoundingFunction2;
      u = Kensei150401_P.Saturation_LowerSat;
      u_0 = Kensei150401_P.Saturation_UpperSat;
      if (tmp >= u_0) {
        Kensei150401_B.Saturation_j = u_0;
      } else if (tmp <= u) {
        Kensei150401_B.Saturation_j = u;
      } else {
        Kensei150401_B.Saturation_j = tmp;
      }

      /* End of Saturate: '<S140>/Saturation' */

      /* Abs: '<S140>/Abs' */
      Kensei150401_B.Abs_nk = fabs(Kensei150401_B.Saturation_j);

      /* Sqrt: '<S140>/Sqrt' */
      Kensei150401_B.Sqrt_n1 = sqrt(Kensei150401_B.Abs_nk);

      /* Switch: '<S140>/Switch' incorporates:
       *  Constant: '<S1>/Ka'
       */
      if (Kensei150401_B.Saturation_j >= Kensei150401_P.Switch_Threshold_h) {
        Kensei150401_B.Switch_d = Kensei150401_P.Ka_Value;
      } else {
        /* Gain: '<S140>/Gain' incorporates:
         *  Constant: '<S1>/Ka'
         */
        Kensei150401_B.Gain_nr = Kensei150401_P.Gain_Gain_p *
          Kensei150401_P.Ka_Value;
        Kensei150401_B.Switch_d = Kensei150401_B.Gain_nr;
      }

      /* End of Switch: '<S140>/Switch' */

      /* Gain: '<S140>/GainKA' */
      Kensei150401_B.GainKA_p = Kensei150401_P.GainKA_Gain *
        Kensei150401_B.Switch_d;

      /* Product: '<S140>/Product' */
      Kensei150401_B.Product_k = Kensei150401_B.GainKA_p *
        Kensei150401_B.Sqrt_n1;

      /* Gain: '<S140>/Gain1' */
      Kensei150401_B.Gain1_hf = Kensei150401_P.Gain1_Gain_n *
        Kensei150401_B.Product_k;

      /* RelationalOperator: '<S139>/Compare' incorporates:
       *  Constant: '<S139>/Constant'
       */
      Kensei150401_B.Compare_g = (Kensei150401_B.RoundingFunction2 >=
        Kensei150401_P.Constant_Value_g);

      /* Switch: '<S137>/Switch1' incorporates:
       *  Constant: '<S1>/T_in'
       */
      if (Kensei150401_B.Compare_g) {
        Kensei150401_B.Switch1_k = Kensei150401_P.T_in_Value;
      } else {
        /* Gain: '<S137>/Gain1' incorporates:
         *  Constant: '<S1>/T_in'
         */
        Kensei150401_B.Gain1_a = Kensei150401_P.Gain1_Gain_g *
          Kensei150401_P.T_in_Value;
        Kensei150401_B.Switch1_k = Kensei150401_B.Gain1_a;
      }

      /* End of Switch: '<S137>/Switch1' */

      /* Fcn: '<S141>/Fcn' */
      tmp = Kensei150401_B.Saturation1;
      tmp = rt_powd_snf(tmp, 2.0);
      Kensei150401_B.Fcn_i = tmp;

      /* Product: '<S141>/Product' incorporates:
       *  Constant: '<S1>/Kb'
       */
      Kensei150401_B.Product_h = Kensei150401_P.Kb_Value * Kensei150401_B.Fcn_i;

      /* Gain: '<S141>/Gain' */
      Kensei150401_B.Gain_nc = Kensei150401_P.Gain_Gain_a *
        Kensei150401_B.Saturation1;

      /* Sum: '<S141>/Sum' incorporates:
       *  Constant: '<S141>/Constant1'
       */
      Kensei150401_B.Sum_lh = Kensei150401_B.Gain_nc -
        Kensei150401_P.Constant1_Value;

      /* Product: '<S141>/Product1' */
      Kensei150401_B.Product1_i = Kensei150401_B.Sum_lh *
        Kensei150401_B.Product_h;

      /* Gain: '<S141>/GainKB' */
      Kensei150401_B.GainKB_f = Kensei150401_P.GainKB_Gain *
        Kensei150401_B.Product1_i;

      /* Sum: '<S141>/Sum1' */
      Kensei150401_B.Sum1_a5 = Kensei150401_B.GainKB_f +
        Kensei150401_B.Switch1_k;

      /* Product: '<S137>/Product' */
      Kensei150401_B.Product_p = Kensei150401_B.Sum1_a5 *
        Kensei150401_B.Gain1_hf;

      /* Gain: '<S137>/Gain' */
      Kensei150401_B.Gain_ni = Kensei150401_P.Gain_Gain_k0 *
        Kensei150401_B.Product_p;

      /* Gain: '<S137>/Gain2' */
      Kensei150401_B.Gain2_f = Kensei150401_P.Gain2_Gain *
        Kensei150401_B.Gain_ni;

      /* Gain: '<S90>/RealPWMin1' */
      Kensei150401_B.RealPWMin1 = Kensei150401_P.RealPWMin1_Gain *
        Kensei150401_B.Gain2_f;
      Kensei150401_B.Switch5 = Kensei150401_B.RealPWMin1;
    }

    /* End of Switch: '<S90>/Switch5' */

    /* Lookup_n-D: '<S90>/Feedback Map' */
    Kensei150401_B.FeedbackMap = look1_binlxpw(Kensei150401_B.Gain1_p,
      Kensei150401_P.FeedbackMap_bp01Data, Kensei150401_P.FeedbackMap_tableData,
      8U);

    /* Saturate: '<S90>/Saturation' */
    tmp = Kensei150401_B.FeedbackMap;
    u = Kensei150401_P.Saturation_LowerSat_f;
    u_0 = Kensei150401_P.Saturation_UpperSat_d;
    if (tmp >= u_0) {
      Kensei150401_B.Saturation_ft = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.Saturation_ft = u;
    } else {
      Kensei150401_B.Saturation_ft = tmp;
    }

    /* End of Saturate: '<S90>/Saturation' */

    /* Gain: '<S90>/Gain1' */
    Kensei150401_B.Gain1_g = Kensei150401_P.Gain1_Gain_hf *
      Kensei150401_B.Saturation_ft;

    /* Switch: '<S90>/Switch2' incorporates:
     *  Switch: '<S90>/Switch'
     *  Switch: '<S90>/Switch1'
     */
    if (Kensei150401_B.clear2go >= Kensei150401_P.Switch2_Threshold_gz) {
      /* Switch: '<S90>/Switch4' incorporates:
       *  Switch: '<S90>/Switch3'
       */
      if (Kensei150401_B.Gain3_h >= Kensei150401_P.Switch4_Threshold) {
        Kensei150401_B.Switch4_e = Kensei150401_B.Gain2_l;
      } else {
        if (Kensei150401_B.Gain1_p >= Kensei150401_P.Switch3_Threshold) {
          /* Switch: '<S90>/Switch3' */
          Kensei150401_B.Switch3 = Kensei150401_B.Gain2_l;
        } else {
          /* Switch: '<S90>/Switch3' */
          Kensei150401_B.Switch3 = Kensei150401_B.Switch5;
        }

        Kensei150401_B.Switch4_e = Kensei150401_B.Switch3;
      }

      /* End of Switch: '<S90>/Switch4' */
      Kensei150401_B.Switch2_n = Kensei150401_B.Switch4_e;
    } else {
      if (Kensei150401_B.Gain3_h >= Kensei150401_P.Switch1_Threshold) {
        /* Switch: '<S90>/Switch1' */
        Kensei150401_B.Switch1_n = Kensei150401_B.Gain1_g;
      } else {
        if (Kensei150401_B.Gain1_p >= Kensei150401_P.Switch_Threshold_e) {
          /* Switch: '<S90>/Switch' incorporates:
           *  Switch: '<S90>/Switch1'
           */
          Kensei150401_B.Switch_fs = Kensei150401_B.Gain1_g;
        } else {
          /* Switch: '<S90>/Switch' incorporates:
           *  Switch: '<S90>/Switch1'
           */
          Kensei150401_B.Switch_fs = Kensei150401_B.Switch5;
        }

        /* Switch: '<S90>/Switch1' */
        Kensei150401_B.Switch1_n = Kensei150401_B.Switch_fs;
      }

      Kensei150401_B.Switch2_n = Kensei150401_B.Switch1_n;
    }

    /* End of Switch: '<S90>/Switch2' */

    /* Abs: '<S90>/Abs' */
    Kensei150401_B.Abs_h = fabs(Kensei150401_B.Switch2_n);

    /* S-Function (rti_commonblock): '<S43>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* write PWM Period and DutyCycle for output channel 5 on port 1 */
    dio_tp4_pwm_update(DIO_TP4_1_MODULE_ADDR , 1, 5, (real_T)
                       Kensei150401_P.u000Hz_Value, (real_T)
                       Kensei150401_B.Abs_h);
  }

  /* Integrator: '<S146>/Integrator' */
  Kensei150401_B.Integrator_p = Kensei150401_X.Integrator_CSTATE_l;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Switch: '<S8>/Switch1' */
    if (Kensei150401_B.clear2go >= Kensei150401_P.Switch1_Threshold_co) {
      /* Lookup_n-D: '<S8>/Throttle MapZPT' */
      Kensei150401_B.ThrottleMapZPT = look1_binlxpw(Kensei150401_B.inADC2,
        Kensei150401_P.ThrottleMapZPT_bp01Data,
        Kensei150401_P.ThrottleMapZPT_tableData, 1U);

      /* Saturate: '<S8>/Pedal Limit zpt 2V' */
      tmp = Kensei150401_B.ThrottleMapZPT;
      u = Kensei150401_P.PedalLimitzpt2V_LowerSat;
      u_0 = Kensei150401_P.PedalLimitzpt2V_UpperSat;
      if (tmp >= u_0) {
        Kensei150401_B.PedalLimitzpt2V = u_0;
      } else if (tmp <= u) {
        Kensei150401_B.PedalLimitzpt2V = u;
      } else {
        Kensei150401_B.PedalLimitzpt2V = tmp;
      }

      /* End of Saturate: '<S8>/Pedal Limit zpt 2V' */
      Kensei150401_B.Switch1_p = Kensei150401_B.PedalLimitzpt2V;
    } else {
      /* Saturate: '<S8>/Pedal Limit 2 V (60 km//h) ' */
      tmp = Kensei150401_B.ThrottleMap1;
      u = Kensei150401_P.PedalLimit2V60kmh_LowerSat;
      u_0 = Kensei150401_P.PedalLimit2V60kmh_UpperSat;
      if (tmp >= u_0) {
        Kensei150401_B.PedalLimit2V60kmh = u_0;
      } else if (tmp <= u) {
        Kensei150401_B.PedalLimit2V60kmh = u;
      } else {
        Kensei150401_B.PedalLimit2V60kmh = tmp;
      }

      /* End of Saturate: '<S8>/Pedal Limit 2 V (60 km//h) ' */
      Kensei150401_B.Switch1_p = Kensei150401_B.PedalLimit2V60kmh;
    }

    /* End of Switch: '<S8>/Switch1' */
  }

  /* Sum: '<S8>/Sum' */
  Kensei150401_B.Sum_bv = Kensei150401_B.Switch1_p - Kensei150401_B.Integrator_p;

  /* Fcn: '<S8>/Fcn' */
  Kensei150401_B.Fcn = (real_T)(Kensei150401_B.Sum_bv >= 0.0) * 2.0 + (real_T)
    (Kensei150401_B.Sum_bv < 0.0);

  /* Product: '<S8>/Product1' */
  Kensei150401_B.Product1_l = Kensei150401_B.Fcn * Kensei150401_B.sport;

  /* Switch: '<S8>/Switch' */
  if (Kensei150401_B.Product1_l >= Kensei150401_P.Switch_Threshold_b) {
    Kensei150401_B.Switch_f = Kensei150401_B.Integrator_p;
  } else {
    Kensei150401_B.Switch_f = Kensei150401_B.Switch1_p;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Product: '<S8>/Product' */
  Kensei150401_B.Product_d = Kensei150401_B.pedalprop * Kensei150401_B.Switch_f;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Gain: '<S145>/Gain1' */
    Kensei150401_B.Gain1_b = Kensei150401_P.Gain1_Gain_l *
      Kensei150401_B.RoundingFunction2;

    /* Abs: '<S8>/Abs' */
    Kensei150401_B.Abs_n = fabs(Kensei150401_B.Gain1_b);

    /* Switch: '<S8>/Switch5' incorporates:
     *  Constant: '<S8>/zero1'
     */
    if (Kensei150401_B.Abs_n >= Kensei150401_P.Switch5_Threshold_i) {
      Kensei150401_B.Switch5_b = Kensei150401_B.Abs_n;
    } else {
      Kensei150401_B.Switch5_b = Kensei150401_P.zero1_Value;
    }

    /* End of Switch: '<S8>/Switch5' */

    /* Lookup_n-D: '<S8>/Throttle MapZPT1' */
    Kensei150401_B.ThrottleMapZPT1 = look1_binlxpw(Kensei150401_B.Switch5_b,
      Kensei150401_P.ThrottleMapZPT1_bp01Data,
      Kensei150401_P.ThrottleMapZPT1_tableData, 1U);

    /* Saturate: '<S8>/Pedal Limit zpt 2V1' */
    tmp = Kensei150401_B.ThrottleMapZPT1;
    u = Kensei150401_P.PedalLimitzpt2V1_LowerSat;
    u_0 = Kensei150401_P.PedalLimitzpt2V1_UpperSat;
    if (tmp >= u_0) {
      Kensei150401_B.PedalLimitzpt2V1 = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.PedalLimitzpt2V1 = u;
    } else {
      Kensei150401_B.PedalLimitzpt2V1 = tmp;
    }

    /* End of Saturate: '<S8>/Pedal Limit zpt 2V1' */

    /* Switch: '<S8>/Switch3' incorporates:
     *  Constant: '<S8>/zero'
     */
    if (Kensei150401_B.steerprop >= Kensei150401_P.Switch3_Threshold_j) {
      Kensei150401_B.pedalzpt = Kensei150401_B.PedalLimitzpt2V1;
    } else {
      Kensei150401_B.pedalzpt = Kensei150401_P.zero_Value;
    }

    /* End of Switch: '<S8>/Switch3' */
  }

  /* Sum: '<S8>/Add' */
  Kensei150401_B.Add = ((Kensei150401_B.Product_d + 0.0) +
                        Kensei150401_B.pedalzpt) + Kensei150401_B.offset;

  /* Saturate: '<S8>/0 to 5 V1' */
  tmp = Kensei150401_B.Add;
  u = Kensei150401_P.to5V1_LowerSat;
  u_0 = Kensei150401_P.to5V1_UpperSat;
  if (tmp >= u_0) {
    Kensei150401_B.to5V1 = u_0;
  } else if (tmp <= u) {
    Kensei150401_B.to5V1 = u;
  } else {
    Kensei150401_B.to5V1 = tmp;
  }

  /* End of Saturate: '<S8>/0 to 5 V1' */

  /* Product: '<S8>/Product2' */
  Kensei150401_B.Product2_m = Kensei150401_B.prop * Kensei150401_B.to5V1;

  /* Gain: '<S3>/outDAC2' */
  Kensei150401_B.outDAC2 = Kensei150401_P.outDAC2_Gain *
    Kensei150401_B.Product2_m;

  /* Saturate: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R' */
  tmp = Kensei150401_B.outDAC2;
  u = Kensei150401_P.OutputLimit05V005CR_LowerSat;
  u_0 = Kensei150401_P.OutputLimit05V005CR_UpperSat;
  if (tmp >= u_0) {
    Kensei150401_B.OutputLimit05V005CR = u_0;
  } else if (tmp <= u) {
    Kensei150401_B.OutputLimit05V005CR = u;
  } else {
    Kensei150401_B.OutputLimit05V005CR = tmp;
  }

  /* End of Saturate: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R' */

  /* Gain: '<S3>/outDAC4' */
  Kensei150401_B.outDAC4 = Kensei150401_P.outDAC4_Gain *
    Kensei150401_B.Product2_m;

  /* Saturate: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R2' */
  tmp = Kensei150401_B.outDAC4;
  u = Kensei150401_P.OutputLimit05V005CR2_LowerSat;
  u_0 = Kensei150401_P.OutputLimit05V005CR2_UpperSat;
  if (tmp >= u_0) {
    Kensei150401_B.OutputLimit05V005CR2 = u_0;
  } else if (tmp <= u) {
    Kensei150401_B.OutputLimit05V005CR2 = u;
  } else {
    Kensei150401_B.OutputLimit05V005CR2 = tmp;
  }

  /* End of Saturate: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R2' */
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Gain: '<S3>/outDAC6' incorporates:
     *  Constant: '<S8>/BrakeR'
     */
    Kensei150401_B.outDAC6 = Kensei150401_P.outDAC6_Gain *
      Kensei150401_P.BrakeR_Value;

    /* Saturate: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R1' */
    tmp = Kensei150401_B.outDAC6;
    u = Kensei150401_P.OutputLimit05V005CR1_LowerSat;
    u_0 = Kensei150401_P.OutputLimit05V005CR1_UpperSat;
    if (tmp >= u_0) {
      Kensei150401_B.OutputLimit05V005CR1 = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.OutputLimit05V005CR1 = u;
    } else {
      Kensei150401_B.OutputLimit05V005CR1 = tmp;
    }

    /* End of Saturate: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R1' */

    /* Gain: '<S3>/outDAC8' incorporates:
     *  Constant: '<S8>/BrakeL'
     */
    Kensei150401_B.outDAC8 = Kensei150401_P.outDAC8_Gain *
      Kensei150401_P.BrakeL_Value;

    /* Saturate: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R3' */
    tmp = Kensei150401_B.outDAC8;
    u = Kensei150401_P.OutputLimit05V005CR3_LowerSat;
    u_0 = Kensei150401_P.OutputLimit05V005CR3_UpperSat;
    if (tmp >= u_0) {
      Kensei150401_B.OutputLimit05V005CR3 = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.OutputLimit05V005CR3 = u;
    } else {
      Kensei150401_B.OutputLimit05V005CR3 = tmp;
    }

    /* End of Saturate: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R3' */

    /* S-Function (rti_commonblock): '<S31>/S-Function1' */
    /* This comment workarounds a code generation problem */
    {
      /* dSPACE I/O Board DS1401STDAIOT1 #1 Unit:DAC */
      /* write value of DAC for output channels 1-4 synchronous*/
      /*write to buffer*/
      aio_tp1_dac_buffer_write(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CH1, (dsfloat)
        Kensei150401_B.OutputLimit05V005CR);
      aio_tp1_dac_buffer_write(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CH2, (dsfloat)
        Kensei150401_B.OutputLimit05V005CR2);
      aio_tp1_dac_buffer_write(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CH3, (dsfloat)
        Kensei150401_B.OutputLimit05V005CR1);
      aio_tp1_dac_buffer_write(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CH4, (dsfloat)
        Kensei150401_B.OutputLimit05V005CR3);

      /*release buffer*/
      aio_tp1_dac_buffer_release(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CTRL_CH1|
        AIO_TP1_DAC_CTRL_CH2|AIO_TP1_DAC_CTRL_CH3|AIO_TP1_DAC_CTRL_CH4);
    }

    /* RelationalOperator: '<S134>/Compare' incorporates:
     *  Constant: '<S134>/Constant'
     */
    Kensei150401_B.Compare = (Kensei150401_B.RoundingFunction2 >=
      Kensei150401_P.Constant_Value_gc);

    /* S-Function (rti_commonblock): '<S32>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* write output state value to digital output channel 10 on port 1 */
    dio_tp4_digout_write(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH10, (UInt16)
                         (Kensei150401_B.Compare << 9));

    /* S-Function (rti_commonblock): '<S33>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* write output state value to digital output channel 11 on port 1 */
    dio_tp4_digout_write(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH11, (UInt16)
                         (Kensei150401_B.revL << 10));

    /* S-Function (rti_commonblock): '<S34>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* write output state value to digital output channel 12 on port 1 */
    dio_tp4_digout_write(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH12, (UInt16)
                         (Kensei150401_B.revR << 11));

    /* Constant: '<S108>/FRdirection' */
    Kensei150401_B.FRdirection = Kensei150401_P.FRdirection_Value;
  }

  /* Switch: '<S108>/Switch1' */
  if (Kensei150401_B.Switch_FR >= Kensei150401_P.Switch1_Threshold_b) {
    Kensei150401_B.Switch1_a = Kensei150401_B.FRdirection;
  } else {
    /* RelationalOperator: '<S114>/Compare' incorporates:
     *  Constant: '<S114>/Constant'
     */
    Kensei150401_B.Compare_i = (Kensei150401_B.Saturation_h >=
      Kensei150401_P.Constant_Value_ge);
    Kensei150401_B.Switch1_a = Kensei150401_B.Compare_i;
  }

  /* End of Switch: '<S108>/Switch1' */
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* S-Function (rti_commonblock): '<S35>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* write output state value to digital output channel 6 on port 1 */
    dio_tp4_digout_write(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH6, (UInt16)
                         (Kensei150401_B.Switch1_a << 5));

    /* Switch: '<S98>/Switch1' incorporates:
     *  Constant: '<S98>/FLdirection'
     *  Constant: '<S98>/Switch_FL'
     */
    if (Kensei150401_P.Switch_FL_Value >= Kensei150401_P.Switch1_Threshold_jh) {
      Kensei150401_B.Switch1_c = Kensei150401_P.FLdirection_Value;
    } else {
      /* RelationalOperator: '<S104>/Compare' incorporates:
       *  Constant: '<S104>/Constant'
       */
      Kensei150401_B.Compare_f = (Kensei150401_B.Switch1_h >=
        Kensei150401_P.Constant_Value_e0);

      /* S-Function (sfix_bitop): '<S98>/Bitwise Operator' */
      Kensei150401_B.BitwiseOperator_a = !Kensei150401_B.Compare_f;
      Kensei150401_B.Switch1_c = Kensei150401_B.BitwiseOperator_a;
    }

    /* End of Switch: '<S98>/Switch1' */

    /* S-Function (rti_commonblock): '<S36>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* write output state value to digital output channel 7 on port 1 */
    dio_tp4_digout_write(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH7, (UInt16)
                         (Kensei150401_B.Switch1_c << 6));

    /* Constant: '<S128>/RRdirection' */
    Kensei150401_B.RRdirection = Kensei150401_P.RRdirection_Value;
  }

  /* Switch: '<S128>/Switch1' */
  if (Kensei150401_B.Switch_RR >= Kensei150401_P.Switch1_Threshold_lu) {
    Kensei150401_B.Switch1_ju = Kensei150401_B.RRdirection;
  } else {
    /* RelationalOperator: '<S131>/Compare' incorporates:
     *  Constant: '<S131>/Constant'
     */
    Kensei150401_B.Compare_j = (Kensei150401_B.Switch1_i >=
      Kensei150401_P.Constant_Value_ew);
    Kensei150401_B.Switch1_ju = Kensei150401_B.Compare_j;
  }

  /* End of Switch: '<S128>/Switch1' */
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* S-Function (rti_commonblock): '<S37>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* write output state value to digital output channel 8 on port 1 */
    dio_tp4_digout_write(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH8, (UInt16)
                         (Kensei150401_B.Switch1_ju << 7));

    /* Switch: '<S121>/Switch1' incorporates:
     *  Constant: '<S121>/RLdirection'
     *  Constant: '<S121>/Switch_RL'
     */
    if (Kensei150401_P.Switch_RL_Value >= Kensei150401_P.Switch1_Threshold_jx) {
      Kensei150401_B.Switch1_b = Kensei150401_P.RLdirection_Value;
    } else {
      /* RelationalOperator: '<S124>/Compare' incorporates:
       *  Constant: '<S124>/Constant'
       */
      Kensei150401_B.Compare_h = (Kensei150401_B.Switch1_d >=
        Kensei150401_P.Constant_Value_ga);

      /* S-Function (sfix_bitop): '<S121>/Bitwise Operator' */
      Kensei150401_B.BitwiseOperator = !Kensei150401_B.Compare_h;
      Kensei150401_B.Switch1_b = Kensei150401_B.BitwiseOperator;
    }

    /* End of Switch: '<S121>/Switch1' */

    /* S-Function (rti_commonblock): '<S38>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* write output state value to digital output channel 9 on port 1 */
    dio_tp4_digout_write(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH9, (UInt16)
                         (Kensei150401_B.Switch1_b << 8));

    /* Constant: '<S44>/Vmin' */
    Kensei150401_B.Vmin = Kensei150401_P.Vmin_Value;
  }

  /* StateSpace: '<S44>/Analog Filter_FR_Pos' */
  {
    Kensei150401_B.AnalogFilter_FR_Pos_g =
      Kensei150401_P.AnalogFilter_FR_Pos_C_k*
      Kensei150401_X.AnalogFilter_FR_Pos_CSTATE_h;
  }

  /* Gain: '<S44>/Ampere//volt' */
  Kensei150401_B.Amperevolt = Kensei150401_P.Amperevolt_Gain *
    Kensei150401_B.AnalogFilter_FR_Pos_g;

  /* Sum: '<S44>/Add' */
  Kensei150401_B.Add_d = Kensei150401_B.Amperevolt - Kensei150401_B.Vmin;

  /* Gain: '<S44>/ratio1' */
  Kensei150401_B.ratio1_gq = Kensei150401_P.ratio1_Gain_a * Kensei150401_B.Add_d;

  /* Rounding: '<S44>/Rounding Function1' */
  Kensei150401_B.RoundingFunction1_b = rt_roundd_snf(Kensei150401_B.ratio1_gq);

  /* Gain: '<S44>/ratio2' */
  Kensei150401_B.ratio2_j = Kensei150401_P.ratio2_Gain_de *
    Kensei150401_B.RoundingFunction1_b;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* S-Function (rti_commonblock): '<S56>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE RTICAN RX Message Block: "RX Message Controller 1" Id:115 */
    {
      UInt32 *CAN_Msg;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read_from_mem(can_type1_msg_M1[CANTP1_M1_C2_RX_STD_0X73]);

      /* Convert timestamp */
      if (can_type1_msg_M1[CANTP1_M1_C2_RX_STD_0X73]->processed) {
        can_type1_msg_M1[CANTP1_M1_C2_RX_STD_0X73]->timestamp =
          rtk_dsts_time_to_simtime_convert
          (can_type1_msg_M1[CANTP1_M1_C2_RX_STD_0X73]->timestamp);
      }

      /* Messages with timestamp zero have been received in pause/stop state
         and must not be handled.
       */
      if (can_type1_msg_M1[CANTP1_M1_C2_RX_STD_0X73]->timestamp > 0.0) {
        if (can_type1_msg_M1[CANTP1_M1_C2_RX_STD_0X73]->processed) {
          Kensei150401_B.SFunction1_o4 = (real_T)
            can_type1_msg_M1[CANTP1_M1_C2_RX_STD_0X73]->processed;
          Kensei150401_B.SFunction1_o5 = (real_T)
            can_type1_msg_M1[CANTP1_M1_C2_RX_STD_0X73]->deltatime;
          CAN_Msg = can_type1_msg_M1[CANTP1_M1_C2_RX_STD_0X73]->data;

          /* ... Decode CAN Message */
          {
            rtican_Signal_t CAN_Sgn;

            /* ...... "MSB" (0|8, standard signal, unsigned int, little endian) */
            CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[0];
            CAN_Sgn.UnsignedSgn &= 0x000000FF;
            Kensei150401_B.SFunction1_o1_h = ((real_T) CAN_Sgn.UnsignedSgn);

            /* ...... "LSB" (8|8, standard signal, unsigned int, little endian) */
            CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[1];
            CAN_Sgn.UnsignedSgn &= 0x000000FF;
            Kensei150401_B.SFunction1_o2_jz = ((real_T) CAN_Sgn.UnsignedSgn);

            /* ...... "CurrentPerc" (16|8, standard signal, unsigned int, little endian) */
            CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[2];
            CAN_Sgn.UnsignedSgn &= 0x000000FF;
            Kensei150401_B.SFunction1_o3 = ((real_T) CAN_Sgn.UnsignedSgn);
          }
        }
      }

      if (!can_type1_msg_M1[CANTP1_M1_C2_RX_STD_0X73]->processed) {
        /* ... set RX status to 0 because no new message has arrived */
        Kensei150401_B.SFunction1_o4 = 0.0;
      }
    }

    /* Gain: '<S45>/Current' */
    Kensei150401_B.Current = Kensei150401_P.Current_Gain *
      Kensei150401_B.SFunction1_o3;

    /* S-Function (rti_commonblock): '<S57>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE RTICAN RX Message Block: "RX Message Controller 1" Id:116 */
    {
      UInt32 *CAN_Msg;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read_from_mem(can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X74]);

      /* Convert timestamp */
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X74]->processed) {
        can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X74]->timestamp =
          rtk_dsts_time_to_simtime_convert
          (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X74]->timestamp);
      }

      /* Messages with timestamp zero have been received in pause/stop state
         and must not be handled.
       */
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X74]->timestamp > 0.0) {
        if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X74]->processed) {
          Kensei150401_B.SFunction1_o4_m = (real_T)
            can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X74]->processed;
          Kensei150401_B.SFunction1_o5_i = (real_T)
            can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X74]->deltatime;
          CAN_Msg = can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X74]->data;

          /* ... Decode CAN Message */
          {
            rtican_Signal_t CAN_Sgn;

            /* ...... "MSB" (0|8, standard signal, unsigned int, little endian) */
            CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[0];
            CAN_Sgn.UnsignedSgn &= 0x000000FF;
            Kensei150401_B.SFunction1_o1_b = ((real_T) CAN_Sgn.UnsignedSgn);

            /* ...... "LSB" (8|8, standard signal, unsigned int, little endian) */
            CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[1];
            CAN_Sgn.UnsignedSgn &= 0x000000FF;
            Kensei150401_B.SFunction1_o2_c = ((real_T) CAN_Sgn.UnsignedSgn);

            /* ...... "CurrentPerc" (16|8, standard signal, unsigned int, little endian) */
            CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[2];
            CAN_Sgn.UnsignedSgn &= 0x000000FF;
            Kensei150401_B.SFunction1_o3_m = ((real_T) CAN_Sgn.UnsignedSgn);
          }
        }
      }

      if (!can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X74]->processed) {
        /* ... set RX status to 0 because no new message has arrived */
        Kensei150401_B.SFunction1_o4_m = 0.0;
      }
    }

    /* Gain: '<S45>/Current1' */
    Kensei150401_B.Current1 = Kensei150401_P.Current1_Gain *
      Kensei150401_B.SFunction1_o3_m;

    /* Gain: '<S45>/Gain' */
    Kensei150401_B.Gain_p = Kensei150401_P.Gain_Gain_m *
      Kensei150401_B.SFunction1_o1_h;

    /* Gain: '<S45>/Gain1' */
    Kensei150401_B.Gain1_bw = Kensei150401_P.Gain1_Gain_h1 *
      Kensei150401_B.SFunction1_o1_b;

    /* Sum: '<S45>/RPM' */
    Kensei150401_B.RPM = Kensei150401_B.Gain_p + Kensei150401_B.SFunction1_o2_jz;

    /* Sum: '<S45>/RPM1' */
    Kensei150401_B.RPM1 = Kensei150401_B.Gain1_bw +
      Kensei150401_B.SFunction1_o2_c;

    /* SignalConversion: '<S45>/TmpSignal ConversionAtRounding Function1Inport1' */
    Kensei150401_B.TmpSignalConversionAtRoundingFu[0] = Kensei150401_B.RPM1;
    Kensei150401_B.TmpSignalConversionAtRoundingFu[1] = Kensei150401_B.RPM;

    /* Gain: '<S45>/RPM to RPSec' */
    Kensei150401_B.RPMtoRPSec[0] = Kensei150401_P.RPMtoRPSec_Gain *
      Kensei150401_B.TmpSignalConversionAtRoundingFu[0];
    Kensei150401_B.RPMtoRPSec[1] = Kensei150401_P.RPMtoRPSec_Gain *
      Kensei150401_B.TmpSignalConversionAtRoundingFu[1];

    /* Gain: '<S45>/RPSec to w' */
    Kensei150401_B.RPSectow_a[0] = Kensei150401_P.RPSectow_Gain_d *
      Kensei150401_B.RPMtoRPSec[0];
    Kensei150401_B.RPSectow_a[1] = Kensei150401_P.RPSectow_Gain_d *
      Kensei150401_B.RPMtoRPSec[1];

    /* Rounding: '<S45>/Rounding Function1' */
    Kensei150401_B.RoundingFunction1_f[0] = rt_roundd_snf
      (Kensei150401_B.TmpSignalConversionAtRoundingFu[0]);
    Kensei150401_B.RoundingFunction1_f[1] = rt_roundd_snf
      (Kensei150401_B.TmpSignalConversionAtRoundingFu[1]);

    /* Gain: '<S45>/Tyre radius' */
    Kensei150401_B.ms_e[0] = Kensei150401_P.Tyreradius_Gain_n *
      Kensei150401_B.RPSectow_a[0];
    Kensei150401_B.ms_e[1] = Kensei150401_P.Tyreradius_Gain_n *
      Kensei150401_B.RPSectow_a[1];

    /* Gain: '<S45>/m//s to km//h' */
    Kensei150401_B.mstokmh_h[0] = Kensei150401_P.mstokmh_Gain_f *
      Kensei150401_B.ms_e[0];
    Kensei150401_B.mstokmh_h[1] = Kensei150401_P.mstokmh_Gain_f *
      Kensei150401_B.ms_e[1];

    /* Rounding: '<S45>/Rounding Function2' */
    Kensei150401_B.RoundingFunction2_g[0] = rt_roundd_snf
      (Kensei150401_B.mstokmh_h[0]);
    Kensei150401_B.RoundingFunction2_g[1] = rt_roundd_snf
      (Kensei150401_B.mstokmh_h[1]);

    /* RelationalOperator: '<S58>/New data' incorporates:
     *  Constant: '<S58>/New data value'
     */
    Kensei150401_B.Newdata = (Kensei150401_B.SFunction1_o4 ==
      Kensei150401_P.Newdatavalue_Value);

    /* RelationalOperator: '<S58>/Delta time limit exceeded' incorporates:
     *  Constant: '<S58>/Delta time limit'
     */
    Kensei150401_B.Deltatimelimitexceeded = (Kensei150401_B.SFunction1_o5 >=
      Kensei150401_P.Deltatimelimit_Value);

    /* Logic: '<S58>/AND' */
    Kensei150401_B.AND = (Kensei150401_B.Newdata &&
                          Kensei150401_B.Deltatimelimitexceeded);

    /* Memory: '<S58>/Mem1' */
    Kensei150401_B.Mem1 = Kensei150401_DWork.Mem1_PreviousInput;

    /* Memory: '<S58>/Mem2' */
    Kensei150401_B.Mem2 = Kensei150401_DWork.Mem2_PreviousInput;

    /* Memory: '<S58>/Mem3' */
    Kensei150401_B.Mem3 = Kensei150401_DWork.Mem3_PreviousInput;

    /* Memory: '<S58>/Mem4' */
    Kensei150401_B.Mem4 = Kensei150401_DWork.Mem4_PreviousInput;

    /* Memory: '<S58>/Mem5' */
    Kensei150401_B.Mem5 = Kensei150401_DWork.Mem5_PreviousInput;

    /* RelationalOperator: '<S58>/No data' incorporates:
     *  Constant: '<S58>/No data value'
     */
    Kensei150401_B.Nodata = (Kensei150401_B.SFunction1_o4 ==
      Kensei150401_P.Nodatavalue_Value);

    /* Logic: '<S58>/OR' */
    Kensei150401_B.OR = (Kensei150401_B.Nodata || Kensei150401_B.AND);

    /* Logic: '<S58>/Warn' */
    Kensei150401_B.Warn = (Kensei150401_B.OR && Kensei150401_B.Mem1 &&
      Kensei150401_B.Mem2 && Kensei150401_B.Mem3 && Kensei150401_B.Mem4 &&
      Kensei150401_B.Mem5);

    /* RelationalOperator: '<S59>/New data' incorporates:
     *  Constant: '<S59>/New data value'
     */
    Kensei150401_B.Newdata_n = (Kensei150401_B.SFunction1_o4_m ==
      Kensei150401_P.Newdatavalue_Value_l);

    /* RelationalOperator: '<S59>/Delta time limit exceeded' incorporates:
     *  Constant: '<S59>/Delta time limit'
     */
    Kensei150401_B.Deltatimelimitexceeded_k = (Kensei150401_B.SFunction1_o5_i >=
      Kensei150401_P.Deltatimelimit_Value_n);

    /* Logic: '<S59>/AND' */
    Kensei150401_B.AND_i = (Kensei150401_B.Newdata_n &&
      Kensei150401_B.Deltatimelimitexceeded_k);

    /* Memory: '<S59>/Mem1' */
    Kensei150401_B.Mem1_l = Kensei150401_DWork.Mem1_PreviousInput_m;

    /* Memory: '<S59>/Mem2' */
    Kensei150401_B.Mem2_h = Kensei150401_DWork.Mem2_PreviousInput_d;

    /* Memory: '<S59>/Mem3' */
    Kensei150401_B.Mem3_f = Kensei150401_DWork.Mem3_PreviousInput_l;

    /* Memory: '<S59>/Mem4' */
    Kensei150401_B.Mem4_e = Kensei150401_DWork.Mem4_PreviousInput_j;

    /* Memory: '<S59>/Mem5' */
    Kensei150401_B.Mem5_p = Kensei150401_DWork.Mem5_PreviousInput_g;

    /* RelationalOperator: '<S59>/No data' incorporates:
     *  Constant: '<S59>/No data value'
     */
    Kensei150401_B.Nodata_d = (Kensei150401_B.SFunction1_o4_m ==
      Kensei150401_P.Nodatavalue_Value_b);

    /* Logic: '<S59>/OR' */
    Kensei150401_B.OR_n = (Kensei150401_B.Nodata_d || Kensei150401_B.AND_i);

    /* Logic: '<S59>/Warn' */
    Kensei150401_B.Warn_i = (Kensei150401_B.OR_n && Kensei150401_B.Mem1_l &&
      Kensei150401_B.Mem2_h && Kensei150401_B.Mem3_f && Kensei150401_B.Mem4_e &&
      Kensei150401_B.Mem5_p);

    /* S-Function (rti_commonblock): '<S61>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE RTICAN TX Message Block: "TX Message Controller 2" Id:107 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X6B]);

      /* Convert timestamp */
      if (can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X6B]->processed) {
        can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X6B]->timestamp =
          rtk_dsts_time_to_simtime_convert
          (can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X6B]->timestamp);
      }

      /* Messages with timestamp zero have been received in pause/stop state
         and must not be handled.
       */
      if (can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X6B]->timestamp > 0.0) {
        Kensei150401_B.SFunction1_o1_c = (real_T)
          can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X6B]->processed;
        Kensei150401_B.SFunction1_o2_d = (real_T)
          can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X6B]->deltatime;
      }

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "RPMRequest" (0|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( Kensei150401_P.Constant_Value_o ) +
          0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X6B], 1, &(CAN_Msg
        [0]), delayTime);
    }

    /* RelationalOperator: '<S62>/Delta time limit exceeded' incorporates:
     *  Constant: '<S62>/Delta time limit'
     */
    Kensei150401_B.Deltatimelimitexceeded_j = (Kensei150401_B.SFunction1_o2_d >=
      Kensei150401_P.Deltatimelimit_Value_i);

    /* Memory: '<S62>/Mem1' */
    Kensei150401_B.Mem1_p = Kensei150401_DWork.Mem1_PreviousInput_p;

    /* Memory: '<S62>/Mem2' */
    Kensei150401_B.Mem2_d = Kensei150401_DWork.Mem2_PreviousInput_m;

    /* Memory: '<S62>/Mem3' */
    Kensei150401_B.Mem3_g = Kensei150401_DWork.Mem3_PreviousInput_f;

    /* Memory: '<S62>/Mem4' */
    Kensei150401_B.Mem4_a = Kensei150401_DWork.Mem4_PreviousInput_b;

    /* RelationalOperator: '<S62>/Prev. msg.  not sent' incorporates:
     *  Constant: '<S62>/Prev. msg. sent value'
     */
    Kensei150401_B.Prevmsgnotsent = (Kensei150401_B.SFunction1_o1_c !=
      Kensei150401_P.Prevmsgsentvalue_Value);

    /* Logic: '<S62>/OR' */
    Kensei150401_B.OR_a = (Kensei150401_B.Prevmsgnotsent ||
      Kensei150401_B.Deltatimelimitexceeded_j);

    /* Logic: '<S62>/Warn' */
    Kensei150401_B.Warn_j = (Kensei150401_B.OR_a && Kensei150401_B.Mem1_p &&
      Kensei150401_B.Mem2_d && Kensei150401_B.Mem3_g && Kensei150401_B.Mem4_a);

    /* S-Function (rti_commonblock): '<S60>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE RTICAN TX Message Block: "TX Message Controller 2" Id:108 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X6C]);

      /* Convert timestamp */
      if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X6C]->processed) {
        can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X6C]->timestamp =
          rtk_dsts_time_to_simtime_convert
          (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X6C]->timestamp);
      }

      /* Messages with timestamp zero have been received in pause/stop state
         and must not be handled.
       */
      if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X6C]->timestamp > 0.0) {
        Kensei150401_B.SFunction1_o1_d = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X6C]->processed;
        Kensei150401_B.SFunction1_o2_nb = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X6C]->deltatime;
      }

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "RPMRequest" (0|8, standard signal, unsigned int, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.UnsignedSgn = (UInt32) (( Kensei150401_P.Constant1_Value_p ) +
          0.5);
        CAN_Sgn.UnsignedSgn &= 0x000000FF;
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X6C], 1, &(CAN_Msg
        [0]), delayTime);
    }

    /* RelationalOperator: '<S63>/Delta time limit exceeded' incorporates:
     *  Constant: '<S63>/Delta time limit'
     */
    Kensei150401_B.Deltatimelimitexceeded_b = (Kensei150401_B.SFunction1_o2_nb >=
      Kensei150401_P.Deltatimelimit_Value_p);

    /* Memory: '<S63>/Mem1' */
    Kensei150401_B.Mem1_i = Kensei150401_DWork.Mem1_PreviousInput_pu;

    /* Memory: '<S63>/Mem2' */
    Kensei150401_B.Mem2_k = Kensei150401_DWork.Mem2_PreviousInput_o;

    /* Memory: '<S63>/Mem3' */
    Kensei150401_B.Mem3_b = Kensei150401_DWork.Mem3_PreviousInput_fn;

    /* Memory: '<S63>/Mem4' */
    Kensei150401_B.Mem4_b = Kensei150401_DWork.Mem4_PreviousInput_e;

    /* RelationalOperator: '<S63>/Prev. msg.  not sent' incorporates:
     *  Constant: '<S63>/Prev. msg. sent value'
     */
    Kensei150401_B.Prevmsgnotsent_n = (Kensei150401_B.SFunction1_o1_d !=
      Kensei150401_P.Prevmsgsentvalue_Value_k);

    /* Logic: '<S63>/OR' */
    Kensei150401_B.OR_a5 = (Kensei150401_B.Prevmsgnotsent_n ||
      Kensei150401_B.Deltatimelimitexceeded_b);

    /* Logic: '<S63>/Warn' */
    Kensei150401_B.Warn_d = (Kensei150401_B.OR_a5 && Kensei150401_B.Mem1_i &&
      Kensei150401_B.Mem2_k && Kensei150401_B.Mem3_b && Kensei150401_B.Mem4_b);

    /* S-Function (rti_commonblock): '<S52>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S53>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S46>/RPSec to w1' */
    Kensei150401_B.RPSectow1 = Kensei150401_P.RPSectow1_Gain *
      Kensei150401_B.RateTransition1;

    /* RateTransition: '<S46>/Rate Transition3' */
    switch (Kensei150401_DWork.RateTransition3_write_buf) {
     case 0:
      Kensei150401_DWork.RateTransition3_read_buf = 1;
      break;

     case 1:
      Kensei150401_DWork.RateTransition3_read_buf = 0;
      break;

     default:
      Kensei150401_DWork.RateTransition3_read_buf =
        Kensei150401_DWork.RateTransition3_last_buf_wr;
      break;
    }

    if (Kensei150401_DWork.RateTransition3_read_buf != 0) {
      Kensei150401_B.RateTransition3 =
        Kensei150401_DWork.RateTransition3_Buffer1;
    } else {
      Kensei150401_B.RateTransition3 =
        Kensei150401_DWork.RateTransition3_Buffer0;
    }

    Kensei150401_DWork.RateTransition3_read_buf = -1;

    /* End of RateTransition: '<S46>/Rate Transition3' */

    /* Gain: '<S46>/pulses to revolution' */
    Kensei150401_B.pulsestorevolution = Kensei150401_P.pulsestorevolution_Gain *
      Kensei150401_B.RateTransition3;

    /* Gain: '<S46>/RPSec to w2' */
    Kensei150401_B.RPSectow2 = Kensei150401_P.RPSectow2_Gain *
      Kensei150401_B.pulsestorevolution;

    /* Gain: '<S46>/Tyre radius2' */
    Kensei150401_B.ms_d = Kensei150401_P.Tyreradius2_Gain *
      Kensei150401_B.RPSectow2;

    /* S-Function (rti_commonblock): '<S71>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* DataTypeConversion: '<S47>/Data Type  Conversion2' */
    Kensei150401_B.DataTypeConversion2 = Kensei150401_B.SFunction1_o1_f;

    /* Sum: '<S46>/Sum' */
    Kensei150401_B.Sum_p = Kensei150401_B.ms_d +
      Kensei150401_B.DataTypeConversion2;

    /* Rounding: '<S46>/Rounded odo1' */
    Kensei150401_B.Roundedodo1 = rt_roundd_snf(Kensei150401_B.Sum_p);

    /* Gain: '<S46>/Tyre radius1' */
    Kensei150401_B.ms_b = Kensei150401_P.Tyreradius1_Gain *
      Kensei150401_B.RPSectow1;

    /* Gain: '<S46>/m to km' */
    Kensei150401_B.mtokm = Kensei150401_P.mtokm_Gain *
      Kensei150401_B.Roundedodo1;

    /* Gain: '<S46>/m//s to km//h1' */
    Kensei150401_B.mstokmh1 = Kensei150401_P.mstokmh1_Gain * Kensei150401_B.ms_b;

    /* S-Function (rti_commonblock): '<S69>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* DataTypeConversion: '<S47>/Data Type  Conversion1' */
    Kensei150401_B.DataTypeConversion1_e = (real_T)
      Kensei150401_B.SFunction1_o2_l;

    /* S-Function (rti_commonblock): '<S68>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS1401BASE #1 Unit:POWER */
    if (Kensei150401_B.DataTypeConversion1_e == 1) {
      simState = 0;                    /* stop */
    }

    /* DataTypeConversion: '<S47>/Data Type  Conversion3' */
    Kensei150401_B.DataTypeConversion3 = Kensei150401_B.Sum_p;

    /* S-Function (rti_commonblock): '<S72>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DSFLASH Unit:NVDATASTORE */
    State_NVData_Odometer = 2;

    /* S-Function (rti_commonblock): '<S70>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Pack: <S48>/Byte Pack */
    (void) memcpy(&Kensei150401_B.BytePack, (real_T*)&Kensei150401_RGND,
                  8);

    /* S-Function (rti_commonblock): '<S73>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board 1401stdasertp1 #1 Unit:GENSER Group:RECEIVE */
    {
      UInt32 bytesActNumOfAddr;
      Kensei150401_B.SFunction1_o2_e = dsser_receive(rti1401stdasertp1_B1_Ser[0],
        1U, (UInt8 *) &Kensei150401_B.SFunction1_o1_cc, &(bytesActNumOfAddr));
    }

    /* DataTypeConversion: '<S48>/Data Type Conversion1' */
    Kensei150401_B.DataTypeConversion1_j = Kensei150401_B.SFunction1_o1_cc;

    /* S-Function (rti_commonblock): '<S75>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* DiscretePulseGenerator: '<S48>/Pulse Generator' */
    Kensei150401_B.PulseGenerator = ((real_T)Kensei150401_DWork.clockTickCounter
      < Kensei150401_P.PulseGenerator_Duty) &&
      (Kensei150401_DWork.clockTickCounter >= 0) ?
      Kensei150401_P.PulseGenerator_Amp : 0.0;
    if ((real_T)Kensei150401_DWork.clockTickCounter >=
        Kensei150401_P.PulseGenerator_Period - 1.0) {
      Kensei150401_DWork.clockTickCounter = 0;
    } else {
      Kensei150401_DWork.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<S48>/Pulse Generator' */

    /* DataTypeConversion: '<S48>/Data Type Conversion' */
    tmp = floor(Kensei150401_B.PulseGenerator);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 256.0);
    }

    Kensei150401_B.DataTypeConversion_o = (uint8_T)(tmp < 0.0 ? (uint8_T)
      (int32_T)(int8_T)-(int8_T)(uint8_T)-tmp : (uint8_T)tmp);

    /* End of DataTypeConversion: '<S48>/Data Type Conversion' */

    /* S-Function (rti_commonblock): '<S76>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board 1401stdasertp1 #1 Unit:GENSER Group:TRANSMIT */
    {
      Kensei150401_B.SFunction1_o2_a = dsser_transmit(rti1401stdasertp1_B1_Ser[0],
        1U, &Kensei150401_B.DataTypeConversion_o, (UInt32 *)
        &Kensei150401_B.SFunction1_o1_lx);
    }

    /* ManualSwitch: '<S48>/Manual Switch' */
    if (Kensei150401_P.ManualSwitch_CurrentSetting == 1) {
      Kensei150401_B.ManualSwitch = 0.0;
    } else {
      Kensei150401_B.ManualSwitch = 0.0;
    }

    /* End of ManualSwitch: '<S48>/Manual Switch' */
  }

  /* Sin: '<S48>/Sine Wave' */
  Kensei150401_B.SineWave = sin(Kensei150401_P.SineWave_Freq *
    Kensei150401_M->Timing.t[0] + Kensei150401_P.SineWave_Phase) *
    Kensei150401_P.SineWave_Amp + Kensei150401_P.SineWave_Bias;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Constant: '<S48>/numbytes' */
    Kensei150401_B.numbytes = Kensei150401_P.numbytes_Value;

    /* S-Function (rti_commonblock): '<S74>/S-Function1' */
    /* This comment workarounds a code generation problem */
  }

  /* Gain: '<S97>/Integral Gain' */
  Kensei150401_B.IntegralGain = Kensei150401_P.IntegralGain_Gain *
    Kensei150401_B.Sum_o;

  /* Sum: '<S97>/SumI2' */
  Kensei150401_B.SumI2 = Kensei150401_B.Saturation_f -
    Kensei150401_B.ProportionalGain_l;

  /* Gain: '<S97>/Kb' */
  Kensei150401_B.Kb = Kensei150401_P.Kb_Gain * Kensei150401_B.SumI2;

  /* Sum: '<S97>/SumI1' */
  Kensei150401_B.SumI1 = Kensei150401_B.IntegralGain + Kensei150401_B.Kb;

  /* Gain: '<S103>/FL_Volt per mm' */
  Kensei150401_B.FL_Voltpermm = Kensei150401_P.FL_Voltpermm_Gain *
    Kensei150401_B.AnalogFilter_FL_Pos;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Gain: '<S103>/FL_Volt per mm1' incorporates:
     *  Constant: '<S103>/FL ADC min'
     */
    Kensei150401_B.FL_Voltpermm1 = Kensei150401_P.FL_Voltpermm1_Gain *
      Kensei150401_P.FLADCmin_Value;

    /* Gain: '<S103>/FL_Volt per mm2' incorporates:
     *  Constant: '<S103>/FL ADC Center'
     */
    Kensei150401_B.FL_Voltpermm2_p = Kensei150401_P.FL_Voltpermm2_Gain_n *
      Kensei150401_P.FLADCCenter_Value_f;

    /* Math: '<S106>/Math Function' incorporates:
     *  Constant: '<S106>/b'
     */
    Kensei150401_B.MathFunction_n0 = Kensei150401_P.b_Value_mg *
      Kensei150401_P.b_Value_mg;

    /* Math: '<S106>/Math Function1' incorporates:
     *  Constant: '<S106>/c'
     */
    Kensei150401_B.MathFunction1_c = Kensei150401_P.c_Value_h *
      Kensei150401_P.c_Value_h;

    /* Math: '<S106>/Math Function2' incorporates:
     *  Constant: '<S106>/d'
     */
    Kensei150401_B.MathFunction2_k = Kensei150401_P.d_Value_f *
      Kensei150401_P.d_Value_f;

    /* Sum: '<S106>/Sum' */
    Kensei150401_B.Sum_hh = (Kensei150401_B.MathFunction_n0 +
      Kensei150401_B.MathFunction1_c) - Kensei150401_B.MathFunction2_k;

    /* Product: '<S106>/Divide2' incorporates:
     *  Constant: '<S106>/b'
     *  Constant: '<S106>/c'
     *  Constant: '<S106>/constant'
     */
    Kensei150401_B.Divide2_d = Kensei150401_P.constant_Value_e0 *
      Kensei150401_P.c_Value_h * Kensei150401_P.b_Value_mg;

    /* Product: '<S106>/Divide' */
    Kensei150401_B.Divide_c = Kensei150401_B.Sum_hh / Kensei150401_B.Divide2_d;
  }

  /* Sum: '<S103>/Sum' */
  Kensei150401_B.Sum_g = Kensei150401_B.FL_Voltpermm -
    Kensei150401_B.FL_Voltpermm1;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Sum: '<S103>/Sum2' */
    Kensei150401_B.Sum2_l = Kensei150401_B.FL_Voltpermm2_p -
      Kensei150401_B.FL_Voltpermm1;
  }

  /* Sum: '<S103>/Sum3' */
  Kensei150401_B.Sum3_d = Kensei150401_B.Sum_g - Kensei150401_B.Sum2_l;

  /* Gain: '<S106>/mm to meter' */
  Kensei150401_B.mmtometer = Kensei150401_P.mmtometer_Gain *
    Kensei150401_B.Sum3_d;

  /* Sum: '<S106>/Sum2' incorporates:
   *  Constant: '<S106>/d'
   */
  Kensei150401_B.Sum2_hw = Kensei150401_B.mmtometer + Kensei150401_P.d_Value_f;

  /* Math: '<S106>/Math Function3' */
  Kensei150401_B.MathFunction3 = Kensei150401_B.Sum2_hw * Kensei150401_B.Sum2_hw;

  /* Sum: '<S106>/Sum1' */
  Kensei150401_B.Sum1_n = (Kensei150401_B.MathFunction_n0 +
    Kensei150401_B.MathFunction1_c) - Kensei150401_B.MathFunction3;

  /* Product: '<S106>/Divide1' */
  Kensei150401_B.Divide1_g = Kensei150401_B.Sum1_n / Kensei150401_B.Divide2_d;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Fcn: '<S106>/Epsilon' */
    tmp = Kensei150401_B.Divide_c;
    if (tmp >= 1.0) {
      tmp = 1.0;
    } else {
      if (tmp <= -1.0) {
        tmp = -1.0;
      }
    }

    tmp = acos(tmp);
    Kensei150401_B.Epsilon_o = tmp;

    /* End of Fcn: '<S106>/Epsilon' */
  }

  /* Fcn: '<S106>/Fcn1' */
  tmp = Kensei150401_B.Divide1_g;
  if (tmp >= 1.0) {
    tmp = 1.0;
  } else {
    if (tmp <= -1.0) {
      tmp = -1.0;
    }
  }

  tmp = acos(tmp);
  Kensei150401_B.Fcn1_p = tmp;

  /* End of Fcn: '<S106>/Fcn1' */

  /* Sum: '<S106>/Sum3' */
  Kensei150401_B.Sum3_a = Kensei150401_B.Fcn1_p - Kensei150401_B.Epsilon_o;

  /* Gain: '<S106>/rad to degree' */
  Kensei150401_B.radtodegree = Kensei150401_P.radtodegree_Gain *
    Kensei150401_B.Sum3_a;

  /* Gain: '<S107>/Integral Gain' */
  Kensei150401_B.IntegralGain_b = Kensei150401_P.IntegralGain_Gain_m *
    Kensei150401_B.Sum1_d;

  /* Sum: '<S107>/SumI2' */
  Kensei150401_B.SumI2_o = Kensei150401_B.Saturation_h -
    Kensei150401_B.ProportionalGain;

  /* Gain: '<S107>/Kb' */
  Kensei150401_B.Kb_m = Kensei150401_P.Kb_Gain_a * Kensei150401_B.SumI2_o;

  /* Sum: '<S107>/SumI1' */
  Kensei150401_B.SumI1_d = Kensei150401_B.IntegralGain_b + Kensei150401_B.Kb_m;

  /* Gain: '<S113>/FR_Volt per mm' */
  Kensei150401_B.FR_Voltpermm = Kensei150401_P.FR_Voltpermm_Gain *
    Kensei150401_B.AnalogFilter_FR_Pos;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Gain: '<S113>/FR_Volt per mm1' incorporates:
     *  Constant: '<S113>/FR ADC min'
     */
    Kensei150401_B.FR_Voltpermm1 = Kensei150401_P.FR_Voltpermm1_Gain *
      Kensei150401_P.FRADCmin_Value;

    /* Gain: '<S113>/FR_Volt per mm2' incorporates:
     *  Constant: '<S113>/FR ADC Center'
     */
    Kensei150401_B.FR_Voltpermm2_h = Kensei150401_P.FR_Voltpermm2_Gain_n *
      Kensei150401_P.FRADCCenter_Value_a;

    /* Math: '<S116>/Math Function' incorporates:
     *  Constant: '<S116>/b'
     */
    Kensei150401_B.MathFunction_g = Kensei150401_P.b_Value_l *
      Kensei150401_P.b_Value_l;

    /* Math: '<S116>/Math Function1' incorporates:
     *  Constant: '<S116>/c'
     */
    Kensei150401_B.MathFunction1_g = Kensei150401_P.c_Value_hu *
      Kensei150401_P.c_Value_hu;

    /* Math: '<S116>/Math Function2' incorporates:
     *  Constant: '<S116>/d'
     */
    Kensei150401_B.MathFunction2_n = Kensei150401_P.d_Value_a *
      Kensei150401_P.d_Value_a;

    /* Sum: '<S116>/Sum' */
    Kensei150401_B.Sum_l = (Kensei150401_B.MathFunction_g +
      Kensei150401_B.MathFunction1_g) - Kensei150401_B.MathFunction2_n;

    /* Product: '<S116>/Divide2' incorporates:
     *  Constant: '<S116>/b'
     *  Constant: '<S116>/c'
     *  Constant: '<S116>/constant'
     */
    Kensei150401_B.Divide2_b0 = Kensei150401_P.constant_Value_h5 *
      Kensei150401_P.c_Value_hu * Kensei150401_P.b_Value_l;

    /* Product: '<S116>/Divide' */
    Kensei150401_B.Divide_i = Kensei150401_B.Sum_l / Kensei150401_B.Divide2_b0;
  }

  /* Sum: '<S113>/Sum' */
  Kensei150401_B.Sum_e = Kensei150401_B.FR_Voltpermm -
    Kensei150401_B.FR_Voltpermm1;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Sum: '<S113>/Sum2' */
    Kensei150401_B.Sum2_e = Kensei150401_B.FR_Voltpermm2_h -
      Kensei150401_B.FR_Voltpermm1;
  }

  /* Sum: '<S113>/Sum3' */
  Kensei150401_B.Sum3_b = Kensei150401_B.Sum_e - Kensei150401_B.Sum2_e;

  /* Gain: '<S116>/mm to meter' */
  Kensei150401_B.mmtometer_i = Kensei150401_P.mmtometer_Gain_p *
    Kensei150401_B.Sum3_b;

  /* Sum: '<S116>/Sum2' incorporates:
   *  Constant: '<S116>/d'
   */
  Kensei150401_B.Sum2_j = Kensei150401_B.mmtometer_i + Kensei150401_P.d_Value_a;

  /* Math: '<S116>/Math Function3' */
  Kensei150401_B.MathFunction3_i = Kensei150401_B.Sum2_j * Kensei150401_B.Sum2_j;

  /* Sum: '<S116>/Sum1' */
  Kensei150401_B.Sum1_ht = (Kensei150401_B.MathFunction_g +
    Kensei150401_B.MathFunction1_g) - Kensei150401_B.MathFunction3_i;

  /* Product: '<S116>/Divide1' */
  Kensei150401_B.Divide1_hh = Kensei150401_B.Sum1_ht / Kensei150401_B.Divide2_b0;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Fcn: '<S116>/Epsilon' */
    tmp = Kensei150401_B.Divide_i;
    if (tmp >= 1.0) {
      tmp = 1.0;
    } else {
      if (tmp <= -1.0) {
        tmp = -1.0;
      }
    }

    tmp = acos(tmp);
    Kensei150401_B.Epsilon_g4 = tmp;

    /* End of Fcn: '<S116>/Epsilon' */
  }

  /* Fcn: '<S116>/Fcn1' */
  tmp = Kensei150401_B.Divide1_hh;
  if (tmp >= 1.0) {
    tmp = 1.0;
  } else {
    if (tmp <= -1.0) {
      tmp = -1.0;
    }
  }

  tmp = acos(tmp);
  Kensei150401_B.Fcn1_n = tmp;

  /* End of Fcn: '<S116>/Fcn1' */

  /* Sum: '<S116>/Sum3' */
  Kensei150401_B.Sum3_mb = Kensei150401_B.Fcn1_n - Kensei150401_B.Epsilon_g4;

  /* Gain: '<S116>/rad to degree' */
  Kensei150401_B.radtodegree_j = Kensei150401_P.radtodegree_Gain_k *
    Kensei150401_B.Sum3_mb;

  /* Gain: '<S120>/Integral Gain' */
  Kensei150401_B.IntegralGain_be = Kensei150401_P.IntegralGain_Gain_c *
    Kensei150401_B.Sum1_b;

  /* Sum: '<S120>/SumI2' */
  Kensei150401_B.SumI2_l = Kensei150401_B.Saturation_fk -
    Kensei150401_B.ProportionalGain_a;

  /* Gain: '<S120>/Kb' */
  Kensei150401_B.Kb_p = Kensei150401_P.Kb_Gain_c * Kensei150401_B.SumI2_l;

  /* Sum: '<S120>/SumI1' */
  Kensei150401_B.SumI1_f = Kensei150401_B.IntegralGain_be + Kensei150401_B.Kb_p;

  /* Gain: '<S123>/RL_Volt per mm' */
  Kensei150401_B.RL_Voltpermm = Kensei150401_P.RL_Voltpermm_Gain *
    Kensei150401_B.AnalogFilter_RL_Pos;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Gain: '<S123>/RL_Volt per mm1' incorporates:
     *  Constant: '<S123>/RL ADC min'
     */
    Kensei150401_B.RL_Voltpermm1 = Kensei150401_P.RL_Voltpermm1_Gain *
      Kensei150401_P.RLADCmin_Value;

    /* Gain: '<S123>/RL_Volt per mm2' incorporates:
     *  Constant: '<S123>/RL ADC Center'
     */
    Kensei150401_B.RL_Voltpermm2_i = Kensei150401_P.RL_Voltpermm2_Gain_p *
      Kensei150401_P.RLADCCenter_Value_i;

    /* Math: '<S126>/Math Function' incorporates:
     *  Constant: '<S126>/b'
     */
    Kensei150401_B.MathFunction_l3 = Kensei150401_P.b_Value_d *
      Kensei150401_P.b_Value_d;

    /* Math: '<S126>/Math Function1' incorporates:
     *  Constant: '<S126>/c'
     */
    Kensei150401_B.MathFunction1_e = Kensei150401_P.c_Value_p *
      Kensei150401_P.c_Value_p;

    /* Math: '<S126>/Math Function2' incorporates:
     *  Constant: '<S126>/d'
     */
    Kensei150401_B.MathFunction2_a = Kensei150401_P.d_Value_g *
      Kensei150401_P.d_Value_g;

    /* Sum: '<S126>/Sum' */
    Kensei150401_B.Sum_po = (Kensei150401_B.MathFunction_l3 +
      Kensei150401_B.MathFunction1_e) - Kensei150401_B.MathFunction2_a;

    /* Product: '<S126>/Divide2' incorporates:
     *  Constant: '<S126>/b'
     *  Constant: '<S126>/c'
     *  Constant: '<S126>/constant'
     */
    Kensei150401_B.Divide2_la = Kensei150401_P.constant_Value_c *
      Kensei150401_P.c_Value_p * Kensei150401_P.b_Value_d;

    /* Product: '<S126>/Divide' */
    Kensei150401_B.Divide_l = Kensei150401_B.Sum_po / Kensei150401_B.Divide2_la;
  }

  /* Sum: '<S123>/Sum' */
  Kensei150401_B.Sum_fd = Kensei150401_B.RL_Voltpermm -
    Kensei150401_B.RL_Voltpermm1;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Sum: '<S123>/Sum2' */
    Kensei150401_B.Sum2_i = Kensei150401_B.RL_Voltpermm2_i -
      Kensei150401_B.RL_Voltpermm1;
  }

  /* Sum: '<S123>/Sum3' */
  Kensei150401_B.Sum3_n = Kensei150401_B.Sum_fd - Kensei150401_B.Sum2_i;

  /* Gain: '<S126>/mm to meter' */
  Kensei150401_B.mmtometer_p = Kensei150401_P.mmtometer_Gain_k *
    Kensei150401_B.Sum3_n;

  /* Sum: '<S126>/Sum2' incorporates:
   *  Constant: '<S126>/d'
   */
  Kensei150401_B.Sum2_g = Kensei150401_B.mmtometer_p + Kensei150401_P.d_Value_g;

  /* Math: '<S126>/Math Function3' */
  Kensei150401_B.MathFunction3_h = Kensei150401_B.Sum2_g * Kensei150401_B.Sum2_g;

  /* Sum: '<S126>/Sum1' */
  Kensei150401_B.Sum1_nn = (Kensei150401_B.MathFunction_l3 +
    Kensei150401_B.MathFunction1_e) - Kensei150401_B.MathFunction3_h;

  /* Product: '<S126>/Divide1' */
  Kensei150401_B.Divide1_a = Kensei150401_B.Sum1_nn / Kensei150401_B.Divide2_la;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Fcn: '<S126>/Epsilon' */
    tmp = Kensei150401_B.Divide_l;
    if (tmp >= 1.0) {
      tmp = 1.0;
    } else {
      if (tmp <= -1.0) {
        tmp = -1.0;
      }
    }

    tmp = acos(tmp);
    Kensei150401_B.Epsilon_n = tmp;

    /* End of Fcn: '<S126>/Epsilon' */
  }

  /* Fcn: '<S126>/Fcn1' */
  tmp = Kensei150401_B.Divide1_a;
  if (tmp >= 1.0) {
    tmp = 1.0;
  } else {
    if (tmp <= -1.0) {
      tmp = -1.0;
    }
  }

  tmp = acos(tmp);
  Kensei150401_B.Fcn1_h = tmp;

  /* End of Fcn: '<S126>/Fcn1' */

  /* Sum: '<S126>/Sum3' */
  Kensei150401_B.Sum3_i = Kensei150401_B.Fcn1_h - Kensei150401_B.Epsilon_n;

  /* Gain: '<S126>/rad to degree' */
  Kensei150401_B.radtodegree_p = Kensei150401_P.radtodegree_Gain_kx *
    Kensei150401_B.Sum3_i;

  /* Gain: '<S127>/Integral Gain' */
  Kensei150401_B.IntegralGain_e = Kensei150401_P.IntegralGain_Gain_l *
    Kensei150401_B.Sum1_i0;

  /* Sum: '<S127>/SumI2' */
  Kensei150401_B.SumI2_h = Kensei150401_B.Saturation_m -
    Kensei150401_B.ProportionalGain_p;

  /* Gain: '<S127>/Kb' */
  Kensei150401_B.Kb_j = Kensei150401_P.Kb_Gain_d * Kensei150401_B.SumI2_h;

  /* Sum: '<S127>/SumI1' */
  Kensei150401_B.SumI1_b = Kensei150401_B.IntegralGain_e + Kensei150401_B.Kb_j;

  /* Gain: '<S130>/RR_Volt per mm' */
  Kensei150401_B.RR_Voltpermm = Kensei150401_P.RR_Voltpermm_Gain *
    Kensei150401_B.AnalogFilter_RR_Pos;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Gain: '<S130>/RR_Volt per mm1' incorporates:
     *  Constant: '<S130>/RR ADC min'
     */
    Kensei150401_B.RR_Voltpermm1 = Kensei150401_P.RR_Voltpermm1_Gain *
      Kensei150401_P.RRADCmin_Value;

    /* Gain: '<S130>/RR_Volt per mm2' incorporates:
     *  Constant: '<S130>/RR ADC Center'
     */
    Kensei150401_B.RR_Voltpermm2_l = Kensei150401_P.RR_Voltpermm2_Gain_j *
      Kensei150401_P.RRADCCenter_Value_f;

    /* Math: '<S133>/Math Function' incorporates:
     *  Constant: '<S133>/b'
     */
    Kensei150401_B.MathFunction_p = Kensei150401_P.b_Value_b *
      Kensei150401_P.b_Value_b;

    /* Math: '<S133>/Math Function1' incorporates:
     *  Constant: '<S133>/c'
     */
    Kensei150401_B.MathFunction1_f = Kensei150401_P.c_Value_f *
      Kensei150401_P.c_Value_f;

    /* Math: '<S133>/Math Function2' incorporates:
     *  Constant: '<S133>/d'
     */
    Kensei150401_B.MathFunction2_d = Kensei150401_P.d_Value_a2 *
      Kensei150401_P.d_Value_a2;

    /* Sum: '<S133>/Sum' */
    Kensei150401_B.Sum_dd = (Kensei150401_B.MathFunction_p +
      Kensei150401_B.MathFunction1_f) - Kensei150401_B.MathFunction2_d;

    /* Product: '<S133>/Divide2' incorporates:
     *  Constant: '<S133>/b'
     *  Constant: '<S133>/c'
     *  Constant: '<S133>/constant'
     */
    Kensei150401_B.Divide2_dp = Kensei150401_P.constant_Value_g *
      Kensei150401_P.c_Value_f * Kensei150401_P.b_Value_b;

    /* Product: '<S133>/Divide' */
    Kensei150401_B.Divide_lr = Kensei150401_B.Sum_dd / Kensei150401_B.Divide2_dp;
  }

  /* Sum: '<S130>/Sum' */
  Kensei150401_B.Sum_ng = Kensei150401_B.RR_Voltpermm -
    Kensei150401_B.RR_Voltpermm1;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Sum: '<S130>/Sum2' */
    Kensei150401_B.Sum2_f = Kensei150401_B.RR_Voltpermm2_l -
      Kensei150401_B.RR_Voltpermm1;
  }

  /* Sum: '<S130>/Sum3' */
  Kensei150401_B.Sum3_ie = Kensei150401_B.Sum_ng - Kensei150401_B.Sum2_f;

  /* Gain: '<S133>/mm to meter' */
  Kensei150401_B.mmtometer_b = Kensei150401_P.mmtometer_Gain_a *
    Kensei150401_B.Sum3_ie;

  /* Sum: '<S133>/Sum2' incorporates:
   *  Constant: '<S133>/d'
   */
  Kensei150401_B.Sum2_a = Kensei150401_B.mmtometer_b + Kensei150401_P.d_Value_a2;

  /* Math: '<S133>/Math Function3' */
  Kensei150401_B.MathFunction3_id = Kensei150401_B.Sum2_a *
    Kensei150401_B.Sum2_a;

  /* Sum: '<S133>/Sum1' */
  Kensei150401_B.Sum1_ow = (Kensei150401_B.MathFunction_p +
    Kensei150401_B.MathFunction1_f) - Kensei150401_B.MathFunction3_id;

  /* Product: '<S133>/Divide1' */
  Kensei150401_B.Divide1_j = Kensei150401_B.Sum1_ow / Kensei150401_B.Divide2_dp;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Fcn: '<S133>/Epsilon' */
    tmp = Kensei150401_B.Divide_lr;
    if (tmp >= 1.0) {
      tmp = 1.0;
    } else {
      if (tmp <= -1.0) {
        tmp = -1.0;
      }
    }

    tmp = acos(tmp);
    Kensei150401_B.Epsilon_oh = tmp;

    /* End of Fcn: '<S133>/Epsilon' */
  }

  /* Fcn: '<S133>/Fcn1' */
  tmp = Kensei150401_B.Divide1_j;
  if (tmp >= 1.0) {
    tmp = 1.0;
  } else {
    if (tmp <= -1.0) {
      tmp = -1.0;
    }
  }

  tmp = acos(tmp);
  Kensei150401_B.Fcn1_c = tmp;

  /* End of Fcn: '<S133>/Fcn1' */

  /* Sum: '<S133>/Sum3' */
  Kensei150401_B.Sum3_g = Kensei150401_B.Fcn1_c - Kensei150401_B.Epsilon_oh;

  /* Gain: '<S133>/rad to degree' */
  Kensei150401_B.radtodegree_n = Kensei150401_P.radtodegree_Gain_f *
    Kensei150401_B.Sum3_g;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Constant: '<S7>/Stop PWM 1..1' */
    Kensei150401_B.StopPWM11 = Kensei150401_P.StopPWM11_Value;

    /* Gain: '<S8>/Tyre radius3' */
    Kensei150401_B.Tyreradius3 = Kensei150401_P.Tyreradius3_Gain * 0.0;

    /* Sum: '<S8>/Add1' */
    Kensei150401_B.Add1 = Kensei150401_B.Tyreradius3 - 0.0;

    /* Fcn: '<S8>/u(2) // u(1)L' */
    Kensei150401_B.slip = Kensei150401_B.Add1 / ((real_T)
      (Kensei150401_B.Tyreradius3 == 0.0) * 2.2204460492503131e-16 +
      Kensei150401_B.Tyreradius3);

    /* Saturate: '<S8>/-1 to 1' */
    tmp = Kensei150401_B.slip;
    u = Kensei150401_P.uto1_LowerSat;
    u_0 = Kensei150401_P.uto1_UpperSat;
    if (tmp >= u_0) {
      Kensei150401_B.uto1 = u_0;
    } else if (tmp <= u) {
      Kensei150401_B.uto1 = u;
    } else {
      Kensei150401_B.uto1 = tmp;
    }

    /* End of Saturate: '<S8>/-1 to 1' */

    /* Gain: '<S8>/Tyre radius' */
    Kensei150401_B.ms_bc = Kensei150401_P.Tyreradius_Gain_i * 0.0;

    /* Sum: '<S8>/Add2' */
    Kensei150401_B.Add2 = Kensei150401_B.ms_bc - 0.0;

    /* Fcn: '<S8>/u(2) // u(1)R' */
    Kensei150401_B.u2u1R = Kensei150401_B.Add2 / ((real_T)(Kensei150401_B.ms_bc ==
      0.0) * 2.2204460492503131e-16 + Kensei150401_B.ms_bc);
  }

  /* Gain: '<S146>/Integral Gain' */
  Kensei150401_B.IntegralGain_g = Kensei150401_P.IntegralGain_Gain_p *
    Kensei150401_B.Sum_bv;
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Switch: '<S8>/Switch4' */
    if (Kensei150401_B.steerprop >= Kensei150401_P.Switch4_Threshold_n) {
      /* Gain: '<S8>/to percent1' */
      Kensei150401_B.topercent1 = Kensei150401_P.topercent1_Gain *
        Kensei150401_B.PedalLimitzpt2V1;

      /* Rounding: '<S8>/Rounding Function1' */
      Kensei150401_B.RoundingFunction1_g = rt_roundd_snf
        (Kensei150401_B.topercent1);

      /* Saturate: '<S8>/Pedal Limit 100%1' */
      tmp = Kensei150401_B.RoundingFunction1_g;
      u = Kensei150401_P.PedalLimit1001_LowerSat;
      u_0 = Kensei150401_P.PedalLimit1001_UpperSat;
      if (tmp >= u_0) {
        Kensei150401_B.PedalLimit1001 = u_0;
      } else if (tmp <= u) {
        Kensei150401_B.PedalLimit1001 = u;
      } else {
        Kensei150401_B.PedalLimit1001 = tmp;
      }

      /* End of Saturate: '<S8>/Pedal Limit 100%1' */
      Kensei150401_B.Switch4 = Kensei150401_B.PedalLimit1001;
    } else {
      Kensei150401_B.Switch4 = Kensei150401_B.PedalLimit100;
    }

    /* End of Switch: '<S8>/Switch4' */
  }
}

/* Model update function for TID0 */
void Kensei150401_update0(void)        /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Update for UnitDelay: '<S65>/Unit Delay' */
    Kensei150401_DWork.UnitDelay_DSTATE = Kensei150401_B.Sum_i;
  }

  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    /* Update for Memory: '<S58>/Mem1' */
    Kensei150401_DWork.Mem1_PreviousInput = Kensei150401_B.OR;

    /* Update for Memory: '<S58>/Mem2' */
    Kensei150401_DWork.Mem2_PreviousInput = Kensei150401_B.Mem1;

    /* Update for Memory: '<S58>/Mem3' */
    Kensei150401_DWork.Mem3_PreviousInput = Kensei150401_B.Mem2;

    /* Update for Memory: '<S58>/Mem4' */
    Kensei150401_DWork.Mem4_PreviousInput = Kensei150401_B.Mem3;

    /* Update for Memory: '<S58>/Mem5' */
    Kensei150401_DWork.Mem5_PreviousInput = Kensei150401_B.Mem4;

    /* Update for Memory: '<S59>/Mem1' */
    Kensei150401_DWork.Mem1_PreviousInput_m = Kensei150401_B.OR_n;

    /* Update for Memory: '<S59>/Mem2' */
    Kensei150401_DWork.Mem2_PreviousInput_d = Kensei150401_B.Mem1_l;

    /* Update for Memory: '<S59>/Mem3' */
    Kensei150401_DWork.Mem3_PreviousInput_l = Kensei150401_B.Mem2_h;

    /* Update for Memory: '<S59>/Mem4' */
    Kensei150401_DWork.Mem4_PreviousInput_j = Kensei150401_B.Mem3_f;

    /* Update for Memory: '<S59>/Mem5' */
    Kensei150401_DWork.Mem5_PreviousInput_g = Kensei150401_B.Mem4_e;

    /* Update for Memory: '<S62>/Mem1' */
    Kensei150401_DWork.Mem1_PreviousInput_p = Kensei150401_B.OR_a;

    /* Update for Memory: '<S62>/Mem2' */
    Kensei150401_DWork.Mem2_PreviousInput_m = Kensei150401_B.Mem1_p;

    /* Update for Memory: '<S62>/Mem3' */
    Kensei150401_DWork.Mem3_PreviousInput_f = Kensei150401_B.Mem2_d;

    /* Update for Memory: '<S62>/Mem4' */
    Kensei150401_DWork.Mem4_PreviousInput_b = Kensei150401_B.Mem3_g;

    /* Update for Memory: '<S63>/Mem1' */
    Kensei150401_DWork.Mem1_PreviousInput_pu = Kensei150401_B.OR_a5;

    /* Update for Memory: '<S63>/Mem2' */
    Kensei150401_DWork.Mem2_PreviousInput_o = Kensei150401_B.Mem1_i;

    /* Update for Memory: '<S63>/Mem3' */
    Kensei150401_DWork.Mem3_PreviousInput_fn = Kensei150401_B.Mem2_k;

    /* Update for Memory: '<S63>/Mem4' */
    Kensei150401_DWork.Mem4_PreviousInput_e = Kensei150401_B.Mem3_b;
  }

  if (rtmIsMajorTimeStep(Kensei150401_M)) {
    rt_ertODEUpdateContinuousStates(&Kensei150401_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Kensei150401_M->Timing.clockTick0)) {
    ++Kensei150401_M->Timing.clockTickH0;
  }

  Kensei150401_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Kensei150401_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Kensei150401_M->Timing.clockTick1)) {
    ++Kensei150401_M->Timing.clockTickH1;
  }

  Kensei150401_M->Timing.t[1] = Kensei150401_M->Timing.clockTick1 *
    Kensei150401_M->Timing.stepSize1 + Kensei150401_M->Timing.clockTickH1 *
    Kensei150401_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void Kensei150401_derivatives(void)
{
  StateDerivatives_Kensei150401 *_rtXdot;
  _rtXdot = ((StateDerivatives_Kensei150401 *) Kensei150401_M->ModelData.derivs);

  /* Derivatives for StateSpace: '<S85>/Analog Filter_FR_Pos' */
  {
    ((StateDerivatives_Kensei150401 *) Kensei150401_M->ModelData.derivs)
      ->AnalogFilter_FR_Pos_CSTATE = (Kensei150401_P.AnalogFilter_FR_Pos_A)*
      Kensei150401_X.AnalogFilter_FR_Pos_CSTATE;
    ((StateDerivatives_Kensei150401 *) Kensei150401_M->ModelData.derivs)
      ->AnalogFilter_FR_Pos_CSTATE += Kensei150401_P.AnalogFilter_FR_Pos_B*
      Kensei150401_B.inADC5;
  }

  /* Derivatives for Integrator: '<S107>/Integrator' */
  _rtXdot->Integrator_CSTATE = Kensei150401_B.SumI1_d;

  /* Derivatives for Integrator: '<S107>/Filter' */
  _rtXdot->Filter_CSTATE = Kensei150401_B.FilterCoefficient;

  /* Derivatives for StateSpace: '<S84>/Analog Filter_FL_Pos' */
  {
    ((StateDerivatives_Kensei150401 *) Kensei150401_M->ModelData.derivs)
      ->AnalogFilter_FL_Pos_CSTATE = (Kensei150401_P.AnalogFilter_FL_Pos_A)*
      Kensei150401_X.AnalogFilter_FL_Pos_CSTATE;
    ((StateDerivatives_Kensei150401 *) Kensei150401_M->ModelData.derivs)
      ->AnalogFilter_FL_Pos_CSTATE += Kensei150401_P.AnalogFilter_FL_Pos_B*
      Kensei150401_B.inADC6;
  }

  /* Derivatives for Integrator: '<S97>/Integrator' */
  _rtXdot->Integrator_CSTATE_d = Kensei150401_B.SumI1;

  /* Derivatives for Integrator: '<S97>/Filter' */
  _rtXdot->Filter_CSTATE_f = Kensei150401_B.FilterCoefficient_n;

  /* Derivatives for StateSpace: '<S89>/Analog Filter_RR_Pos' */
  {
    ((StateDerivatives_Kensei150401 *) Kensei150401_M->ModelData.derivs)
      ->AnalogFilter_RR_Pos_CSTATE = (Kensei150401_P.AnalogFilter_RR_Pos_A)*
      Kensei150401_X.AnalogFilter_RR_Pos_CSTATE;
    ((StateDerivatives_Kensei150401 *) Kensei150401_M->ModelData.derivs)
      ->AnalogFilter_RR_Pos_CSTATE += Kensei150401_P.AnalogFilter_RR_Pos_B*
      Kensei150401_B.inADC7;
  }

  /* Derivatives for Integrator: '<S127>/Integrator' */
  _rtXdot->Integrator_CSTATE_p = Kensei150401_B.SumI1_b;

  /* Derivatives for Integrator: '<S127>/Filter' */
  _rtXdot->Filter_CSTATE_i = Kensei150401_B.FilterCoefficient_i;

  /* Derivatives for StateSpace: '<S88>/Analog Filter_RL_Pos' */
  {
    ((StateDerivatives_Kensei150401 *) Kensei150401_M->ModelData.derivs)
      ->AnalogFilter_RL_Pos_CSTATE = (Kensei150401_P.AnalogFilter_RL_Pos_A)*
      Kensei150401_X.AnalogFilter_RL_Pos_CSTATE;
    ((StateDerivatives_Kensei150401 *) Kensei150401_M->ModelData.derivs)
      ->AnalogFilter_RL_Pos_CSTATE += Kensei150401_P.AnalogFilter_RL_Pos_B*
      Kensei150401_B.inADC8;
  }

  /* Derivatives for Integrator: '<S120>/Integrator' */
  _rtXdot->Integrator_CSTATE_c = Kensei150401_B.SumI1_f;

  /* Derivatives for Integrator: '<S120>/Filter' */
  _rtXdot->Filter_CSTATE_c = Kensei150401_B.FilterCoefficient_o;

  /* Derivatives for Integrator: '<S146>/Integrator' */
  _rtXdot->Integrator_CSTATE_l = Kensei150401_B.IntegralGain_g;

  /* Derivatives for StateSpace: '<S44>/Analog Filter_FR_Pos' */
  {
    ((StateDerivatives_Kensei150401 *) Kensei150401_M->ModelData.derivs)
      ->AnalogFilter_FR_Pos_CSTATE_h = (Kensei150401_P.AnalogFilter_FR_Pos_A_e)*
      Kensei150401_X.AnalogFilter_FR_Pos_CSTATE_h;
    ((StateDerivatives_Kensei150401 *) Kensei150401_M->ModelData.derivs)
      ->AnalogFilter_FR_Pos_CSTATE_h += Kensei150401_P.AnalogFilter_FR_Pos_B_f*
      Kensei150401_B.inADC3;
  }
}

/* Model output function for TID2 */
void Kensei150401_output2(void)        /* Sample time: [0.05s, 0.0s] */
{
  /* S-Function (rti_commonblock): '<S54>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN Status block */
  /* ... read status variables of the CAN microcontroller */
  {
    UInt32 loop_counter, memory, j;
    for (j=0;j<=2;j++) {
      rtican_type1_tq_error[0][6] = can_tp1_service_read
        (can_type1_service_M1_C1[j]);
      loop_counter = 0;
      while ((rtican_type1_tq_error[0][6] = can_tp1_service_request
              (can_type1_service_M1_C1[j]))== DSMCOM_BUFFER_OVERFLOW) {
        loop_counter++;
        if (loop_counter > MAX_LOOP) {
          memory = rtican_type1_error_level;
          rtican_type1_error_level = 1;
          rtican_type1_tq_err_sig(0, 6);
          rtican_type1_error_level = memory;
          break;
        }
      }

      if (j==CANTP1_M1_C1_RXLost) {
        rtican_type1_tq_error[0][6] = can_tp1_service_read
          (can_type1_service_M1_C1[CANTP1_M1_C1_DataLost]);
        loop_counter = 0;
        while ((rtican_type1_tq_error[0][6] = can_tp1_service_request
                (can_type1_service_M1_C1[CANTP1_M1_C1_DataLost]))==
               DSMCOM_BUFFER_OVERFLOW) {
          loop_counter++;
          if (loop_counter > MAX_LOOP) {
            memory = rtican_type1_error_level;
            rtican_type1_error_level = 1;
            rtican_type1_tq_err_sig(0, 6);
            rtican_type1_error_level = memory;
            break;
          }
        }
      }
    }

    Kensei150401_B.SFunction1_o1_p = (UInt32)
      can_type1_service_M1_C1[CANTP1_M1_C1_Status]->data0;
    Kensei150401_B.SFunction1_o2_h = (UInt32)
      (can_type1_service_M1_C1[CANTP1_M1_C1_RXLost]->data0 +
       can_type1_service_M1_C1[CANTP1_M1_C1_DataLost]->data0);
    Kensei150401_B.SFunction1_o3_c = (UInt32)
      can_type1_service_M1_C1[CANTP1_M1_C1_RXOK]->data0;
  }

  /* DataTypeConversion: '<S50>/Data Type  Conversion' */
  Kensei150401_B.DataTypeConversion = (real_T)Kensei150401_B.SFunction1_o1_p;

  /* RelationalOperator: '<S50>/Bus Off' incorporates:
   *  Constant: '<S50>/Bus Off value'
   */
  Kensei150401_B.BusOff = (Kensei150401_B.DataTypeConversion ==
    Kensei150401_P.BusOffvalue_Value);

  /* DataTypeConversion: '<S50>/Data Type  Conversion1' */
  Kensei150401_B.DataTypeConversion1 = (real_T)Kensei150401_B.SFunction1_o2_h;

  /* RelationalOperator: '<S50>/RX lost limit reached' incorporates:
   *  Constant: '<S50>/RX lost limit'
   */
  Kensei150401_B.RXlostlimitreached = (Kensei150401_B.DataTypeConversion1 >
    Kensei150401_P.RXlostlimit_Value);

  /* Logic: '<S50>/OR' */
  Kensei150401_B.OR_f = (Kensei150401_B.BusOff ||
    Kensei150401_B.RXlostlimitreached);

  /* S-Function (rti_commonblock): '<S55>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN Status block */
  /* ... read status variables of the CAN microcontroller */
  {
    UInt32 loop_counter, memory, j;
    for (j=0;j<=1;j++) {
      rtican_type1_tq_error[0][6] = can_tp1_service_read
        (can_type1_service_M1_C2[j]);
      loop_counter = 0;
      while ((rtican_type1_tq_error[0][6] = can_tp1_service_request
              (can_type1_service_M1_C2[j]))== DSMCOM_BUFFER_OVERFLOW) {
        loop_counter++;
        if (loop_counter > MAX_LOOP) {
          memory = rtican_type1_error_level;
          rtican_type1_error_level = 1;
          rtican_type1_tq_err_sig(0, 6);
          rtican_type1_error_level = memory;
          break;
        }
      }
    }

    Kensei150401_B.SFunction1_o1_l = (UInt32)
      can_type1_service_M1_C2[CANTP1_M1_C2_Status]->data0;
    Kensei150401_B.SFunction1_o2_p = (UInt32)
      can_type1_service_M1_C2[CANTP1_M1_C2_AckErrors]->data0;
  }

  /* DataTypeConversion: '<S51>/Data Type  Conversion1' */
  Kensei150401_B.DataTypeConversion1_m = (real_T)Kensei150401_B.SFunction1_o2_p;

  /* RelationalOperator: '<S51>/Acknowdledge error limit reached' incorporates:
   *  Constant: '<S51>/Acknowdledge error limit'
   */
  Kensei150401_B.Acknowdledgeerrorlimitreached =
    (Kensei150401_B.DataTypeConversion1_m >
     Kensei150401_P.Acknowdledgeerrorlimit_Value);

  /* DataTypeConversion: '<S51>/Data Type  Conversion' */
  Kensei150401_B.DataTypeConversion_h = (real_T)Kensei150401_B.SFunction1_o1_l;

  /* RelationalOperator: '<S51>/Bus Off' incorporates:
   *  Constant: '<S51>/Bus Off value'
   */
  Kensei150401_B.BusOff_j = (Kensei150401_B.DataTypeConversion_h ==
    Kensei150401_P.BusOffvalue_Value_i);

  /* Logic: '<S51>/OR' */
  Kensei150401_B.OR_j = (Kensei150401_B.BusOff_j ||
    Kensei150401_B.Acknowdledgeerrorlimitreached);
}

/* Model update function for TID2 */
void Kensei150401_update2(void)        /* Sample time: [0.05s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Kensei150401_M->Timing.clockTick2)) {
    ++Kensei150401_M->Timing.clockTickH2;
  }

  Kensei150401_M->Timing.t[2] = Kensei150401_M->Timing.clockTick2 *
    Kensei150401_M->Timing.stepSize2 + Kensei150401_M->Timing.clockTickH2 *
    Kensei150401_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void Kensei150401_output(int_T tid)
{
  switch (tid) {
   case 0 :
    Kensei150401_output0();
    break;

   case 2 :
    Kensei150401_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void Kensei150401_update(int_T tid)
{
  switch (tid) {
   case 0 :
    Kensei150401_update0();
    break;

   case 2 :
    Kensei150401_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Kensei150401_initialize(void)
{
  /* Start for RateTransition: '<S46>/Rate Transition' */
  Kensei150401_B.RateTransition = Kensei150401_P.RateTransition_X0;

  /* Start for S-Function (rti_commonblock): '<S67>/S-Function1' incorporates:
   *  Start for SubSystem: '<S46>/fl encoder interrupt function'
   */
  flencoderinterruptfunctio_Start();

  /* Start for RateTransition: '<S46>/Rate Transition4' */
  Kensei150401_B.RateTransition4 = Kensei150401_P.RateTransition4_X0;

  /* Start for RateTransition: '<S46>/Rate Transition1' */
  Kensei150401_B.RateTransition1 = Kensei150401_P.RateTransition1_X0;

  /* Start for RateTransition: '<S46>/Rate Transition3' */
  Kensei150401_B.RateTransition3 = Kensei150401_P.RateTransition3_X0;

  /* Start for DiscretePulseGenerator: '<S48>/Pulse Generator' */
  Kensei150401_DWork.clockTickCounter = 0;

  /* InitializeConditions for UnitDelay: '<S65>/Unit Delay' */
  Kensei150401_DWork.UnitDelay_DSTATE =
    Kensei150401_P.UnitDelay_InitialCondition;

  /* InitializeConditions for RateTransition: '<S46>/Rate Transition' */
  Kensei150401_DWork.RateTransition_Buffer0 = Kensei150401_P.RateTransition_X0;
  Kensei150401_DWork.RateTransition_write_buf = -1;
  Kensei150401_DWork.RateTransition_read_buf = -1;

  /* InitializeConditions for RateTransition: '<S46>/Rate Transition4' */
  Kensei150401_DWork.RateTransition4_Buffer0 = Kensei150401_P.RateTransition4_X0;
  Kensei150401_DWork.RateTransition4_write_buf = -1;
  Kensei150401_DWork.RateTransition4_read_buf = -1;

  /* InitializeConditions for S-Function (sdspcount2): '<S46>/Counter' */
  Kensei150401_DWork.Counter_ClkEphState = 5U;
  Kensei150401_DWork.Counter_RstEphState = 5U;
  Kensei150401_DWork.Counter_Count = Kensei150401_P.Counter_InitialCount;

  /* InitializeConditions for RateTransition: '<S46>/Rate Transition1' */
  Kensei150401_DWork.RateTransition1_Buffer0 = Kensei150401_P.RateTransition1_X0;
  Kensei150401_DWork.RateTransition1_write_buf = -1;
  Kensei150401_DWork.RateTransition1_read_buf = -1;

  /* InitializeConditions for Chart: '<S49>/Chart (Propulsion Modes)' */
  Kensei150401_DWork.is_active_gearmode = 0U;
  Kensei150401_DWork.is_gearmode = Kensei150401_IN_NO_ACTIVE_CHILD;
  Kensei150401_DWork.is_Forward = Kensei150401_IN_NO_ACTIVE_CHILD;
  Kensei150401_DWork.is_Parking = Kensei150401_IN_NO_ACTIVE_CHILD;
  Kensei150401_DWork.is_Reverse = Kensei150401_IN_NO_ACTIVE_CHILD;
  Kensei150401_DWork.is_active_fromzptwarn = 0U;
  Kensei150401_DWork.is_fromzptwarn = Kensei150401_IN_NO_ACTIVE_CHILD;
  Kensei150401_DWork.is_active_throt = 0U;
  Kensei150401_DWork.is_throt = Kensei150401_IN_NO_ACTIVE_CHILD;
  Kensei150401_DWork.is_enabled = Kensei150401_IN_NO_ACTIVE_CHILD;
  Kensei150401_DWork.is_fromZPT_warning = Kensei150401_IN_NO_ACTIVE_CHILD;
  Kensei150401_DWork.is_toZPT_warning = Kensei150401_IN_NO_ACTIVE_CHILD;
  Kensei150401_DWork.is_wait_angle = Kensei150401_IN_NO_ACTIVE_CHILD;
  Kensei150401_DWork.is_active_response = 0U;
  Kensei150401_DWork.is_response = Kensei150401_IN_NO_ACTIVE_CHILD;
  Kensei150401_DWork.is_active_c3_Kensei150401 = 0U;
  Kensei150401_DWork.presentTicks = 0U;
  Kensei150401_DWork.elapsedTicks = 0U;
  Kensei150401_DWork.previousTicks = 0U;

  /* InitializeConditions for Chart: '<S49>/Chart (AWS FWS)' */
  Kensei150401_DWork.is_active_c1_Kensei150401 = 0U;
  Kensei150401_DWork.is_c1_Kensei150401 = Kensei150401_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for StateSpace: '<S85>/Analog Filter_FR_Pos' */
  Kensei150401_X.AnalogFilter_FR_Pos_CSTATE =
    Kensei150401_P.AnalogFilter_FR_Pos_X0;

  /* InitializeConditions for Integrator: '<S107>/Integrator' */
  Kensei150401_X.Integrator_CSTATE = Kensei150401_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S107>/Filter' */
  Kensei150401_X.Filter_CSTATE = Kensei150401_P.Filter_IC;

  /* InitializeConditions for StateSpace: '<S84>/Analog Filter_FL_Pos' */
  Kensei150401_X.AnalogFilter_FL_Pos_CSTATE =
    Kensei150401_P.AnalogFilter_FL_Pos_X0;

  /* InitializeConditions for Integrator: '<S97>/Integrator' */
  Kensei150401_X.Integrator_CSTATE_d = Kensei150401_P.Integrator_IC_k;

  /* InitializeConditions for Integrator: '<S97>/Filter' */
  Kensei150401_X.Filter_CSTATE_f = Kensei150401_P.Filter_IC_n;

  /* InitializeConditions for StateSpace: '<S89>/Analog Filter_RR_Pos' */
  Kensei150401_X.AnalogFilter_RR_Pos_CSTATE =
    Kensei150401_P.AnalogFilter_RR_Pos_X0;

  /* InitializeConditions for Integrator: '<S127>/Integrator' */
  Kensei150401_X.Integrator_CSTATE_p = Kensei150401_P.Integrator_IC_g;

  /* InitializeConditions for Integrator: '<S127>/Filter' */
  Kensei150401_X.Filter_CSTATE_i = Kensei150401_P.Filter_IC_i;

  /* InitializeConditions for StateSpace: '<S88>/Analog Filter_RL_Pos' */
  Kensei150401_X.AnalogFilter_RL_Pos_CSTATE =
    Kensei150401_P.AnalogFilter_RL_Pos_X0;

  /* InitializeConditions for Integrator: '<S120>/Integrator' */
  Kensei150401_X.Integrator_CSTATE_c = Kensei150401_P.Integrator_IC_gk;

  /* InitializeConditions for Integrator: '<S120>/Filter' */
  Kensei150401_X.Filter_CSTATE_c = Kensei150401_P.Filter_IC_a;

  /* InitializeConditions for Integrator: '<S146>/Integrator' */
  Kensei150401_X.Integrator_CSTATE_l = Kensei150401_P.Integrator_IC_j;

  /* InitializeConditions for StateSpace: '<S44>/Analog Filter_FR_Pos' */
  Kensei150401_X.AnalogFilter_FR_Pos_CSTATE_h =
    Kensei150401_P.AnalogFilter_FR_Pos_X0_d;

  /* InitializeConditions for Memory: '<S58>/Mem1' */
  Kensei150401_DWork.Mem1_PreviousInput = Kensei150401_P.Mem1_X0;

  /* InitializeConditions for Memory: '<S58>/Mem2' */
  Kensei150401_DWork.Mem2_PreviousInput = Kensei150401_P.Mem2_X0;

  /* InitializeConditions for Memory: '<S58>/Mem3' */
  Kensei150401_DWork.Mem3_PreviousInput = Kensei150401_P.Mem3_X0;

  /* InitializeConditions for Memory: '<S58>/Mem4' */
  Kensei150401_DWork.Mem4_PreviousInput = Kensei150401_P.Mem4_X0;

  /* InitializeConditions for Memory: '<S58>/Mem5' */
  Kensei150401_DWork.Mem5_PreviousInput = Kensei150401_P.Mem5_X0;

  /* InitializeConditions for Memory: '<S59>/Mem1' */
  Kensei150401_DWork.Mem1_PreviousInput_m = Kensei150401_P.Mem1_X0_g;

  /* InitializeConditions for Memory: '<S59>/Mem2' */
  Kensei150401_DWork.Mem2_PreviousInput_d = Kensei150401_P.Mem2_X0_a;

  /* InitializeConditions for Memory: '<S59>/Mem3' */
  Kensei150401_DWork.Mem3_PreviousInput_l = Kensei150401_P.Mem3_X0_i;

  /* InitializeConditions for Memory: '<S59>/Mem4' */
  Kensei150401_DWork.Mem4_PreviousInput_j = Kensei150401_P.Mem4_X0_n;

  /* InitializeConditions for Memory: '<S59>/Mem5' */
  Kensei150401_DWork.Mem5_PreviousInput_g = Kensei150401_P.Mem5_X0_f;

  /* InitializeConditions for Memory: '<S62>/Mem1' */
  Kensei150401_DWork.Mem1_PreviousInput_p = Kensei150401_P.Mem1_X0_m;

  /* InitializeConditions for Memory: '<S62>/Mem2' */
  Kensei150401_DWork.Mem2_PreviousInput_m = Kensei150401_P.Mem2_X0_m;

  /* InitializeConditions for Memory: '<S62>/Mem3' */
  Kensei150401_DWork.Mem3_PreviousInput_f = Kensei150401_P.Mem3_X0_f;

  /* InitializeConditions for Memory: '<S62>/Mem4' */
  Kensei150401_DWork.Mem4_PreviousInput_b = Kensei150401_P.Mem4_X0_l;

  /* InitializeConditions for Memory: '<S63>/Mem1' */
  Kensei150401_DWork.Mem1_PreviousInput_pu = Kensei150401_P.Mem1_X0_e;

  /* InitializeConditions for Memory: '<S63>/Mem2' */
  Kensei150401_DWork.Mem2_PreviousInput_o = Kensei150401_P.Mem2_X0_k;

  /* InitializeConditions for Memory: '<S63>/Mem3' */
  Kensei150401_DWork.Mem3_PreviousInput_fn = Kensei150401_P.Mem3_X0_e;

  /* InitializeConditions for Memory: '<S63>/Mem4' */
  Kensei150401_DWork.Mem4_PreviousInput_e = Kensei150401_P.Mem4_X0_m;

  /* InitializeConditions for RateTransition: '<S46>/Rate Transition3' */
  Kensei150401_DWork.RateTransition3_Buffer0 = Kensei150401_P.RateTransition3_X0;
  Kensei150401_DWork.RateTransition3_write_buf = -1;
  Kensei150401_DWork.RateTransition3_read_buf = -1;

  /* Enable for Chart: '<S49>/Chart (Propulsion Modes)' */
  Kensei150401_DWork.presentTicks = Kensei150401_M->Timing.clockTick1;
  Kensei150401_DWork.previousTicks = Kensei150401_DWork.presentTicks;
}

/* Model terminate function */
void Kensei150401_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S41>/S-Function1' */

  /* disable digital output channel 3 on port 1 *
   * (set to high-impedance), when the simulation terminates */
  dio_tp4_pwm_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH3,
                   DIO_TP4_LS_DISABLE, DIO_TP4_HS_DISABLE, DIO_TP4_TIMING_RANGE1,
                   DIO_TP4_PWM);

  /* Terminate for S-Function (rti_commonblock): '<S42>/S-Function1' */

  /* disable digital output channel 4 on port 1 *
   * (set to high-impedance), when the simulation terminates */
  dio_tp4_pwm_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH4,
                   DIO_TP4_LS_DISABLE, DIO_TP4_HS_DISABLE, DIO_TP4_TIMING_RANGE1,
                   DIO_TP4_PWM);

  /* Terminate for S-Function (rti_commonblock): '<S31>/S-Function1' */

  /* write termination value of DAC for relevant output channels synchronous*/
  /*write to buffer*/
  aio_tp1_dac_buffer_write(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CH1, 0.0);
  aio_tp1_dac_buffer_write(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CH2, 0.0);
  aio_tp1_dac_buffer_write(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CH3, 0.0);
  aio_tp1_dac_buffer_write(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CH4, 0.0);

  /*release buffer*/
  aio_tp1_dac_buffer_release(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CTRL_CH1|
    AIO_TP1_DAC_CTRL_CH2|AIO_TP1_DAC_CTRL_CH3|AIO_TP1_DAC_CTRL_CH4);

  /* Terminate for S-Function (rti_commonblock): '<S56>/S-Function1' */

  /* dSPACE RTICAN RX Message Block: "RX Message Controller 1" Id:115 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][2] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_RX_STD_0X73])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S57>/S-Function1' */

  /* dSPACE RTICAN RX Message Block: "RX Message Controller 1" Id:116 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][3] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X74])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S61>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "TX Message Controller 2" Id:107 */
  {
    /* ... Send termination message */
    {
      UInt32 CAN_Msg[8] = { 0x37, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      while ((rtican_type1_tq_error[0][0] = can_tp1_msg_send
              (can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X6B], 1, &(CAN_Msg[0]), 0.0))
             == DSMCOM_BUFFER_OVERFLOW) ;
    }

    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][0] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X6B])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S60>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "TX Message Controller 2" Id:108 */
  {
    /* ... Send termination message */
    {
      UInt32 CAN_Msg[8] = { 0x37, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      while ((rtican_type1_tq_error[0][1] = can_tp1_msg_send
              (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X6C], 1, &(CAN_Msg[0]), 0.0))
             == DSMCOM_BUFFER_OVERFLOW) ;
    }

    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][1] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X6C])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S72>/S-Function1' */
  if (State_NVData_Odometer == 2) {
    /* dSPACE I/O Board DSFLASH -- save in temp_buffer Odometer             */
    /*--------------------------------------------------------------------------*/
    char NameNvVar[DSNVDATA_ENTRY_IDENTIFIER_LENGTH+1] = "Odometer";

    /* write updated data in flash NV area */
    /*-------------------------------------*/
    dsnvdata_write(&NameNvVar[0], (void*)(&Kensei150401_B.DataTypeConversion3),
                   1 * sizeof(real_T));
  } else {
    char NameNvVar[DSNVDATA_ENTRY_IDENTIFIER_LENGTH+1] = "Odometer";

    /* write default values from init phase in flash NV area */
    /*-------------------------------------------------------*/
    dsnvdata_write(&NameNvVar[0], (void*)(Addr_Odometer), 1 * sizeof(real_T));
  }

  /* Terminate for S-Function (rti_commonblock): '<S74>/S-Function1' */

  /* dSPACE I/O Board 1401stdasertp1 #1 Unit:GENSER Group:SETUP */
  dsser_disable(rti1401stdasertp1_B1_Ser[0]);
  dsser_fifo_reset(rti1401stdasertp1_B1_Ser[0]);

  /* user code (Terminate function Trailer) */

  /* dSPACE I/O Board DSFLASH -- NVDATASTORE        */
  /* transfer data from temp_buffer in flash mmemory*/
  dsnvdata_flashtransfer();
  if (Kensei150401_B.DataTypeConversion1_e == 1) {
    ds1401_power_hold_off();           /* MABX power down */
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Kensei150401_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Kensei150401_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Kensei150401_initialize();
}

void MdlTerminate(void)
{
  Kensei150401_terminate();
}

RT_MODEL_Kensei150401 *Kensei150401(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Kensei150401_M, 0,
                sizeof(RT_MODEL_Kensei150401));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Kensei150401_M->solverInfo,
                          &Kensei150401_M->Timing.simTimeStep);
    rtsiSetTPtr(&Kensei150401_M->solverInfo, &rtmGetTPtr(Kensei150401_M));
    rtsiSetStepSizePtr(&Kensei150401_M->solverInfo,
                       &Kensei150401_M->Timing.stepSize0);
    rtsiSetdXPtr(&Kensei150401_M->solverInfo, &Kensei150401_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Kensei150401_M->solverInfo,
                         &Kensei150401_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Kensei150401_M->solverInfo,
      &Kensei150401_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Kensei150401_M->solverInfo, (&rtmGetErrorStatus
      (Kensei150401_M)));
    rtsiSetRTModelPtr(&Kensei150401_M->solverInfo, Kensei150401_M);
  }

  rtsiSetSimTimeStep(&Kensei150401_M->solverInfo, MAJOR_TIME_STEP);
  Kensei150401_M->ModelData.intgData.f[0] = Kensei150401_M->ModelData.odeF[0];
  Kensei150401_M->ModelData.contStates = ((real_T *) &Kensei150401_X);
  rtsiSetSolverData(&Kensei150401_M->solverInfo, (void *)
                    &Kensei150401_M->ModelData.intgData);
  rtsiSetSolverName(&Kensei150401_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Kensei150401_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    Kensei150401_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Kensei150401_M->Timing.sampleTimes =
      (&Kensei150401_M->Timing.sampleTimesArray[0]);
    Kensei150401_M->Timing.offsetTimes =
      (&Kensei150401_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Kensei150401_M->Timing.sampleTimes[0] = (0.0);
    Kensei150401_M->Timing.sampleTimes[1] = (0.001);
    Kensei150401_M->Timing.sampleTimes[2] = (0.05);

    /* task offsets */
    Kensei150401_M->Timing.offsetTimes[0] = (0.0);
    Kensei150401_M->Timing.offsetTimes[1] = (0.0);
    Kensei150401_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Kensei150401_M, &Kensei150401_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Kensei150401_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = Kensei150401_M->Timing.perTaskSampleHitsArray;
    Kensei150401_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Kensei150401_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Kensei150401_M, -1);
  Kensei150401_M->Timing.stepSize0 = 0.001;
  Kensei150401_M->Timing.stepSize1 = 0.001;
  Kensei150401_M->Timing.stepSize2 = 0.05;
  Kensei150401_M->solverInfoPtr = (&Kensei150401_M->solverInfo);
  Kensei150401_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Kensei150401_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Kensei150401_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  Kensei150401_M->ModelData.blockIO = ((void *) &Kensei150401_B);
  (void) memset(((void *) &Kensei150401_B), 0,
                sizeof(BlockIO_Kensei150401));

  /* parameters */
  Kensei150401_M->ModelData.defaultParam = ((real_T *)&Kensei150401_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Kensei150401_X;
    Kensei150401_M->ModelData.contStates = (x);
    (void) memset((void *)&Kensei150401_X, 0,
                  sizeof(ContinuousStates_Kensei150401));
  }

  /* states (dwork) */
  Kensei150401_M->Work.dwork = ((void *) &Kensei150401_DWork);
  (void) memset((void *)&Kensei150401_DWork, 0,
                sizeof(D_Work_Kensei150401));

  /* exported global states */
  deltaT = 0.0;
  flipflop = 0.0;
  oldTime = 0.0;
  pulse = 0.0;

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }

  /* Initialize Sizes */
  Kensei150401_M->Sizes.numContStates = (14);/* Number of continuous states */
  Kensei150401_M->Sizes.numY = (0);    /* Number of model outputs */
  Kensei150401_M->Sizes.numU = (0);    /* Number of model inputs */
  Kensei150401_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Kensei150401_M->Sizes.numSampTimes = (3);/* Number of sample times */
  Kensei150401_M->Sizes.numBlocks = (802);/* Number of blocks */
  Kensei150401_M->Sizes.numBlockIO = (665);/* Number of block outputs */
  Kensei150401_M->Sizes.numBlockPrms = (512);/* Sum of parameter "widths" */
  return Kensei150401_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
