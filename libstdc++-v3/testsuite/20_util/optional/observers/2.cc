// { dg-do run { target c++17 }  }

// Copyright (C) 2013-2025 Free Software Foundation, Inc.
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

#include <optional>
#include <testsuite_hooks.h>

struct value_type
{
  int i;
};

void* operator&(const value_type&) = delete;

int main()
{
  std::optional<value_type> o { value_type { 51 } };
  VERIFY( o->i == 51 );
  VERIFY( o->i == (*o).i );
  VERIFY( &o->i == &(*o).i );
}
