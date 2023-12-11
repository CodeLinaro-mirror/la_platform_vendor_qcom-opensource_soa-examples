/*====================================================================

  @file DemoApp1ServiceEventImpl.h
  @brief DemoApp1ServiceEventImpl implements the ServiceEvent for CommonApiDemo app

  @details Class DemoApp1ServiceEventImpl shall be responsible to receive
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

#ifndef DEMO_APP1_SERVICE_EVENT_IMPL_H
#define DEMO_APP1_SERVICE_EVENT_IMPL_H

#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/demo/DemoApp1Stub.hpp>
#include <iostream>
#include <string>
#include <functional>

namespace commonapi { namespace demo {

   struct DemoApp1EventCallbackType
   {
      std::function<void(const int32_t siValue)>                              uiDemoa1AttrChanged;
      std::function<void(const ::v0::commonapi::demo::CommonTypes::a1Struct&)> a1StructDemoAttrChanged;;
   };

   class DemoApp1ServiceEventImpl:public v0::commonapi::demo::DemoApp1StubRemoteEvent
   {
      using EventCbStSp = std::shared_ptr<DemoApp1EventCallbackType>;

      public:
        /**
         @brief Default Constructure of DemoApp1ServiceEventImpl
         @param None.
         @return None.
        */
        DemoApp1ServiceEventImpl(const EventCbStSp stspEventCb);

        /**
        @brief Default Constructure of DemoApp1ServiceEventImpl
        @param None.
        @return None.
        */
        virtual ~DemoApp1ServiceEventImpl();


        /**
        @brief Default Constructure of DemoApp1ServiceEventImpl
        @param None.
        @return None.
        */
        bool onRemoteSetUiDemoAttr1Attribute(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _value) override;


        /**
        @brief Default Constructure of DemoApp1ServiceEventImpl
        @param None.
        @return None.
        */
        void onRemoteUiDemoAttr1AttributeChanged() override;


        /**
        @brief Default Constructure of DemoApp1ServiceEventImpl
        @param None.
        @return None.
        */
        bool onRemoteSetA1DemoAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, ::v0::commonapi::demo::CommonTypes::a1Struct _value) override;


        /**
        @brief Default Constructure of DemoApp1ServiceEventImpl
        @param None.
        @return None.
        */
        void onRemoteA1DemoAttributeChanged() override;

      private:
        EventCbStSp mstspEventCb;
   };
}}
#endif /* DEMO_APP1_SERVICE_EVENT_IMPL_H */
