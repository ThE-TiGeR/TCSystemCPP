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
//  $Id: TCException.h,v 19a9fe061077 2014/07/01 18:05:17 thomas $
//*******************************************************************************
#ifndef _TC_EXCEPTION_H_
#define _TC_EXCEPTION_H_

#include "TCTypes.h"

#include <exception>
#include <string>

namespace tc
{
   /**
   * @addtogroup TC_BASE
   * @{
   */

   /**
   * @file
   * @brief This file provides the definition of tc::Exception
   *
   * @author Thomas Goessler
   */

   /**
   * @brief Base class for all exceptions
   * wrapping the std::exception because they differ on some compilers :(
   */
   class TCBASE_API Exception: public std::exception
   {
   public:
      Exception();
      Exception(const char* what);
      Exception(const std::string& what);
      ~Exception() throw();

#ifndef TCOS_WINDOWS
      /** @brief Get some information about the exception */
      virtual const char* what() const throw();
   private:
      std::string m_what;
#endif
   };
}

#endif // _TC_EXCEPTION_H_

