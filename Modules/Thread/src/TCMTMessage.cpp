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
// see http://sourceforge.net/projects/tcsystem/ for details.
// Copyright (C) 2003 - 2012 Thomas Goessler. All Rights Reserved. 
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
//  $Id$
//*******************************************************************************

#include "TCMTMessage.h"

#include "TCMTFactory.h"

#include "TCNewEnable.h"

namespace tc
{
   namespace multi_threading
   {
      static tc::interlocked::Type s_unique_reply_id(0);
      static uint32 GetReplyIdentifier()
      {
          uint32 reply_id;
          do
          {
             reply_id = static_cast<uint32>(tc::interlocked::Increment(s_unique_reply_id));
          } while (reply_id == 0);
          return reply_id;
      }

      Message::Message( uint32 message_id )
          :m_message_id(message_id)
          ,m_reply_id(GetReplyIdentifier())
          ,m_sender_thread(factory::GetCurrentThread())
      {
      }

      Message::~Message()
      {

      }
   }
}