#include "Std_Types.hpp"

#include "Types_SwcServiceComM.hpp"

#include "CanSM_Prv.hpp"

#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.hpp"
FUNC(NetworkHandleType, CANSM_CODE) CanSM_GetHandle(VAR(NetworkHandleType, AUTOMATIC) ComMChannelId){
   VAR(uint8, AUTOMATIC) loop_uo;
   VAR(uint8, AUTOMATIC) CanSM_NetworkIdx_u8 = CANSM_ZERO;
   for(loop_uo =0; loop_uo < CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_SizeOfCanSMNetworks_u8 ; loop_uo++){
   	if(CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_NetworkConf_pcst[loop_uo].ComM_channelId_uo == ComMChannelId){
   	    CanSM_NetworkIdx_u8 = (NetworkHandleType)loop_uo;
            break;
        }
        else{
            CanSM_NetworkIdx_u8 = CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_SizeOfCanSMNetworks_u8 + (uint8)1;
        }
   }
    return CanSM_NetworkIdx_u8;
}

FUNC(void, CANSM_CODE) CanSM_StopCtrl(VAR(NetworkHandleType, AUTOMATIC) network){
   P2CONST(CanSM_NetworkConf_tst, AUTOMATIC, CANSM_CONST) CanSM_NetworkConf_ps;
   VAR(uint8, AUTOMATIC) CanSM_ControllerId_u8;
   VAR(uint8, AUTOMATIC) CanSM_Ctrl_index_u8;
   VAR(uint8, AUTOMATIC) CanSM_Ctrl_Status_u8[CANSM_NUM_CAN_CONTROLLERS];
   VAR(CanSM_NetworkModeStateType_ten, AUTOMATIC) CanSM_CurrNwMode_en;
   VAR(uint8, AUTOMATIC) CanSM_Controller_Counter_u8 = 0;
   CanSM_NetworkConf_ps = &CanSM_Network_pcst[network];
   CanSM_CurrNwMode_en = CanSM_CurrNw_Mode_en[network];
   for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
   	CanSM_ControllerId_u8 = CanSM_NetworkConf_ps->Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
   	if(CanSM_ControllerState_en[CanSM_ControllerId_u8] != CANSM_ControllerState_STOPPED){
            if(E_NOT_OK == CanIf_SetControllerMode(CanSM_ControllerId_u8,EcuabCanIf_eModeController_STOPPED)){
   			CanSM_Ctrl_Status_u8[CanSM_Ctrl_index_u8] = CANSM_FALSE;
   			CanSM_Num_Unsuccessful_ModeReq_au8[network]++;
   			break;
   		}
   		else{
   			 CanSM_Ctrl_Status_u8[CanSM_Ctrl_index_u8] = CANSM_TRUE;
   		}
   	}
   	else{
   		CanSM_Ctrl_Status_u8[CanSM_Ctrl_index_u8] = CANSM_TRUE;
   	}
   }
   for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
        if(CanSM_Ctrl_Status_u8[CanSM_Ctrl_index_u8] == CANSM_TRUE){
   	    CanSM_Controller_Counter_u8++;
   	}
   }
   if(CanSM_Controller_Counter_u8 == CanSM_NetworkConf_ps->SizeofController_u8 ){
   	if(CanSM_Ctrl_ModeInd_ab[network] == TRUE){
   		CanSM_Ctrl_ModeInd_ab[network] = FALSE;
   		CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
   		CanSM_Controller_Counter_u8 = CANSM_ZERO;

   		if((CanSM_CurrNwMode_en == CANSM_BSM_S_PRE_NOCOM) && (CanSM_PreNoCom_Substates_en[network] == CANSM_S_CC_STOPPED)){
   			CanSM_PreNoCom_Substates_en[network]= CANSM_S_CC_SLEEP;
   		}
   		else if((CanSM_CurrNwMode_en == CANSM_BSM_S_PRE_FULLCOM) && (CanSM_PreFullCom_Substates_en[network] == CANSM_PRE_FULLCOM_S_CC_STOPPED)){
   			CanSM_PreFullCom_Substates_en[network] = CANSM_PRE_FULLCOM_S_CC_STARTED;
   		}
   		else if((CanSM_CurrNwMode_en == CANSM_BSM_WUVALIDATION) && (CanSM_WakeUpValidation_Substates_en[network] == CANSM_WAKEUP_VALIDATION_S_CC_STOPPED)){
   			CanSM_WakeUpValidation_Substates_en[network] = CANSM_WAKEUP_VALIDATION_S_CC_STARTED;
   		}
   		else if((CanSM_CurrNwMode_en == CANSM_BSM_S_TX_TIMEOUT_EXCEPTION) && (CanSM_TxTimeoutexception_Substates_en[network] == CANSM_TxTimeoutException_S_CC_STOPPED)){
   			CanSM_TxTimeoutexception_Substates_en[network] = CANSM_TxTimeoutException_S_CC_STARTED;
   		}
   		else{
   		}
   	}
        else{
   		SchM_Enter_CanSM_BOR_Nw_ModesNoNest();

   		if((CanSM_CurrNwMode_en == CANSM_BSM_S_PRE_NOCOM) && (CanSM_PreNoCom_Substates_en[network] == CANSM_S_CC_STOPPED)){
   			CanSM_PreNoCom_Substates_en[network]= CANSM_S_CC_STOPPED_WAIT;
   		}
   		else if((CanSM_CurrNwMode_en == CANSM_BSM_S_PRE_FULLCOM) && (CanSM_PreFullCom_Substates_en[network] == CANSM_PRE_FULLCOM_S_CC_STOPPED)){
   			CanSM_PreFullCom_Substates_en[network] = CANSM_PRE_FULLCOM_S_CC_STOPPED_WAIT;
   		}
   		else if((CanSM_CurrNwMode_en == CANSM_BSM_WUVALIDATION) && (CanSM_WakeUpValidation_Substates_en[network] == CANSM_WAKEUP_VALIDATION_S_CC_STOPPED)){
   			CanSM_WakeUpValidation_Substates_en[network] = CANSM_WAKEUP_VALIDATION_S_CC_STOPPED_WAIT;
   		}
   		else if((CanSM_CurrNwMode_en == CANSM_BSM_S_TX_TIMEOUT_EXCEPTION) && (CanSM_TxTimeoutexception_Substates_en[network] == CANSM_TxTimeoutException_S_CC_STOPPED)){
   			CanSM_TxTimeoutexception_Substates_en[network] = CANSM_TxTimeoutException_S_CC_STOPPED_WAIT;
   		}
   		else{
   		}
   		SchM_Exit_CanSM_BOR_Nw_ModesNoNest();
            CanSM_StartTimer(network);
        }
   }
   else{
        if(CanSM_Num_Unsuccessful_ModeReq_au8[network] >= CanSM_ModeRepeatReq_Max_u8){
            CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
   		if((CanSM_CurrNwMode_en == CANSM_BSM_S_PRE_NOCOM) && (CanSM_PreNoCom_Substates_en[network] == CANSM_S_CC_STOPPED)){
   			CanSM_PreNoCom_Substates_en[network]= CANSM_S_CC_STOPPED;
   		}
   		else if((CanSM_CurrNwMode_en== CANSM_BSM_S_PRE_FULLCOM) && (CanSM_PreFullCom_Substates_en[network] == CANSM_PRE_FULLCOM_S_CC_STOPPED)){
   		    CanSM_PreFullCom_Substates_en[network] = CANSM_PRE_FULLCOM_DEFAULT;
               CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
               CanSM_CurrNw_Mode_en[network] = CANSM_BSM_S_PRE_NOCOM;
               CanSM_ReqComM_Mode_en[network] = COMM_NO_COMMUNICATION;
               if(CanSM_Network_pcst[network].Trcv_hndle_u8 != 255u){
                    CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
                }
               else{
                    CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
                }
   		}
   		else if((CanSM_CurrNwMode_en == CANSM_BSM_WUVALIDATION) && (CanSM_WakeUpValidation_Substates_en[network] == CANSM_WAKEUP_VALIDATION_S_CC_STOPPED)){
   			CanSM_WakeUpValidation_Substates_en[network] = CANSM_WAKEUP_VALIDATION_DEFAULT;
   			CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
   			CanSM_CurrNw_Mode_en[network] = CANSM_BSM_S_PRE_NOCOM;
   			CanSM_ReqComM_Mode_en[network] = COMM_NO_COMMUNICATION;
   			if(CanSM_Network_pcst[network].Trcv_hndle_u8 != 255u){

   				CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
   			}
               else{
                    CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
                }
   		}
   		else if((CanSM_CurrNwMode_en == CANSM_BSM_S_TX_TIMEOUT_EXCEPTION) && (CanSM_TxTimeoutexception_Substates_en[network] == CANSM_TxTimeoutException_S_CC_STOPPED)){
   			CanSM_TxTimeoutexception_Substates_en[network] = CANSM_TxTimeoutException_S_CC_STOPPED;
   		}
   		else{
   		}
        }
        else{
        }
   }
}

