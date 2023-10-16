#include "Std_Types.hpp"

#include "CanSM_Prv.hpp"

#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.hpp"
FUNC(void, CANSM_CODE) CanSM_ControllerModeIndication(VAR(uint8, AUTOMATIC) ControllerId,VAR(Type_EcuabCanIf_eModeController,AUTOMATIC) ControllerMode){
   VAR(uint8, AUTOMATIC) network_indx_u8;
   VAR(uint8_least, AUTOMATIC) CanSM_ControllerId_u8;
   VAR(uint8_least, AUTOMATIC) CanSM_Ctrl_index_u8;
   VAR(uint8, AUTOMATIC) CanSM_Controller_Counter_u8;
   P2CONST(CanSM_NetworkConf_tst, AUTOMATIC, CANSM_CONST) CanSM_NetworkConf_ps;

#if(CANSM_DEV_ERROR_DETECT != STD_OFF)
   VAR(CanSM_NetworkModeStateType_ten, AUTOMATIC) CurNwMode_Temp_uo;
#endif

   CanSM_Controller_Counter_u8 =  CANSM_ZERO;
   (void)ControllerMode;
   network_indx_u8 = (uint8)CfgSwcServiceCanSM_castConfigSet_pcst->CanSM_NetworktoCtrlConf_pcu8[ControllerId];
   CanSM_NetworkConf_ps = &CanSM_Network_pcst[network_indx_u8];

#if(CANSM_DEV_ERROR_DETECT != STD_OFF)
   CurNwMode_Temp_uo = CanSM_CurrNw_Mode_en[network_indx_u8];
#endif

   CanSM_ControllerIndications_ab[ControllerId] = TRUE;
   if(CanSM_NetworkConf_ps->SizeofController_u8 > 1u){
        for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
            CanSM_ControllerId_u8 = CanSM_NetworkConf_ps->Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
            if(CanSM_ControllerIndications_ab[CanSM_ControllerId_u8] == TRUE){
                CanSM_Controller_Counter_u8++ ;
            }
        }
        if(CanSM_Controller_Counter_u8 == CanSM_NetworkConf_ps->SizeofController_u8 ){
            CanSM_Ctrl_ModeInd_ab[network_indx_u8] = TRUE;
            for(CanSM_Ctrl_index_u8 = 0; CanSM_Ctrl_index_u8 < CanSM_NetworkConf_ps->SizeofController_u8 ;CanSM_Ctrl_index_u8++){
                CanSM_ControllerId_u8 = CanSM_NetworkConf_ps->Cntrl_startidx_pu8[CanSM_Ctrl_index_u8];
                CanSM_ControllerIndications_ab[CanSM_ControllerId_u8] = FALSE;
            }
        }
   }
   else{
        CanSM_Ctrl_ModeInd_ab[network_indx_u8] = TRUE;
        CanSM_ControllerIndications_ab[ControllerId] = FALSE;
   }
}
#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.hpp"
