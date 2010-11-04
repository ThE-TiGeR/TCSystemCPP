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


#include <TC/unittest/simple_test_result.h>

#include <TC/unittest/test_case.h>

#include <iostream>

namespace TC {
namespace Unit {

void SimpleTestResult::add_success(const TestCase*)
{
    num_success_++;
}

void SimpleTestResult::add_failure(const TestCase* tc, const Failure& f)
{
    num_failure_++;
    if (ostream_)
        std::cerr << "FAILURE: " << tc->name() << ": " << f.failed_condition()
                  << " (" << f.filename() << ':' << f.line() << ')' << std::endl;
}

void SimpleTestResult::add_error(const TestCase* tc, const std::string& message)
{
    num_error_++;
    if (ostream_)
        std::cerr << "ERROR:   " << tc->name() << ": " << message << std::endl;
}

void SimpleTestResult::add_assertion(const TestCase*)
{
    num_assertion_++;
}

}
}