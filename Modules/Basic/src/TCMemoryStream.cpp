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
// Copyright (C) 2003 - 2012 Thomas Goessler. All Rights Reserved. 
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
//  $Id$
//*******************************************************************************
#include "TCMemoryStream.h"

#include "TCUtil.h"

#include <cstring>
#include <limits>

#include "TCNewEnable.h"

namespace tc
{
   namespace imp
   {

      MemoryStream::MemoryStream(CodecPtr codec, ByteVector& memory)
         :StreamBase(codec),
         m_memory(memory),
         m_memory_position(0)
      {
         setStreamDirection(stream_readwrite);
      }

      MemoryStream::~MemoryStream()
      {
      }

      uint64 MemoryStream::ReadBytes(uint64 num_bytes, void* bytes)
      {
         if (num_bytes > std::numeric_limits<ByteVector::size_type>::max())
         {
             return 0;
         }

         if (m_memory_position + num_bytes <= m_memory.size())
         {
            ByteVector::pointer copy_data = static_cast<ByteVector::pointer>(bytes);
            std::copy(m_memory.begin()+m_memory_position, 
                      m_memory.begin()+ByteVector::size_type(m_memory_position+num_bytes), copy_data);
            m_memory_position += ByteVector::size_type(num_bytes);

            return num_bytes;
         }

         return 0;
      }

      uint64 MemoryStream::WriteBytes(uint64 num_bytes, const void* bytes)
      {
         if (num_bytes > std::numeric_limits<ByteVector::size_type>::max())
         {
             return 0;
         }

         ByteVector::const_pointer data_to_write = static_cast<ByteVector::const_pointer>(bytes);
         if (m_memory.size() == m_memory_position)
         {
            m_memory.insert(m_memory.end(), data_to_write, data_to_write + num_bytes);
         }
         else if (m_memory.size() < m_memory_position+num_bytes)
         {
             m_memory.resize(ByteVector::size_type(m_memory_position+num_bytes));
             std::copy(data_to_write, data_to_write+num_bytes, m_memory.begin()+m_memory_position);
         }
         else
         {
             std::copy(data_to_write, data_to_write+num_bytes, m_memory.begin()+m_memory_position);
         }

         m_memory_position += ByteVector::size_type(num_bytes);

         return num_bytes;
      }

      bool MemoryStream::SetPosition(sint64 pos, StreamPosition pos_mode)
      {
         if (uint64(util::Abs(pos)) > std::numeric_limits<ByteVector::size_type>::max())
         {
             return false;
         }

         switch(pos_mode)
         {
         case POSITION_SET:
            m_memory_position = ByteVector::size_type(pos);
            break;

         case POSITION_CURRENT:
            m_memory_position += ssize_type(pos);
            break;

         case POSITION_END:
            m_memory_position = m_memory.size() + ssize_type(pos);
            break;
         }

         // check if vector is big enought
         if (m_memory.size() < m_memory_position)
         {
             m_memory.resize(m_memory_position, 0);
         }

         return true;
      }

      uint64 MemoryStream::GetPosition() const
      {
         return m_memory_position;
      }
   }
}
