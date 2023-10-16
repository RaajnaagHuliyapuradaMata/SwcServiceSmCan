#include "Std_Types.hpp"

#include "CanSM_Prv.hpp"

#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.hpp"
FUNC(void, CANSM_CODE) CanSM_ControllerBusOff(VAR(uint8, AUTOMATIC) ControllerId ){
       VAR(ComM_ModeType,     AUTOMATIC) CanSM_ComM_ModeType_uo;
       VAR(CanSM_BswMCurrentStateType,     AUTOMATIC) CanSM_BswM_Mode_en;
       VAR(CanSM_BusOffRecoveryStateType_ten,  AUTOMATIC) CanSM_CurrBORState_en;
   P2CONST(CanSM_NetworkConf_tst, AUTOMATIC, CANSM_CONST) CanSM_NetworkConf_ps;
       VAR(uint8,     AUTOMATIC) network_indx_u8;
       VAR(boolean,     AUTOMATIC) BusoffISRPend_Temp_b;
       VAR(uint8,     AUTOMATIC) CanSM_BORMode_u8;
   network_indx_u8       = (uint8)CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_NetworktoCtrlConf_pcu8[ControllerId];
   CanSM_NetworkConf_ps  = &CanSM_Network_pcst[network_indx_u8];
   BusoffISRPend_Temp_b  = CanSM_BusOffISRPend_ab[network_indx_u8];
   CanSM_BORMode_u8      = CanSM_BORMode_au8[network_indx_u8];
   CanSM_CurrBORState_en = CanSM_currBOR_State_en[network_indx_u8];

   if(CanSM_CurrNw_Mode_en[network_indx_u8] == CANSM_BSM_S_SILENTCOM){
      if((CanSM_BusOff_Indicated_ab[network_indx_u8] == TRUE) || (BusoffISRPend_Temp_b == TRUE)){
         CanSM_BusOff_Indicated_ab[network_indx_u8] = FALSE;
         CanSM_BusOffISRPend_ab[network_indx_u8] = FALSE;
         CanSM_BOR_SilentCom_ab[network_indx_u8] = TRUE;
      }
      CanSM_currBOR_State_en[network_indx_u8] = CANSM_S_RESTART_CC;
      Dem_ReportErrorStatus(CanSM_Network_pcst[network_indx_u8].BusOffEventId_uo,DEM_EVENT_STATUS_PREFAILED);
      CanSM_StartTimer(network_indx_u8);
   }
   else{
      CanSM_BusOff_Indicated_ab[network_indx_u8] = TRUE;
      if(CanSM_BORMode_u8 == (uint8)CANSM_RECOVERY_ENABLED){
         if(E_OK == CanSM_GetMutex(network_indx_u8)){
            if((CanSM_CurrBORState_en == CANSM_S_BUS_OFF_CHECK) || (CanSM_CurrBORState_en == CANSM_S_NO_BUS_OFF)){
               CanSM_BswM_Mode_en = CANSM_BSWM_BUS_OFF;
               BswM_CanSM_CurrentState(CanSM_NetworkConf_ps->ComM_channelId_uo,CanSM_BswM_Mode_en);
               CanSM_BusSMMode_au8[network_indx_u8] = (ComM_ModeType)CANSM_BSM_S_SILENTCOM;
               if(CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_NetworkConf_pcst[network_indx_u8].SizeofController_u8 > 1u){
                  CanSM_BOR_Controller_Stopped_state_en[network_indx_u8] = CANSM_BOR_CONTROLLER_STOPPED_REQUEST;
               }
               else{
                  CanSM_currBOR_State_en[network_indx_u8] = CANSM_S_RESTART_CC;
                  CanSM_StartTimer(network_indx_u8);
               }
               CanSM_CurrBORState_en = CanSM_currBOR_State_en[network_indx_u8];
               CanSM_ComM_ModeType_uo = COMM_SILENT_COMMUNICATION;
               ComM_BusSM_ModeIndication(CanSM_Network_pcst[network_indx_u8].ComM_channelId_uo,&CanSM_ComM_ModeType_uo);
               Dem_ReportErrorStatus(CanSM_Network_pcst[network_indx_u8].BusOffEventId_uo,DEM_EVENT_STATUS_PREFAILED);
            }
            CanSM_ReleaseMutex(network_indx_u8);
         }
         else if(BusoffISRPend_Temp_b == FALSE){
            CanSM_BusOffISRPend_ab[network_indx_u8]= TRUE;
            if((CanSM_CurrBORState_en == CANSM_S_BUS_OFF_CHECK) || (CanSM_CurrBORState_en == CANSM_S_NO_BUS_OFF)){
               CanSM_BswM_Mode_en = CANSM_BSWM_BUS_OFF;
               BswM_CanSM_CurrentState(CanSM_NetworkConf_ps->ComM_channelId_uo,CanSM_BswM_Mode_en);
               CanSM_BusSMMode_au8[network_indx_u8] = (ComM_ModeType)CANSM_BSM_S_SILENTCOM;
               if(CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_NetworkConf_pcst[network_indx_u8].SizeofController_u8 > 1u){
                  CanSM_BOR_Controller_Stopped_state_en[network_indx_u8] = CANSM_BOR_CONTROLLER_STOPPED_REQUEST;
               }
               else{
                  CanSM_currBOR_State_en[network_indx_u8] = CANSM_S_RESTART_CC;
                  CanSM_StartTimer(network_indx_u8);
               }
               CanSM_CurrBORState_en = CanSM_currBOR_State_en[network_indx_u8];
               CanSM_ComM_ModeType_uo = COMM_SILENT_COMMUNICATION;
               ComM_BusSM_ModeIndication(CanSM_Network_pcst[network_indx_u8].ComM_channelId_uo,&CanSM_ComM_ModeType_uo);
               Dem_ReportErrorStatus(CanSM_Network_pcst[network_indx_u8].BusOffEventId_uo,DEM_EVENT_STATUS_PREFAILED);
            }
         }
         else{
         }
      }
   }
}

