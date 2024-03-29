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
//  $Id: TCCodec.h,v 19a9fe061077 2014/07/01 18:05:17 thomas $
//*******************************************************************************
#ifndef _TCCODEC_H_
#define _TCCODEC_H_

#include "TCSharedPtr.h"

#include <string>

namespace tc
{
    class Stream;

    /**
     * @addtogroup TC_BASE_IO
     * @{
     */

    /**
     * @file
     * @brief This file provides the definition of tc::Codec
     *
     * @author Thomas Goessler
     */

    class Codec;
    /** @brief Shared pointer of an codec object */
    typedef SharedPtr<Codec> CodecPtr;

    /**
     * @brief Base class for all codec
     * method fro encoding and decoding standard types
     * and prepares methods for decoding and encoding
     */
    class Codec
    {
    public:
       /** Clone this codec object */
       virtual CodecPtr Clone() = 0;

       /**
        * Method for reading one signed 8bit integer from the stream
        * @param stream Stream from which to decode the data
        * @param val the short which should store the short
        * @return Number of bytes decoded
        */
       virtual uint64_t Decode(Stream& stream, int8_t &val) = 0;
       /**
        * Method for reading one unsigned 8bit integer from the stream
        * @param stream Stream from which to decode the data
        * @param val the short which should store the short
        * @return Number of bytes decoded
        */
       virtual uint64_t Decode(Stream& stream, uint8_t &val) = 0;
       /**
        * Method for reading one signed 16bit integer from the stream
        * @param stream Stream from which to decode the data
        * @param val the short which should store the short
        * @return Number of bytes decoded
        */
       virtual uint64_t Decode(Stream& stream, int16_t &val) = 0;
       /**
        * Method for reading one unsigned 16bit integer from the stream
        * @param stream Stream from which to decode the data
        * @param val the short which should store the short
        * @return Number of bytes decoded
        */
       virtual uint64_t Decode(Stream& stream, uint16_t &val) = 0;
       /**
        * Method for reading one signed int 32bit integer the stream
        * @param stream Stream from which to decode the data
        * @param val the int which should store the int
        * @return Number of bytes decoded
        */
       virtual uint64_t Decode(Stream& stream, int32_t &val) = 0;
       /**
        * Method for reading one unsigned 32bit integer from the stream
        * @param stream Stream from which to decode the data
        * @param val the int which should store the int
        * @return Number of bytes decoded
        */
       virtual uint64_t Decode(Stream& stream, uint32_t &val) = 0;
       /**
        * Method for reading one signed 64bit integer from the stream
        * @param stream Stream from which to decode the data
        * @param val the long which should store the long
        * @return Number of bytes decoded
        */
       virtual uint64_t Decode(Stream& stream, int64_t &val) = 0;
       /**
        * Method for reading one unsigned 64bit integer from the stream
        * @param stream Stream from which to decode the data
        * @param val the long which should store the long
        * @return Number of bytes decoded
        */
       virtual uint64_t Decode(Stream& stream, uint64_t &val) = 0;
       /**
        * Method for reading one float from the stream
        * @param stream Stream from which to decode the data
        * @param val the float which should store the float
        * @return Number of bytes decoded
        */
       virtual uint64_t Decode(Stream& stream, float &val) = 0;
       /**
        * Method for reading one double from the stream
        * @param stream Stream from which to decode the data
        * @param val the double which should store the double
        * @return Number of bytes decoded
        */
       virtual uint64_t Decode(Stream& stream, double &val) = 0;
       /**
       * Method for reading one string from the stream
       * @param stream Stream from which to decode the data
       * @param val the string which should store the string
       * @return Number of bytes decoded
       */
       virtual uint64_t Decode(Stream& stream, std::string& val) = 0;
       /**
       * Method for reading one wstring from the stream
       * @param stream Stream from which to decode the data
       * @param val the string which should store the string
       * @return Number of bytes decoded
       */
       virtual uint64_t Decode(Stream& stream, std::wstring& val) = 0;
       /**
        * Method for reading one char from the stream
        * @param stream Stream from which to decode the data
        * @param val the char which should store the char
        * @return Number of bytes decoded
        */
       virtual uint64_t Decode(Stream& stream, char &val) = 0;
       /**
        * Method for reading one bool from the stream
        * @param stream Stream from which to decode the data
        * @param val the char which should store the bool
        * @return Number of bytes decoded
        */
       virtual uint64_t Decode(Stream& stream, bool &val)  = 0;


