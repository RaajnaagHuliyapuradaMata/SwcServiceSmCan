#include "Std_Types.hpp"

#include "Types_SwcServiceComM.hpp"

#include "infSwcServiceCanSmSwcServiceSchM.hpp"
#include "CanSM_Prv.hpp"

#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.hpp"
FUNC(void, CANSM_CODE) infSwcServiceCanSMSwcServiceSchM_vMainFunction(void){
   VAR(uint8, AUTOMATIC) CanSM_NetworkIdx_u8;
   VAR(CanSM_NetworkModeStateType_ten, AUTOMATIC) CanSM_CurrNwMode_en;
   VAR(CanSM_BusOffRecoveryStateType_ten, AUTOMATIC) CanSM_CurrBORState_en;
   VAR(CanSM_TxTimeoutException_Substates_ten, CANSM_VAR) CanSM_TxToutException_state_en;
   P2CONST(CanSM_NetworkConf_tst, AUTOMATIC, CANSM_CONST) CanSM_NetworkConf_ps;
   VAR(uint8, AUTOMATIC) CanSM_ControllerId_u8;
   VAR(uint8, AUTOMATIC) CanSM_Ctrl_index_u8;
   VAR(Type_SwcServiceComM_tMode, AUTOMATIC) CanSM_ComM_Mode_uo;
   VAR(Type_SwcServiceComM_tMode, AUTOMATIC) CanSM_ReqComMode_uo;
   VAR(uint8, AUTOMATIC) CanSM_BORMode_u8;
   for(CanSM_NetworkIdx_u8 =0; CanSM_NetworkIdx_u8 < CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_SizeOfCanSMNetworks_u8 ; CanSM_NetworkIdx_u8++){
      CanSM_NetworkConf_ps = &CanSM_Network_pcst[CanSM_NetworkIdx_u8];
      CanSM_CurrNwMode_en = CanSM_CurrNw_Mode_en[CanSM_NetworkIdx_u8];
      CanSM_CurrBORState_en = CanSM_currBOR_State_en[CanSM_NetworkIdx_u8];
      CanSM_TxToutException_state_en = CanSM_TxTimeoutexception_Substates_en[CanSM_NetworkIdx_u8];
      CanSM_ReqComMode_uo = CanSM_ReqComM_Mode_en[CanSM_NetworkIdx_u8];
      CanSM_BORMode_u8=  CanSM_BORMode_au8[CanSM_NetworkIdx_u8];
        if(CanSM_TimerConfig_ast[CanSM_NetworkIdx_u8].stTimer == CANSM_TIMER_RUNNING){
            CanSM_TimerConfig_ast[CanSM_NetworkIdx_u8].cntTick_u16++;
        }
        if(CanSM_TxToutException_state_en != CANSM_TxTimeoutException_DEFAULT){
            CanSM_TxTimeoutException_StateMachine((NetworkHandleType)CanSM_NetworkIdx_u8);
        }
        if((CanSM_ReqComMode_uo != (Type_SwcServiceComM_tMode)CanSM_CurrNwMode_en)){
            CanSM_NetworkModeTrans((NetworkHandleType)CanSM_NetworkIdx_u8,CanSM_ReqComMode_uo);
        }
        if(CanSM_WakeUpValidation_Substates_en[CanSM_NetworkIdx_u8] != CANSM_WAKEUP_VALIDATION_DEFAULT){
            CanSM_WakeUpValidation_StateMachine((NetworkHandleType)CanSM_NetworkIdx_u8);
        }
        if(CanSM_BOR_SilentCom_ab[CanSM_NetworkIdx_u8] == TRUE){
            CanSM_BOR_CtrlsStart_SilentCom(CanSM_NetworkIdx_u8);
        }
        if((CanSM_BORMode_au8[CanSM_NetworkIdx_u8]==(uint8)CANSM_RECOVERY_ENABLED) && (CanSM_CurrBORState_en == CANSM_S_BUS_OFF_CHECK) &&

          (CanSM_TimerConfig_ast[CanSM_NetworkIdx_u8].cntTick_u16 > CanSM_NetworkConf_ps->BorTimeTxEnsured_u16 )
        ){
            Dem_ReportErrorStatus(CanSM_Network_pcst[CanSM_NetworkIdx_u8].BusOffEventId_uo,DEM_EVENT_STATUS_PASSED) ;
            SchM_Enter_CanSM_BOR_Nw_ModesNoNest();
            CanSM_currBOR_State_en[CanSM_NetworkIdx_u8] = CANSM_S_NO_BUS_OFF;
            CanSM_BusOff_Indicated_ab[CanSM_NetworkIdx_u8] = FALSE;
            CanSM_TimerConfig_ast[CanSM_NetworkIdx_u8].stTimer = CANSM_TIMER_ELAPSED;
            CanSM_BusOff_Cntr_au8[CanSM_NetworkIdx_u8] = CANSM_ZERO;
            CanSM_Num_Unsuccessful_ModeReq_au8[CanSM_NetworkIdx_u8]= CANSM_ZERO;
            SchM_Exit_CanSM_BOR_Nw_ModesNoNest();
        }
        if(CanSM_Rn_DisableBusOffRecovery_ab[CanSM_NetworkIdx_u8] == TRUE){
                CanSM_BORMode_au8[CanSM_NetworkIdx_u8] = CANSM_RECOVERY_DISABLED;
                CanSM_BORMode_u8 = CanSM_BORMode_au8[CanSM_NetworkIdx_u8];
                for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
                    CanSM_ControllerId_u8 = CanSM_NetworkConf_ps->Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
                    if(CanSM_ControllerState_en[CanSM_ControllerId_u8] != CANSM_ControllerState_STOPPED){
                       (void)CanIf_SetControllerMode(CanSM_ControllerId_u8,EcuabCanIf_eModeController_STOPPED);
                    }
                    (void)(CanIf_SetPduMode((uint8)CanSM_ControllerId_u8,EcuabCanIf_eModePdu_OFFLINE));
                }
            }
        else if((CanSM_BORMode_u8 == (uint8)CANSM_RECOVERY_ENABLED) &&  ((CanSM_BusOff_Indicated_ab[CanSM_NetworkIdx_u8] == TRUE) || (CanSM_BusOffISRPend_ab[CanSM_NetworkIdx_u8]))){
            CanSM_BusOffTransitions((NetworkHandleType)CanSM_NetworkIdx_u8);
        }
        else if(CanSM_CurrNw_Mode_en[CanSM_NetworkIdx_u8]== CANSM_BSM_S_NOCOM){
            CanSM_BusSMMode_au8[CanSM_NetworkIdx_u8] = (Type_SwcServiceComM_tMode)CANSM_BSM_S_NOCOM;
            CanSM_ComM_Mode_uo = COMM_NO_COMMUNICATION;
            ComM_BusSM_ModeIndication(CanSM_NetworkConf_ps->ComM_channelId_uo, &CanSM_ComM_Mode_uo);
        }
        else{
        }
     }
}
#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.hpp"
