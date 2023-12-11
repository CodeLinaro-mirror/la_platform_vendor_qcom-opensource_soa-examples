/*====================================================================

  @file DemoApp1Service.cpp
  @brief Implements the  main function for CommonApiDemoService app

  @details Shall be responsible to send 
           event and method informations from MW services. Shall implement
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

#include "commonapi/demo/DemoApp1ServiceImpl.hpp"
#include <thread>
#include <chrono>
#include <iostream>

int main()
{
   std::shared_ptr<commonapi::demo::DemoApp1ServiceImpl> spDemoApp1ServiceImpl(std::make_shared<commonapi::demo::DemoApp1ServiceImpl>());
   if(nullptr != spDemoApp1ServiceImpl)
   {
      spDemoApp1ServiceImpl->DemoApp1ServiceImpl_Start();

      while (true)
      {
         //std::cout << "[DemoApp1][DemoApp1Service][main] Waiting for calls... (Abort with CTRL+C)" << std::endl;
         std::this_thread::sleep_for(std::chrono::milliseconds(1000));
         spDemoApp1ServiceImpl->DemoApp1ServiceImpl_TriggerEvents();
      }
      spDemoApp1ServiceImpl->DemoApp1ServiceImpl_Stop();
   }
   else{/* Nothing To Do */}
   return 0;
}
