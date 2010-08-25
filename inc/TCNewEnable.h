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
//  $Id: TCNewEnable.h 957 2010-01-28 23:17:00Z the_____tiger $
//*******************************************************************************

#ifndef _TC_NEW_ENABLE_H_
#define _TC_NEW_ENABLE_H_

/**
 * @addtogroup TC_BASE_DEBUG
 * @{
 */

/**
 * @file
 * Enables the redefinition of the operator new and delete to dedect memory leaks
 *
 * @author Thomas Goessler
 */

// if debug we enable memory checking
#if defined DEBUG || defined _DEBUG

#  ifndef TC_USE_MEM_CHECK
#     define TC_USE_MEM_CHECK 1
#  endif

#else
#  ifdef TC_USE_MEM_CHECK
#     undef TC_USE_MEM_CHECK
#  endif
#  define TC_USE_MEM_CHECK 0

#endif

#if TC_USE_MEM_CHECK

# include <new>

#if TCOS_LINUX || TCOS_AIX || TCOS_SUN || TCOS_CYGWIN
#  define TC_NEW_THROW   throw(std::bad_alloc)
#  define TC_DEL_THROW   throw()
#  define TC_CRT_DECL
#elif TCOS_OSF1
#  define TC_NEW_THROW   _RWSTD_THROW_SPEC((std::bad_alloc))
#  define TC_DEL_THROW   _RWSTD_THROW_SPEC_NULL
#  define TC_CRT_DECL
#elif TCOS_HP
#  define TC_NEW_THROW   __THROWSPEC_X(__bad_alloc)
#  define TC_DEL_THROW   __THROWSPEC_NULL
#  define TC_CRT_DECL
#elif TCOS_WINDOWS
#  if _MSC_VER
#    define TC_NEW_THROW   _THROW1(std::bad_alloc)
#    define TC_DEL_THROW   _THROW0()
#    define TC_CRT_DECL    __cdecl
#  else
#    define TC_NEW_THROW
#    define TC_DEL_THROW
#    define TC_CRT_DECL
#  endif
#else
#  define TC_NEW_THROW
#  define TC_DEL_THROW
#  define TC_CRT_DECL
#endif

// __cdecl
void* TC_CRT_DECL operator new(std::size_t size) TC_NEW_THROW;
void* TC_CRT_DECL operator new[](std::size_t size) TC_NEW_THROW;
void* TC_CRT_DECL operator new(std::size_t size, const char *fileName, int line) TC_NEW_THROW;
void* TC_CRT_DECL operator new[](std::size_t size, const char *fileName, int line) TC_NEW_THROW;

void TC_CRT_DECL operator delete(void *p) TC_DEL_THROW;
void TC_CRT_DECL operator delete[](void *p) TC_DEL_THROW;
void TC_CRT_DECL operator delete(void *p, const char *fileName, int line) TC_DEL_THROW;
void TC_CRT_DECL operator delete[](void *p, const char *fileName, int line) TC_DEL_THROW;

# define TC_NEW new(__FILE__, __LINE__)
# define new     TC_NEW

#endif // _TC_NEW_ENABLE_H_

/**
 *  @}
 */

#endif // DBG_NEW_ENABLE_H
