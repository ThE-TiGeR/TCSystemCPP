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
//  $Id: TCFile.h,v 19a9fe061077 2014/07/01 18:05:17 thomas $
//*******************************************************************************

#ifndef _TC_WFILE_H_
#define _TC_WFILE_H_

#include "TCSharedPtr.h"
#include "TCStlTypes.h"

#include <string>
#include <vector>

namespace tc
{
   /**
    * @addtogroup TC_BASE_IO
    * @{
    */

   /**
    * @file
    * @brief This file provides the definition of tc::file
    *
    * @author Thomas Goessler
    */

   /**
    * @brief Provides functions to get/create/set file information
    */
   namespace wfile
   {
      enum FileAttributes: uint32_t
      {
         OWNER_WRITE          = 0x00000001,
         OWNER_READ           = 0x00000002,
         OWNER_EXEC           = 0x00000004,
         GROUP_WRITE          = 0x00000008,
         GROUP_READ           = 0x00000010,
         GROUP_EXEC           = 0x00000020,
         EVERYONE_WRITE       = 0x00000040,
         EVERYONE_READ        = 0x00000080,
         EVERYONE_EXEC        = 0x00000100,

         READONLY             = 0x00000200,
         ARCHIVE              = 0x00000400,
         SYSTEM               = 0x00000800,
         HIDDEN               = 0x00001000,

         WRITE                = 0x00002000,
         EXECUTE              = 0x00004000

      };

      /// @brief  return if file or directory exists
      TCBASE_API bool Exists(const std::wstring &file);
      /// @brief  return if its a file
      TCBASE_API bool IsFile(const std::wstring &file);
      /// @brief  return if file is a directory
      TCBASE_API bool IsDirectory(const std::wstring &file);
      /// @brief  return if the files/directory readable
      TCBASE_API bool IsReadable(const std::wstring &file);
      /// @brief  return if the files/directory writeable
      TCBASE_API bool IsWriteable(const std::wstring &file);
      /// @brief  return if the files/directory executable
      TCBASE_API bool IsExecutable(const std::wstring &file);

      /// @brief  Change the mode flags for this file
      TCBASE_API bool SetFileAttr(const std::wstring &file, uint32_t attr);
      /// @brief  Get file size
      TCBASE_API uint64_t GetFileSize(const std::wstring &file);

      /// @brief  returns time file was last modified   
      TCBASE_API uint64_t GetModificationTime(const std::wstring &file);
      /// @brief  returns time file was last accessed
      TCBASE_API uint64_t GetLastAccessTime(const std::wstring &file);
      /// @brief  returns time when created
      TCBASE_API uint64_t GetCreationTime(const std::wstring &file);
      /// @brief  returns time when touched
      TCBASE_API uint64_t GetTouchedTime(const std::wstring &file);

      /// @brief  get name of file user
      TCBASE_API std::wstring GetFileUser(const std::wstring &file);
      /// @brief  get name of file group
      TCBASE_API std::wstring GetFileGroup(const std::wstring &file);

      /// @brief  change to specified directory
      TCBASE_API bool ChangeDirectory(const std::wstring &directoryIn);
      /// @brief  returns current directory
      TCBASE_API std::wstring GetDirectory();
      /// @brief  returns all files with specified extension
      TCBASE_API std::vector<std::wstring> GetFileListOfDirectory(const std::wstring &search_dir, const std::wstring &search_ext=L"");
      struct FileInfo
      {
         std::wstring name;
         uint64_t last_modified;
         bool is_directory;
         uint64_t file_size;
      };
      typedef std::vector < FileInfo > FileInfos;

      TCBASE_API void GetFileInfosOfDirectory(FileInfos& file_infos,
         const std::wstring& search_dir, 
         const std::wstring& search_ext=L"");
      TCBASE_API FileInfos FindFilesRecursive(const std::wstring& search_dir,
         const std::wstring& search_ext=L"");


      /// @brief  create a empty file
      TCBASE_API bool Create(const std::wstring &file, bool removeOld=true);
      /// @brief  remove specified file
      TCBASE_API bool Remove(const std::wstring &file);

      class Progress
      {
      public:
         virtual void OnCurrentStatus(uint32_t percent_done) = 0;

         virtual ~Progress() {}
      };

      /// @brief  copy source file to destination file
      TCBASE_API bool Copy(const std::wstring& source, const std::wstring& dest,
         SharedPtr<Progress> copy_status=SharedPtr<Progress>());
      /// @brief  move source file to destination file
      TCBASE_API bool Move(const std::wstring& source, const std::wstring& dest);
      /// @brief  create a directory
      TCBASE_API bool CreateDir(const std::wstring &path);
      /// @brief  create a directory also if one of the parent directories does not exist
      TCBASE_API bool CreateDirRecursive(const std::wstring& path);
      /// @brief  remove a directory
      TCBASE_API bool RemoveDir(const std::wstring &path);
      /// @brief  remove a directory also if not empty
      TCBASE_API bool RemoveDirRecursive(const std::wstring &path);

   } // namespace file

   /**
    * @}
    */

} // namespace tc

#endif // _TC_FILE_H_
