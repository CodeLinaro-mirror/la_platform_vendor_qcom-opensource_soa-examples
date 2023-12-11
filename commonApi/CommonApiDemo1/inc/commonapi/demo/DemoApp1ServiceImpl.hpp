/*====================================================================

  @file DemoApp1ServiceImpl.h
  @brief DemoApp1ServiceImpl implements the Service details for CommonApiDemo app

  @details Class DemoApp1ServiceImpl shall be responsible to receive
           event and method callbacks from MW services. Shall implement
           business logics if required and then call listener function.
  @Auther  Gourab Dalal

  @copyright
  Copyright (c) 2023 Qualcomm Innovation Center, Inc. All rights reserved.
  SPDX-License-Identifier: BSD-3-Clause-Clear

=======================================================================*/
/*======================================================================
 EDIT HISTORY
 This section contains comments describing changes made to the module.
 Notice that changes are listed in reverse chronological order.
 ISO format for dates.
 $Header$$DateTime$$Author$
 when            who                      what, where, why
 ----------   ---------   ----------------------------------------------
 2022-12-01     gdalal    File Created.
=======================================================================*/

#ifndef DEMO_APP1_SERVICE_IMPL_HPP_
#define DEMO_APP1_SERVICE_IMPL_HPP_

#include <memory>

namespace commonapi { namespace demo {

   class DemoApp1ServiceImpl
   {
      public:
         /**
          @brief Default Constructure of DemoApp1ServiceImpl
          @param None.
          @return None.
         */
         DemoApp1ServiceImpl();

         /**
          @brief Default Constructure of DemoApp1ServiceImpl
          @param None.
          @return None.
         */
         virtual ~DemoApp1ServiceImpl();

         /**
          @brief Default Constructure of DemoApp1ServiceImpl
          @param None.
          @return None.
         */
         void DemoApp1ServiceImpl_Start();

         /**
          @brief Default Constructure of DemoApp1ServiceImpl
          @param None.
          @return None.
         */
         void DemoApp1ServiceImpl_Stop();

         /**
          @brief Default Constructure of DemoApp1ServiceImpl
          @param None.
          @return None.
         */
         void DemoApp1ServiceImpl_TriggerEvents();

      private:
         class CImpl;
         std::unique_ptr<CImpl> mupCImpl;
   };
}}

#endif // DEMO_APP1_SERVICE_IMPL_HPP_
