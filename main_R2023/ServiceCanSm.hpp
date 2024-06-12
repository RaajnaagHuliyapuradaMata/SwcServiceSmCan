#pragma once
/******************************************************************************/
/* File   : ServiceCanSm.hpp                                                  */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "infServiceCanSm_ServiceNvM_Types.hpp"
#include "CfgServiceCanSm.hpp"
#include "ServiceCanSm_core.hpp"
#include "infServiceCanSm_Exp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_ServiceCanSm:
      INTERFACES_EXPORTED_SERVICECANSM
      public abstract_module
   ,  public class_ServiceCanSm_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
      const ConstModule_TypeAbstract* lptrNvMBlocksRom = (ConstModule_TypeAbstract*)NULL_PTR;
      infServicePduRClient_Up infServicePduRClient_ServiceCanSm;

   public:
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
      FUNC(void, SERVICECANSM_CODE) InitFunction(
            CONSTP2CONST(ConstModule_TypeAbstract, SERVICECANSM_CONST,       SERVICECANSM_APPL_CONST) lptrNvMBlocksRomModule
         ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICECANSM_CONFIG_DATA, SERVICECANSM_APPL_CONST) lptrCfgModule
      );
      FUNC(void, SERVICECANSM_CODE) DeInitFunction (void);
      FUNC(void, SERVICECANSM_CODE) MainFunction   (void);
      SERVICECANSM_CORE_FUNCTIONALITIES
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
extern VAR(module_ServiceCanSm, SERVICECANSM_VAR) ServiceCanSm;

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

