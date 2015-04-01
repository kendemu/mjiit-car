/*
 * Kensei150401.h
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
#ifndef RTW_HEADER_Kensei150401_h_
#define RTW_HEADER_Kensei150401_h_
#ifndef Kensei150401_COMMON_INCLUDES_
# define Kensei150401_COMMON_INCLUDES_
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
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#endif                                 /* Kensei150401_COMMON_INCLUDES_ */

#include "Kensei150401_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) <= 1)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define Kensei150401_rtModel           RT_MODEL_Kensei150401

/* Block signals (auto storage) */
typedef struct {
  real_T offset;                       /* '<S1>/offset' */
  real_T kmh1;                         /* '<S1>/kmh1' */
  real_T SFunction1;                   /* '<S9>/S-Function1' */
  real_T inADC1;                       /* '<S2>/inADC1' */
  real_T SFunction1_f;                 /* '<S10>/S-Function1' */
  real_T inADC2;                       /* '<S2>/inADC2' */
  real_T SFunction1_e;                 /* '<S11>/S-Function1' */
  real_T inADC3;                       /* '<S2>/inADC3' */
  real_T SFunction1_o;                 /* '<S12>/S-Function1' */
  real_T inADC4;                       /* '<S2>/inADC4' */
  real_T SFunction1_os;                /* '<S13>/S-Function1' */
  real_T inADC5;                       /* '<S2>/inADC5' */
  real_T SFunction1_c;                 /* '<S14>/S-Function1' */
  real_T inADC6;                       /* '<S2>/inADC6' */
  real_T SFunction1_cu;                /* '<S15>/S-Function1' */
  real_T inADC7;                       /* '<S2>/inADC7' */
  real_T SFunction1_d;                 /* '<S16>/S-Function1' */
  real_T inADC8;                       /* '<S2>/inADC8' */
  real_T SFunction1_h;                 /* '<S17>/S-Function1' */
  real_T inADC9;                       /* '<S2>/inADC9' */
  real_T SFunction1_o1;                /* '<S28>/S-Function1' */
  real_T SFunction1_o2;                /* '<S28>/S-Function1' */
  real_T SFunction1_o1_k;              /* '<S29>/S-Function1' */
  real_T SFunction1_o2_j;              /* '<S29>/S-Function1' */
  real_T SFunction1_o1_o;              /* '<S30>/S-Function1' */
  real_T SFunction1_o2_n;              /* '<S30>/S-Function1' */
  real_T PC_On_Off_Touch_Button;       /* '<S2>/PC_On_Off_Touch_Button' */
  real_T Touch_Button_Forward_1_Reverse_;/* '<S2>/Touch_Button_Forward_1_Reverse_0' */
  real_T ZPT_Touch_Button;             /* '<S2>/ZPT_Touch_Button' */
  real_T FRwm;                         /* '<S108>/FRwm' */
  real_T Switch_FR;                    /* '<S108>/Switch_FR' */
  real_T MathFunction;                 /* '<S115>/Math Function' */
  real_T MathFunction1;                /* '<S115>/Math Function1' */
  real_T MathFunction2;                /* '<S115>/Math Function2' */
  real_T Sum;                          /* '<S115>/Sum' */
  real_T Divide2;                      /* '<S115>/Divide2' */
  real_T Divide;                       /* '<S115>/Divide' */
  real_T Epsilon;                      /* '<S115>/Epsilon' */
  real_T pulse_to_degree;              /* '<S135>/pulse_to_degree' */
  real_T limitrotationdata;            /* '<S135>/limit rotation data' */
  real_T RoundingFunction2;            /* '<S135>/Rounding Function2' */
  real_T Gain1;                        /* '<S79>/Gain1' */
  real_T UnitDelay;                    /* '<S65>/Unit Delay' */
  real_T Sum_i;                        /* '<S65>/Sum' */
  real_T Divide_a;                     /* '<S46>/Divide' */
  real_T RateTransition;               /* '<S46>/Rate Transition' */
  real_T RateTransition4;              /* '<S46>/Rate Transition4' */
  real_T Counter;                      /* '<S46>/Counter' */
  real_T RateTransition1;              /* '<S46>/Rate Transition1' */
  real_T Switch1;                      /* '<S46>/Switch1' */
  real_T RPSectow;                     /* '<S46>/RPSec to w' */
  real_T ms;                           /* '<S46>/Tyre radius' */
  real_T mstokmh;                      /* '<S46>/m//s to km//h' */
  real_T Roundedfl_kmh;                /* '<S46>/Rounded fl_kmh' */
  real_T Limit80kmh;                   /* '<S46>/Limit 80km//h' */
  real_T ThrottleMap1;                 /* '<S8>/Throttle Map1' */
  real_T topercent;                    /* '<S8>/to percent' */
  real_T RoundingFunction2_d;          /* '<S8>/Rounding Function2' */
  real_T PedalLimit100;                /* '<S8>/Pedal Limit 100%' */
  real_T Gain1_i;                      /* '<S86>/Gain1' */
  real_T Gain;                         /* '<S86>/Gain' */
  real_T MathFunction1_o;              /* '<S86>/Math Function1' */
  real_T Product;                      /* '<S135>/Product' */
  real_T ratio1;                       /* '<S135>/ratio1' */
  real_T RoundingFunction1;            /* '<S135>/Rounding Function1' */
  real_T ratio2;                       /* '<S135>/ratio2' */
  real_T Gain1_f;                      /* '<S117>/Gain1' */
  real_T Abs;                          /* '<S86>/Abs' */
  real_T tan_d;                        /* '<S86>/tan' */
  real_T Product_l;                    /* '<S86>/Product' */
  real_T MathFunction_l;               /* '<S86>/Math Function' */
  real_T Sum_a;                        /* '<S86>/Sum' */
  real_T R;                            /* '<S86>/R' */
  real_T Sum1;                         /* '<S86>/Sum1' */
  real_T outertyre;                    /* '<S86>/outertyre' */
  real_T Sum2;                         /* '<S86>/Sum2' */
  real_T innertyre;                    /* '<S86>/innertyre ' */
  real_T Gain2;                        /* '<S86>/Gain2' */
  real_T switching;                    /* '<S86>/switching' */
  real_T Gain_e;                       /* '<S118>/Gain' */
  real_T Gain1_h;                      /* '<S91>/Gain1' */
  real_T Abs1;                         /* '<S83>/Abs1' */
  real_T kmhtoms;                      /* '<S87>/km//h to m//s' */
  real_T MathFunction_m;               /* '<S87>/Math Function' */
  real_T Product_o;                    /* '<S87>/Product' */
  real_T Product2;                     /* '<S87>/Product2' */
  real_T Product1;                     /* '<S87>/Product1' */
  real_T Product3;                     /* '<S87>/Product3' */
  real_T Sum_d;                        /* '<S87>/Sum' */
  real_T Product5;                     /* '<S87>/Product5' */
  real_T Product6;                     /* '<S87>/Product6' */
  real_T Product7;                     /* '<S87>/Product7' */
  real_T Product8;                     /* '<S87>/Product8' */
  real_T Sum1_a;                       /* '<S87>/Sum1' */
  real_T K_ratio;                      /* '<S87>/K_ratio' */
  real_T Saturation;                   /* '<S87>/Saturation' */
  real_T Product4;                     /* '<S87>/Product4' */
  real_T ratio1_g;                     /* '<S87>/ratio1' */
  real_T RoundingFunction1_l;          /* '<S87>/Rounding Function1' */
  real_T ratio2_m;                     /* '<S87>/ratio2' */
  real_T Gain1_o;                      /* '<S92>/Gain1' */
  real_T Abs_j;                        /* '<S83>/Abs' */
  real_T Lf;                           /* '<S83>/Lf' */
  real_T Rc;                           /* '<S83>/Rc' */
  real_T angle_Fi;                     /* '<S83>/angle_Fi' */
  real_T angle_Fo;                     /* '<S83>/angle_Fo' */
  real_T switching4;                   /* '<S83>/switching4' */
  real_T Gain_h;                       /* '<S96>/Gain' */
  real_T Gain3;                        /* '<S83>/Gain3' */
  real_T switching4_i;                 /* '<S7>/switching4' */
  real_T ratio3;                       /* '<S109>/ratio3' */
  real_T RoundingFunction2_a;          /* '<S109>/Rounding Function2' */
  real_T ratio4;                       /* '<S109>/ratio4' */
  real_T FR_refdegree;                 /* '<S85>/FR_ref degree' */
  real_T Switch2;                      /* '<S85>/Switch2' */
  real_T direction;                    /* '<S115>/direction' */
  real_T degreetorad;                  /* '<S115>/degree to rad' */
  real_T Sum4;                         /* '<S115>/Sum4' */
  real_T Fcn1;                         /* '<S115>/Fcn1' */
  real_T Divide1;                      /* '<S115>/Divide1' */
  real_T Sum3;                         /* '<S115>/Sum3' */
  real_T Sqrt;                         /* '<S115>/Sqrt' */
  real_T Sum2_o;                       /* '<S115>/Sum2' */
  real_T mtomm;                        /* '<S115>/m to mm' */
  real_T FR_Voltpermm2;                /* '<S112>/FR_Volt per mm2' */
  real_T Sum1_o;                       /* '<S112>/Sum1' */
  real_T FR_mmtovolt;                  /* '<S112>/FR_mm to volt' */
  real_T FR_refinputSaturation;        /* '<S85>/FR_ref input Saturation' */
  real_T ratio3_l;                     /* '<S110>/ratio3' */
  real_T RoundingFunction2_n;          /* '<S110>/Rounding Function2' */
  real_T ratio4_j;                     /* '<S110>/ratio4' */
  real_T AnalogFilter_FR_Pos;          /* '<S85>/Analog Filter_FR_Pos' */
  real_T ratio3_c;                     /* '<S111>/ratio3' */
  real_T RoundingFunction2_dz;         /* '<S111>/Rounding Function2' */
  real_T ratio4_g;                     /* '<S111>/ratio4' */
  real_T Sum1_d;                       /* '<S85>/Sum1' */
  real_T Integrator;                   /* '<S107>/Integrator' */
  real_T DerivativeGain;               /* '<S107>/Derivative Gain' */
  real_T Filter;                       /* '<S107>/Filter' */
  real_T SumD;                         /* '<S107>/SumD' */
  real_T FilterCoefficient;            /* '<S107>/Filter Coefficient' */
  real_T Sum_h;                        /* '<S107>/Sum' */
  real_T ProportionalGain;             /* '<S107>/Proportional Gain' */
  real_T Saturation_h;                 /* '<S107>/Saturation' */
  real_T Abs_c;                        /* '<S85>/Abs' */
  real_T Constant;                     /* '<S85>/Constant' */
  real_T Switch1_e;                    /* '<S85>/Switch1' */
  real_T Offset5;                      /* '<S7>/Offset5' */
  real_T Sum5;                         /* '<S7>/Sum5' */
  real_T FLpwm;                        /* '<S98>/FLpwm' */
  real_T MathFunction_o;               /* '<S105>/Math Function' */
  real_T MathFunction1_m;              /* '<S105>/Math Function1' */
  real_T MathFunction2_b;              /* '<S105>/Math Function2' */
  real_T Sum_b;                        /* '<S105>/Sum' */
  real_T Divide2_b;                    /* '<S105>/Divide2' */
  real_T Divide_b;                     /* '<S105>/Divide' */
  real_T Epsilon_d;                    /* '<S105>/Epsilon' */
  real_T Switch1_j;                    /* '<S86>/Switch1' */
  real_T Gain_o;                       /* '<S119>/Gain' */
  real_T switching2;                   /* '<S83>/switching2' */
  real_T Gain_m;                       /* '<S95>/Gain' */
  real_T Gain2_c;                      /* '<S83>/Gain2' */
  real_T switching3;                   /* '<S7>/switching3' */
  real_T ratio3_k;                     /* '<S99>/ratio3' */
  real_T RoundingFunction2_df;         /* '<S99>/Rounding Function2' */
  real_T ratio4_gb;                    /* '<S99>/ratio4' */
  real_T FL_refdegree;                 /* '<S84>/FL_ref degree' */
  real_T Switch2_p;                    /* '<S84>/Switch2' */
  real_T degreetorad_d;                /* '<S105>/degree to rad' */
  real_T Sum4_b;                       /* '<S105>/Sum4' */
  real_T Fcn1_k;                       /* '<S105>/Fcn1' */
  real_T Divide1_p;                    /* '<S105>/Divide1' */
  real_T Sum3_m;                       /* '<S105>/Sum3' */
  real_T Sqrt_h;                       /* '<S105>/Sqrt' */
  real_T Sum2_h;                       /* '<S105>/Sum2' */
  real_T mtomm_k;                      /* '<S105>/m to mm' */
  real_T FL_Voltpermm2;                /* '<S102>/FL_Volt per mm2' */
  real_T Sum1_k;                       /* '<S102>/Sum1' */
  real_T FL_mmtovolt;                  /* '<S102>/FL_mm to volt' */
  real_T FL_refinputSaturation;        /* '<S84>/FL_ref input Saturation' */
  real_T ratio3_h;                     /* '<S100>/ratio3' */
  real_T RoundingFunction2_nv;         /* '<S100>/Rounding Function2' */
  real_T ratio4_j0;                    /* '<S100>/ratio4' */
  real_T AnalogFilter_FL_Pos;          /* '<S84>/Analog Filter_FL_Pos' */
  real_T ratio3_j;                     /* '<S101>/ratio3' */
  real_T RoundingFunction2_e;          /* '<S101>/Rounding Function2' */
  real_T ratio4_p;                     /* '<S101>/ratio4' */
  real_T Sum_o;                        /* '<S84>/Sum' */
  real_T Integrator_k;                 /* '<S97>/Integrator' */
  real_T DerivativeGain_o;             /* '<S97>/Derivative Gain' */
  real_T Filter_e;                     /* '<S97>/Filter' */
  real_T SumD_c;                       /* '<S97>/SumD' */
  real_T FilterCoefficient_n;          /* '<S97>/Filter Coefficient' */
  real_T Sum_f;                        /* '<S97>/Sum' */
  real_T ProportionalGain_l;           /* '<S97>/Proportional Gain' */
  real_T Saturation_f;                 /* '<S97>/Saturation' */
  real_T Abs_g;                        /* '<S84>/Abs' */
  real_T Constant_c;                   /* '<S84>/Constant' */
  real_T Switch1_h;                    /* '<S84>/Switch1' */
  real_T Switch2_l;                    /* '<S98>/Switch2' */
  real_T RealPWMin;                    /* '<S98>/RealPWMin' */
  real_T Offset6;                      /* '<S7>/Offset6' */
  real_T Sum6;                         /* '<S7>/Sum6' */
  real_T RRpwm;                        /* '<S128>/RRpwm' */
  real_T Switch_RR;                    /* '<S128>/Switch_RR' */
  real_T MathFunction_n;               /* '<S132>/Math Function' */
  real_T MathFunction1_l;              /* '<S132>/Math Function1' */
  real_T MathFunction2_c;              /* '<S132>/Math Function2' */
  real_T Sum_m;                        /* '<S132>/Sum' */
  real_T Divide2_l;                    /* '<S132>/Divide2' */
  real_T Divide_p;                     /* '<S132>/Divide' */
  real_T Epsilon_g;                    /* '<S132>/Epsilon' */
  real_T Lr;                           /* '<S83>/Lr' */
  real_T angle_Ri;                     /* '<S83>/angle_Ri' */
  real_T angle_Ro;                     /* '<S83>/angle_Ro' */
  real_T Switch;                       /* '<S89>/Switch' */
  real_T degreetorad_b;                /* '<S132>/degree to rad' */
  real_T Sum4_c;                       /* '<S132>/Sum4' */
  real_T Fcn1_f;                       /* '<S132>/Fcn1' */
  real_T Divide1_k;                    /* '<S132>/Divide1' */
  real_T Sum3_f;                       /* '<S132>/Sum3' */
  real_T Sqrt_n;                       /* '<S132>/Sqrt' */
  real_T Sum2_n;                       /* '<S132>/Sum2' */
  real_T mtomm_g;                      /* '<S132>/m to mm' */
  real_T RR_Voltpermm2;                /* '<S129>/RR_Volt per mm2' */
  real_T Sum1_i;                       /* '<S129>/Sum1' */
  real_T RR_mmtovolt;                  /* '<S129>/RR_mm to volt' */
  real_T RR_refinputSaturation;        /* '<S89>/RR_ref input Saturation' */
  real_T AnalogFilter_RR_Pos;          /* '<S89>/Analog Filter_RR_Pos' */
  real_T Sum1_i0;                      /* '<S89>/Sum1' */
  real_T Integrator_o;                 /* '<S127>/Integrator' */
  real_T DerivativeGain_e;             /* '<S127>/Derivative Gain' */
  real_T Filter_h;                     /* '<S127>/Filter' */
  real_T SumD_g;                       /* '<S127>/SumD' */
  real_T FilterCoefficient_i;          /* '<S127>/Filter Coefficient' */
  real_T Sum_n;                        /* '<S127>/Sum' */
  real_T ProportionalGain_p;           /* '<S127>/Proportional Gain' */
  real_T Saturation_m;                 /* '<S127>/Saturation' */
  real_T Abs_o;                        /* '<S89>/Abs' */
  real_T Constant_j;                   /* '<S89>/Constant' */
  real_T Switch1_i;                    /* '<S89>/Switch1' */
  real_T Switch2_h;                    /* '<S128>/Switch2' */
  real_T RealPWMin_b;                  /* '<S128>/RealPWMin' */
  real_T Offset7;                      /* '<S7>/Offset7' */
  real_T Sum7;                         /* '<S7>/Sum7' */
  real_T RLpwm;                        /* '<S121>/RLpwm' */
  real_T MathFunction_f;               /* '<S125>/Math Function' */
  real_T MathFunction1_l3;             /* '<S125>/Math Function1' */
  real_T MathFunction2_bb;             /* '<S125>/Math Function2' */
  real_T Sum_c;                        /* '<S125>/Sum' */
  real_T Divide2_lb;                   /* '<S125>/Divide2' */
  real_T Divide_bn;                    /* '<S125>/Divide' */
  real_T Epsilon_l;                    /* '<S125>/Epsilon' */
  real_T Switch_h;                     /* '<S88>/Switch' */
  real_T gain;                         /* '<S125>/gain' */
  real_T degreetorad_h;                /* '<S125>/degree to rad' */
  real_T Sum4_n;                       /* '<S125>/Sum4' */
  real_T Fcn1_kl;                      /* '<S125>/Fcn1' */
  real_T Divide1_h;                    /* '<S125>/Divide1' */
  real_T Sum3_k;                       /* '<S125>/Sum3' */
  real_T Sqrt_d;                       /* '<S125>/Sqrt' */
  real_T Sum2_c;                       /* '<S125>/Sum2' */
  real_T mtomm_l;                      /* '<S125>/m to mm' */
  real_T RL_Voltpermm2;                /* '<S122>/RL_Volt per mm2' */
  real_T Sum1_h;                       /* '<S122>/Sum1' */
  real_T RL_mmtovolt;                  /* '<S122>/RL_mm to volt' */
  real_T RL_refinputSaturation;        /* '<S88>/RL_ref input Saturation' */
  real_T AnalogFilter_RL_Pos;          /* '<S88>/Analog Filter_RL_Pos' */
  real_T Sum1_b;                       /* '<S88>/Sum1' */
  real_T Integrator_g;                 /* '<S120>/Integrator' */
  real_T DerivativeGain_eq;            /* '<S120>/Derivative Gain' */
  real_T Filter_o;                     /* '<S120>/Filter' */
  real_T SumD_h;                       /* '<S120>/SumD' */
  real_T FilterCoefficient_o;          /* '<S120>/Filter Coefficient' */
  real_T Sum_k;                        /* '<S120>/Sum' */
  real_T ProportionalGain_a;           /* '<S120>/Proportional Gain' */
  real_T Saturation_fk;                /* '<S120>/Saturation' */
  real_T Abs_p;                        /* '<S88>/Abs' */
  real_T Constant_h;                   /* '<S88>/Constant' */
  real_T Switch1_d;                    /* '<S88>/Switch1' */
  real_T Switch2_k;                    /* '<S121>/Switch2' */
  real_T RealPWMin_f;                  /* '<S121>/RealPWMin' */
  real_T Offset4;                      /* '<S7>/Offset4' */
  real_T Sum8;                         /* '<S7>/Sum8' */
  real_T Gain1_p;                      /* '<S136>/Gain1' */
  real_T FeedbackMapZPT;               /* '<S90>/Feedback Map ZPT' */
  real_T Saturation2;                  /* '<S90>/Saturation2' */
  real_T Gain2_l;                      /* '<S90>/Gain2' */
  real_T Gain3_h;                      /* '<S90>/Gain3' */
  real_T Saturation1;                  /* '<S90>/Saturation1' */
  real_T Switch5;                      /* '<S90>/Switch5' */
  real_T FeedbackMap;                  /* '<S90>/Feedback Map' */
  real_T Saturation_ft;                /* '<S90>/Saturation' */
  real_T Gain1_g;                      /* '<S90>/Gain1' */
  real_T Switch2_n;                    /* '<S90>/Switch2' */
  real_T Abs_h;                        /* '<S90>/Abs' */
  real_T Integrator_p;                 /* '<S146>/Integrator' */
  real_T Switch1_p;                    /* '<S8>/Switch1' */
  real_T Sum_bv;                       /* '<S8>/Sum' */
  real_T Fcn;                          /* '<S8>/Fcn' */
  real_T Product1_l;                   /* '<S8>/Product1' */
  real_T Switch_f;                     /* '<S8>/Switch' */
  real_T Product_d;                    /* '<S8>/Product' */
  real_T Gain1_b;                      /* '<S145>/Gain1' */
  real_T Abs_n;                        /* '<S8>/Abs' */
  real_T Switch5_b;                    /* '<S8>/Switch5' */
  real_T ThrottleMapZPT1;              /* '<S8>/Throttle MapZPT1' */
  real_T PedalLimitzpt2V1;             /* '<S8>/Pedal Limit zpt 2V1' */
  real_T pedalzpt;                     /* '<S8>/Switch3' */
  real_T Add;                          /* '<S8>/Add' */
  real_T to5V1;                        /* '<S8>/0 to 5 V1' */
  real_T Product2_m;                   /* '<S8>/Product2' */
  real_T outDAC2;                      /* '<S3>/outDAC2' */
  real_T OutputLimit05V005CR;          /* '<S3>/Output Limit [0, 5V] = [0, 0.5] C R' */
  real_T outDAC4;                      /* '<S3>/outDAC4' */
  real_T OutputLimit05V005CR2;         /* '<S3>/Output Limit [0, 5V] = [0, 0.5] C R2' */
  real_T outDAC6;                      /* '<S3>/outDAC6' */
  real_T OutputLimit05V005CR1;         /* '<S3>/Output Limit [0, 5V] = [0, 0.5] C R1' */
  real_T outDAC8;                      /* '<S3>/outDAC8' */
  real_T OutputLimit05V005CR3;         /* '<S3>/Output Limit [0, 5V] = [0, 0.5] C R3' */
  real_T Vmin;                         /* '<S44>/Vmin' */
  real_T AnalogFilter_FR_Pos_g;        /* '<S44>/Analog Filter_FR_Pos' */
  real_T Amperevolt;                   /* '<S44>/Ampere//volt' */
  real_T Add_d;                        /* '<S44>/Add' */
  real_T ratio1_gq;                    /* '<S44>/ratio1' */
  real_T RoundingFunction1_b;          /* '<S44>/Rounding Function1' */
  real_T ratio2_j;                     /* '<S44>/ratio2' */
  real_T SFunction1_o1_h;              /* '<S56>/S-Function1' */
  real_T SFunction1_o2_jz;             /* '<S56>/S-Function1' */
  real_T SFunction1_o3;                /* '<S56>/S-Function1' */
  real_T SFunction1_o4;                /* '<S56>/S-Function1' */
  real_T SFunction1_o5;                /* '<S56>/S-Function1' */
  real_T Current;                      /* '<S45>/Current' */
  real_T SFunction1_o1_b;              /* '<S57>/S-Function1' */
  real_T SFunction1_o2_c;              /* '<S57>/S-Function1' */
  real_T SFunction1_o3_m;              /* '<S57>/S-Function1' */
  real_T SFunction1_o4_m;              /* '<S57>/S-Function1' */
  real_T SFunction1_o5_i;              /* '<S57>/S-Function1' */
  real_T Current1;                     /* '<S45>/Current1' */
  real_T Gain_p;                       /* '<S45>/Gain' */
  real_T Gain1_bw;                     /* '<S45>/Gain1' */
  real_T RPM;                          /* '<S45>/RPM' */
  real_T RPM1;                         /* '<S45>/RPM1' */
  real_T TmpSignalConversionAtRoundingFu[2];/* '<S45>/Mux' */
  real_T RPMtoRPSec[2];                /* '<S45>/RPM to RPSec' */
  real_T RPSectow_a[2];                /* '<S45>/RPSec to w' */
  real_T RoundingFunction1_f[2];       /* '<S45>/Rounding Function1' */
  real_T ms_e[2];                      /* '<S45>/Tyre radius' */
  real_T mstokmh_h[2];                 /* '<S45>/m//s to km//h' */
  real_T RoundingFunction2_g[2];       /* '<S45>/Rounding Function2' */
  real_T DataTypeConversion;           /* '<S50>/Data Type  Conversion' */
  real_T DataTypeConversion1;          /* '<S50>/Data Type  Conversion1' */
  real_T DataTypeConversion1_m;        /* '<S51>/Data Type  Conversion1' */
  real_T DataTypeConversion_h;         /* '<S51>/Data Type  Conversion' */
  real_T SFunction1_o1_c;              /* '<S61>/S-Function1' */
  real_T SFunction1_o2_d;              /* '<S61>/S-Function1' */
  real_T SFunction1_o1_d;              /* '<S60>/S-Function1' */
  real_T SFunction1_o2_nb;             /* '<S60>/S-Function1' */
  real_T RPSectow1;                    /* '<S46>/RPSec to w1' */
  real_T RateTransition3;              /* '<S46>/Rate Transition3' */
  real_T pulsestorevolution;           /* '<S46>/pulses to revolution' */
  real_T RPSectow2;                    /* '<S46>/RPSec to w2' */
  real_T ms_d;                         /* '<S46>/Tyre radius2' */
  real_T SFunction1_o1_f;              /* '<S71>/S-Function1' */
  real_T DataTypeConversion2;          /* '<S47>/Data Type  Conversion2' */
  real_T Sum_p;                        /* '<S46>/Sum' */
  real_T Roundedodo1;                  /* '<S46>/Rounded odo1' */
  real_T ms_b;                         /* '<S46>/Tyre radius1' */
  real_T mtokm;                        /* '<S46>/m to km' */
  real_T mstokmh1;                     /* '<S46>/m//s to km//h1' */
  real_T DataTypeConversion1_e;        /* '<S47>/Data Type  Conversion1' */
  real_T DataTypeConversion3;          /* '<S47>/Data Type  Conversion3' */
  real_T PulseGenerator;               /* '<S48>/Pulse Generator' */
  real_T ManualSwitch;                 /* '<S48>/Manual Switch' */
  real_T SineWave;                     /* '<S48>/Sine Wave' */
  real_T IntegralGain;                 /* '<S97>/Integral Gain' */
  real_T SumI2;                        /* '<S97>/SumI2' */
  real_T Kb;                           /* '<S97>/Kb' */
  real_T SumI1;                        /* '<S97>/SumI1' */
  real_T FL_Voltpermm;                 /* '<S103>/FL_Volt per mm' */
  real_T FL_Voltpermm1;                /* '<S103>/FL_Volt per mm1' */
  real_T FL_Voltpermm2_p;              /* '<S103>/FL_Volt per mm2' */
  real_T MathFunction_n0;              /* '<S106>/Math Function' */
  real_T MathFunction1_c;              /* '<S106>/Math Function1' */
  real_T MathFunction2_k;              /* '<S106>/Math Function2' */
  real_T Sum_hh;                       /* '<S106>/Sum' */
  real_T Divide2_d;                    /* '<S106>/Divide2' */
  real_T Divide_c;                     /* '<S106>/Divide' */
  real_T Sum_g;                        /* '<S103>/Sum' */
  real_T Sum2_l;                       /* '<S103>/Sum2' */
  real_T Sum3_d;                       /* '<S103>/Sum3' */
  real_T mmtometer;                    /* '<S106>/mm to meter' */
  real_T Sum2_hw;                      /* '<S106>/Sum2' */
  real_T MathFunction3;                /* '<S106>/Math Function3' */
  real_T Sum1_n;                       /* '<S106>/Sum1' */
  real_T Divide1_g;                    /* '<S106>/Divide1' */
  real_T Epsilon_o;                    /* '<S106>/Epsilon' */
  real_T Fcn1_p;                       /* '<S106>/Fcn1' */
  real_T Sum3_a;                       /* '<S106>/Sum3' */
  real_T radtodegree;                  /* '<S106>/rad to degree' */
  real_T IntegralGain_b;               /* '<S107>/Integral Gain' */
  real_T SumI2_o;                      /* '<S107>/SumI2' */
  real_T Kb_m;                         /* '<S107>/Kb' */
  real_T SumI1_d;                      /* '<S107>/SumI1' */
  real_T FR_Voltpermm;                 /* '<S113>/FR_Volt per mm' */
  real_T FR_Voltpermm1;                /* '<S113>/FR_Volt per mm1' */
  real_T FR_Voltpermm2_h;              /* '<S113>/FR_Volt per mm2' */
  real_T MathFunction_g;               /* '<S116>/Math Function' */
  real_T MathFunction1_g;              /* '<S116>/Math Function1' */
  real_T MathFunction2_n;              /* '<S116>/Math Function2' */
  real_T Sum_l;                        /* '<S116>/Sum' */
  real_T Divide2_b0;                   /* '<S116>/Divide2' */
  real_T Divide_i;                     /* '<S116>/Divide' */
  real_T Sum_e;                        /* '<S113>/Sum' */
  real_T Sum2_e;                       /* '<S113>/Sum2' */
  real_T Sum3_b;                       /* '<S113>/Sum3' */
  real_T mmtometer_i;                  /* '<S116>/mm to meter' */
  real_T Sum2_j;                       /* '<S116>/Sum2' */
  real_T MathFunction3_i;              /* '<S116>/Math Function3' */
  real_T Sum1_ht;                      /* '<S116>/Sum1' */
  real_T Divide1_hh;                   /* '<S116>/Divide1' */
  real_T Epsilon_g4;                   /* '<S116>/Epsilon' */
  real_T Fcn1_n;                       /* '<S116>/Fcn1' */
  real_T Sum3_mb;                      /* '<S116>/Sum3' */
  real_T radtodegree_j;                /* '<S116>/rad to degree' */
  real_T IntegralGain_be;              /* '<S120>/Integral Gain' */
  real_T SumI2_l;                      /* '<S120>/SumI2' */
  real_T Kb_p;                         /* '<S120>/Kb' */
  real_T SumI1_f;                      /* '<S120>/SumI1' */
  real_T RL_Voltpermm;                 /* '<S123>/RL_Volt per mm' */
  real_T RL_Voltpermm1;                /* '<S123>/RL_Volt per mm1' */
  real_T RL_Voltpermm2_i;              /* '<S123>/RL_Volt per mm2' */
  real_T MathFunction_l3;              /* '<S126>/Math Function' */
  real_T MathFunction1_e;              /* '<S126>/Math Function1' */
  real_T MathFunction2_a;              /* '<S126>/Math Function2' */
  real_T Sum_po;                       /* '<S126>/Sum' */
  real_T Divide2_la;                   /* '<S126>/Divide2' */
  real_T Divide_l;                     /* '<S126>/Divide' */
  real_T Sum_fd;                       /* '<S123>/Sum' */
  real_T Sum2_i;                       /* '<S123>/Sum2' */
  real_T Sum3_n;                       /* '<S123>/Sum3' */
  real_T mmtometer_p;                  /* '<S126>/mm to meter' */
  real_T Sum2_g;                       /* '<S126>/Sum2' */
  real_T MathFunction3_h;              /* '<S126>/Math Function3' */
  real_T Sum1_nn;                      /* '<S126>/Sum1' */
  real_T Divide1_a;                    /* '<S126>/Divide1' */
  real_T Epsilon_n;                    /* '<S126>/Epsilon' */
  real_T Fcn1_h;                       /* '<S126>/Fcn1' */
  real_T Sum3_i;                       /* '<S126>/Sum3' */
  real_T radtodegree_p;                /* '<S126>/rad to degree' */
  real_T IntegralGain_e;               /* '<S127>/Integral Gain' */
  real_T SumI2_h;                      /* '<S127>/SumI2' */
  real_T Kb_j;                         /* '<S127>/Kb' */
  real_T SumI1_b;                      /* '<S127>/SumI1' */
  real_T RR_Voltpermm;                 /* '<S130>/RR_Volt per mm' */
  real_T RR_Voltpermm1;                /* '<S130>/RR_Volt per mm1' */
  real_T RR_Voltpermm2_l;              /* '<S130>/RR_Volt per mm2' */
  real_T MathFunction_p;               /* '<S133>/Math Function' */
  real_T MathFunction1_f;              /* '<S133>/Math Function1' */
  real_T MathFunction2_d;              /* '<S133>/Math Function2' */
  real_T Sum_dd;                       /* '<S133>/Sum' */
  real_T Divide2_dp;                   /* '<S133>/Divide2' */
  real_T Divide_lr;                    /* '<S133>/Divide' */
  real_T Sum_ng;                       /* '<S130>/Sum' */
  real_T Sum2_f;                       /* '<S130>/Sum2' */
  real_T Sum3_ie;                      /* '<S130>/Sum3' */
  real_T mmtometer_b;                  /* '<S133>/mm to meter' */
  real_T Sum2_a;                       /* '<S133>/Sum2' */
  real_T MathFunction3_id;             /* '<S133>/Math Function3' */
  real_T Sum1_ow;                      /* '<S133>/Sum1' */
  real_T Divide1_j;                    /* '<S133>/Divide1' */
  real_T Epsilon_oh;                   /* '<S133>/Epsilon' */
  real_T Fcn1_c;                       /* '<S133>/Fcn1' */
  real_T Sum3_g;                       /* '<S133>/Sum3' */
  real_T radtodegree_n;                /* '<S133>/rad to degree' */
  real_T StopPWM11;                    /* '<S7>/Stop PWM 1..1' */
  real_T Tyreradius3;                  /* '<S8>/Tyre radius3' */
  real_T Add1;                         /* '<S8>/Add1' */
  real_T slip;                         /* '<S8>/u(2) // u(1)L' */
  real_T uto1;                         /* '<S8>/-1 to 1' */
  real_T ms_bc;                        /* '<S8>/Tyre radius' */
  real_T Add2;                         /* '<S8>/Add2' */
  real_T u2u1R;                        /* '<S8>/u(2) // u(1)R' */
  real_T IntegralGain_g;               /* '<S146>/Integral Gain' */
  real_T Switch4;                      /* '<S8>/Switch4' */
  real_T ThrottleMapZPT;               /* '<S8>/Throttle MapZPT' */
  real_T PedalLimitzpt2V;              /* '<S8>/Pedal Limit zpt 2V' */
  real_T PedalLimit2V60kmh;            /* '<S8>/Pedal Limit 2 V (60 km//h) ' */
  real_T topercent1;                   /* '<S8>/to percent1' */
  real_T RoundingFunction1_g;          /* '<S8>/Rounding Function1' */
  real_T PedalLimit1001;               /* '<S8>/Pedal Limit 100%1' */
  real_T Switch4_e;                    /* '<S90>/Switch4' */
  real_T Switch3;                      /* '<S90>/Switch3' */
  real_T Switch1_n;                    /* '<S90>/Switch1' */
  real_T Switch_fs;                    /* '<S90>/Switch' */
  real_T Saturation_l;                 /* '<S143>/Saturation' */
  real_T Abs_l;                        /* '<S143>/Abs' */
  real_T Sqrt_j;                       /* '<S143>/Sqrt' */
  real_T Switch_g;                     /* '<S143>/Switch' */
  real_T GainKA;                       /* '<S143>/GainKA' */
  real_T Product_lu;                   /* '<S143>/Product' */
  real_T Gain1_c;                      /* '<S143>/Gain1' */
  real_T Switch1_l;                    /* '<S138>/Switch1' */
  real_T Fcn_e;                        /* '<S144>/Fcn' */
  real_T Product_n;                    /* '<S144>/Product' */
  real_T Gain_j;                       /* '<S144>/Gain' */
  real_T Sum_br;                       /* '<S144>/Sum' */
  real_T Product1_o;                   /* '<S144>/Product1' */
  real_T GainKB;                       /* '<S144>/GainKB' */
  real_T Sum1_g;                       /* '<S144>/Sum1' */
  real_T Product_j;                    /* '<S138>/Product' */
  real_T Gain_g;                       /* '<S138>/Gain' */
  real_T Gain2_k;                      /* '<S138>/Gain2' */
  real_T RealPWMin2;                   /* '<S90>/RealPWMin2' */
  real_T Gain1_fd;                     /* '<S138>/Gain1' */
  real_T Gain_n;                       /* '<S143>/Gain' */
  real_T Saturation_j;                 /* '<S140>/Saturation' */
  real_T Abs_nk;                       /* '<S140>/Abs' */
  real_T Sqrt_n1;                      /* '<S140>/Sqrt' */
  real_T Switch_d;                     /* '<S140>/Switch' */
  real_T GainKA_p;                     /* '<S140>/GainKA' */
  real_T Product_k;                    /* '<S140>/Product' */
  real_T Gain1_hf;                     /* '<S140>/Gain1' */
  real_T Switch1_k;                    /* '<S137>/Switch1' */
  real_T Fcn_i;                        /* '<S141>/Fcn' */
  real_T Product_h;                    /* '<S141>/Product' */
  real_T Gain_nc;                      /* '<S141>/Gain' */
  real_T Sum_lh;                       /* '<S141>/Sum' */
  real_T Product1_i;                   /* '<S141>/Product1' */
  real_T GainKB_f;                     /* '<S141>/GainKB' */
  real_T Sum1_a5;                      /* '<S141>/Sum1' */
  real_T Product_p;                    /* '<S137>/Product' */
  real_T Gain_ni;                      /* '<S137>/Gain' */
  real_T Gain2_f;                      /* '<S137>/Gain2' */
  real_T RealPWMin1;                   /* '<S90>/RealPWMin1' */
  real_T Gain1_a;                      /* '<S137>/Gain1' */
  real_T Gain_nr;                      /* '<S140>/Gain' */
  real_T Abs_b;                        /* '<S128>/Abs' */
  real_T switching1;                   /* '<S83>/switching1' */
  real_T Gain_a;                       /* '<S94>/Gain' */
  real_T Gain1_m;                      /* '<S83>/Gain1' */
  real_T switching2_b;                 /* '<S7>/switching2' */
  real_T RR_refdegree;                 /* '<S89>/RR_ref degree' */
  real_T Abs_e;                        /* '<S121>/Abs' */
  real_T switching_h;                  /* '<S83>/switching' */
  real_T Gain_os;                      /* '<S93>/Gain' */
  real_T Gain_g4;                      /* '<S83>/Gain' */
  real_T switching1_p;                 /* '<S7>/switching1' */
  real_T RL_refdegree;                 /* '<S88>/RL_ref degree' */
  real_T Gain3_n;                      /* '<S86>/Gain3' */
  real_T Switch2_lr;                   /* '<S108>/Switch2' */
  real_T RealPWMin_c;                  /* '<S108>/RealPWMin' */
  real_T Abs_ht;                       /* '<S108>/Abs' */
  real_T Switch_p;                     /* '<S85>/Switch' */
  real_T Abs_f;                        /* '<S98>/Abs' */
  real_T Switch_o;                     /* '<S84>/Switch' */
  real_T prop;                         /* '<S49>/Chart (Propulsion Modes)' */
  real_T sport;                        /* '<S49>/Chart (Propulsion Modes)' */
  real_T clear2go;                     /* '<S49>/Chart (Propulsion Modes)' */
  real_T zptwarn;                      /* '<S49>/Chart (Propulsion Modes)' */
  real_T mode;                         /* '<S49>/Chart (Propulsion Modes)' */
  real_T zptrate;                      /* '<S49>/Chart (Propulsion Modes)' */
  real_T steerprop;                    /* '<S49>/Chart (Propulsion Modes)' */
  real_T pedalprop;                    /* '<S49>/Chart (Propulsion Modes)' */
  real_T FRdeg;                        /* '<S49>/Chart (Propulsion Modes)' */
  real_T RRdeg;                        /* '<S49>/Chart (Propulsion Modes)' */
  real_T FLdeg;                        /* '<S49>/Chart (Propulsion Modes)' */
  real_T RLdeg;                        /* '<S49>/Chart (Propulsion Modes)' */
  real_T AWS;                          /* '<S49>/Chart (AWS FWS)' */
  real_T RateTransition3_j;            /* '<S66>/Rate Transition3' */
  real_T deltaTRead;                   /* '<S66>/deltaT Read' */
  real_T Divide_m;                     /* '<S66>/Divide' */
  real_T RateTransition2;              /* '<S66>/Rate Transition2' */
  real_T flipflopRead;                 /* '<S66>/flipflop Read' */
  real_T pulseRead;                    /* '<S66>/pulse Read' */
  int32_T SFunction1_o2_e;             /* '<S73>/S-Function1' */
  int32_T SFunction1_o2_a;             /* '<S76>/S-Function1' */
  uint32_T SFunction1_o1_p;            /* '<S54>/S-Function1' */
  uint32_T SFunction1_o2_h;            /* '<S54>/S-Function1' */
  uint32_T SFunction1_o3_c;            /* '<S54>/S-Function1' */
  uint32_T SFunction1_o1_l;            /* '<S55>/S-Function1' */
  uint32_T SFunction1_o2_p;            /* '<S55>/S-Function1' */
  uint32_T SFunction1_o1_lx;           /* '<S76>/S-Function1' */
  uint16_T SFunction1_o2_hn;           /* '<S71>/S-Function1' */
  uint8_T BytePack;                    /* '<S48>/Byte Pack' */
  uint8_T SFunction1_o1_cc;            /* '<S73>/S-Function1' */
  uint8_T DataTypeConversion1_j;       /* '<S48>/Data Type Conversion1' */
  uint8_T SFunction1_o1_f0[8];         /* '<S75>/S-Function1' */
  uint8_T SFunction1_o2_eq[8];         /* '<S75>/S-Function1' */
  uint8_T SFunction1_o3_a[8];          /* '<S75>/S-Function1' */
  uint8_T DataTypeConversion_o;        /* '<S48>/Data Type Conversion' */
  uint8_T numbytes;                    /* '<S48>/numbytes' */
  boolean_T SFunction1_a;              /* '<S18>/S-Function1' */
  boolean_T SFunction1_aj;             /* '<S19>/S-Function1' */
  boolean_T SFunction1_p;              /* '<S20>/S-Function1' */
  boolean_T SFunction1_e0;             /* '<S21>/S-Function1' */
  boolean_T SFunction1_p3;             /* '<S22>/S-Function1' */
  boolean_T SFunction1_l;              /* '<S23>/S-Function1' */
  boolean_T SFunction1_b;              /* '<S24>/S-Function1' */
  boolean_T SFunction1_fy;             /* '<S25>/S-Function1' */
  boolean_T SFunction1_n;              /* '<S26>/S-Function1' */
  boolean_T SFunction1_c0;             /* '<S27>/S-Function1' */
  boolean_T Compare;                   /* '<S134>/Compare' */
  boolean_T FRdirection;               /* '<S108>/FRdirection' */
  boolean_T Switch1_a;                 /* '<S108>/Switch1' */
  boolean_T Switch1_c;                 /* '<S98>/Switch1' */
  boolean_T RRdirection;               /* '<S128>/RRdirection' */
  boolean_T Switch1_ju;                /* '<S128>/Switch1' */
  boolean_T Switch1_b;                 /* '<S121>/Switch1' */
  boolean_T Newdata;                   /* '<S58>/New data' */
  boolean_T Deltatimelimitexceeded;    /* '<S58>/Delta time limit exceeded' */
  boolean_T AND;                       /* '<S58>/AND' */
  boolean_T Mem1;                      /* '<S58>/Mem1' */
  boolean_T Mem2;                      /* '<S58>/Mem2' */
  boolean_T Mem3;                      /* '<S58>/Mem3' */
  boolean_T Mem4;                      /* '<S58>/Mem4' */
  boolean_T Mem5;                      /* '<S58>/Mem5' */
  boolean_T Nodata;                    /* '<S58>/No data' */
  boolean_T OR;                        /* '<S58>/OR' */
  boolean_T Warn;                      /* '<S58>/Warn' */
  boolean_T Newdata_n;                 /* '<S59>/New data' */
  boolean_T Deltatimelimitexceeded_k;  /* '<S59>/Delta time limit exceeded' */
  boolean_T AND_i;                     /* '<S59>/AND' */
  boolean_T Mem1_l;                    /* '<S59>/Mem1' */
  boolean_T Mem2_h;                    /* '<S59>/Mem2' */
  boolean_T Mem3_f;                    /* '<S59>/Mem3' */
  boolean_T Mem4_e;                    /* '<S59>/Mem4' */
  boolean_T Mem5_p;                    /* '<S59>/Mem5' */
  boolean_T Nodata_d;                  /* '<S59>/No data' */
  boolean_T OR_n;                      /* '<S59>/OR' */
  boolean_T Warn_i;                    /* '<S59>/Warn' */
  boolean_T BusOff;                    /* '<S50>/Bus Off' */
  boolean_T RXlostlimitreached;        /* '<S50>/RX lost limit reached' */
  boolean_T OR_f;                      /* '<S50>/OR' */
  boolean_T Acknowdledgeerrorlimitreached;/* '<S51>/Acknowdledge error limit reached' */
  boolean_T BusOff_j;                  /* '<S51>/Bus Off' */
  boolean_T OR_j;                      /* '<S51>/OR' */
  boolean_T Deltatimelimitexceeded_j;  /* '<S62>/Delta time limit exceeded' */
  boolean_T Mem1_p;                    /* '<S62>/Mem1' */
  boolean_T Mem2_d;                    /* '<S62>/Mem2' */
  boolean_T Mem3_g;                    /* '<S62>/Mem3' */
  boolean_T Mem4_a;                    /* '<S62>/Mem4' */
  boolean_T Prevmsgnotsent;            /* '<S62>/Prev. msg.  not sent' */
  boolean_T OR_a;                      /* '<S62>/OR' */
  boolean_T Warn_j;                    /* '<S62>/Warn' */
  boolean_T Deltatimelimitexceeded_b;  /* '<S63>/Delta time limit exceeded' */
  boolean_T Mem1_i;                    /* '<S63>/Mem1' */
  boolean_T Mem2_k;                    /* '<S63>/Mem2' */
  boolean_T Mem3_b;                    /* '<S63>/Mem3' */
  boolean_T Mem4_b;                    /* '<S63>/Mem4' */
  boolean_T Prevmsgnotsent_n;          /* '<S63>/Prev. msg.  not sent' */
  boolean_T OR_a5;                     /* '<S63>/OR' */
  boolean_T Warn_d;                    /* '<S63>/Warn' */
  boolean_T SFunction1_o1_c0;          /* '<S69>/S-Function1' */
  boolean_T SFunction1_o2_l;           /* '<S69>/S-Function1' */
  boolean_T Compare_e;                 /* '<S142>/Compare' */
  boolean_T Compare_g;                 /* '<S139>/Compare' */
  boolean_T Compare_j;                 /* '<S131>/Compare' */
  boolean_T Compare_h;                 /* '<S124>/Compare' */
  boolean_T BitwiseOperator;           /* '<S121>/Bitwise Operator' */
  boolean_T Compare_i;                 /* '<S114>/Compare' */
  boolean_T Compare_f;                 /* '<S104>/Compare' */
  boolean_T BitwiseOperator_a;         /* '<S98>/Bitwise Operator' */
  boolean_T revR;                      /* '<S49>/Chart (Propulsion Modes)' */
  boolean_T revL;                      /* '<S49>/Chart (Propulsion Modes)' */
} BlockIO_Kensei150401;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S65>/Unit Delay' */
  real_T RateTransition_Buffer0;       /* '<S46>/Rate Transition' */
  real_T RateTransition_Buffer1;       /* '<S46>/Rate Transition' */
  real_T RateTransition4_Buffer0;      /* '<S46>/Rate Transition4' */
  real_T RateTransition4_Buffer1;      /* '<S46>/Rate Transition4' */
  real_T RateTransition1_Buffer0;      /* '<S46>/Rate Transition1' */
  real_T RateTransition1_Buffer1;      /* '<S46>/Rate Transition1' */
  real_T RateTransition3_Buffer0;      /* '<S46>/Rate Transition3' */
  real_T RateTransition3_Buffer1;      /* '<S46>/Rate Transition3' */
  int32_T clockTickCounter;            /* '<S48>/Pulse Generator' */
  uint32_T Counter_Count;              /* '<S46>/Counter' */
  uint32_T Counter_ClkEphState;        /* '<S46>/Counter' */
  uint32_T Counter_RstEphState;        /* '<S46>/Counter' */
  uint32_T presentTicks;               /* '<S49>/Chart (Propulsion Modes)' */
  uint32_T elapsedTicks;               /* '<S49>/Chart (Propulsion Modes)' */
  uint32_T previousTicks;              /* '<S49>/Chart (Propulsion Modes)' */
  int_T SFunction1_IWORK[2];           /* '<S52>/S-Function1' */
  int_T SFunction1_IWORK_n[2];         /* '<S53>/S-Function1' */
  uint16_T temporalCounter_i1;         /* '<S49>/Chart (Propulsion Modes)' */
  uint16_T temporalCounter_i2;         /* '<S49>/Chart (Propulsion Modes)' */
  int8_T RateTransition_write_buf;     /* '<S46>/Rate Transition' */
  int8_T RateTransition_read_buf;      /* '<S46>/Rate Transition' */
  int8_T RateTransition_last_buf_wr;   /* '<S46>/Rate Transition' */
  int8_T RateTransition4_write_buf;    /* '<S46>/Rate Transition4' */
  int8_T RateTransition4_read_buf;     /* '<S46>/Rate Transition4' */
  int8_T RateTransition4_last_buf_wr;  /* '<S46>/Rate Transition4' */
  int8_T RateTransition1_write_buf;    /* '<S46>/Rate Transition1' */
  int8_T RateTransition1_read_buf;     /* '<S46>/Rate Transition1' */
  int8_T RateTransition1_last_buf_wr;  /* '<S46>/Rate Transition1' */
  int8_T RateTransition3_write_buf;    /* '<S46>/Rate Transition3' */
  int8_T RateTransition3_read_buf;     /* '<S46>/Rate Transition3' */
  int8_T RateTransition3_last_buf_wr;  /* '<S46>/Rate Transition3' */
  uint8_T is_active_c3_Kensei150401;   /* '<S49>/Chart (Propulsion Modes)' */
  uint8_T is_response;                 /* '<S49>/Chart (Propulsion Modes)' */
  uint8_T is_active_response;          /* '<S49>/Chart (Propulsion Modes)' */
  uint8_T is_gearmode;                 /* '<S49>/Chart (Propulsion Modes)' */
  uint8_T is_active_gearmode;          /* '<S49>/Chart (Propulsion Modes)' */
  uint8_T is_toZPT_warning;            /* '<S49>/Chart (Propulsion Modes)' */
  uint8_T is_throt;                    /* '<S49>/Chart (Propulsion Modes)' */
  uint8_T is_active_throt;             /* '<S49>/Chart (Propulsion Modes)' */
  uint8_T is_enabled;                  /* '<S49>/Chart (Propulsion Modes)' */
  uint8_T is_fromzptwarn;              /* '<S49>/Chart (Propulsion Modes)' */
  uint8_T is_active_fromzptwarn;       /* '<S49>/Chart (Propulsion Modes)' */
  uint8_T is_Forward;                  /* '<S49>/Chart (Propulsion Modes)' */
  uint8_T is_wait_angle;               /* '<S49>/Chart (Propulsion Modes)' */
  uint8_T is_Parking;                  /* '<S49>/Chart (Propulsion Modes)' */
  uint8_T is_fromZPT_warning;          /* '<S49>/Chart (Propulsion Modes)' */
  uint8_T is_Reverse;                  /* '<S49>/Chart (Propulsion Modes)' */
  uint8_T is_active_c1_Kensei150401;   /* '<S49>/Chart (AWS FWS)' */
  uint8_T is_c1_Kensei150401;          /* '<S49>/Chart (AWS FWS)' */
  boolean_T Mem1_PreviousInput;        /* '<S58>/Mem1' */
  boolean_T Mem2_PreviousInput;        /* '<S58>/Mem2' */
  boolean_T Mem3_PreviousInput;        /* '<S58>/Mem3' */
  boolean_T Mem4_PreviousInput;        /* '<S58>/Mem4' */
  boolean_T Mem5_PreviousInput;        /* '<S58>/Mem5' */
  boolean_T Mem1_PreviousInput_m;      /* '<S59>/Mem1' */
  boolean_T Mem2_PreviousInput_d;      /* '<S59>/Mem2' */
  boolean_T Mem3_PreviousInput_l;      /* '<S59>/Mem3' */
  boolean_T Mem4_PreviousInput_j;      /* '<S59>/Mem4' */
  boolean_T Mem5_PreviousInput_g;      /* '<S59>/Mem5' */
  boolean_T Mem1_PreviousInput_p;      /* '<S62>/Mem1' */
  boolean_T Mem2_PreviousInput_m;      /* '<S62>/Mem2' */
  boolean_T Mem3_PreviousInput_f;      /* '<S62>/Mem3' */
  boolean_T Mem4_PreviousInput_b;      /* '<S62>/Mem4' */
  boolean_T Mem1_PreviousInput_pu;     /* '<S63>/Mem1' */
  boolean_T Mem2_PreviousInput_o;      /* '<S63>/Mem2' */
  boolean_T Mem3_PreviousInput_fn;     /* '<S63>/Mem3' */
  boolean_T Mem4_PreviousInput_e;      /* '<S63>/Mem4' */
} D_Work_Kensei150401;

