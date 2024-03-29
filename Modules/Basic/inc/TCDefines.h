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
//  $Id: TCDefines.h,v 655ae364031f 2014/09/26 18:19:58 thomas $
//*******************************************************************************
#ifndef _TC_DEFINES_H_
#define _TC_DEFINES_H_

#ifdef _DEBUG
#   ifndef DEBUG
#       define DEBUG
#   endif
#endif

/**
 * @addtogroup TC_BASE
 * @{
 */

 /**
  * @file
  * @brief This file provides the definition PLATFORM depending defines
  *
  * @author Thomas Goessler
  */

// define TCOS_WINDOWS if WIN32
#ifdef _WIN32
/** @brief defines that we are compiling for Windows */
#ifndef TCOS_WINDOWS
#  define TCOS_WINDOWS 1
#endif
#define TCOS_32BIT 1
#ifndef NOMINMAX
#  define NOMINMAX 1
#endif
#endif

// define TCOS_WINDOWS if WIN32
#ifdef _WIN64
/** @brief defines that we are compiling for Windows */
#ifndef TCOS_WINDOWS
#  define TCOS_WINDOWS 1
#endif
#define TCOS_64BIT 1
#ifndef NOMINMAX
#  define NOMINMAX 1
#endif
#endif

// We only support windows ce 4.*
// define TCOS_WINCE_40 if _WIN32_WCE
#ifdef _WIN32_WCE
/** @brief defines that we are compiling for Windows CE */
#define TCOS_WINCE_40 1
#define TCOS_WINDOWS 1
#define TCOS_32BIT 1
#endif

// we define TCOS_POSIX
#ifndef TCOS_WINDOWS
/** @brief defines that we are compiling for a posix compatible system */
#  define TCOS_POSIX 1
#  ifdef __x86_64__
#     if __x86_64__
#        define TCOS_64BIT 1
#     else
#        define TCOS_32BIT 1
#     endif
#  else
#     define TCOS_32BIT 1
#  endif
#else
#  ifndef _WIN32_WINNT
#     define _WIN32_WINNT 0x0602
#     define WINVER 0x0602
#  endif
#endif

// ---------------------------------------------------------------
// Version and build numbers
// ---------------------------------------------------------------
/** @brief Version string of TCSystem */
#define TCVERSION_STR   "3.0.0"
/** @brief The TCSystem string */
#define TCPRODUCT_STR   "TCSystem"
/** @brief The Version string + TCSystem string */
#define TCPRODUCT_ID_STR TCPRODUCT_STR "(" TCVERSION_STR ")"
/** @brief The Homepage of TCSystem */
#define TCHOMPAGE       "https://bitbucket.org/the____tiger/tcsystem"
/** @brief The copyright string*/
#define TCCOPYRIGHT     "Copyright (C) 2003 - 2021 Thomas Goessler. All rights reserved"

// ---------------------------------------------------------------
// For DLL�s
// ---------------------------------------------------------------
#ifndef TC_COMPILE_STATIC_LIBS
#  ifdef _MSC_VER
#    define TC_EXPORT_DLL __declspec(dllexport)
#    define TC_IMPORT_DLL __declspec(dllimport)
#    define TC_DLL_LOCAL
#  elif defined __GNUC__
#    if __GNUC__ >= 4
#       define TC_DLL_LOCAL  __attribute__ ((visibility("hidden")))
#       define TC_EXPORT_DLL __attribute__ ((visibility("default")))
#    elif __GNUC__ >= 3
#       define TC_EXPORT_DLL __attribute__ ((visibility("default")))
#    else
#      error unsupported gnu compiler
#    endif
#  else
#    error unsupported compiler
#  endif
#endif

#ifndef TC_DLL_LOCAL
#  define TC_DLL_LOCAL
#endif
#ifndef TC_EXPORT_DLL
#  define TC_EXPORT_DLL
#endif
#ifndef TC_IMPORT_DLL
#  define TC_IMPORT_DLL
#endif

#ifdef TCBASE_EXPORTS
#  define TCBASE_API TC_EXPORT_DLL
#else
#  define TCBASE_API TC_IMPORT_DLL
#endif

