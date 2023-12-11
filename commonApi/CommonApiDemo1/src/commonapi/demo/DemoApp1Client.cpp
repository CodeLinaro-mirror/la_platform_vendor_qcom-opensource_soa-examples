/*====================================================================

  @file DemoApp1Client.cpp
  @brief Implements the  main function for CommonApiDemoClient app

  @details Shall be responsible to receive 
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

#include <commonapi/demo/DemoApp1ProxyImpl.hpp>
//#include <iostream>
#include <thread>
#include <chrono>
#include <memory>

int main()
{
   std::shared_ptr<commonapi::demo::DemoApp1ProxyImpl> spDemoApp1Proxy(std::make_shared<commonapi::demo::DemoApp1ProxyImpl>());
   if(nullptr != spDemoApp1Proxy)
   {
      spDemoApp1Proxy->DemoApp1ProxyImpl_Start();
      while (true)
      {
         std::this_thread::sleep_for(std::chrono::milliseconds(1000));
         spDemoApp1Proxy->DemoApp1ProxyImpl_TriggerMethods();
         //spDemoApp1Proxy->DemoApp1ProxyImpl_GetDemoAttr1ChchedValue();
      }
      spDemoApp1Proxy->DemoApp1ProxyImpl_Stop();  //For Demonstration given as of now
   }
   return 0;
}
