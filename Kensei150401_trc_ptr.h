  /*********************** dSPACE target specific file *************************

   Header file Kensei150401_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1401 7.2 (02-May-2014)
   Wed Apr 01 11:49:03 2015

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_Kensei150401_trc_ptr_h_
  #define RTI_HEADER_Kensei150401_trc_ptr_h_
  /* Include the model header file. */
  #include "Kensei150401.h"
  #include "Kensei150401_private.h"

  #ifdef EXTERN_C
  #undef EXTERN_C
  #endif

  #ifdef __cplusplus
  #define EXTERN_C                       extern "C"
  #else
  #define EXTERN_C                       extern
  #endif

  /*
   *  Declare the global TRC pointers
   */
              EXTERN_C volatile  real_T *p_Kensei150401_B_real_T_0;
              EXTERN_C volatile  int32_T *p_Kensei150401_B_int32_T_1;
              EXTERN_C volatile  uint32_T *p_Kensei150401_B_uint32_T_2;
              EXTERN_C volatile  uint16_T *p_Kensei150401_B_uint16_T_3;
              EXTERN_C volatile  uint8_T *p_Kensei150401_B_uint8_T_4;
              EXTERN_C volatile  boolean_T *p_Kensei150401_B_boolean_T_5;
              EXTERN_C volatile  real_T *p_Kensei150401_P_real_T_0;
              EXTERN_C volatile  uint32_T *p_Kensei150401_P_uint32_T_1;
              EXTERN_C volatile  uint8_T *p_Kensei150401_P_uint8_T_2;
              EXTERN_C volatile  boolean_T *p_Kensei150401_P_boolean_T_3;
              EXTERN_C volatile  real_T *p_Kensei150401_DWork_real_T_0;
              EXTERN_C volatile  int32_T *p_Kensei150401_DWork_int32_T_1;
              EXTERN_C volatile  uint32_T *p_Kensei150401_DWork_uint32_T_2;
              EXTERN_C volatile  int_T *p_Kensei150401_DWork_int_T_3;
              EXTERN_C volatile  uint16_T *p_Kensei150401_DWork_uint16_T_4;
              EXTERN_C volatile  int8_T *p_Kensei150401_DWork_int8_T_5;
              EXTERN_C volatile  uint8_T *p_Kensei150401_DWork_uint8_T_6;
              EXTERN_C volatile  boolean_T *p_Kensei150401_DWork_boolean_T_7;
              EXTERN_C volatile  real_T *p_Kensei150401_X_real_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_Kensei150401_B_real_T_0 = &Kensei150401_B.offset;\
              p_Kensei150401_B_int32_T_1 = &Kensei150401_B.SFunction1_o2_e;\
              p_Kensei150401_B_uint32_T_2 = &Kensei150401_B.SFunction1_o1_p;\
              p_Kensei150401_B_uint16_T_3 = &Kensei150401_B.SFunction1_o2_hn;\
              p_Kensei150401_B_uint8_T_4 = &Kensei150401_B.BytePack;\
              p_Kensei150401_B_boolean_T_5 = &Kensei150401_B.SFunction1_a;\
              p_Kensei150401_P_real_T_0 = &Kensei150401_P.rps_Value;\
              p_Kensei150401_P_uint32_T_1 = &Kensei150401_P.Counter_InitialCount;\
              p_Kensei150401_P_uint8_T_2 = &Kensei150401_P.ManualSwitch_CurrentSetting;\
              p_Kensei150401_P_boolean_T_3 = &Kensei150401_P.FLdirection_Value;\
              p_Kensei150401_DWork_real_T_0 = &Kensei150401_DWork.UnitDelay_DSTATE;\
              p_Kensei150401_DWork_int32_T_1 = &Kensei150401_DWork.clockTickCounter;\
              p_Kensei150401_DWork_uint32_T_2 = &Kensei150401_DWork.Counter_Count;\
              p_Kensei150401_DWork_int_T_3 = &Kensei150401_DWork.SFunction1_IWORK[0];\
              p_Kensei150401_DWork_uint16_T_4 = &Kensei150401_DWork.temporalCounter_i1;\
              p_Kensei150401_DWork_int8_T_5 = &Kensei150401_DWork.RateTransition_write_buf;\
              p_Kensei150401_DWork_uint8_T_6 = &Kensei150401_DWork.is_active_c3_Kensei150401;\
              p_Kensei150401_DWork_boolean_T_7 = &Kensei150401_DWork.Mem1_PreviousInput;\
              p_Kensei150401_X_real_T_0 = &Kensei150401_X.AnalogFilter_FR_Pos_CSTATE;\

   #endif                       /* RTI_HEADER_Kensei150401_trc_ptr_h_ */
