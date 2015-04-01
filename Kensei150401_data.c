/*
 * Kensei150401_data.c
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
#include "Kensei150401.h"
#include "Kensei150401_private.h"

/* Block parameters (auto storage) */
Parameters_Kensei150401 Kensei150401_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S46>/0 rps'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S66>/deltaT Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S66>/flipflop Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S66>/oldTime Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S66>/pulse Memory'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S84>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S85>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S108>/Switch2'
                                        */
  0.025,                               /* Expression: 0.025
                                        * Referenced by: '<S108>/RealPWMin'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S86>/Gain3'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S93>/Gain'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S83>/Gain'
                                        */
  30.0,                                /* Expression: RL_Angle_UpperLimit
                                        * Referenced by: '<S88>/RL_ref degree'
                                        */
  -30.0,                               /* Expression: RL_Angle_LowerLimit
                                        * Referenced by: '<S88>/RL_ref degree'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S94>/Gain'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S83>/Gain1'
                                        */
  30.0,                                /* Expression: RR_Angle_UpperLimit
                                        * Referenced by: '<S89>/RR_ref degree'
                                        */
  -30.0,                               /* Expression: RR_Angle_LowerLimit
                                        * Referenced by: '<S89>/RR_ref degree'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S140>/Gain'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S137>/Gain1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S140>/Saturation'
                                        */
  -180.0,                              /* Expression: -180
                                        * Referenced by: '<S140>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S140>/Switch'
                                        */
  1.2,                                 /* Expression: 1.2
                                        * Referenced by: '<S140>/GainKA'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S140>/Gain1'
                                        */
  30.0,                                /* Expression: 60/2
                                        * Referenced by: '<S141>/Constant1'
                                        */
  0.33333333333333331,                 /* Expression: 1/3
                                        * Referenced by: '<S141>/Gain'
                                        */
  1250.0,                              /* Expression: 1250
                                        * Referenced by: '<S141>/GainKB'
                                        */
  0.04,                                /* Expression: 0.04
                                        * Referenced by: '<S137>/Gain'
                                        */
  0.5,                                 /* Expression: 1/2
                                        * Referenced by: '<S137>/Gain2'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S90>/RealPWMin1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S143>/Gain'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S138>/Gain1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S143>/Saturation'
                                        */
  -180.0,                              /* Expression: -180
                                        * Referenced by: '<S143>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S143>/Switch'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S143>/GainKA'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S143>/Gain1'
                                        */
  30.0,                                /* Expression: 60/2
                                        * Referenced by: '<S144>/Constant1'
                                        */
  0.33333333333333331,                 /* Expression: 1/3
                                        * Referenced by: '<S144>/Gain'
                                        */
  1250.0,                              /* Expression: 1250
                                        * Referenced by: '<S144>/GainKB'
                                        */
  0.04,                                /* Expression: 0.04
                                        * Referenced by: '<S138>/Gain'
                                        */
  0.5,                                 /* Expression: 1/2
                                        * Referenced by: '<S138>/Gain2'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S90>/RealPWMin2'
                                        */
  12.0,                                /* Expression: 4*3
                                        * Referenced by: '<S90>/Switch'
                                        */
  12.0,                                /* Expression: 4*3
                                        * Referenced by: '<S90>/Switch1'
                                        */
  1.6,                                 /* Expression: 1.6
                                        * Referenced by: '<S90>/Switch3'
                                        */
  1.6,                                 /* Expression: 1.6
                                        * Referenced by: '<S90>/Switch4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/zero1'
                                        */
  100.0,                               /* Expression: 100/1
                                        * Referenced by: '<S8>/to percent1'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S8>/Pedal Limit 100%1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Pedal Limit 100%1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/zero'
                                        */
  3.0,                                 /* Expression: 3.00
                                        * Referenced by: '<S8>/Pedal Limit 2 V (60 km//h) '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Pedal Limit 2 V (60 km//h) '
                                        */

  /*  Expression: [0,1.5]
   * Referenced by: '<S8>/Throttle MapZPT'
   */
  { 0.0, 1.5 },

  /*  Expression: [0,4.85]
   * Referenced by: '<S8>/Throttle MapZPT'
   */
  { 0.0, 4.85 },
  2.0,                                 /* Expression: 2.00
                                        * Referenced by: '<S8>/Pedal Limit zpt 2V'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Pedal Limit zpt 2V'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/AWScomm'
                                        */
  -55.0,                               /* Expression: -55
                                        * Referenced by: '<S1>/FLdegcomm'
                                        */
  52.0,                                /* Expression: 52
                                        * Referenced by: '<S1>/FRdegcomm'
                                        */
  1.4,                                 /* Expression: 1.4
                                        * Referenced by: '<S1>/Ka'
                                        */
  54.0,                                /* Expression: 54
                                        * Referenced by: '<S1>/RLdegcomm'
                                        */
  -51.0,                               /* Expression: -51
                                        * Referenced by: '<S1>/RRdegcomm'
                                        */
  9.0,                                 /* Expression: 9
                                        * Referenced by: '<S1>/T_in'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S1>/kmh'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S1>/Modecomm'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/offset'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/sportcomm'
                                        */
  -3.2999999999999996E-5,              /* Expression: -(3.3*10^-5)
                                        * Referenced by: '<S1>/Kb'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/kmh1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S2>/inADC1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S2>/inADC2'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S2>/inADC3'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S2>/inADC4'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S2>/inADC5'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S2>/inADC6'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S2>/inADC7'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S2>/inADC8'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S2>/inADC9'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/PC_On_Off_Touch_Button'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Touch_Button_Forward_1_Reverse_0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/ZPT_Touch_Button'
                                        */
  5.0E-5,                              /* Expression: 5e-5
                                        * Referenced by: '<S3>/20000 Hz'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S108>/FRwm'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S108>/Switch_FR'
                                        */
  0.38781,                             /* Expression: FR_b
                                        * Referenced by: '<S115>/b'
                                        */
  0.10686,                             /* Expression: FR_c
                                        * Referenced by: '<S115>/c'
                                        */
  0.428,                               /* Expression: FR_d
                                        * Referenced by: '<S115>/d'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S115>/constant'
                                        */
  0.076923076923076927,                /* Expression: 1/13
                                        * Referenced by: '<S135>/pulse_to_degree'
                                        */
  720.0,                               /* Expression: 720
                                        * Referenced by: '<S135>/limit rotation data'
                                        */
  -720.0,                              /* Expression: -720
                                        * Referenced by: '<S135>/limit rotation data'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S79>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S65>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S65>/Unit Delay'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S46>/if to rad = 2*pi'
                                        */
  86.0,                                /* Expression: 86
                                        * Referenced by: '<S46>/pulses per revolution'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S46>/Rate Transition'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S46>/Rate Transition4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S46>/Rate Transition1'
                                        */
  1180.0,                              /* Expression: 1180
                                        * Referenced by: '<S46>/Switch1'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S46>/RPSec to w'
                                        */
  0.225,                               /* Expression: 0.225
                                        * Referenced by: '<S46>/Tyre radius'
                                        */
  3.6,                                 /* Expression: 3600/1000
                                        * Referenced by: '<S46>/m//s to km//h'
                                        */
  80.0,                                /* Expression: 80
                                        * Referenced by: '<S46>/Limit 80km//h'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S46>/Limit 80km//h'
                                        */

  /*  Expression: THO
   * Referenced by: '<S8>/Throttle Map1'
   */
  { 0.0, 0.1, 0.5, 1.0, 1.5, 2.5, 3.0, 4.5, 5.0 },

  /*  Expression: THI
   * Referenced by: '<S8>/Throttle Map1'
   */
  { 0.0, 0.1, 0.5, 1.0, 1.5, 2.5, 3.0, 4.0, 4.85 },
  20.0,                                /* Expression: 100/5.00
                                        * Referenced by: '<S8>/to percent'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S8>/Pedal Limit 100%'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Pedal Limit 100%'
                                        */
  1.615,                               /* Expression: 1.615
                                        * Referenced by: '<S86>/Wheel base'
                                        */
  1.1,                                 /* Expression: 1.1
                                        * Referenced by: '<S86>/Wheel track'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S86>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S86>/Gain'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<S135>/Steering Ratio'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<S135>/ratio1'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S135>/ratio2'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S117>/Gain1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S86>/Gain2'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S118>/Gain'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S91>/Gain1'
                                        */
  0.27777777777777779,                 /* Expression: 1000/3600
                                        * Referenced by: '<S87>/km//h to m//s'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S87>/A'
                                        */
  200.0,                               /* Expression: 200
                                        * Referenced by: '<S87>/m'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S87>/L'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<S87>/Cr'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S87>/B'
                                        */
  2000.0,                              /* Expression: 2000
                                        * Referenced by: '<S87>/Cf'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S87>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S87>/Saturation'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<S87>/ratio1'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S87>/ratio2'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S92>/Gain1'
                                        */
  1.615,                               /* Expression: 1.615
                                        * Referenced by: '<S83>/Wheel base'
                                        */
  1.1,                                 /* Expression: 1.1
                                        * Referenced by: '<S83>/Wheel track'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S96>/Gain'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S83>/Gain3'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S109>/ratio3'
                                        */
  0.1,                                 /* Expression: 1/10
                                        * Referenced by: '<S109>/ratio4'
                                        */
  30.0,                                /* Expression: FR_Angle_UpperLimit
                                        * Referenced by: '<S85>/FR_ref degree'
                                        */
  -30.0,                               /* Expression: FR_Angle_LowerLimit
                                        * Referenced by: '<S85>/FR_ref degree'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S85>/Switch2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S115>/direction'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S115>/degree to rad'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<S115>/m to mm'
                                        */
  3.117,                               /* Expression: FR_ADC_Center
                                        * Referenced by: '<S112>/FR ADC Center'
                                        */
  34.482758620689651,                  /* Expression: FR_Vpm
                                        * Referenced by: '<S112>/FR_Volt per mm2'
                                        */
  0.029,                               /* Expression: FR_Mpv
                                        * Referenced by: '<S112>/FR_mm to volt'
                                        */
  4.42,                                /* Expression: FR_ADC_UpperLimit
                                        * Referenced by: '<S85>/FR_ref input Saturation'
                                        */
  0.17,                                /* Expression: FR_ADC_LowerLimit
                                        * Referenced by: '<S85>/FR_ref input Saturation'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<S110>/ratio3'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S110>/ratio4'
                                        */
  -9.8261336418013574,                 /* Computed Parameter: AnalogFilter_FR_Pos_A
                                        * Referenced by: '<S85>/Analog Filter_FR_Pos'
                                        */
  5.0,                                 /* Computed Parameter: AnalogFilter_FR_Pos_B
                                        * Referenced by: '<S85>/Analog Filter_FR_Pos'
                                        */
  1.9652267283602716,                  /* Computed Parameter: AnalogFilter_FR_Pos_C
                                        * Referenced by: '<S85>/Analog Filter_FR_Pos'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S85>/Analog Filter_FR_Pos'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<S111>/ratio3'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S111>/ratio4'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S107>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S107>/Derivative Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S107>/Filter'
                                        */
  100.0,                               /* Expression: N
                                        * Referenced by: '<S107>/Filter Coefficient'
                                        */
  200.0,                               /* Expression: P
                                        * Referenced by: '<S107>/Proportional Gain'
                                        */
  1000.0,                              /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S107>/Saturation'
                                        */
  -1000.0,                             /* Expression: LowerSaturationLimit
                                        * Referenced by: '<S107>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S85>/Constant'
                                        */
  0.02,                                /* Expression: 0.02
                                        * Referenced by: '<S85>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Offset5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S98>/FLpwm'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S98>/Switch_FL'
                                        */
  0.38677,                             /* Expression: FL_b
                                        * Referenced by: '<S105>/b'
                                        */
  0.10137,                             /* Expression: FL_c
                                        * Referenced by: '<S105>/c'
                                        */
  0.431,                               /* Expression: FL_d
                                        * Referenced by: '<S105>/d'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S105>/constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S86>/Switch1'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S119>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S95>/Gain'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S83>/Gain2'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S99>/ratio3'
                                        */
  0.1,                                 /* Expression: 1/10
                                        * Referenced by: '<S99>/ratio4'
                                        */
  30.0,                                /* Expression: FL_Angle_UpperLimit
                                        * Referenced by: '<S84>/FL_ref degree'
                                        */
  -30.0,                               /* Expression: FL_Angle_LowerLimit
                                        * Referenced by: '<S84>/FL_ref degree'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S84>/Switch2'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S105>/degree to rad'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<S105>/m to mm'
                                        */
  3.175,                               /* Expression: FL_ADC_Center
                                        * Referenced by: '<S102>/FL ADC Center'
                                        */
  34.482758620689651,                  /* Expression: FL_Vpm
                                        * Referenced by: '<S102>/FL_Volt per mm2'
                                        */
  0.029,                               /* Expression: FL_Mpv
                                        * Referenced by: '<S102>/FL_mm to volt'
                                        */
  4.45,                                /* Expression: FL_ADC_UpperLimit
                                        * Referenced by: '<S84>/FL_ref input Saturation'
                                        */
  0.23,                                /* Expression: FL_ADC_LowerLimit
                                        * Referenced by: '<S84>/FL_ref input Saturation'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<S100>/ratio3'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S100>/ratio4'
                                        */
  -9.8261336418013574,                 /* Computed Parameter: AnalogFilter_FL_Pos_A
                                        * Referenced by: '<S84>/Analog Filter_FL_Pos'
                                        */
  5.0,                                 /* Computed Parameter: AnalogFilter_FL_Pos_B
                                        * Referenced by: '<S84>/Analog Filter_FL_Pos'
                                        */
  1.9652267283602716,                  /* Computed Parameter: AnalogFilter_FL_Pos_C
                                        * Referenced by: '<S84>/Analog Filter_FL_Pos'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S84>/Analog Filter_FL_Pos'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<S101>/ratio3'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S101>/ratio4'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S97>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S97>/Derivative Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S97>/Filter'
                                        */
  100.0,                               /* Expression: N
                                        * Referenced by: '<S97>/Filter Coefficient'
                                        */
  200.0,                               /* Expression: P
                                        * Referenced by: '<S97>/Proportional Gain'
                                        */
  1000.0,                              /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S97>/Saturation'
                                        */
  -1000.0,                             /* Expression: LowerSaturationLimit
                                        * Referenced by: '<S97>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S84>/Constant'
                                        */
  0.02,                                /* Expression: 0.02
                                        * Referenced by: '<S84>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S98>/Switch2'
                                        */
  0.025,                               /* Expression: 0.025
                                        * Referenced by: '<S98>/RealPWMin'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Offset6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S128>/RRpwm'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S128>/Switch_RR'
                                        */
  0.38781,                             /* Expression: RR_b
                                        * Referenced by: '<S132>/b'
                                        */
  0.10686,                             /* Expression: RR_c
                                        * Referenced by: '<S132>/c'
                                        */
  0.433,                               /* Expression: RR_d
                                        * Referenced by: '<S132>/d'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S132>/constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S89>/Switch'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S132>/degree to rad'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<S132>/m to mm'
                                        */
  3.151,                               /* Expression: RR_ADC_Center
                                        * Referenced by: '<S129>/RR ADC Center'
                                        */
  34.482758620689651,                  /* Expression: RR_Vpm
                                        * Referenced by: '<S129>/RR_Volt per mm2'
                                        */
  0.029,                               /* Expression: RR_Mpv
                                        * Referenced by: '<S129>/RR_mm to volt'
                                        */
  4.43,                                /* Expression: RR_ADC_UpperLimit
                                        * Referenced by: '<S89>/RR_ref input Saturation'
                                        */
  0.23,                                /* Expression: RR_ADC_LowerLimit
                                        * Referenced by: '<S89>/RR_ref input Saturation'
                                        */
  -9.8261336418013574,                 /* Computed Parameter: AnalogFilter_RR_Pos_A
                                        * Referenced by: '<S89>/Analog Filter_RR_Pos'
                                        */
  5.0,                                 /* Computed Parameter: AnalogFilter_RR_Pos_B
                                        * Referenced by: '<S89>/Analog Filter_RR_Pos'
                                        */
  1.9652267283602716,                  /* Computed Parameter: AnalogFilter_RR_Pos_C
                                        * Referenced by: '<S89>/Analog Filter_RR_Pos'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S89>/Analog Filter_RR_Pos'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S127>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S127>/Derivative Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S127>/Filter'
                                        */
  100.0,                               /* Expression: N
                                        * Referenced by: '<S127>/Filter Coefficient'
                                        */
  200.0,                               /* Expression: P
                                        * Referenced by: '<S127>/Proportional Gain'
                                        */
  1000.0,                              /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S127>/Saturation'
                                        */
  -1000.0,                             /* Expression: LowerSaturationLimit
                                        * Referenced by: '<S127>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S89>/Constant'
                                        */
  0.02,                                /* Expression: 0.02
                                        * Referenced by: '<S89>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S128>/Switch2'
                                        */
  0.025,                               /* Expression: 0.025
                                        * Referenced by: '<S128>/RealPWMin'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Offset7'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S121>/RLpwm'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S121>/Switch_RL'
                                        */
  0.39708,                             /* Expression: RL_b
                                        * Referenced by: '<S125>/b'
                                        */
  0.10551,                             /* Expression: RL_c
                                        * Referenced by: '<S125>/c'
                                        */
  0.434,                               /* Expression: RL_d
                                        * Referenced by: '<S125>/d'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S125>/constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S88>/Switch'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S125>/gain'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S125>/degree to rad'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<S125>/m to mm'
                                        */
  3.221,                               /* Expression: RL_ADC_Center
                                        * Referenced by: '<S122>/RL ADC Center'
                                        */
  34.482758620689651,                  /* Expression: RL_Vpm
                                        * Referenced by: '<S122>/RL_Volt per mm2'
                                        */
  0.029,                               /* Expression: RL_Mpv
                                        * Referenced by: '<S122>/RL_mm to volt'
                                        */
  4.37,                                /* Expression: RL_ADC_UpperLimit
                                        * Referenced by: '<S88>/RL_ref input Saturation'
                                        */
  0.18,                                /* Expression: RL_ADC_LowerLimit
                                        * Referenced by: '<S88>/RL_ref input Saturation'
                                        */
  -9.8261336418013574,                 /* Computed Parameter: AnalogFilter_RL_Pos_A
                                        * Referenced by: '<S88>/Analog Filter_RL_Pos'
                                        */
  5.0,                                 /* Computed Parameter: AnalogFilter_RL_Pos_B
                                        * Referenced by: '<S88>/Analog Filter_RL_Pos'
                                        */
  1.9652267283602716,                  /* Computed Parameter: AnalogFilter_RL_Pos_C
                                        * Referenced by: '<S88>/Analog Filter_RL_Pos'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S88>/Analog Filter_RL_Pos'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S120>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S120>/Derivative Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S120>/Filter'
                                        */
  100.0,                               /* Expression: N
                                        * Referenced by: '<S120>/Filter Coefficient'
                                        */
  200.0,                               /* Expression: P
                                        * Referenced by: '<S120>/Proportional Gain'
                                        */
  1000.0,                              /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S120>/Saturation'
                                        */
  -1000.0,                             /* Expression: LowerSaturationLimit
                                        * Referenced by: '<S120>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S88>/Constant'
                                        */
  0.02,                                /* Expression: 0.02
                                        * Referenced by: '<S88>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S121>/Switch2'
                                        */
  0.025,                               /* Expression: 0.025
                                        * Referenced by: '<S121>/RealPWMin'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Offset4'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S136>/Gain1'
                                        */

  /*  Expression: [-1.68*14, -1.64*12, -1.62*6, -1.6, 0, 1.6, 1.62*6, 1.64*12, 1.68*14]
   * Referenced by: '<S90>/Feedback Map ZPT'
   */
  { -23.52, -19.68, -9.72, -1.6, 0.0, 1.6, 9.72, 19.68, 23.52 },

  /*  Expression: [-1.68, -1.64, -1.62, -1.6, 0, 1.6, 1.62, 1.64, 1.68]
   * Referenced by: '<S90>/Feedback Map ZPT'
   */
  { -1.68, -1.64, -1.62, -1.6, 0.0, 1.6, 1.62, 1.64, 1.68 },
  24.52,                               /* Expression: 1.68*14+1
                                        * Referenced by: '<S90>/Saturation2'
                                        */
  -24.52,                              /* Expression: -1.68*14-1
                                        * Referenced by: '<S90>/Saturation2'
                                        */
  0.04,                                /* Expression: 0.04
                                        * Referenced by: '<S90>/Gain2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S90>/Gain3'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S90>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S90>/Saturation1'
                                        */
  17.0,                                /* Expression: 17
                                        * Referenced by: '<S138>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S142>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S139>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S90>/Switch5'
                                        */

  /*  Expression: [-4.08*4, -4.04*2, -4.02*1.3, -4, 0, 4, 4.02*1.3, 4.04*2, 4.08*4]
   * Referenced by: '<S90>/Feedback Map'
   */
  { -16.32, -8.08, -5.226, -4.0, 0.0, 4.0, 5.226, 8.08, 16.32 },

  /*  Expression: [-4.08*3, -4.04*3, -4.02*3, -4*3, 0, 4*3, 4.02*3, 4.04*3, 4.08*3]
   * Referenced by: '<S90>/Feedback Map'
   */
  { -12.24, -12.120000000000001, -12.059999999999999, -12.0, 0.0, 12.0,
    12.059999999999999, 12.120000000000001, 12.24 },
  17.32,                               /* Expression: 4.08*4+1
                                        * Referenced by: '<S90>/Saturation'
                                        */
  -17.32,                              /* Expression: -4.08*4-1
                                        * Referenced by: '<S90>/Saturation'
                                        */
  0.04,                                /* Expression: 0.04
                                        * Referenced by: '<S90>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S90>/Switch2'
                                        */
  0.1,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S146>/Integrator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S8>/Switch1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S8>/Switch'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S145>/Gain1'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S8>/Switch5'
                                        */

  /*  Expression: [0, 1.0]
   * Referenced by: '<S8>/Throttle MapZPT1'
   */
  { 0.0, 1.0 },

  /*  Expression: [0.2, 1.6]
   * Referenced by: '<S8>/Throttle MapZPT1'
   */
  { 0.2, 1.6 },
  1.5,                                 /* Expression: 1.5
                                        * Referenced by: '<S8>/Pedal Limit zpt 2V1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Pedal Limit zpt 2V1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S8>/Switch3'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S8>/0 to 5 V1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/0 to 5 V1'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S3>/outDAC2'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S3>/outDAC4'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/BrakeR'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S3>/outDAC6'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/BrakeL'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S3>/outDAC8'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S134>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S114>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S108>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S104>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S98>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S131>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S128>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S124>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S121>/Switch1'
                                        */
  47.4,                                /* Expression: 47.4
                                        * Referenced by: '<S44>/Vmin'
                                        */
  -9.8261336418013574,                 /* Computed Parameter: AnalogFilter_FR_Pos_A_e
                                        * Referenced by: '<S44>/Analog Filter_FR_Pos'
                                        */
  5.0,                                 /* Computed Parameter: AnalogFilter_FR_Pos_B_f
                                        * Referenced by: '<S44>/Analog Filter_FR_Pos'
                                        */
  1.9652267283602716,                  /* Computed Parameter: AnalogFilter_FR_Pos_C_k
                                        * Referenced by: '<S44>/Analog Filter_FR_Pos'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S44>/Analog Filter_FR_Pos'
                                        */
  22.32,                               /* Expression: 22.32
                                        * Referenced by: '<S44>/Ampere//volt'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S44>/ratio1'
                                        */
  0.01,                                /* Expression: 1/100
                                        * Referenced by: '<S44>/ratio2'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S45>/Current'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S45>/Current1'
                                        */
  256.0,                               /* Expression: 256
                                        * Referenced by: '<S45>/Gain'
                                        */
  256.0,                               /* Expression: 256
                                        * Referenced by: '<S45>/Gain1'
                                        */
  0.016666666666666666,                /* Expression: 1/60
                                        * Referenced by: '<S45>/RPM to RPSec'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S45>/RPSec to w'
                                        */
  0.225,                               /* Expression: 0.225
                                        * Referenced by: '<S45>/Tyre radius'
                                        */
  3.6,                                 /* Expression: 3600/1000
                                        * Referenced by: '<S45>/m//s to km//h'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S58>/New data value'
                                        */
  0.055,                               /* Expression: 0.055
                                        * Referenced by: '<S58>/Delta time limit'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S58>/No data value'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S59>/New data value'
                                        */
  0.055,                               /* Expression: 0.055
                                        * Referenced by: '<S59>/Delta time limit'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S59>/No data value'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S50>/Bus Off value'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S50>/RX lost limit'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<S51>/Acknowdledge error limit'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S51>/Bus Off value'
                                        */
  55.0,                                /* Expression: 55
                                        * Referenced by: '<S45>/Constant'
                                        */
  0.055,                               /* Expression: 0.055
                                        * Referenced by: '<S62>/Delta time limit'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S62>/Prev. msg. sent value'
                                        */
  55.0,                                /* Expression: 55
                                        * Referenced by: '<S45>/Constant1'
                                        */
  0.055,                               /* Expression: 0.055
                                        * Referenced by: '<S63>/Delta time limit'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S63>/Prev. msg. sent value'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S46>/RPSec to w1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S46>/Rate Transition3'
                                        */
  0.011627906976744186,                /* Expression: 1/86
                                        * Referenced by: '<S46>/pulses to revolution'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S46>/RPSec to w2'
                                        */
  0.225,                               /* Expression: 0.225
                                        * Referenced by: '<S46>/Tyre radius2'
                                        */
  0.225,                               /* Expression: 0.225
                                        * Referenced by: '<S46>/Tyre radius1'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S46>/m to km'
                                        */
  3.6,                                 /* Expression: 3600/1000
                                        * Referenced by: '<S46>/m//s to km//h1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S48>/Pulse Generator'
                                        */
  1000.0,                              /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<S48>/Pulse Generator'
                                        */
  500.0,                               /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<S48>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S48>/Pulse Generator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S48>/Sine Wave'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S48>/Sine Wave'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S48>/Sine Wave'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S48>/Sine Wave'
                                        */
  0.01,                                /* Expression: I
                                        * Referenced by: '<S97>/Integral Gain'
                                        */
  4.0,                                 /* Expression: Kb
                                        * Referenced by: '<S97>/Kb'
                                        */
  3.175,                               /* Expression: FL_ADC_Center
                                        * Referenced by: '<S103>/FL ADC Center'
                                        */
  0.22,                                /* Expression: FL_ADC_Min
                                        * Referenced by: '<S103>/FL ADC min'
                                        */
  34.482758620689651,                  /* Expression: FL_Vpm
                                        * Referenced by: '<S103>/FL_Volt per mm'
                                        */
  34.482758620689651,                  /* Expression: FL_Vpm
                                        * Referenced by: '<S103>/FL_Volt per mm1'
                                        */
  34.482758620689651,                  /* Expression: FL_Vpm
                                        * Referenced by: '<S103>/FL_Volt per mm2'
                                        */
  0.38677,                             /* Expression: FL_b
                                        * Referenced by: '<S106>/b'
                                        */
  0.10137,                             /* Expression: FL_c
                                        * Referenced by: '<S106>/c'
                                        */
  0.431,                               /* Expression: FL_d
                                        * Referenced by: '<S106>/d'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S106>/constant'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S106>/mm to meter'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S106>/rad to degree'
                                        */
  0.01,                                /* Expression: I
                                        * Referenced by: '<S107>/Integral Gain'
                                        */
  4.0,                                 /* Expression: Kb
                                        * Referenced by: '<S107>/Kb'
                                        */
  3.117,                               /* Expression: FR_ADC_Center
                                        * Referenced by: '<S113>/FR ADC Center'
                                        */
  0.16,                                /* Expression: FR_ADC_Min
                                        * Referenced by: '<S113>/FR ADC min'
                                        */
  34.482758620689651,                  /* Expression: FR_Vpm
                                        * Referenced by: '<S113>/FR_Volt per mm'
                                        */
  34.482758620689651,                  /* Expression: FR_Vpm
                                        * Referenced by: '<S113>/FR_Volt per mm1'
                                        */
  34.482758620689651,                  /* Expression: FR_Vpm
                                        * Referenced by: '<S113>/FR_Volt per mm2'
                                        */
  0.38781,                             /* Expression: FR_b
                                        * Referenced by: '<S116>/b'
                                        */
  0.10686,                             /* Expression: FR_c
                                        * Referenced by: '<S116>/c'
                                        */
  0.428,                               /* Expression: FR_d
                                        * Referenced by: '<S116>/d'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S116>/constant'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S116>/mm to meter'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S116>/rad to degree'
                                        */
  0.01,                                /* Expression: I
                                        * Referenced by: '<S120>/Integral Gain'
                                        */
  4.0,                                 /* Expression: Kb
                                        * Referenced by: '<S120>/Kb'
                                        */
  3.221,                               /* Expression: RL_ADC_Center
                                        * Referenced by: '<S123>/RL ADC Center'
                                        */
  0.17,                                /* Expression: RL_ADC_Min
                                        * Referenced by: '<S123>/RL ADC min'
                                        */
  34.482758620689651,                  /* Expression: RL_Vpm
                                        * Referenced by: '<S123>/RL_Volt per mm'
                                        */
  34.482758620689651,                  /* Expression: RL_Vpm
                                        * Referenced by: '<S123>/RL_Volt per mm1'
                                        */
  34.482758620689651,                  /* Expression: RL_Vpm
                                        * Referenced by: '<S123>/RL_Volt per mm2'
                                        */
  0.39708,                             /* Expression: RL_b
                                        * Referenced by: '<S126>/b'
                                        */
  0.10551,                             /* Expression: RL_c
                                        * Referenced by: '<S126>/c'
                                        */
  0.434,                               /* Expression: RL_d
                                        * Referenced by: '<S126>/d'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S126>/constant'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S126>/mm to meter'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S126>/rad to degree'
                                        */
  0.01,                                /* Expression: I
                                        * Referenced by: '<S127>/Integral Gain'
                                        */
  4.0,                                 /* Expression: Kb
                                        * Referenced by: '<S127>/Kb'
                                        */
  3.151,                               /* Expression: RR_ADC_Center
                                        * Referenced by: '<S130>/RR ADC Center'
                                        */
  0.22,                                /* Expression: RR_ADC_Min
                                        * Referenced by: '<S130>/RR ADC min'
                                        */
  34.482758620689651,                  /* Expression: RR_Vpm
                                        * Referenced by: '<S130>/RR_Volt per mm'
                                        */
  34.482758620689651,                  /* Expression: RR_Vpm
                                        * Referenced by: '<S130>/RR_Volt per mm1'
                                        */
  34.482758620689651,                  /* Expression: RR_Vpm
                                        * Referenced by: '<S130>/RR_Volt per mm2'
                                        */
  0.38781,                             /* Expression: RR_b
                                        * Referenced by: '<S133>/b'
                                        */
  0.10686,                             /* Expression: RR_c
                                        * Referenced by: '<S133>/c'
                                        */
  0.433,                               /* Expression: RR_d
                                        * Referenced by: '<S133>/d'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S133>/constant'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S133>/mm to meter'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S133>/rad to degree'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Stop PWM 1..1'
                                        */
  1.0,                                 /* Expression: r
                                        * Referenced by: '<S8>/Tyre radius3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S8>/-1 to 1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S8>/-1 to 1'
                                        */
  1.0,                                 /* Expression: r
                                        * Referenced by: '<S8>/Tyre radius'
                                        */
  0.4,                                 /* Expression: I
                                        * Referenced by: '<S146>/Integral Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S8>/Switch4'
                                        */
  0U,                                  /* Computed Parameter: Counter_InitialCount
                                        * Referenced by: '<S46>/Counter'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S48>/Manual Switch'
                                        */
  1U,                                  /* Computed Parameter: numbytes_Value
                                        * Referenced by: '<S48>/numbytes'
                                        */
  0,                                   /* Computed Parameter: FLdirection_Value
                                        * Referenced by: '<S98>/FLdirection'
                                        */
  0,                                   /* Computed Parameter: RLdirection_Value
                                        * Referenced by: '<S121>/RLdirection'
                                        */
  0,                                   /* Computed Parameter: FRdirection_Value
                                        * Referenced by: '<S108>/FRdirection'
                                        */
  0,                                   /* Computed Parameter: RRdirection_Value
                                        * Referenced by: '<S128>/RRdirection'
                                        */
  0,                                   /* Computed Parameter: Mem1_X0
                                        * Referenced by: '<S58>/Mem1'
                                        */
  0,                                   /* Computed Parameter: Mem2_X0
                                        * Referenced by: '<S58>/Mem2'
                                        */
  0,                                   /* Computed Parameter: Mem3_X0
                                        * Referenced by: '<S58>/Mem3'
                                        */
  0,                                   /* Computed Parameter: Mem4_X0
                                        * Referenced by: '<S58>/Mem4'
                                        */
  0,                                   /* Computed Parameter: Mem5_X0
                                        * Referenced by: '<S58>/Mem5'
                                        */
  0,                                   /* Computed Parameter: Mem1_X0_g
                                        * Referenced by: '<S59>/Mem1'
                                        */
  0,                                   /* Computed Parameter: Mem2_X0_a
                                        * Referenced by: '<S59>/Mem2'
                                        */
  0,                                   /* Computed Parameter: Mem3_X0_i
                                        * Referenced by: '<S59>/Mem3'
                                        */
  0,                                   /* Computed Parameter: Mem4_X0_n
                                        * Referenced by: '<S59>/Mem4'
                                        */
  0,                                   /* Computed Parameter: Mem5_X0_f
                                        * Referenced by: '<S59>/Mem5'
                                        */
  0,                                   /* Computed Parameter: Mem1_X0_m
                                        * Referenced by: '<S62>/Mem1'
                                        */
  0,                                   /* Computed Parameter: Mem2_X0_m
                                        * Referenced by: '<S62>/Mem2'
                                        */
  0,                                   /* Computed Parameter: Mem3_X0_f
                                        * Referenced by: '<S62>/Mem3'
                                        */
  0,                                   /* Computed Parameter: Mem4_X0_l
                                        * Referenced by: '<S62>/Mem4'
                                        */
  0,                                   /* Computed Parameter: Mem1_X0_e
                                        * Referenced by: '<S63>/Mem1'
                                        */
  0,                                   /* Computed Parameter: Mem2_X0_k
                                        * Referenced by: '<S63>/Mem2'
                                        */
  0,                                   /* Computed Parameter: Mem3_X0_e
                                        * Referenced by: '<S63>/Mem3'
                                        */
  0                                    /* Computed Parameter: Mem4_X0_m
                                        * Referenced by: '<S63>/Mem4'
                                        */
};
