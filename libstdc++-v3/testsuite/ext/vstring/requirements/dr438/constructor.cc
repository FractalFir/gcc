// 2007-04-27  Paolo Carlini  <pcarlini@suse.de>

// Copyright (C) 2007-2025 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// { dg-do compile }

#include <ext/vstring.h>

void f()
{
  __gnu_cxx::__versa_string<char, std::char_traits<char>,
    std::allocator<char>, __gnu_cxx::__sso_string_base> vs(10, 1);

  __gnu_cxx::__versa_string<char, std::char_traits<char>,
    std::allocator<char>, __gnu_cxx::__rc_string_base> vr(10, 1);  
}
