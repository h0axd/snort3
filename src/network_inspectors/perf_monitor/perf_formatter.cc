//--------------------------------------------------------------------------
// Copyright (C) 2016-2016 Cisco and/or its affiliates. All rights reserved.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License Version 2 as published
// by the Free Software Foundation.  You may not use, modify or distribute
// this program under any other version of the GNU General Public License.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//--------------------------------------------------------------------------

// perf_formatter.cc author Carter Waxman <cwaxman@cisco.com>

#include "perf_formatter.h"

using namespace std;

void PerfFormatter::register_section(string)
{
    types.push_back(vector<FormatterType>());
    values.push_back(vector<FormatterValue>());
    last_section++;
}

void PerfFormatter::register_field(string name, PegCount* val)
{
    FormatterValue fv;
    fv.pc = val;

    values[last_section].push_back(fv);
    types[last_section].push_back(FT_PEG_COUNT);

    register_field_name(name);
}

void PerfFormatter::register_field(string name, const char* val)
{
    FormatterValue fv;
    fv.s = val;

    values[last_section].push_back(fv);
    types[last_section].push_back(FT_STRING);

    register_field_name(name);
}

void PerfFormatter::register_field(string name, vector<PegCount>* val)
{
    FormatterValue fv;
    fv.ipc = val;

    values[last_section].push_back(fv);
    types[last_section].push_back(FT_IDX_PEG_COUNT);

    register_field_name(name);
}