FUNC(void, CANSM_CODE) CanSM_StartCtrl(VAR(NetworkHandleType, AUTOMATIC) network){
   P2CONST(CanSM_NetworkConf_tst, AUTOMATIC, CANSM_CONST) CanSM_NetworkConf_ps;
   VAR(uint8, AUTOMATIC) CanSM_ControllerId_u8;
   VAR(uint8, AUTOMATIC) CanSM_Ctrl_index_u8;
   VAR(uint8, AUTOMATIC) CanSM_Ctrl_Status_u8[CANSM_NUM_CAN_CONTROLLERS];
   VAR(CanSM_NetworkModeStateType_ten, AUTOMATIC) CanSM_CurrNwMode_en;
   VAR(uint8, AUTOMATIC) CanSM_Controller_Counter_u8 = 0;
   CanSM_NetworkConf_ps = &CanSM_Network_pcst[network];
   CanSM_CurrNwMode_en = CanSM_CurrNw_Mode_en[network];
   for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
   	CanSM_ControllerId_u8 = CanSM_NetworkConf_ps->Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
   	if(CanSM_ControllerState_en[CanSM_ControllerId_u8] != CANSM_ControllerState_STARTED){
            if(E_NOT_OK == CanIf_SetControllerMode(CanSM_ControllerId_u8,EcuabCanIf_eModeController_STARTED)){
   			CanSM_Ctrl_Status_u8[CanSM_Ctrl_index_u8] = CANSM_FALSE;
   			CanSM_Num_Unsuccessful_ModeReq_au8[network]++;
   			break;
   		}
   		else{
   			 CanSM_Ctrl_Status_u8[CanSM_Ctrl_index_u8] = CANSM_TRUE;
   		}
   	}
   	else{
   		CanSM_Ctrl_Status_u8[CanSM_Ctrl_index_u8] = CANSM_TRUE;
   	}
   }
   for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
        if(CanSM_Ctrl_Status_u8[CanSM_Ctrl_index_u8] == CANSM_TRUE){
   		CanSM_Controller_Counter_u8++;
   	}
   }
   if(CanSM_Controller_Counter_u8 == CanSM_NetworkConf_ps->SizeofController_u8 ){
   	if(CanSM_Ctrl_ModeInd_ab[network] == TRUE)
   	{
   		CanSM_Ctrl_ModeInd_ab[network] = FALSE;
   		CanSM_Num_Unsuccessful_ModeReq_au8[network]= CANSM_ZERO;
   		if((CanSM_CurrNwMode_en == CANSM_BSM_S_PRE_FULLCOM) && (CanSM_PreFullCom_Substates_en[network] == CANSM_PRE_FULLCOM_S_CC_STARTED)){
                CanSM_PreFullCom_Substates_en[network] = CANSM_PRE_FULLCOM_DEFAULT;
            }
   		else if((CanSM_CurrNwMode_en == CANSM_BSM_WUVALIDATION) && (CanSM_WakeUpValidation_Substates_en[network] == CANSM_WAKEUP_VALIDATION_S_CC_STARTED)){
   			CanSM_WakeUpValidation_Substates_en[network] = CANSM_WAKEUP_VALIDATION_DEFAULT;
   		}
   		else if((CanSM_CurrNwMode_en == CANSM_BSM_S_TX_TIMEOUT_EXCEPTION) && (CanSM_TxTimeoutexception_Substates_en[network] == CANSM_TxTimeoutException_S_CC_STARTED)){
   			CanSM_TxTimeoutexception_Substates_en[network] = CANSM_TxTimeoutException_DEFAULT;
   		}
   		else{
   		}
   	}
        else{
   		SchM_Enter_CanSM_BOR_Nw_ModesNoNest();
            if((CanSM_CurrNwMode_en== CANSM_BSM_S_PRE_FULLCOM) && (CanSM_PreFullCom_Substates_en[network] == CANSM_PRE_FULLCOM_S_CC_STARTED)){
                CanSM_PreFullCom_Substates_en[network] = CANSM_PRE_FULLCOM_S_CC_STARTED_WAIT;
            }
   		else if((CanSM_CurrNwMode_en == CANSM_BSM_WUVALIDATION) && (CanSM_WakeUpValidation_Substates_en[network] == CANSM_WAKEUP_VALIDATION_S_CC_STARTED)){
   			CanSM_WakeUpValidation_Substates_en[network] = CANSM_WAKEUP_VALIDATION_S_CC_STARTED_WAIT;
   		}
   		else if((CanSM_CurrNwMode_en == CANSM_BSM_S_TX_TIMEOUT_EXCEPTION) && (CanSM_TxTimeoutexception_Substates_en[network] == CANSM_TxTimeoutException_S_CC_STARTED)){
   			CanSM_TxTimeoutexception_Substates_en[network] = CANSM_TxTimeoutException_S_CC_STARTED_WAIT;
   		}
   		else{
   		}
   		SchM_Exit_CanSM_BOR_Nw_ModesNoNest();
            CanSM_StartTimer(network);
        }
   }
   else{
        if(CanSM_Num_Unsuccessful_ModeReq_au8[network] >= CanSM_ModeRepeatReq_Max_u8){
            CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
           if((CanSM_CurrNw_Mode_en[network] == CANSM_BSM_S_PRE_FULLCOM) && (CanSM_PreFullCom_Substates_en[network] == CANSM_PRE_FULLCOM_S_CC_STARTED)){
                CanSM_PreFullCom_Substates_en[network] = CANSM_PRE_FULLCOM_DEFAULT;
                CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
                CanSM_CurrNw_Mode_en[network] = CANSM_BSM_S_PRE_NOCOM;
                CanSM_ReqComM_Mode_en[network] = COMM_NO_COMMUNICATION;
                if(CanSM_Network_pcst[network].Trcv_hndle_u8 != 255u){
                    CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
                }
                else{
                    CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
                }
            }
   		else if((CanSM_CurrNw_Mode_en[network] == CANSM_BSM_WUVALIDATION) && (CanSM_WakeUpValidation_Substates_en[network] == CANSM_WAKEUP_VALIDATION_S_CC_STARTED)){
   		    CanSM_WakeUpValidation_Substates_en[network] = CANSM_WAKEUP_VALIDATION_DEFAULT;
               CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
               CanSM_CurrNw_Mode_en[network] = CANSM_BSM_S_PRE_NOCOM;
               CanSM_ReqComM_Mode_en[network] = COMM_NO_COMMUNICATION;
               if(CanSM_Network_pcst[network].Trcv_hndle_u8 != 255u){
                    CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
                }
               else{
                    CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
                }
   		}
   		else if((CanSM_CurrNw_Mode_en[network] == CANSM_BSM_S_TX_TIMEOUT_EXCEPTION) && (CanSM_TxTimeoutexception_Substates_en[network] == CANSM_TxTimeoutException_S_CC_STARTED)){
   			CanSM_TxTimeoutexception_Substates_en[network] = CANSM_TxTimeoutException_S_CC_STOPPED;
   		}
   		else{
   		}
        }
        else{
        }
   }
}