FUNC(void, CANSM_CODE) CanSM_BusOffTransitions(VAR(NetworkHandleType, AUTOMATIC) network){
   VAR(CanSM_BswMCurrentStateType, AUTOMATIC) CanSM_BswM_Mode_en;
   VAR(CanSM_BusOffRecoveryStateType_ten, AUTOMATIC) CanSM_CurrBORState_en;
   VAR(CanSM_BOR_Controller_Stopped_stateType_ten, AUTOMATIC) CanSM_BOR_Controller_Stopped_states_en;
   P2CONST(CanSM_NetworkConf_tst, AUTOMATIC, CANSM_CONST) CanSM_NetworkConf_ps;
   VAR(uint8, AUTOMATIC) CanSM_ControllerId_u8;
   VAR(uint8, AUTOMATIC) CanSM_Ctrl_index_u8;
   VAR(ComM_ModeType, AUTOMATIC) CanSM_reqComM_Mode_uo;
   CanSM_NetworkConf_ps = &CanSM_Network_pcst[network];
   CanSM_CurrBORState_en = CanSM_currBOR_State_en[network];
   CanSM_BOR_Controller_Stopped_states_en =  CanSM_BOR_Controller_Stopped_state_en[network];
   if(CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_NetworkConf_pcst[network].SizeofController_u8 > 1u){
      if(CanSM_BOR_Controller_Stopped_states_en == CANSM_BOR_CONTROLLER_STOPPED_REQUEST){
         CanSM_BOR_MultipleCtrlsStop(network);
         CanSM_BOR_Controller_Stopped_states_en =  CanSM_BOR_Controller_Stopped_state_en[network];
         if(CanSM_BOR_Controller_Stopped_states_en == CANSM_BOR_CONTROLLER_STOPPED_REQUEST_COMPLETED){
            CanSM_currBOR_State_en[network] = CANSM_S_RESTART_CC;
            CanSM_CurrBORState_en = CanSM_currBOR_State_en[network];
            CanSM_StartTimer(network);
         }
      }
   }
   if(CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_NetworkConf_pcst[network].SizeofController_u8 > 1u){
      if(CanSM_Num_Unsuccessful_ModeReq_au8[network] < CanSM_ModeRepeatReq_Max_u8){
         if(CanSM_BOR_Controller_Stopped_states_en == CANSM_BOR_CONTROLLER_STOPPED_WAIT){
            if(CanSM_Ctrl_ModeInd_ab[network] == TRUE){
               CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
               CanSM_Ctrl_ModeInd_ab[network] = FALSE;
               CanSM_BOR_Controller_Stopped_state_en[network] = CANSM_BOR_CONTROLLER_STOPPED_REQUEST_COMPLETED;
               CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
               CanSM_currBOR_State_en[network] = CANSM_S_RESTART_CC;
               CanSM_CurrBORState_en = CanSM_currBOR_State_en[network];
               CanSM_StartTimer(network);
            }
            else{
               if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                  CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                  CanSM_BOR_Controller_Stopped_state_en[network]=CANSM_BOR_CONTROLLER_STOPPED_REQUEST;
                  CanSM_CurrBORState_en = CanSM_currBOR_State_en[network];
               }
            }
         }
      }
      else{
         CanSM_CurrNw_Mode_en[network] = CANSM_BSM_S_PRE_NOCOM;
         CanSM_ReqComM_Mode_en[network] = COMM_NO_COMMUNICATION;
         CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
         CanSM_BusOff_Indicated_ab[network] = FALSE;
         CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
         CanSM_currBOR_State_en[network] = CANSM_BOR_IDLE;
         CanSM_CurrBORState_en = CanSM_currBOR_State_en[network];
         CanSM_BswM_Mode_en = CANSM_BSWM_NO_COMMUNICATION;
         BswM_CanSM_CurrentState(CanSM_NetworkConf_ps->ComM_channelId_uo,CanSM_BswM_Mode_en);
      }
   }
   if(CanSM_CurrBORState_en == CANSM_S_RESTART_CC){
      CanSM_BOR_CtrlsStart(network);
   }
   else if(CanSM_CurrBORState_en == CANSM_S_RESTART_CC_WAIT){
      if(CanSM_Ctrl_ModeInd_ab[network] == TRUE){
         CanSM_Ctrl_ModeInd_ab[network] = FALSE;
         CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
         if(CanSM_BusOff_Cntr_au8[network] < CanSM_Network_pcst[network].BorCntL1L2_u8){
            CanSM_currBOR_State_en[network] = CANSM_S_BUS_OFF_RECOVERY_L1;
         }
         else{
            CanSM_currBOR_State_en[network] = CANSM_S_BUS_OFF_RECOVERY_L2;
         }
      }
      else{
         if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
            CanSM_currBOR_State_en[network]=CANSM_S_RESTART_CC;
         }
      }
   }
   else if((CanSM_CurrBORState_en == CANSM_S_BUS_OFF_RECOVERY_L1) ||(CanSM_CurrBORState_en == CANSM_S_BUS_OFF_RECOVERY_L2)){
      if(
         (( CanSM_BusOff_Cntr_au8[network] < CanSM_Network_pcst[network].BorCntL1L2_u8)&&(CanSM_TimerConfig_ast[network].cntTick_u16 >=(CanSM_Network_pcst[network].BorTimeL1_u16 + CanSM_GetBusOffDelay_Value_u8[network]) ))||
         ((CanSM_BusOff_Cntr_au8[network] >= CanSM_Network_pcst[network].BorCntL1L2_u8) && (CanSM_TimerConfig_ast[network].cntTick_u16 >= (CanSM_Network_pcst[network].BorTimeL2_u16 + CanSM_GetBusOffDelay_Value_u8[network])))
      ){
         if((CanSM_CurrBORState_en == CANSM_S_BUS_OFF_RECOVERY_L1) &&  (CanSM_BusOff_Cntr_au8[network] < 255u)){
            CanSM_BusOff_Cntr_au8[network]++;
         }
         CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
         for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_Network_pcst[network].SizeofController_u8 ;CanSM_Ctrl_index_u8++){
            CanSM_ControllerId_u8 = CanSM_Network_pcst[network].Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
            (void)(CanIf_SetPduMode(CanSM_ControllerId_u8, CANIF_ONLINE));
         }
         CanSM_BswM_Mode_en = CANSM_BSWM_FULL_COMMUNICATION;
         BswM_CanSM_CurrentState(CanSM_Network_pcst[network].ComM_channelId_uo,CanSM_BswM_Mode_en);
         CanSM_BusSMMode_au8[network] = (ComM_ModeType)CANSM_BSM_S_FULLCOM;
         CanSM_currBOR_State_en[network] = CANSM_S_BUS_OFF_CHECK;
         CanSM_reqComM_Mode_uo = COMM_FULL_COMMUNICATION;
         ComM_BusSM_ModeIndication(CanSM_Network_pcst[network].ComM_channelId_uo,&CanSM_reqComM_Mode_uo);
         CanSM_StartTimer(network);
      }
   }
   else{
      for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
         CanSM_ControllerId_u8 = CanSM_NetworkConf_ps->Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
         if(CanSM_ControllerState_en[CanSM_ControllerId_u8] != CANSM_ControllerState_STARTED){
            (void)CanIf_SetControllerMode(CanSM_ControllerId_u8,CANIF_CS_STARTED);
         }
      }
   }
}

