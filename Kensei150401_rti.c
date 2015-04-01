/*********************** dSPACE target specific file *************************

   Include file Kensei150401_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1401 7.2 (02-May-2014)
   Wed Apr 01 11:49:03 2015

   (c) Copyright 2006, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "Kensei150401.h"
#include "Kensei150401_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             Kensei150401_B
#define RTP_STRUCTURE_NAME             Kensei150401_P

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <dsnvdata.h>
#include <rti_flash_msg.h>
#include <rti_sim_engine_exp.h>
#include <dsflrec.h>
#include <dsser.h>
#include <rtican_ds1401.h>

/****** Definitions: task functions for timer tasks *********************/

/* Timer Task 1. (Base rate). */
static void rti_TIMERA(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  baseRateService(task);

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* Timer Task 2. (Sample rate). */
static void rti_TIMERA2(rtk_p_task_control_block task)
{
  /* Task code. */
  sampleRateService(task);
}

/****** Definitions: task functions for HW interrupts *******************/

/* HW Interrupt: <S64>/Common Hardware Interrupt Interface */
static void rti_DIOT4M0I2S16(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  {
    /* RateTransition: '<S46>/Rate Transition' */
    switch (Kensei150401_DWork.RateTransition_write_buf) {
     case 0:
      Kensei150401_DWork.RateTransition_read_buf = 1;
      break;

     case 1:
      Kensei150401_DWork.RateTransition_read_buf = 0;
      break;

     default:
      Kensei150401_DWork.RateTransition_read_buf =
        Kensei150401_DWork.RateTransition_last_buf_wr;
      break;
    }

    if (Kensei150401_DWork.RateTransition_read_buf != 0) {
      Kensei150401_B.RateTransition = Kensei150401_DWork.RateTransition_Buffer1;
    } else {
      Kensei150401_B.RateTransition = Kensei150401_DWork.RateTransition_Buffer0;
    }

    Kensei150401_DWork.RateTransition_read_buf = -1;

    /* End of RateTransition: '<S46>/Rate Transition' */
    Kens_flencoderinterruptfunction(0);

    /* RateTransition: '<S46>/Rate Transition4' */
    switch (Kensei150401_DWork.RateTransition4_read_buf) {
     case 0:
      Kensei150401_DWork.RateTransition4_write_buf = 1;
      break;

     case 1:
      Kensei150401_DWork.RateTransition4_write_buf = 0;
      break;

     default:
      Kensei150401_DWork.RateTransition4_write_buf = (int8_T)
        (Kensei150401_DWork.RateTransition4_last_buf_wr == 0);
      break;
    }

    if (Kensei150401_DWork.RateTransition4_write_buf != 0) {
      Kensei150401_DWork.RateTransition4_Buffer1 = Kensei150401_B.flipflopRead;
    } else {
      Kensei150401_DWork.RateTransition4_Buffer0 = Kensei150401_B.flipflopRead;
    }

    Kensei150401_DWork.RateTransition4_last_buf_wr =
      Kensei150401_DWork.RateTransition4_write_buf;
    Kensei150401_DWork.RateTransition4_write_buf = -1;

    /* End of RateTransition: '<S46>/Rate Transition4' */

    /* RateTransition: '<S46>/Rate Transition1' */
    switch (Kensei150401_DWork.RateTransition1_read_buf) {
     case 0:
      Kensei150401_DWork.RateTransition1_write_buf = 1;
      break;

     case 1:
      Kensei150401_DWork.RateTransition1_write_buf = 0;
      break;

     default:
      Kensei150401_DWork.RateTransition1_write_buf = (int8_T)
        (Kensei150401_DWork.RateTransition1_last_buf_wr == 0);
      break;
    }

    if (Kensei150401_DWork.RateTransition1_write_buf != 0) {
      Kensei150401_DWork.RateTransition1_Buffer1 =
        Kensei150401_B.RateTransition2;
    } else {
      Kensei150401_DWork.RateTransition1_Buffer0 =
        Kensei150401_B.RateTransition2;
    }

    Kensei150401_DWork.RateTransition1_last_buf_wr =
      Kensei150401_DWork.RateTransition1_write_buf;
    Kensei150401_DWork.RateTransition1_write_buf = -1;

    /* End of RateTransition: '<S46>/Rate Transition1' */

    /* RateTransition: '<S46>/Rate Transition3' */
    switch (Kensei150401_DWork.RateTransition3_read_buf) {
     case 0:
      Kensei150401_DWork.RateTransition3_write_buf = 1;
      break;

     case 1:
      Kensei150401_DWork.RateTransition3_write_buf = 0;
      break;

     default:
      Kensei150401_DWork.RateTransition3_write_buf = (int8_T)
        (Kensei150401_DWork.RateTransition3_last_buf_wr == 0);
      break;
    }

    if (Kensei150401_DWork.RateTransition3_write_buf != 0) {
      Kensei150401_DWork.RateTransition3_Buffer1 = Kensei150401_B.pulseRead;
    } else {
      Kensei150401_DWork.RateTransition3_Buffer0 = Kensei150401_B.pulseRead;
    }

    Kensei150401_DWork.RateTransition3_last_buf_wr =
      Kensei150401_DWork.RateTransition3_write_buf;
    Kensei150401_DWork.RateTransition3_write_buf = -1;

    /* End of RateTransition: '<S46>/Rate Transition3' */
  }

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* ===== Declarations of RTI blocks ======================================== */

/* dSPACE I/O Board DS1401STDDIOT4 #0 */
UInt16 DioTp4EncCount[DS1401_IMBUS_MODULE_NB] = { MODULE_NB_ARRAY_INIT };

UInt16 DioTp4EncNo[DS1401_IMBUS_MODULE_NB][DIO_TP4_PORT_NUM][DIO_TP4_CH_NUM];

/* dSPACE I/O Board DSFLASH #1 */
/* dSPACE I/O Board DSFLASH #1 Unit:SETUP */
extern dsflash_handle_type ds1401_flash_handle;

/* dSPACE I/O Board DSFLASH #1 Unit:NVDATARESTORE */
/* Global variables for NVData transfer */
UInt32 Addr_Odometer;
int_T State_NVData_Odometer;

/* dSPACE I/O Board 1401stdasertp1 #1 Unit:GENSER Group:SETUP */
dsserChannel *rti1401stdasertp1_B1_Ser[2];

/* dSPACE I/O Board DS1_RTICAN #1 */

/* ...  definition of channel struct */
can_tp1_canChannel* can_type1_channel_M1_C2;

/* ...  service variables for the RTICAN status block */
can_tp1_canService* can_type1_service_M1_C2[13];

/* ...  definition of channel struct */
can_tp1_canChannel* can_type1_channel_M1_C1;

/* ...  service variables for the RTICAN status block */
can_tp1_canService* can_type1_service_M1_C1[13];

/* declare pointers to CAN message structures for support of TX-Custom code */
can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C2_STD;
can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C2_XTD;

/* declare pointers to CAN message structures for support of TX-Custom code */
can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C1_STD;
can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C1_XTD;

/* ... definition of message variable for the RTICAN blocks */
can_tp1_canMsg* can_type1_msg_M1[CANTP1_M1_NUMMSG];

/* dSPACE I/O Board RTICAN_GLOBAL #0 */

/* ===== Definition of interface functions for simulation engine =========== */
#ifdef MULTITASKING
# define dsIsSampleHit(RTM,sti)        rtmGetSampleHitPtr(RTM)[sti]
#else
# define dsIsSampleHit(RTM,sti)        rtmIsSampleHit(RTM,sti,0)
#endif

#if defined(_INLINE)
# define __INLINE                      static inline
#else
# define __INLINE                      static
#endif

static void rti_mdl_initialize_host_services(void)
{
  ts_timestamp_type ts = { 0, 0 };

  host_service(1, &ts);
  DsDaq_Init(0, 32, 1);
}

static void rti_mdl_initialize_io_boards(void)
{
  /* Registering of RTI products and modules at VCM */
  {
    vcm_module_register(VCM_MID_RTI1401, (void *) 0,
                        VCM_TXT_RTI1401, 7, 2, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);

    {
      vcm_module_descriptor_type* msg_mod_ptr;
      msg_mod_ptr = vcm_module_register(VCM_MID_MATLAB, (void *) 0,
        VCM_TXT_MATLAB, 8, 0, 0,
        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_SIMULINK, msg_mod_ptr,
                          VCM_TXT_SIMULINK, 8, 0, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_RTW, msg_mod_ptr,
                          VCM_TXT_RTW, 8, 3, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW, msg_mod_ptr,
                          VCM_TXT_STATEFLOW, 8, 0, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW_CODER, msg_mod_ptr,
                          VCM_TXT_STATEFLOW_CODER, 8, 3, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
    }

    vcm_module_register(VCM_MID_RTICAN, (void *) 0,
                        VCM_TXT_RTICAN, 3, 2, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
  }

  /* dSPACE I/O Board DS1401STDADCT4 #1 */
  adc_tp4_init(ADC_TP4_1_MODULE_ADDR);

  /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC */
  adc_tp4_single_init(ADC_TP4_1_MODULE_ADDR,
                      ADC_TP4_CH1,
                      ADC_TP4_TRIG_SW,
                      0.0);
  adc_tp4_single_init(ADC_TP4_1_MODULE_ADDR,
                      ADC_TP4_CH2,
                      ADC_TP4_TRIG_SW,
                      0.0);
  adc_tp4_single_init(ADC_TP4_1_MODULE_ADDR,
                      ADC_TP4_CH3,
                      ADC_TP4_TRIG_SW,
                      0.0);
  adc_tp4_single_init(ADC_TP4_1_MODULE_ADDR,
                      ADC_TP4_CH4,
                      ADC_TP4_TRIG_SW,
                      0.0);
  adc_tp4_single_init(ADC_TP4_1_MODULE_ADDR,
                      ADC_TP4_CH5,
                      ADC_TP4_TRIG_SW,
                      0.0);
  adc_tp4_single_init(ADC_TP4_1_MODULE_ADDR,
                      ADC_TP4_CH6,
                      ADC_TP4_TRIG_SW,
                      0.0);
  adc_tp4_single_init(ADC_TP4_1_MODULE_ADDR,
                      ADC_TP4_CH7,
                      ADC_TP4_TRIG_SW,
                      0.0);
  adc_tp4_single_init(ADC_TP4_1_MODULE_ADDR,
                      ADC_TP4_CH8,
                      ADC_TP4_TRIG_SW,
                      0.0);
  adc_tp4_single_init(ADC_TP4_1_MODULE_ADDR,
                      ADC_TP4_CH9,
                      ADC_TP4_TRIG_SW,
                      0.0);

  /* dSPACE I/O Board DS1401STDDIOT4 #1 */
  /* main init for DIO TP4 module 1 */
  dio_tp4_init(DIO_TP4_1_MODULE_ADDR);

  /* dSPACE I/O Board DS1401STDDIOT4 #1 Unit:BITINCH */
  dio_tp4_digin_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH1);
  dio_tp4_digin_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH10);
  dio_tp4_digin_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH2);
  dio_tp4_digin_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH3);
  dio_tp4_digin_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH4);
  dio_tp4_digin_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH5);
  dio_tp4_digin_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH6);
  dio_tp4_digin_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH7);
  dio_tp4_digin_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH8);
  dio_tp4_digin_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH9);

  /* dSPACE I/O Board DS1401STDDIOT4 #1 Unit:ENC */
  DioTp4EncCount[(1 - 1)]++;
  DioTp4EncNo[(1 - 1)][(1 - 1)][(11 - 1)] = DioTp4EncCount[(1 - 1)];

  /* encoder measurement setup for channel 11 on port 1 */
  dio_tp4_enc_init(DIO_TP4_1_MODULE_ADDR, 1, 11, DioTp4EncNo[(1 - 1)][(1 - 1)]
                   [(11 - 1)], 7, DIO_TP4_ENC_INDEX_DISABLE, 0, 0, -2097152,
                   2.09715175E+6, 0);
  DioTp4EncCount[(1 - 1)]++;
  DioTp4EncNo[(1 - 1)][(2 - 1)][(1 - 1)] = DioTp4EncCount[(1 - 1)];

  /* encoder measurement setup for channel 1 on port 2 */
  dio_tp4_enc_init(DIO_TP4_1_MODULE_ADDR, 2, 1, DioTp4EncNo[(1 - 1)][(2 - 1)][(1
    - 1)], 7, DIO_TP4_ENC_INDEX_DISABLE, 0, 0, -2097152, 2.09715175E+6, 0);

  /* setup the interrupt generation of DIO Type4 module on channel 1 of port 2 */
  dio_tp4_multi_source_int_mode_set(DIO_TP4_1_MODULE_ADDR, 2, 1, 3, 3);
  DioTp4EncCount[(1 - 1)]++;
  DioTp4EncNo[(1 - 1)][(2 - 1)][(4 - 1)] = DioTp4EncCount[(1 - 1)];

  /* encoder measurement setup for channel 4 on port 2 */
  dio_tp4_enc_init(DIO_TP4_1_MODULE_ADDR, 2, 4, DioTp4EncNo[(1 - 1)][(2 - 1)][(4
    - 1)], 7, DIO_TP4_ENC_INDEX_DISABLE, 0, 0, -2097152, 2.09715175E+6, 0);

  /* dSPACE I/O Board DS1401STDDIOT4 #1 Unit:DIGOUT */
  /* PWM generation setup for channel 1 on port 1 */
  dio_tp4_pwm_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH1, 1, 1,
                   DIO_TP4_TIMING_RANGE1, DIO_TP4_PWM);

  /* PWM generation setup for channel 2 on port 1 */
  dio_tp4_pwm_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH2, 1, 1,
                   DIO_TP4_TIMING_RANGE1, DIO_TP4_PWM);

  /* PWM generation setup for channel 3 on port 1 */
  dio_tp4_pwm_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH3, 1, 1,
                   DIO_TP4_TIMING_RANGE1, DIO_TP4_PWM);

  /* PWM generation setup for channel 4 on port 1 */
  dio_tp4_pwm_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH4, 1, 1,
                   DIO_TP4_TIMING_RANGE1, DIO_TP4_PWM);

  /* PWM generation setup for channel 5 on port 1 */
  dio_tp4_pwm_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH5, 1, 1,
                   DIO_TP4_TIMING_RANGE1, DIO_TP4_PWM);

  /* setup digital output mode (supply rails) for channel 10 on port 1 */
  dio_tp4_digout_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH10, 1, 1);

  /* setup digital output mode (supply rails) for channel 11 on port 1 */
  dio_tp4_digout_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH11, 1, 1);

  /* setup digital output mode (supply rails) for channel 12 on port 1 */
  dio_tp4_digout_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH12, 1, 1);

  /* setup digital output mode (supply rails) for channel 6 on port 1 */
  dio_tp4_digout_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH6, 1, 1);

  /* setup digital output mode (supply rails) for channel 7 on port 1 */
  dio_tp4_digout_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH7, 1, 1);

  /* setup digital output mode (supply rails) for channel 8 on port 1 */
  dio_tp4_digout_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH8, 1, 1);

  /* setup digital output mode (supply rails) for channel 9 on port 1 */
  dio_tp4_digout_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH9, 1, 1);

  /* dSPACE I/O Board DS1401STDAIOT1 #1 */
  /* main init for AIOTP1 Module 1*/
  aio_tp1_init(AIO_TP1_1_MODULE_ADDR);

  /* dSPACE I/O Board DS1401STDAIOT1 #1 Unit:DAC */
  /* main init for DAC Unit of AIOTP1 Module 1 */
  aio_tp1_dac_init(AIO_TP1_1_MODULE_ADDR);
  aio_tp1_dac_channel_control(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CTRL_CH1|
    AIO_TP1_DAC_CTRL_CH2|AIO_TP1_DAC_CTRL_CH3|AIO_TP1_DAC_CTRL_CH4,
    AIO_TP1_DAC_CHANNEL_ENABLE);

  /* dSPACE I/O Board DS1401BASEII #1 Unit:REMOTEIN */
  ds1401_remote_in_init();

  /* dSPACE I/O Board DS1401BASE #1 Unit:POWER */
  ds1401_power_hold_on();              /* MABX ignore signal KL15 */

  /* dSPACE I/O Board DSFLASH #1 */
  {
    /* dSPACE I/O Board DSFLASH #1 Unit:SETUP */
    /* This part of code has been generated from the block: */
    /* DSFLASH initialization function */
    UInt16 number_of_flash_blocks= 4;
    UInt8 number_of_flash_blocks_flrec_header = 1;

    /* read value from the edit field */
    /* could be between 4 ...53 DS1401 */
    /* could be between 4 ...62 DS1005 */
    UInt8 indexflrec= 4;

    /* Enable non-volatile data feature */
    if (1) {
      /* initialize NVRAM DATA Flash area */
      dsnvdata_init();

      /* this function decrease the numbre of free blocks with 1 */
    }

    /* Enable flight recorder feature */
    if (0) {
      /* check if the flight recorder was initialized */
      if (ds1401_flash_handle.flight_rec_start_data[indexflrec] !=
          DSFLASH_BLOCK_USAGE_FREE ) {
        /* the simulation was executed more than one time */
        /* read from flash memory the value of blocks     */
        number_of_flash_blocks= ds1401_flash_handle.number_of_blocks;
      } else {
        /* the simulation it's execute for first time */
        /* minimum 4 block = the number available     */
        if (1) {
          number_of_flash_blocks = ds1401_flash_handle.number_of_free_blocks;
          if (ds1401_flash_handle.flight_rec_start_block ==
              DSFLASH_BLOCK_USAGE_FREE) {
            number_of_flash_blocks -= number_of_flash_blocks_flrec_header;
          }
        } else {
          /* the value 13 it's checked in SLGUI file for minimum 4 */
          number_of_flash_blocks = 13 / 0.25;
        }
      }

      dsflrec_initialize(1, number_of_flash_blocks);
    }
  }

  /* dSPACE I/O Board DSFLASH #1 Unit:NVDATASTORE */
  State_NVData_Odometer = 0;

  /* dSPACE I/O Board DS1_RTICAN #1 */
  /* Initialization of DS1501 board */
  can_tp1_communication_init(can_tp1_address_table[0].module_addr,
    CAN_TP1_INT_ENABLE);

  /* dSPACE RTICAN MASTER SETUP Block */
  /* ... Initialize the CAN communication: 1000 kbit/s */
  can_type1_channel_M1_C2 = can_tp1_channel_init(can_tp1_address_table[0].
    module_addr, 1, (1000 * 1000), CAN_TP1_STD, CAN_TP1_NO_SUBINT);
  can_tp1_channel_termination_set(can_type1_channel_M1_C2,
    CAN_TP1_TERMINATION_ON);

  /* ... Initialize TX message structs for custom code  */
  CANTP1_TX_SPMSG_M1_C2_STD = can_tp1_msg_tx_register(can_type1_channel_M1_C2, 3,
    1050, CAN_TP1_STD, CAN_TP1_TIMECOUNT_INFO | CAN_TP1_DELAYCOUNT_INFO |
    CAN_TP1_MSG_INFO, CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG,
    CAN_TP1_TIMEOUT_NORMAL);
  CANTP1_TX_SPMSG_M1_C2_XTD = can_tp1_msg_tx_register(can_type1_channel_M1_C2, 3,
    1100, CAN_TP1_EXT, CAN_TP1_TIMECOUNT_INFO | CAN_TP1_DELAYCOUNT_INFO |
    CAN_TP1_MSG_INFO, CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG,
    CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN MASTER SETUP Block */
  /* ... Initialize the Partial Networking Settings */

  /* dSPACE RTICAN TX Message Block: "TX Message Controller 2" Id:107 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X6B] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C2, 0, 107, CAN_TP1_STD, (CAN_TP1_TIMECOUNT_INFO|
      CAN_TP1_TIMECOUNT_INFO), CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG,
     CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN RX Message Block: "RX Message Controller 1" Id:115 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_RX_STD_0X73] = can_tp1_msg_rx_register
    (can_type1_channel_M1_C2, 2, 115, CAN_TP1_STD, (CAN_TP1_DATA_INFO|
      CAN_TP1_DATA_INFO|CAN_TP1_TIMECOUNT_INFO), CAN_TP1_NO_SUBINT);

  /* dSPACE RTICAN Status block */
  /* ... Register employed functions */
  can_type1_service_M1_C2[CANTP1_M1_C2_Status] = can_tp1_service_register
    (can_type1_channel_M1_C2,CAN_TP1_SERVICE_BUSSTATUS);
  can_type1_service_M1_C2[CANTP1_M1_C2_AckErrors] = can_tp1_service_register
    (can_type1_channel_M1_C2,CAN_TP1_SERVICE_ACK_ERR);

  /* dSPACE RTICAN MASTER SETUP Block */
  /* ... Initialize the CAN communication: 1000 kbit/s */
  can_type1_channel_M1_C1 = can_tp1_channel_init(can_tp1_address_table[0].
    module_addr, 0, (1000 * 1000), CAN_TP1_STD, CAN_TP1_NO_SUBINT);
  can_tp1_channel_termination_set(can_type1_channel_M1_C1,
    CAN_TP1_TERMINATION_ON);

  /* ... Initialize TX message structs for custom code  */
  CANTP1_TX_SPMSG_M1_C1_STD = can_tp1_msg_tx_register(can_type1_channel_M1_C1, 3,
    1050, CAN_TP1_STD, CAN_TP1_TIMECOUNT_INFO | CAN_TP1_DELAYCOUNT_INFO |
    CAN_TP1_MSG_INFO, CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG,
    CAN_TP1_TIMEOUT_NORMAL);
  CANTP1_TX_SPMSG_M1_C1_XTD = can_tp1_msg_tx_register(can_type1_channel_M1_C1, 3,
    1100, CAN_TP1_EXT, CAN_TP1_TIMECOUNT_INFO | CAN_TP1_DELAYCOUNT_INFO |
    CAN_TP1_MSG_INFO, CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG,
    CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN MASTER SETUP Block */
  /* ... Initialize the Partial Networking Settings */

  /* dSPACE RTICAN TX Message Block: "TX Message Controller 2" Id:108 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X6C] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C1, 1, 108, CAN_TP1_STD, (CAN_TP1_TIMECOUNT_INFO|
      CAN_TP1_TIMECOUNT_INFO), CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG,
     CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN RX Message Block: "RX Message Controller 1" Id:116 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X74] = can_tp1_msg_rx_register
    (can_type1_channel_M1_C1, 3, 116, CAN_TP1_STD, (CAN_TP1_DATA_INFO|
      CAN_TP1_DATA_INFO|CAN_TP1_TIMECOUNT_INFO), CAN_TP1_NO_SUBINT);

  /* dSPACE RTICAN Status block */
  /* ... Register employed functions */
  can_type1_service_M1_C1[CANTP1_M1_C1_Status] = can_tp1_service_register
    (can_type1_channel_M1_C1,CAN_TP1_SERVICE_BUSSTATUS);
  can_type1_service_M1_C1[CANTP1_M1_C1_RXLost] = can_tp1_service_register
    (can_type1_channel_M1_C1,CAN_TP1_SERVICE_RX_LOST);
  can_type1_service_M1_C1[CANTP1_M1_C1_DataLost] = can_tp1_service_register
    (can_type1_channel_M1_C1,CAN_TP1_SERVICE_DATA_LOST);
  can_type1_service_M1_C1[CANTP1_M1_C1_RXOK] = can_tp1_service_register
    (can_type1_channel_M1_C1,CAN_TP1_SERVICE_RX_OK);

  /* dSPACE RTICAN RX Message Block: "RX Message Controller 1" Id:115 */
  Kensei150401_B.SFunction1_o4 = 0;    /* processed - flag */
  Kensei150401_B.SFunction1_o5 = 0;    /* deltatime */

  /* dSPACE RTICAN TX Message Block: "TX Message Controller 2" Id:107 */
  /* Messages with timestamp zero have been received in pause/stop state
     and must not be handled.
   */
  if (can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X6B]->timestamp > 0.0) {
    Kensei150401_B.SFunction1_o1_c = 0;/* processed - flag */
    Kensei150401_B.SFunction1_o2_d = 0;/* deltatime */
  }

  /* dSPACE RTICAN RX Message Block: "RX Message Controller 1" Id:116 */
  Kensei150401_B.SFunction1_o4_m = 0;  /* processed - flag */
  Kensei150401_B.SFunction1_o5_i = 0;  /* deltatime */

  /* dSPACE RTICAN TX Message Block: "TX Message Controller 2" Id:108 */
  /* Messages with timestamp zero have been received in pause/stop state
     and must not be handled.
   */
  if (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X6C]->timestamp > 0.0) {
    Kensei150401_B.SFunction1_o1_d = 0;/* processed - flag */
    Kensei150401_B.SFunction1_o2_nb = 0;/* deltatime */
  }

  /* dSPACE I/O Board RTICAN_GLOBAL #0 */
}

