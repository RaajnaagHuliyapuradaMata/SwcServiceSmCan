#ifndef CANSM_PRV_H
#define CANSM_PRV_H

#include "CanSM_Cfg_SchM.hpp"
#include "CanSM.hpp"
#include "BswM_CanSM.hpp"
#include "Dem.hpp"
#include "CanSM_Cbk.hpp"
#include "CanSM_ComM.hpp"
#include "CanSM_TxTimeoutException.hpp"

#define CANSM_RECOVERY_ENABLED                                                1u
#define CANSM_RECOVERY_DISABLED                                               2u
#define CANSM_MUTEX_FREE                                                      1u
#define CANSM_MUTEX_BUSY                                                      2u
#define CANSM_NETWORKIDX_ERROR                                              255u
#define CANSM_ZERO                                                            0u
#define CANSM_INITED                                                        0x0u
#define CANSM_UNINITED                                                      0x1u
#define CANSM_FALSE                                                         0x0u
#define CANSM_TRUE                                                         0x01u
#define CANSM_DEM_DISABLED                                                0xffff

#define CANSM_REPORT_ERROR(CONDITION, API, ERROR)
#define CANSM_REPORT_ERROR_NOK(CONDITION, API, ERROR)

#define CanSM_ReleaseMutex(Indx_Network)           CanSM_MutexMode_au8[Indx_Network] = CANSM_MUTEX_FREE;

#define CanSM_InitTimer(Indx_Network)                                 \
do{                                                                     \
   CanSM_TimerConfig_ast[Indx_Network].cntTick_u16 = 0;                \
   CanSM_TimerConfig_ast[Indx_Network].stTimer = CANSM_TIMER_INIT;     \
}while(0)

#define CanSM_StartTimer(Indx_Network)                                \
do{                                                                     \
   CanSM_TimerConfig_ast[Indx_Network].cntTick_u16 = 0;                \
   CanSM_TimerConfig_ast[Indx_Network].stTimer = CANSM_TIMER_RUNNING;  \
}while(0)

typedef enum{
      CANSM_DEFAULT
   ,  CANSM_S_CC_STOPPED
   ,  CANSM_S_PN_CC_STOPPED
   ,  CANSM_S_CC_STOPPED_WAIT
   ,  CANSM_S_PN_CC_STOPPED_WAIT
   ,  CANSM_S_CC_SLEEP
   ,  CANSM_S_PN_CC_SLEEP
   ,  CANSM_S_CC_SLEEP_WAIT
   ,  CANSM_S_PN_CC_SLEEP_WAIT
   ,  CANSM_S_TRCV_NORMAL
   ,  CANSM_S_PN_TRCV_NORMAL
   ,  CANSM_S_TRCV_NORMAL_WAIT
   ,  CANSM_S_PN_TRCV_NORMAL_WAIT
   ,  CANSM_S_TRCV_STANDBY
   ,  CANSM_S_PN_TRCV_STANDBY
   ,  CANSM_S_TRCV_STANDBY_WAIT
   ,  CANSM_S_PN_TRCV_STANDBY_WAIT
   ,  CANSM_S_PN_CLEAR_WUF
   ,  CANSM_S_PN_CLEAR_WUF_WAIT
   ,  CANSM_S_CHECK_WFLAG_IN_CC_SLEEP
   ,  CANSM_S_CHECK_WFLAG_IN_CC_SLEEP_WAIT
   ,  CANSM_S_CHECK_WFLAG_IN_NOT_CC_SLEEP
   ,  CANSM_S_CHECK_WFLAG_IN_NOT_CC_SLEEP_WAIT
}CanSM_PreNoCom_Substates_ten;

typedef enum{
      CANSM_BOR_CONTROLLER_STOPPED_REQUEST
   ,  CANSM_BOR_CONTROLLER_STOPPED_WAIT
   ,  CANSM_BOR_CONTROLLER_STOPPED_REQUEST_COMPLETED
}CanSM_BOR_Controller_Stopped_stateType_ten;

typedef enum{
      CANSM_PRE_FULLCOM_DEFAULT
   ,  CANSM_PRE_FULLCOM_S_TRCV_NORMAL
   ,  CANSM_PRE_FULLCOM_S_TRCV_NORMAL_WAIT
   ,  CANSM_PRE_FULLCOM_S_CC_STOPPED
   ,  CANSM_PRE_FULLCOM_S_CC_STOPPED_WAIT
   ,  CANSM_PRE_FULLCOM_S_CC_STARTED
   ,  CANSM_PRE_FULLCOM_S_CC_STARTED_WAIT
}CanSM_PreFullCom_Substates_ten;

