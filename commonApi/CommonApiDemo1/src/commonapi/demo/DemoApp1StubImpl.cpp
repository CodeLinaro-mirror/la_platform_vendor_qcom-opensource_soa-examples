/*====================================================================

  @file DemoApp1StubImpl.cpp
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

#include "commonapi/demo/DemoApp1StubImpl.hpp"
#include <iostream>
#include <sstream>

namespace commonapi { namespace demo {

   /**
    @brief Default Constructure of DemoApp1StubImpl
    @param None.
    @return None.
   */
   DemoApp1StubImpl::DemoApp1StubImpl():msiCount(0U),
                                        msiCountEv(500U),
                                        mCommonapiV(0, 1)
   {
      mstspCallback = std::make_shared<DemoApp1EventCallbackType>();
      if(nullptr != mstspCallback)
      {
         mstspCallback->uiDemoa1AttrChanged     = std::bind(&DemoApp1StubImpl::DemoApp1StubImpl_SetUiDemoAttr1Attribute,this,std::placeholders::_1);
         mstspCallback->a1StructDemoAttrChanged = std::bind(&DemoApp1StubImpl::DemoApp1StubImpl_Seta1StructDemoAttribute,this,std::placeholders::_1);
      }
      else{/* Nothing To Do */}
   }

   /**
    @brief Default Constructure of DemoApp1StubImpl
    @param None.
    @return None.
   */
   DemoApp1StubImpl::~DemoApp1StubImpl()
   {

   }

   /**
   @brief Default Constructure of DemoApp1StubImpl
   @param None.
   @return None.
   */
   const CommonAPI::Version& DemoApp1StubImpl::getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client)
   {
      //return CommonAPI::Version(0, 1);
      return mCommonapiV;
   }

   /**
   @brief Default Constructure of DemoApp1StubImpl
   @param None.
   @return None.
   */
   const int32_t& DemoApp1StubImpl::getUiDemoAttr1Attribute(const std::shared_ptr<CommonAPI::ClientId> _client)
   {
      return msiCount;
   }

   /**
   @brief Default Constructure of DemoApp1StubImpl
   @param None.
   @return None.
   */
   const DemoApp1StubImpl::StuctA1St& DemoApp1StubImpl::getA1DemoAttribute(const std::shared_ptr<CommonAPI::ClientId> _client)
   {
      return msta1Struct;
   }

   /**
   @brief Default Constructure of DemoApp1StubImpl
   @param None.
   @return None.
   */
   void DemoApp1StubImpl::DemoMethod1(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, DemoMethod1Reply_t _reply)
   {
      std::cerr<<"[DemoApp1][DemoApp1StubImpl][DemoMethod1] Called "<<std::endl;
      std::stringstream replyMsgStream;
      if(false == _name.empty())
      {
          replyMsgStream << "Hello " << _name << "!";
          std::cout << "[DemoApp1][DemoApp1StubImpl][DemoMethod1] " << _name << replyMsgStream.str() << std::endl;
      }
      else
      {
         replyMsgStream << "Invalid Argument !";
      }
      _reply(replyMsgStream.str());
   }

   /**
   @brief Default Constructure of DemoApp1StubImpl
   @param None.
   @return None.
   */
   void DemoApp1StubImpl::DemoMethodErr1(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, DemoMethodErr1Reply_t _reply)
   {
      std::cerr<<"[DemoApp1][DemoApp1StubImpl][DemoMethodErr1] Called "<<std::endl;
      ErrorTypeEt eErrType(ErrorTypeEt::NO_FAULT);
      std::stringstream replyMsgStream;
      if(false == _name.empty())
     {
      replyMsgStream << "Reply DemoMethodErr1 ";
      std::cout << "[DemoApp1][DemoApp1StubImpl][DemoMethodErr1] " << _name << replyMsgStream.str() << std::endl;
     }
     else
     {
        replyMsgStream << "Invalid Argument !";
     }
     _reply(eErrType,replyMsgStream.str());

   }


   /**
   @brief Default Constructure of DemoApp1StubImpl
   @param None.
   @return None.
   */
   void DemoApp1StubImpl::DemoMethodTp1(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, std::vector< int32_t > _data, DemoMethodTp1Reply_t _reply)
   {
      std::cerr<<"[DemoApp1][DemoApp1StubImpl][DemoMethodTp1] Called "<<std::endl;
      ErrorTypeEt eErrType(ErrorTypeEt::NO_FAULT);
      std::stringstream replyMsgStream;
      if(false == _name.empty())
      {
         replyMsgStream << "Reply DemoMethodTp1 ";
         std::cout << "[DemoApp1][DemoApp1StubImpl][DemoMethodTp1] _data[(_data.size() - 1)] = " <<_data[(_data.size() - 1)] << std::endl;
      }
      else
      {
         replyMsgStream << "Invalid Argument !";
      }
      _reply(replyMsgStream.str());
   }

   /**
    @brief Default Constructure of DemoApp1StubImpl
    @param None.
    @return None.
   */
   void DemoApp1StubImpl::DemoApp1StubImpl_TriggerEvent()
   {
      std::cerr<<"[DemoApp1][DemoApp1StubImpl][DemoApp1StubImpl_TriggerEvent] Triggering Events UiDemoAttr1 "<<msiCount<<std::endl;
      fireUiDemoAttr1AttributeChanged(msiCount);
      msiCount++;

      std::cerr<<"[DemoApp1][DemoApp1StubImpl][DemoApp1StubImpl_TriggerEvent] Triggering Events Status1 "<<msiCountEv<<std::endl;
      fireDemoStatus1Event(msiCountEv);
      msiCountEv += 2U;

      std::cerr<<"[DemoApp1][DemoApp1StubImpl][DemoApp1StubImpl_TriggerEvent] Triggering Events Status2 "<<std::endl;
      fireDemoStatus2Event();

      const int32_t siVal(msiCount);
      const bool    bIsEqual(msiCount == msiCountEv);
      const double  dParam((msiCount + msiCountEv) * 1.0);
      msta2Struct.setA(siVal);
      msta2Struct.setB(siVal);
      msta2Struct.setD(siVal);
      std::string strValue(std::string("Struct_String"));

      msta1Struct.setS(strValue);
      msta1Struct.setA2(msta2Struct);
      fireA1DemoAttributeChanged(msta1Struct);

   }

   /**
    @brief Default Constructure of DemoApp1StubImpl
    @param None.
    @return None.
   */
   DemoApp1StubImpl::CallbackStSp DemoApp1StubImpl::DemoApp1StubImpl_GetCallback()
   {
      return mstspCallback;
   }

   /**
    @brief Default Constructure of DemoApp1StubImpl
    @param None.
    @return None.
   */
   void DemoApp1StubImpl::DemoApp1StubImpl_SetUiDemoAttr1Attribute(const int32_t siValue)
   {
      msiCount = siValue;
   }

   /**
    @brief Default Constructure of DemoApp1StubImpl
    @param None.
    @return None.
   */
   void DemoApp1StubImpl::DemoApp1StubImpl_Seta1StructDemoAttribute(const StuctA1St& stValue)
   {

   }

   DemoApp1StubImpl::RemoteEvent* DemoApp1StubImpl::initStubAdapter(const StubAdapterSp &_stubAdapter)
   {
       CommonAPI::Stub<StubAdapter, RemoteEvent>::stubAdapter_ = _stubAdapter;
       return mspDemoApp1StubRemoteEvent.get();
   }

   void DemoApp1StubImpl::setEvent(const RemoteEventSp spEvent)
   {
      mspDemoApp1StubRemoteEvent = spEvent;
   }
}}