FUNC(void, CANSM_CODE) CanSM_SleepCtrl(VAR(NetworkHandleType, AUTOMATIC) network){
   P2CONST(CanSM_NetworkConf_tst, AUTOMATIC, CANSM_CONST) CanSM_NetworkConf_ps;
   VAR(uint8, AUTOMATIC) CanSM_ControllerId_u8;
   VAR(uint8, AUTOMATIC) CanSM_Ctrl_index_u8;
   VAR(uint8, AUTOMATIC) CanSM_Ctrl_Status_u8[CANSM_NUM_CAN_CONTROLLERS];
   VAR(uint8, AUTOMATIC) CanSM_Controller_Counter_u8 = 0;
   CanSM_NetworkConf_ps = &CanSM_Network_pcst[network];
   for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
   	CanSM_ControllerId_u8 = CanSM_NetworkConf_ps->Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
   	if(CanSM_ControllerState_en[CanSM_ControllerId_u8] != CANSM_ControllerState_SLEEP){
            if(E_NOT_OK == CanIf_SetControllerMode(CanSM_ControllerId_u8,EcuabCanIf_eModeController_SLEEP)){
   			CanSM_Ctrl_Status_u8[CanSM_Ctrl_index_u8] = CANSM_FALSE;
   			CanSM_Num_Unsuccessful_ModeReq_au8[network]++;
   			break;
   		}
   		else{
   			 CanSM_Ctrl_Status_u8[CanSM_Ctrl_index_u8] = CANSM_TRUE;
   		}
   	}
   	else{
   		CanSM_Ctrl_Status_u8[CanSM_Ctrl_index_u8] = CANSM_TRUE;
   	}
   }
   for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
        if(CanSM_Ctrl_Status_u8[CanSM_Ctrl_index_u8] == CANSM_TRUE){
   	    CanSM_Controller_Counter_u8++;
   	}
   }
   if(CanSM_Controller_Counter_u8 == CanSM_NetworkConf_ps->SizeofController_u8 ){
   	if(CanSM_Ctrl_ModeInd_ab[network] == TRUE){
   		CanSM_Ctrl_ModeInd_ab[network] = FALSE;
   		CanSM_PreNoCom_Substates_en[network]= CANSM_S_TRCV_NORMAL;
   		CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
   	}
   	else{
   		CanSM_PreNoCom_Substates_en[network]= CANSM_S_CC_SLEEP_WAIT;
   		CanSM_StartTimer(network);
   	}
   }
   else{
        if(CanSM_Num_Unsuccessful_ModeReq_au8[network] >= CanSM_ModeRepeatReq_Max_u8){
            CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;

   	     CanSM_PreNoCom_Substates_en[network]= CANSM_S_CC_STOPPED;
        }
        else{}
   }
}