/* Continuous states (auto storage) */
typedef struct {
  real_T AnalogFilter_FR_Pos_CSTATE;   /* '<S85>/Analog Filter_FR_Pos' */
  real_T Integrator_CSTATE;            /* '<S107>/Integrator' */
  real_T Filter_CSTATE;                /* '<S107>/Filter' */
  real_T AnalogFilter_FL_Pos_CSTATE;   /* '<S84>/Analog Filter_FL_Pos' */
  real_T Integrator_CSTATE_d;          /* '<S97>/Integrator' */
  real_T Filter_CSTATE_f;              /* '<S97>/Filter' */
  real_T AnalogFilter_RR_Pos_CSTATE;   /* '<S89>/Analog Filter_RR_Pos' */
  real_T Integrator_CSTATE_p;          /* '<S127>/Integrator' */
  real_T Filter_CSTATE_i;              /* '<S127>/Filter' */
  real_T AnalogFilter_RL_Pos_CSTATE;   /* '<S88>/Analog Filter_RL_Pos' */
  real_T Integrator_CSTATE_c;          /* '<S120>/Integrator' */
  real_T Filter_CSTATE_c;              /* '<S120>/Filter' */
  real_T Integrator_CSTATE_l;          /* '<S146>/Integrator' */
  real_T AnalogFilter_FR_Pos_CSTATE_h; /* '<S44>/Analog Filter_FR_Pos' */
} ContinuousStates_Kensei150401;

