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
//  $Id: TCMTConditionPthread.h,v 19a9fe061077 2014/07/01 18:05:17 thomas $
//*******************************************************************************

#ifndef _TC_MT_CONDITION_PTHREAD_H_
#define _TC_MT_CONDITION_PTHREAD_H_

#include "TCMTCondition.h"
#include "TCMTMutexPthread.h"

namespace tc
{
namespace multi_threading
{
namespace imp
{
   /**
    * @addtogroup TC_MT_IMP
    * @{
    */

   /**
    * Implementation class of Condition for pthread
    */
  class TC_DLL_LOCAL ConditionPthread: public Condition
   {
   public:
     ConditionPthread();
     ConditionPthread(MutexPtr mutex);
     virtual ~ConditionPthread();
     
     MutexPtr GetMutex();

     bool Wait();
     bool TryWait(const Time& timeout);
     bool Signal();
     bool Broadcast();
     
   private:
     SharedPtr<MutexPthread> m_mutex;
     ::pthread_cond_t m_condition;
   };

   /**
    * @}
    */

} // namespace imp
} // namespace multi_threading
} // namespace tc

#endif // _TC_MT_CONDITION_PTHREAD_H_
