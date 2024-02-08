#ifndef  CANSM_COMM_H
#define CANSM_COMM_H

#include "CanSM_Cfg.hpp"
#include "ComM.hpp"

#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.hpp"

extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_RequestComMode(
      VAR(NetworkHandleType, AUTOMATIC) network
   ,  VAR(ComM_ModeType,     AUTOMATIC) ComM_Mode
);

extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetCurrentComMode(
        VAR(NetworkHandleType, AUTOMATIC                 ) network
   ,  P2VAR(ComM_ModeType,     AUTOMATIC, CANSM_APPL_DATA) ComM_ModePtr
);

#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.hpp"

#endif