FUNC(void, CANSM_CODE) CanSM_NO2FULL_COM(VAR(NetworkHandleType, AUTOMATIC) network){
   VAR(CanSM_PreFullCom_Substates_ten, CANSM_VAR) CanSM_PreFullCom_Substates;
   VAR(CanSM_BswMCurrentStateType, AUTOMATIC) CanSM_BswM_Mode_en;
   P2CONST(CanSM_NetworkConf_tst, AUTOMATIC, CANSM_APPL_DATA) NetworkConf_ps;
   VAR(uint8, AUTOMATIC) CanSM_Ctrl_index_u8;
   VAR(uint8, AUTOMATIC) CanSM_ControllerId_u8;
   VAR(Type_SwcServiceComM_tMode, AUTOMATIC) CanSM_reqComM_Mode_uo;
   NetworkConf_ps = &CanSM_Network_pcst[network];
   CanSM_PreFullCom_Substates = CanSM_PreFullCom_Substates_en[network];
   if(CanSM_Num_Unsuccessful_ModeReq_au8[network] < CanSM_ModeRepeatReq_Max_u8){
            switch(CanSM_PreFullCom_Substates){
                case CANSM_PRE_FULLCOM_S_TRCV_NORMAL_WAIT:{
                    if(CanSM_Trcv_ModeInd_ab[network]==TRUE){
                        if(CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_NetworkConf_pcst[network].Trcv_hndle_u8 != 255){
                            CanSM_Trcv_ModeInd_ab[network] = FALSE;
                        }
                        CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_PreFullCom_Substates_en[network]= CANSM_PRE_FULLCOM_S_CC_STOPPED;
                        CanSM_PreFullCom_Substates = CanSM_PreFullCom_Substates_en[network];
                        CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
                    }
                    else{
                        if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                            CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                            CanSM_PreFullCom_Substates_en[network]= CANSM_PRE_FULLCOM_S_TRCV_NORMAL;
                            CanSM_PreFullCom_Substates = CanSM_PreFullCom_Substates_en[network];
                        }
                    }
                }
                break;

   			case CANSM_PRE_FULLCOM_S_CC_STOPPED_WAIT:{
                    if(CanSM_Ctrl_ModeInd_ab[network] == TRUE){
                        CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_Ctrl_ModeInd_ab[network] = FALSE;
                        CanSM_PreFullCom_Substates_en[network] = CANSM_PRE_FULLCOM_S_CC_STARTED;
                        CanSM_PreFullCom_Substates = CanSM_PreFullCom_Substates_en[network];
                        CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
                   }
                    else{
                        if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                            CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                            CanSM_PreFullCom_Substates_en[network]= CANSM_PRE_FULLCOM_S_CC_STOPPED;
                            CanSM_PreFullCom_Substates = CanSM_PreFullCom_Substates_en[network];
                        }
                    }
                }
                break;

   			case CANSM_PRE_FULLCOM_S_CC_STARTED_WAIT:{
   				if(CanSM_Ctrl_ModeInd_ab[network] == TRUE){
   					CanSM_Ctrl_ModeInd_ab[network] = FALSE;
   					CanSM_PreFullCom_Substates_en[network]= CANSM_PRE_FULLCOM_DEFAULT;
   					CanSM_PreFullCom_Substates = CanSM_PreFullCom_Substates_en[network];
   					CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
   					CanSM_BswM_Mode_en = CANSM_BSWM_FULL_COMMUNICATION;
   					BswM_CanSM_CurrentState(NetworkConf_ps->ComM_channelId_uo,CanSM_BswM_Mode_en);
   					CanSM_CurrNw_Mode_en[network]=CANSM_BSM_S_FULLCOM;
   					CanSM_Num_Unsuccessful_ModeReq_au8[network]= CANSM_ZERO;
   					CanSM_BusOff_Cntr_au8[network] = CANSM_ZERO;
   					CanSM_currBOR_State_en[network] = CANSM_S_BUS_OFF_CHECK;
   					CanSM_BORMode_au8[network] =  (uint8)CANSM_RECOVERY_ENABLED;
   					CanSM_BusSMMode_au8[network] = (Type_SwcServiceComM_tMode)CANSM_BSM_S_FULLCOM;
   					for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_Network_pcst[network].SizeofController_u8 ;CanSM_Ctrl_index_u8++){
   						CanSM_ControllerId_u8 = CanSM_Network_pcst[network].Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
   						(void)(CanIf_SetPduMode(CanSM_ControllerId_u8,EcuabCanIf_eModePdu_ONLINE));
   					}
   					CanSM_reqComM_Mode_uo = COMM_FULL_COMMUNICATION;
   					ComM_BusSM_ModeIndication(CanSM_Network_pcst[network].ComM_channelId_uo,&CanSM_reqComM_Mode_uo);
   				}
   				else{
   					if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
   						CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
   						CanSM_PreFullCom_Substates_en[network]= CANSM_PRE_FULLCOM_S_CC_STARTED;
   						CanSM_PreFullCom_Substates = CanSM_PreFullCom_Substates_en[network];
   					}
   				}
   			}
            break;

            default:
            break;
        }
   }
   else{
   	CanSM_PreFullCom_Substates_en[network] = CANSM_PRE_FULLCOM_DEFAULT;
   	CanSM_PreFullCom_Substates = CanSM_PreFullCom_Substates_en[network];
   	CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
   	CanSM_CurrNw_Mode_en[network] = CANSM_BSM_S_PRE_NOCOM;
   	CanSM_ReqComM_Mode_en[network] = COMM_NO_COMMUNICATION;
   	if(CanSM_Network_pcst[network].Trcv_hndle_u8 != 255u){
            CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
        }
   	else{
            CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
        }
   }
   if(CanSM_PreFullCom_Substates == CANSM_PRE_FULLCOM_S_TRCV_NORMAL){
        if(CanSM_Network_pcst[network].Trcv_hndle_u8 == 255u){
            CanSM_Trcv_ModeInd_ab[network] = TRUE;
            CanSM_PreFullCom_Substates_en[network] = CANSM_PRE_FULLCOM_S_CC_STOPPED;
            CanSM_PreFullCom_Substates = CanSM_PreFullCom_Substates_en[network];
        }
        else{
            CanSM_PreFullCom_Substates = CanSM_PreFullCom_Substates_en[network];
        }
   }
   if(CanSM_PreFullCom_Substates == CANSM_PRE_FULLCOM_S_CC_STOPPED){
        CanSM_StopCtrl(network);
        CanSM_PreFullCom_Substates = CanSM_PreFullCom_Substates_en[network];
   }
   if(CanSM_PreFullCom_Substates == CANSM_PRE_FULLCOM_S_CC_STARTED){
        CanSM_StartCtrl(network);
        CanSM_PreFullCom_Substates = CanSM_PreFullCom_Substates_en[network];
        if(CanSM_PreFullCom_Substates== CANSM_PRE_FULLCOM_DEFAULT){
   		CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
   		CanSM_BswM_Mode_en = CANSM_BSWM_FULL_COMMUNICATION;
   		BswM_CanSM_CurrentState(NetworkConf_ps->ComM_channelId_uo,CanSM_BswM_Mode_en);
   		CanSM_CurrNw_Mode_en[network]=CANSM_BSM_S_FULLCOM;
   		CanSM_BusOff_Cntr_au8[network] = CANSM_ZERO;
   		CanSM_StartTimer(network);
   		CanSM_currBOR_State_en[network] = CANSM_S_BUS_OFF_CHECK;
   		CanSM_BORMode_au8[network] =  (uint8)CANSM_RECOVERY_ENABLED;
   		CanSM_BusSMMode_au8[network] = (Type_SwcServiceComM_tMode)CANSM_BSM_S_FULLCOM;
   		for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_Network_pcst[network].SizeofController_u8 ;CanSM_Ctrl_index_u8++){
   			CanSM_ControllerId_u8 = CanSM_Network_pcst[network].Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
   			(void)(CanIf_SetPduMode(CanSM_ControllerId_u8,EcuabCanIf_eModePdu_ONLINE));
   		}
   		CanSM_reqComM_Mode_uo = COMM_FULL_COMMUNICATION;
   		ComM_BusSM_ModeIndication(CanSM_Network_pcst[network].ComM_channelId_uo,&CanSM_reqComM_Mode_uo);
        }
   }
}

