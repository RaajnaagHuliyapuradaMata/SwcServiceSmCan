#ifndef CANSM_H
#define CANSM_H

#include "CfgSwcServiceCanSM.hpp"
#include "ComM.hpp"

#define CANSM_E_UNINIT                                                     0x01u
#define CANSM_E_PARAM_POINTER                                              0x02u
#define CANSM_E_INVALID_NETWORK_HANDLE                                     0x03u
#define CANSM_E_PARAM_CONTROLLER                                           0x04u
#define CANSM_E_PARAM_TRANSCEIVER                                          0x05u
#define CANSM_E_WAIT_MODE_INDICATION                                       0x07u
#define CANSM_E_MODE_REQUEST_TIMEOUT                                       0x0Au
#define CANSM_E_INIT_FAILED                                                0x0Cu
#define CANSM_E_BUSOFF_RECOVERY_ACTIVE                                     0x06u
#define CANSM_E_INVALID_COMM_REQUEST                                       0x08u
#define CANSM_INIT_SID                                                     0x00u
#define CANSM_REQUESTCOMMODE_SID                                           0x02u
#define CANSM_GETCURRENTCOMMODE_SID                                        0x03u
#define CANSM_CONTROLLERBUSOFF_SID                                         0x04u
#define CANSM_MAINFUNCTION_SID                                             0x05u
#define CANSM_CTRLMODEINDICATION_SID                                       0x07u
#define CANSM_TXTIMEOUTEXCEPTION_SID                                       0x0bu
#define CANSM_STARTWAKEUPVALIDATION_SID                                    0x11u
#define CANSM_STOPWAKEUPVALIDATION_SID                                     0x12u
#define CANSM_GETBUSOFFDELAY_SID                                           0x0fu
#define CANSM_GETBUSOFFSUBSTATE_SID                                        0x0Fu
#define CANSM_GETNETWORKMODESUBSTATE_SID                                   0x11u

typedef enum{
      CANSM_BSM_S_NOCOM     = (Type_SwcServiceComM_tMode)COMM_NO_COMMUNICATION
   ,  CANSM_BSM_S_SILENTCOM = (Type_SwcServiceComM_tMode)COMM_SILENT_COMMUNICATION
   ,  CANSM_BSM_S_FULLCOM   = (Type_SwcServiceComM_tMode)COMM_FULL_COMMUNICATION
   ,  CANSM_BSM_S_NOT_INITIALIZED
   ,  CANSM_BSM_S_PRE_NOCOM
   ,  CANSM_BSM_WUVALIDATION
   ,  CANSM_BSM_S_PRE_FULLCOM
   ,  CANSM_BSM_S_CHANGE_BAUDRATE
   ,  CANSM_BSM_S_SILENTCOM_BOR
   ,  CANSM_BSM_S_TX_TIMEOUT_EXCEPTION
}CanSM_NetworkModeStateType_ten;

typedef enum{
      CANSM_BOR_IDLE                  = 1 //TBD: Check if it can start from 0
   ,  CANSM_S_BUS_OFF_CHECK           = 2
   ,  CANSM_S_NO_BUS_OFF              = 3
   ,  CANSM_S_BUS_OFF_RECOVERY_L1     = 4
   ,  CANSM_S_RESTART_CC              = 5
   ,  CANSM_S_RESTART_CC_WAIT         = 6
   ,  CANSM_S_BUS_OFF_RECOVERY_L2     = 7
}CanSM_BusOffRecoveryStateType_ten;

extern VAR(uint8, CANSM_VAR) CanSM_GetBusOffDelay_Value_u8[CANSM_NUM_CAN_NETWORKS];

extern FUNC(void, CANSM_CODE) CanSM_Init( const Type_CfgSwcServiceCanSM_st* ConfigPtr );

extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_StartWakeupSource(        VAR(NetworkHandleType, AUTOMATIC) network);
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_StopWakeupSource(         VAR(NetworkHandleType, AUTOMATIC) network);
extern FUNC(void,     CANSM_CODE) CanSM_Rn_DisableBusOffRecovery( VAR(NetworkHandleType, AUTOMATIC) network);

extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetNetworkMode_Substate(
        VAR(NetworkHandleType,     AUTOMATIC                 ) network
   ,  P2VAR(CanSM_NetworkModeStateType_ten, AUTOMATIC, CANSM_APPL_DATA) NetworkMode_SubstatePtr
);

extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetBusoff_Substate(
      uint8                              ControllerId
   ,  CanSM_BusOffRecoveryStateType_ten* BORStatePtr
);

#endif

