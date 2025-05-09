﻿// DLP = Dynamic Leecher Protection
// this code is part of Xtreme-Mod
// author: Xman
// 
// This program is free software; you can redistribute it and/or 
// modify it under the terms of the GNU General Public License 
// as published by the Free Software Foundation; either 
// version 2 of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License 
// along with this program; if not, write to the Free Software 
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.


//SDC team start
#if defined(SPECIAL_DLP_VERSION)
#ifndef SPECIAL_DLP_ADVANCED
#define SPECIAL_DLP_ADVANCED
#endif
#if defined(SPECIAL_DLP_ADVANCED)
#include <regex>
#endif
#endif
//SDC team end
#include <atlstr.h>
#include "antiLeech.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//>>> eWombat [SNAFU_V3]
//SDC team start
#if defined(SPECIAL_DLP_VERSION)
static LPCTSTR apszSnafuTag[]
#else //Official
LPCTSTR apszSnafuTag[] = 
#endif
//SDC team end
{
	_T("[DodgeBoards]"),										//0
	_T("[DodgeBoards & DarkMule eVorteX]"),						//1
	_T("[DarkMule v6 eVorteX]"),								//2
	_T("[eMuleReactor]"),										//3
	_T("[Bionic]"),												//4
	_T("[LSD7c]"),												//5
	_T("[0x8d] unknown Leecher - (client version:60)"),			//6
	_T("[RAMMSTEIN]"),											//7
	_T("[MD5 Community]"),										//8
	_T("[new DarkMule]"),										//9
	_T("[OMEGA v.07 Heiko]"),									//10
	_T("[eMule v0.26 Leecher]"),								//11
	_T("[Hunter]"),												//12
	_T("[Bionic 0.20 Beta]"),									//13
	_T("[Rumata (rus)(Plus v1f)]"),								//14
	_T("[Fusspi]"),												//15
	_T("[donkey2002]"),											//16
	_T("[md4]"),												//17
	_T("[SpeedMule]"),											//18 Xman
	_T("[pimp]"),												//19 Xman
	_T("[Chinese Leecher]"),									//20 SquallATF
//	_T("[eChanblardNext]"),										//21 zz_fly
};

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
//SDC team start
#if defined(SPECIAL_DLP_VERSION)
	//Do nothing.
#else //Official
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
		break;
	}
#endif
//SDC team end

	return TRUE;
}

//SDC team start
#if defined(SPECIAL_DLP_VERSION)
const DWORD __declspec(dllexport) GetDLPVersion(void)
{
	return DLPVERSION;
}
#else //Official
void __declspec(dllexport) TestFunc(void)
{
	::MessageBox(NULL, _T("Inside the DLL!"), _T("Nix"), 0);
}
#endif
//SDC team end

//drop old version support
/*
LPCTSTR __declspec(dllexport) DLPCheckModstring(LPCTSTR modversion, LPCTSTR clientversion)
{
	if (modversion == NULL || clientversion == NULL)
		return NULL;

	if (StrStrI(modversion, _T("Freeza")) || 
		StrStrI(modversion, _T("d-unit")) || 
//		StrStrI(modversion, _T("NOS")) || //removed for the moment
		StrStrI(modversion, _T("imperator")) || 
		StrStrI(modversion, _T("SpeedLoad")) || 
		StrStrI(modversion, _T("gt mod")) || 
		StrStrI(modversion, _T("egomule")) || 
		StrStrI(modversion, _T("aldo")) || 
		StrStrI(modversion, _T("darkmule")) || 
		StrStrI(modversion, _T("LegoLas")) || 
		StrStrI(modversion, _T("dodgethis")) || //Updated
		StrStrI(modversion, _T("DM-")) || 
		StrStrI(modversion, _T("|X|")) || 
		StrStrI(modversion, _T("eVorte")) || 
		StrStrI(modversion, _T("Mison")) || 
		StrStrI(modversion, _T("father")) || 
		StrStrI(modversion, _T("Dragon")) || 
		StrStrI(modversion, _T("booster")) || //Temporaly added, must check the tag
		StrStrI(modversion, _T("$motty")) || 
		StrStrI(modversion, _T("Thunder")) || 
		StrStrI(modversion, _T("BuzzFuzz")) || 
		StrStrI(modversion, _T("Speed-Unit")) || 
		StrStrI(modversion, _T("Killians")) || 
		StrStrI(modversion, _T("Element")) || 
		StrStrI(modversion, _T("§¯Å]")) || 
		StrStrI(modversion, _T("Rappi")) || 
		StrStrI(modversion, _T("EastShare")) && StrStrI(clientversion, _T("0.29")) || 
		StrStrI(modversion, _T("eChanblard v7.0")) || 
//		StrStrI(modversion, _T("ACAT")) || 
		StrStrI(modversion, _T("!FREEANGEL!")) || 
		StrStrI(modversion, _T("          ")) || 
		StrStrI(modversion, _T("Stonehenge")) || 
		StrStrI(modversion, _T("@RAPTOR")) || 
		StrStrI(modversion, _T("pwNd muLe")) || 
		StrStrI(modversion, _T("HARDPAW")) || 
		StrStrI(modversion, _T("XXL")) || 
		StrStrI(modversion, _T("LSD")) || 
		StrStrI(modversion, _T("Rockesel")) || //WiZaRd
		StrStrI(modversion, _T("Bad Donkey")) || //WiZaRd
		StrStrI(modversion, _T("DSL-Light-Client")) || //WiZaRd
		StrStrI(modversion, _T("Elben")) || //WiZaRd
		StrStrI(modversion, _T("PROeMule")) || //WiZaRd
		StrStrI(modversion, _T("OO.de")) || //WiZaRd
		StrStrI(modversion, _T("00.de")) || //WiZaRd
		StrStrI(modversion, _T("OOde")) || //WiZaRd
		StrStrI(modversion, _T("00de")) || 
		StrStrI(modversion, _T("Devil")) || 
		StrStrI(modversion, _T("Elfen")) || 
		StrStrI(modversion, _T("Ef-mod ")) || //Xman this mod can be abused as a full leecher
		StrStrI(modversion, _T("HARDMULE")) || 
		StrStrI(modversion, _T("Xtreme Xtended")) || //Xman 15.08.05
		StrStrI(modversion, _T("MirageMod")) || //"
		StrStrI(modversion, _T("SpeedX")) || 
		StrStrI(modversion, _T("AIDEADSL")) || 
		StrStrI(modversion, _T("Hypnotix")) || 
		StrStrI(modversion, _T("blackviper")) || 
		StrStrI(modversion, _T("BlackAngel")) || 
		StrStrI(modversion, _T("Community")) || 
		StrStrI(modversion, _T("rabbit")) || 
		StrStrI(modversion, _T("rabb_it")) || 
		StrStrI(modversion, _T("Speedmule")) || 
		StrStrI(modversion, _T("Raptor")) || 
		StrStrI(modversion, _T("Hawkstar")) || 
		StrStrI(modversion, _T("ServerClient")) || 
		StrStrI(modversion, _T("Love-Angel")) || 
		StrStrI(modversion, _T("SuperKiller")) || 
		StrStrI(modversion, _T("Ultimativ")) || 
		StrStrI(modversion, _T("uptempo")) || 
		StrStrI(modversion, _T("ZamBoR")) || 
		StrStrI(modversion, _T("Arabella")) || 
		StrStrI(modversion, _T("Morph")) && (StrStrI(modversion, _T("Max")) || StrStrI(modversion, _T("+")) || StrStrI(modversion, _T("×"))) || 
		StrStrI(modversion, _T("Morph XT")) || //very bad mod (MPAA ?)
		StrStrI(modversion, _T("BlueHex")) || 
		StrStrI(modversion, _T("FlowerPower")) || 
		StrStrI(modversion, _T("Fincan")) || 
		StrStrI(modversion, _T("Heartbreaker")) || 
		StrStrI(modversion, _T("Administrator")) || 
		StrStrI(modversion, _T("B@d-D3vi7")) || 
		StrStrI(modversion, _T("CryptedSpeed")) || 
		StrStrI(modversion, _T("DarkDragon")) || 
		StrStrI(modversion, _T("OS_")) || //Xman most are found via other checks, but not all
		_tcslen(modversion) > 0 && (StrStrI(clientversion, _T("edonkey")) || modversion[0] == _T('[')) || //1. donkey user with modstring, 2. modstring begins with [ this is a known leecher
		(StrStrI(modversion, _T("Xtreme")) && StrStrI(modversion, _T("]"))) //bad Xtreme mod
	)
		return _T("Bad MODSTRING");

	return NULL;
}

LPCTSTR __declspec(dllexport) DLPCheckUsername(LPCTSTR username)
{
	if (username == NULL)
		return NULL;

	if (StrStrI(username, _T("$GAM3R$")) || 
		StrStrI(username, _T("G@m3r")) || 
		StrStrI(username, _T("$WAREZ$")) || 
//		StrStrI(username, _T("RAMMSTEIN")) || //Xman 21.06.05 SNAFU should filter the right ones out
//		StrStr(username, _T("toXic")) || //Xman 19.10.05 too old
		StrStrI(username, _T("Leecha")) || 
		StrStr(username, _T("eDevil")) || 
		StrStrI(username, _T("darkmule")) || 
//		StrStrI(username, _T("phArAo")) || //Xman 19.10.05 too old
//		StrStrI(username, _T("dodgethis")) || //Xman 21.06.05 not seen for a long time
		StrStrI(username, _T("Reverse")) || 
//		StrStrI(username, _T("eVortex")) || //Xman didn't see it for a long time
//		StrStrI(username, _T("|eVorte|X|")) || //"
//		StrStrI(username, _T("Chief")) || //Xman 17.5.08 old and no more needed
		StrStrI(username, _T("$motty")) || 
		StrStrI(username, _T("emule-speed")) || 
		StrStrI(username, _T("celinesexy")) || 
		StrStrI(username, _T("Gate-eMule")) || 
		StrStrI(username, _T("energyfaker")) || 
		StrStrI(username, _T("BuzzFuzz")) || 
		StrStrI(username, _T("Speed-Unit")) || 
		StrStrI(username, _T("Killians")) || 
		StrStrI(username, _T("pubsman")) || 
		StrStrI(username, _T("emule-element")) || 
		StrStrI(username, _T("00de.de")) || 
		StrStrI(username, _T("00de")) || 
		StrStrI(username, _T("OO.de")) || 
		StrStrI(username, _T("OOde")) || 
		StrStrI(username, _T("emule")) && StrStrI(username, _T("booster")) || 
		StrStrI(username, _T("Rappi")) || 
		StrStrI(username, _T("Ketamine")) || 
		StrStrI(username, _T("HARDMULE")) || 
		StrStrI(username, _T("emuleech")) || 
	//Xman 15.08.05
		StrStrI(username, _T("SchlumpMule")) || //"
		StrStrI(username, _T("Safty´s")) || 
		StrStrI(username, _T("UnKnOwN pOiSoN")) || 
		StrStrI(username, _T("ElfenPower")) || 
		StrStrI(username, _T("eMule Cow")) || 
		StrStrI(username, _T("Freezamule")) || 
		StrStr(username, _T("EGOmule")) || 
		StrStrI(username, _T("-=EGOist=-")) || 
		StrStrI(username, _T("FreezaVamp")) || 
		StrStrI(username, _T("Muli_Checka")) || 
		StrStr(username, _T("PrOjEcT-SaNdStOrM")) || 
		StrStr(username, _T("NotHer eDitiOn")) || 
		StrStrI(username, _T("eSl@d3vil")) || 
		StrStrI(username, _T(" AgentSmith")) || 
		StrStrI(username, _T("rabb_it")) || 
		StrStrI(username, _T("ServerClient")) || 
		StrStrI(username, _T(">>Power-Mod")) || 
		StrStr(username, _T("DM_X")) || //darkmule
		StrCmpI(username, _T("Muse")) == 0 || //ketamine mod
		StrStr(username, _T("ZamBoR")) || 
		StrStr(username, _T("emule.razorback3.com")) || 
		StrStrI(username, _T("[LSD.19")) //Xman 21.06.2005 definitive not a good mod, with protocol bugs
	)
		return _T("Bad USERNAME");

//bad mods, where every second sign is
//enough to check two places

	if (_tcslen(username) >= 4 && username[3] <= 0x1F && username[1] <= 0x1F)
		return _T("Leecher-Username");

	return NULL;
}

//SDC team start
#if defined(SPECIAL_DLP_VERSION)
LPCTSTR __declspec(dllexport) DLPCheckNameAndHash(const CString username, const CString & userhash)
#else //Official
LPCTSTR __declspec(dllexport) DLPCheckNameAndHash(CString username, CString & userhash)
#endif
//SDC team end
{
	if (username.IsEmpty() || userhash.IsEmpty())
		return NULL;

//community check
	if (username.GetLength() >= 7 && username.Right(1) == _T("]"))
	{
	//check for gamer
	//two checks should be enough.
		if (username.Right(6).Left(1) == userhash.Mid(5, 1) && username.Right(3).Left(1) == userhash.Mid(7, 1))
			return _T("Gamers");

	//check for snake
		int find = username.ReverseFind(_T('['));
		if (find >= 0)
		{
			CString addon = username.Mid(find + 1);
			int endpos = addon.GetLength() - 1;
		//SDC team start
		#if defined(SPECIAL_DLP_VERSION)
			int i{0};
			for (i = 0;i < endpos;++i)
		#else //Official
			for (int i = 0;i < endpos;i++)
		#endif
		//SDC team end
			{
				if (!(addon.GetAt(i) >= _T('0') && addon.GetAt(i) <= _T('9')))
					i = endpos + 1;
			}
			if (i == endpos)
				return _T("Snake");
		}
	}

	return NULL;
}
*/
//end old version ------------------------------------------

