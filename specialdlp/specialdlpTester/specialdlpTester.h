// Strict DLP Chinese (SDC) is a strict DLP based on the eMule Xtreme (official) version.
// Copyright (C) 2009-2023  SDC Team
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.


#include <iostream>
#include <string>
#include <atlstr.h>

//Global definition
#define PATH_MAX_SIZE			0xFFFF

//Original functions from eMule Xtreme (official) version.
typedef DWORD(__cdecl * GETDLPVERSION)(void);
typedef LPCWSTR(__cdecl * DLPCHECKMODSTRING_HARD)(LPCWSTR modversion, LPCWSTR clientversion);
typedef LPCWSTR(__cdecl * DLPCHECKMODSTRING_SOFT)(LPCWSTR modversion, LPCWSTR clientversion);
typedef LPCWSTR(__cdecl * DLPCHECKUSERNAME_HARD)(LPCWSTR username);
typedef LPCWSTR(__cdecl * DLPCHECKUSERNAME_SOFT)(LPCWSTR username);
typedef LPCWSTR(__cdecl * DLPCHECKNAMEANDHASHANDMOD)(const CString username, const CString & userhash, const CString & modversion);
typedef LPCWSTR(__cdecl * DLPCHECKMESSAGESPAM)(LPCWSTR messagetext);
typedef LPCWSTR(__cdecl * DLPCHECKUSERHASH)(const PBYTE userhash);
typedef LPCWSTR(__cdecl * DLPCHECKHELLOTAG)(const UINT tagnumber);
typedef LPCWSTR(__cdecl * DLPCHECKINFOTAG)(const UINT tagnumber);
