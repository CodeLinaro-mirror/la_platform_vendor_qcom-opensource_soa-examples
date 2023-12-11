/*====================================================================

  @file DemoApp1StubImpl.h
  @brief DemoApp1StubImpl implements the Stub details for CommonApiDemo app

  @details Class DemoApp1StubImpl shall be responsible to receive
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

#ifndef DEMO_APP_STUB_IMPL_HPP_
#define DEMO_APP_STUB_IMPL_HPP_

#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/demo/DemoApp1Stub.hpp>
#include "commonapi/demo/DemoApp1ServiceEventImpl.hpp"

namespace commonapi { namespace demo {

   class DemoApp1StubImpl: public v0::commonapi::demo::DemoApp1Stub
   {
      using StuctA2St     = ::v0::commonapi::demo::CommonTypes::a2Struct;
      using StuctA1St     = ::v0::commonapi::demo::CommonTypes::a1Struct;
      using ErrorTypeEt   = ::v0::commonapi::demo::DemoApp1::stdErrorTypeEnum;
      using RemoteEvent   = v0::commonapi::demo::DemoApp1StubRemoteEvent;
      using StubAdapter   = v0::commonapi::demo::DemoApp1StubAdapter;
      using RemoteEventSp = std::shared_ptr<RemoteEvent>;
      using StubAdapterSp = std::shared_ptr<StubAdapter>;
      using CallbackStSp  = std::shared_ptr<DemoApp1EventCallbackType>;
      using CommonapiV    = CommonAPI::Version;

      public:
         /**
          @brief Default Constructure of DemoApp1StubImpl
          @param None.
          @return None.
         */
         DemoApp1StubImpl();

         /**
          @brief Default Constructure of DemoApp1StubImpl
          @param None.
          @return None.
         */
         virtual ~DemoApp1StubImpl();

         /**
          @brief Default Constructure of DemoApp1StubImpl
          @param None.
          @return None.
         */
         const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) override;

         /**
          @brief Default Constructure of DemoApp1StubImpl
          @param None.
          @return None.
         */
         const int32_t &getUiDemoAttr1Attribute(const std::shared_ptr<CommonAPI::ClientId> _client) override;

         /**
          @brief Default Constructure of DemoApp1StubImpl
          @param None.
          @return None.
         */
         const StuctA1St& getA1DemoAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) override;

         /**
          @brief Default Constructure of DemoApp1StubImpl
          @param None.
          @return None.
         */
         void DemoMethod1(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, DemoMethod1Reply_t _reply)override;

         /**
          @brief Default Constructure of DemoApp1StubImpl
          @param None.
          @return None.
         */
         void DemoMethodErr1(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, DemoMethodErr1Reply_t _reply)override;

         /**
          @brief Default Constructure of DemoApp1StubImpl
          @param None.
          @return None.
         */
         void DemoMethodTp1(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, std::vector< int32_t > _data, DemoMethodTp1Reply_t _reply) override;

         /**
          @brief Default Constructure of DemoApp1StubImpl
          @param None.
          @return None.
         */
         void DemoApp1StubImpl_TriggerEvent();

         /**
          @brief Default Constructure of DemoApp1StubImpl
          @param None.
          @return None.
         */
         CallbackStSp DemoApp1StubImpl_GetCallback();

         /**
          @brief Default Constructure of DemoApp1StubImpl
          @param None.
          @return None.
         */
         RemoteEvent* initStubAdapter(const StubAdapterSp &_stubAdapter)override;

         /**
          @brief Default Constructure of DemoApp1StubImpl
          @param None.
          @return None.
         */
         void setEvent(const RemoteEventSp spEvent);

     private:


      private:
         StuctA2St     msta2Struct;
         StuctA1St     msta1Struct;
         int32_t       msiCount;
         int32_t       msiCountEv;
         CallbackStSp  mstspCallback;
         CommonapiV    mCommonapiV;
         RemoteEventSp mspDemoApp1StubRemoteEvent;
         

         /**
          @brief Default Constructure of DemoApp1StubImpl
          @param None.
          @return None.
         */
         void DemoApp1StubImpl_SetUiDemoAttr1Attribute(const int32_t siValue);

         /**
          @brief Default Constructure of DemoApp1StubImpl
          @param None.
          @return None.
         */
         void DemoApp1StubImpl_Seta1StructDemoAttribute(const StuctA1St& stValue);
   };
}}

#endif // DEMO_APP_STUB_IMPL_HPP_