//SDC team start
#if defined(SPECIAL_DLP_VERSION)
const bool IsTypicalHex(const CString & addon)
#else //Official
bool IsTypicalHex(CString & addon)
#endif
//SDC team end
{
	if (addon.GetLength() > 25 || addon.GetLength() < 5)
		return false;
	short bigalpha = 0;
	short smallalpha = 0;
	short numeric = 0;
	int endpos = addon.GetLength();
//SDC team start
#if defined(SPECIAL_DLP_VERSION)
	int i{0};
	for (i = 0;i < endpos;++i)
#else //Official
	for (int i = 0;i < endpos;i++)
#endif
//SDC team end
	{
		if ((addon.GetAt(i) >= _T('0') && addon.GetAt(i) <= _T('9')))
			numeric++;
		else if ((addon.GetAt(i) >= _T('A') && addon.GetAt(i) <= _T('F')))
			bigalpha++;
		else if ((addon.GetAt(i) >= _T('a') && addon.GetAt(i) <= _T('f')))
			smallalpha++;
		else 
			break;
	}
	if (i == endpos)
	{
		if (numeric > 0 && (smallalpha > 0 && bigalpha == 0 || smallalpha == 0 && bigalpha > 0))
			return true;
	}

	return false;
}

LPCTSTR __declspec(dllexport) DLPCheckUserhash(const PBYTE userhash)
{
//No more AJ check
	return NULL;
}

