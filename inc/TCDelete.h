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
//  $Id: TCDelete.h 957 2010-01-28 23:17:00Z the_____tiger $
//*******************************************************************************
#ifndef _TC_DELETE_H_
#define _TC_DELETE_H_

#include "TCTypes.h"

namespace TC
{
   /**
    * @addtogroup TC_BASE
    * @{
    */

   /**
    * @file
    * This header file provides the definition of the classes
    * TC::Delete
    * TC::CheckedDelete
    * TC::ArrayDelete
    * TC::CheckedArrayDelete
    *
    * @author Thomas Goessler
    */

   /**
    * @brief Default delete object
    * The deleted pointer is set to null
    */
   class Delete
   {
   public:
      template <class T>
      void operator()(T* &ptr)
      {
         delete ptr;
         ptr = 0;
      }
   };

   /**
    * @brief Delete object which checks for null pointer
    * The deleted pointer is set to null
    */
   class CheckedDelete
   {
   public:
      template <class T>
      void operator()(T* &ptr)
      {
         if (ptr) delete ptr;
         ptr = 0;
      }
   };

   /**
    * @brief Default array delete object
    * The deleted pointer is set to null
    */
   class ArrayDelete
   {
   public:
      template <class T>
      void operator()(T* &ptr)
      {
         delete[] ptr;
         ptr = 0;
      }
   };

   /**
    * @brief Array delete object which checks for null pointer
    * The deleted pointer is set to null
    */
   class CheckedArrayDelete
   {
   public:
      template <class T>
      void operator()(T* &ptr)
      {
         if (ptr) delete[] ptr;
         ptr = 0;
      }
   };

   /**
    * @brief delete object when ptr should not be deleted
    */
   class NoDelete
   {
   public:
      template <class T>
      void operator()(T* &ptr)
      {
         ptr = 0;
      }
   };

   /**
    * @}
    */

} // namespace TC

#endif // _TC_DELETE_H_