FUNC(void, CANSM_CODE) CanSM_BOR_MultipleCtrlsStop(VAR(NetworkHandleType, AUTOMATIC) network){
   P2CONST(CanSM_NetworkConf_tst, AUTOMATIC, CANSM_CONST) CanSM_NetworkConf_ps;
   VAR(CanSM_BswMCurrentStateType, AUTOMATIC) CanSM_BswM_Mode_en;
   VAR(uint8, AUTOMATIC) CanSM_ControllerId_u8;
   VAR(uint8, AUTOMATIC) CanSM_Ctrl_index_u8;
   VAR(boolean, AUTOMATIC) CanSM_Ctrl_return_val_b[CANSM_NUM_CAN_CONTROLLERS];
   VAR(uint8, AUTOMATIC) CanSM_Controller_Counter_u8 = 0;
   CanSM_NetworkConf_ps = &CanSM_Network_pcst[network];
   for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
      CanSM_ControllerId_u8 = CanSM_NetworkConf_ps->Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
      if(CanSM_ControllerState_en[CanSM_ControllerId_u8] != CANSM_ControllerState_STOPPED){
         if(E_NOT_OK == CanIf_SetControllerMode(CanSM_ControllerId_u8,CANIF_CS_STOPPED)){
            CanSM_Ctrl_return_val_b[CanSM_Ctrl_index_u8] = FALSE;
            CanSM_Num_Unsuccessful_ModeReq_au8[network]++;
            break;
         }
         else{
            CanSM_Ctrl_return_val_b[CanSM_Ctrl_index_u8] = TRUE;
         }
      }
      else{
         CanSM_Ctrl_return_val_b[CanSM_Ctrl_index_u8] = TRUE;
      }
   }
   for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
      if(CanSM_Ctrl_return_val_b[CanSM_Ctrl_index_u8] == TRUE){
         CanSM_Controller_Counter_u8++;
      }
   }
   if(CanSM_Controller_Counter_u8 == CanSM_NetworkConf_ps->SizeofController_u8 ){
      if(CanSM_Ctrl_ModeInd_ab[network] == TRUE){
         CanSM_Ctrl_ModeInd_ab[network] = FALSE;
         CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
         CanSM_BOR_Controller_Stopped_state_en[network] = CANSM_BOR_CONTROLLER_STOPPED_REQUEST_COMPLETED;
      }
      else{
         CanSM_BOR_Controller_Stopped_state_en[network] = CANSM_BOR_CONTROLLER_STOPPED_WAIT;
         CanSM_StartTimer(network);
      }
   }
   else{
      if(CanSM_Num_Unsuccessful_ModeReq_au8[network] >= CanSM_ModeRepeatReq_Max_u8){
         CanSM_CurrNw_Mode_en[network] = CANSM_BSM_S_PRE_NOCOM;
         CanSM_ReqComM_Mode_en[network] = COMM_NO_COMMUNICATION;
         CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
         CanSM_BusOff_Indicated_ab[network] = FALSE;
         CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
         CanSM_currBOR_State_en[network] = CANSM_BOR_IDLE;
         CanSM_BswM_Mode_en = CANSM_BSWM_NO_COMMUNICATION;
         BswM_CanSM_CurrentState(CanSM_NetworkConf_ps->ComM_channelId_uo,CanSM_BswM_Mode_en);
      }
   }
}

