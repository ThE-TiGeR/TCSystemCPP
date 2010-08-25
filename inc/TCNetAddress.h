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
// Copyright (C) 2003 - 2010 Thomas Goessler. All Rights Reserved. 
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
//  $Id: TCNetAddress.h 999 2010-07-14 23:04:00Z the_____tiger $
//*******************************************************************************

#ifndef _TCNET_ADRESS_H_
#define _TCNET_ADRESS_H_

#include "TCNetApi.h"
#include "TCNetTypes.h"

#include <string>

namespace TC
{
   namespace Net
   {
      namespace Impl
      {
         class Base;
      }

      /**
      * @addtogroup TC_NET
      * @{
      */

      /**
      * class for getting or setting hostname or address
      */
      class TCNET_API Address
      {
      public:
         /**
         * constructs an net address with internet address none
         * @see TC::Net::Address::initAddress()
         */
         Address();
         /**
         * constructs an net address with hostname
         * @see TC::Net::Address::SetHostName(const std::string &name)
         */
         explicit Address(const std::string &name);
         /**
         * constructs an net address with uint32 ip address (no ipv6)
         * @see TC::Net::Address::SetHostName(uint32 ip_address)
         */
         explicit Address(uint32 ip_address);
         /**
         * copy contructor
         * @see TC::Net::Address::SetAddress(const TC::Net::Address &add)
         */
         Address(const Address&);
         /**
         * constructs an net address with an internataddress
         * @see TC::Net::Address::SetAddress(const TC::Net::InternetAddress &add)
         */
         explicit Address(const InternetAddress &add);
         /**
         * constructs an net address with an internataddress
         * @see TC::Net::Address::SetAddress(const TC::Net::SocketAddress &add)
         */
         explicit Address(const SocketAddress&);

         /**
         * deletes an TC::Net::Address object
         */
         virtual ~Address();

         // cast operators
         operator const InternetAddress&() const { return GetInternetAddress(); }
         operator std::string() const { return GetDotNotation(); }

         // operators for setting the net address
         Address& operator=(uint32);
         Address& operator=(const std::string&);
         Address& operator=(const Address&);
         Address& operator=(const InternetAddress&);
         Address& operator=(const SocketAddress&);

         // operators for comparing the net address
         bool operator==(const Address&) const;
         bool operator!=(const Address&) const;

         /**
         * inits an net address because of the hostname
         * @param name holds string of the hostname
         * @see TC::Net::Address::setupInternetAdress(const std::string &name)
         */
         void SetHostName(const std::string &name);
         /**
         * inits an net address with uint32 ip address (no ipv6)
         * @param add holds the ipv4 internet address
         */
         void SetAddress(uint32 add);
         /**
         * inits an net address with an net address
         * @param add holds the structure of an net address
         */
         void SetAddress(const Address &add);
         /**
         * inits an net address with an internataddress
         * @param add holds the structure of an internet address
         * @see TC::Net::InternetAddress
         */
         void SetAddress(const InternetAddress &add);
         /**
         * inits an net address with an internataddress
         * @param add holds the structure of an socket address
         * @see TC::Net::SocketAddress
         */
         void SetAddress(const SocketAddress &add);

         /**
         * return the dot notation of the net address (e.g. 157.247.1.31)
         */
         std::string GetDotNotation() const;
         /**
         * returns the hostname of the net address
         */
         std::string GetHostName() const;
         /**
         * returns the structure of the internet address
         */
         const InternetAddress& GetInternetAddress() const;

         /**
         * returns the net address of the localhost
         */
         static Address GetLocalAddress();
         static Address GetAnyAddress();
         static Address GetBroadcastAddress();
         static Address GetLoopBackAddress();

      private:
         /**
         * inits an net address because of the hostname
         * @param name holds string of the hostname
         * if the string is empty it uses the local hostname
         */
         void setupInternetAdress(const std::string &name);
         /**
         * initializes the addr with internet address none (INADDR_ANY)
         */
         void initAddress();
      private:
         /** structure of internet address */
         InternetAddress* m_address;
         Impl::Base* m_base;
      };

      /**
      * @}
      */
   } // namespace Net
} // namespace TC

#endif
