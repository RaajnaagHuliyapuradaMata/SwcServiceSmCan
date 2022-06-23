/******************************************************************************/
/* File   : CanSm.cpp                                                         */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "CfgCanSm.hpp"
#include "CanSm_core.hpp"
#include "infCanSm_Exp.hpp"
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
class module_CanSm:
      INTERFACES_EXPORTED_CANSM
      public abstract_module
   ,  public class_CanSm_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
            Std_TypeReturn          IsInitDone{E_NOT_OK};
      const CfgModule_TypeAbstract* lptrCfg{(CfgModule_TypeAbstract*)NULL_PTR};
            infPduRClient_Up        infPduRClient_CanSm;

   public:
      module_CanSm(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, CANSM_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, CANSM_CONFIG_DATA, CANSM_APPL_CONST) lptrCfgModule
      );
      FUNC(void, CANSM_CODE) DeInitFunction (void);
      FUNC(void, CANSM_CODE) MainFunction   (void);
      CANSM_CORE_FUNCTIONALITIES
};

extern VAR(module_CanSm, CANSM_VAR) CanSm;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, CANSM_VAR, CANSM_CONST) gptrinfEcuMClient_CanSm = &CanSm;
CONSTP2VAR(infDcmClient,  CANSM_VAR, CANSM_CONST) gptrinfDcmClient_CanSm  = &CanSm;
CONSTP2VAR(infSchMClient, CANSM_VAR, CANSM_CONST) gptrinfSchMClient_CanSm = &CanSm;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_CanSm, CANSM_VAR) CanSm(
   {
         CANSM_AR_RELEASE_VERSION_MAJOR
      ,  CANSM_AR_RELEASE_VERSION_MINOR
      ,  0x00
      ,  0xFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, CANSM_CODE) module_CanSm::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, CANSM_CONFIG_DATA, CANSM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == CanSm_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(NULL_PTR != lptrCfgModule){
         if(STD_HIGH){
            lptrCfg = lptrCfgModule;
         }
         else{
            lptrCfg = &PBcfgCanSm;
         }
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