FUNC(void, CANSM_CODE) CanSM_BOR_CtrlsStart(VAR(NetworkHandleType, AUTOMATIC) network){
   P2CONST(CanSM_NetworkConf_tst, AUTOMATIC, CANSM_CONST) CanSM_NetworkConf_ps;
   VAR(CanSM_BswMCurrentStateType, AUTOMATIC) CanSM_BswM_Mode_en;
   VAR(uint8, AUTOMATIC) CanSM_ControllerId_u8;
   VAR(uint8, AUTOMATIC) CanSM_Ctrl_index_u8;
   VAR(boolean, AUTOMATIC) CanSM_Ctrl_return_val_b[CANSM_NUM_CAN_CONTROLLERS];
   VAR(uint8, AUTOMATIC) CanSM_Controller_Counter_u8 = 0;
   CanSM_NetworkConf_ps = &CanSM_Network_pcst[network];
   for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
      CanSM_ControllerId_u8 = CanSM_NetworkConf_ps->Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
      if(CanSM_ControllerState_en[CanSM_ControllerId_u8] != CANSM_ControllerState_STARTED){
         if(E_NOT_OK == CanIf_SetControllerMode(CanSM_ControllerId_u8,CANIF_CS_STARTED)){
            CanSM_Ctrl_return_val_b[CanSM_Ctrl_index_u8] = FALSE;
            CanSM_Num_Unsuccessful_ModeReq_au8[network]++;
            break;
         }
         else{
            CanSM_Ctrl_return_val_b[CanSM_Ctrl_index_u8] = TRUE;
         }
      }
      else{
         CanSM_Ctrl_return_val_b[CanSM_Ctrl_index_u8] = TRUE;
      }
   }
   for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
      if(CanSM_Ctrl_return_val_b[CanSM_Ctrl_index_u8] == TRUE){
         CanSM_Controller_Counter_u8++;
      }
   }
   if(CanSM_Controller_Counter_u8 == CanSM_NetworkConf_ps->SizeofController_u8){
      if(CanSM_Ctrl_ModeInd_ab[network] == TRUE){
         CanSM_Ctrl_ModeInd_ab[network] = FALSE;
         CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
         if(CanSM_BusOff_Cntr_au8[network] < CanSM_Network_pcst[network].BorCntL1L2_u8){
            CanSM_currBOR_State_en[network] = CANSM_S_BUS_OFF_RECOVERY_L1;
         }
         else{
            CanSM_currBOR_State_en[network] = CANSM_S_BUS_OFF_RECOVERY_L2;
         }
      }
      else{
         CanSM_currBOR_State_en[network] = CANSM_S_RESTART_CC_WAIT;
      }
   }
   else{
      if(CanSM_Num_Unsuccessful_ModeReq_au8[network] >= CanSM_ModeRepeatReq_Max_u8){
         CanSM_CurrNw_Mode_en[network] = CANSM_BSM_S_PRE_NOCOM;
         CanSM_ReqComM_Mode_en[network] = COMM_NO_COMMUNICATION;
         CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
         CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
         CanSM_currBOR_State_en[network] = CANSM_BOR_IDLE;
         CanSM_BswM_Mode_en = CANSM_BSWM_NO_COMMUNICATION;
         BswM_CanSM_CurrentState(CanSM_NetworkConf_ps->ComM_channelId_uo,CanSM_BswM_Mode_en);
      }
   }
}