static void rti_mdl_slave_load(void)
{
  /* dSPACE I/O Board 1401stdasertp1 #1 Unit:GENSER Group:SETUP */
  rti1401stdasertp1_B1_Ser[0] = dsser_init(can_tp1_address_table[0].module_addr,
    0,64);
  dsser_config(rti1401stdasertp1_B1_Ser[0],1, 9600, 8, DSSER_1_STOPBIT,
               DSSER_NO_PARITY, DSSER_1_BYTE_TRIGGER_LEVEL,0, (DSSER_RS232 |
    DSSER_AUTOFLOW_DISABLE));
  RTLIB_SLAVE_LOAD_ACKNOWLEDGE();
}

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

static void rti_mdl_initialize_io_units(void)
{
  /* dSPACE I/O Board DS1401STDDIOT4 #1 Unit:DIGOUT */
  /* write initial values of PWM Period and DutyCycle for output channel 1 on port 1 */
  dio_tp4_pwm_update(DIO_TP4_1_MODULE_ADDR, 1, 1, (dsfloat) 5.0E-5, (dsfloat) 0);

  /* write initial values of PWM Period and DutyCycle for output channel 2 on port 1 */
  dio_tp4_pwm_update(DIO_TP4_1_MODULE_ADDR, 1, 2, (dsfloat) 5.0E-5, (dsfloat) 0);

  /* re-adjustment: PWM generation setup for channel 3 on port 1 */
  dio_tp4_pwm_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH3, 1, 1,
                   DIO_TP4_TIMING_RANGE1, DIO_TP4_PWM);

  /* write initial values of PWM Period and DutyCycle for output channel 3 on port 1 */
  dio_tp4_pwm_update(DIO_TP4_1_MODULE_ADDR , 1, 3, (dsfloat) 5.0E-5, (dsfloat) 0);

  /* re-adjustment: PWM generation setup for channel 4 on port 1 */
  dio_tp4_pwm_init(DIO_TP4_1_MODULE_ADDR, 1, DIO_TP4_MASK_CH4, 1, 1,
                   DIO_TP4_TIMING_RANGE1, DIO_TP4_PWM);

  /* write initial values of PWM Period and DutyCycle for output channel 4 on port 1 */
  dio_tp4_pwm_update(DIO_TP4_1_MODULE_ADDR , 1, 4, (dsfloat) 5.0E-5, (dsfloat) 0);

  /* write initial values of PWM Period and DutyCycle for output channel 5 on port 1 */
  dio_tp4_pwm_update(DIO_TP4_1_MODULE_ADDR, 1, 5, (dsfloat) 5.0E-5, (dsfloat) 0);

  /* write initialization value to digital output channel 10 on port 1 */
  dio_tp4_digout_write(DIO_TP4_1_MODULE_ADDR , 1, DIO_TP4_MASK_CH10, (UInt16) 0);

  /* write initialization value to digital output channel 11 on port 1 */
  dio_tp4_digout_write(DIO_TP4_1_MODULE_ADDR , 1, DIO_TP4_MASK_CH11, (UInt16) 0);

  /* write initialization value to digital output channel 12 on port 1 */
  dio_tp4_digout_write(DIO_TP4_1_MODULE_ADDR , 1, DIO_TP4_MASK_CH12, (UInt16)
                       2048);

  /* write initialization value to digital output channel 6 on port 1 */
  dio_tp4_digout_write(DIO_TP4_1_MODULE_ADDR , 1, DIO_TP4_MASK_CH6, (UInt16) 0);

  /* write initialization value to digital output channel 7 on port 1 */
  dio_tp4_digout_write(DIO_TP4_1_MODULE_ADDR , 1, DIO_TP4_MASK_CH7, (UInt16) 0);

  /* write initialization value to digital output channel 8 on port 1 */
  dio_tp4_digout_write(DIO_TP4_1_MODULE_ADDR , 1, DIO_TP4_MASK_CH8, (UInt16) 0);

  /* write initialization value to digital output channel 9 on port 1 */
  dio_tp4_digout_write(DIO_TP4_1_MODULE_ADDR , 1, DIO_TP4_MASK_CH9, (UInt16) 0);

  /* dSPACE I/O Board DS1401STDDIOT4 #1 Unit:DIGOUT Group:PWM */
  /* enable all digital output ports (no port wise Dis-Enabling supported) */
  /* called once per module for all dig output ports */
  dio_tp4_digout_mode_set(DIO_TP4_1_MODULE_ADDR, DIO_TP4_DIGOUT_ENABLE);

  /* dSPACE I/O Board DS1401STDAIOT1 #1 Unit:DAC */
  /* enable channels 1-4*/
  aio_tp1_dac_channel_control(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CTRL_CH1|
    AIO_TP1_DAC_CTRL_CH2|AIO_TP1_DAC_CTRL_CH3|AIO_TP1_DAC_CTRL_CH4,
    AIO_TP1_DAC_CHANNEL_ENABLE);

  /* write initial value of DAC for output channels 1-4 synchronous*/
  /*write to buffer*/
  aio_tp1_dac_buffer_write(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CH1, 0.0);
  aio_tp1_dac_buffer_write(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CH2, 0.0);
  aio_tp1_dac_buffer_write(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CH3, 0.0);
  aio_tp1_dac_buffer_write(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CH4, 0.0);

  /*release buffer*/
  aio_tp1_dac_buffer_release(AIO_TP1_1_MODULE_ADDR, AIO_TP1_DAC_CTRL_CH1|
    AIO_TP1_DAC_CTRL_CH2|AIO_TP1_DAC_CTRL_CH3|AIO_TP1_DAC_CTRL_CH4);

  /* dSPACE I/O Board DSFLASH #1 */
  {
    /* dSPACE I/O Board DSFLASH #1 Unit:SETUP */
    /* Enable non-volatile data feature */
    if (1) {
      /* reinitialize NVRAM DATA Flash area                                       */
      dsnvdata_reinit();
    }
  }

  /* dSPACE I/O Board DSFLASH #1 Unit:NVDATARESTORE */
  {
    /* dSPACE I/O Board DSFLASH -- read from flash memory Odometer          */
    /*--------------------------------------------------------------------------*/
    char NameNvVar[DSNVDATA_ENTRY_IDENTIFIER_LENGTH+1] = "Odometer";

    /* data default declaration */
    /*--------------------------*/
    dsfloat default_Odometer[1] = { 0 };

    /* call function to read data */
    /*----------------------------*/
    Kensei150401_B.SFunction1_o2_hn = dsnvdata_read(&NameNvVar[0], (void*)
      &Kensei150401_B.SFunction1_o1_f, 1*sizeof(real_T), (void*)
      &(default_Odometer[0]));

    /* Store pointer of init values */
    Addr_Odometer = (UInt32) &Kensei150401_B.SFunction1_o1_f;
  }

  /* dSPACE I/O Board 1401stdasertp1 #1 Unit:GENSER Group:SETUP */
  dsser_enable(rti1401stdasertp1_B1_Ser[0]);

  /* dSPACE I/O Board DS1_RTICAN #1 */
  /* Start CAN controller */
  can_tp1_channel_start(can_type1_channel_M1_C2, CAN_TP1_INT_ENABLE);

  /* Start CAN controller */
  can_tp1_channel_start(can_type1_channel_M1_C1, CAN_TP1_INT_ENABLE);

  /* Set the type1CAN error level */
  rtican_type1_error_level = 0;

  /* ... Reset all taskqueue-specific error variables */
  rtican_type1_tq_err_all_reset(0);

  /* ... Clear all message data buffers */
  can_tp1_all_data_clear(can_tp1_address_table[0].module_addr);

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][0] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X6B])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  /* dSPACE RTICAN TX Message Block: "TX Message Controller 2" Id:107 */
  /* ... Send initial message  */
  {
    UInt32 CAN_Msg[8] = { 0x37, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    while ((rtican_type1_tq_error[0][0] = can_tp1_msg_send
            (can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X6B], 1, &(CAN_Msg[0]), 0.0))
           == DSMCOM_BUFFER_OVERFLOW) ;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][2] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_RX_STD_0X73])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][1] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X6C])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  /* dSPACE RTICAN TX Message Block: "TX Message Controller 2" Id:108 */
  /* ... Send initial message  */
  {
    UInt32 CAN_Msg[8] = { 0x37, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    while ((rtican_type1_tq_error[0][1] = can_tp1_msg_send
            (can_type1_msg_M1[CANTP1_M1_C1_TX_STD_0X6C], 1, &(CAN_Msg[0]), 0.0))
           == DSMCOM_BUFFER_OVERFLOW) ;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][3] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X74])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }
}