FUNC(void, CANSM_CODE) CanSM_FULL2SILENT_COM(VAR(NetworkHandleType, AUTOMATIC) network){
   VAR(CanSM_BswMCurrentStateType, AUTOMATIC) CanSM_BswM_Mode_en;
   P2CONST(CanSM_NetworkConf_tst, AUTOMATIC, CANSM_APPL_DATA) NetworkConf_ps;
   VAR(uint8, AUTOMATIC) CanSM_Ctrl_index_u8;
   VAR(uint8, AUTOMATIC) CanSM_ControllerId_u8;
   VAR(Type_SwcServiceComM_tMode, AUTOMATIC) CanSM_reqComM_Mode_uo;
   NetworkConf_ps = &CanSM_Network_pcst[network];
   CanSM_BORMode_au8[network] =  (uint8)CANSM_RECOVERY_DISABLED;
   CanSM_currBOR_State_en[network] = CANSM_BOR_IDLE;
   CanSM_Num_Unsuccessful_ModeReq_au8[network]= CANSM_ZERO;
   CanSM_CurrNw_Mode_en[network] = CANSM_BSM_S_SILENTCOM;
   CanSM_BusSMMode_au8[network] = (Type_SwcServiceComM_tMode)CANSM_BSM_S_SILENTCOM;
   CanSM_BswM_Mode_en = CANSM_BSWM_SILENT_COMMUNICATION;
   BswM_CanSM_CurrentState(NetworkConf_ps->ComM_channelId_uo,CanSM_BswM_Mode_en);
   for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_Network_pcst[network].SizeofController_u8 ;CanSM_Ctrl_index_u8++){
        CanSM_ControllerId_u8 = CanSM_Network_pcst[network].Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
        (void)(CanIf_SetPduMode(CanSM_ControllerId_u8,EcuabCanIf_eModePdu_TX_OFFLINE));
   }
   CanSM_reqComM_Mode_uo = COMM_SILENT_COMMUNICATION ;
   ComM_BusSM_ModeIndication(CanSM_Network_pcst[network].ComM_channelId_uo, &CanSM_reqComM_Mode_uo);
}