FUNC(void, CANSM_CODE) CanSM_Rn_DisableBusOffRecovery(VAR(NetworkHandleType, AUTOMATIC) network){
   network = CanSM_GetHandle(network);
   CanSM_Rn_DisableBusOffRecovery_ab[network] = TRUE;
}

FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetMutex(VAR(NetworkHandleType, AUTOMATIC) network){
   VAR(Std_ReturnType, AUTOMATIC) CanSM_FuncVal_uo;
   CanSM_FuncVal_uo = E_NOT_OK;
   SchM_Enter_CanSM_GetMutexNoNest();
   if(CanSM_MutexMode_au8[network] == CANSM_MUTEX_FREE){
      CanSM_MutexMode_au8[network] = CANSM_MUTEX_BUSY;
      CanSM_FuncVal_uo = E_OK;
   }
   else{
      CanSM_FuncVal_uo = E_NOT_OK;
   }
   SchM_Exit_CanSM_GetMutexNoNest();
   return(CanSM_FuncVal_uo);
}

FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetBusoff_Substate(uint8 ControllerId, CanSM_BusOffRecoveryStateType_ten* BORStatePtr){
   VAR(uint8, AUTOMATIC) network_indx_u8;
   VAR(Std_ReturnType, AUTOMATIC) CanSM_FuncVal_uo;
   CanSM_FuncVal_uo = E_NOT_OK;
   network_indx_u8 = (uint8)CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_NetworktoCtrlConf_pcu8[ControllerId];
   *BORStatePtr = CanSM_currBOR_State_en[network_indx_u8];
   CanSM_FuncVal_uo = E_OK;
   return(CanSM_FuncVal_uo);
}