/* State derivatives (auto storage) */
typedef struct {
  real_T AnalogFilter_FR_Pos_CSTATE;   /* '<S85>/Analog Filter_FR_Pos' */
  real_T Integrator_CSTATE;            /* '<S107>/Integrator' */
  real_T Filter_CSTATE;                /* '<S107>/Filter' */
  real_T AnalogFilter_FL_Pos_CSTATE;   /* '<S84>/Analog Filter_FL_Pos' */
  real_T Integrator_CSTATE_d;          /* '<S97>/Integrator' */
  real_T Filter_CSTATE_f;              /* '<S97>/Filter' */
  real_T AnalogFilter_RR_Pos_CSTATE;   /* '<S89>/Analog Filter_RR_Pos' */
  real_T Integrator_CSTATE_p;          /* '<S127>/Integrator' */
  real_T Filter_CSTATE_i;              /* '<S127>/Filter' */
  real_T AnalogFilter_RL_Pos_CSTATE;   /* '<S88>/Analog Filter_RL_Pos' */
  real_T Integrator_CSTATE_c;          /* '<S120>/Integrator' */
  real_T Filter_CSTATE_c;              /* '<S120>/Filter' */
  real_T Integrator_CSTATE_l;          /* '<S146>/Integrator' */
  real_T AnalogFilter_FR_Pos_CSTATE_h; /* '<S44>/Analog Filter_FR_Pos' */
} StateDerivatives_Kensei150401;

