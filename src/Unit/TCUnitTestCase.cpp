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


#include <TC/unittest/test_case.h>

#include <TC/unittest/test_result.h>
#include <TC/unittest/failure.h>
#include <TC/unittest/cleanliness.h>

#include <cassert>
#include <cstdio>

namespace {

class FailureException : public std::exception
{
public:
    FailureException(const TC::unittest::Failure& failure) : failure_(failure) {}
    const TC::unittest::Failure& failure() const { return failure_; }
    /** Inherited from std::exception. Overloaded fatally since nobody
        should get a chance to call it. */
    virtual const char* what() { assert(false); return 0;}

private:
    TC::unittest::Failure failure_;
};

static void add_failure_description(std::string& msg, const TC::unittest::Failure& f)
{
    msg += f.failed_condition();
    msg += " (";
    msg += f.filename();
    msg += ':';
    char tmp[16];
    std::sprintf(tmp, "%d", f.line());
    msg += tmp;
    msg += ')';
}

}

namespace TC {
namespace Unit {

void TestCase::run_internal(TestResult* result, const CleanlinessCheck* cleanliness_check)
{
    result_ = result;
    result->enter_test(this);
    
    bool setup_ok = false;
    try {
        this->setup();
        setup_ok = true;
    }
    catch (const FailureException& e) {
        std::string msg("setup: ");
        add_failure_description(msg, e.failure());
        result->add_error(this, msg);
    }
    catch (const std::exception& e) {
        std::string msg("setup: ");
        msg += e.what();
        result->add_error(this, msg);
    }
    catch (...) {
        result->add_error(this, "setup: \"...\" caught");
    }

    // only if setup went ok go on to execute the test code and
    // teardown
    if (setup_ok) {
        try {
            this->run();
            result->add_success(this);
        }
        catch (const FailureException& f) {
            result->add_failure(this, f.failure());
        }
        catch (const std::exception& e) {
            result->add_error(this, e.what());
        }
        catch (...) {
            result->add_error(this, "\"...\" caught");
        }

        try {
            this->teardown();
        }
        catch (const FailureException& e) {
            std::string msg("teardown: ");
            add_failure_description(msg, e.failure());
            result->add_error(this, msg);
        }
        catch (const std::exception& e) {
            std::string msg("teardown: ");
            msg += e.what();
            result->add_error(this, msg);
        }
        catch (...) {
            result->add_error(this, "teardown: \"...\" caught");
        }
    }

    result->leave_test(this);

    if (cleanliness_check && !cleanliness_check->environment_is_clean())
        result->unclean_alarm(this);

    result_ = 0;
}

void TestCase::do_cond_fail(
    bool condition,
    const std::string& condition_str,
    const std::string& filename,
    int line)
{
    if (result_)
        result_->add_assertion(this);

    if (!condition)
        throw FailureException(Failure(condition_str, filename, line));
}

}
}
