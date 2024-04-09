#ifndef CANSM_TXTIMEOUTEXCEPTION_H
#define CANSM_TXTIMEOUTEXCEPTION_H

#include "CanSM_Cfg.hpp"
#include "ComM.hpp"

#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.hpp"
extern FUNC(void, CANSM_CODE) CanSM_TxTimeoutException(VAR(NetworkHandleType, AUTOMATIC) Channel);
#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.hpp"

#endif
