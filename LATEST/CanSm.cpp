/******************************************************************************/
/* File   : CanSm.cpp                                                         */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "CanSm.hpp"
#include "infCanSm_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CANSM_AR_RELEASE_VERSION_MAJOR                                         4
#define CANSM_AR_RELEASE_VERSION_MINOR                                         3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(CANSM_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible CANSM_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(CANSM_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible CANSM_AR_RELEASE_VERSION_MINOR!"
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
VAR(module_CanSm, CANSM_VAR) CanSm;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, CANSM_CODE) module_CanSm::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, CANSM_CONST,       CANSM_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   CANSM_CONFIG_DATA, CANSM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == CanSm_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = lptrConstModule;
         lptrCfg   = lptrCfgModule;
      }
      else{
#if(STD_ON == CanSm_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == CanSm_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == CanSm_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CANSM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CANSM_CODE) module_CanSm::DeInitFunction(
   void
){
#if(STD_ON == CanSm_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == CanSm_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == CanSm_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CANSM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CANSM_CODE) module_CanSm::MainFunction(
   void
){
#if(STD_ON == CanSm_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == CanSm_InitCheck)
   }
   else{
#if(STD_ON == CanSm_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CANSM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CANSM_CODE) module_CanSm::dummy(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

