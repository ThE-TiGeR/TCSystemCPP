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
// Copyright (C) 2003 - 2014 Thomas Goessler. All Rights Reserved. 
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
//  $Id: TCNetSSLFactory.h,v 19a9fe061077 2014/07/01 18:05:17 thomas $
//*******************************************************************************

#ifndef _TCNET_SSL_FACTORY_H_
#define _TCNET_SSL_FACTORY_H_

#include "TCNetFactory.h"
#include "TCNetAddress.h"
#include "TCNetReadWriteSocket.h"
#include "TCNetSocketServer.h"

/**
* @addtogroup TC_NET
* @{
*/

/**
* @file
* @brief This file provides the definition of tc::net::SSFactory
* @author Thomas Goessler
*/

/**
* @}
*/

namespace tc
{
   namespace net
   {
      /**
      * @brief Factory for creating tc::net SSL objects
      */
      namespace ssl_factory
      {
         /**
         * @addtogroup TC_NET
         * @{
         */

         /**
         * @brief Connects to specified server and returns the socket
         *
         * @param ip_addr Network name or ip address of the server to which to connect
         * @param port   Port on which to connect to the server
         * @param protocol @see Protocol
         */
         TCNET_API ReadWriteSocketPtr Connect(const Address& ip_addr, PortNumber port, Protocol protocol);

         /**
         * @}
         */
      }



   } // namespace net
} // namespace tc


#endif // _TCNET_SSL_FACTORY_H_
