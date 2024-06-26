/******************************************************************************/
/* File   : ServiceCanSm.cpp                                                  */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "ServiceCanSm.hpp"
#include "infServiceCanSm_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SERVICECANSM_AR_RELEASE_VERSION_MAJOR                                  4
#define SERVICECANSM_AR_RELEASE_VERSION_MINOR                                  3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(SERVICECANSM_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible SERVICECANSM_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(SERVICECANSM_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible SERVICECANSM_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_ServiceCanSm, SERVICECANSM_VAR) ServiceCanSm;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, SERVICECANSM_CODE) module_ServiceCanSm::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, SERVICECANSM_CONST,       SERVICECANSM_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICECANSM_CONFIG_DATA, SERVICECANSM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == ServiceCanSm_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = (const ConstServiceCanSm_Type*)lptrConstModule;
         lptrCfg   = lptrCfgModule;
      }
      else{
#if(STD_ON == ServiceCanSm_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == ServiceCanSm_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == ServiceCanSm_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICECANSM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICECANSM_CODE) module_ServiceCanSm::DeInitFunction(
   void
){
#if(STD_ON == ServiceCanSm_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == ServiceCanSm_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == ServiceCanSm_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICECANSM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICECANSM_CODE) module_ServiceCanSm::MainFunction(
   void
){
#if(STD_ON == ServiceCanSm_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == ServiceCanSm_InitCheck)
   }
   else{
#if(STD_ON == ServiceCanSm_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICECANSM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICECANSM_CODE) module_ServiceCanSm::dummy(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

