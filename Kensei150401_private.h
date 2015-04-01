/*
 * Kensei150401_private.h
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
#ifndef RTW_HEADER_Kensei150401_private_h_
#define RTW_HEADER_Kensei150401_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/* ...  variable for information on a CAN channel */
extern can_tp1_canChannel* can_type1_channel_M1_C2;

/* ...  service variables for the RTICAN status block */
extern can_tp1_canService* can_type1_service_M1_C2[13];

/* ...  variable for information on a CAN channel */
extern can_tp1_canChannel* can_type1_channel_M1_C1;

/* ...  service variables for the RTICAN status block */
extern can_tp1_canService* can_type1_service_M1_C1[13];

/* ... definition of message variable for the RTICAN blocks */
#define CANTP1_M1_NUMMSG               4

extern can_tp1_canMsg* can_type1_msg_M1[CANTP1_M1_NUMMSG];

/* ... variable for taskqueue error checking                  */
extern Int32 rtican_type1_tq_error[CAN_TYPE1_NUM_MODULES]
  [CAN_TYPE1_NUM_TASKQUEUES];

/* Declaration of user indices (CAN_Type1_M1) */
#define CANTP1_M1_C2_TX_STD_0X6B       0
#define TX_C2_STD_0X6B                 0
#undef TX_C2_STD_0X6B
#define CANTP1_M1_C2_RX_STD_0X73       1
#define RX_C2_STD_0X73                 1
#undef RX_C2_STD_0X73
#define CANTP1_M1_C2_Status            0
#define Status_C2                      0
#undef Status_C2
#define CANTP1_M1_C2_AckErrors         1
#define AckErrors_C2                   1
#undef AckErrors_C2
#define CANTP1_M1_C1_TX_STD_0X6C       2
#define TX_C1_STD_0X6C                 2
#undef TX_C1_STD_0X6C
#define CANTP1_M1_C1_RX_STD_0X74       3
#define RX_C1_STD_0X74                 3
#undef RX_C1_STD_0X74
#define CANTP1_M1_C1_Status            0
#define Status_C1                      0
#undef Status_C1
#define CANTP1_M1_C1_RXLost            1
#define RXLost_C1                      1
#undef RXLost_C1
#define CANTP1_M1_C1_DataLost          12
#define CANTP1_M1_C1_RXOK              2
#define RXOK_C1                        2
#undef RXOK_C1

/* predefine needed TX-definition code to support TX-Custom code */
extern can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C2_STD;
extern can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C2_XTD;

/* predefine needed TX-definition code to support TX-Custom code */
extern can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C1_STD;
extern can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C1_XTD;
extern UInt16 DioTp4EncCount[DS1401_IMBUS_MODULE_NB];
extern UInt16 DioTp4EncNo[DS1401_IMBUS_MODULE_NB][DIO_TP4_PORT_NUM]
  [DIO_TP4_CH_NUM];

/* Global variables for NVData transfer */
extern UInt32 Addr_Odometer;
extern int_T State_NVData_Odometer;

/* dSPACE I/O Board 1401stdasertp1 #1 Unit:GENSER Group:SETUP */
extern dsserChannel *rti1401stdasertp1_B1_Ser[2];
extern real_T rt_roundd_snf(real_T u);
extern uint32_T MWDSP_EPH_E_D(real_T evt, uint32_T *sta);
extern real_T rt_powd_snf(real_T u0, real_T u1);

/* Exported functions */
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void flencoderinterruptfunctio_Start(void);
extern void Kens_flencoderinterruptfunction(int_T controlPortIdx);
extern void Kens_flencoderinterruptfunction(int_T controlPortIdx);
void Kensei150401_output0(void);
void Kensei150401_update0(void);
void Kensei150401_output2(void);
void Kensei150401_update2(void);       /* private model entry point functions */
extern void Kensei150401_derivatives(void);

#endif                                 /* RTW_HEADER_Kensei150401_private_h_ */