//new versions
LPCTSTR __declspec(dllexport) DLPCheckModstring_Hard(LPCTSTR modversion, LPCTSTR clientversion)
{
	if (modversion == NULL || clientversion == NULL)
		return NULL;

	if (_tcsstr(clientversion, L"eMule Compat v0.26.2"))
		return L"Flashget";

	if (
//Chinese Leecher - https://forum.emule-project.net/index.php?showtopic=134097&hl=
		_tcsstr(modversion, L"TM0910") || 
//Chinese Leecher - https://forum.emule-project.net/index.php?showtopic=134097&hl=
//		StrStrI(modversion, _T("Freeza")) || 
		StrStrI(modversion, _T("FXeMule")) || 
		StrStrI(modversion, _T("FX eMule")) || 
		StrStrI(modversion, _T("RIAA")) || 
//		StrStrI(modversion, _T("d-unit")) || 
//		StrStrI(modversion, _T("NOS")) || //removed for the moment
//		StrStrI(modversion, _T("imperator")) || 
		StrStrI(modversion, _T("SpeedLoad")) || 
//		StrStrI(modversion, _T("gt mod")) || //outdated
//		StrStrI(modversion, _T("egomule")) || //outdated
//		StrStrI(modversion, _T("aldo")) || //outdated
//		StrStrI(modversion, _T("darkmule")) || //outdated
//		StrStrI(modversion, _T("LegoLas")) || 
//		StrStrI(modversion, _T("dodgethis")) || //Updated
//		StrStrI(modversion, _T("DM-")) || 
//		StrStrI(modversion, _T("|X|")) || 
//		StrStrI(modversion, _T("eVorte")) || 
//		StrStrI(modversion, _T("Mison")) || 
//		StrStrI(modversion, _T("father")) || 
//		StrStrI(modversion, _T("Dragon")) || 
//		StrStrI(modversion, _T("$motty")) || 
//		StrStrI(modversion, _T("Thunder")) || 
//		StrStrI(modversion, _T("BuzzFuzz")) || 
//		StrStrI(modversion, _T("Speed-Unit")) || 
//		StrStrI(modversion, _T("Killians")) || 
		StrStrI(modversion, _T("Element")) || 
//		StrStrI(modversion, _T("§¯Å]")) || //outdated
		StrStrI(modversion, _T("Rappi")) || 
		StrStrI(modversion, _T("EastShare")) && StrStrI(clientversion, _T("0.29")) || 
		StrStrI(modversion, _T("eChanblard v7.0")) || 
//		StrStrI(modversion, _T("ACAT")) || 
//		StrStrI(modversion, _T("!FREEANGEL!")) || 
		StrStrI(modversion, _T("          ")) || 
//		StrStrI(modversion, _T("Stonehenge")) || 
		StrStrI(modversion, _T("@RAPTOR")) || 
		StrStr(modversion, _T("pwNd muLe")) || 
		StrStrI(modversion, _T("HARDPAW")) || 
//		StrStrI(modversion, _T("XXL")) || 
		StrStrI(modversion, _T("LSD")) || 
		StrStrI(modversion, _T("Bad Donkey")) || //WiZaRd
		StrStrI(modversion, _T("DSL-Light-Client")) || //WiZaRd
		StrStrI(modversion, _T("Elben")) || //WiZaRd
		StrStr(modversion, _T("PROeMule")) || //WiZaRd
		StrStrI(modversion, _T("Devil")) || 
		StrStrI(modversion, _T("Elfen")) || 
		StrStrI(modversion, _T("Ef-mod 2.0 ")) || //Xman this mod can be abused as a full leecher
		StrStrI(modversion, _T("Xtreme Xtended")) || //Xman 15.08.05
		StrStrI(modversion, _T("MirageMod")) || //"
		StrStrI(modversion, _T("SpeedX")) || 
		StrStrI(modversion, _T("AIDEADSL")) || 
		StrStrI(modversion, _T("Hypnotix")) || 
		StrStrI(modversion, _T("BLACKMULE")) || 
		StrStrI(modversion, _T("blackviper")) || 
		StrStrI(modversion, _T("BlackAngel")) || 
		StrStrI(modversion, _T("rabbit")) || 
		StrStrI(modversion, _T("rabb_it")) || 
		StrStrI(modversion, _T("Raptor")) || 
		StrStrI(modversion, _T("Hawkstar")) || 
		StrStrI(modversion, _T("ServerClient")) || 
		StrStrI(modversion, _T("Love-Angel")) || 
		StrStrI(modversion, _T("SuperKiller")) || 
		StrStrI(modversion, _T("ZamBoR")) || 
		StrStrI(modversion, _T("Morph")) && (StrStrI(modversion, _T("Max")) || StrStrI(modversion, _T("+")) || StrStrI(modversion, _T("×"))) || 
		StrStrI(modversion, _T("Morph XT")) || //very bad mod (MPAA ?)
		StrStrI(modversion, _T("Mørph")) || 
		StrStrI(modversion, _T("BlueHex")) || 
		StrStrI(modversion, _T("FlowerPower")) || 
		StrStrI(modversion, _T("Fincan")) || 
		StrStrI(modversion, _T("OO.de")) || //WiZaRd
		StrStrI(modversion, _T("00.de")) || //WiZaRd
		StrStrI(modversion, _T("OOde")) || //WiZaRd
		StrStrI(modversion, _T("00de")) || 
		StrStrI(modversion, _T("OS_")) || //Xman most are found via other checks, but not all
		StrStrI(modversion, _T("Heartbreaker")) || 
		StrStrI(modversion, _T("Arabella")) || 
		StrStrI(modversion, _T("Administrator")) || 
		StrStrI(modversion, _T("B@d-D3vi7")) || 
		StrStrI(modversion, _T("Dying Angel")) || 
		StrStrI(modversion, _T("FREAK MOD VENOM")) || 
		StrStrI(modversion, _T("CryptedSpeed")) || 
		StrStrI(modversion, _T("h34r7b34k3r")) || 
		StrStrI(modversion, _T("Exorzist")) || 
		StrStrI(modversion, _T("A.i.d.e-A.D.S.L")) || 
		StrStrI(modversion, _T("albaR")) || 
		StrStrI(modversion, _T("AngelDr")) || //5/2006
		StrStrI(modversion, _T("Tombstone Reloaded")) || //5/2006
		StrStrI(modversion, _T("Tombstone Next")) || //10/2006
		StrStrI(modversion, _T("pP.r8b")) || //5/2006
		StrStrI(modversion, _T("x0Rz!$T")) || //E/€xorzist
		StrStrI(modversion, _T("€xORz!§T")) || 
		_tcsstr(clientversion, _T("eMule Compat v0.40")) || //7/2006
		_tcsstr(clientversion, _T("eMule Compat v127.")) || //8/2006
		StrStrI(modversion, _T("No Ratio")) || //based on scarangel 7/2006
		StrStrI(modversion, _T("DeathAngel")) || //based on Xtreme 8/2006
		StrStrI(modversion, _T("PROemule")) || //9/2006
		StrStrI(modversion, _T("Simple Leecher")) || //9/2006
		StrStrI(modversion, _T("oFF *+*")) || //10/2006
		StrStrI(modversion, _T("0FF ")) || //6/2007
		StrStrI(modversion, _T("SmartMuli")) || //12/2006
		StrStrI(modversion, _T("D10T")) || //12/2006
		StrStrI(modversion, _T("the fonz")) || //12/2006
		StrStrI(modversion, _T("TurkMule")) || //1/2007
		StrStrI(modversion, _T("Hyperdrive")) || //1/2007
		StrStrI(modversion, _T("NextEvolution")) || //1/2007
		StrStrI(modversion, _T("Pimp")) || //3/2007
		StrStrI(modversion, _T("XDP ")) || //6/2007
		StrStrI(modversion, _T("AeOnFlux")) || //8/2007
	//8/2007 from dlarge:
		StrStrI(modversion, _T("Final Fight")) || //added dlarge
		StrStrI(modversion, _T("Fireball")) || //added dlarge "standart String"
		StrStrI(modversion, _T("SunPower")) || //added dlarge "standart String"
		StrStrI(modversion, _T("SuperKiller")) || //added dlarge
		StrStrI(modversion, _T("X-Cite")) || //added dlarge
		StrStrI(modversion, _T("waZZa")) || //added dlarge
		StrStrI(modversion, _T("Merza")) || //added dlarge
		StrStrI(modversion, _T("K.O.T.")) || //added dlarge
		StrStrI(modversion, _T("Licokine")) || //added dlarge
		StrStrI(modversion, _T("BlackStar")) || //added dlarge
		StrStrI(modversion, _T("nEwLoGic")) || //added dlarge
	//end
		StrStrI(modversion, _T("Applejuice")) || //6/2007 now ban instead score reduce
//more AJ modstrings
		StrStrI(modversion, L"Wikinger") || 
		StrStrI(modversion, L"ROCKFORCE") || 
		StrStrI(modversion, L"RC-ATLANTIS") || 
//more AJ modstrings
//zz_fly Start
	//modstring of XL
		_tcsstr(modversion, _T("20071122")) || _tcsstr(modversion, _T("20080228")) || 
		_tcsstr(modversion, _T("080620")) || _tcsstr(modversion, _T("080307")) || 
		_tcsstr(modversion, _T("080509")) || _tcsstr(modversion, _T("20080505")) || 
		_tcsstr(modversion, _T("v 080828")) || _tcsstr(modversion, _T("XL8828")) || 
		_tcsstr(modversion, _T("build 11230")) || _tcsstr(modversion, _T("20080923")) || 
		_tcsstr(modversion, _T("ZZULL")) || _tcsstr(modversion, _T("XunaLei")) || 
		_tcsstr(modversion, _T("XunL")) || _tcsstr(modversion, _T("Xthunder")) || 
		_tcsstr(modversion, _T("xl build")) || 
	//end
		_tcsstr(modversion, _T("FreeCD")) || //BitComet, changed to hardban
		_tcsstr(modversion, _T("PlayMule")) || //PlayMule
		(!CString(modversion).IsEmpty() && CString(modversion).Trim().IsEmpty()) || //pruma, korean leecher, modversion is a space
		_tcsstr(modversion, _T("VMULE")) || //israel
		StrStrI(modversion, _T("Goop.co.il")) || 
		StrStrI(modversion, _T("Razorback")) || 
		StrStrI(modversion, _T("UlTiMaTiC ")) || //based on MA 3.5
		StrStrI(modversion, _T("Peizheng")) || //gpl-breaker
		_tcsstr(modversion, _T("amule")) || //fake version, amule never write a modstring here
		_tcsstr(modversion, _T("Amule")) || 
	//2010/5/29
		_tcsstr(modversion, _T("miniMule")) || //a compatible client, but without share file option.
		StrStrI(modversion, _T("EYE888")) || //compatible client in china, but no src
		StrStrI(modversion, _T("WebeSo")) || //compatible client in china, but no src //Chengr28
		(_tcsstr(modversion, _T(" 091113")) && !_tcsstr(modversion, _T("VeryCD"))) || //compatible client in china, but no src //tetris
		StrStrI(modversion, _T("Unbuyi")) || //a client announced that it is based on a its framework, but in fact it just copy VeryCD's code //Chengr28
	//2010/12/11
		_tcsstr(modversion, _T("easyMule2")) || //protocol bug, lack maintaince, ban
//zz_fly End
		_tcsstr(modversion, _T("Neo-R")) || 
		_tcsstr(modversion, _T("Neo-RS")) || 
		StrStrI(modversion, _T("Apace")) || 
		StrStrI(modversion, _T("L!()Netw0rk")) || 
		StrStrI(modversion, _T("L!ONetwork")) || 
		StrStrI(modversion, _T("l!onet")) || 
		StrStrI(modversion, _T("l!0net")) || 
		StrStrI(modversion, _T("lionet")) || 
		StrStrI(modversion, _T("li0net")) || 
		StrStrI(modversion, _T("li()net")) || 
		StrStrI(modversion, _T("L!()Net")) || 
		StrStrI(modversion, _T("800STER")) || 
		StrStrI(modversion, _T("8OOSTER")) || 
		StrStrI(modversion, _T("BOO$T")) || 
		StrStrI(modversion, _T("B00ST")) || 
		StrStrI(modversion, _T("T-L-N BO0ST")) || //by briandgwx
		StrStrI(modversion, _T("T L N B O O S T")) || //by taz-me
		StrStrI(modversion, _T("iberica")) || //by briandgwx
//from **Riso64Bit**
		_tcsstr(modversion, _T("Thor ")) || 
		_tcsstr(modversion, _T("DeSfAlko")) || 
		_tcsstr(modversion, _T("The Killer Bean")) || 
		_tcsstr(modversion, _T("ZZ-R ")) || 
		_tcsstr(modversion, _T("ZZ-RS ")) || 
		_tcsstr(modversion, _T("Reptil-Crew-3")) || 
		_tcsstr(modversion, _T("Anonymous Mod")) || 
		StrStrI(modversion, _T("NFO.Co.iL")) || 
		_tcsstr(modversion, _T("Down.co.il")) || 
		_tcsstr(modversion, _T("Red Projekt")) || 
		_tcsstr(modversion, _T("centraldivx.com")) || //no source
		StrStrI(modversion, _T("emule.co.il")) || 
		StrStrI(modversion, _T("Fire eMule")) || 
		StrStrI(modversion, _T("PirateMule")) || 
		StrStrI(modversion, _T("HighTime")) || 
		StrStrI(modversion, _T("GPS2Crew")) || 
		StrStrI(modversion, _T("TLN eMule")) || 
		StrStrI(modversion, _T("DVD-RS")) || 
		_tcsstr(modversion, _T("ZZULtimativ-R")) || 
		_tcsstr(modversion, _T("Div eMule")) || 
		_tcsstr(modversion, _T("Pwr eMule")) || 
//		_tcsstr(modversion, _T("VipeR")) || //it become good
		_tcsstr(modversion, _T("Methadone")) || 
		_tcsstr(modversion, _T("Titandonkey")) || 
		_tcsstr(modversion, _T("SpeedShare")) || 
		_tcsstr(modversion, _T("Wodan")) || 
		_tcsstr(modversion, _T("Sikombious")) || 
		_tcsstr(modversion, _T("HyperTraxx")) || 
		_tcsstr(modversion, _T("Div pro")) || 
		_tcsstr(modversion, _T("GangBang")) || 
		_tcsstr(modversion, _T("WarezFaw")) || 
		_tcsstr(modversion, _T("Rastak")) || 
		_tcsstr(modversion, _T("Okinawa")) || 
		_tcsstr(modversion, _T("Hiroshima")) || 
		_tcsstr(modversion, _T("Kamikaze")) || 
		_tcsstr(modversion, _T("Yotoruma")) || 
		_tcsstr(modversion, _T("Nagasaki")) || 
		_tcsstr(modversion, _T("Addiction")) || 
		_tcsstr(modversion, _T("Bondage")) || 
		_tcsstr(modversion, _T("eMuleLife")) || 
		StrStrI(modversion, _T("PP-edition")) || 
		StrStrI(modversion, _T("ZZULtra")) || 
		_tcsstr(modversion, _T("eMulix")) || 
		_tcsstr(modversion, _T("BigBang")) || 
		_tcsstr(modversion, _T("PR0 ")) || //0(zero)
		_tcsstr(modversion, _T("PRO ")) || //o
		_tcsstr(modversion, _T("LoCMuLe")) || 
		_tcsstr(modversion, _T("Flux ")) || 
//		_tcsstr(modversion, _T("Aurora")) || 
//		_tcsstr(modversion, _T("Alias")) || //although it is the base-version of leechermods, but it has no leecher function, unban it
//		_tcsstr(modversion, _T("R-Mod")) || //same as Alias
		_tcsstr(modversion, _T("UniATeam")) || 
		StrStrI(modversion, _T("Torenkey")) || 
		StrStrI(modversion, _T("RSVCD")) || 
		_tcsstr(modversion, _T("BlueEarth")) || 
		_tcsstr(modversion, _T("RocketMule")) || 
		_tcsstr(modversion, _T("eMule 0.4")) || //some bad mods write clientversion in modstring
		_tcsstr(modversion, _T("Emule")) || 
		_tcsstr(modversion, _T("eMule v")) || 
		_tcsstr(modversion, _T("OrAnGe")) || 
		StrStrI(modversion, _T("Evil Mod")) || 
		StrStrI(modversion, _T("StulleMule v")) || //real modstring is "StulleMule #.#", no 'v'
		StrStrI(modversion, _T("X-Ray v")) || 
		StrStrI(modversion, _T("Ulti F")) || 
		StrStrI(modversion, _T("ChímÊrÂ")) || 
		StrStrI(modversion, _T("ÇhïmerÀ")) || 
		StrStrI(modversion, _T("Plus Plus")) || //some of them did not banned in bin
		_tcsstr(modversion, _T("UMatic")) || 
		_tcsstr(modversion, _T("BRAZILINJAPAN")) || //no source
		StrStrI(modversion, _T("Pigpen")) || 
		_tcsstr(modversion, _T("TCMod")) || 
		StrStrI(modversion, _T("UltiMatiX")) || 
		_tcsstr(modversion, _T("Perestroika")) || 
		_tcsstr(modversion, _T("Ebola")) || 
		StrStrI(modversion, _T("StulleMule Plus")) || 
		_tcsstr(modversion, _T("DVD-START.COM")) || 
		(_tcsicmp(clientversion, _T("eMule")) == 0) || //the client did not send client version
		_tcsstr(modversion, _T("Penthotal")) || 
		_tcsstr(clientversion, _T("eMule Compat v2.1")) || //+Ultra
//		_tcsstr(modversion, _T("TSmod")) || 
		_tcsstr(modversion, _T("Okaemule")) || 
		_tcsstr(modversion, _T("Okamula")) || 
		_tcsstr(modversion, _T("Potenza")) || 
		_tcsstr(modversion, _T("AntraX MoD")) || 
//		_tcsstr(modversion, _T("Picapica")) || 
//		_tcsstr(modversion, _T("PeaceMule")) || 
		_tcsstr(modversion, _T("0.49b")) || 
		_tcsstr(modversion, _T("0.49c")) || 
		_tcsstr(modversion, _T("Metha")) || 
//		_tcsstr(modversion, _T("XTreme")) || move to fake area
	//newlines 2009/11/8
		_tcsstr(modversion, _T("UMatiX-45a")) || 
		StrStrI(modversion, _T("maultierpower")) || //maultier-power.com sponsorize applejuice
		StrStrI(modversion, _T("PoWeR MoD")) || 
		StrStrI(modversion, _T("UltiAnalyzer")) || 
		StrStrI(modversion, _T("UBR-Mod")) || 
	//2009/11/29
		StrStrI(modversion, _T("UltraFast")) || //thl
	//2010/4/4
		_tcsstr(modversion, _T("Devils Mod")) || 
		StrStrI(modversion, _T("-XDP-")) || 
	//2010/6/6
		_tcsstr(modversion, _T("Sharinghooligan")) || 
//end
//from XRAY antileecher start
		StrStrI(modversion, L"SPEED EMULE") || //MyTh
		StrStrI(modversion, L"SPIKE2 +") || //MyTh hard leecher
//		StrStrI(modversion, L"Adunanza") || //MyTh italian ISP-spec com user
		StrStrI(modversion, L"Asiklar") || //MyTh apple-com
		StrStrI(modversion, L"Shadow") || //MyTh
		StrStrI(modversion, L"EPB") || //MyTh
		StrStrI(modversion, L"Tyrantmule") || //MyTh
		StrStrI(modversion, L"APRC") || //MyTh
		StrStrI(modversion, L"Hardstyle") || //MyTh
		StrStrI(modversion, L"pP.r12b") || //MyTh
		StrStrI(modversion, L"Simple Life") || //MyTh
		StrStrI(modversion, L"TYRANUS") || //MyTh
		StrStrI(modversion, _T("[OO.de-L33CH4")) || //Stulle
		(StrStrI(modversion, _T("sivka v12e8")) && StrStrI(clientversion, L"0.42e")) || //m_nClientVersion != MAKE_CLIENT_VERSION(0, 42, 4) //added - Stulle
		StrStrI(modversion, L"RapCom") || //added dlarge
		StrStrI(modversion, L"SBI leecher") || //added dlarge
		StrStrI(modversion, L"TS Next Lite") || //added dlarge
//from XRAY antileecher end
		StrStrI(modversion, L"Dein Modstring") || //JvA: moved up from soft because also used by Applejuice
		StrStrI(modversion, L"Angelmule") || //JvA: no sources, no changelog, community username,...
		StrStrI(modversion, L"TR-P2P-MoD") || //JvA: bad client
		StrStrI(modversion, L"Esekci") || //JvA: no sources, no changelog, ...
		StrStrI(modversion, L"MaGiX") || //default modstring if activated and unchanged
		StrStrI(modversion, L"MorphJC") || //bad 'Justice CS' and PBF for incomplete files
		_tcslen(modversion) > 0 && (StrStrI(clientversion, _T("edonkey")) || modversion[0] == _T('[')) || //1. donkey user with modstring, 2. modstring begins with [ this is a known leecher
		(StrStrI(modversion, _T("Xtreme")) && StrStrI(modversion, _T("]"))) //bad Xtreme mod
	)
		return _T("Bad MODSTRING");

	if (_tcsstr(modversion, _T("xtreme")) || _tcsstr(modversion, _T("XTreme"))) //case sensitive!
		return _T("Fake Xtreme");

//zz_fly :: fake modstring area
//move some entries from above
	if (((_tcsstr(modversion, _T("MorphXT v9.6")) || _tcsstr(modversion, _T("Xtreme 7")) || _tcsstr(modversion, _T("ZZUL Plus 1"))) && _tcsstr(clientversion, _T("0.48a"))) || //should not 0.48a
		_tcsstr(modversion, _T("NetF WARP 9")) || //should be NetF WARP 0.3a.9
		_tcsstr(modversion, _T("VeryCD 080126")) || //Fake VeryCD
		_tcsstr(modversion, _T("VeryCD 080730")) || //Fake VeryCD
		_tcsstr(modversion, _T("VeryCD 080509")) || //Fake VeryCD
		_tcsstr(modversion, _T("VeryCD 080606")) || //Fake VeryCD
		_tcsstr(modversion, _T("VeryCD 080624")) || //Fake VeryCD
		_tcsstr(modversion, _T("VeryCD 080630")) || //Fake VeryCD
		(_tcsstr(modversion, _T("easyMule 10")) && _tcsstr(clientversion, _T("0.48a"))) || //easymule 10#### are not based on .48a
		(_tcsstr(modversion, _T("VeryCD 080919")) && _tcsstr(clientversion, _T("0.49b"))) //fake clientversion, should be 0.48a
	)
		return _T("Fake MODSTRING");
//zz_fly :: end

//WiZaRd Bad Modstring Scheme
	CString strMod = CString(modversion);
	if (strMod.IsEmpty() || 
		(strMod.Find(_T("CHN ")) == 0 && strMod.GetLength() > 8) || 
		(strMod.Find(_T("Apollo")) == 0) || //Apollo is a Portugal Mod
		(strMod.Find(_T("sivka")) == 0) || 
		(strMod.Find(_T("aMule CVS")) == 0)
	)
	{
		; //do nothing
	}
	else {
		if (_tcsstr(clientversion, _T("eMule v")) && (strMod.GetLength() <= 4)) //most of them are fincan
			return L"Bad Modstring Scheme";

		int iNumberFound = -1;
	//SDC team start
	#if defined(SPECIAL_DLP_VERSION)
		_TINT ch{0};
	#else //Official
		_TINT ch;
	#endif
	//SDC team end
		bool bBad = false;
		bool bNotEnd = false;
		for (int i = 0;i < strMod.GetLength() && bBad == false;++i)
		{
			ch = strMod.GetAt(i);
			if (ch == L'.' || ch == L' ')
			{
				bNotEnd = true; //these chars should not be the end of modstring
				iNumberFound = -1; //this is a simple hack to not punish mods like TK4 or Spike2 :)
				continue; //skip "legal" chars
			}
			if (ch == L'-' /* || ch == L'+' */ ) //connector characters, connect two string or two numbers
			{
				bNotEnd = true; //these chars should not be the end of modstring
				if (iNumberFound != -1)
					iNumberFound++; //exclude some modstring like v#.#-a1
				continue;
			}
			if (_istpunct(ch) || _istspace(ch))
			{
				bBad = true; //illegal punctuation or whitespace character
			}
			else if (_istcntrl(ch))
			{
				bBad = true; //control character in modstring!?
			}
			else {
				bNotEnd = false;
				if (_istdigit(ch))
				{
					iNumberFound = i;
				}
				else if ((iNumberFound == i - 1) && _istxdigit(ch)) //abcdef is legal in the end of version number, also exclude bowlfish tk4 and so on
				{
					; //do nothing
				}
				else if (iNumberFound != -1)
				{
					bBad = true; //that is: number out of row, e.g. not MorphXT v11.9 but Morph11XT.9
				}
			}
		}

		if (bBad || bNotEnd)
			return L"Bad Modstring Scheme";
	}
//WiZaRd

//SDC team start
#if defined(SPECIAL_DLP_VERSION)
	if ((wcsstr(clientversion, L"0.49c") != nullptr && wcsstr(modversion, L"X-Ray 2.") != nullptr) || //Fake X-Ray Mod [**Riso64Bit**]
		(wcsstr(clientversion, L"0.48a") != nullptr && wcsstr(modversion, L"MorphCA") != nullptr) || //Fake MorphCA [DargonD]
		wcsstr(modversion, L"0.50a") != nullptr || //ClientVersion instead of ModString [DargonD]
		wcsstr(clientversion, L"eMule v5.6a") != nullptr //Fake official [冰靈曦曉]
	) [[unlikely]]
		return L"<SDC> Fake ModString";

	if (wcsstr(modversion, L"eMule-GIFC") != nullptr || //GPL-Breaker [DragonD]
		wcsstr(clientversion, L"4.0h") != nullptr || //SpeedyP2P
		wcsstr(modversion, L"OS") != nullptr || //GPL-Breaker [ieD2k]
		wcsstr(modversion, L"THC") != nullptr || //Fake queues [Bill Lee]
		wcsstr(modversion, L"EggAche") != nullptr || //Custom ModString
		wcsstr(modversion, L"DarkSky") != nullptr || //Custom ModString
		wcsstr(modversion, L"eMuleTorrent") != nullptr //GPL-Breaker [冰靈曦曉]
	) [[unlikely]]
		return L"<SDC> Bad ModString";

//Removed since 44005 update 3.
//The traditional Non-Standard ModString check is like a "whitelist" and it's unfriendly to new mod.
/*
#if defined(SPECIAL_DLP_ADVANCED)
	std::size_t ClientData[]{static_cast<const std::size_t>(strMod.GetLength()), 0, 0};
	if (ClientData[0] >= 1U && 
		wcsstr(modversion, L"eserver") == nullptr && //eServer
		wcsstr(modversion, L"Apollo") == nullptr && //Apollo Mod
		(wcsstr(modversion, L"CHN ") == nullptr || ClientData[0] <= 8U) //CN Mod
	) [[likely]]
	{
		if (wcsstr(modversion, L" ") != nullptr || wcsstr(modversion, L".") != nullptr) [[likely]]
		{
			for (ClientData[1U] = 0;ClientData[1U] < ClientData[0];++ClientData[1U])
			{
				const auto NSData{strMod.GetAt(static_cast<const int>(ClientData[1U]))};
				if ((NSData >= 65U && NSData <= 90U) || (NSData >= 97U && NSData <= 122U))
					ClientData[2U] = 1U;
				if ((ClientData[2U] == 0 && (ClientData[1U] == 0 || ClientData[1U] + 1U == ClientData[0])) || NSData == 91U || NSData == 93U || //"[" and "]" in ModString
					(ClientData[2U] != 1U && NSData != 32U && NSData != 40U && NSData != 41U && NSData != 43U && //" ", "(", ")" or "+" in ModString
					NSData != 45U && NSData != 46U && //"-" or "." in Modstring
					(NSData <= 47U || NSData >= 58U)) //Number in ModString
				) [[unlikely]]
					return L"<SDC> Non-Standard ModString";
			}
		}
		else { //" " or "." in ModString
			return L"<SDC> Non-Standard ModString";
		}
	}
#endif
*/
#endif
//SDC team end

	return NULL;
}