/**
 * @def TC_EXPORT_DLL
 * @brief Define for exporting classes functions from a dll
 */
/**
 * @def TC_IMPORT_DLL
 * @brief Define for importing classes functions from a dll
 */
/**
 * @def TC_DLL_LOCAL
 * @brief Define for not exporting a symbol from the dll
 */
/**
 * @def TCBASE_API
 * @brief Define for exporting or importing classes and functions from the TCBasic dll
 */

// ---------------------------------------------------------------
// string formats
// ---------------------------------------------------------------
#ifdef TCOS_WINDOWS
   /** @brief  Defines the format which should be used for sint64 data type */
#  define TC_SINT64_FORMAT   "I64d"
   /** @brief  Defines the wformat which should be used for sint64 data type */
#  define TC_SINT64_WFORMAT L"I64d"
   /** @brief  Defines the format which should be used for uint64_t data type */
#  define TC_UINT64_FORMAT   "I64u"
   /** @brief  Defines the wformat which should be used for uint64_t data type */
#  define TC_UINT64_WFORMAT L"I64u"

   /**
   * @brief Makro for initialising 64 bit values
   *
   * The literal of a 64bit integer is not the same on all compilers
   * e.g. the gcc does not compile if you do not add the integer literal
   *
   * Instead:
   * @code
   * uint64_t val = 0xffffffffffffffff;
   * @endcode
   *
   * Use:
   * @code
   * uint64_t val = UINT64_VAL(0xffffffffffffffff);
   * @endcode
   *
   * This will automatically add the correct integer literal for the 64bit value
   */
#  define TC_UINT64_VAL(val) (val##ui64)
#  define TC_SINT64_VAL(val) (val##i64)

#else
#  ifdef TCOS_64BIT
#    define TC_SINT64_FORMAT   "ld"
#    define TC_SINT64_WFORMAT L"ld"
#    define TC_UINT64_FORMAT   "lu"
#    define TC_UINT64_WFORMAT L"lu"
#  else
#    define TC_SINT64_FORMAT   "lld"
#    define TC_SINT64_WFORMAT L"lld"
#    define TC_UINT64_FORMAT   "llu"
#    define TC_UINT64_WFORMAT L"llu"
#  endif

#  define TC_UINT64_VAL(val) (val##ull)
#  define TC_SINT64_VAL(val) (val##ll)
#endif

#ifdef TCOS_WINDOWS 
#  define _WINSOCKAPI_ // Prevent inclusion of winsock.h in windows.h

#  ifdef _MSC_VER
#     if _MSC_VER < 1300
#        define TC_NO_FRIEND_TEMPLATES
#     endif
      // 'stdext::_Unchecked_uninitialized_move' : decorated name length exceeded, name was truncated
#     pragma warning (disable: 4503)
      // warning C4251: 'AnyClass::m_member' : class 'std::vector<_Ty>' needs to have dll-interface to be used by clients of class 'AnyClass'
#     pragma warning (disable: 4251)
      // warning C4127: conditional expression is constant
#     pragma warning (disable: 4127)
      // warning C4275: non dll-interface class 'AnyClass' used as base for dll-interface class 'AnyClass'
#     pragma warning (disable: 4275)
#   endif

#endif

#ifdef TCOS_WINDOWS 
#  define TC_DISABLE_COMPILER_WARNINGS() __pragma(warning(push, 0)) \
   __pragma(warning(disable: 4308)) \
   __pragma(warning(disable: 4702))

#  define TC_POP_COMPILER_WARNINGS() __pragma(warning(pop))
#else
#  define TC_DISABLE_COMPILER_WARNINGS() _Pragma("GCC diagnostic push") \
   _Pragma("GCC diagnostic ignored \"-Wall\"") \
   _Pragma("GCC diagnostic ignored \"-Wunused-variable\"") \
   _Pragma("GCC diagnostic ignored \"-Wunused-local-typedefs\"")
#  define TC_POP_COMPILER_WARNINGS() _Pragma("GCC diagnostic pop")
#endif

/**
 * @}
 */

#endif // _TC_DEFINES_H_

