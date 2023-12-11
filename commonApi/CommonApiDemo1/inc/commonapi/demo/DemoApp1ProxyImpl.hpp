/*====================================================================

  @file DemoApp1ProxyImpl.h
  @brief DemoApp1ProxyImpl implements the Proxy for CommonApiDemo app

  @details Class DemoApp1ProxyImpl shall be responsible to receive
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

#ifndef DEMO_APP_PROXY_IMPL_HPP_
#define DEMO_APP_PROXY_IMPL_HPP_

#include <memory>

namespace commonapi { namespace demo {

   class DemoApp1ProxyImpl
   {
      public:
         /**
          @brief Default Constructure of DemoApp1ProxyImpl
          @param None.
          @return None.
         */
         explicit DemoApp1ProxyImpl();

         /**
          @brief Default Constructure of DemoApp1ProxyImpl
          @param None.
          @return None.
         */
         virtual ~DemoApp1ProxyImpl();

         /**
          @brief Default Constructure of DemoApp1ProxyImpl
          @param None.
          @return None.
         */
         void DemoApp1ProxyImpl_Start();

         /**
          @brief Default Constructure of DemoApp1ProxyImpl
          @param None.
          @return None.
         */
         void DemoApp1ProxyImpl_Stop();

         /**
          @brief Default Constructure of DemoApp1ProxyImpl
          @param None.
          @return None.
         */
         int32_t DemoApp1ProxyImpl_GetDemoAttr1ChchedValue();

         /**
          @brief Default Constructure of DemoApp1ProxyImpl
          @param None.
          @return None.
         */
         void DemoApp1ProxyImpl_TriggerMethods();
      private:
         class CImpl;
         std::unique_ptr<CImpl> mupCimpl;
   };
}}

#endif // DEMO_APP_PROXY_IMPL_HPP_
