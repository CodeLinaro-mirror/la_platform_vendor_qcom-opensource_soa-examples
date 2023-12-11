/*====================================================================

  @file DemoApp1ServiceImpl.cpp
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

#include <CommonAPI/CommonAPI.hpp>
#include "commonapi/demo/DemoApp1StubImpl.hpp"
#include "commonapi/demo/DemoApp1ServiceEventImpl.hpp"
#include "commonapi/demo/DemoApp1ServiceImpl.hpp"

#include <memory>
#include <iostream>
#include <chrono>
#include <thread>

namespace commonapi { namespace demo {

   class DemoApp1ServiceImpl::CImpl
   {
      using RuntimeSp            = std::shared_ptr < CommonAPI::Runtime >;
      using DemoApp1StubImplSp   = std::shared_ptr<DemoApp1StubImpl>;
      using DemoApp1ServEvImplSp = std::shared_ptr<DemoApp1ServiceEventImpl>;

      public:
         /**
          @brief Default Constructure of CImpl
          @param None.
          @return None.
         */
         explicit CImpl():mstrDomain(std::string("local")),
                          mstrInstance(std::string("commonapi.demo.DemoApp1")),
                          mstrConnection(std::string("DemoApp1Service"))
         {}

         virtual ~CImpl()
         {
            CImpl_Stop();
         }

         /**
          @brief Default Constructure of DemoApp1ServiceImpl
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
               mspDemoApp1StubImpl = std::make_shared<DemoApp1StubImpl>();

               if((nullptr != mspDemoApp1StubImpl) &&
                  (nullptr != mspDemoApp1StubImpl->DemoApp1StubImpl_GetCallback()))
               {
                  mspDemoApp1ServEvImpl = std::make_shared<DemoApp1ServiceEventImpl>(mspDemoApp1StubImpl->DemoApp1StubImpl_GetCallback());
                  if((nullptr != mspDemoApp1ServEvImpl))
                  {
                     mspDemoApp1StubImpl->setEvent(mspDemoApp1ServEvImpl);
                     do
                     {
                        mbIsRegistered = mspRuntime->registerService(mstrDomain, mstrInstance, mspDemoApp1StubImpl, mstrConnection);
                        if(false == mbIsRegistered)
                        {
                           std::cout << "[DemoApp1][DemoApp1Service::CImpl][CImpl_Start] Register Service failed, trying again in 100 milliseconds..." << std::endl;
                           std::this_thread::sleep_for(std::chrono::milliseconds(100));
                        }
                        else{/* Nothing To Do */}
                     }while (false == mbIsRegistered);
                     std::cout << "[DemoApp1][DemoApp1Service::CImpl][CImpl_Start]Successfully Registered Service!" << std::endl;
                  }
                  else{/* Nothing To Do */}
               }
               else{/* Nothing To Do */}
            }
            else{/* Nothing To Do */}
         }

         /**
          @brief Default Constructure of DemoApp1ServiceImpl
          @param None.
          @return None.
         */
         void CImpl_Stop()
         {
            std::cout << "[DemoApp1][DemoApp1Service::CImpl][CImpl_Stop]Called!" << std::endl;
            if(nullptr != mspRuntime)
            {
               mspRuntime->unregisterService(mstrDomain, mstrInstance, mstrConnection);
            }
            else{/* Nothing To Do */}
         }

         /**
          @brief Default Constructure of DemoApp1ServiceImpl
          @param None.
          @return None.
         */
         void CImpl_TriggerEvents()
         {
            if((nullptr != mspDemoApp1StubImpl) &&
               (true    == mbIsRegistered))
            {
               mspDemoApp1StubImpl->DemoApp1StubImpl_TriggerEvent();
            }
            else{/* Nothing To Do */}
         }

      private:
         std::string          mstrDomain;
         std::string          mstrInstance;
         std::string          mstrConnection;
         RuntimeSp            mspRuntime;
         DemoApp1StubImplSp   mspDemoApp1StubImpl;
         DemoApp1ServEvImplSp mspDemoApp1ServEvImpl;
         bool                 mbIsRegistered;
   };

   /**
    @brief Default Constructure of DemoApp1ServiceImpl
    @param None.
    @return None.
   */
   DemoApp1ServiceImpl::DemoApp1ServiceImpl()
   {
      mupCImpl = std::make_unique<CImpl>();
   }

   /**
    @brief Default Constructure of DemoApp1ServiceImpl
    @param None.
    @return None.
   */
   DemoApp1ServiceImpl::~DemoApp1ServiceImpl()
   {
      mupCImpl.reset();
   }

   /**
    @brief Default Constructure of DemoApp1ServiceImpl
    @param None.
    @return None.
   */
   void DemoApp1ServiceImpl::DemoApp1ServiceImpl_Start()
   {
      if(nullptr != mupCImpl)
      {
         mupCImpl->CImpl_Start();
      }
      else{/* Nothing To Do */}
   }

   /**
    @brief Default Constructure of DemoApp1ServiceImpl
    @param None.
    @return None.
   */
   void DemoApp1ServiceImpl::DemoApp1ServiceImpl_Stop()
   {
      if(nullptr != mupCImpl)
      {
         mupCImpl->CImpl_Stop();
      }
      else{/* Nothing To Do */}
   }

   /**
    @brief Default Constructure of DemoApp1ServiceImpl
    @param None.
    @return None.
   */
   void DemoApp1ServiceImpl::DemoApp1ServiceImpl_TriggerEvents()
   {
      if(nullptr != mupCImpl)
      {
         mupCImpl->CImpl_TriggerEvents();
      }
      else{/* Nothing To Do */}
   }
}}

