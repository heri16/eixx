//----------------------------------------------------------------------------
/// \file  endian.hpp
//----------------------------------------------------------------------------
/// \brief A wrapper around boost endian-handling functions.
//----------------------------------------------------------------------------
// Copyright (c) 2010 Serge Aleynikov <saleyn@gmail.com>
// Created: 2010-09-20
//----------------------------------------------------------------------------
/*
***** BEGIN LICENSE BLOCK *****

Copyright 2010 Serge Aleynikov <saleyn at gmail dot com>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

***** END LICENSE BLOCK *****
*/

#ifndef _EIXX_ENDIAN_HPP_
#define _EIXX_ENDIAN_HPP_

#include <cstdint>
#include <boost/version.hpp>
#if BOOST_VERSION >= 107100
#include <boost/endian/conversion.hpp>
#else
#include <boost/spirit/home/support/detail/endian.hpp>
#endif

namespace eixx {

namespace {
#if BOOST_VERSION >= 107100
    namespace bsd = boost::endian;
#elif BOOST_VERSION >= 104800
    namespace bsd = boost::spirit::detail;
#else
    namespace bsd = boost::detail;
#endif
}

template <typename T>
inline void store_be(char* s, T n) {
#if BOOST_VERSION >= 107100
    bsd::endian_store<T, sizeof(T), bsd::order::big>(reinterpret_cast<uint8_t*>(s), n);
#else
    bsd::store_big_endian<T, sizeof(T)>(static_cast<void*>(s), n);
#endif
}

template <typename T>
inline void put_be(char*& s, T n) {
    store_be<T>(s, n);
    s += sizeof(T);
}

template <typename T>
inline T cast_be(const char* s) {
#if BOOST_VERSION >= 107100
    return bsd::endian_load<T, sizeof(T), bsd::order::big>
        (reinterpret_cast<const uint8_t*>(s));
#else
    return bsd::load_big_endian<T, sizeof(T)>((const void*)s);
#endif
}

template <typename T, typename Ch>
inline void get_be(const Ch*& s, T& n) {
    n = cast_be<T>(s);
    s += sizeof(T);
}

inline void put8   (char*& s, uint8_t n ) { put_be(s, n); }
inline void put16be(char*& s, uint16_t n) { put_be(s, n); }
inline void put32be(char*& s, uint32_t n) { put_be(s, n); }
inline void put64be(char*& s, uint64_t n) { put_be(s, n); }

inline uint8_t  get8   (const char*& s) { uint8_t  n; get_be(s, n); return n; }
inline uint16_t get16be(const char*& s) { uint16_t n; get_be(s, n); return n; }
inline uint32_t get32be(const char*& s) { uint32_t n; get_be(s, n); return n; }
inline uint64_t get64be(const char*& s) { uint64_t n; get_be(s, n); return n; }

} // namespace eixx

#endif // _EIXX_ENDIAN_HPP_