       /**
        * Method for writing one signed 8bit integer to the stream
        * @param stream Stream to which to encode the data
        * @param val the short which to write
        * @return Number of bytes encoded
        */
       virtual uint64_t Encode(int8_t val, Stream& stream) = 0;
       /**
        * Method for writing one unsigned 8bit integer to the stream
        * @param stream Stream to which to encode the data
        * @param val the short which to write
        * @return Number of bytes encoded
        */
       virtual uint64_t Encode(uint8_t val, Stream& stream) = 0;
       /**
        * Method for writing one signed 16bit integer to the stream
        * @param stream Stream to which to encode the data
        * @param val the short which to write
        * @return Number of bytes encoded
        */
       virtual uint64_t Encode(int16_t val, Stream& stream) = 0;
       /**
        * Method for writing one unsigned 16bit integer to the stream
        * @param stream Stream to which to encode the data
        * @param val the short which to write
        * @return Number of bytes encoded
        */
       virtual uint64_t Encode(uint16_t val, Stream& stream) = 0;
       /**
        * Method for writing one signed 32bit integer to the stream
        * @param stream Stream to which to encode the data
        * @param val the int which to write
        * @return Number of bytes encoded
        */
       virtual uint64_t Encode(int32_t val, Stream& stream) = 0;
       /**
        * Method for writing one unsigned 32bit integer to the stream
        * @param stream Stream to which to encode the data
        * @param val the int which to write
        * @return Number of bytes encoded
        */
       virtual uint64_t Encode(uint32_t val, Stream& stream) = 0;
       /**
        * Method for writing one signed 64bit integer to the stream
        * @param stream Stream to which to encode the data
        * @param val the long which to write
        * @return Number of bytes encoded
        */
       virtual uint64_t Encode(int64_t val, Stream& stream) = 0;
       /**
        * Method for writing one unsigned 64bit integer to the stream
        * @param stream Stream to which to encode the data
        * @param val the long which to write
        * @return Number of bytes encoded
        */
       virtual uint64_t Encode(uint64_t val, Stream& stream) = 0;
       /**
        * Method for writing one float to the stream
        * @param stream Stream to which to encode the data
        * @param val the float which to write
        * @return Number of bytes encoded
        */
       virtual uint64_t Encode(float val, Stream& stream) = 0;
       /**
        * Method for writing one double to the stream
        * @param stream Stream to which to encode the data
        * @param val the double which to write
        * @return Number of bytes encoded
        */
       virtual uint64_t Encode(double val, Stream& stream) = 0;
       /**
       * Method for writing one string to the stream
       * @param stream Stream to which to encode the data
       * @param val the string which to write
       * @return Number of bytes encoded
       */
       virtual uint64_t Encode(const char *val, Stream& stream) = 0;
       /**
        * Method for writing one string to the stream
        * @param stream Stream to which to encode the data
        * @param val the string which to write
        * @return Number of bytes encoded
        */
       virtual uint64_t Encode(const std::string& val, Stream& stream) = 0;
       /**
        * Method for writing one wstring to the stream
        * @param stream Stream to which to encode the data
        * @param val the string which to write
        * @return Number of bytes encoded
        */
       virtual uint64_t Encode(const std::wstring& val, Stream& stream) = 0;
       /**
        * Method for writing one signed char to the stream
        * @param stream Stream to which to encode the data
        * @param val the char which to write
        * @return Number of bytes encoded
        */
       virtual uint64_t Encode(char val, Stream& stream) = 0;

       /**
        * Method for writing one bool to the stream
        * @param stream Stream to which to encode the data
        * @param val the bool which to write
        * @return Number of bytes encoded
        */
       virtual uint64_t Encode(bool val, Stream& stream) = 0;

       /**
        * Writes the end of line characters if needed for the stream
        * @param stream Stream to which to encode the end of line
        * @return Number of bytes encoded
        */
       virtual uint64_t EncodeEndOfLine(Stream& stream) = 0;
       /**
        * Writes space to the stream if needed for the stream
        * needed for separating words or numbers
        * @param stream Stream to which to encode the space
        * @return Number of bytes encoded
        */
       virtual uint64_t EncodeSpace(Stream& stream) = 0;

       virtual ~Codec() {}
    };

    /**
     * @}
     */

} // namespace tc

#endif // _TCCODEC_H_