LPCTSTR __declspec(dllexport) DLPCheckModstring_Soft(LPCTSTR modversion, LPCTSTR clientversion)
{
	if (modversion == NULL || clientversion == NULL)
		return NULL;

	if (StrStrI(modversion, _T("Rockesel")) || 
		StrStrI(modversion, _T("HARDMULE")) || 
		StrStrI(modversion, _T("Community")) || 
		StrStrI(modversion, _T("IcE-MoD")) || 
		StrStrI(modversion, _T("a-eDit")) || 
		StrStrI(modversion, _T("Ultimativ")) || 
		StrStrI(modversion, _T("Ultimate")) || 
//		StrStrI(modversion, _T("Ulti F")) || //move to hard ban
		StrStrI(modversion, _T("Enter MoD Name")) || 
//		StrStrI(modversion, _T("Dein Modstring")) || // 3/2007
//		StrStrI(modversion, _T("choose your modstring")) || // 3/2007
		StrStrI(modversion, _T("La tua Modstring")) || //italian
	//8/2007 from dlarge:
//		StrStrI(modversion, _T("Enter Your Modstring")) || //added dlarge
		StrStrI(modversion, _T("Your Modstring")) || 
		StrStrI(modversion, _T("C-E-R-E-B-R-O")) || //added dlarge
	//end
		StrStrI(modversion, _T("NewMule")) || 
		StrStrI(modversion, _T("smart- muli")) || 
		StrStrI(modversion, _T("TCMatic 3")) || //1/2007 //version 3 is the public version and used as leecher
//		StrStrI(clientversion, _T("eMule v2.0")) || //6/2007 fake Xtreme / GPL-breaker
		StrStrI(modversion, _T("uptempo"))
//zz_fly Start
		|| _tcsstr(clientversion, _T("eMule v0.95g")) //korea
		|| _tcsstr(clientversion, _T("eMule v0.47f"))
		|| _tcsstr(modversion, _T("Bowlfish")) //international filter, change to softban.
		|| StrStrI(modversion, _T("BLACKMULE")) //no completely source, but it seems it do not have leecher functions.
		|| _tcsstr(clientversion, _T("eMule v1.")) //ban all version number >= 1.0
		|| _tcsstr(clientversion, _T("eMule v2."))
//		|| _tcsstr(clientversion, _T("eMule v3."))
		|| _tcsstr(clientversion, _T("Shareaza v6.")) //Shareaza's current version is 2.5.2
		|| _tcsstr(clientversion, _T("Shareaza v5."))
		|| _tcsstr(clientversion, _T("Shareaza v4."))
		|| _tcsstr(clientversion, _T("Shareaza v3."))
		|| StrStrI(modversion, _T(".COM")) //no domain name in modstring
		|| StrStrI(modversion, _T(".ORG"))
		|| StrStrI(modversion, _T(".NET"))
		|| StrStrI(modversion, _T(".BIZ"))
		|| StrStrI(modversion, _T(".INFO"))
//zz_fly End
		|| (_tcsstr(clientversion, _T("lphant v2.01")) && _tcsstr(modversion, _T("Plus"))) //www.lphantplus.com, no src
	)
		return _T("Bad MODSTRING");

//SDC team start
#if defined(SPECIAL_DLP_VERSION)
#if (defined(SDC_ALL_VERYCD) || defined(SDC_VERYCD_TAG))
	if (wcsstr(modversion, L"VeryCD") != nullptr && 
		wcsstr(modversion, L"VeryCD 090304") == nullptr //It will be handled by DLPCheckNameAndHashAndMod function.
	) [[unlikely]]
		return L"<SDC> all-verycd";
#elif defined(SDC_EASYMULE)
	if (wcsstr(modversion, L"easyMule") != nullptr || //Current ModString
	//ModString in 2007 and 2008
		(wcsstr(modversion, L"VeryCD ") != nullptr && 
		(wcsstr(modversion, L" 071109") != nullptr || wcsstr(modversion, L" 071207") != nullptr || wcsstr(modversion, L" 071229") != nullptr || 
		wcsstr(modversion, L" 080125") != nullptr || wcsstr(modversion, L" 080202") != nullptr || wcsstr(modversion, L" 080227") != nullptr || 
		wcsstr(modversion, L" 080320") != nullptr || wcsstr(modversion, L" 080401") != nullptr || wcsstr(modversion, L" 080506") != nullptr || 
		wcsstr(modversion, L" 080514") != nullptr || wcsstr(modversion, L" 080701") != nullptr || wcsstr(modversion, L" 080701") != nullptr || 
		wcsstr(modversion, L" 080722") != nullptr || wcsstr(modversion, L" 080815") != nullptr || wcsstr(modversion, L" 080905") != nullptr || 
		wcsstr(modversion, L" 080905") != nullptr || wcsstr(modversion, L" 080928") != nullptr || wcsstr(modversion, L" 081015") != nullptr || 
		wcsstr(modversion, L" 081023") != nullptr || wcsstr(modversion, L" 081023") != nullptr || wcsstr(modversion, L" 081113") != nullptr || 
		wcsstr(modversion, L" 081121") != nullptr || wcsstr(modversion, L" 081122") != nullptr || wcsstr(modversion, L" 081205") != nullptr || 
		wcsstr(modversion, L" 081218") != nullptr))
	) [[unlikely]]
		return L"<SDC> easymule";
#endif
#endif
//SDC team end

	return NULL;
}

