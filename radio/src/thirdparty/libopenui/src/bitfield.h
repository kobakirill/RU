/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   libopenui - https://github.com/opentx/libopenui
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include <inttypes.h>

// A set of bitfield handling macros

template <typename T>
inline T bfBit(uint8_t n)
{
  return T(1) << n;
}

#define BFBIT_FLIP(y, mask)       ( y ^=  (mask) )

//! Create a bitmask of length 'len'.
template <typename T>
inline T bfBitmask(uint8_t len)
{
  return bfBit<T>(len) - 1;
}

//! Create a bitfield mask of length 'len' starting at bit 'start'.
template <typename T>
inline T bfMask(uint8_t start, uint8_t len)
{
  return bfBitmask<T>(len) << start;
}

//! Prepare a bitmask for insertion or combining.
template <typename T>
inline T bfPrep(T x, uint8_t start, uint8_t len)
{
  return (x & bfBitmask<T>(len)) << start;
}

//! Extract a bitfield of length 'len' starting at bit 'start' from  'y'.
template <typename T>
inline T bfGet(T y, uint8_t start, uint8_t len)
{
  return ((y)>>(start)) & bfBitmask<T>(len);
}

//! Insert 'len' bits of 'x 'into 'y', starting at bit 'start' from  'y'.
template <class T>
inline T bfSet(T to, T from, uint8_t start, uint8_t len)
{
  return (to & ~bfMask<T>(start, len)) | bfPrep<T>(from, start, len);
}

template <class T>
inline T bfBitGet(T y, T mask)
{
  return (y & mask);
}

template <class T>
inline T bfSingleBitGet(T y, uint8_t i)
{
  return bfBitGet(y, bfBit<T>(i));
}

