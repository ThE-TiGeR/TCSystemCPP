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
//  $Id: TCAudioSoundPlayer.h,v a33a555a5a40 2012/02/01 22:48:18 Thomas $
//*******************************************************************************
#ifndef _TC_AUDIO_SOUND_PLAYER_H_
#define _TC_AUDIO_SOUND_PLAYER_H_

#include "TCAudioSoundData.h"

namespace tc
{
   namespace audio
   {
      class TC_DLL_LOCAL SoundPlayer
      {
      public:
         virtual ~SoundPlayer() {}

         virtual bool IsSoundDataPlaying(SoundDataCPtr sound_data) const = 0;
         virtual bool IsSoundDataPaused(SoundDataCPtr sound_data) const = 0;
         virtual bool IsSoundDataStopped(SoundDataCPtr sound_data) const = 0;

         virtual bool PlaySoundData(SoundDataPtr sound_data) = 0;
         virtual bool PauseSoundData(SoundDataPtr sound_data) = 0;
         virtual bool StopSoundData(SoundDataPtr sound_data) = 0;
      };

      typedef SharedPtr<SoundPlayer> SoundPlayerPtr;
   }
}

#endif // _TC_AUDIO_SOUND_PLAYER_H_

