//*******************************************************************************
//
// *******   ***   ***               *
//    *     *     *                  *
//    *    *      *                *****
//    *    *       ***  *   *   **   *    **    ***
//    *    *          *  * *   *     *   ****  * * *
//    *     *         *   *      *   * * *     * * *
//    *      ***   ***    *     **   **   **   *   *
//                        *
//*******************************************************************************
// see https://bitbucket.org/the____tiger/tcsystem for details.
// Copyright (C) 2003 - 2021 Thomas Goessler. All Rights Reserved. 
//*******************************************************************************
//
// TCSystem is the legal property of its developers.
// Please refer to the COPYRIGHT file distributed with this source distribution.
// 
// This library is free software; you can redistribute it and/or             
// modify it under the terms of the GNU Lesser General Public                
// License as published by the Free Software Foundation; either              
// version 2.1 of the License, or (at your option) any later version.        
//                                                                           
// This library is distributed in the hope that it will be useful,           
// but WITHOUT ANY WARRANTY; without even the implied warranty of            
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         
// Lesser General Public License for more details.                           
//                                                                           
// You should have received a copy of the GNU Lesser General Public          
// License along with this library; if not, write to the Free Software       
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
//*******************************************************************************
//  $Id: TCMTMessageQueue.cpp,v 19a9fe061077 2014/07/01 18:05:17 thomas $
//*******************************************************************************

#include "TCMTMessageQueue.h"

#include "TCTime.h"

#include "TCNewEnable.h"

namespace tc
{
   namespace multi_threading
   {
      namespace imp
      {

         MessageQueue::MessageQueue()
         {
            Locker lock(this);

            m_new_message_event = factory::CreateEvent(false, false);
         }

         MessageQueue::~MessageQueue()
         {
            Locker lock(this);

            m_messages.clear();
            m_new_message_event = EventPtr();
         }

         bool MessageQueue::AddMessage(MessagePtr message)
         {
            Locker lock(this);

            m_messages.push_back(message);

            return m_new_message_event->Set();
         }

         Message::ReturnValue MessageQueue::GetMessage(uint32_t msg_id_start, uint32_t msg_id_end, 
            MessagePtr& message)
         {
            do
            {
               Message::ReturnValue ret = GetMessageFromQueue(msg_id_start, msg_id_end,
                  message, true);
               if (ret != Message::ReturnValue::MSG_RECEIVE_FAILED)
               {
                  return ret;
               }
            }while (m_new_message_event->Wait());

            return Message::ReturnValue::MSG_RECEIVE_FAILED;
         }

         Message::ReturnValue MessageQueue::GetMessage(uint32_t msg_id_start, uint32_t msg_id_end,
            MessagePtr& message, const Time& timeout)
         {
            Time start_time = Time::Now();
            Message::ReturnValue ret = Message::ReturnValue::MSG_RECEIVE_FAILED;

            while (ret == Message::ReturnValue::MSG_RECEIVE_FAILED)
            {
               ret = GetMessageFromQueue(msg_id_start, msg_id_end, message, true);
               if (ret == Message::ReturnValue::MSG_RECEIVE_FAILED)
               {
                  Time ellapsed_time = Time::Since(start_time);
                  if (ellapsed_time < timeout)
                  {
                     m_new_message_event->TryWait(timeout - ellapsed_time);
                  }
                  else
                  {
                     ret = Message::ReturnValue::MSG_RECEIVE_TIMEOUT;
                  }
               }
            }

            return ret;
         }

         Message::ReturnValue MessageQueue::TryGetMessage(uint32_t msg_id_start, uint32_t msg_id_end,
            MessagePtr& message, bool remove)
         {
            return GetMessageFromQueue(msg_id_start, msg_id_end, message, remove);
         }

         Message::ReturnValue MessageQueue::GetMessageFromQueue(uint32_t msg_id_start, uint32_t msg_id_end,
            MessagePtr& message, bool remove)
         {
            Message::ReturnValue ret = Message::ReturnValue::MSG_RECEIVE_FAILED;

            Locker lock(this);
            if (m_messages.size() == 0)
            {
               return ret;
            }

            std::vector<MessagePtr>::iterator it_msg;
            for (it_msg =  m_messages.begin(); it_msg != m_messages.end(); it_msg++)
            {
               if ((*it_msg)->GetMessageId() == Message::MSG_ID_QUIT)
               {
                  ret = Message::ReturnValue::MSG_QUIT_RECEIVED;
                  break;
               }
               else if (msg_id_start == Message::MSG_ID_UNKNOWN ||
                  ((*it_msg)->GetMessageId() >= msg_id_start &&
                  (*it_msg)->GetMessageId() <= msg_id_end))
               {
                  ret = Message::ReturnValue::MSG_RECEIVED;
                  break;
               }
            }

            if (ret == Message::ReturnValue::MSG_RECEIVE_FAILED)
            {
               return ret;
            }

            message = *it_msg;

            if (remove)
            {
               m_messages.erase(it_msg);
            }

            return ret;
         }

      } // namespace imp
   } // namespace multi_threading
} // namespace tc