typedef enum{
      CANSM_WAKEUP_VALIDATION_DEFAULT
   ,  CANSM_WAKEUP_VALIDATION_S_TRCV_NORMAL
   ,  CANSM_WAKEUP_VALIDATION_S_TRCV_NORMAL_WAIT
   ,  CANSM_WAKEUP_VALIDATION_S_CC_STOPPED
   ,  CANSM_WAKEUP_VALIDATION_S_CC_STOPPED_WAIT
   ,  CANSM_WAKEUP_VALIDATION_S_CC_STARTED
   ,  CANSM_WAKEUP_VALIDATION_S_CC_STARTED_WAIT
}CanSM_WakeUpValidation_Substates_ten;

typedef enum{
      CANSM_TxTimeoutException_DEFAULT
   ,  CANSM_TxTimeoutException_S_CC_STOPPED
   ,  CANSM_TxTimeoutException_S_CC_STOPPED_WAIT
   ,  CANSM_TxTimeoutException_S_CC_STARTED
   ,  CANSM_TxTimeoutException_S_CC_STARTED_WAIT
}CanSM_TxTimeoutException_Substates_ten;

typedef enum{
      CANSM_ControllerState_UNINIT
   ,  CANSM_ControllerState_STOPPED
   ,  CANSM_ControllerState_STARTED
   ,  CANSM_ControllerState_SLEEP
}CanSM_CANControllerStateType_ten;

typedef enum{
      CANSM_TIMER_INIT        = 1 //TBD: Check if it can start from 0?
   ,  CANSM_TIMER_RUNNING     = 2
   ,  CANSM_TIMER_ELAPSED     = 3
   ,  CANSM_TIMER_CANCELLED   = 4
}CanSM_TimerStateType_ten;

typedef struct{
   VAR(CanSM_TimerStateType_ten, TYPEDEF)   stTimer;
   VAR(uint16, TYPEDEF)                 cntTick_u16;
}CanSM_TimerConfig_tst;

extern const CanSM_NetworkConf_tst CanSM_Network_Config_acst[CANSM_NUM_CAN_NETWORKS];
extern const uint8 CanSM_NetworktoCtrl_Config_acu8[CANSM_NUM_CAN_CONTROLLERS];
extern P2CONST(CanSM_NetworkConf_tst, CANSM_VAR, CANSM_APPL_CONST) CanSM_Network_pcst;
extern VAR(CanSM_TimerConfig_tst, CANSM_VAR)  CanSM_TimerConfig_ast[CANSM_NUM_CAN_NETWORKS] ;
extern VAR(boolean, CANSM_VAR) CanSM_Init_ab;
extern VAR(CanSM_NetworkModeStateType_ten, CANSM_VAR) CanSM_CurrNw_Mode_en[CANSM_NUM_CAN_NETWORKS];
extern VAR(CanSM_BusOffRecoveryStateType_ten, CANSM_VAR) CanSM_currBOR_State_en[CANSM_NUM_CAN_NETWORKS];
extern VAR(uint8, CANSM_VAR) CanSM_BusOff_Cntr_au8[CANSM_NUM_CAN_NETWORKS];
extern VAR(uint8, CANSM_VAR) CanSM_BORMode_au8[CANSM_NUM_CAN_NETWORKS];
extern VAR(boolean, CANSM_VAR) CanSM_BusOff_Indicated_ab[CANSM_NUM_CAN_NETWORKS];
extern VAR(uint8, CANSM_VAR) CanSM_MutexMode_au8[CANSM_NUM_CAN_NETWORKS];
extern VAR(Type_SwcServiceComM_tMode, CANSM_VAR) CanSM_ReqComM_Mode_en[CANSM_NUM_CAN_NETWORKS];
extern VAR(boolean, CANSM_VAR) CanSM_Wuvalidation_Start_ab[CANSM_NUM_CAN_NETWORKS];
extern VAR(boolean, CANSM_VAR) CanSM_BusOffISRPend_ab[CANSM_NUM_CAN_NETWORKS];
extern VAR(uint8, CANSM_VAR) CanSM_Num_Unsuccessful_ModeReq_au8[CANSM_NUM_CAN_NETWORKS];
extern VAR(boolean, CANSM_VAR) CanSM_Trcv_ModeInd_ab[CANSM_NUM_CAN_NETWORKS];
extern VAR(boolean, CANSM_VAR) CanSM_Ctrl_ModeInd_ab[CANSM_NUM_CAN_NETWORKS];
extern VAR(CanSM_PreNoCom_Substates_ten, CANSM_VAR) CanSM_PreNoCom_Substates_en[CANSM_NUM_CAN_NETWORKS];
extern VAR(Type_SwcServiceComM_tMode, CANSM_VAR) CanSM_BusSMMode_au8[CANSM_NUM_CAN_NETWORKS];
extern VAR(CanSM_PreFullCom_Substates_ten, CANSM_VAR) CanSM_PreFullCom_Substates_en[CANSM_NUM_CAN_NETWORKS];
extern VAR(CanSM_WakeUpValidation_Substates_ten, CANSM_VAR) CanSM_WakeUpValidation_Substates_en[CANSM_NUM_CAN_NETWORKS];
extern VAR(CanSM_TxTimeoutException_Substates_ten, CANSM_VAR) CanSM_TxTimeoutexception_Substates_en[CANSM_NUM_CAN_NETWORKS];
extern VAR(uint16, CANSM_VAR)  CanSM_ModeRepeatReq_Time_u16;
extern VAR(uint8, CANSM_VAR)   CanSM_ModeRepeatReq_Max_u8;
extern VAR(CanSM_CANControllerStateType_ten, CANSM_VAR)CanSM_ControllerState_en[CANSM_NUM_CAN_CONTROLLERS];
extern VAR(boolean, CANSM_VAR) CanSM_Network_Init_ab[CANSM_NUM_CAN_NETWORKS];
extern VAR(boolean, CANSM_VAR) CanSM_ControllerIndications_ab[CANSM_NUM_CAN_CONTROLLERS];
extern VAR(CanSM_BOR_Controller_Stopped_stateType_ten, CANSM_VAR)CanSM_BOR_Controller_Stopped_state_en[CANSM_NUM_CAN_NETWORKS];
extern VAR(boolean, CANSM_VAR) CanSM_Rn_DisableBusOffRecovery_ab[CANSM_NUM_CAN_NETWORKS];
extern VAR(boolean, CANSM_VAR) CanSM_BOR_SilentCom_ab[CANSM_NUM_CAN_NETWORKS];