LPCTSTR __declspec(dllexport) DLPCheckUsername_Hard(LPCTSTR username)
{
	if (username == NULL)
		return NULL;

	if (
//Chinese Leecher - https://forum.emule-project.net/index.php?showtopic=134097&hl=
		_tcsstr(username, L"dianlei.com") || 
		_tcsstr(username, L"[eMuleBT]") || 
		_tcsstr(username, L"[PPMule]") || 
		StrStrI(username, L"TUOTU") || 
		_tcsstr(username, L"kaggo.com") || 
		_tcsstr(username, L"[Chinfo]") || 
		_tcsstr(username, L"vgo.21cn") || 
//Chinese Leecher - https://forum.emule-project.net/index.php?showtopic=134097&hl=
//		StrStrI(username, _T("$WAREZ$")) || 
//		StrStrI(username, _T("Leecha")) || 
//		StrStrI(username, _T("Reverse")) || 
//		StrStrI(username, _T("$motty")) || 
		StrStrI(username, _T("emule-speed")) || 
		StrStrI(username, _T("Intuition")) || 
//		StrStrI(username, _T("W.I.P.")) || //outdated
//		StrStrI(username, _T("celinesexy")) || 
//		StrStrI(username, _T("Gate-eMule")) || 
//		StrStrI(username, _T("energyfaker")) || 
//		StrStrI(username, _T("BuzzFuzz")) || 
//		StrStrI(username, _T("Speed-Unit")) || 
//		StrStrI(username, _T("Killians")) || 
//		StrStrI(username, _T("pubsman")) || 
		StrStrI(username, _T("emule-element")) || 
//		StrStrI(username, _T("emule")) && StrStrI(username, _T("booster")) || 
//		StrStrI(username, _T("Rappi")) || 
		StrStrI(username, _T("Ketamine")) || 
		StrStrI(username, _T("emuleech.com")) || 
//		StrStrI(username, _T("SchlumpMule")) || //"
//		StrStrI(username, _T("Safty´s")) || 
		StrStr(username, _T("UnKnOwN pOiSoN")) || 
//		StrStrI(username, _T("ElfenPower")) || 
//		StrStrI(username, _T("eMule Cow")) || 
//		StrStrI(username, _T("Freezamule")) || 
		StrStrI(username, _T("EGOmule")) || 
		StrStrI(username, _T("-=EGOist=-")) || 
//		StrStrI(username, _T("FreezaVamp")) || 
		StrStrI(username, _T("Muli_Checka")) || 
		StrStrI(username, _T("00de.de")) || 
//		StrStrI(username, _T("00de")) || 
//		StrStrI(username, _T("OO.de")) || 
//		StrStrI(username, _T("OOde")) || 
//		StrStrI(username, _T("PrOjEcT-SaNdStOrM")) || 
//		StrStrI(username, _T("NotHer eDitiOn")) || 
//		StrStrI(username, _T("eSl@d3vil")) || 
//		StrStrI(username, _T(" AgentSmith")) || 
//		StrStrI(username, _T("rabb_it")) || 
//		StrStrI(username, _T("ServerClient")) || 
		StrCmpI(username, _T("Muse")) == 0 || //ketamine mod
//		StrStr(username, _T("ZamBoR")) || 
//		StrStrI(username, _T("HARDMULE")) || 
		StrStrI(username, _T("futurezone-reloaded")) || 
		StrStrI(username, _T("Gate-To-Darkness.com")) || 
		StrStrI(username, _T("Razorback")) || 
		StrStrI(username, _T("Titanesel.tk")) || 
		StrStrI(username, _T("bigbang.to")) || 
		StrStrI(username, _T("leecherclients.org")) || //Xman 10/06
		StrStrI(username, _T("futuremods.de")) || //Xman 10/06
		StrStrI(username, _T(".::Stenoco-Zone::.")) || 
		StrStrI(username, _T("emule-mods.cc")) || //Xman 01/07
		StrStrI(username, _T("leecher-mod.net")) || //Xman 02/07
	//08/2007 from dlarge:
		StrStrI(username, _T("leecher-world.com")) || //added dlarge
		StrStrI(username, _T("leecher.biz")) || //added dlarge
	//end
	//Xman 6/2007:
//more AJ modstrings
//		(StrStrI(username, L"[") && StrStrI(username, L"]")
//		&& (
			StrStrI(username, L"Applejuice") || 
			StrStrI(username, L"Wikinger") || 
			StrStrI(username, L"ROCKFORCE") || 
			StrStrI(username, L"RC-ATLANTIS") || 
			StrStrI(username, L"Fireball") || 
			StrStrI(username, L"SunPower") || 
//		)
//		) || 
//		StrStrI(username, _T("AppleJuice")) && StrStrI(username, _T("[")) && StrStrI(username, _T("]")) || 
		StrStrI(username, L"futuremod.de") || //JvA: apple-com adress
//more AJ modstrings
		StrStrI(username, L"@ Raptor") || //added dlarge
		StrStrI(username, L"FUCKLW") || //added dlarge
//zz_fly Start
		_tcsstr(username, _T("a1[VeryCD]xthame")) || //XL
		StrStrI(username, _T("Flashget")) || //FlashGet
		_tcsstr(username, _T("http://www.net-xfer.com")) || //netxfer
		_tcsstr(username, _T("emuIe-project.net")) || //phishing site
		_tcsstr(username, _T("QQDownload")) || //tencent
		_tcsstr(username, _T("[Devils][")) || //2009/12/25
		_tcsstr(username, _T("sharing-devils")) || //leecher community
	//2010/5/29
//		_tcsstr(username, _T("btbbt.com")) || //community username
//		_tcsstr(username, _T("Greendown.Cn")) || //community username //these two sites provide some modified versions. they only hacked the title and changed the default username. i think the users are innocent. unban.
		_tcsstr(username, _T("MTVP2P")) || //community username from Chengr28
		_tcsstr(username, _T("qobfxb")) || //community username
		_tcsstr(username, _T("[CHN][VeryCD]QQ")) || //QQDownload
//zz_fly End
		StrStrI(username, _T("lionetwork")) || 
		StrStrI(username, _T("[lionheart")) || 
		StrStrI(username, _T("li@network")) || 
		StrStrI(username, _T("l!onetwork")) || 
		StrStrI(username, _T("li()net")) || 
		StrStrI(username, _T("l!0net")) || 
		StrStrI(username, _T("L!()Network")) || 
		StrStrI(username, _T("Li()Network")) || 
		StrStrI(username, _T("L!0Network")) || 
		StrStrI(username, _T("Li@Network")) || 
//from **Riso64Bit**
		_tcsstr(username, _T("FincanMod")) || //fincan
		_tcsstr(username, _T("Finc@nMod")) || 
		StrStrI(username, _T("titanmule")) || 
		StrStrI(username, _T(".c0.il")) || //0, zero
		StrStrI(username, _T("Goop.Co.il")) || //israel community
		StrStrI(username, _T("Div.Co.il")) || 
		StrStrI(username, _T("emule.co.il")) || 
		StrStrI(username, _T("pwr.co.il")) || 
		StrStrI(username, _T("nFo.Co.il")) || 
		StrStrI(username, _T("lhnet.co.il")) || 
		StrStrI(username, _T("ynet.co.il")) || 
		StrStrI(username, _T("wnet.co.il")) || 
		StrStrI(username, _T("Paf.co.il")) || 
		StrStrI(username, _T("finder.co.il")) || 
		StrStrI(username, _T("joop.Co.il")) || 
		StrStrI(username, _T("Www.NFOil.com")) || 
		StrStrI(username, _T("TLN eMule")) || 
		StrStrI(username, _T("LHeMule")) || 
		StrStrI(username, _T("VMULE 2007")) || 
		StrStrI(username, _T("TLNGuest")) || 
		StrStrI(username, _T("Div eMule 2007")) || 
		StrStrI(username, _T("eMulePro.de.vu")) || 
		StrStrI(username, _T("emuIe-co.net")) || 
		StrStrI(username, _T("AE CoM UseR")) || 
		StrStrI(username, _T("BTFaw.Com")) || 
		StrStrI(username, _T("warezfaw")) || 
		StrStrI(username, _T("lh.2y.net")) || 
//		StrStrI(username, _T("viper-istraeL.Org")) || 
		StrStrI(username, _T("[Pwr Mule]Usuario")) || 
		StrStrI(username, _T("Www.D-iL.Net")) || 
		StrStrI(username, _T("www.aideadsl.com")) || 
		StrStrI(username, _T("tangot.com")) || 
		StrStrI(username, _T("r3wlx.com")) || 
		StrStrI(username, _T("http://yo.com")) || 
		StrStrI(username, _T("Angel eMule")) || 
		StrStrI(username, _T("AngelMule")) || 
	//MyTh NOT to ban!
/*	//they are some release groups, although some of them use bad mods, but rest of them is good one.
		_tcsstr(username, _T("Ultimativ")) || 
		StrStrI(username, _T("gps2c.6x.to")) || 
		StrStrI(username, _T("maultier-power")) || 
		_tcsstr(username, _T("RSVCD-Forum")) || 
		StrStrI(username, _T("rsvcd-crew")) || 
		StrStrI(username, _T("Ulti-Board")) || 
		_tcsstr(username, _T("R-Mod")) || 
		StrStrI(username, _T("gps2crew")) || 
*/
//		StrStrI(username, _T("www.eChanblardNext.org")) || 
//		StrStrI(username, _T("www.e-sipa.de")) || 
		StrStrI(username, _T("[TEC]")) || //fincan
		StrStrI(username, _T("e-Sipa")) || 
		StrStrI(username, _T("emuleech")) || 
		StrStrI(username, _T("mkp2p")) || 
		_tcsstr(username, _T("[ CHN]")) || //a space after bracket
		StrStrI(username, _T("PlayMule")) || 
		StrStrI(username, _T("eDonkey2008")) || 
		StrStrI(username, _T("Torenkey")) || 
//		StrStrI(username, _T("sdjtuning")) || 
		StrStrI(username, _T("RAPCOM")) || 
		_tcsstr(username, _T("ZZULtimativ-R")) || 
		_tcsstr(username, _T("ZZ-R ")) || 
		StrStrI(username, _T("OFF +")) || 
		StrStrI(username, _T("OFF+")) || 
		StrStrI(username, _T("Ultim@tiv")) || 
		StrStrI(username, _T("[CHN][VeryCD][Your")) || 
		_tcsstr(username, _T("eMuleUniATeam")) || 
		StrStrI(username, _T("mods.sub.cc")) || 
		_tcsstr(username, _T("ExtrEMule")) || 
		_tcsstr(username, _T("Titandonkey")) || 
		_tcsstr(username, _T("xtmhtl [ePlus]")) || //same name, same userhash
		_tcsstr(username, _T("eMule Accelerator")) || 
	//2010/4/4
		StrStrI(username, _T("eMule Pro Ultra")) || 
		StrStrI(username, _T("[CHN][VeryCD][username]")) || //[CHN][VeryCD][username] eMule v0.48a [xl build58]
	//2010/5/29
		StrStrI(username, _T("Fireb@ll")) || 
	//2010/6/6
		StrStrI(username, _T("monster-mod.com")) || 
		StrStrI(username, _T("Reptil-Crew-3")) || //Reptil mod
		StrStrI(username, _T("!Lou-Nissart!")) || //no src only BIN (kick from upload)
	//all sites below are phishing sites
		StrStrI(username, _T("www.extremule.com")) || 
		StrStrI(username, _T("www.emuleproject.com")) || 
		StrStrI(username, _T("bigbang-emule.de.vu")) || 
		StrStrI(username, _T("emulenet.de.vu")) || 
		_tcsstr(username, _T("http://emule.net")) || 
		StrStrI(username, _T("http://emulo.net")) || 
		StrStrI(username, _T("http://projekt.org")) || 
		StrStrI(username, _T("CryptMule.de.vu")) || 
		StrStrI(username, _T("titanload.to")) || 
		StrStrI(username, _T("http://emule-projekt.net")) || 
		StrStrI(username, _T("emuleitalianogratis.com")) || 
		StrStrI(username, _T("http://www.official-emule.com")) || 
		StrStrI(username, _T("emulepro.6x.to")) || 
//		StrStrI(username, _T("power-portal")) || //MyTh NOT to ban!
		StrStrI(username, _T("e-mule.nu")) || 
		StrStrI(username, _T("emulesoftware.com")) || 
		StrStrI(username, _T("emuleitaliano.com")) || 
		StrStrI(username, _T("scaricareemule.com")) || 
		StrStrI(username, _T("emule--it.com")) || 
		StrStrI(username, _T("italian.eazel.com")) || 
		StrStrI(username, _T("speed-downloading.com")) || 
		StrStrI(username, _T("nuovaversione.com")) || 
		StrStrI(username, _T("emuleplus.com")) || 
		StrStrI(username, _T("emuleultra.com")) || 
		StrStrI(username, _T("emule.org")) || 
		StrStrI(username, _T("[emule.de v")) || //default name: [emule.de v ##]
		StrStrI(username, _T("emule.fr")) || 
		StrStrI(username, _T("emule.ru")) || 
		StrStrI(username, _T("emule.com")) || 
		StrStrI(username, _T("emule-mods.biz")) || 
		StrStrI(username, _T("emule-projet")) || 
		StrStrI(username, _T("maomao.eu")) || 
		StrStrI(username, _T("donkey.com")) || 
		StrStrI(username, _T("super4.com")) || 
		StrStrI(username, _T("emule.cc")) || 
		StrStrI(username, _T("emule.net")) || 
		StrStrI(username, _T("emulegratis.net")) || 
	//new lines 2009/11/8
		StrStrI(username, _T("emulespeedup.de.vu")) || 
		StrStrI(username, _T("superemule.6x.to")) || 
		StrStrI(username, _T("emulea.com")) || 
		StrStrI(username, _T("emule24horas.com")) || 
		StrStrI(username, _T("emule.es")) || 
		StrStrI(username, _T("emulext.net")) || 
		StrStrI(username, _T("netemule.com")) || 
		StrStrI(username, _T("gratis-emule.com")) || 
		StrStrI(username, _T("emuleproject.com")) || 
		StrStrI(username, _T("emuleplusplus.de")) || 
		StrStrI(username, _T("wikingergilde")) || 
		StrStrI(username, _T("emuleclassic.com")) || 
		StrStrI(username, _T("mega-emule.com")) || 
		StrStrI(username, _T("speedyp2p.com")) || 
		StrStrI(username, _T("anubisp2p.com")) || 
		StrStrI(username, _T("cruxp2p.com")) || 
		StrStrI(username, _T("downloademulegratis.com")) || 
		StrStrI(username, _T("emulegold.com")) || 
		StrStrI(username, _T("pro-sharing.com")) || 
		StrStrI(username, _T("turbomule ")) || 
		StrStrI(username, _T("devhancer.com")) || 
		StrStrI(username, _T("emulefileswap.com")) || 
		StrStrI(username, _T("p2psharing.biz")) || 
		StrStrI(username, _T("fastsearchbooster.biz")) || 
		StrStrI(username, _T("emule-features.6x.to")) || 
		StrStrI(username, _T("emule-pro.blogspot.com")) || 
		StrStrI(username, _T("emule-ng.com")) || 
		StrStrI(username, _T("version049c-official.com")) || 
		StrStrI(username, _T("emule.to")) || 
		StrStrI(username, _T("adunanza.italiazip.com")) || 
		StrStrI(username, _T("emulesoftware.com")) || 
		StrStrI(username, _T("phpnuke.org")) || 
	//new lines 2009/11/29
		StrStrI(username, _T("gratis.emule49-info.com")) || 
		StrStrI(username, _T("emuleds.com")) || 
		StrStrI(username, _T("scarica-emule-gratis.com")) || 
		StrStrI(username, _T("mp3edonkeysearch.com")) || 
		StrStrI(username, _T("mp3rocket.com")) || 
		StrStrI(username, _T("emule-rocket.com")) || 
		StrStrI(username, _T("MonkeyP2P")) || 
	//new lines 2010/01/17
		StrStrI(username, _T("http://alpha-gaming.net")) || 
	//new lines 2010/4/4
		StrStrI(username, _T("piolet.com")) || 
		StrStrI(username, _T("hermesp2p.com")) || 
		StrStrI(username, _T("shareghost.com")) || 
		StrStrI(username, _T("zultrax.com")) || 
		StrStrI(username, _T("getfasterp2p.com")) || 
		StrStrI(username, _T("pro-sharing.com")) || 
		StrStrI(username, _T("truxshare.com")) || 
		StrStrI(username, _T("meteorshare.com")) || 
		StrStrI(username, _T("manolito.com")) || 
		StrStrI(username, _T("blubster.com")) || 
		StrStrI(username, _T("fastsearchbooster.biz")) || 
		StrStrI(username, _T("e-mule-")) || //detect any mirror simil to "e-mule-it.com"
		StrStrI(username, _T("download-gratis-emule.com")) || 
		StrStrI(username, _T("emule-italy.it")) || 
		StrStrI(username, _T("e-mule.be")) || 
		StrStrI(username, _T("official-emule")) || 
		StrStrI(username, _T("emule-gratis.it")) || 
		StrStrI(username, _T("devhancer")) || 
	//2010/5/29
		StrStrI(username, _T("dbgo.com")) || 
		StrStrI(username, _T("net2search.com")) || 
	//2010/6/6
		StrStrI(username, _T("p2phood.com")) || 
		StrStrI(username, _T("intelpeers.com")) || 
//End
		StrStrI(username, _T("[LSD.19")) //Xman 21.06.2005 definitive not a good mod, with protocol bugs
	)
		return _T("Bad USERNAME");

//new ketamine
//	if (StrStrI(username, _T("[ePlus]")) != StrRStrI(username, NULL, _T("[ePlus]"))) //old version
	if (_tcslen(username) >= 14)
	{
		LPCTSTR tempstr = StrStr(username, _T("[ePlus]"));
		if (tempstr && _tcslen(tempstr) >= 7)
			if (StrStr(tempstr + 7, _T("[ePlus]")))
				return _T("new Ketamine");
	}

//SDC team start
#if defined(SPECIAL_DLP_VERSION)
	if (wcsstr(username, L"VgroupTeam") != nullptr || //Random ModString [doompower]
//		wcsstr(username, L"ED2000") != nullptr || //GPL-Breaker
		wcsstr(username, L"[CHN]X_jIQ") != nullptr || //P2PSearcher
		wcsstr(username, L"[CHN]sf") != nullptr || //P2PSearcher
		wcsstr(username, L"[CHN]__VRom") != nullptr || //P2PSearcher [dark]
		wcsstr(username, L".net «Xtreme") != nullptr || //eMule -LPE-, fake ModString
		wcsstr(username, L"[CHN]yourname") != nullptr || //Old Chinese leecher and default nickname in QQDownload client
		wcsstr(username, L"28881.com") != nullptr || //MTVP2P (2013) [雁蝎]
		wcsstr(username, L"[CHN]shaohan") != nullptr || //Xunlei offline download server and moblie app [Glasses 王子]
		wcsstr(username, L"HubbleKadTracker") != nullptr //GPL-Breaker [冰靈曦曉]
	) [[unlikely]]
		return L"<SDC> Bad UserName";

//Removed since 44005 update 3.
//The traditional Fake ModString Type 4 check is like a "whitelist" and it's unfriendly to new mod.
/*
#if defined(SPECIAL_DLP_ADVANCED)
	const CString strNickName(username);
	if (strNickName.ReverseFind(L'«') > 5 && strNickName.ReverseFind(L'»') + 1 == static_cast<const SSIZE_T>(wcslen(username)))
	{
		for (SSIZE_T Index{strNickName.ReverseFind(L'«') - 5};Index + 1 < strNickName.ReverseFind(L'«');++Index)
		{
		//Its NickName looks like a normal eMule Mod, but ramdom part is incorrect. For example, "NickName **** «ModString»" which string "****" is uppercase letter.
			if (username[Index] < 65U || username[Index] > 90U) //Non letter
				break;
			else if (Index + 2 == strNickName.ReverseFind(L'«') && username[strNickName.ReverseFind(L'«') - 1] == 32U && username[strNickName.ReverseFind(L'«') - 6] == 32U) [[unlikely]]
				return L"<SDC> Fake ModString T4";
		}
	}
#endif
*/
#endif
//SDC team end

	return NULL;
}

