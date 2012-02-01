//************************************************************
//
// *******   ***   ***               *
//    *     *     *                  *
//    *    *      *                *****
//    *    *       ***  *   *   **   *    **    ***
//    *    *          *  * *   *     *   ****  * * *
//    *     *         *   *      *   * * *     * * *
//    *      ***   ***    *     **   **   **   *   *
//                        *
// see http://sourceforge.net/projects/tcsystem/ for details.
// Copyright (C) 2003 - 2007 Thomas Goessler (the____tiger@hotmail.com)
//************************************************************
//
// TCSystem is the legal property of its developers.
// Please refer to the COPYRIGHT file distributed with this source distribution.
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//----------------------------------------------------------------------
//  $Id$
//----------------------------------------------------------------------

#include "TCRng69069.h"

#include "TCNewEnable.h"

namespace tc
{
   namespace imp
   {
      Rng69069::Rng69069(uint32 seed)
         :m_rng(seed)
      {
      }

      uint32 Rng69069::GetRandomNumber()
      {
         return CreateRandomNumber();
      }

      uint32 Rng69069::GetRandomNumber(uint32 lower_limit, uint32 upper_limit)
      {
         uint64 diff = 1 + static_cast<uint64>(upper_limit - lower_limit);
         uint64 aux = diff * CreateRandomNumber();
         aux = aux >> 32;

         return lower_limit + static_cast<uint32>(aux);
      }

      double Rng69069::GetRandomNumberDouble(double lower_limit, double upper_limit)
      {
         double val = static_cast<double>(CreateRandomNumber()) / static_cast<double>(0xffffffff);

         return lower_limit + val * (upper_limit - lower_limit);
      }

      void Rng69069::SetSeed(uint32 seed)
      {
         m_rng = seed;
      }

      uint32 Rng69069::CreateRandomNumber()
      {
         m_rng = (69069 * m_rng) + 1;
         return m_rng;
      }
   }
}