FUNC(void, CANSM_CODE) CanSM_SILENT2FULL_COM(VAR(NetworkHandleType, AUTOMATIC) network){
   VAR(CanSM_BswMCurrentStateType, AUTOMATIC) CanSM_BswM_Mode_en;
   P2CONST(CanSM_NetworkConf_tst, AUTOMATIC, CANSM_APPL_DATA) NetworkConf_ps;
   VAR(uint8, AUTOMATIC) CanSM_Ctrl_index_u8;
   VAR(uint8, AUTOMATIC) CanSM_ControllerId_u8 = 0;
   VAR(Type_SwcServiceComM_tMode, AUTOMATIC) CanSM_reqComM_Mode_uo;
   NetworkConf_ps = &CanSM_Network_pcst[network];
   for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_Network_pcst[network].SizeofController_u8 ;CanSM_Ctrl_index_u8++){
        CanSM_ControllerId_u8 = CanSM_Network_pcst[network].Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
        (void)(CanIf_SetPduMode(CanSM_ControllerId_u8,EcuabCanIf_eModePdu_ONLINE));
   }
   CanSM_CurrNw_Mode_en[network]=CANSM_BSM_S_FULLCOM;
   CanSM_BusOff_Cntr_au8[network] = CANSM_ZERO;
   CanSM_StartTimer(network);
   CanSM_currBOR_State_en[network] = CANSM_S_BUS_OFF_CHECK;
   CanSM_BORMode_au8[network] =  (uint8)CANSM_RECOVERY_ENABLED;
   CanSM_BusSMMode_au8[network] = (Type_SwcServiceComM_tMode)CANSM_BSM_S_FULLCOM;
   CanSM_reqComM_Mode_uo = COMM_FULL_COMMUNICATION;
   ComM_BusSM_ModeIndication(CanSM_Network_pcst[network].ComM_channelId_uo,&CanSM_reqComM_Mode_uo);
   CanSM_BswM_Mode_en = CANSM_BSWM_FULL_COMMUNICATION;
   BswM_CanSM_CurrentState(NetworkConf_ps->ComM_channelId_uo,CanSM_BswM_Mode_en);
}