LPCTSTR __declspec(dllexport) DLPCheckUsername_Soft(LPCTSTR username)
{
	if (username == NULL)
		return NULL;

	if (
	//Xman 15.08.05
		StrStrI(username, _T(">>Power-Mod"))
	//Xman 1/2007
/*
		StrStrI(username, _T("AppleJuice [")) && StrStrI(username, _T("]")) || 
		StrStrI(username, _T("AppleJuice Mod [")) && StrStrI(username, _T("]")) || 
		StrStrI(username, _T("AppleJuice eMule [")) && StrStrI(username, _T("]")) //5/2007
*/
//zz_fly Start korea
		|| _tcsstr(username, _T("DONKEY2007")) //korea
		|| _tcsstr(username, _T("www.Freang.com"))
		|| _tcsstr(username, _T("www.pruna.com"))
		|| _tcsstr(username, _T("[KOREA]"))
		|| _tcsstr(username, _T("superemule"))
		|| _tcsstr(username, _T("PRUNA 2008"))
		|| _tcsstr(username, _T("MOYAM"))
		|| _tcsstr(username, _T("eDonkey2009"))
//zz_fly End
	)
		return _T("Bad USERNAME");

//bad mods, where every second sign is
//enough to check two places

	if (_tcslen(username) >= 4 && username[3] <= 0x1F && username[1] <= 0x1F)
		return _T("Community-Username"); //community (based on LSD or it's smasher)

	if (_tcslen(username) >= 4 && username[0] == _T('v') && StrStr(username, _T(":com ")))
		return _T("X-Treme");

//SDC team start
#if defined(SPECIAL_DLP_VERSION)
#if defined(SDC_VERYCD_TAG)
	if (StrStrIW(username, L"[VeryCD]") != nullptr && 
	//Below client will be handled by DLPCheckUsername_Hard function.
		wcsstr(username, L"a1[VeryCD]xthame") == nullptr && 
		(StrStrIW(username, L"[CHN][VeryCD]") == nullptr || (StrStrIW(username, L"[Your") == nullptr && StrStrIW(username, L"[username]") == nullptr)) && 
		wcsstr(username, L"[CHN][VeryCD]QQ") == nullptr
	) [[unlikely]]
		return L"<SDC> verycd-tag";
#endif
#endif
//SDC team end

	return NULL;
}