/* State disabled  */
typedef struct {
  boolean_T AnalogFilter_FR_Pos_CSTATE;/* '<S85>/Analog Filter_FR_Pos' */
  boolean_T Integrator_CSTATE;         /* '<S107>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S107>/Filter' */
  boolean_T AnalogFilter_FL_Pos_CSTATE;/* '<S84>/Analog Filter_FL_Pos' */
  boolean_T Integrator_CSTATE_d;       /* '<S97>/Integrator' */
  boolean_T Filter_CSTATE_f;           /* '<S97>/Filter' */
  boolean_T AnalogFilter_RR_Pos_CSTATE;/* '<S89>/Analog Filter_RR_Pos' */
  boolean_T Integrator_CSTATE_p;       /* '<S127>/Integrator' */
  boolean_T Filter_CSTATE_i;           /* '<S127>/Filter' */
  boolean_T AnalogFilter_RL_Pos_CSTATE;/* '<S88>/Analog Filter_RL_Pos' */
  boolean_T Integrator_CSTATE_c;       /* '<S120>/Integrator' */
  boolean_T Filter_CSTATE_c;           /* '<S120>/Filter' */
  boolean_T Integrator_CSTATE_l;       /* '<S146>/Integrator' */
  boolean_T AnalogFilter_FR_Pos_CSTATE_h;/* '<S44>/Analog Filter_FR_Pos' */
} StateDisabled_Kensei150401;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            Kensei150401_B
#define BlockIO                        BlockIO_Kensei150401
#define rtX                            Kensei150401_X
#define ContinuousStates               ContinuousStates_Kensei150401
#define rtXdot                         Kensei150401_Xdot
#define StateDerivatives               StateDerivatives_Kensei150401
#define tXdis                          Kensei150401_Xdis
#define StateDisabled                  StateDisabled_Kensei150401
#define rtP                            Kensei150401_P
#define Parameters                     Parameters_Kensei150401
#define rtDWork                        Kensei150401_DWork
#define D_Work                         D_Work_Kensei150401

