//----------------------------------------------------------------------------
/// \file  config.hpp
//----------------------------------------------------------------------------
/// \brief A class encapsulation static configuration options
//----------------------------------------------------------------------------
// Copyright (c) 2021 Serge Aleynikov <saleyn@gmail.com>
// Created: 2021-08-25
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

#include <eixx/marshal/config.hpp>

namespace eixx {
namespace marshal {

bool config::s_display_creation = true;

}} // eixx::marshal