/* Function rti_mdl_acknowledge_interrupts() is empty */
#define rti_mdl_acknowledge_interrupts()

/* Function rti_mdl_timetables_register() is empty */
#define rti_mdl_timetables_register()

/* Function rti_mdl_timesync_simstate() is empty */
#define rti_mdl_timesync_simstate()

/* Function rti_mdl_timesync_baserate() is empty */
#define rti_mdl_timesync_baserate()

static void rti_mdl_background(void)
{
  /* DsDaq background call */
  DsDaq_Background(0);

  /* dSPACE I/O Board DS1_RTICAN #1 */
  {
    real_T bg_code_exec_time;
    static real_T bg_code_last_exec_time = 0.0;
    bg_code_exec_time = RTLIB_TIC_READ();
    if ((bg_code_exec_time - bg_code_last_exec_time) > 0.25 ||
        (bg_code_exec_time - bg_code_last_exec_time) < 0) {
      /* ... Check taskqueue-specific error variables */
      rtican_type1_tq_err_all_chk(can_tp1_address_table[0].module_addr, 0);
      bg_code_last_exec_time = bg_code_exec_time;
    }
  }

  /* copy DPMEM - buffers in background */
  {
    /* call update function for CAN Tp1 CAN interface (module number: 1) */
    can_tp1_msg_copy_all_to_mem(can_tp1_address_table[0].module_addr);
  }
}