/* Parameters (auto storage) */
struct Parameters_Kensei150401_ {
  real_T rps_Value;                    /* Expression: 0
                                        * Referenced by: '<S46>/0 rps'
                                        */
  real_T deltaTMemory_InitialValue;    /* Expression: 0
                                        * Referenced by: '<S66>/deltaT Memory'
                                        */
  real_T flipflopMemory_InitialValue;  /* Expression: 0
                                        * Referenced by: '<S66>/flipflop Memory'
                                        */
  real_T oldTimeMemory_InitialValue;   /* Expression: 0
                                        * Referenced by: '<S66>/oldTime Memory'
                                        */
  real_T pulseMemory_InitialValue;     /* Expression: 0
                                        * Referenced by: '<S66>/pulse Memory'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S84>/Switch'
                                        */
  real_T Switch_Threshold_c;           /* Expression: 1
                                        * Referenced by: '<S85>/Switch'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S108>/Switch2'
                                        */
  real_T RealPWMin_Gain;               /* Expression: 0.025
                                        * Referenced by: '<S108>/RealPWMin'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<S86>/Gain3'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S93>/Gain'
                                        */
  real_T Gain_Gain_f;                  /* Expression: -1
                                        * Referenced by: '<S83>/Gain'
                                        */
  real_T RL_refdegree_UpperSat;        /* Expression: RL_Angle_UpperLimit
                                        * Referenced by: '<S88>/RL_ref degree'
                                        */
  real_T RL_refdegree_LowerSat;        /* Expression: RL_Angle_LowerLimit
                                        * Referenced by: '<S88>/RL_ref degree'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 180/pi
                                        * Referenced by: '<S94>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S83>/Gain1'
                                        */
  real_T RR_refdegree_UpperSat;        /* Expression: RR_Angle_UpperLimit
                                        * Referenced by: '<S89>/RR_ref degree'
                                        */
  real_T RR_refdegree_LowerSat;        /* Expression: RR_Angle_LowerLimit
                                        * Referenced by: '<S89>/RR_ref degree'
                                        */
  real_T Gain_Gain_p;                  /* Expression: -1
                                        * Referenced by: '<S140>/Gain'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: -1
                                        * Referenced by: '<S137>/Gain1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 180
                                        * Referenced by: '<S140>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -180
                                        * Referenced by: '<S140>/Saturation'
                                        */
  real_T Switch_Threshold_h;           /* Expression: 0
                                        * Referenced by: '<S140>/Switch'
                                        */
  real_T GainKA_Gain;                  /* Expression: 1.2
                                        * Referenced by: '<S140>/GainKA'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 0.5
                                        * Referenced by: '<S140>/Gain1'
                                        */
  real_T Constant1_Value;              /* Expression: 60/2
                                        * Referenced by: '<S141>/Constant1'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 1/3
                                        * Referenced by: '<S141>/Gain'
                                        */
  real_T GainKB_Gain;                  /* Expression: 1250
                                        * Referenced by: '<S141>/GainKB'
                                        */
  real_T Gain_Gain_k0;                 /* Expression: 0.04
                                        * Referenced by: '<S137>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<S137>/Gain2'
                                        */
  real_T RealPWMin1_Gain;              /* Expression: 0.05
                                        * Referenced by: '<S90>/RealPWMin1'
                                        */
  real_T Gain_Gain_e;                  /* Expression: -1
                                        * Referenced by: '<S143>/Gain'
                                        */
  real_T Gain1_Gain_gw;                /* Expression: -1
                                        * Referenced by: '<S138>/Gain1'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 180
                                        * Referenced by: '<S143>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -180
                                        * Referenced by: '<S143>/Saturation'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 0
                                        * Referenced by: '<S143>/Switch'
                                        */
  real_T GainKA_Gain_h;                /* Expression: 2
                                        * Referenced by: '<S143>/GainKA'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 0.5
                                        * Referenced by: '<S143>/Gain1'
                                        */
  real_T Constant1_Value_o;            /* Expression: 60/2
                                        * Referenced by: '<S144>/Constant1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 1/3
                                        * Referenced by: '<S144>/Gain'
                                        */
  real_T GainKB_Gain_p;                /* Expression: 1250
                                        * Referenced by: '<S144>/GainKB'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 0.04
                                        * Referenced by: '<S138>/Gain'
                                        */
  real_T Gain2_Gain_h;                 /* Expression: 1/2
                                        * Referenced by: '<S138>/Gain2'
                                        */
  real_T RealPWMin2_Gain;              /* Expression: 0.05
                                        * Referenced by: '<S90>/RealPWMin2'
                                        */
  real_T Switch_Threshold_e;           /* Expression: 4*3
                                        * Referenced by: '<S90>/Switch'
                                        */
  real_T Switch1_Threshold;            /* Expression: 4*3
                                        * Referenced by: '<S90>/Switch1'
                                        */
  real_T Switch3_Threshold;            /* Expression: 1.6
                                        * Referenced by: '<S90>/Switch3'
                                        */
  real_T Switch4_Threshold;            /* Expression: 1.6
                                        * Referenced by: '<S90>/Switch4'
                                        */
  real_T zero1_Value;                  /* Expression: 0
                                        * Referenced by: '<S8>/zero1'
                                        */
  real_T topercent1_Gain;              /* Expression: 100/1
                                        * Referenced by: '<S8>/to percent1'
                                        */
  real_T PedalLimit1001_UpperSat;      /* Expression: 100
                                        * Referenced by: '<S8>/Pedal Limit 100%1'
                                        */
  real_T PedalLimit1001_LowerSat;      /* Expression: 0
                                        * Referenced by: '<S8>/Pedal Limit 100%1'
                                        */
  real_T zero_Value;                   /* Expression: 0
                                        * Referenced by: '<S8>/zero'
                                        */
  real_T PedalLimit2V60kmh_UpperSat;   /* Expression: 3.00
                                        * Referenced by: '<S8>/Pedal Limit 2 V (60 km//h) '
                                        */
  real_T PedalLimit2V60kmh_LowerSat;   /* Expression: 0
                                        * Referenced by: '<S8>/Pedal Limit 2 V (60 km//h) '
                                        */
  real_T ThrottleMapZPT_tableData[2];  /* Expression: [0,1.5]
                                        * Referenced by: '<S8>/Throttle MapZPT'
                                        */
  real_T ThrottleMapZPT_bp01Data[2];   /* Expression: [0,4.85]
                                        * Referenced by: '<S8>/Throttle MapZPT'
                                        */
  real_T PedalLimitzpt2V_UpperSat;     /* Expression: 2.00
                                        * Referenced by: '<S8>/Pedal Limit zpt 2V'
                                        */
  real_T PedalLimitzpt2V_LowerSat;     /* Expression: 0
                                        * Referenced by: '<S8>/Pedal Limit zpt 2V'
                                        */
  real_T AWScomm_Value;                /* Expression: 1
                                        * Referenced by: '<S1>/AWScomm'
                                        */
  real_T FLdegcomm_Value;              /* Expression: -55
                                        * Referenced by: '<S1>/FLdegcomm'
                                        */
  real_T FRdegcomm_Value;              /* Expression: 52
                                        * Referenced by: '<S1>/FRdegcomm'
                                        */
  real_T Ka_Value;                     /* Expression: 1.4
                                        * Referenced by: '<S1>/Ka'
                                        */
  real_T RLdegcomm_Value;              /* Expression: 54
                                        * Referenced by: '<S1>/RLdegcomm'
                                        */
  real_T RRdegcomm_Value;              /* Expression: -51
                                        * Referenced by: '<S1>/RRdegcomm'
                                        */
  real_T T_in_Value;                   /* Expression: 9
                                        * Referenced by: '<S1>/T_in'
                                        */
  real_T kmh_Value;                    /* Expression: 4
                                        * Referenced by: '<S1>/kmh'
                                        */
  real_T Modecomm_Value;               /* Expression: 2
                                        * Referenced by: '<S1>/Modecomm'
                                        */
  real_T offset_Value;                 /* Expression: 0
                                        * Referenced by: '<S1>/offset'
                                        */
  real_T sportcomm_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/sportcomm'
                                        */
  real_T Kb_Value;                     /* Expression: -(3.3*10^-5)
                                        * Referenced by: '<S1>/Kb'
                                        */
  real_T kmh1_Value;                   /* Expression: 0
                                        * Referenced by: '<S1>/kmh1'
                                        */
  real_T inADC1_Gain;                  /* Expression: 10
                                        * Referenced by: '<S2>/inADC1'
                                        */
  real_T inADC2_Gain;                  /* Expression: 10
                                        * Referenced by: '<S2>/inADC2'
                                        */
  real_T inADC3_Gain;                  /* Expression: 10
                                        * Referenced by: '<S2>/inADC3'
                                        */
  real_T inADC4_Gain;                  /* Expression: 10
                                        * Referenced by: '<S2>/inADC4'
                                        */
  real_T inADC5_Gain;                  /* Expression: 10
                                        * Referenced by: '<S2>/inADC5'
                                        */
  real_T inADC6_Gain;                  /* Expression: 10
                                        * Referenced by: '<S2>/inADC6'
                                        */
  real_T inADC7_Gain;                  /* Expression: 10
                                        * Referenced by: '<S2>/inADC7'
                                        */
  real_T inADC8_Gain;                  /* Expression: 10
                                        * Referenced by: '<S2>/inADC8'
                                        */
  real_T inADC9_Gain;                  /* Expression: 10
                                        * Referenced by: '<S2>/inADC9'
                                        */
  real_T PC_On_Off_Touch_Button_Value; /* Expression: 1
                                        * Referenced by: '<S2>/PC_On_Off_Touch_Button'
                                        */
  real_T Touch_Button_Forward_1_Reverse_;/* Expression: 1
                                          * Referenced by: '<S2>/Touch_Button_Forward_1_Reverse_0'
                                          */
  real_T ZPT_Touch_Button_Value;       /* Expression: 1
                                        * Referenced by: '<S2>/ZPT_Touch_Button'
                                        */
  real_T u000Hz_Value;                 /* Expression: 5e-5
                                        * Referenced by: '<S3>/20000 Hz'
                                        */
  real_T FRwm_Value;                   /* Expression: 0
                                        * Referenced by: '<S108>/FRwm'
                                        */
  real_T Switch_FR_Value;              /* Expression: -1
                                        * Referenced by: '<S108>/Switch_FR'
                                        */
  real_T b_Value;                      /* Expression: FR_b
                                        * Referenced by: '<S115>/b'
                                        */
  real_T c_Value;                      /* Expression: FR_c
                                        * Referenced by: '<S115>/c'
                                        */
  real_T d_Value;                      /* Expression: FR_d
                                        * Referenced by: '<S115>/d'
                                        */
  real_T constant_Value;               /* Expression: 2
                                        * Referenced by: '<S115>/constant'
                                        */
  real_T pulse_to_degree_Gain;         /* Expression: 1/13
                                        * Referenced by: '<S135>/pulse_to_degree'
                                        */
  real_T limitrotationdata_UpperSat;   /* Expression: 720
                                        * Referenced by: '<S135>/limit rotation data'
                                        */
  real_T limitrotationdata_LowerSat;   /* Expression: -720
                                        * Referenced by: '<S135>/limit rotation data'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: pi/180
                                        * Referenced by: '<S79>/Gain1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S65>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S65>/Unit Delay'
                                        */
  real_T iftorad2pi_Value;             /* Expression: 1
                                        * Referenced by: '<S46>/if to rad = 2*pi'
                                        */
  real_T pulsesperrevolution_Value;    /* Expression: 86
                                        * Referenced by: '<S46>/pulses per revolution'
                                        */
  real_T RateTransition_X0;            /* Expression: 0
                                        * Referenced by: '<S46>/Rate Transition'
                                        */
  real_T RateTransition4_X0;           /* Expression: 0
                                        * Referenced by: '<S46>/Rate Transition4'
                                        */
  real_T RateTransition1_X0;           /* Expression: 0
                                        * Referenced by: '<S46>/Rate Transition1'
                                        */
  real_T Switch1_Threshold_l;          /* Expression: 1180
                                        * Referenced by: '<S46>/Switch1'
                                        */
  real_T RPSectow_Gain;                /* Expression: 2*pi
                                        * Referenced by: '<S46>/RPSec to w'
                                        */
  real_T Tyreradius_Gain;              /* Expression: 0.225
                                        * Referenced by: '<S46>/Tyre radius'
                                        */
  real_T mstokmh_Gain;                 /* Expression: 3600/1000
                                        * Referenced by: '<S46>/m//s to km//h'
                                        */
  real_T Limit80kmh_UpperSat;          /* Expression: 80
                                        * Referenced by: '<S46>/Limit 80km//h'
                                        */
  real_T Limit80kmh_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S46>/Limit 80km//h'
                                        */
  real_T ThrottleMap1_tableData[9];    /* Expression: THO
                                        * Referenced by: '<S8>/Throttle Map1'
                                        */
  real_T ThrottleMap1_bp01Data[9];     /* Expression: THI
                                        * Referenced by: '<S8>/Throttle Map1'
                                        */
  real_T topercent_Gain;               /* Expression: 100/5.00
                                        * Referenced by: '<S8>/to percent'
                                        */
  real_T PedalLimit100_UpperSat;       /* Expression: 100
                                        * Referenced by: '<S8>/Pedal Limit 100%'
                                        */
  real_T PedalLimit100_LowerSat;       /* Expression: 0
                                        * Referenced by: '<S8>/Pedal Limit 100%'
                                        */
  real_T Wheelbase_Value;              /* Expression: 1.615
                                        * Referenced by: '<S86>/Wheel base'
                                        */
  real_T Wheeltrack_Value;             /* Expression: 1.1
                                        * Referenced by: '<S86>/Wheel track'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: 0.5
                                        * Referenced by: '<S86>/Gain1'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 0.5
                                        * Referenced by: '<S86>/Gain'
                                        */
  real_T SteeringRatio_Value;          /* Expression: 30
                                        * Referenced by: '<S135>/Steering Ratio'
                                        */
  real_T ratio1_Gain;                  /* Expression: 1000
                                        * Referenced by: '<S135>/ratio1'
                                        */
  real_T ratio2_Gain;                  /* Expression: 1/1000
                                        * Referenced by: '<S135>/ratio2'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: pi/180
                                        * Referenced by: '<S117>/Gain1'
                                        */
  real_T Gain2_Gain_g;                 /* Expression: -1
                                        * Referenced by: '<S86>/Gain2'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 180/pi
                                        * Referenced by: '<S118>/Gain'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: pi/180
                                        * Referenced by: '<S91>/Gain1'
                                        */
  real_T kmhtoms_Gain;                 /* Expression: 1000/3600
                                        * Referenced by: '<S87>/km//h to m//s'
                                        */
  real_T A_Value;                      /* Expression: 1
                                        * Referenced by: '<S87>/A'
                                        */
  real_T m_Value;                      /* Expression: 200
                                        * Referenced by: '<S87>/m'
                                        */
  real_T L_Value;                      /* Expression: 2
                                        * Referenced by: '<S87>/L'
                                        */
  real_T Cr_Value;                     /* Expression: 1000
                                        * Referenced by: '<S87>/Cr'
                                        */
  real_T B_Value;                      /* Expression: 1
                                        * Referenced by: '<S87>/B'
                                        */
  real_T Cf_Value;                     /* Expression: 2000
                                        * Referenced by: '<S87>/Cf'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: 0
                                        * Referenced by: '<S87>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -1
                                        * Referenced by: '<S87>/Saturation'
                                        */
  real_T ratio1_Gain_l;                /* Expression: 1000
                                        * Referenced by: '<S87>/ratio1'
                                        */
  real_T ratio2_Gain_d;                /* Expression: 1/1000
                                        * Referenced by: '<S87>/ratio2'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: pi/180
                                        * Referenced by: '<S92>/Gain1'
                                        */
  real_T Wheelbase_Value_e;            /* Expression: 1.615
                                        * Referenced by: '<S83>/Wheel base'
                                        */
  real_T Wheeltrack_Value_o;           /* Expression: 1.1
                                        * Referenced by: '<S83>/Wheel track'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 180/pi
                                        * Referenced by: '<S96>/Gain'
                                        */
  real_T Gain3_Gain_d;                 /* Expression: -1
                                        * Referenced by: '<S83>/Gain3'
                                        */
  real_T ratio3_Gain;                  /* Expression: 10
                                        * Referenced by: '<S109>/ratio3'
                                        */
  real_T ratio4_Gain;                  /* Expression: 1/10
                                        * Referenced by: '<S109>/ratio4'
                                        */
  real_T FR_refdegree_UpperSat;        /* Expression: FR_Angle_UpperLimit
                                        * Referenced by: '<S85>/FR_ref degree'
                                        */
  real_T FR_refdegree_LowerSat;        /* Expression: FR_Angle_LowerLimit
                                        * Referenced by: '<S85>/FR_ref degree'
                                        */
  real_T Switch2_Threshold_g;          /* Expression: 1
                                        * Referenced by: '<S85>/Switch2'
                                        */
  real_T direction_Gain;               /* Expression: -1
                                        * Referenced by: '<S115>/direction'
                                        */
  real_T degreetorad_Gain;             /* Expression: pi/180
                                        * Referenced by: '<S115>/degree to rad'
                                        */
  real_T mtomm_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S115>/m to mm'
                                        */
  real_T FRADCCenter_Value;            /* Expression: FR_ADC_Center
                                        * Referenced by: '<S112>/FR ADC Center'
                                        */
  real_T FR_Voltpermm2_Gain;           /* Expression: FR_Vpm
                                        * Referenced by: '<S112>/FR_Volt per mm2'
                                        */
  real_T FR_mmtovolt_Gain;             /* Expression: FR_Mpv
                                        * Referenced by: '<S112>/FR_mm to volt'
                                        */
  real_T FR_refinputSaturation_UpperSat;/* Expression: FR_ADC_UpperLimit
                                         * Referenced by: '<S85>/FR_ref input Saturation'
                                         */
  real_T FR_refinputSaturation_LowerSat;/* Expression: FR_ADC_LowerLimit
                                         * Referenced by: '<S85>/FR_ref input Saturation'
                                         */
  real_T ratio3_Gain_g;                /* Expression: 1000
                                        * Referenced by: '<S110>/ratio3'
                                        */
  real_T ratio4_Gain_i;                /* Expression: 1/1000
                                        * Referenced by: '<S110>/ratio4'
                                        */
  real_T AnalogFilter_FR_Pos_A;        /* Computed Parameter: AnalogFilter_FR_Pos_A
                                        * Referenced by: '<S85>/Analog Filter_FR_Pos'
                                        */
  real_T AnalogFilter_FR_Pos_B;        /* Computed Parameter: AnalogFilter_FR_Pos_B
                                        * Referenced by: '<S85>/Analog Filter_FR_Pos'
                                        */
  real_T AnalogFilter_FR_Pos_C;        /* Computed Parameter: AnalogFilter_FR_Pos_C
                                        * Referenced by: '<S85>/Analog Filter_FR_Pos'
                                        */
  real_T AnalogFilter_FR_Pos_X0;       /* Expression: 0
                                        * Referenced by: '<S85>/Analog Filter_FR_Pos'
                                        */
  real_T ratio3_Gain_l;                /* Expression: 1000
                                        * Referenced by: '<S111>/ratio3'
                                        */
  real_T ratio4_Gain_f;                /* Expression: 1/1000
                                        * Referenced by: '<S111>/ratio4'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S107>/Integrator'
                                        */
  real_T DerivativeGain_Gain;          /* Expression: D
                                        * Referenced by: '<S107>/Derivative Gain'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S107>/Filter'
                                        */
  real_T FilterCoefficient_Gain;       /* Expression: N
                                        * Referenced by: '<S107>/Filter Coefficient'
                                        */
  real_T ProportionalGain_Gain;        /* Expression: P
                                        * Referenced by: '<S107>/Proportional Gain'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S107>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: LowerSaturationLimit
                                        * Referenced by: '<S107>/Saturation'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S85>/Constant'
                                        */
  real_T Switch1_Threshold_c;          /* Expression: 0.02
                                        * Referenced by: '<S85>/Switch1'
                                        */
  real_T Offset5_Value;                /* Expression: 0
                                        * Referenced by: '<S7>/Offset5'
                                        */
  real_T FLpwm_Value;                  /* Expression: 0
                                        * Referenced by: '<S98>/FLpwm'
                                        */
  real_T Switch_FL_Value;              /* Expression: -1
                                        * Referenced by: '<S98>/Switch_FL'
                                        */
  real_T b_Value_m;                    /* Expression: FL_b
                                        * Referenced by: '<S105>/b'
                                        */
  real_T c_Value_n;                    /* Expression: FL_c
                                        * Referenced by: '<S105>/c'
                                        */
  real_T d_Value_i;                    /* Expression: FL_d
                                        * Referenced by: '<S105>/d'
                                        */
  real_T constant_Value_h;             /* Expression: 2
                                        * Referenced by: '<S105>/constant'
                                        */
  real_T Switch1_Threshold_p;          /* Expression: 0
                                        * Referenced by: '<S86>/Switch1'
                                        */
  real_T Gain_Gain_kz;                 /* Expression: 180/pi
                                        * Referenced by: '<S119>/Gain'
                                        */
  real_T Gain_Gain_c3;                 /* Expression: 180/pi
                                        * Referenced by: '<S95>/Gain'
                                        */
  real_T Gain2_Gain_d;                 /* Expression: -1
                                        * Referenced by: '<S83>/Gain2'
                                        */
  real_T ratio3_Gain_n;                /* Expression: 10
                                        * Referenced by: '<S99>/ratio3'
                                        */
  real_T ratio4_Gain_l;                /* Expression: 1/10
                                        * Referenced by: '<S99>/ratio4'
                                        */
  real_T FL_refdegree_UpperSat;        /* Expression: FL_Angle_UpperLimit
                                        * Referenced by: '<S84>/FL_ref degree'
                                        */
  real_T FL_refdegree_LowerSat;        /* Expression: FL_Angle_LowerLimit
                                        * Referenced by: '<S84>/FL_ref degree'
                                        */
  real_T Switch2_Threshold_i;          /* Expression: 1
                                        * Referenced by: '<S84>/Switch2'
                                        */
  real_T degreetorad_Gain_i;           /* Expression: pi/180
                                        * Referenced by: '<S105>/degree to rad'
                                        */
  real_T mtomm_Gain_k;                 /* Expression: 1000
                                        * Referenced by: '<S105>/m to mm'
                                        */
  real_T FLADCCenter_Value;            /* Expression: FL_ADC_Center
                                        * Referenced by: '<S102>/FL ADC Center'
                                        */
  real_T FL_Voltpermm2_Gain;           /* Expression: FL_Vpm
                                        * Referenced by: '<S102>/FL_Volt per mm2'
                                        */
  real_T FL_mmtovolt_Gain;             /* Expression: FL_Mpv
                                        * Referenced by: '<S102>/FL_mm to volt'
                                        */
  real_T FL_refinputSaturation_UpperSat;/* Expression: FL_ADC_UpperLimit
                                         * Referenced by: '<S84>/FL_ref input Saturation'
                                         */
  real_T FL_refinputSaturation_LowerSat;/* Expression: FL_ADC_LowerLimit
                                         * Referenced by: '<S84>/FL_ref input Saturation'
                                         */
  real_T ratio3_Gain_j;                /* Expression: 1000
                                        * Referenced by: '<S100>/ratio3'
                                        */
  real_T ratio4_Gain_d;                /* Expression: 1/1000
                                        * Referenced by: '<S100>/ratio4'
                                        */
  real_T AnalogFilter_FL_Pos_A;        /* Computed Parameter: AnalogFilter_FL_Pos_A
                                        * Referenced by: '<S84>/Analog Filter_FL_Pos'
                                        */
  real_T AnalogFilter_FL_Pos_B;        /* Computed Parameter: AnalogFilter_FL_Pos_B
                                        * Referenced by: '<S84>/Analog Filter_FL_Pos'
                                        */
  real_T AnalogFilter_FL_Pos_C;        /* Computed Parameter: AnalogFilter_FL_Pos_C
                                        * Referenced by: '<S84>/Analog Filter_FL_Pos'
                                        */
  real_T AnalogFilter_FL_Pos_X0;       /* Expression: 0
                                        * Referenced by: '<S84>/Analog Filter_FL_Pos'
                                        */
  real_T ratio3_Gain_nn;               /* Expression: 1000
                                        * Referenced by: '<S101>/ratio3'
                                        */
  real_T ratio4_Gain_ls;               /* Expression: 1/1000
                                        * Referenced by: '<S101>/ratio4'
                                        */
  real_T Integrator_IC_k;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S97>/Integrator'
                                        */
  real_T DerivativeGain_Gain_k;        /* Expression: D
                                        * Referenced by: '<S97>/Derivative Gain'
                                        */
  real_T Filter_IC_n;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S97>/Filter'
                                        */
  real_T FilterCoefficient_Gain_e;     /* Expression: N
                                        * Referenced by: '<S97>/Filter Coefficient'
                                        */
  real_T ProportionalGain_Gain_n;      /* Expression: P
                                        * Referenced by: '<S97>/Proportional Gain'
                                        */
  real_T Saturation_UpperSat_ib;       /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S97>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: LowerSaturationLimit
                                        * Referenced by: '<S97>/Saturation'
                                        */
  real_T Constant_Value_f;             /* Expression: 0
                                        * Referenced by: '<S84>/Constant'
                                        */
  real_T Switch1_Threshold_j;          /* Expression: 0.02
                                        * Referenced by: '<S84>/Switch1'
                                        */
  real_T Switch2_Threshold_m;          /* Expression: 0
                                        * Referenced by: '<S98>/Switch2'
                                        */
  real_T RealPWMin_Gain_n;             /* Expression: 0.025
                                        * Referenced by: '<S98>/RealPWMin'
                                        */
  real_T Offset6_Value;                /* Expression: 0
                                        * Referenced by: '<S7>/Offset6'
                                        */
  real_T RRpwm_Value;                  /* Expression: 0
                                        * Referenced by: '<S128>/RRpwm'
                                        */
  real_T Switch_RR_Value;              /* Expression: -1
                                        * Referenced by: '<S128>/Switch_RR'
                                        */
  real_T b_Value_h;                    /* Expression: RR_b
                                        * Referenced by: '<S132>/b'
                                        */
  real_T c_Value_g;                    /* Expression: RR_c
                                        * Referenced by: '<S132>/c'
                                        */
  real_T d_Value_p;                    /* Expression: RR_d
                                        * Referenced by: '<S132>/d'
                                        */
  real_T constant_Value_f;             /* Expression: 2
                                        * Referenced by: '<S132>/constant'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 1
                                        * Referenced by: '<S89>/Switch'
                                        */
  real_T degreetorad_Gain_c;           /* Expression: pi/180
                                        * Referenced by: '<S132>/degree to rad'
                                        */
  real_T mtomm_Gain_h;                 /* Expression: 1000
                                        * Referenced by: '<S132>/m to mm'
                                        */
  real_T RRADCCenter_Value;            /* Expression: RR_ADC_Center
                                        * Referenced by: '<S129>/RR ADC Center'
                                        */
  real_T RR_Voltpermm2_Gain;           /* Expression: RR_Vpm
                                        * Referenced by: '<S129>/RR_Volt per mm2'
                                        */
  real_T RR_mmtovolt_Gain;             /* Expression: RR_Mpv
                                        * Referenced by: '<S129>/RR_mm to volt'
                                        */
  real_T RR_refinputSaturation_UpperSat;/* Expression: RR_ADC_UpperLimit
                                         * Referenced by: '<S89>/RR_ref input Saturation'
                                         */
  real_T RR_refinputSaturation_LowerSat;/* Expression: RR_ADC_LowerLimit
                                         * Referenced by: '<S89>/RR_ref input Saturation'
                                         */
  real_T AnalogFilter_RR_Pos_A;        /* Computed Parameter: AnalogFilter_RR_Pos_A
                                        * Referenced by: '<S89>/Analog Filter_RR_Pos'
                                        */
  real_T AnalogFilter_RR_Pos_B;        /* Computed Parameter: AnalogFilter_RR_Pos_B
                                        * Referenced by: '<S89>/Analog Filter_RR_Pos'
                                        */
  real_T AnalogFilter_RR_Pos_C;        /* Computed Parameter: AnalogFilter_RR_Pos_C
                                        * Referenced by: '<S89>/Analog Filter_RR_Pos'
                                        */
  real_T AnalogFilter_RR_Pos_X0;       /* Expression: 0
                                        * Referenced by: '<S89>/Analog Filter_RR_Pos'
                                        */
  real_T Integrator_IC_g;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S127>/Integrator'
                                        */
  real_T DerivativeGain_Gain_g;        /* Expression: D
                                        * Referenced by: '<S127>/Derivative Gain'
                                        */
  real_T Filter_IC_i;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S127>/Filter'
                                        */
  real_T FilterCoefficient_Gain_c;     /* Expression: N
                                        * Referenced by: '<S127>/Filter Coefficient'
                                        */
  real_T ProportionalGain_Gain_o;      /* Expression: P
                                        * Referenced by: '<S127>/Proportional Gain'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S127>/Saturation'
                                        */
  real_T Saturation_LowerSat_m;        /* Expression: LowerSaturationLimit
                                        * Referenced by: '<S127>/Saturation'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S89>/Constant'
                                        */
  real_T Switch1_Threshold_i;          /* Expression: 0.02
                                        * Referenced by: '<S89>/Switch1'
                                        */
  real_T Switch2_Threshold_j;          /* Expression: 0
                                        * Referenced by: '<S128>/Switch2'
                                        */
  real_T RealPWMin_Gain_b;             /* Expression: 0.025
                                        * Referenced by: '<S128>/RealPWMin'
                                        */
  real_T Offset7_Value;                /* Expression: 0
                                        * Referenced by: '<S7>/Offset7'
                                        */
  real_T RLpwm_Value;                  /* Expression: 0
                                        * Referenced by: '<S121>/RLpwm'
                                        */
  real_T Switch_RL_Value;              /* Expression: -1
                                        * Referenced by: '<S121>/Switch_RL'
                                        */
  real_T b_Value_o;                    /* Expression: RL_b
                                        * Referenced by: '<S125>/b'
                                        */
  real_T c_Value_k;                    /* Expression: RL_c
                                        * Referenced by: '<S125>/c'
                                        */
  real_T d_Value_h;                    /* Expression: RL_d
                                        * Referenced by: '<S125>/d'
                                        */
  real_T constant_Value_e;             /* Expression: 2
                                        * Referenced by: '<S125>/constant'
                                        */
  real_T Switch_Threshold_g;           /* Expression: 1
                                        * Referenced by: '<S88>/Switch'
                                        */
  real_T gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S125>/gain'
                                        */
  real_T degreetorad_Gain_m;           /* Expression: pi/180
                                        * Referenced by: '<S125>/degree to rad'
                                        */
  real_T mtomm_Gain_ky;                /* Expression: 1000
                                        * Referenced by: '<S125>/m to mm'
                                        */
  real_T RLADCCenter_Value;            /* Expression: RL_ADC_Center
                                        * Referenced by: '<S122>/RL ADC Center'
                                        */
  real_T RL_Voltpermm2_Gain;           /* Expression: RL_Vpm
                                        * Referenced by: '<S122>/RL_Volt per mm2'
                                        */
  real_T RL_mmtovolt_Gain;             /* Expression: RL_Mpv
                                        * Referenced by: '<S122>/RL_mm to volt'
                                        */
  real_T RL_refinputSaturation_UpperSat;/* Expression: RL_ADC_UpperLimit
                                         * Referenced by: '<S88>/RL_ref input Saturation'
                                         */
  real_T RL_refinputSaturation_LowerSat;/* Expression: RL_ADC_LowerLimit
                                         * Referenced by: '<S88>/RL_ref input Saturation'
                                         */
  real_T AnalogFilter_RL_Pos_A;        /* Computed Parameter: AnalogFilter_RL_Pos_A
                                        * Referenced by: '<S88>/Analog Filter_RL_Pos'
                                        */
  real_T AnalogFilter_RL_Pos_B;        /* Computed Parameter: AnalogFilter_RL_Pos_B
                                        * Referenced by: '<S88>/Analog Filter_RL_Pos'
                                        */
  real_T AnalogFilter_RL_Pos_C;        /* Computed Parameter: AnalogFilter_RL_Pos_C
                                        * Referenced by: '<S88>/Analog Filter_RL_Pos'
                                        */
  real_T AnalogFilter_RL_Pos_X0;       /* Expression: 0
                                        * Referenced by: '<S88>/Analog Filter_RL_Pos'
                                        */
  real_T Integrator_IC_gk;             /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S120>/Integrator'
                                        */
  real_T DerivativeGain_Gain_h;        /* Expression: D
                                        * Referenced by: '<S120>/Derivative Gain'
                                        */
  real_T Filter_IC_a;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S120>/Filter'
                                        */
  real_T FilterCoefficient_Gain_p;     /* Expression: N
                                        * Referenced by: '<S120>/Filter Coefficient'
                                        */
  real_T ProportionalGain_Gain_d;      /* Expression: P
                                        * Referenced by: '<S120>/Proportional Gain'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S120>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: LowerSaturationLimit
                                        * Referenced by: '<S120>/Saturation'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S88>/Constant'
                                        */
  real_T Switch1_Threshold_o;          /* Expression: 0.02
                                        * Referenced by: '<S88>/Switch1'
                                        */
  real_T Switch2_Threshold_mi;         /* Expression: 0
                                        * Referenced by: '<S121>/Switch2'
                                        */
  real_T RealPWMin_Gain_i;             /* Expression: 0.025
                                        * Referenced by: '<S121>/RealPWMin'
                                        */
  real_T Offset4_Value;                /* Expression: 0
                                        * Referenced by: '<S7>/Offset4'
                                        */
  real_T Gain1_Gain_a3;                /* Expression: pi/180
                                        * Referenced by: '<S136>/Gain1'
                                        */
  real_T FeedbackMapZPT_tableData[9];  /* Expression: [-1.68*14, -1.64*12, -1.62*6, -1.6, 0, 1.6, 1.62*6, 1.64*12, 1.68*14]
                                        * Referenced by: '<S90>/Feedback Map ZPT'
                                        */
  real_T FeedbackMapZPT_bp01Data[9];   /* Expression: [-1.68, -1.64, -1.62, -1.6, 0, 1.6, 1.62, 1.64, 1.68]
                                        * Referenced by: '<S90>/Feedback Map ZPT'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1.68*14+1
                                        * Referenced by: '<S90>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -1.68*14-1
                                        * Referenced by: '<S90>/Saturation2'
                                        */
  real_T Gain2_Gain_o;                 /* Expression: 0.04
                                        * Referenced by: '<S90>/Gain2'
                                        */
  real_T Gain3_Gain_n;                 /* Expression: -1
                                        * Referenced by: '<S90>/Gain3'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 5
                                        * Referenced by: '<S90>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S90>/Saturation1'
                                        */
  real_T Constant1_Value_h;            /* Expression: 17
                                        * Referenced by: '<S138>/Constant1'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S142>/Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S139>/Constant'
                                        */
  real_T Switch5_Threshold;            /* Expression: 1
                                        * Referenced by: '<S90>/Switch5'
                                        */
  real_T FeedbackMap_tableData[9];     /* Expression: [-4.08*4, -4.04*2, -4.02*1.3, -4, 0, 4, 4.02*1.3, 4.04*2, 4.08*4]
                                        * Referenced by: '<S90>/Feedback Map'
                                        */
  real_T FeedbackMap_bp01Data[9];      /* Expression: [-4.08*3, -4.04*3, -4.02*3, -4*3, 0, 4*3, 4.02*3, 4.04*3, 4.08*3]
                                        * Referenced by: '<S90>/Feedback Map'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 4.08*4+1
                                        * Referenced by: '<S90>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: -4.08*4-1
                                        * Referenced by: '<S90>/Saturation'
                                        */
  real_T Gain1_Gain_hf;                /* Expression: 0.04
                                        * Referenced by: '<S90>/Gain1'
                                        */
  real_T Switch2_Threshold_gz;         /* Expression: 1
                                        * Referenced by: '<S90>/Switch2'
                                        */
  real_T Integrator_IC_j;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S146>/Integrator'
                                        */
  real_T Switch1_Threshold_co;         /* Expression: 1
                                        * Referenced by: '<S8>/Switch1'
                                        */
  real_T Switch_Threshold_b;           /* Expression: 2
                                        * Referenced by: '<S8>/Switch'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: pi/180
                                        * Referenced by: '<S145>/Gain1'
                                        */
  real_T Switch5_Threshold_i;          /* Expression: 0.1
                                        * Referenced by: '<S8>/Switch5'
                                        */
  real_T ThrottleMapZPT1_tableData[2]; /* Expression: [0, 1.0]
                                        * Referenced by: '<S8>/Throttle MapZPT1'
                                        */
  real_T ThrottleMapZPT1_bp01Data[2];  /* Expression: [0.2, 1.6]
                                        * Referenced by: '<S8>/Throttle MapZPT1'
                                        */
  real_T PedalLimitzpt2V1_UpperSat;    /* Expression: 1.5
                                        * Referenced by: '<S8>/Pedal Limit zpt 2V1'
                                        */
  real_T PedalLimitzpt2V1_LowerSat;    /* Expression: 0
                                        * Referenced by: '<S8>/Pedal Limit zpt 2V1'
                                        */
  real_T Switch3_Threshold_j;          /* Expression: 1
                                        * Referenced by: '<S8>/Switch3'
                                        */
  real_T to5V1_UpperSat;               /* Expression: 5
                                        * Referenced by: '<S8>/0 to 5 V1'
                                        */
  real_T to5V1_LowerSat;               /* Expression: 0
                                        * Referenced by: '<S8>/0 to 5 V1'
                                        */
  real_T outDAC2_Gain;                 /* Expression: 0.1
                                        * Referenced by: '<S3>/outDAC2'
                                        */
  real_T OutputLimit05V005CR_UpperSat; /* Expression: 0.5
                                        * Referenced by: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R'
                                        */
  real_T OutputLimit05V005CR_LowerSat; /* Expression: 0
                                        * Referenced by: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R'
                                        */
  real_T outDAC4_Gain;                 /* Expression: 0.1
                                        * Referenced by: '<S3>/outDAC4'
                                        */
  real_T OutputLimit05V005CR2_UpperSat;/* Expression: 0.5
                                        * Referenced by: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R2'
                                        */
  real_T OutputLimit05V005CR2_LowerSat;/* Expression: 0
                                        * Referenced by: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R2'
                                        */
  real_T BrakeR_Value;                 /* Expression: 0
                                        * Referenced by: '<S8>/BrakeR'
                                        */
  real_T outDAC6_Gain;                 /* Expression: 0.1
                                        * Referenced by: '<S3>/outDAC6'
                                        */
  real_T OutputLimit05V005CR1_UpperSat;/* Expression: 0.5
                                        * Referenced by: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R1'
                                        */
  real_T OutputLimit05V005CR1_LowerSat;/* Expression: 0
                                        * Referenced by: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R1'
                                        */
  real_T BrakeL_Value;                 /* Expression: 0
                                        * Referenced by: '<S8>/BrakeL'
                                        */
  real_T outDAC8_Gain;                 /* Expression: 0.1
                                        * Referenced by: '<S3>/outDAC8'
                                        */
  real_T OutputLimit05V005CR3_UpperSat;/* Expression: 0.5
                                        * Referenced by: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R3'
                                        */
  real_T OutputLimit05V005CR3_LowerSat;/* Expression: 0
                                        * Referenced by: '<S3>/Output Limit [0, 5V] = [0, 0.5] C R3'
                                        */
  real_T Constant_Value_gc;            /* Expression: 0
                                        * Referenced by: '<S134>/Constant'
                                        */
  real_T Constant_Value_ge;            /* Expression: 0
                                        * Referenced by: '<S114>/Constant'
                                        */
  real_T Switch1_Threshold_b;          /* Expression: 0
                                        * Referenced by: '<S108>/Switch1'
                                        */
  real_T Constant_Value_e0;            /* Expression: 0
                                        * Referenced by: '<S104>/Constant'
                                        */
  real_T Switch1_Threshold_jh;         /* Expression: 0
                                        * Referenced by: '<S98>/Switch1'
                                        */
  real_T Constant_Value_ew;            /* Expression: 0
                                        * Referenced by: '<S131>/Constant'
                                        */
  real_T Switch1_Threshold_lu;         /* Expression: 0
                                        * Referenced by: '<S128>/Switch1'
                                        */
  real_T Constant_Value_ga;            /* Expression: 0
                                        * Referenced by: '<S124>/Constant'
                                        */
  real_T Switch1_Threshold_jx;         /* Expression: 0
                                        * Referenced by: '<S121>/Switch1'
                                        */
  real_T Vmin_Value;                   /* Expression: 47.4
                                        * Referenced by: '<S44>/Vmin'
                                        */
  real_T AnalogFilter_FR_Pos_A_e;      /* Computed Parameter: AnalogFilter_FR_Pos_A_e
                                        * Referenced by: '<S44>/Analog Filter_FR_Pos'
                                        */
  real_T AnalogFilter_FR_Pos_B_f;      /* Computed Parameter: AnalogFilter_FR_Pos_B_f
                                        * Referenced by: '<S44>/Analog Filter_FR_Pos'
                                        */
  real_T AnalogFilter_FR_Pos_C_k;      /* Computed Parameter: AnalogFilter_FR_Pos_C_k
                                        * Referenced by: '<S44>/Analog Filter_FR_Pos'
                                        */
  real_T AnalogFilter_FR_Pos_X0_d;     /* Expression: 0
                                        * Referenced by: '<S44>/Analog Filter_FR_Pos'
                                        */
  real_T Amperevolt_Gain;              /* Expression: 22.32
                                        * Referenced by: '<S44>/Ampere//volt'
                                        */
  real_T ratio1_Gain_a;                /* Expression: 100
                                        * Referenced by: '<S44>/ratio1'
                                        */
  real_T ratio2_Gain_de;               /* Expression: 1/100
                                        * Referenced by: '<S44>/ratio2'
                                        */
  real_T Current_Gain;                 /* Expression: 4
                                        * Referenced by: '<S45>/Current'
                                        */
  real_T Current1_Gain;                /* Expression: 4
                                        * Referenced by: '<S45>/Current1'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 256
                                        * Referenced by: '<S45>/Gain'
                                        */
  real_T Gain1_Gain_h1;                /* Expression: 256
                                        * Referenced by: '<S45>/Gain1'
                                        */
  real_T RPMtoRPSec_Gain;              /* Expression: 1/60
                                        * Referenced by: '<S45>/RPM to RPSec'
                                        */
  real_T RPSectow_Gain_d;              /* Expression: 2*pi
                                        * Referenced by: '<S45>/RPSec to w'
                                        */
  real_T Tyreradius_Gain_n;            /* Expression: 0.225
                                        * Referenced by: '<S45>/Tyre radius'
                                        */
  real_T mstokmh_Gain_f;               /* Expression: 3600/1000
                                        * Referenced by: '<S45>/m//s to km//h'
                                        */
  real_T Newdatavalue_Value;           /* Expression: 1
                                        * Referenced by: '<S58>/New data value'
                                        */
  real_T Deltatimelimit_Value;         /* Expression: 0.055
                                        * Referenced by: '<S58>/Delta time limit'
                                        */
  real_T Nodatavalue_Value;            /* Expression: 0
                                        * Referenced by: '<S58>/No data value'
                                        */
  real_T Newdatavalue_Value_l;         /* Expression: 1
                                        * Referenced by: '<S59>/New data value'
                                        */
  real_T Deltatimelimit_Value_n;       /* Expression: 0.055
                                        * Referenced by: '<S59>/Delta time limit'
                                        */
  real_T Nodatavalue_Value_b;          /* Expression: 0
                                        * Referenced by: '<S59>/No data value'
                                        */
  real_T BusOffvalue_Value;            /* Expression: 2
                                        * Referenced by: '<S50>/Bus Off value'
                                        */
  real_T RXlostlimit_Value;            /* Expression: 50
                                        * Referenced by: '<S50>/RX lost limit'
                                        */
  real_T Acknowdledgeerrorlimit_Value; /* Expression: 1000
                                        * Referenced by: '<S51>/Acknowdledge error limit'
                                        */
  real_T BusOffvalue_Value_i;          /* Expression: 2
                                        * Referenced by: '<S51>/Bus Off value'
                                        */
  real_T Constant_Value_o;             /* Expression: 55
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T Deltatimelimit_Value_i;       /* Expression: 0.055
                                        * Referenced by: '<S62>/Delta time limit'
                                        */
  real_T Prevmsgsentvalue_Value;       /* Expression: 1
                                        * Referenced by: '<S62>/Prev. msg. sent value'
                                        */
  real_T Constant1_Value_p;            /* Expression: 55
                                        * Referenced by: '<S45>/Constant1'
                                        */
  real_T Deltatimelimit_Value_p;       /* Expression: 0.055
                                        * Referenced by: '<S63>/Delta time limit'
                                        */
  real_T Prevmsgsentvalue_Value_k;     /* Expression: 1
                                        * Referenced by: '<S63>/Prev. msg. sent value'
                                        */
  real_T RPSectow1_Gain;               /* Expression: 2*pi
                                        * Referenced by: '<S46>/RPSec to w1'
                                        */
  real_T RateTransition3_X0;           /* Expression: 0
                                        * Referenced by: '<S46>/Rate Transition3'
                                        */
  real_T pulsestorevolution_Gain;      /* Expression: 1/86
                                        * Referenced by: '<S46>/pulses to revolution'
                                        */
  real_T RPSectow2_Gain;               /* Expression: 2*pi
                                        * Referenced by: '<S46>/RPSec to w2'
                                        */
  real_T Tyreradius2_Gain;             /* Expression: 0.225
                                        * Referenced by: '<S46>/Tyre radius2'
                                        */
  real_T Tyreradius1_Gain;             /* Expression: 0.225
                                        * Referenced by: '<S46>/Tyre radius1'
                                        */
  real_T mtokm_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S46>/m to km'
                                        */
  real_T mstokmh1_Gain;                /* Expression: 3600/1000
                                        * Referenced by: '<S46>/m//s to km//h1'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S48>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<S48>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<S48>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S48>/Pulse Generator'
                                        */
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<S48>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<S48>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<S48>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<S48>/Sine Wave'
                                        */
  real_T IntegralGain_Gain;            /* Expression: I
                                        * Referenced by: '<S97>/Integral Gain'
                                        */
  real_T Kb_Gain;                      /* Expression: Kb
                                        * Referenced by: '<S97>/Kb'
                                        */
  real_T FLADCCenter_Value_f;          /* Expression: FL_ADC_Center
                                        * Referenced by: '<S103>/FL ADC Center'
                                        */
  real_T FLADCmin_Value;               /* Expression: FL_ADC_Min
                                        * Referenced by: '<S103>/FL ADC min'
                                        */
  real_T FL_Voltpermm_Gain;            /* Expression: FL_Vpm
                                        * Referenced by: '<S103>/FL_Volt per mm'
                                        */
  real_T FL_Voltpermm1_Gain;           /* Expression: FL_Vpm
                                        * Referenced by: '<S103>/FL_Volt per mm1'
                                        */
  real_T FL_Voltpermm2_Gain_n;         /* Expression: FL_Vpm
                                        * Referenced by: '<S103>/FL_Volt per mm2'
                                        */
  real_T b_Value_mg;                   /* Expression: FL_b
                                        * Referenced by: '<S106>/b'
                                        */
  real_T c_Value_h;                    /* Expression: FL_c
                                        * Referenced by: '<S106>/c'
                                        */
  real_T d_Value_f;                    /* Expression: FL_d
                                        * Referenced by: '<S106>/d'
                                        */
  real_T constant_Value_e0;            /* Expression: 2
                                        * Referenced by: '<S106>/constant'
                                        */
  real_T mmtometer_Gain;               /* Expression: 1/1000
                                        * Referenced by: '<S106>/mm to meter'
                                        */
  real_T radtodegree_Gain;             /* Expression: 180/pi
                                        * Referenced by: '<S106>/rad to degree'
                                        */
  real_T IntegralGain_Gain_m;          /* Expression: I
                                        * Referenced by: '<S107>/Integral Gain'
                                        */
  real_T Kb_Gain_a;                    /* Expression: Kb
                                        * Referenced by: '<S107>/Kb'
                                        */
  real_T FRADCCenter_Value_a;          /* Expression: FR_ADC_Center
                                        * Referenced by: '<S113>/FR ADC Center'
                                        */
  real_T FRADCmin_Value;               /* Expression: FR_ADC_Min
                                        * Referenced by: '<S113>/FR ADC min'
                                        */
  real_T FR_Voltpermm_Gain;            /* Expression: FR_Vpm
                                        * Referenced by: '<S113>/FR_Volt per mm'
                                        */
  real_T FR_Voltpermm1_Gain;           /* Expression: FR_Vpm
                                        * Referenced by: '<S113>/FR_Volt per mm1'
                                        */
  real_T FR_Voltpermm2_Gain_n;         /* Expression: FR_Vpm
                                        * Referenced by: '<S113>/FR_Volt per mm2'
                                        */
  real_T b_Value_l;                    /* Expression: FR_b
                                        * Referenced by: '<S116>/b'
                                        */
  real_T c_Value_hu;                   /* Expression: FR_c
                                        * Referenced by: '<S116>/c'
                                        */
  real_T d_Value_a;                    /* Expression: FR_d
                                        * Referenced by: '<S116>/d'
                                        */
  real_T constant_Value_h5;            /* Expression: 2
                                        * Referenced by: '<S116>/constant'
                                        */
  real_T mmtometer_Gain_p;             /* Expression: 1/1000
                                        * Referenced by: '<S116>/mm to meter'
                                        */
  real_T radtodegree_Gain_k;           /* Expression: 180/pi
                                        * Referenced by: '<S116>/rad to degree'
                                        */
  real_T IntegralGain_Gain_c;          /* Expression: I
                                        * Referenced by: '<S120>/Integral Gain'
                                        */
  real_T Kb_Gain_c;                    /* Expression: Kb
                                        * Referenced by: '<S120>/Kb'
                                        */
  real_T RLADCCenter_Value_i;          /* Expression: RL_ADC_Center
                                        * Referenced by: '<S123>/RL ADC Center'
                                        */
  real_T RLADCmin_Value;               /* Expression: RL_ADC_Min
                                        * Referenced by: '<S123>/RL ADC min'
                                        */
  real_T RL_Voltpermm_Gain;            /* Expression: RL_Vpm
                                        * Referenced by: '<S123>/RL_Volt per mm'
                                        */
  real_T RL_Voltpermm1_Gain;           /* Expression: RL_Vpm
                                        * Referenced by: '<S123>/RL_Volt per mm1'
                                        */
  real_T RL_Voltpermm2_Gain_p;         /* Expression: RL_Vpm
                                        * Referenced by: '<S123>/RL_Volt per mm2'
                                        */
  real_T b_Value_d;                    /* Expression: RL_b
                                        * Referenced by: '<S126>/b'
                                        */
  real_T c_Value_p;                    /* Expression: RL_c
                                        * Referenced by: '<S126>/c'
                                        */
  real_T d_Value_g;                    /* Expression: RL_d
                                        * Referenced by: '<S126>/d'
                                        */
  real_T constant_Value_c;             /* Expression: 2
                                        * Referenced by: '<S126>/constant'
                                        */
  real_T mmtometer_Gain_k;             /* Expression: 1/1000
                                        * Referenced by: '<S126>/mm to meter'
                                        */
  real_T radtodegree_Gain_kx;          /* Expression: 180/pi
                                        * Referenced by: '<S126>/rad to degree'
                                        */
  real_T IntegralGain_Gain_l;          /* Expression: I
                                        * Referenced by: '<S127>/Integral Gain'
                                        */
  real_T Kb_Gain_d;                    /* Expression: Kb
                                        * Referenced by: '<S127>/Kb'
                                        */
  real_T RRADCCenter_Value_f;          /* Expression: RR_ADC_Center
                                        * Referenced by: '<S130>/RR ADC Center'
                                        */
  real_T RRADCmin_Value;               /* Expression: RR_ADC_Min
                                        * Referenced by: '<S130>/RR ADC min'
                                        */
  real_T RR_Voltpermm_Gain;            /* Expression: RR_Vpm
                                        * Referenced by: '<S130>/RR_Volt per mm'
                                        */
  real_T RR_Voltpermm1_Gain;           /* Expression: RR_Vpm
                                        * Referenced by: '<S130>/RR_Volt per mm1'
                                        */
  real_T RR_Voltpermm2_Gain_j;         /* Expression: RR_Vpm
                                        * Referenced by: '<S130>/RR_Volt per mm2'
                                        */
  real_T b_Value_b;                    /* Expression: RR_b
                                        * Referenced by: '<S133>/b'
                                        */
  real_T c_Value_f;                    /* Expression: RR_c
                                        * Referenced by: '<S133>/c'
                                        */
  real_T d_Value_a2;                   /* Expression: RR_d
                                        * Referenced by: '<S133>/d'
                                        */
  real_T constant_Value_g;             /* Expression: 2
                                        * Referenced by: '<S133>/constant'
                                        */
  real_T mmtometer_Gain_a;             /* Expression: 1/1000
                                        * Referenced by: '<S133>/mm to meter'
                                        */
  real_T radtodegree_Gain_f;           /* Expression: 180/pi
                                        * Referenced by: '<S133>/rad to degree'
                                        */
  real_T StopPWM11_Value;              /* Expression: 0
                                        * Referenced by: '<S7>/Stop PWM 1..1'
                                        */
  real_T Tyreradius3_Gain;             /* Expression: r
                                        * Referenced by: '<S8>/Tyre radius3'
                                        */
  real_T uto1_UpperSat;                /* Expression: 1
                                        * Referenced by: '<S8>/-1 to 1'
                                        */
  real_T uto1_LowerSat;                /* Expression: -1
                                        * Referenced by: '<S8>/-1 to 1'
                                        */
  real_T Tyreradius_Gain_i;            /* Expression: r
                                        * Referenced by: '<S8>/Tyre radius'
                                        */
  real_T IntegralGain_Gain_p;          /* Expression: I
                                        * Referenced by: '<S146>/Integral Gain'
                                        */
  real_T Switch4_Threshold_n;          /* Expression: 1
                                        * Referenced by: '<S8>/Switch4'
                                        */
  uint32_T Counter_InitialCount;       /* Computed Parameter: Counter_InitialCount
                                        * Referenced by: '<S46>/Counter'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S48>/Manual Switch'
                                        */
  uint8_T numbytes_Value;              /* Computed Parameter: numbytes_Value
                                        * Referenced by: '<S48>/numbytes'
                                        */
  boolean_T FLdirection_Value;         /* Computed Parameter: FLdirection_Value
                                        * Referenced by: '<S98>/FLdirection'
                                        */
  boolean_T RLdirection_Value;         /* Computed Parameter: RLdirection_Value
                                        * Referenced by: '<S121>/RLdirection'
                                        */
  boolean_T FRdirection_Value;         /* Computed Parameter: FRdirection_Value
                                        * Referenced by: '<S108>/FRdirection'
                                        */
  boolean_T RRdirection_Value;         /* Computed Parameter: RRdirection_Value
                                        * Referenced by: '<S128>/RRdirection'
                                        */
  boolean_T Mem1_X0;                   /* Computed Parameter: Mem1_X0
                                        * Referenced by: '<S58>/Mem1'
                                        */
  boolean_T Mem2_X0;                   /* Computed Parameter: Mem2_X0
                                        * Referenced by: '<S58>/Mem2'
                                        */
  boolean_T Mem3_X0;                   /* Computed Parameter: Mem3_X0
                                        * Referenced by: '<S58>/Mem3'
                                        */
  boolean_T Mem4_X0;                   /* Computed Parameter: Mem4_X0
                                        * Referenced by: '<S58>/Mem4'
                                        */
  boolean_T Mem5_X0;                   /* Computed Parameter: Mem5_X0
                                        * Referenced by: '<S58>/Mem5'
                                        */
  boolean_T Mem1_X0_g;                 /* Computed Parameter: Mem1_X0_g
                                        * Referenced by: '<S59>/Mem1'
                                        */
  boolean_T Mem2_X0_a;                 /* Computed Parameter: Mem2_X0_a
                                        * Referenced by: '<S59>/Mem2'
                                        */
  boolean_T Mem3_X0_i;                 /* Computed Parameter: Mem3_X0_i
                                        * Referenced by: '<S59>/Mem3'
                                        */
  boolean_T Mem4_X0_n;                 /* Computed Parameter: Mem4_X0_n
                                        * Referenced by: '<S59>/Mem4'
                                        */
  boolean_T Mem5_X0_f;                 /* Computed Parameter: Mem5_X0_f
                                        * Referenced by: '<S59>/Mem5'
                                        */
  boolean_T Mem1_X0_m;                 /* Computed Parameter: Mem1_X0_m
                                        * Referenced by: '<S62>/Mem1'
                                        */
  boolean_T Mem2_X0_m;                 /* Computed Parameter: Mem2_X0_m
                                        * Referenced by: '<S62>/Mem2'
                                        */
  boolean_T Mem3_X0_f;                 /* Computed Parameter: Mem3_X0_f
                                        * Referenced by: '<S62>/Mem3'
                                        */
  boolean_T Mem4_X0_l;                 /* Computed Parameter: Mem4_X0_l
                                        * Referenced by: '<S62>/Mem4'
                                        */
  boolean_T Mem1_X0_e;                 /* Computed Parameter: Mem1_X0_e
                                        * Referenced by: '<S63>/Mem1'
                                        */
  boolean_T Mem2_X0_k;                 /* Computed Parameter: Mem2_X0_k
                                        * Referenced by: '<S63>/Mem2'
                                        */
  boolean_T Mem3_X0_e;                 /* Computed Parameter: Mem3_X0_e
                                        * Referenced by: '<S63>/Mem3'
                                        */
  boolean_T Mem4_X0_m;                 /* Computed Parameter: Mem4_X0_m
                                        * Referenced by: '<S63>/Mem4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Kensei150401 {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][14];
    ODE1_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[4];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_Kensei150401 Kensei150401_P;

/* Block signals (auto storage) */
extern BlockIO_Kensei150401 Kensei150401_B;

/* Continuous states (auto storage) */
extern ContinuousStates_Kensei150401 Kensei150401_X;

/* Block states (auto storage) */
extern D_Work_Kensei150401 Kensei150401_DWork;

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern real_T deltaT;                  /* '<S66>/deltaT Memory' */
extern real_T flipflop;                /* '<S66>/flipflop Memory' */
extern real_T oldTime;                 /* '<S66>/oldTime Memory' */
extern real_T pulse;                   /* '<S66>/pulse Memory' */

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* External data declarations for dependent source files */
extern const real_T Kensei150401_RGND; /* real_T ground */

/* Model entry point functions */
extern void Kensei150401_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Kensei150401_initialize(void);
extern void Kensei150401_output0(void);
extern void Kensei150401_update0(void);
extern void Kensei150401_output(int_T tid);
extern void Kensei150401_update(int_T tid);
extern void Kensei150401_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Kensei150401 *const Kensei150401_M;

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
 * '<Root>' : 'Kensei150401'
 * '<S1>'   : 'Kensei150401/Control and Display'
 * '<S2>'   : 'Kensei150401/Inputs'
 * '<S3>'   : 'Kensei150401/Outputs'
 * '<S4>'   : 'Kensei150401/Peripherals'
 * '<S5>'   : 'Kensei150401/RTI Data'
 * '<S6>'   : 'Kensei150401/Record Data'
 * '<S7>'   : 'Kensei150401/Steering (Full)'
 * '<S8>'   : 'Kensei150401/Throttle (Basic)'
 * '<S9>'   : 'Kensei150401/Inputs/ADC_TYPE4_BL1'
 * '<S10>'  : 'Kensei150401/Inputs/ADC_TYPE4_BL2'
 * '<S11>'  : 'Kensei150401/Inputs/ADC_TYPE4_BL3'
 * '<S12>'  : 'Kensei150401/Inputs/ADC_TYPE4_BL4'
 * '<S13>'  : 'Kensei150401/Inputs/ADC_TYPE4_BL5'
 * '<S14>'  : 'Kensei150401/Inputs/ADC_TYPE4_BL6'
 * '<S15>'  : 'Kensei150401/Inputs/ADC_TYPE4_BL7'
 * '<S16>'  : 'Kensei150401/Inputs/ADC_TYPE4_BL8'
 * '<S17>'  : 'Kensei150401/Inputs/ADC_TYPE4_BL9'
 * '<S18>'  : 'Kensei150401/Inputs/DIO_TYPE4_BIT_IN_CH_BL1'
 * '<S19>'  : 'Kensei150401/Inputs/DIO_TYPE4_BIT_IN_CH_BL10'
 * '<S20>'  : 'Kensei150401/Inputs/DIO_TYPE4_BIT_IN_CH_BL2'
 * '<S21>'  : 'Kensei150401/Inputs/DIO_TYPE4_BIT_IN_CH_BL3'
 * '<S22>'  : 'Kensei150401/Inputs/DIO_TYPE4_BIT_IN_CH_BL4'
 * '<S23>'  : 'Kensei150401/Inputs/DIO_TYPE4_BIT_IN_CH_BL5'
 * '<S24>'  : 'Kensei150401/Inputs/DIO_TYPE4_BIT_IN_CH_BL6'
 * '<S25>'  : 'Kensei150401/Inputs/DIO_TYPE4_BIT_IN_CH_BL7'
 * '<S26>'  : 'Kensei150401/Inputs/DIO_TYPE4_BIT_IN_CH_BL8'
 * '<S27>'  : 'Kensei150401/Inputs/DIO_TYPE4_BIT_IN_CH_BL9'
 * '<S28>'  : 'Kensei150401/Inputs/DIO_TYPE4_ENC_BL1'
 * '<S29>'  : 'Kensei150401/Inputs/DIO_TYPE4_ENC_P2_BL1'
 * '<S30>'  : 'Kensei150401/Inputs/DIO_TYPE4_ENC_P2_BL4'
 * '<S31>'  : 'Kensei150401/Outputs/AIO_TYPE1_DAC_BL1234'
 * '<S32>'  : 'Kensei150401/Outputs/DIO_TYPE4_BIT_OUT_CH_BL10'
 * '<S33>'  : 'Kensei150401/Outputs/DIO_TYPE4_BIT_OUT_CH_BL11'
 * '<S34>'  : 'Kensei150401/Outputs/DIO_TYPE4_BIT_OUT_CH_BL12'
 * '<S35>'  : 'Kensei150401/Outputs/DIO_TYPE4_BIT_OUT_CH_BL6'
 * '<S36>'  : 'Kensei150401/Outputs/DIO_TYPE4_BIT_OUT_CH_BL7'
 * '<S37>'  : 'Kensei150401/Outputs/DIO_TYPE4_BIT_OUT_CH_BL8'
 * '<S38>'  : 'Kensei150401/Outputs/DIO_TYPE4_BIT_OUT_CH_BL9'
 * '<S39>'  : 'Kensei150401/Outputs/DIO_TYPE4_PWM_BL1'
 * '<S40>'  : 'Kensei150401/Outputs/DIO_TYPE4_PWM_BL2'
 * '<S41>'  : 'Kensei150401/Outputs/DIO_TYPE4_PWM_BL3'
 * '<S42>'  : 'Kensei150401/Outputs/DIO_TYPE4_PWM_BL4'
 * '<S43>'  : 'Kensei150401/Outputs/DIO_TYPE4_PWM_BL5'
 * '<S44>'  : 'Kensei150401/Peripherals/BattCurrent'
 * '<S45>'  : 'Kensei150401/Peripherals/CAN'
 * '<S46>'  : 'Kensei150401/Peripherals/FLspeedEnc'
 * '<S47>'  : 'Kensei150401/Peripherals/Flash Memory'
 * '<S48>'  : 'Kensei150401/Peripherals/SER_Gyro'
 * '<S49>'  : 'Kensei150401/Peripherals/Stateflow'
 * '<S50>'  : 'Kensei150401/Peripherals/CAN/CAN Bus Status Monitoring C1'
 * '<S51>'  : 'Kensei150401/Peripherals/CAN/CAN Bus Status Monitoring C2'
 * '<S52>'  : 'Kensei150401/Peripherals/CAN/CAN_TYPE1_SETUP_M1_C1'
 * '<S53>'  : 'Kensei150401/Peripherals/CAN/CAN_TYPE1_SETUP_M1_C2'
 * '<S54>'  : 'Kensei150401/Peripherals/CAN/DS1CAN_STATUS_B1_C1'
 * '<S55>'  : 'Kensei150401/Peripherals/CAN/DS1CAN_STATUS_B1_C2'
 * '<S56>'  : 'Kensei150401/Peripherals/CAN/RX Message Controller 1'
 * '<S57>'  : 'Kensei150401/Peripherals/CAN/RX Message Controller 2'
 * '<S58>'  : 'Kensei150401/Peripherals/CAN/Sender OK Detection'
 * '<S59>'  : 'Kensei150401/Peripherals/CAN/Sender OK Detection1'
 * '<S60>'  : 'Kensei150401/Peripherals/CAN/TX Message Controller 1'
 * '<S61>'  : 'Kensei150401/Peripherals/CAN/TX Message Controller 2'
 * '<S62>'  : 'Kensei150401/Peripherals/CAN/Transmit OK Detection'
 * '<S63>'  : 'Kensei150401/Peripherals/CAN/Transmit OK Detection1'
 * '<S64>'  : 'Kensei150401/Peripherals/FLspeedEnc/DIO_TYPE4_HWINT_BL1'
 * '<S65>'  : 'Kensei150401/Peripherals/FLspeedEnc/Rising edge every 0 .002s'
 * '<S66>'  : 'Kensei150401/Peripherals/FLspeedEnc/fl encoder interrupt function'
 * '<S67>'  : 'Kensei150401/Peripherals/FLspeedEnc/DIO_TYPE4_HWINT_BL1/Common Hardware Interrupt Interface'
 * '<S68>'  : 'Kensei150401/Peripherals/Flash Memory/DS1401_POWER_DOWN'
 * '<S69>'  : 'Kensei150401/Peripherals/Flash Memory/DS1401_REMOTE_IN_BL1'
 * '<S70>'  : 'Kensei150401/Peripherals/Flash Memory/FLASH_SETUP'
 * '<S71>'  : 'Kensei150401/Peripherals/Flash Memory/RESTORE_FROM_FLASH_BL1'
 * '<S72>'  : 'Kensei150401/Peripherals/Flash Memory/STORE_TO_FLASH_BL1'
 * '<S73>'  : 'Kensei150401/Peripherals/SER_Gyro/CAN_TYPE1_SER_RX_M1_C1'
 * '<S74>'  : 'Kensei150401/Peripherals/SER_Gyro/CAN_TYPE1_SER_SETUP_M1_C1'
 * '<S75>'  : 'Kensei150401/Peripherals/SER_Gyro/CAN_TYPE1_SER_STAT_M1_C1'
 * '<S76>'  : 'Kensei150401/Peripherals/SER_Gyro/CAN_TYPE1_SER_TX_M1_C1'
 * '<S77>'  : 'Kensei150401/Peripherals/Stateflow/Chart (AWS FWS)'
 * '<S78>'  : 'Kensei150401/Peripherals/Stateflow/Chart (Propulsion Modes)'
 * '<S79>'  : 'Kensei150401/Peripherals/Stateflow/Degrees to Radians'
 * '<S80>'  : 'Kensei150401/RTI Data/RTI Data Store'
 * '<S81>'  : 'Kensei150401/RTI Data/RTI Data Store/RTI Data Store'
 * '<S82>'  : 'Kensei150401/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 * '<S83>'  : 'Kensei150401/Steering (Full)/AWS Ackerman'
 * '<S84>'  : 'Kensei150401/Steering (Full)/FL_steering'
 * '<S85>'  : 'Kensei150401/Steering (Full)/FR_steering'
 * '<S86>'  : 'Kensei150401/Steering (Full)/FWS Ackerman'
 * '<S87>'  : 'Kensei150401/Steering (Full)/K_ratio'
 * '<S88>'  : 'Kensei150401/Steering (Full)/RL_steering'
 * '<S89>'  : 'Kensei150401/Steering (Full)/RR_steering'
 * '<S90>'  : 'Kensei150401/Steering (Full)/SW_System'
 * '<S91>'  : 'Kensei150401/Steering (Full)/AWS Ackerman/Degrees to Radians'
 * '<S92>'  : 'Kensei150401/Steering (Full)/AWS Ackerman/Degrees to Radians1'
 * '<S93>'  : 'Kensei150401/Steering (Full)/AWS Ackerman/Radians to Degrees'
 * '<S94>'  : 'Kensei150401/Steering (Full)/AWS Ackerman/Radians to Degrees1'
 * '<S95>'  : 'Kensei150401/Steering (Full)/AWS Ackerman/Radians to Degrees2'
 * '<S96>'  : 'Kensei150401/Steering (Full)/AWS Ackerman/Radians to Degrees3'
 * '<S97>'  : 'Kensei150401/Steering (Full)/FL_steering/FL_Discrete PID Controller'
 * '<S98>'  : 'Kensei150401/Steering (Full)/FL_steering/FL_motordriver'
 * '<S99>'  : 'Kensei150401/Steering (Full)/FL_steering/Rounding1digit'
 * '<S100>' : 'Kensei150401/Steering (Full)/FL_steering/Rounding3digit1'
 * '<S101>' : 'Kensei150401/Steering (Full)/FL_steering/Rounding3digit2'
 * '<S102>' : 'Kensei150401/Steering (Full)/FL_steering/angle to displacement'
 * '<S103>' : 'Kensei150401/Steering (Full)/FL_steering/convert displacement to angle'
 * '<S104>' : 'Kensei150401/Steering (Full)/FL_steering/FL_motordriver/Compare To Zero'
 * '<S105>' : 'Kensei150401/Steering (Full)/FL_steering/angle to displacement/Subsystem'
 * '<S106>' : 'Kensei150401/Steering (Full)/FL_steering/convert displacement to angle/Subsystem'
 * '<S107>' : 'Kensei150401/Steering (Full)/FR_steering/FR_Discrete PID Controller'
 * '<S108>' : 'Kensei150401/Steering (Full)/FR_steering/FR_motordriver'
 * '<S109>' : 'Kensei150401/Steering (Full)/FR_steering/Rounding1digit'
 * '<S110>' : 'Kensei150401/Steering (Full)/FR_steering/Rounding3digit1'
 * '<S111>' : 'Kensei150401/Steering (Full)/FR_steering/Rounding3digit2'
 * '<S112>' : 'Kensei150401/Steering (Full)/FR_steering/angle to displacement'
 * '<S113>' : 'Kensei150401/Steering (Full)/FR_steering/convert displacement to angle'
 * '<S114>' : 'Kensei150401/Steering (Full)/FR_steering/FR_motordriver/Compare To Zero'
 * '<S115>' : 'Kensei150401/Steering (Full)/FR_steering/angle to displacement/Subsystem'
 * '<S116>' : 'Kensei150401/Steering (Full)/FR_steering/convert displacement to angle/Subsystem'
 * '<S117>' : 'Kensei150401/Steering (Full)/FWS Ackerman/Degrees to Radians'
 * '<S118>' : 'Kensei150401/Steering (Full)/FWS Ackerman/Radians to Degrees'
 * '<S119>' : 'Kensei150401/Steering (Full)/FWS Ackerman/Radians to Degrees1'
 * '<S120>' : 'Kensei150401/Steering (Full)/RL_steering/RL_Discrete PID Controller'
 * '<S121>' : 'Kensei150401/Steering (Full)/RL_steering/RL_motordriver'
 * '<S122>' : 'Kensei150401/Steering (Full)/RL_steering/angle to displacement'
 * '<S123>' : 'Kensei150401/Steering (Full)/RL_steering/convert displacement to angle'
 * '<S124>' : 'Kensei150401/Steering (Full)/RL_steering/RL_motordriver/Compare To Zero'
 * '<S125>' : 'Kensei150401/Steering (Full)/RL_steering/angle to displacement/Subsystem'
 * '<S126>' : 'Kensei150401/Steering (Full)/RL_steering/convert displacement to angle/Subsystem'
 * '<S127>' : 'Kensei150401/Steering (Full)/RR_steering/RR_Discrete PID Controller'
 * '<S128>' : 'Kensei150401/Steering (Full)/RR_steering/RR_motordriver'
 * '<S129>' : 'Kensei150401/Steering (Full)/RR_steering/angle to displacement'
 * '<S130>' : 'Kensei150401/Steering (Full)/RR_steering/convert displacement to angle'
 * '<S131>' : 'Kensei150401/Steering (Full)/RR_steering/RR_motordriver/Compare To Zero'
 * '<S132>' : 'Kensei150401/Steering (Full)/RR_steering/angle to displacement/Subsystem'
 * '<S133>' : 'Kensei150401/Steering (Full)/RR_steering/convert displacement to angle/Subsystem'
 * '<S134>' : 'Kensei150401/Steering (Full)/SW_System/Compare To Zero'
 * '<S135>' : 'Kensei150401/Steering (Full)/SW_System/Convert'
 * '<S136>' : 'Kensei150401/Steering (Full)/SW_System/Degrees to Radians'
 * '<S137>' : 'Kensei150401/Steering (Full)/SW_System/Torque Map'
 * '<S138>' : 'Kensei150401/Steering (Full)/SW_System/Torque Map1'
 * '<S139>' : 'Kensei150401/Steering (Full)/SW_System/Torque Map/Compare To Zero'
 * '<S140>' : 'Kensei150401/Steering (Full)/SW_System/Torque Map/Steering torque corresponding to SW-angle'
 * '<S141>' : 'Kensei150401/Steering (Full)/SW_System/Torque Map/Steering torque corresponding to Vx'
 * '<S142>' : 'Kensei150401/Steering (Full)/SW_System/Torque Map1/Compare To Zero'
 * '<S143>' : 'Kensei150401/Steering (Full)/SW_System/Torque Map1/Steering torque corresponding to SW-angle'
 * '<S144>' : 'Kensei150401/Steering (Full)/SW_System/Torque Map1/Steering torque corresponding to Vx'
 * '<S145>' : 'Kensei150401/Throttle (Basic)/Degrees to Radians'
 * '<S146>' : 'Kensei150401/Throttle (Basic)/PID Controller1'
 */
#endif                                 /* RTW_HEADER_Kensei150401_h_ */
