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
//  $Id: TCMemoryMappedFilePosix.h,v 19a9fe061077 2014/07/01 18:05:17 thomas $
//*******************************************************************************
#ifndef _TC_MEMORY_MAPPED_FILE_POSIX_H_
#define _TC_MEMORY_MAPPED_FILE_POSIX_H_

#include "TCMemoryMappedFile.h"

namespace tc
{
   /**
   * @addtogroup TC_BASE_IMP
   * @{
   */

   /**
   * @file
   * This header file provides the definition of the class tc::MemoryMappedFilePosix.
   *
   * @author Thomas Goessler
   */

   /**
   * The class tc::MemoryMappedFilePosix is a simple file opener by mapping the file into the memory.
   *
   * @author Thomas Goessler
   */
   class MemoryMappedFilePosix: public MemoryMappedFile
   {
   public:
      MemoryMappedFilePosix();
      virtual ~MemoryMappedFilePosix();

      virtual uint32_t GetSize() const;
      virtual uint8_t* GetData();
      virtual const uint8_t* GetReadOnlyData() const;

      virtual bool MapToMemory(const std::wstring& fileName,
         bool            readonly,
         uint32_t          size);
      virtual bool MapToMemory(const std::string& fileName,
         bool            readonly,
         uint32_t          size);

   private:
      virtual void UnmapFromMemory();

   private:
      /** Size of the mapped data */
      uint32_t m_size;
      /** Pointer to the mapped data */
      void* m_data;
      /** Handle of the file */
      int m_file;
      /** Handle of the file mapping */
      void* m_file_map;
      /** File is mapped as readonly or as writeable */
      bool m_readonly;
   };

   /**
   *  @}
   */
}

#endif // _TC_MEMORY_MAPPED_FILE_POSIX_H_
