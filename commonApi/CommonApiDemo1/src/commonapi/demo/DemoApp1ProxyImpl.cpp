/*====================================================================

  @file DemoApp1ProxyImpl.cpp
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

#include <CommonAPI/CommonAPI.hpp>
//#include <CommonAPI/AttributeCacheExtension.hpp>
#include <v0/commonapi/demo/DemoApp1Proxy.hpp>
#include <commonapi/demo/DemoApp1ProxyImpl.hpp>

#include <iostream>
#include <chrono>
#include <thread>

namespace commonapi { namespace demo {

   class DemoApp1ProxyImpl::CImpl
   {
      using RuntimeSp     = std::shared_ptr < CommonAPI::Runtime >;
      using DemoApp1Proxy = std::shared_ptr<v0::commonapi::demo::DemoApp1Proxy<>>;
      using Structa1St    = ::v0::commonapi::demo::CommonTypes::a1Struct;
      using Structa2St    = ::v0::commonapi::demo::CommonTypes::a2Struct;
      using CallStatusEt  = CommonAPI::CallStatus;
      using CalInfoSt     = CommonAPI::CallInfo;
      using Subscription  = uint32_t;

      public:
        /**
         @brief Default Constructure of CImpl
         @param None.
         @return None.
        */
        explicit CImpl():mstrDomain(std::string("local")),
                         mstrInstance(std::string("commonapi.demo.DemoApp1")),
                         mstrConnection(std::string("DemoApp1Client")),
                         muiCount(0U)
        {}

        /**
         @brief Default Constructure of CImpl
         @param None.
         @return None.
        */
        virtual ~CImpl()
        {
           CImpl_Stop();
        }

        /**
         @brief Default Constructure of DemoApp1ProxyImpl
         @param None.
         @return None.
        */
        void CImpl_Start()
        {
           CommonAPI::Runtime::setProperty("LogContext"    , "DAP1");
           CommonAPI::Runtime::setProperty("LogApplication", "DAP1");
           CommonAPI::Runtime::setProperty("LibraryBase"   , "DemoApp1");

           mspRuntime = CommonAPI::Runtime::get();
           if(nullptr != mspRuntime)
           {
              CImpl_CheckServiceAvailability();
          }
          else
          {
             std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl][CImpl_Start] mspRuntime = nullptr" << std::endl;
          }
       }

       /**
        @brief Default Constructure of DemoApp1ProxyImpl
        @param None.
        @return None.
      */
       void CImpl_Stop()
       {
          CImpl_UnSubscribe();
          mspDemoApp1Proxy.reset();
       }

       /**
        @brief Default Constructure of DemoApp1ProxyImpl
        @param None.
        @return None.
       */
       void CImpl_DemoStatus1Notification(const int32_t& siValue)
       {
          std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl][CImpl_DemoStatus1Notification] Received siValue : " <<siValue<< std::endl;
       }

       /**
        @brief Default Constructure of DemoApp1ProxyImpl
        @param None.
        @return None.
       */
       void CImpl_DemoStatus2Notification()
       {
          std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl][CImpl_DemoStatus2Notification] Received "<< std::endl;
       }

      /**
       @brief Default Constructure of DemoApp1ProxyImpl
       @param None.
       @return None.
      */
      void CImpl_DemoAttrNotification(const int32_t& siValue)
      {
         std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl][CImpl_DemoAttrNotification] Received siValue : " <<siValue<< std::endl;
      }

      /**
       @brief Default Constructure of DemoApp1ProxyImpl
       @param None.
       @return None.
      */
      void CImpl_Demoa1Notification(const Structa1St& stStructa1)
      {
         const Structa2St sta2Struct(stStructa1.getA2());
         std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl][CImpl_Demoa1Notification] Received a1.s = " <<stStructa1.getS()
                   <<" a1.a2.a = "<<sta2Struct.getA()
                   <<" a1.a2.b = "<<sta2Struct.getB()
                   <<" a1.a2.d = "<<sta2Struct.getD()<<std::endl;
      }

      /**
       @brief Default Constructure of DemoApp1ProxyImpl
       @param None.
       @return None.
      */
      int32_t CImpl_GetDemoAttr1ChchedValue()
      {
         int32_t siValue(0U);
         if((nullptr != mspDemoApp1Proxy) &&
            (true    == mspDemoApp1Proxy->isAvailable()))
         {
            CallStatusEt eCallStatus(CallStatusEt::SUCCESS);
            mspDemoApp1Proxy->getUiDemoAttr1Attribute().getValue(eCallStatus, siValue, &mstCallInfo);
            if (CallStatusEt::SUCCESS == eCallStatus)
            {
               std::cout << "[DemoApp1][DemoApp1ProxyImpl::CImpl]CImpl_GetDemoAttr1ChchedValue] " << siValue << std::endl;
            }
            else
            {
               std::cout << "[DemoApp1][DemoApp1ProxyImpl::CImpl][CImpl_GetDemoAttr1ChchedValue] error "<< std::endl;
               CImpl_Stop();
               CImpl_CheckServiceAvailability(); 
            }
         }
         else{/* Nothing To Do */}
         return siValue;
      }

      /**
       @brief Default Constructure of DemoApp1ProxyImpl
       @param None.
       @return None.
      */
      void CImpl_TriggerMethods()
      {
         CallStatusEt eCallStatus(CallStatusEt::SUCCESS);
         if((nullptr != mspDemoApp1Proxy))
         {
            if((true    == mspDemoApp1Proxy->isAvailable()))
            {
               if(0U == muiCount%5)
               {
                  std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl]CImpl_TriggerMethods] Calling DemoMethod1"<<std::endl;
                  const std::string strName(std::string("DemoMethod1"));
                  std::string strReturnMessage(std::string(""));
                  mspDemoApp1Proxy->DemoMethod1(strName, eCallStatus, strReturnMessage, &mstCallInfo);
                  if (CallStatusEt::SUCCESS != eCallStatus)
                  {
                     std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl]CImpl_TriggerMethods] DemoMethod1 Remote call failed!"<<std::endl;
                     CImpl_Stop();
                     CImpl_CheckServiceAvailability();
                  }
                  else
                  {
                     std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl]CImpl_TriggerMethods] DemoMethod1 Reply Msg !"<<strReturnMessage<<std::endl;
                  }
               }
               else if(1U == muiCount%5)
               {
                  std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl]CImpl_TriggerMethods] Calling DemoMethodErr1"<<std::endl;
                  const std::string strName(std::string("DemoMethodErr1"));
                  std::string strReturnMessage(std::string(""));
                  v0::commonapi::demo::DemoApp1::stdErrorTypeEnum eErrRet(v0::commonapi::demo::DemoApp1::stdErrorTypeEnum::FAULT_OCCURED);
                  mspDemoApp1Proxy->DemoMethodErr1(strName, eCallStatus, eErrRet,strReturnMessage, &mstCallInfo);
                  if (CallStatusEt::SUCCESS != eCallStatus)
                  {
                     std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl]CImpl_TriggerMethods] DemoMethodErr1 Remote call failed!"<<std::endl;
                     CImpl_Stop();
                     CImpl_CheckServiceAvailability();
                  }
                  else
                  {
                     std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl]CImpl_TriggerMethods] DemoMethodErr1 Reply Msg !"<<strReturnMessage<<std::endl;
                  }
               }
               else if(2U == muiCount%5)
               {
                  std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl]CImpl_TriggerMethods] Calling DemoMethodTp1"<<std::endl;
                  const std::string strName(std::string("DemoMethodTp1"));
                  std::string strReturnMessage(std::string(""));
                  std::vector< int32_t > vData;
                  //vData.reserve(3000U);

                  for(int32_t siLoopCount = 0;  siLoopCount < 3000U; siLoopCount++)
                  {
                     vData.push_back(siLoopCount);
                  }
                  mspDemoApp1Proxy->DemoMethodTp1(strName, vData, eCallStatus,strReturnMessage, &mstCallInfo);
                  if (CallStatusEt::SUCCESS != eCallStatus)
                  {
                     std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl]CImpl_TriggerMethods] DemoMethodTp1 Remote call failed!"<<std::endl;
                     CImpl_Stop();
                     CImpl_CheckServiceAvailability();
                  }
                  else
                  {
                     std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl]CImpl_TriggerMethods] DemoMethodTp1 Reply Msg !"<<strReturnMessage<<std::endl;
                  }
               }
               else if(3U == muiCount%5)
               {
                  int32_t siValue(0);
                  mspDemoApp1Proxy->getUiDemoAttr1Attribute().setValueAsync(siValue,[](const CallStatusEt& eCallStatus, const int32_t& siVal){
                                                                                  std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl]CImpl_TriggerMethods] Set UiDemo Attr1 Callback!"<<std::endl;
                                                                           },&mstCallInfo);
               }
               else if(4U == muiCount%5)
               {
                  CImpl_GetDemoAttr1ChchedValue();
               }
               else{/* Nothing To Do */}
               muiCount++;
            }
            else
            {
               CImpl_Stop();
               CImpl_CheckServiceAvailability();
            }
         }
      }

      private:
         std::string   mstrDomain;
         std::string   mstrInstance;
         std::string   mstrConnection;
         RuntimeSp     mspRuntime;
         DemoApp1Proxy mspDemoApp1Proxy;
         CalInfoSt     mstCallInfo;
         Structa1St    ma1Struct;
         uint32_t      muiCount;
         Subscription  mSubsDemoStatus1;
         Subscription  mSubsDemoStatus2;
         Subscription  mSubsDemoAttr1;
         Subscription  mSubsDemoStructa1;

         /**
          @brief Default Constructure of DemoApp1ProxyImpl
          @param None.
          @return None.
         */
         void CImpl_CheckServiceAvailability()
         {
            if(nullptr != mspRuntime)
            {
               mspDemoApp1Proxy = mspRuntime->buildProxy<v0::commonapi::demo::DemoApp1Proxy>(mstrDomain, mstrInstance, mstrConnection);
               if(nullptr != mspDemoApp1Proxy)
               {
                  std::cerr << "[DemoApp1][DemoApp1Client::CImpl][CImpl_CheckServiceAvailability] Waiting for service to become available." << std::endl;
                  while (!mspDemoApp1Proxy->isAvailable())
                  {
                     std::this_thread::sleep_for(std::chrono::microseconds(100));
                  }
                  std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl][CImpl_CheckServiceAvailability] service available." << std::endl;
                  CImpl_Subscribe();
               }
               else
               {
                  std::cerr << "[DemoApp1][DemoApp1ProxyImpl::CImpl][CImpl_CheckServiceAvailability] mspDemoApp1Proxy = nullptr" << std::endl;
               }
            }
         }

         /**
          @brief Default Constructure of DemoApp1ProxyImpl
          @param None.
          @return None.
         */
         void CImpl_Subscribe()
         {
            if(nullptr != mspDemoApp1Proxy)
            {
               mSubsDemoStatus1  = mspDemoApp1Proxy->getDemoStatus1Event().subscribe(std::bind(&CImpl::CImpl_DemoStatus1Notification,this,std::placeholders::_1));
               mSubsDemoStatus2  = mspDemoApp1Proxy->getDemoStatus2Event().subscribe(std::bind(&CImpl::CImpl_DemoStatus2Notification,this));
               mSubsDemoAttr1    = mspDemoApp1Proxy->getUiDemoAttr1Attribute().getChangedEvent().subscribe(std::bind(&CImpl::CImpl_DemoAttrNotification,this,std::placeholders::_1));
               mSubsDemoStructa1 = mspDemoApp1Proxy->getA1DemoAttribute().getChangedEvent().subscribe(std::bind(&CImpl::CImpl_Demoa1Notification,this,std::placeholders::_1));
            }
            else{/* Nothing To Do */}
         }

         /**
          @brief Default Constructure of DemoApp1ProxyImpl
          @param None.
          @return None.
         */
         void CImpl_UnSubscribe()
         {
            mspDemoApp1Proxy->getDemoStatus1Event().unsubscribe(mSubsDemoStatus1);
            mspDemoApp1Proxy->getDemoStatus2Event().unsubscribe(mSubsDemoStatus1);
            mspDemoApp1Proxy->getUiDemoAttr1Attribute().getChangedEvent().unsubscribe(mSubsDemoStatus1);
            mspDemoApp1Proxy->getA1DemoAttribute().getChangedEvent().unsubscribe(mSubsDemoStatus1);
         }
   };

   /**
   @brief Default Constructure of DemoApp1ProxyImpl
   @param None.
   @return None.
   */
   DemoApp1ProxyImpl::DemoApp1ProxyImpl()
   {
      mupCimpl = std::make_unique<CImpl>();
   }

   /**
   @brief Default Constructure of DemoApp1ProxyImpl
   @param None.
   @return None.
   */
   DemoApp1ProxyImpl::~DemoApp1ProxyImpl()
   {
      mupCimpl.reset();
   }

   /**
    @brief Default Constructure of DemoApp1ProxyImpl
    @param None.
    @return None.
   */
   void DemoApp1ProxyImpl::DemoApp1ProxyImpl_Start()
   {
      if(nullptr != mupCimpl)
      {
         mupCimpl->CImpl_Start();
      }
      else{/* Nothing To Do */}
   }

   /**
    @brief Default Constructure of DemoApp1ProxyImpl
    @param None.
    @return None.
   */
   void DemoApp1ProxyImpl::DemoApp1ProxyImpl_Stop()
   {
      if(nullptr != mupCimpl)
      {
         mupCimpl->CImpl_Stop();
      }
      else{/* Nothing To Do */}
   }

   /**
    @brief Default Constructure of DemoApp1ProxyImpl
    @param None.
    @return None.
   */
   int32_t DemoApp1ProxyImpl::DemoApp1ProxyImpl_GetDemoAttr1ChchedValue()
   {
      int32_t siRetVal(-1);
      if(nullptr != mupCimpl)
      {
         siRetVal = mupCimpl->CImpl_GetDemoAttr1ChchedValue();
      }
      else{/* Nothing To Do */}
      return siRetVal;
   }

   /**
     @brief Default Constructure of DemoApp1ProxyImpl
     @param None.
     @return None.
    */
    void DemoApp1ProxyImpl::DemoApp1ProxyImpl_TriggerMethods()
    {
       mupCimpl->CImpl_TriggerMethods();
    }
}}