FUNC(void, CANSM_CODE) CanSM_TxTimeoutException_StateMachine(VAR(NetworkHandleType, AUTOMATIC) Channel){
   VAR(CanSM_TxTimeoutException_Substates_ten, AUTOMATIC) CanSM_TxTimeoutException_en;
   VAR(uint8, AUTOMATIC) CanSM_Ctrl_index_u8;
   VAR(uint8, AUTOMATIC) CanSM_ControllerId_u8 = 0;
   CanSM_TxTimeoutException_en = CanSM_TxTimeoutexception_Substates_en[Channel];
   if(CanSM_Num_Unsuccessful_ModeReq_au8[Channel] < CanSM_ModeRepeatReq_Max_u8){
        switch(CanSM_TxTimeoutException_en){
            case CANSM_TxTimeoutException_S_CC_STOPPED_WAIT :{
                if(CanSM_Ctrl_ModeInd_ab[Channel] == TRUE){
                    CanSM_TimerConfig_ast[Channel].stTimer = CANSM_TIMER_ELAPSED;
                    CanSM_Ctrl_ModeInd_ab[Channel] = FALSE;
                    CanSM_TxTimeoutexception_Substates_en[Channel] = CANSM_TxTimeoutException_S_CC_STARTED;
                    CanSM_TxTimeoutException_en = CanSM_TxTimeoutexception_Substates_en[Channel];
                    CanSM_Num_Unsuccessful_ModeReq_au8[Channel] = CANSM_ZERO;
               }
                else{
                    if(CanSM_TimerConfig_ast[Channel].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                        CanSM_TimerConfig_ast[Channel].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_TxTimeoutexception_Substates_en[Channel] = CANSM_TxTimeoutException_S_CC_STOPPED;
                        CanSM_TxTimeoutException_en = CanSM_TxTimeoutexception_Substates_en[Channel];
                    }
                }
            }
            break;

            case  CANSM_TxTimeoutException_S_CC_STARTED_WAIT:{
                if(CanSM_Ctrl_ModeInd_ab[Channel] == TRUE){
                    CanSM_TimerConfig_ast[Channel].stTimer = CANSM_TIMER_ELAPSED;
                    CanSM_Ctrl_ModeInd_ab[Channel] = FALSE;
                    CanSM_TxTimeoutexception_Substates_en[Channel] = CANSM_TxTimeoutException_DEFAULT;
                    CanSM_TxTimeoutException_en = CanSM_TxTimeoutexception_Substates_en[Channel];
                    CanSM_Num_Unsuccessful_ModeReq_au8[Channel] = CANSM_ZERO;
                    for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_Network_pcst[Channel].SizeofController_u8 ;CanSM_Ctrl_index_u8++){
                        CanSM_ControllerId_u8 = CanSM_Network_pcst[Channel].Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
                        (void)(CanIf_SetPduMode(CanSM_ControllerId_u8, EcuabCanIf_eModePdu_ONLINE));
                    }
                    CanSM_currBOR_State_en[Channel] = CANSM_S_NO_BUS_OFF;
                    CanSM_CurrNw_Mode_en[Channel] = CANSM_BSM_S_FULLCOM;
               }
                else{
                    if(CanSM_TimerConfig_ast[Channel].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                        CanSM_TimerConfig_ast[Channel].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_TxTimeoutexception_Substates_en[Channel] = CANSM_TxTimeoutException_S_CC_STARTED;
                        CanSM_TxTimeoutException_en = CanSM_TxTimeoutexception_Substates_en[Channel];
                    }
                }
            }
            break;

            default:
            break;
        }
   }
   else{
        CanSM_Num_Unsuccessful_ModeReq_au8[Channel] = CANSM_ZERO;
        CanSM_TxTimeoutexception_Substates_en[Channel] = CANSM_TxTimeoutException_S_CC_STOPPED;
        CanSM_TxTimeoutException_en = CanSM_TxTimeoutexception_Substates_en[Channel];
   }
   if(CanSM_TxTimeoutException_en == CANSM_TxTimeoutException_S_CC_STOPPED){
        CanSM_StopCtrl(Channel);
        CanSM_TxTimeoutException_en = CanSM_TxTimeoutexception_Substates_en[Channel];
   }
   if(CanSM_TxTimeoutException_en == CANSM_TxTimeoutException_S_CC_STARTED){
        CanSM_StartCtrl(Channel);
        CanSM_TxTimeoutException_en = CanSM_TxTimeoutexception_Substates_en[Channel];
        if(CanSM_TxTimeoutException_en == CANSM_TxTimeoutException_DEFAULT){
            for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_Network_pcst[Channel].SizeofController_u8 ;CanSM_Ctrl_index_u8++){
                CanSM_ControllerId_u8 = CanSM_Network_pcst[Channel].Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
                (void)(CanIf_SetPduMode(CanSM_ControllerId_u8, EcuabCanIf_eModePdu_ONLINE));
            }
            CanSM_currBOR_State_en[Channel] = CANSM_S_NO_BUS_OFF;
            CanSM_CurrNw_Mode_en[Channel] = CANSM_BSM_S_FULLCOM;
        }
   }
}

FUNC(void, CANSM_CODE) CanSM_WakeUpValidation_StateMachine(VAR(NetworkHandleType, AUTOMATIC) network){
   VAR(CanSM_WakeUpValidation_Substates_ten, CANSM_VAR) CanSM_WakeUpValidation_Substates;
   CanSM_WakeUpValidation_Substates = CanSM_WakeUpValidation_Substates_en[network];
   if(CanSM_Num_Unsuccessful_ModeReq_au8[network] < CanSM_ModeRepeatReq_Max_u8){
        switch(CanSM_WakeUpValidation_Substates){
            case CANSM_WAKEUP_VALIDATION_S_TRCV_NORMAL_WAIT:{
                if(CanSM_Trcv_ModeInd_ab[network]==TRUE){
                    if(CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_NetworkConf_pcst[network].Trcv_hndle_u8 != 255){
                        CanSM_Trcv_ModeInd_ab[network] = FALSE;
                    }
                    CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                    CanSM_WakeUpValidation_Substates_en[network]= CANSM_WAKEUP_VALIDATION_S_CC_STOPPED;
                    CanSM_WakeUpValidation_Substates = CanSM_WakeUpValidation_Substates_en[network];
                    CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
                }
                else{
                    if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                        CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_WakeUpValidation_Substates_en[network]= CANSM_WAKEUP_VALIDATION_S_TRCV_NORMAL;
                        CanSM_WakeUpValidation_Substates = CanSM_WakeUpValidation_Substates_en[network];
                    }
                }
            }
            break;

   		case CANSM_WAKEUP_VALIDATION_S_CC_STOPPED_WAIT:{
                if(CanSM_Ctrl_ModeInd_ab[network] == TRUE){
                    CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                    CanSM_Ctrl_ModeInd_ab[network] = FALSE;
                    CanSM_WakeUpValidation_Substates_en[network] = CANSM_WAKEUP_VALIDATION_S_CC_STARTED;
                    CanSM_WakeUpValidation_Substates = CanSM_WakeUpValidation_Substates_en[network];
                    CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
   			}
                else{
                    if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                        CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                        CanSM_WakeUpValidation_Substates_en[network]= CANSM_WAKEUP_VALIDATION_S_CC_STOPPED;
                        CanSM_WakeUpValidation_Substates = CanSM_WakeUpValidation_Substates_en[network];
                    }
                }
            }
            break;

   		case CANSM_WAKEUP_VALIDATION_S_CC_STARTED_WAIT:{
   			if(CanSM_Ctrl_ModeInd_ab[network] == TRUE){
   				CanSM_Ctrl_ModeInd_ab[network] = FALSE;
   				CanSM_WakeUpValidation_Substates_en[network]= CANSM_WAKEUP_VALIDATION_DEFAULT;
   				CanSM_Wuvalidation_Start_ab[network] = FALSE;
   				CanSM_WakeUpValidation_Substates = CanSM_WakeUpValidation_Substates_en[network];
   				CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
   			}
   			else{
   				if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
   					CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
   					CanSM_WakeUpValidation_Substates_en[network]= CANSM_WAKEUP_VALIDATION_S_CC_STARTED;
   					CanSM_WakeUpValidation_Substates = CanSM_WakeUpValidation_Substates_en[network];
   				}
   			}
   		}
   		break;

   		default:
   		break;
   	}
   }
   else{
   	CanSM_WakeUpValidation_Substates_en[network] = CANSM_WAKEUP_VALIDATION_DEFAULT;
   	CanSM_Wuvalidation_Start_ab[network] = FALSE;
   	CanSM_WakeUpValidation_Substates = CanSM_WakeUpValidation_Substates_en[network];
   	CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
   	CanSM_CurrNw_Mode_en[network] = CANSM_BSM_S_PRE_NOCOM;
   	CanSM_ReqComM_Mode_en[network] = COMM_NO_COMMUNICATION;
   	if(CanSM_Network_pcst[network].Trcv_hndle_u8 != 255u){
   			CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
   		}
   		else{
   			CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
   		}
   	}
   if(CanSM_WakeUpValidation_Substates == CANSM_WAKEUP_VALIDATION_S_TRCV_NORMAL){
   	if(CanSM_Network_pcst[network].Trcv_hndle_u8 == 255u){
   		CanSM_Trcv_ModeInd_ab[network] = TRUE;
   		CanSM_WakeUpValidation_Substates_en[network] = CANSM_WAKEUP_VALIDATION_S_CC_STOPPED;
   		CanSM_WakeUpValidation_Substates = CanSM_WakeUpValidation_Substates_en[network];
   	}
   	else{
   		CanSM_WakeUpValidation_Substates = CanSM_WakeUpValidation_Substates_en[network];
   	}
   }
   if(CanSM_WakeUpValidation_Substates == CANSM_WAKEUP_VALIDATION_S_CC_STOPPED){
   	CanSM_StopCtrl(network);
   	CanSM_WakeUpValidation_Substates = CanSM_WakeUpValidation_Substates_en[network];
   }
   if(CanSM_WakeUpValidation_Substates == CANSM_WAKEUP_VALIDATION_S_CC_STARTED){
   	CanSM_StartCtrl(network);
   	CanSM_WakeUpValidation_Substates = CanSM_WakeUpValidation_Substates_en[network];
   	if(CanSM_WakeUpValidation_Substates== CANSM_WAKEUP_VALIDATION_DEFAULT){
   		CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
   		CanSM_Wuvalidation_Start_ab[network] = FALSE;
   	}
   }
}

