#ifndef CANSM_CBK_H
#define CANSM_CBK_H

#include "CanSM_Cfg.hpp"
#include "CanIf.hpp"

extern FUNC(void, CANSM_CODE) CanSM_ControllerBusOff(VAR(uint8, AUTOMATIC) ControllerId);
extern FUNC(void, CANSM_CODE) CanSM_ControllerModeIndication(
      VAR(uint8, AUTOMATIC) ControllerId
   ,  VAR(Type_EcuabCanIf_eModeController, AUTOMATIC) ControllerMode
);

#endif

