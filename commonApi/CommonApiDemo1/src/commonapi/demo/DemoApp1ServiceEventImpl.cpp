/*====================================================================

  @file DemoApp1ServiceEventImpl.cpp
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

#include "commonapi/demo/DemoApp1ServiceEventImpl.hpp"
#include <iostream>
#include <sstream>

namespace commonapi { namespace demo {

   /**
    @brief Default Constructure of DemoApp1ServiceEventImpl
    @param None.
    @return None.
   */
   DemoApp1ServiceEventImpl::DemoApp1ServiceEventImpl(const EventCbStSp stspEventCb):mstspEventCb(stspEventCb)
   {

   }

   /**
   @brief Default Constructure of DemoApp1ServiceEventImpl
   @param None.
   @return None.
   */
   DemoApp1ServiceEventImpl::~DemoApp1ServiceEventImpl()
   {

   }

   /**
   @brief Default Constructure of DemoApp1ServiceEventImpl
   @param None.
   @return None.
   */
   bool DemoApp1ServiceEventImpl::onRemoteSetUiDemoAttr1Attribute(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _value)
   {
      std::cerr<<"[DemoApp1][DemoApp1ServiceEventImpl][onRemoteSetUiDemoAttr1Attribute] Called "<<_value<<std::endl;
      if(nullptr != mstspEventCb)
      {
         mstspEventCb->uiDemoa1AttrChanged(_value);
      }
      else{/* Nothing To Do */}
      return true;
   }

   /**
   @brief Default Constructure of DemoApp1ServiceEventImpl
   @param None.
   @return None.
   */
   void DemoApp1ServiceEventImpl::onRemoteUiDemoAttr1AttributeChanged()
   {

   }

   /**
   @brief Default Constructure of DemoApp1ServiceEventImpl
   @param None.
   @return None.
   */
   bool DemoApp1ServiceEventImpl::onRemoteSetA1DemoAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, ::v0::commonapi::demo::CommonTypes::a1Struct _value)
   {
      std::cerr<<"[DemoApp1][DemoApp1ServiceEventImpl][onRemoteSetA1DemoAttribute] Called "<<std::endl;
      if(nullptr != mstspEventCb)
      {
         mstspEventCb->a1StructDemoAttrChanged(_value);
      }
      else{/* Nothing To Do */}
      return true;
   }

   /**
   @brief Default Constructure of DemoApp1ServiceEventImpl
   @param None.
   @return None.
   */
   void DemoApp1ServiceEventImpl::onRemoteA1DemoAttributeChanged()
   {

   }
}}