FUNC(void, CANSM_CODE) CanSM_PreNoCom_Exit(VAR(NetworkHandleType, AUTOMATIC) network){
   VAR(CanSM_BswMCurrentStateType, AUTOMATIC) CanSM_BswM_Mode_en;
   CanSM_Network_Init_ab[network] = TRUE;
   CanSM_BswM_Mode_en = CANSM_BSWM_NO_COMMUNICATION;
   BswM_CanSM_CurrentState(CanSM_Network_pcst[network].ComM_channelId_uo,CanSM_BswM_Mode_en);
   if(CanSM_Wuvalidation_Start_ab[network] == TRUE){
        CanSM_CurrNw_Mode_en[network]= CANSM_BSM_WUVALIDATION;
        CanSM_WakeUpValidation_Substates_en[network] = CANSM_WAKEUP_VALIDATION_S_TRCV_NORMAL;
   }
   else{
        CanSM_CurrNw_Mode_en[network]= CANSM_BSM_S_NOCOM;
   }
}

FUNC(void, CANSM_CODE) CanSM_BOR_SilentCom_Exit(VAR(NetworkHandleType, AUTOMATIC) network){
   P2CONST(CanSM_NetworkConf_tst, AUTOMATIC, CANSM_CONST) CanSM_NetworkConf_ps;
   VAR(CanSM_BswMCurrentStateType, AUTOMATIC) CanSM_BswM_Mode_en;
   VAR(Type_SwcServiceComM_tMode, AUTOMATIC) CanSM_ComM_Mode_uo;
   CanSM_NetworkConf_ps = &CanSM_Network_pcst[network];
   CanSM_Ctrl_ModeInd_ab[network] = FALSE;
   CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
   CanSM_BOR_SilentCom_ab[network] = FALSE;
   CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
   if(CanSM_ReqComM_Mode_en[network] == COMM_NO_COMMUNICATION){
   	CanSM_CurrNw_Mode_en[network] = CANSM_BSM_S_PRE_NOCOM;
   	CanSM_currBOR_State_en[network] = CANSM_BOR_IDLE;
   	if(CanSM_Network_pcst[network].Trcv_hndle_u8 != 255u){
            CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
        }
   	else{
            CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
        }
   }
   else{
       CanSM_BswM_Mode_en = CANSM_BSWM_SILENT_COMMUNICATION;
       BswM_CanSM_CurrentState(CanSM_NetworkConf_ps->ComM_channelId_uo,CanSM_BswM_Mode_en);
       CanSM_BusSMMode_au8[network] = (Type_SwcServiceComM_tMode)CANSM_BSM_S_SILENTCOM;
       CanSM_ComM_Mode_uo = COMM_SILENT_COMMUNICATION;
       ComM_BusSM_ModeIndication(CanSM_Network_pcst[network].ComM_channelId_uo,&CanSM_ComM_Mode_uo);
   }
}
#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.hpp"