//SDC team start
#if defined(SPECIAL_DLP_VERSION)
LPCTSTR __declspec(dllexport) DLPCheckNameAndHashAndMod(const CString username, const CString & userhash, const CString & modversion)
#else //Official
LPCTSTR __declspec(dllexport) DLPCheckNameAndHashAndMod(CString username, CString & userhash, CString & modversion)
#endif
//SDC team end
{
	if (username.IsEmpty() || userhash.IsEmpty())
		return NULL;

//zz_fly Start
//Fake VeryCD
	if ((_tcsstr(modversion, _T("VeryCD 071107")) || _tcsstr(modversion, _T("VeryCD 080307")))
		&& _tcsstr(username, _T("[CHN][VeryCD]yourname")) //all fake VeryCD have a default username
	)
		return _T("Fake VeryCD");

//community userhash check
	static const TCHAR refuserhash0[] = _T("154CE646120E96CC798C439A20D26F8D"); // (windows ue)
	static const TCHAR refuserhash1[] = _T("455361F9D95C3CD7E6BF2192D1CB3D02"); // (windows ue)
	static const TCHAR refuserhash2[] = _T("C8B5F41441C615FBABAD9A7E55294D01");
	static const TCHAR refuserhash6[] = _T("A2221641460E961C8B7FF21A53FB6F6C"); //**Riso64Bit**
	static const TCHAR refuserhash7[] = _T("888F4742450EF75F9DD8B7E53FA06FF0"); //**Riso64Bit**
	static const TCHAR refuserhash8[] = _T("0B76CC42CB0E81B0DC6120D2BCB36FF9"); //**Riso64Bit**
	static const TCHAR refuserhash9[] = _T("EAA383FD9E0E68538C7AC8AD15526F7A"); //**Riso64Bit**
	static const TCHAR refuserhash10[] = _T("65C3B2E8940E582630A7F58AF9F26F9E"); //from TaiWan
	static const TCHAR refuserhash11[] = _T("9BA09B83DC0EE78BE20280C387936F00"); //from SS1900
	static const TCHAR refuserhash12[] = _T("C92859E4860EA0F15F7837750C886FB6"); //from SS1900
	static const TCHAR refuserhash13[] = _T("CB42F563EE0EA7907395420CAC146FF5"); //From "qobfxb" multi user [DargonD]

//SDC team start
#if defined(SPECIAL_DLP_VERSION)
	if (_wcsicmp(userhash, refuserhash0) == 0 || _wcsicmp(userhash, refuserhash1) == 0 || _wcsicmp(userhash, refuserhash2) == 0 || 
		_wcsicmp(userhash, refuserhash6) == 0 || _wcsicmp(userhash, refuserhash7) == 0 || _wcsicmp(userhash, refuserhash8) == 0 || 
		_wcsicmp(userhash, refuserhash9) == 0 || _wcsicmp(userhash, refuserhash10) == 0 || _wcsicmp(userhash, refuserhash11) == 0 || 
		_wcsicmp(userhash, refuserhash12) == 0 || 
	//The refuserhash13 with NickName "qobfxb" will be handled by DLPCheckUsername_Hard function.
		(_wcsicmp(userhash, refuserhash13) == 0 && wcsstr(username, L"qobfxb") == nullptr)
	) [[unlikely]]
#else //Official
	if (_tcsicmp(userhash, refuserhash0) == 0 || _tcsicmp(userhash, refuserhash1) == 0 || _tcsicmp(userhash, refuserhash2) == 0
		|| _tcsicmp(userhash, refuserhash6) == 0 || _tcsicmp(userhash, refuserhash7) == 0 || _tcsicmp(userhash, refuserhash8) == 0
		|| _tcsicmp(userhash, refuserhash9) == 0 || _tcsicmp(userhash, refuserhash10) == 0
		|| _tcsicmp(userhash, refuserhash11) == 0 || _tcsicmp(userhash, refuserhash12) == 0 || _tcsicmp(userhash, refuserhash13) == 0
	)
#endif
		return _T("Community Userhash");
//SDC team end

//corrupt userhash check
	static const TCHAR refuserhash3[] = _T("00000000000E00000000000000006F00");
	static const TCHAR refuserhash4[] = _T("FE000000000E00000000000000006F00");
	if (_tcsicmp(userhash, refuserhash3) == 0 || _tcsicmp(userhash, refuserhash4) == 0)
		return _T("Corrupt Userhash");

//Community Userhash check, thanks SquallATF.
	static const TCHAR refuserhash5[] = _T("DA1CEEE05B0E5319B3B48CAED24C6F4A");
//SDC team start
#if defined(SPECIAL_DLP_VERSION)
	if (_wcsicmp(userhash, refuserhash5) == 0 && wcsstr(username, L"QQDownload") == nullptr) [[unlikely]] //The refuserhash5 with NickName "QQDownload" will be handled by DLPCheckUsername_Hard function.
#else //Official
	if (_tcsicmp(userhash, refuserhash5) == 0)
#endif
		return _T("Bad Userhash");
//SDC team end
//zz_fly End

//Check for aedit
//remark: a unmodded emule can't send a space at last sign
//SDC team start
#if defined(SPECIAL_DLP_VERSION)
	if (modversion.IsEmpty() == true && username.Right(1) == L" ") [[unlikely]] //CStringT::Right returns substring. [aMule-dlp]
#else //Official
	if (modversion.IsEmpty() && username.Right(1) == 32)
#endif
//SDC team end
		return _T("AEdit");

//Check for Hex-Modstring
	if (IsTypicalHex(modversion))
		return _T("Hex-Modstring");

//community check
	if (username.GetLength() >= 7 && username.Right(1) == _T("]"))
	{
	/* no more needed
	//check for gamer
	//two checks should be enough.
		if (username.Right(6).Left(1) == userhash.Mid(5, 1) && username.Right(3).Left(1) == userhash.Mid(7, 1))
			return _T("old united");
	*/

	//check for special nickaddon
		int find = username.ReverseFind(_T('['));
		if (find >= 0)
		{
			CString addon = username.Mid(find + 1);
		//SDC team start
		#if defined(SPECIAL_DLP_VERSION)
			//Do nothing.
		#else //Official
			int endpos = addon.GetLength() - 1;
		#endif
		//SDC team end
			if (addon.GetLength() > 2)
			{
			//check for snake //12/2006
			/* no more needed, better detection inside Xtreme
				for (int i = 0;i < endpos;i++)
				{
					if (!(addon.GetAt(i) >= _T('0') && addon.GetAt(i) <= _T('9')))
						i = endpos + 1;
				}
				if (i == endpos)
					return _T("Snake");
			*/

			//Chek for Hex (e.g. X-Treme)
				if (IsTypicalHex(addon.Left(addon.GetLength() - 1)))
					return _T("Hex-Code-Addon");
			}
		//zz_fly :: start
			if (find == username.GetLength() - 6)
			{
				bool bFoundRandomPadding = false;
			//SDC team start
			#if defined(SPECIAL_DLP_VERSION)
				_TINT ch{0};
			#else //Official
				_TINT ch;
			#endif
			//SDC team end
				for (int i = 1;i < 5;i++)
				{
					ch = username.GetAt(find + i);
					if (_istpunct(ch) || /* _istspace(ch) || */ _istcntrl(ch))
					{
						bFoundRandomPadding = true;
						break;
					}
				}

				if (bFoundRandomPadding && !modversion.IsEmpty() && (username.Find(_T("http://emule-project.net [")) == 0) && (find == 25))
					return _T("TLH Community"); //username like "http://emule-project.net [random]"

				if (bFoundRandomPadding && modversion.IsEmpty() && (find == username.Find(_T('['))))
					return _T("GhostMod"); //username has a random padding [random], it should be a mod function, but there is no modstring

				if (bFoundRandomPadding && (username.Find(_T("Silver Surfer User")) == 0) && (modversion.Find(_T("Silver")) == -1))
					return _T("Fake Silver Surfer"); //**Riso64Bit** :: fake silver surfer
			}
		//zz_fly :: end
		}
	}

//thx cyrex
	if (modversion.GetLength() == 10 && username.GetLength() > 4 && StrStr(username.Right(4), _T("/]")) && StrStr(username, _T("[SE]")))
		return _T("Mystery ModString");

//Some Community UserHash check
//SDC team start
#if defined(SPECIAL_DLP_VERSION)
	static const wchar_t SDC_refuserhash_01[]{L"66B002DADE0E6DBEDF4FCCAA380E6FD4"}; //From multiple users [DargonD]
	static const wchar_t SDC_refuserhash_02[]{L"AAEE84C0C30E247CBB99B459255D6F99"}; //From NAS_01G multiple users [DargonD]
	static const wchar_t SDC_refuserhash_03[]{L"5E02F74DBA0E8A19DBF6733F0AE66F4A"}; //Community UserHash [FzH/DargonD]
	static const wchar_t SDC_refuserhash_04[]{L"B6491292AE0E07AC8C6045CAC2DD6F9F"}; //Community UserHash [FzH/DargonD]
	static const wchar_t SDC_refuserhash_05[]{L"596B305E050EA842CE38DF3811216F3F"}; //Community UserHash [FzH/DargonD]
	static const wchar_t SDC_refuserhash_06[]{L"B1798B2F620E0B676452C6E2EF706F13"}; //Invalid UserHash [DargonD]
	static const wchar_t SDC_refuserhash_07[]{L"C1533316C00E3E0D0218843A05E46FAC"}; //Invalid UserHash [DargonD]
	static const wchar_t SDC_refuserhash_08[]{L"FE10F3C0610E0A925B85204CE8456F42"}; //Invalid UserHash [DargonD]
	static const wchar_t SDC_refuserhash_09[]{L"C9E61DEEF30E0360E2741C9CF1396F94"}; //Invalid UserHash [DargonD]
	static const wchar_t SDC_refuserhash_10[]{L"559ACC89D80E90C50A7A0CD3224F6F57"}; //Invalid UserHash [DargonD]
	static const wchar_t SDC_refuserhash_11[]{L"6AE1D2DF4B0E8707B6F6BC29E8746F0F"}; //Invalid UserHash [DargonD]
	static const wchar_t SDC_refuserhash_12[]{L"8A537F20B80EF9AF02E59E6C087C6F6B"}; //Invalid UserHash [DargonD]
	static const wchar_t SDC_refuserhash_13[]{L"3F44A7996F0E17D1F4B319EB58B26F64"}; //Invalid UserHash [DargonD]
	static const wchar_t SDC_refuserhash_14[]{L"D0D897BD360EEFF329903E04990B6F86"}; //Xunlei
	static const wchar_t SDC_refuserhash_15[]{L"36725093E00E9350F7680C871E946FD1"}; //Tencent offline download server UserHash [DargonD]
	static const wchar_t SDC_refuserhash_16[]{L"769D36987E0E313A1501967D0F146F7A"}; //Xunlei offline download server and moblie app [pandaleo]
	if (_wcsicmp(userhash, SDC_refuserhash_01) == 0 || _wcsicmp(userhash, SDC_refuserhash_02) == 0 || _wcsicmp(userhash, SDC_refuserhash_03) == 0 || 
		_wcsicmp(userhash, SDC_refuserhash_04) == 0 || _wcsicmp(userhash, SDC_refuserhash_05) == 0 || _wcsicmp(userhash, SDC_refuserhash_06) == 0 || 
		_wcsicmp(userhash, SDC_refuserhash_07) == 0 || _wcsicmp(userhash, SDC_refuserhash_08) == 0 || _wcsicmp(userhash, SDC_refuserhash_09) == 0 || 
		_wcsicmp(userhash, SDC_refuserhash_10) == 0 || _wcsicmp(userhash, SDC_refuserhash_11) == 0 || _wcsicmp(userhash, SDC_refuserhash_12) == 0 || 
		_wcsicmp(userhash, SDC_refuserhash_13) == 0 || 
		(_wcsicmp(userhash, SDC_refuserhash_14) == 0 && wcsstr(modversion, L"xl build") == nullptr) || //The SDC_refuserhash_14 with ModString "xl build" will be handled by DLPCheckModstring_Hard function.
		(_wcsicmp(userhash, SDC_refuserhash_15) == 0 && wcsstr(username, L"[CHN][VeryCD]QQ") == nullptr) || //The SDC_refuserhash_15 with NickName "[CHN][VeryCD]QQ" will be handled by DLPCheckUsername_Hard function.
		(_wcsicmp(userhash, SDC_refuserhash_16) == 0 && wcsstr(username, L"[CHN]shaohan") == nullptr) //The SDC_refuserhash_16 with NickName "[CHN]shaohan" will be handled by DLPCheckUsername_Hard function.
	) [[unlikely]]
		return L"<SDC> Community UserHash";

//Removed since 44005 update 3.
//The traditional Ghost Mod check is like a "whitelist" and it's unfriendly to new mod.
/*
#if defined(SPECIAL_DLP_ADVANCED)
	std::size_t ClientData[]{static_cast<const std::size_t>(modversion.GetLength()), static_cast<const std::size_t>(username.GetLength()), 0, 0};
	if (username.ReverseFind(91U) > 0)
		ClientData[2U] = static_cast<const std::size_t>(username.ReverseFind(91U));
	if (StrStrIW(username, L"speedyp2p.com") == nullptr && ClientData[0] == 0 && (wcsstr(username, L"«") != nullptr || wcsstr(username, L"»") != nullptr)) [[unlikely]] //Its NickName looks like a normal eMule Mod, but without ModString.
		return L"<SDC> Ghost Mod";
#endif
*/
#endif
//SDC team end

	if (modversion.IsEmpty())
		return NULL;

#define NUMBERSOFSTRING 9
	static const CString testModString[] = {_T("Xtreme"), _T("ScarAngel"), _T("Mephisto"), _T("MorphXT"), _T("EastShare"), _T("StulleMule"), /* _T("Magic Angel"), */ _T("DreaMule"), _T("X-Mod"), _T("RaJiL")};
	static const float testMinVer[] = {4.4f, 2.5f, 1.5f, 10.0f, 13.0f, 6.0f, /* 3.0f, */ 3.0f, 0.0f, 2.2f};
	for (int i = 0;i < NUMBERSOFSTRING;i++)
	{
		bool tag1 = (username.Find(_T('«') + testModString[i]) != -1);
		if (modversion.Find(testModString[i]) != -1)
		{
			float version = (float)_tstof(modversion.Right(4));
			if (!tag1 && ((testMinVer[i] == 0.0f) || (version == 9.7f) || (version >= testMinVer[i])))
				return _T("ModString Thief");
		}
		else if (tag1)
		{
			return _T("ModString Thief");
		}
	}

//doubled «...» in the username, like "username «Xtreme #.#» «abcd»"
	int posr1 = username.Find(_T('»'));
	int posr2 = username.ReverseFind(_T('»'));
	if ((posr1 > 5) && (posr2 - posr1 > 5) && ((username.GetAt(posr1 - 5) == _T('«')) || (username.GetAt(posr2 - 5) == _T('«'))))
		return _T("Bad Username Paddings");
//zz_fly :: end

//SDC team start
#if defined(SPECIAL_DLP_VERSION)
#if defined(SPECIAL_DLP_ADVANCED)
//Removed since 44005 update 3.
//The traditional Fake ModString Type 1 check is like a "whitelist" and it's unfriendly to new mod.
/*
	ClientData[3U] = modversion.GetAt(0);
	if (ClientData[0] >= 10U && ClientData[0] <= 15U && ClientData[1U] >= 11U || ClientData[1U] <= 35U && ClientData[2U] >= 1U && 
		wcsstr(modversion, L"AnalyZZUL") == nullptr && //AnalyZZUL Mod
		wcsstr(modversion, L"AcKroNiC") == nullptr && //AcKroNiC Mod
	//Normal ModString is usually "ModString *.*(Version)", but its NickName without "«ModString»".
		(ClientData[3U] >= 65U && ClientData[3U] <= 90U && 
		modversion.GetAt(static_cast<const int>(ClientData[0]) - 4U) == 32U && modversion.GetAt(static_cast<const int>(ClientData[0]) - 2U) == 46U && 
		modversion.GetAt(static_cast<const int>(ClientData[0]) - 1U) > 47U && modversion.GetAt(static_cast<const int>(ClientData[0]) - 1U) < 58U && 
		modversion.GetAt(static_cast<const int>(ClientData[0]) - 3U) > 47U && modversion.GetAt(static_cast<const int>(ClientData[0]) - 3U) < 58U && 
		(username.GetAt(0) > 64U && username.GetAt(0) < 91U || username.GetAt(0) > 96U && username.GetAt(0) < 123U) && 
		username.GetAt(static_cast<const int>(ClientData[1U]) - 1U) == 93U && username.GetAt(static_cast<const int>(ClientData[1U]) - 6U) == 91U && username.GetAt(static_cast<const int>(ClientData[1U]) - 7U) == 32U)
	) [[unlikely]]
		return L"<SDC> Fake ModString T1";
*/

//Removed since 44005 update 3.
//The traditional Fake ModString Type 3 check is like a "whitelist" and it's unfriendly to new mod.
/*
	std::size_t Index{0};
	for (Index = 0;Index < NUMBERSOFSTRING;++Index)
	{
		if (wcsstr(modversion, testModString[Index]) != nullptr && (wcsstr(username, L"«") == nullptr || wcsstr(username, L"»") == nullptr)) [[unlikely]]
			return L"<SDC> Fake ModString T3";
	}
*/

//Removed since 44005 update 3.
//The traditional Fake ModString Type 2 check is like a "whitelist" and it's unfriendly to new mod.
/*
	std::size_t EACheck[]{static_cast<const std::size_t>(username.GetLength()), username.GetAt(0), 0, 0, 0, 0, 0, 0}; //Length, First, Second, Last, FirstEnd, SecondEnd, LastStart, Flag
	if (wcsstr(username, L"(") != nullptr && wcsstr(username, L")") != nullptr) //There must be "(" and ")"
		++EACheck[7U];
	if (wcsstr(username, L"[") != nullptr && wcsstr(username, L"]") != nullptr) //There must be "[" and "]"
		++EACheck[7U];
	if (wcsstr(username, L"{") != nullptr && wcsstr(username, L"}") != nullptr) //There must be "{" and "}"
		++EACheck[7U];
	if (EACheck[7U] == 2U && (EACheck[1U] == 40U || EACheck[1U] == 91U || EACheck[1U] == 123U) && EACheck[0] > 1U)
	{
		bool IsType[]{false, false, false};
		if (EACheck[1U] == 40U)
			EACheck[4U] = EACheck[1U] + 1U;
		else 
			EACheck[4U] = EACheck[1U] + 2U;
		EACheck[3U] = username.GetAt(static_cast<const int>(EACheck[0]) - 1U);
		EACheck[2U] = username.GetAt(username.Find(static_cast<const wchar_t>(EACheck[4U]) + 2U));
		if (EACheck[2U] == 40U)
			EACheck[5U] = EACheck[2U] + 1U;
		else 
			EACheck[5U] = EACheck[2U] + 2U;
		if (EACheck[3U] == 41U)
			EACheck[6U] = EACheck[3U] - 1U;
		else 
			EACheck[6U] = EACheck[3U] - 2U;
		if (EACheck[4U] != EACheck[3U] && (EACheck[3U] == 41U || EACheck[3U] == 93U || EACheck[3U] == 125U) && 
			username.Find(static_cast<const wchar_t>(EACheck[4U])) + 1 == username.Find(32U) && 
			username.ReverseFind(static_cast<const wchar_t>(EACheck[6U])) == username.ReverseFind(32U) + 1 && 
			username.Find(static_cast<const wchar_t>(EACheck[4U])) > 4 && username.Find(static_cast<const wchar_t>(EACheck[4U])) < 12 && 
			username.ReverseFind(static_cast<const wchar_t>(EACheck[6U])) + 13 > static_cast<const SSIZE_T>(EACheck[0]) && 
			username.ReverseFind(static_cast<const wchar_t>(EACheck[6U])) + 5 < static_cast<const SSIZE_T>(EACheck[0])
		)
			IsType[0] = true; //Like "(****) NickName [****]", "****" length is between 4 and 10.
		if (EACheck[1U] != EACheck[2U] && (EACheck[2U] == 40U || EACheck[2U] == 91U || EACheck[2U] == 123U) && 
			username.Find(static_cast<const wchar_t>(EACheck[4U])) + 1 == username.Find(32U) && 
			username.GetAt(username.Find(static_cast<const wchar_t>(EACheck[5U])) + 1U) == 32U && 
			username.Find(static_cast<const wchar_t>(EACheck[5U])) - username.Find(static_cast<const wchar_t>(EACheck[2U])) > 4 && 
			username.Find(static_cast<const wchar_t>(EACheck[5U])) - username.Find(static_cast<const wchar_t>(EACheck[2U])) < 12
		)
			IsType[1U] = true; //Like "(****) [****] NickName", "****" length is between 4 and 10.
		if (wcsstr(modversion, L"kMule") == nullptr && //kMule Mod
			wcsstr(modversion, L"MorphCA") == nullptr && //MorphCA Mod
			wcsstr(modversion, L"ZZUL-TRA") == nullptr && //ZZUL-TRA Mod
			wcsstr(modversion, L"Katana") == nullptr && //Katana Mod
			(IsType[0] == true || IsType[1U] == true)
		)
		{
			for (Index = 1U;Index < static_cast<const std::size_t>(username.Find(static_cast<const wchar_t>(EACheck[4U])));++Index)
			{
				if ((username.GetAt(static_cast<const int>(Index)) >= 65U && username.GetAt(static_cast<const int>(Index)) <= 90U) || 
					(username.GetAt(static_cast<const int>(Index)) >= 97U && username.GetAt(static_cast<const int>(Index)) <= 122U)) //"****" must be a letter.
				{
					if (Index + 1U == static_cast<const std::size_t>(username.Find(static_cast<const wchar_t>(EACheck[4U]))))
						IsType[2U] = true;
				}
				else {
					break;
				}
			}

			if (IsType[0] == true && IsType[2U] == true)
			{
				for (Index = static_cast<const std::size_t>(username.ReverseFind(static_cast<const wchar_t>(EACheck[6U])) + 1U);Index + 1U < EACheck[0];++Index)
				{
					if ((username.GetAt(static_cast<const int>(Index)) >= 65U && username.GetAt(static_cast<const int>(Index)) <= 90U) || 
						(username.GetAt(static_cast<const int>(Index)) >= 97U && username.GetAt(static_cast<const int>(Index)) <= 122U)) //"****" must be a letter.
					{
						if (Index + 2U == EACheck[0]) [[unlikely]]
							return L"<SDC> Fake ModString T2";
					}
					else {
						break;
					}
				}
			}

			if (IsType[1U] == true && IsType[2U] == true)
			{
				for (Index = static_cast<const std::size_t>(username.Find(static_cast<const wchar_t>(EACheck[2U])) + 1U);Index < static_cast<const std::size_t>(username.Find(static_cast<const wchar_t>(EACheck[5U])));++Index)
				{
					if ((username.GetAt(static_cast<const int>(Index)) >= 65U && username.GetAt(static_cast<const int>(Index)) <= 90U) || 
						(username.GetAt(static_cast<const int>(Index)) >= 97U && username.GetAt(static_cast<const int>(Index)) <= 122U)) //"****" must be a letter.
					{
						if (Index + 1U == static_cast<const std::size_t>(username.Find(static_cast<const wchar_t>(EACheck[5U])))) [[unlikely]]
							return L"<SDC> Fake ModString T2";
					}
					else {
						break;
					}
				}
			}
		}
	}
*/

//Random ModString check
	if (wcsstr(username, L" http://emule-project.net ") != nullptr || 
		wcsstr(username, L" beba.eMuleFuture.de ") != nullptr
	) [[unlikely]]
	{
		static const std::wregex SDC_Pattern_RandomModString_Modversion(L"^[A-Z][a-z]{4,10} [1-9]\\.[0-9]$");
		static const std::wregex SDC_Pattern_RandomModString_Username(L"^(\\([A-Za-z]{4,10}\\)|\\{[A-Za-z]{4,10}\\}) .{19,24} \\[[A-Za-z]{4,10}\\]$"); //Middle part of Username is limited to possible length, which should be able to improve performance.
		if (
//			modversion.IsEmpty() == false && //Already be passed above.
			std::regex_match(modversion.GetString(), SDC_Pattern_RandomModString_Modversion) == true && 
			std::regex_match(username.GetString(), SDC_Pattern_RandomModString_Username) == true
		) [[unlikely]]
			return L"<SDC> Random ModString";
	}
#endif

#if (defined(SDC_ALL_VERYCD) || defined(SDC_VERYCD_TAG))
	if (wcsstr(modversion, L"VeryCD 090304") != nullptr && 
		wcsstr(username, L"[CHN]shaohan") == nullptr //It will be handled by DLPCheckUsername_Hard function.
	) [[unlikely]]
		return L"<SDC> all-verycd";
#elif defined(SDC_VERYCD_NICKNAME)
	if (wcsstr(modversion, L"VeryCD") != nullptr && 
	//Below client will be handled by DLPCheckModstring_Hard function.
		wcsstr(modversion, L" 080126") == nullptr && wcsstr(modversion, L" 080730") == nullptr && wcsstr(modversion, L" 080509") == nullptr && 
		wcsstr(modversion, L" 080606") == nullptr && wcsstr(modversion, L" 080624") == nullptr && wcsstr(modversion, L" 080630") == nullptr && 
	//Default NickName in newer VeryCD-EasyMule-Mod
		(wcsstr(username, L"easyMule.com") != nullptr || 
	//Default NickName in VeryCD-Mod and old VeryCD-EasyMule-Mod
		((wcsstr(username, L"[CHN]") != nullptr || wcsstr(username, L"[VeryCD]") != nullptr) && 
		(wcsstr(username, L"yourname") != nullptr || 
	//Added in 2009-07, GB2312 codepage.
		wcsstr(username, L"我爱电驴") != nullptr || 
		wcsstr(username, L"爱分享") != nullptr || 
		wcsstr(username, L"分享快乐") != nullptr || 
		wcsstr(username, L"上传Happy") != nullptr || 
		wcsstr(username, L"爱电驴爱生活") != nullptr || 
		wcsstr(username, L"dianlv") != nullptr || 
		wcsstr(username, L"自由电驴") != nullptr || 
	//Added in 2009-07, broken Big5 codepage version.
		wcsstr(username, L"扂乾萇聶") != nullptr || 
		wcsstr(username, L"乾煦砅") != nullptr || 
		wcsstr(username, L"煦砅辦氈") != nullptr || 
		wcsstr(username, L"奻換Happy") != nullptr || 
		wcsstr(username, L"乾萇聶乾汜魂") != nullptr || 
		wcsstr(username, L"赻蚕萇聶") != nullptr || 
	//Added in 2009-08, GB2312 codepage.
		wcsstr(username, L"感谢驴友") != nullptr || 
		wcsstr(username, L"感谢分享") != nullptr || 
		wcsstr(username, L"大家一起来加速") != nullptr || 
		wcsstr(username, L"分享越多 下载越快") != nullptr || 
		wcsstr(username, L"挂机王") != nullptr || 
		wcsstr(username, L"通宵上传") != nullptr || 
		wcsstr(username, L"分享互联网") != nullptr || 
	//Added in 2009-08, broken Big5 codepage version.
		wcsstr(username, L"覜郅聶衭") != nullptr || 
		wcsstr(username, L"覜郅煦砅") != nullptr || 
		wcsstr(username, L"湮模珨懂樓厒") != nullptr || 
		wcsstr(username, L"煦砅埣嗣 狟婥埣辦") != nullptr || 
		wcsstr(username, L"境儂卼") != nullptr || 
		wcsstr(username, L"籵秖奻換") != nullptr || 
		wcsstr(username, L"煦砅誑薊厙") != nullptr || 
	//Added in 2013-01.
		wcsstr(username, L"[easyMule]") != nullptr)))
	) [[unlikely]]
		return L"<SDC> verycd-nickname";
#endif
#endif
//SDC team end

	return NULL;
}