extern FUNC(void, CANSM_CODE) CanSM_DeInitPnNotSupported(VAR(NetworkHandleType, AUTOMATIC) network);
extern FUNC(void, CANSM_CODE) CanSM_StopCtrl(VAR(NetworkHandleType, AUTOMATIC) network);
extern FUNC(void, CANSM_CODE) CanSM_StartCtrl(VAR(NetworkHandleType, AUTOMATIC) network);
extern FUNC(void, CANSM_CODE) CanSM_SleepCtrl(VAR(NetworkHandleType, AUTOMATIC) network);
extern FUNC(void, CANSM_CODE) CanSM_NO2FULL_COM(VAR(NetworkHandleType, AUTOMATIC) network);
extern FUNC(void, CANSM_CODE) CanSM_FULL2SILENT_COM(VAR(NetworkHandleType, AUTOMATIC) network);
extern FUNC(void, CANSM_CODE) CanSM_SILENT2FULL_COM(VAR(NetworkHandleType, AUTOMATIC) network);
extern FUNC(void, CANSM_CODE) CanSM_TxTimeoutException_StateMachine(VAR(NetworkHandleType, AUTOMATIC) Channel);
extern FUNC(void, CANSM_CODE) CanSM_NetworkModeTrans( VAR(NetworkHandleType, AUTOMATIC) network,VAR(Type_SwcServiceComM_tMode, AUTOMATIC) ComM_Mode);
extern FUNC(NetworkHandleType, CANSM_CODE) CanSM_GetHandle(VAR(NetworkHandleType, AUTOMATIC) ComMChannelId);
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetMutex(VAR(NetworkHandleType, AUTOMATIC) network);
extern FUNC(void, CANSM_CODE) CanSM_BusOffTransitions(VAR(NetworkHandleType, AUTOMATIC) network);
extern FUNC(void, CANSM_CODE) CanSM_BOR_MultipleCtrlsStop(VAR(NetworkHandleType, AUTOMATIC) network);
extern FUNC(void, CANSM_CODE) CanSM_BOR_CtrlsStart(VAR(NetworkHandleType, AUTOMATIC) network);
extern FUNC(void, CANSM_CODE) CanSM_BOR_CtrlsStart_SilentCom(VAR(NetworkHandleType, AUTOMATIC) network);
extern FUNC(void, CANSM_CODE) CanSM_WakeUpValidation_StateMachine(VAR(NetworkHandleType, AUTOMATIC) network);
extern FUNC(void, CANSM_CODE) CanSM_BOR_SilentCom_Exit(VAR(NetworkHandleType, AUTOMATIC) network);
extern FUNC(void, CANSM_CODE) CanSM_PreNoCom_Exit(VAR(NetworkHandleType, AUTOMATIC) network);

#endif