__INLINE void rti_mdl_sample_input(void)
{
  /* Calls for base sample time: [0.001, 0] */
  /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC */

  /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
  adc_tp4_sw_trigger(ADC_TP4_1_MODULE_ADDR, ADC_TP4_CONV_START_1|
                     ADC_TP4_CONV_START_2|ADC_TP4_CONV_START_3|
                     ADC_TP4_CONV_START_4|ADC_TP4_CONV_START_5|
                     ADC_TP4_CONV_START_6|ADC_TP4_CONV_START_7|
                     ADC_TP4_CONV_START_8|ADC_TP4_CONV_START_9);

  /* dSPACE I/O Board DS1401STDDIOT4 #1 Unit:BITINCH */
  {
    /* get digital signal state on channel 1 on port 1 */
    UInt16 inputValue = dio_tp4_digin_read(DIO_TP4_1_MODULE_ADDR, 1,
      DIO_TP4_MASK_CH1);
    Kensei150401_B.SFunction1_a = (boolean_T) (inputValue >> (1 - 1));
  }

  {
    /* get digital signal state on channel 10 on port 1 */
    UInt16 inputValue = dio_tp4_digin_read(DIO_TP4_1_MODULE_ADDR, 1,
      DIO_TP4_MASK_CH10);
    Kensei150401_B.SFunction1_aj = (boolean_T) (inputValue >> (10 - 1));
  }

  {
    /* get digital signal state on channel 2 on port 1 */
    UInt16 inputValue = dio_tp4_digin_read(DIO_TP4_1_MODULE_ADDR, 1,
      DIO_TP4_MASK_CH2);
    Kensei150401_B.SFunction1_p = (boolean_T) (inputValue >> (2 - 1));
  }

  {
    /* get digital signal state on channel 3 on port 1 */
    UInt16 inputValue = dio_tp4_digin_read(DIO_TP4_1_MODULE_ADDR, 1,
      DIO_TP4_MASK_CH3);
    Kensei150401_B.SFunction1_e0 = (boolean_T) (inputValue >> (3 - 1));
  }

  {
    /* get digital signal state on channel 4 on port 1 */
    UInt16 inputValue = dio_tp4_digin_read(DIO_TP4_1_MODULE_ADDR, 1,
      DIO_TP4_MASK_CH4);
    Kensei150401_B.SFunction1_p3 = (boolean_T) (inputValue >> (4 - 1));
  }

  {
    /* get digital signal state on channel 5 on port 1 */
    UInt16 inputValue = dio_tp4_digin_read(DIO_TP4_1_MODULE_ADDR, 1,
      DIO_TP4_MASK_CH5);
    Kensei150401_B.SFunction1_l = (boolean_T) (inputValue >> (5 - 1));
  }

  {
    /* get digital signal state on channel 6 on port 1 */
    UInt16 inputValue = dio_tp4_digin_read(DIO_TP4_1_MODULE_ADDR, 1,
      DIO_TP4_MASK_CH6);
    Kensei150401_B.SFunction1_b = (boolean_T) (inputValue >> (6 - 1));
  }

  {
    /* get digital signal state on channel 7 on port 1 */
    UInt16 inputValue = dio_tp4_digin_read(DIO_TP4_1_MODULE_ADDR, 1,
      DIO_TP4_MASK_CH7);
    Kensei150401_B.SFunction1_fy = (boolean_T) (inputValue >> (7 - 1));
  }

  {
    /* get digital signal state on channel 8 on port 1 */
    UInt16 inputValue = dio_tp4_digin_read(DIO_TP4_1_MODULE_ADDR, 1,
      DIO_TP4_MASK_CH8);
    Kensei150401_B.SFunction1_n = (boolean_T) (inputValue >> (8 - 1));
  }

  {
    /* get digital signal state on channel 9 on port 1 */
    UInt16 inputValue = dio_tp4_digin_read(DIO_TP4_1_MODULE_ADDR, 1,
      DIO_TP4_MASK_CH9);
    Kensei150401_B.SFunction1_c0 = (boolean_T) (inputValue >> (9 - 1));
  }

  /* dSPACE I/O Board DS1401STDDIOT4 #1 Unit:ENC */
  {
    /* get encoder data position and speed from encoder channel DioTp4EncNo[(1 - 1)][(1 - 1)][(11 - 1)] */
    dio_tp4_enc_read (DIO_TP4_1_MODULE_ADDR, DioTp4EncNo[(1 - 1)][(1 - 1)][(11 -
      1)], (real_T*) &Kensei150401_B.SFunction1_o1, (real_T*)
                      &Kensei150401_B.SFunction1_o2);
  }

  {
    /* get encoder data position and speed from encoder channel DioTp4EncNo[(1 - 1)][(2 - 1)][(1 - 1)] */
    dio_tp4_enc_read (DIO_TP4_1_MODULE_ADDR, DioTp4EncNo[(1 - 1)][(2 - 1)][(1 -
      1)], (real_T*) &Kensei150401_B.SFunction1_o1_k, (real_T*)
                      &Kensei150401_B.SFunction1_o2_j);
  }

  {
    /* get encoder data position and speed from encoder channel DioTp4EncNo[(1 - 1)][(2 - 1)][(4 - 1)] */
    dio_tp4_enc_read (DIO_TP4_1_MODULE_ADDR, DioTp4EncNo[(1 - 1)][(2 - 1)][(4 -
      1)], (real_T*) &Kensei150401_B.SFunction1_o1_o, (real_T*)
                      &Kensei150401_B.SFunction1_o2_n);
  }

  /* dSPACE I/O Board DS1401BASEII #1 Unit:REMOTEIN */
  {
    UInt16 inputValue = ds1401_remote_in_read();
    if (SYS1401_REMOTE_IN_CONNECTED == inputValue) {
      Kensei150401_B.SFunction1_o1_c0 = (boolean_T) (SYS1401_REMOTE_IN_CONNECTED);
      Kensei150401_B.SFunction1_o2_l = (boolean_T)
        (SYS1401_REMOTE_IN_NOT_CONNECTED);
    } else {
      Kensei150401_B.SFunction1_o1_c0 = (boolean_T)
        (SYS1401_REMOTE_IN_NOT_CONNECTED);
      Kensei150401_B.SFunction1_o2_l = (boolean_T) (SYS1401_REMOTE_IN_CONNECTED);
    }
  }

  /* dSPACE I/O Board DS1_RTICAN #1 Unit:DEFAULT */
  /* call update function for CAN Tp1 CAN interface (module number: 1) */
  can_tp1_msg_copy_all_to_mem(can_tp1_address_table[0].module_addr);
}

static void rti_mdl_daq_service()
{
  /* dSPACE Host Service */
  host_service(1, rtk_current_task_absolute_time_ptr_get());
  DsDaq_Service(0, 0, 1, (DsDaqSTimestampStruct *)
                rtk_current_task_absolute_time_ptr_get());
}

#undef __INLINE

/****** [EOF] ****************************************************************/
