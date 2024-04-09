#ifndef  CANSM_COMM_H
#define CANSM_COMM_H

#include "CanSM_Cfg.hpp"
#include "ComM.hpp"

extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_RequestComMode(
      VAR(NetworkHandleType, AUTOMATIC) network
   ,  VAR(Type_SwcServiceComM_tMode,     AUTOMATIC) ComM_Mode
);

extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetCurrentComMode(
        VAR(NetworkHandleType, AUTOMATIC                 ) network
   ,  P2VAR(Type_SwcServiceComM_tMode,     AUTOMATIC, CANSM_APPL_DATA) ComM_ModePtr
);

#endif