FUNC(void, CANSM_CODE) CanSM_BOR_CtrlsStart_SilentCom(VAR(NetworkHandleType, AUTOMATIC) network){
   P2CONST(CanSM_NetworkConf_tst, AUTOMATIC, CANSM_CONST) CanSM_NetworkConf_ps;
   VAR(CanSM_BswMCurrentStateType, AUTOMATIC) CanSM_BswM_Mode_en;
   VAR(uint8, AUTOMATIC) CanSM_ControllerId_u8;
   VAR(uint8, AUTOMATIC) CanSM_Ctrl_index_u8;
   VAR(boolean, AUTOMATIC) CanSM_Ctrl_return_val_b[CANSM_NUM_CAN_CONTROLLERS];
   VAR(uint8, AUTOMATIC) CanSM_Controller_Counter_u8 = 0;
   VAR(CanSM_BusOffRecoveryStateType_ten, AUTOMATIC) CanSM_CurrBORState_en;
   CanSM_NetworkConf_ps = &CanSM_Network_pcst[network];
   CanSM_CurrBORState_en = CanSM_currBOR_State_en[network];
   if(CanSM_Num_Unsuccessful_ModeReq_au8[network] < CanSM_ModeRepeatReq_Max_u8){
      switch(CanSM_CurrBORState_en){
         case CANSM_S_RESTART_CC_WAIT:{
            if(CanSM_Ctrl_ModeInd_ab[network] == TRUE){
               CanSM_BOR_SilentCom_Exit(network);
            }
            else{
               if(CanSM_TimerConfig_ast[network].cntTick_u16 >= CanSM_ModeRepeatReq_Time_u16){
                  CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
                  CanSM_currBOR_State_en[network]= CANSM_S_RESTART_CC;
               }
            }
         }
         break;

         case CANSM_S_RESTART_CC:{
            for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
               CanSM_ControllerId_u8 = CanSM_NetworkConf_ps->Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
               if(CanSM_ControllerState_en[CanSM_ControllerId_u8] != CANSM_ControllerState_STARTED){
                  if(E_NOT_OK == CanIf_SetControllerMode(CanSM_ControllerId_u8,CANIF_CS_STARTED)){
                     CanSM_Ctrl_return_val_b[CanSM_Ctrl_index_u8] = FALSE;
                     CanSM_Num_Unsuccessful_ModeReq_au8[network]++;
                     break;
                  }
                  else{
                     CanSM_Ctrl_return_val_b[CanSM_Ctrl_index_u8] = TRUE;
                  }
               }
               else{
                  CanSM_Ctrl_return_val_b[CanSM_Ctrl_index_u8] = TRUE;
               }
            }
            for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
               if(CanSM_Ctrl_return_val_b[CanSM_Ctrl_index_u8] == TRUE){
                  CanSM_Controller_Counter_u8++;
               }
            }
            if(CanSM_Controller_Counter_u8 == CanSM_NetworkConf_ps->SizeofController_u8){
               if(CanSM_Ctrl_ModeInd_ab[network] == TRUE){
                  CanSM_BOR_SilentCom_Exit(network);
               }
               else{
                  CanSM_currBOR_State_en[network] = CANSM_S_RESTART_CC_WAIT;
                  CanSM_StartTimer(network);
               }
            }
         }
         break;

         default:
         break;
      }
   }
   else{
      CanSM_CurrNw_Mode_en[network] = CANSM_BSM_S_PRE_NOCOM;
      CanSM_ReqComM_Mode_en[network] = COMM_NO_COMMUNICATION;
      CanSM_Num_Unsuccessful_ModeReq_au8[network] = CANSM_ZERO;
      CanSM_BOR_SilentCom_ab[network] = FALSE;
      CanSM_TimerConfig_ast[network].stTimer = CANSM_TIMER_ELAPSED;
      CanSM_PreNoCom_Substates_en[network] = CANSM_S_CC_STOPPED;
      CanSM_currBOR_State_en[network] = CANSM_BOR_IDLE;
      CanSM_BswM_Mode_en = CANSM_BSWM_NO_COMMUNICATION;
      BswM_CanSM_CurrentState(CanSM_NetworkConf_ps->ComM_channelId_uo,CanSM_BswM_Mode_en);
   }
}
#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.hpp"
