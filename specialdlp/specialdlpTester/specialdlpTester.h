// Strict DLP Chinese (SDC) is a set of strict DLP (Dynamic Leech Protection) DLLs based on the eMule Xtreme Mod's official version.
// Copyright (C) 2009-2024 SDC Team
// 
// This program is free software: you can redistribute it and/or modify 
// it under the terms of the GNU General Public License as published by 
// the Free Software Foundation, either version 3 of the License, or 
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License 
// along with this program. If not, see <https://www.gnu.org/licenses/>.


//External dependency
#include <iostream>
#include <string>
#include <atlstr.h>

//Internal dependency
//No dependency

//Library dependency
//No dependency

//Size and length definition
#define SDC_PATH_MAXSIZE							0xFFFF

//Structure definition
//No definition

//Code definition
#define SDC_LOCALE_SETTING							("en_US.UTF-8")
#if (defined(WIN_X86) && !defined(WIN_X64))
#define SDC_LIBRARY_NAME							("antiLeech.dll")
#elif defined(WIN_X64)
#define SDC_LIBRARY_NAME							("antiLeechx64.dll")
#elif (defined(WIN_ARM32) && !defined(WIN_ARM64))
#define SDC_LIBRARY_NAME							("antiLeecharm.dll")
#elif (defined(WIN_ARM64) && !defined(WIN_ARM64EC))
#define SDC_LIBRARY_NAME							("antiLeecharm64.dll")
#elif defined(WIN_ARM64EC)
#define SDC_LIBRARY_NAME							("antiLeecharm64ec.dll")
#else 
#define SDC_LIBRARY_NAME							("antiLeech.dll")
#endif
typedef DWORD(__cdecl * GETDLPVERSION)(void);
typedef LPCWSTR(__cdecl * DLPCHECKMODSTRING_HARD)(LPCWSTR modversion, LPCWSTR clientversion);
typedef LPCWSTR(__cdecl * DLPCHECKMODSTRING_SOFT)(LPCWSTR modversion, LPCWSTR clientversion);
typedef LPCWSTR(__cdecl * DLPCHECKUSERNAME_HARD)(LPCWSTR username);
typedef LPCWSTR(__cdecl * DLPCHECKUSERNAME_SOFT)(LPCWSTR username);
typedef LPCWSTR(__cdecl * DLPCHECKNAMEANDHASHANDMOD)(const CString username, const CString & userhash, const CString & modversion);
typedef LPCWSTR(__cdecl * DLPCHECKMESSAGESPAM)(LPCWSTR messagetext);
//typedef LPCWSTR(__cdecl * DLPCHECKUSERHASH)(const PBYTE userhash); //No more AJ check.
typedef LPCWSTR(__cdecl * DLPCHECKHELLOTAG)(const UINT tagnumber);
typedef LPCWSTR(__cdecl * DLPCHECKINFOTAG)(const UINT tagnumber);

//Class definition
//No definition

//Function definition
static void PressReturnToEnd(
	void
);
