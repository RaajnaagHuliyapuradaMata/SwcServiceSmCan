#include "Std_Types.hpp"

#include "CanSM_Prv.hpp"

#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"
VAR(CanSM_TimerConfig_tst, CANSM_VAR)  CanSM_TimerConfig_ast[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"
VAR(boolean, CANSM_VAR) CanSM_Init_ab;
#define CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"
VAR(CanSM_NetworkModeStateType_ten, CANSM_VAR) CanSM_CurrNw_Mode_en[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"
VAR(CanSM_BusOffRecoveryStateType_ten, CANSM_VAR) CanSM_currBOR_State_en[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_8
#include "CanSM_MemMap.hpp"
VAR(uint8, CANSM_VAR) CanSM_BusOff_Cntr_au8[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_8
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_8
#include "CanSM_MemMap.hpp"
VAR(uint8, CANSM_VAR) CanSM_BORMode_au8[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_8
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"
VAR(boolean, CANSM_VAR) CanSM_BusOff_Indicated_ab[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_8
#include "CanSM_MemMap.hpp"
VAR(uint8, CANSM_VAR) CanSM_MutexMode_au8[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_8
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"
VAR(ComM_ModeType, CANSM_VAR) CanSM_ReqComM_Mode_en[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"
VAR(boolean, CANSM_VAR) CanSM_Wuvalidation_Start_ab[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"
VAR(boolean, CANSM_VAR) CanSM_BusOffISRPend_ab[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"

#if(CANSM_SET_BAUDRATE_API == STD_ON)
#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"

VAR(CanSM_ChangeBR_Substates_ten, CANSM_VAR) CanSM_ChangeBR_Substates_en[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"
#endif

#if(CANSM_SET_BAUDRATE_API == STD_ON)

#define CANSM_START_SEC_VAR_CLEARED_16
#include "CanSM_MemMap.hpp"
VAR(uint16, CANSM_VAR) CanSM_BaudRateConfigID_Value_au16[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_16
#include "CanSM_MemMap.hpp"

#endif

#define CANSM_START_SEC_VAR_CLEARED_8
#include "CanSM_MemMap.hpp"
VAR(uint8, CANSM_VAR) CanSM_Num_Unsuccessful_ModeReq_au8[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_8
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"
VAR(boolean, CANSM_VAR) CanSM_Trcv_ModeInd_ab[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"
VAR(boolean, CANSM_VAR) CanSM_Ctrl_ModeInd_ab[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"
VAR(CanSM_PreNoCom_Substates_ten, CANSM_VAR) CanSM_PreNoCom_Substates_en[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"

#if(CANSM_PN_SUPPORT_CONFIGD == STD_ON)

#define CANSM_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"
VAR(boolean, CANSM_VAR) CanSM_PN_Substate_Ind_ab[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"
#endif

#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"
VAR(ComM_ModeType, CANSM_VAR) CanSM_BusSMMode_au8[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"
VAR(CanSM_PreFullCom_Substates_ten, CANSM_VAR) CanSM_PreFullCom_Substates_en[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"
VAR(CanSM_WakeUpValidation_Substates_ten, CANSM_VAR) CanSM_WakeUpValidation_Substates_en[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"
VAR(CanSM_TxTimeoutException_Substates_ten, CANSM_VAR) CanSM_TxTimeoutexception_Substates_en[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_16
#include "CanSM_MemMap.hpp"
VAR(uint16, CANSM_VAR)  CanSM_ModeRepeatReq_Time_u16;
#define CANSM_STOP_SEC_VAR_CLEARED_16
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_8
#include "CanSM_MemMap.hpp"
VAR(uint8, CANSM_VAR)   CanSM_ModeRepeatReq_Max_u8;
#define CANSM_STOP_SEC_VAR_CLEARED_8
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"
VAR(CanSM_CANControllerStateType_ten, CANSM_VAR)CanSM_ControllerState_en[CANSM_NUM_CAN_CONTROLLERS];
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"
VAR(boolean, CANSM_VAR) CanSM_Network_Init_ab[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"
VAR(boolean, CANSM_VAR) CanSM_ControllerIndications_ab[CANSM_NUM_CAN_CONTROLLERS];
#define CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"
VAR(CanSM_BOR_Controller_Stopped_stateType_ten, CANSM_VAR)CanSM_BOR_Controller_Stopped_state_en[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"
P2CONST(CanSM_NetworkConf_tst, CANSM_VAR, CANSM_APPL_CONST) CanSM_Network_pcst;
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"
P2CONST(Type_CfgSwcServiceCanSM_st, CANSM_VAR, CANSM_APPL_CONST) CfgSwcServiceCanSM_castConfigSet_pcst;
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"

#if(CANSM_DSM_REINIT_ENABLED != STD_OFF)
#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"
P2VAR(CanSM_NetworkConf_DEM_tst, CANSM_VAR, CANSM_APPL_DATA) CanSM_NetworkDem_pst;
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.hpp"
#endif

#if(CANSM_TX_OFFLINE_ACTIVE_SUPPORT == STD_ON)

#define CANSM_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"
VAR(boolean , AUTOMATIC) CanSM_Passive_b;
#define CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"
#endif

#define CANSM_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"
VAR(boolean, CANSM_VAR) CanSM_Rn_DisableBusOffRecovery_ab[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_8
#include "CanSM_MemMap.hpp"
VAR(uint8, CANSM_VAR) CanSM_GetBusOffDelay_Value_u8[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_8
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"
VAR(boolean, CANSM_VAR) CanSM_BOR_SilentCom_ab[CANSM_NUM_CAN_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.hpp"

#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.hpp"
FUNC(void, CANSM_CODE) CanSM_Init(const Type_CfgSwcServiceCanSM_st* ConfigPtr){
   VAR(uint8, AUTOMATIC) CanSM_NetworkIdx_u8;
   VAR(uint8, AUTOMATIC) CanSM_ControllerId_u8;
   VAR(uint8, AUTOMATIC) CanSM_Ctrl_index_u8;
   P2CONST(CanSM_NetworkConf_tst, AUTOMATIC, CANSM_CONST) CanSM_NetworkConf_ps;

#if(CANSM_VARIANT_INFO == CANSM_VARIANT_PRE_COMPILE)
   CfgSwcServiceCanSM_castConfigSet_pcst = &CfgSwcServiceCanSM_castConfigSet[0];
    (void)ConfigPtr;
#else
   CfgSwcServiceCanSM_castConfigSet_pcst = ConfigPtr;
#endif

   CanSM_Network_pcst = CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_NetworkConf_pcst;

#if(CANSM_DSM_REINIT_ENABLED != STD_OFF)
   CanSM_NetworkDem_pst = CfgSwcServiceCanSM_castConfigSet_pcst->CanSMNetworkConfDEM_pst;
#endif

   CanSM_ModeRepeatReq_Max_u8   = CfgSwcServiceCanSM_castConfigSet_pcst->CanSMModeRequestRepetitionMax_u8;
   CanSM_ModeRepeatReq_Time_u16 = CfgSwcServiceCanSM_castConfigSet_pcst->CanSMModeRequestRepetitionTime_u16;
   for(CanSM_NetworkIdx_u8 =0; CanSM_NetworkIdx_u8 < CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_SizeOfCanSMNetworks_u8 ; CanSM_NetworkIdx_u8++){
        CanSM_CurrNw_Mode_en[CanSM_NetworkIdx_u8]                      = CANSM_BSM_S_NOT_INITIALIZED;
        CanSM_currBOR_State_en[CanSM_NetworkIdx_u8]                    = CANSM_BOR_IDLE;
        CanSM_BusOff_Cntr_au8[CanSM_NetworkIdx_u8]                     = CANSM_ZERO;
        CanSM_BORMode_au8[CanSM_NetworkIdx_u8]                         = CANSM_RECOVERY_DISABLED;
        CanSM_ReqComM_Mode_en[CanSM_NetworkIdx_u8]                     = COMM_NO_COMMUNICATION ;
        CanSM_BusOffISRPend_ab[CanSM_NetworkIdx_u8]                    = FALSE;
        CanSM_Ctrl_ModeInd_ab[CanSM_NetworkIdx_u8]                     = FALSE;
        CanSM_Network_Init_ab[CanSM_NetworkIdx_u8]                     = FALSE;
        CanSM_MutexMode_au8[CanSM_NetworkIdx_u8]                       = CANSM_MUTEX_FREE;
        CanSM_Init_ab                                                  = (boolean)CANSM_UNINITED;
        CanSM_Wuvalidation_Start_ab[CanSM_NetworkIdx_u8]                = FALSE;
        CanSM_PreNoCom_Substates_en[CanSM_NetworkIdx_u8]               = CANSM_DEFAULT;
        CanSM_PreFullCom_Substates_en[CanSM_NetworkIdx_u8]             = CANSM_PRE_FULLCOM_DEFAULT;
        CanSM_WakeUpValidation_Substates_en[CanSM_NetworkIdx_u8]       = CANSM_WAKEUP_VALIDATION_DEFAULT;
#if(CANSM_SET_BAUDRATE_API == STD_ON)
        CanSM_ChangeBR_Substates_en[CanSM_NetworkIdx_u8]               = CANSM_BR_DEFAULT;
#endif
        CanSM_TxTimeoutexception_Substates_en[CanSM_NetworkIdx_u8]     = CANSM_TxTimeoutException_DEFAULT;
        CanSM_Num_Unsuccessful_ModeReq_au8[CanSM_NetworkIdx_u8]        = CANSM_ZERO;
        CanSM_BusOff_Indicated_ab[CanSM_NetworkIdx_u8]                  = FALSE;
        CanSM_InitTimer(CanSM_NetworkIdx_u8);
        CanSM_BOR_Controller_Stopped_state_en[CanSM_NetworkIdx_u8]    = CANSM_BOR_CONTROLLER_STOPPED_REQUEST_COMPLETED;
#if(CANSM_TX_OFFLINE_ACTIVE_SUPPORT == STD_ON)
        CanSM_Passive_b                                                = FALSE;
#endif

        CanSM_Rn_DisableBusOffRecovery_ab[CanSM_NetworkIdx_u8]         = FALSE;
        CanSM_GetBusOffDelay_Value_u8[CanSM_NetworkIdx_u8]             = CANSM_ZERO;
        CanSM_BOR_SilentCom_ab[CanSM_NetworkIdx_u8]                     = FALSE;
        CanSM_NetworkConf_ps = &CanSM_Network_pcst[CanSM_NetworkIdx_u8];

#if(CANSM_SET_BAUDRATE_API == STD_ON)
        CanSM_BaudRateConfigID_Value_au16[CanSM_NetworkIdx_u8] = 0xFFFFu;
#endif

        CanSM_CurrNw_Mode_en[CanSM_NetworkIdx_u8] = CANSM_BSM_S_PRE_NOCOM;
        if(CanSM_Network_pcst[CanSM_NetworkIdx_u8].Trcv_hndle_u8 != 255u){
                CanSM_Trcv_ModeInd_ab[CanSM_NetworkIdx_u8] = FALSE;

#if(CANSM_PN_SUPPORT_CONFIGD == STD_ON)
                if(CanSM_Network_pcst[CanSM_NetworkIdx_u8].TrcvPnConfig_b == TRUE){
                        CanSM_PN_Substate_Ind_ab[CanSM_NetworkIdx_u8] = FALSE;
                    }
#endif
            }
        else{
                CanSM_Trcv_ModeInd_ab[CanSM_NetworkIdx_u8] = TRUE;
            }
        for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
                CanSM_ControllerId_u8 = CanSM_NetworkConf_ps->Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
                CanSM_ControllerState_en[CanSM_ControllerId_u8] = CANSM_ControllerState_UNINIT ;
                CanSM_ControllerIndications_ab[CanSM_ControllerId_u8] = FALSE;
            }
        Dem_ReportErrorStatus(CanSM_Network_pcst[CanSM_NetworkIdx_u8].BusOffEventId_uo,DEM_EVENT_STATUS_PASSED);

#if(CANSM_DSM_REINIT_ENABLED != STD_OFF)
        CanSM_NetworkDem_pst[CanSM_NetworkIdx_u8].CanSM_DEM_Eventstatus_u8 = DEM_EVENT_STATUS_PASSED;
#endif

   }
        CanSM_Init_ab = (boolean)CANSM_INITED;
}

FUNC(void, CANSM_CODE) CanSM_DeInitPnNotSupported(VAR(NetworkHandleType, AUTOMATIC) network){
   VAR(CanSM_PreNoCom_Substates_ten, CANSM_VAR) CanSM_PreNoCom_Substates;
   CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
   if(CanSM_Num_Unsuccessful_ModeReq_au8[network] < CanSM_ModeRepeatReq_Max_u8){
        switch(CanSM_PreNoCom_Substates){
            case CANSM_S_CC_STOPPED_WAIT:{
                if(CanSM_Ctrl_ModeInd_ab[network] == TRUE){
                    CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                    CanSM_Ctrl_ModeInd_ab[network] = FALSE;
                    CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_SLEEP;
                    CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
               }
                else{
                    if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                        CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_PreNoCom_Substates_en[network]= CANSM_S_CC_STOPPED;
                        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    }
                }
            }
            break;

            case CANSM_S_CC_SLEEP_WAIT:{
                if(CanSM_Ctrl_ModeInd_ab[network]==TRUE){
                    CanSM_Ctrl_ModeInd_ab[network]=FALSE;
                    CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                    CanSM_PreNoCom_Substates_en[network]= CANSM_S_TRCV_NORMAL;
                    CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
                }
                else{
                    if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                        CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_PreNoCom_Substates_en[network]= CANSM_S_CC_SLEEP;
                        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    }
                }
            }
            break;

            case CANSM_S_TRCV_NORMAL_WAIT:{
                if(CanSM_Trcv_ModeInd_ab[network]==TRUE){
                    if(CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_NetworkConf_pcst[network].Trcv_hndle_u8 != 255){
                            CanSM_Trcv_ModeInd_ab[network] = FALSE;
                        }
                    CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                    CanSM_PreNoCom_Substates_en[network]= CANSM_S_TRCV_STANDBY;
                    CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
                    CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                }
                else{
                    if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                        CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_PreNoCom_Substates_en[network]= CANSM_S_TRCV_NORMAL;
                        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    }
                }
            }
            break;

            case CANSM_S_TRCV_STANDBY_WAIT:{
                if(CanSM_Trcv_ModeInd_ab[network]==TRUE){
                    if(CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_NetworkConf_pcst[network].Trcv_hndle_u8 != 255){
                        CanSM_Trcv_ModeInd_ab[network] = FALSE;
                    }
                    CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                    CanSM_Num_Unsuccessful_ModeReq_au8[network]= CANSM_ZERO;
                    CanSM_PreNoCom_Substates_en[network] = CANSM_DEFAULT;
                    CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    CanSM_PreNoCom_Exit(network);
                }
                else{
                   if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                        CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_PreNoCom_Substates_en[network] = CANSM_S_TRCV_STANDBY;
                        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    }
                }
            }
            break;

            default:
            break;
        }
   }
   else{
        CanSM_PreNoCom_Substates_en[network]=CANSM_S_CC_STOPPED;
        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
        CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
   }
   if(CanSM_PreNoCom_Substates == CANSM_S_CC_STOPPED){
            CanSM_StopCtrl(network);
            CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
        }
   if(CanSM_PreNoCom_Substates == CANSM_S_CC_SLEEP){
            CanSM_SleepCtrl(network);
            CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
        }
   if(CanSM_PreNoCom_Substates == CANSM_S_TRCV_NORMAL){
            if(CanSM_Network_pcst[network].Trcv_hndle_u8 == 255){
                CanSM_Trcv_ModeInd_ab[network] = TRUE;
                CanSM_PreNoCom_Substates_en[network] = CANSM_S_TRCV_STANDBY;
                CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
            }
            else{
#if(CANSM_CFG_TRCV_CANIF_SUPPORT == STD_ON)
                CanSM_NormalTrcv(network);
#endif
                CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
            }
        }
   if(CanSM_PreNoCom_Substates_en[network] == CANSM_S_TRCV_STANDBY){
            if(CanSM_Network_pcst[network].Trcv_hndle_u8 == 255u){
                CanSM_Trcv_ModeInd_ab[network] = TRUE;
                CanSM_PreNoCom_Substates_en[network] = CANSM_DEFAULT;
                CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
   			CanSM_PreNoCom_Exit(network);
            }
            else{
#if(CANSM_CFG_TRCV_CANIF_SUPPORT == STD_ON)
                CanSM_StandbyTrcv(network);
#endif
                CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
            }
        }
}

#if(CANSM_PN_SUPPORT_CONFIGD == STD_ON)
FUNC(void, CANSM_CODE) CanSM_DeInitPnSupported(VAR(NetworkHandleType, AUTOMATIC) network){
   VAR(CanSM_PreNoCom_Substates_ten, CANSM_VAR) CanSM_PreNoCom_Substates;
   CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
   if(CanSM_Num_Unsuccessful_ModeReq_au8[network] < CanSM_ModeRepeatReq_Max_u8){
        switch(CanSM_PreNoCom_Substates){
            case CANSM_S_PN_CLEAR_WUF_WAIT:{
                if(CanSM_PN_Substate_Ind_ab[network] == TRUE){
                    CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                    CanSM_PN_Substate_Ind_ab[network] = FALSE;
                    CanSM_PreNoCom_Substates_en[network] = CANSM_S_PN_CC_STOPPED;
                    CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
                    CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                }
                else{
                    if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                        CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_PreNoCom_Substates_en[network]=CANSM_S_PN_CLEAR_WUF;
                        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    }
                }
            }
            break;

            case CANSM_S_PN_CC_STOPPED_WAIT:{
                if(CanSM_Ctrl_ModeInd_ab[network] == TRUE){
                    CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                    CanSM_Ctrl_ModeInd_ab[network] = FALSE;
                    CanSM_PreNoCom_Substates_en[network] = CANSM_S_TRCV_NORMAL;
                    CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
                }
                else{
                    if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                        CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_PreNoCom_Substates_en[network]=CANSM_S_PN_CC_STOPPED;
                        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    }
                }
            }
            break;

            case CANSM_S_PN_TRCV_NORMAL_WAIT:{
                if(CanSM_Trcv_ModeInd_ab[network] == TRUE){
                    CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                    CanSM_Trcv_ModeInd_ab[network] = FALSE;
                    CanSM_PreNoCom_Substates_en[network] = CANSM_S_PN_TRCV_STANDBY;
                    CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
                }
                else{
                    if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                        CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_PreNoCom_Substates_en[network]= CANSM_S_PN_TRCV_NORMAL;
                        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    }
                }
            }
            break;

            case CANSM_S_PN_TRCV_STANDBY_WAIT:{
                if(CanSM_Trcv_ModeInd_ab[network] == TRUE){
                    CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                    CanSM_Trcv_ModeInd_ab[network] = FALSE;
                    CanSM_PreNoCom_Substates_en[network] = CANSM_S_PN_CC_SLEEP;
                    CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
                }
                else{
                    if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                        CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_PreNoCom_Substates_en[network]=CANSM_S_PN_TRCV_STANDBY;
                        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    }
                }
            }
            break;

            case CANSM_S_PN_CC_SLEEP_WAIT:{
                if(CanSM_Ctrl_ModeInd_ab[network] == TRUE){
                    CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                    CanSM_Ctrl_ModeInd_ab[network] = FALSE;
                    CanSM_PreNoCom_Substates_en[network] = CANSM_S_CHECK_WFLAG_IN_CC_SLEEP;
                    CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
                }
                else{
                    if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                        CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_PreNoCom_Substates_en[network]=CANSM_S_CHECK_WFLAG_IN_NOT_CC_SLEEP;
                        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    }
               }
            }
            break;

            case CANSM_S_CHECK_WFLAG_IN_CC_SLEEP_WAIT:{
                if(CanSM_PN_Substate_Ind_ab[network] == TRUE){
                    CanSM_PN_Substate_Ind_ab[network]   = FALSE;
                    CanSM_Ctrl_ModeInd_ab[network]      = FALSE;
                    CanSM_Trcv_ModeInd_ab[network]      = FALSE;
                    CanSM_PreNoCom_Substates_en[network] = CANSM_DEFAULT;
                    CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                    CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
                    CanSM_PreNoCom_Exit(network);
                }
                else{
                    if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                        CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_PreNoCom_Substates_en[network] = CANSM_S_CHECK_WFLAG_IN_CC_SLEEP;
                        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    }
                }
            }
            break;

            case CANSM_S_CHECK_WFLAG_IN_NOT_CC_SLEEP_WAIT:{
                if(CanSM_PN_Substate_Ind_ab[network] == TRUE){
                    CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                    CanSM_PN_Substate_Ind_ab[network]   = FALSE;
                    CanSM_Ctrl_ModeInd_ab[network]      = FALSE;
                    CanSM_Trcv_ModeInd_ab[network]      = FALSE;
                    CanSM_PreNoCom_Substates_en[network] = CANSM_S_PN_CLEAR_WUF;
                    CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
                }
                else{
                    if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                        CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_PreNoCom_Substates_en[network]=CANSM_S_CHECK_WFLAG_IN_NOT_CC_SLEEP;
                        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
                    }
                }
            }
            break;

            default:
            break;
        }
   }
   else{
            CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
            CanSM_PreNoCom_Substates_en[network] = CANSM_S_PN_CLEAR_WUF;
            CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
        }
   if(CanSM_PreNoCom_Substates == CANSM_S_PN_CLEAR_WUF){
        CanSM_PN_ClearWufTrcv(network);
        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
   }
   if(CanSM_PreNoCom_Substates == CANSM_S_PN_CC_STOPPED){
        CanSM_StopCtrl(network);
        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
   }
   if(CanSM_PreNoCom_Substates == CANSM_S_PN_TRCV_NORMAL){
#if(CANSM_CFG_TRCV_CANIF_SUPPORT == STD_ON)
        CanSM_NormalTrcv(network);
#endif
        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
   }
   if(CanSM_PreNoCom_Substates == CANSM_S_PN_TRCV_STANDBY){
#if(CANSM_CFG_TRCV_CANIF_SUPPORT == STD_ON)
        CanSM_StandbyTrcv(network);
#endif
        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
   }
   if(CanSM_PreNoCom_Substates == CANSM_S_PN_CC_SLEEP){
        CanSM_SleepCtrl(network);
        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
   }
   if(CanSM_PreNoCom_Substates == CANSM_S_CHECK_WFLAG_IN_CC_SLEEP){
        CanSM_CheckWakeUpFlagInSleep(network);
        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
   }
   if(CanSM_PreNoCom_Substates == CANSM_S_CHECK_WFLAG_IN_NOT_CC_SLEEP){
        CanSM_CheckWakeUpFlagNotInSleep(network);
        CanSM_PreNoCom_Substates = CanSM_PreNoCom_Substates_en[network];
   }
}
#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.hpp"
#endif