LPCTSTR __declspec(dllexport) DLPCheckMessageSpam(LPCTSTR messagetext)
{
	if (messagetext == NULL)
		return NULL;

	if (_tcsstr(messagetext, _T("ZamBoR")) || 
		_tcsstr(messagetext, _T("DI-Emule")) || 
		_tcsstr(messagetext, _T("Join the L33cher")) || 
		_tcsstr(messagetext, _T("eMule FX")) || 
		_tcsstr(messagetext, _T("---> ed2k://|file|Ketamine")) || 
		_tcsstr(messagetext, _T("robot from RIAA, you can't fight")) || 
		_tcsstr(messagetext, _T("agent from PeerFactor, she advises you to stop")) || 
		_tcsstr(messagetext, _T("bot from MPAA, you can't do anything against her")) || 
		_tcsstr(messagetext, _T("[Sangue-Suga]")) || //3/2007
		_tcsstr(messagetext, _T("[te@m projekt")) || //5/2007
		_tcsstr(messagetext, _T("eMule PRO Ultra")) || //8/2007 //include ultra 1 2 3
		_tcsstr(messagetext, _T("HyperMule")) || //8/2007
		_tcsstr(messagetext, _T("FXeMule")) || 
		_tcsstr(messagetext, _T("angelmule.com")) || //**Riso64Bit**
		_tcsstr(messagetext, _T("RocketMule")) //**Riso64Bit**
	)
		return _T("Spam-Message");

	if (CString(messagetext).Trim().IsEmpty())
		return _T("Spam-Message");

	return NULL;
}

//SDC team start
#if defined(SPECIAL_DLP_VERSION)
LPCTSTR __declspec(dllexport) DLPCheckHelloTag(const UINT tagnumber)
#else //Official
LPCTSTR __declspec(dllexport) DLPCheckHelloTag(UINT tagnumber)
#endif
//SDC team end
{
	LPCTSTR strSnafuTag = NULL;
	switch (tagnumber)
	{
		case CT_UNKNOWNx12:
		case CT_UNKNOWNx13:
		case CT_UNKNOWNx14:
		case CT_UNKNOWNx16:
		case CT_UNKNOWNx17:
		case CT_UNKNOWNxE6:			strSnafuTag = apszSnafuTag[0];break; //buffer = _T("DodgeBoards");break;
		case CT_UNKNOWNx15:			strSnafuTag = apszSnafuTag[1];break; //buffer = _T("DodgeBoards & DarkMule |eVorte|X|");break;
		case CT_UNKNOWNx22:			strSnafuTag = apszSnafuTag[2];break; //buffer = _T("DarkMule v6 |eVorte|X|");break;
		case CT_UNKNOWNx5D:
		case CT_UNKNOWNx6B:
		case CT_UNKNOWNx6C:			strSnafuTag = apszSnafuTag[17];break;
		case CT_UNKNOWNx74:
		case CT_UNKNOWNx87:			strSnafuTag = apszSnafuTag[17];break;
		case CT_UNKNOWNxF0:
		case CT_UNKNOWNxF4:			strSnafuTag = apszSnafuTag[17];break;
//		case CT_UNKNOWNx69:			strSnafuTag = apszSnafuTag[3];break; //buffer = _T("eMuleReactor");break;
		case CT_UNKNOWNx79:			strSnafuTag = apszSnafuTag[4];break; //buffer = _T("Bionic");break;
		case CT_UNKNOWNx83:			strSnafuTag = apszSnafuTag[15];break; //buffer = _T("Fusspi");break;
		case CT_UNKNOWNx76:
		case CT_UNKNOWNxCD:			strSnafuTag = apszSnafuTag[16];break; //buffer = _T("www.donkey2002.to");break;
		case CT_UNKNOWNx88:			strSnafuTag = apszSnafuTag[5];break; //[LSD7c]
		case CT_UNKNOWNx8C:			strSnafuTag = apszSnafuTag[5];break; //buffer = _T("[LSD7c]");break;
		case CT_UNKNOWNx8D:			strSnafuTag = apszSnafuTag[6];break; //buffer = _T("[0x8d] unknown Leecher - (client version:60)");break;
		case CT_UNKNOWNx99:			strSnafuTag = apszSnafuTag[7];break; //buffer = _T("[RAMMSTEIN]");break; //STRIKE BACK
		case CT_UNKNOWNx97:
		case CT_UNKNOWNx98:
		case CT_UNKNOWNx9C:
		case CT_UNKNOWNxDA:			strSnafuTag = apszSnafuTag[3];break; //buffer = _T("eMuleReactor");break;
		case CT_UNKNOWNxC8:			//Xman x4
		case CT_UNKNOWNxCE:			//Xman 20.08.05
		case CT_UNKNOWNxCF:			//Xman 20.08.05
		case CT_UNKNOWNx94:			//Xman 20.08.05
		case CT_UNKNOWNxC4:			strSnafuTag = apszSnafuTag[8];break; //buffer = _T("[MD5 Community]");break; //USED BY NEW BIONIC => 0x12 Sender
		case CT_UNKNOWNxEC:			strSnafuTag = apszSnafuTag[18];break; //Xman x4 Speedmule
//		case CT_FRIENDSHARING:		break; //STRIKE BACK
		case CT_DARK:				//STRIKE BACK
		case CT_UNKNOWNx7A:
		case CT_UNKNOWNxCA:			strSnafuTag = apszSnafuTag[9];break; //buffer = _T("new DarkMule");
		case CT_UNKNOWNx4D:			strSnafuTag = apszSnafuTag[19];break; //pimp my mule misuse an official tag in hello
		case CT_UNKNOWNxD2:			strSnafuTag = apszSnafuTag[20];break; //SquallATF
//		case CT_UNKNOWNx85:			strSnafuTag = apszSnafuTag[21];break; //zz_fly
	}

	return strSnafuTag;
}

//SDC team start
#if defined(SPECIAL_DLP_VERSION)
LPCTSTR __declspec(dllexport) DLPCheckInfoTag(const UINT tagnumber)
#else //Official
LPCTSTR __declspec(dllexport) DLPCheckInfoTag(UINT tagnumber)
#endif
//SDC team end
{
	LPCTSTR strSnafuTag = NULL;
	switch (tagnumber)
	{
		case ET_MOD_UNKNOWNx12:
		case ET_MOD_UNKNOWNx13:
		case ET_MOD_UNKNOWNx14:
		case ET_MOD_UNKNOWNx17:		strSnafuTag = apszSnafuTag[0];break; //("[DodgeBoards]")
		case ET_MOD_UNKNOWNx2F:		strSnafuTag = apszSnafuTag[10];break; //buffer = _T("[OMEGA v.07 Heiko]");break;
		case ET_MOD_UNKNOWNx36:
		case ET_MOD_UNKNOWNx5B:
		case ET_MOD_UNKNOWNxA6:		strSnafuTag = apszSnafuTag[11];break; //buffer = _T("eMule v0.26 Leecher");break;
		case ET_MOD_UNKNOWNx60:		strSnafuTag = apszSnafuTag[12];break; //buffer = _T("[Hunter]");break; //STRIKE BACK
		case ET_MOD_UNKNOWNx76:		strSnafuTag = apszSnafuTag[0];break; //buffer = _T("[DodgeBoards]");break;
		case ET_MOD_UNKNOWNx50:
		case ET_MOD_UNKNOWNxB1:
		case ET_MOD_UNKNOWNxB4:
		case ET_MOD_UNKNOWNxC8:
		case ET_MOD_UNKNOWNxC9:		strSnafuTag = apszSnafuTag[13];break; //buffer = _T("[Bionic 0.20 Beta]");break;
		case ET_MOD_UNKNOWNxDA:		strSnafuTag = apszSnafuTag[14];break; //buffer = _T("[Rumata (rus)(Plus v1f)]");break;
	}

	return strSnafuTag;
}
