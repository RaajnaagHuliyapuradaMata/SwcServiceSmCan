#include "Std_Types.hpp"

#include "CanSM_Prv.hpp"

#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.hpp"
FUNC(Std_ReturnType, CANSM_CODE) CanSM_RequestComMode( VAR(NetworkHandleType, AUTOMATIC) network,VAR(ComM_ModeType, AUTOMATIC) ComM_Mode ){
   VAR(Std_ReturnType, AUTOMATIC) CanSM_FuncVal_uo;
   VAR(CanSM_NetworkModeStateType_ten, AUTOMATIC) CanSM_CurrNwMode_en;
   VAR(CanSM_BusOffRecoveryStateType_ten, AUTOMATIC) CanSM_CurrBORState_en;

#if(CANSM_SET_BAUDRATE_API == STD_ON)
   VAR(CanSM_ChangeBR_Substates_ten, AUTOMATIC) CanSM_ChangeBR_State_en;
#endif

   VAR(CanSM_TxTimeoutException_Substates_ten, CANSM_VAR) CanSM_TxToutException_state_en;
   CanSM_FuncVal_uo = E_OK;
   network = CanSM_GetHandle(network);
   CanSM_CurrNwMode_en = CanSM_CurrNw_Mode_en[network];
   CanSM_CurrBORState_en = CanSM_currBOR_State_en[network];

#if(CANSM_SET_BAUDRATE_API == STD_ON)
   CanSM_ChangeBR_State_en = CanSM_ChangeBR_Substates_en[network];
#endif

   CanSM_TxToutException_state_en = CanSM_TxTimeoutexception_Substates_en[network];
   if((CanSM_Network_Init_ab[network] == TRUE)&& (CanSM_CurrNwMode_en==CANSM_BSM_S_FULLCOM)&&(ComM_Mode == COMM_NO_COMMUNICATION )&&
          (CanSM_CurrBORState_en!=CANSM_S_BUS_OFF_RECOVERY_L1) &&
          (CanSM_CurrBORState_en!=CANSM_S_BUS_OFF_RECOVERY_L2) &&
          (CanSM_CurrBORState_en!=CANSM_S_RESTART_CC) &&
          (CanSM_CurrBORState_en!=CANSM_S_RESTART_CC_WAIT)&&
#if(CANSM_SET_BAUDRATE_API == STD_ON)
          (CanSM_ChangeBR_State_en == CANSM_BR_DEFAULT)&&
#endif
          (CanSM_TxToutException_state_en==CANSM_TxTimeoutException_DEFAULT)
   ){
                CanSM_ReqComM_Mode_en[network] = COMM_NO_COMMUNICATION ;
                CanSM_CurrNw_Mode_en[network] = CANSM_BSM_S_PRE_NOCOM;
   }
        else if((CanSM_Network_Init_ab[network] == TRUE)&& (CanSM_CurrNwMode_en==CANSM_BSM_S_FULLCOM)&&(ComM_Mode == COMM_NO_COMMUNICATION )&&
              (CanSM_CurrBORState_en!=CANSM_S_BUS_OFF_RECOVERY_L1) &&
              (CanSM_CurrBORState_en!=CANSM_S_BUS_OFF_RECOVERY_L2) &&
              (CanSM_CurrBORState_en!=CANSM_S_RESTART_CC) &&
              (CanSM_CurrBORState_en!=CANSM_S_RESTART_CC_WAIT)&&
#if(CANSM_SET_BAUDRATE_API == STD_ON)
              ((CanSM_ChangeBR_State_en == CANSM_BR_S_CC_STARTED_WAIT)) &&
#endif
              (CanSM_TxToutException_state_en==CANSM_TxTimeoutException_DEFAULT)
             ){
                    CanSM_ReqComM_Mode_en[network] = COMM_NO_COMMUNICATION ;
                }
   else if((CanSM_Network_Init_ab[network] == TRUE)&& (CanSM_CurrNwMode_en==CANSM_BSM_S_FULLCOM)&&
          (ComM_Mode == COMM_SILENT_COMMUNICATION )&&
          (CanSM_CurrBORState_en!=CANSM_S_BUS_OFF_RECOVERY_L1) &&
          (CanSM_CurrBORState_en!=CANSM_S_BUS_OFF_RECOVERY_L2) &&
          (CanSM_CurrBORState_en!=CANSM_S_RESTART_CC) &&
          (CanSM_CurrBORState_en!=CANSM_S_RESTART_CC_WAIT)&&
#if(CANSM_SET_BAUDRATE_API == STD_ON)
          ((CanSM_ChangeBR_State_en == CANSM_BR_DEFAULT) || (CanSM_ChangeBR_State_en == CANSM_BR_S_CC_STARTED_WAIT))&&
#endif
          (CanSM_TxToutException_state_en==CANSM_TxTimeoutException_DEFAULT)
         ){
                CanSM_ReqComM_Mode_en[network] = COMM_SILENT_COMMUNICATION ;
            }
   else if((CanSM_Network_Init_ab[network] == TRUE)&& (CanSM_CurrNwMode_en==CANSM_BSM_S_SILENTCOM)&&
          (ComM_Mode == COMM_NO_COMMUNICATION )&&
          (CanSM_CurrBORState_en!=CANSM_S_BUS_OFF_RECOVERY_L1) &&
          (CanSM_CurrBORState_en!=CANSM_S_BUS_OFF_RECOVERY_L2) &&
          (CanSM_CurrBORState_en!=CANSM_S_RESTART_CC) &&
          (CanSM_CurrBORState_en!=CANSM_S_RESTART_CC_WAIT)&&
#if(CANSM_SET_BAUDRATE_API == STD_ON)
            (CanSM_ChangeBR_State_en == CANSM_BR_DEFAULT)&&
#endif
          (CanSM_TxToutException_state_en==CANSM_TxTimeoutException_DEFAULT)
         ){
                CanSM_ReqComM_Mode_en[network] = COMM_NO_COMMUNICATION ;
                CanSM_CurrNw_Mode_en[network] = CANSM_BSM_S_PRE_NOCOM;
            }
   else if((CanSM_Network_Init_ab[network] == TRUE)&& (CanSM_CurrNwMode_en== CANSM_BSM_S_SILENTCOM)&&
            (ComM_Mode == COMM_FULL_COMMUNICATION )&&
            (CanSM_CurrBORState_en!=CANSM_S_BUS_OFF_RECOVERY_L1) &&
            (CanSM_CurrBORState_en!=CANSM_S_BUS_OFF_RECOVERY_L2) &&
            (CanSM_CurrBORState_en!=CANSM_S_RESTART_CC) &&
            (CanSM_CurrBORState_en!=CANSM_S_RESTART_CC_WAIT)&&
#if(CANSM_SET_BAUDRATE_API == STD_ON)
            (CanSM_ChangeBR_State_en == CANSM_BR_DEFAULT)&&
#endif
            (CanSM_TxToutException_state_en==CANSM_TxTimeoutException_DEFAULT)
           )
                {
                    CanSM_ReqComM_Mode_en[network] = COMM_FULL_COMMUNICATION ;
                }
   else if((CanSM_Network_Init_ab[network] == TRUE)&& (CanSM_CurrNwMode_en== CANSM_BSM_S_NOCOM)&&
            (ComM_Mode == COMM_FULL_COMMUNICATION )&&
            (CanSM_CurrBORState_en!=CANSM_S_BUS_OFF_RECOVERY_L1) &&
            (CanSM_CurrBORState_en!=CANSM_S_BUS_OFF_RECOVERY_L2) &&
            (CanSM_CurrBORState_en!=CANSM_S_RESTART_CC) &&
            (CanSM_CurrBORState_en!=CANSM_S_RESTART_CC_WAIT)&&
#if(CANSM_SET_BAUDRATE_API == STD_ON)
            (CanSM_ChangeBR_State_en == CANSM_BR_DEFAULT)&&
#endif
            (CanSM_TxToutException_state_en==CANSM_TxTimeoutException_DEFAULT)
           ){
                    CanSM_ReqComM_Mode_en[network] = COMM_FULL_COMMUNICATION ;
                    CanSM_CurrNw_Mode_en[network] = CANSM_BSM_S_PRE_FULLCOM;
                }
   else if((CanSM_Network_Init_ab[network] == TRUE) && (CanSM_CurrNwMode_en==CANSM_BSM_WUVALIDATION) && (CanSM_WakeUpValidation_Substates_en[network] == CANSM_WAKEUP_VALIDATION_DEFAULT) &&
               (ComM_Mode == COMM_FULL_COMMUNICATION )
               ){
           CanSM_ReqComM_Mode_en[network] = COMM_FULL_COMMUNICATION ;
           CanSM_CurrNw_Mode_en[network] = CANSM_BSM_S_PRE_FULLCOM;
       }
   else if((CanSM_Network_Init_ab[network] == TRUE)&&(CanSM_CurrNwMode_en!=CANSM_BSM_S_PRE_FULLCOM) &&
             (CanSM_CurrNwMode_en!=CANSM_BSM_S_PRE_NOCOM)&&
             (CanSM_CurrBORState_en!=CANSM_S_BUS_OFF_RECOVERY_L1) &&
             (CanSM_CurrBORState_en!=CANSM_S_BUS_OFF_RECOVERY_L2) &&
             (CanSM_CurrBORState_en!=CANSM_S_RESTART_CC) &&
             (CanSM_CurrBORState_en!=CANSM_S_RESTART_CC_WAIT)&&
#if(CANSM_SET_BAUDRATE_API == STD_ON)
            (CanSM_ChangeBR_State_en == CANSM_BR_DEFAULT)&&
#endif
                         (CanSM_TxToutException_state_en==CANSM_TxTimeoutException_DEFAULT)
            ){
                    CanSM_ReqComM_Mode_en[network] = ComM_Mode ;
                }
   else{
            CanSM_FuncVal_uo = E_NOT_OK;
        }
    return (CanSM_FuncVal_uo);
}
#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.hpp"

