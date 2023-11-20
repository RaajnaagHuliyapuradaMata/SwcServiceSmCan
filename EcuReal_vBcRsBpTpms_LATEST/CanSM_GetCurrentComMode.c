#include "Std_Types.hpp"

#include "CanSM_Prv.hpp"

#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.hpp"
FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetCurrentComMode(
        VAR(NetworkHandleType, AUTOMATIC                 ) network
   ,  P2VAR(ComM_ModeType,     AUTOMATIC, CANSM_APPL_DATA) ComM_ModePtr
){
   VAR(Std_ReturnType, AUTOMATIC) stFuncVal = E_NOT_OK;
   VAR(boolean,     AUTOMATIC) CanSM_NwInitStatus_b;
   network = CanSM_GetHandle(network);
   CanSM_NwInitStatus_b =  CanSM_Network_Init_ab[network];
   if(
         (CanSM_Init_ab == (boolean)CANSM_INITED)
      && (CanSM_NwInitStatus_b != FALSE)
   ){
      *ComM_ModePtr = CanSM_BusSMMode_au8[network];
      stFuncVal = E_OK;
   }
   return(stFuncVal);
}

#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.hpp"
