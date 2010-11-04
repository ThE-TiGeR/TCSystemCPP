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
//  $Id: $
//*******************************************************************************


#ifndef _TC_UNIT_TEST_CASE_H
#define _TC_UNIT_TEST_CASE_H

#include "TCUnitTest.h"

namespace TC 
{
   namespace Unit 
   {

      class TCUNIT_API TestCase : public Test
      {
      public:
         TestCase(const std::string& name) : Test(name), result_(0) {}
         virtual ~TestCase() {}

         virtual void setup() {}
         virtual void run() = 0;
         virtual void teardown() {}

      public:
         virtual void run_internal(TestResult*, const CleanlinessCheck*);

#   define TCUNIT_OBJECT_ASSERT(testcase, condition) \
   do { \
   testcase->do_cond_fail((condition), #condition, __FILE__, __LINE__); \
   } while (false)
#   define TCUNIT_OBJECT_FAIL(testcase) TCUNIT_OBJECT_ASSERT(testcase, false)
#   define TCUNIT_ASSERT(condition) TCUNIT_OBJECT_ASSERT(this, condition)
#   define TCUNIT_FAIL() TCUNIT_ASSERT(false)
#   define TCUNIT_ASSERT_THROWS(Exception, expr) \
   do { \
   try { \
   expr; \
   TCUNIT_FAIL(); \
         } \
         catch (const Exception&) {} \
         catch (...) { \
         TCUNIT_FAIL(); \
         } \
   } while (false)
         void do_cond_fail(bool condition,
            const std::string& condition_str,
            const std::string& filename,
            int line);
      private:
         TestResult* result_;
      };

   }
}

#endif