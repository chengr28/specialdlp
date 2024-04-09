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
//No dependency

//Internal dependency
#include "specialdlpTester.h"

//Namespace definition
//No definition

//Function: Main
int main(
//	const int argc, 
//	const char * const argv[]
	void
)
{
//Set locale environment.
	std::setlocale(LC_ALL, SDC_LOCALE_SETTING);

//Load library file.
	const auto LibraryInstance = LoadLibraryExA(SDC_LIBRARY_NAME, nullptr, LOAD_LIBRARY_SEARCH_APPLICATION_DIR);
	if (LibraryInstance == nullptr)
	{
		std::cout << "Error: Load library file failed, error code is " << GetLastError() << "." << std::endl;
		PressReturnToEnd();

		return EXIT_FAILURE;
	}

//Load function from library.
	const auto GetDLPVersion = reinterpret_cast<GETDLPVERSION>(GetProcAddress(LibraryInstance, "GetDLPVersion"));
	const auto DLPCheckModstring_Hard = reinterpret_cast<DLPCHECKMODSTRING_HARD>(GetProcAddress(LibraryInstance, "DLPCheckModstring_Hard"));
	const auto DLPCheckModstring_Soft = reinterpret_cast<DLPCHECKMODSTRING_SOFT>(GetProcAddress(LibraryInstance, "DLPCheckModstring_Soft"));
	const auto DLPCheckUsername_Hard = reinterpret_cast<DLPCHECKUSERNAME_HARD>(GetProcAddress(LibraryInstance, "DLPCheckUsername_Hard"));
	const auto DLPCheckUsername_Soft = reinterpret_cast<DLPCHECKUSERNAME_SOFT>(GetProcAddress(LibraryInstance, "DLPCheckUsername_Soft"));
	const auto DLPCheckNameAndHashAndMod = reinterpret_cast<DLPCHECKNAMEANDHASHANDMOD>(GetProcAddress(LibraryInstance, "DLPCheckNameAndHashAndMod"));
	const auto DLPCheckMessageSpam = reinterpret_cast<DLPCHECKMESSAGESPAM>(GetProcAddress(LibraryInstance, "DLPCheckMessageSpam"));
//	const auto DLPCheckUserhash = reinterpret_cast<DLPCHECKUSERHASH>(GetProcAddress(LibraryInstance, "DLPCheckUserhash")); //No more AJ check.
	const auto DLPCheckHelloTag = reinterpret_cast<DLPCHECKHELLOTAG>(GetProcAddress(LibraryInstance, "DLPCheckHelloTag"));
	const auto DLPCheckInfoTag = reinterpret_cast<DLPCHECKINFOTAG>(GetProcAddress(LibraryInstance, "DLPCheckInfoTag"));
	if (GetDLPVersion == nullptr || DLPCheckModstring_Hard == nullptr || DLPCheckModstring_Soft == nullptr || 
		DLPCheckUsername_Hard == nullptr || DLPCheckUsername_Soft == nullptr || DLPCheckNameAndHashAndMod == nullptr || 
		DLPCheckMessageSpam == nullptr || /* DLPCheckUserhash == nullptr || */ DLPCheckHelloTag == nullptr || 
		DLPCheckInfoTag == nullptr
	)
	{
		std::cout << "Error: Load function from library failed, error code is " << GetLastError() << "." << std::endl;
		FreeLibrary(LibraryInstance);
		PressReturnToEnd();

		return EXIT_FAILURE;
	}

//Print library location.
	auto LocationBuffer(std::make_unique<wchar_t[]>(SDC_PATH_MAXSIZE + sizeof(std::uint8_t)));
	if (GetModuleFileNameW(LibraryInstance, LocationBuffer.get(), SDC_PATH_MAXSIZE) <= 0 || 
		wcsnlen(LocationBuffer.get(), SDC_PATH_MAXSIZE) <= 0)
	{
		std::cout << "Error: Load module name from library failed, error code is " << GetLastError() << "." << std::endl;
		FreeLibrary(LibraryInstance);
		PressReturnToEnd();

		return EXIT_FAILURE;
	}
	else {
		std::wcout << L"File location: \"" << LocationBuffer.get() << L"\"" << std::endl;
		std::cout << std::endl;
		LocationBuffer.reset();
	}

//Print library version.
	std::cout << "Dynamic Anti-Leecher Protection v" << GetDLPVersion() << " loaded." << std::endl;
	std::cout << std::endl;

//Prepare parameter.
	std::wstring StringClientVersion(L"");
	std::wstring StringModVersion(L"");
	std::wstring StringUserName(L"");
	std::wstring StringUserHash(L"");
	std::wstring StringMessageText(L"");
	unsigned int TagNumber = 0;
	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Example: " << std::endl;
	std::cout << "Client version = \"eMule v0.70a\"" << std::endl;
	std::cout << "Mod version = \"Xtreme 8.1\"" << std::endl;
	std::cout << "User name = \"Hello World!\"" << std::endl;
	std::cout << "User hash = \"0123456789ABCDE0123456789ABCDE01\"" << std::endl;
	std::cout << "Message text = \"Hello World!\"" << std::endl;
	std::cout << "Tag number = \"0\"" << std::endl;
	std::cout << std::endl;
	std::cout << "Client version: ";
	std::getline(std::wcin, StringClientVersion);
	std::cout << std::endl;
	std::cout << "Mod version: ";
	std::getline(std::wcin, StringModVersion);
	std::cout << std::endl;
	std::cout << "User name: ";
	std::getline(std::wcin, StringUserName);
	std::cout << std::endl;
	std::cout << "User hash: ";
	std::getline(std::wcin, StringUserHash);
	std::cout << std::endl;
	std::cout << "Message text: ";
	std::getline(std::wcin, StringMessageText);
	std::cout << std::endl;
	std::cout << "Tag number: ";
	std::wcin >> std::noskipws >> TagNumber;
	std::cout << std::endl;

//Print parameter.
	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Client version = \"";
	std::wcout << StringClientVersion;
	std::cout << "\"" << std::endl;
	std::cout << "Mod version = \"";
	std::wcout << StringModVersion;
	std::cout << "\"" << std::endl;
	std::cout << "User name = \"";
	std::wcout << StringUserName;
	std::cout << "\"" << std::endl;
	std::cout << "User hash = \"";
	std::wcout << StringUserHash;
	std::cout << "\"" << std::endl;
	std::cout << "Message text = \"";
	std::wcout << StringMessageText;
	std::cout << "\"" << std::endl;
	std::cout << "Tag number = \"";
	std::cout << std::hex << "0x" << TagNumber;
	std::cout << "\"" << std::endl;
	std::cout << std::endl;

//Check parameter.
	LPCWSTR PointClientVersion = nullptr;
	LPCWSTR PointModVersion = nullptr;
	LPCWSTR PointUserName = nullptr;
	LPCWSTR PointUserHash = nullptr;
	LPCWSTR PointMessageText = nullptr;
	if (StringClientVersion.empty() == false)
		PointClientVersion = StringClientVersion.c_str();
	if (StringModVersion.empty() == false)
		PointModVersion = StringModVersion.c_str();
	if (StringUserName.empty() == false)
		PointUserName = StringUserName.c_str();
	if (StringUserHash.empty() == false)
		PointUserHash = StringUserHash.c_str();
	if (StringMessageText.empty() == false)
		PointMessageText = StringMessageText.c_str();

//Run the test, the order is from eMule Xtreme 8.1 sources.
	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	LPCWSTR Reason = nullptr;
	Reason = DLPCheckHelloTag(TagNumber);
	if (Reason != nullptr)
	{
		std::cout << "<Hard-Ban> DLPCheckHelloTag: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}
	Reason = DLPCheckInfoTag(TagNumber);
	if (Reason != nullptr)
	{
		std::cout << "<Hard-Ban> DLPCheckInfoTag: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}
	Reason = DLPCheckModstring_Hard(PointModVersion, PointClientVersion);
	if (Reason != nullptr)
	{
		std::cout << "<Hard-Ban> DLPCheckModstring_Hard: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}
	Reason = DLPCheckModstring_Soft(PointModVersion, PointClientVersion);
	if (Reason != nullptr)
	{
		std::cout << "<Soft-Ban> DLPCheckModstring_Soft: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}
/* No more AJ check.
	Reason = DLPCheckUserhash(nullptr);
	if (Reason != nullptr)
	{
		std::cout << "<AJ-Ban> DLPCheckUserhash: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}
*/
	Reason = DLPCheckNameAndHashAndMod(PointUserName, PointUserHash, PointModVersion);
	if (Reason != nullptr)
	{
		std::cout << "<Soft-Ban> DLPCheckNameAndHashAndMod: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}
	Reason = DLPCheckUsername_Soft(PointUserName);
	if (Reason != nullptr)
	{
		std::cout << "<Soft-Ban> DLPCheckUsername_Soft: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}
	Reason = DLPCheckUsername_Hard(PointUserName);
	if (Reason != nullptr)
	{
		std::cout << "<Hard-Ban> DLPCheckUsername_Hard: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}
	Reason = DLPCheckMessageSpam(PointMessageText);
	if (Reason != nullptr)
	{
		std::cout << "<Spam-Ban> DLPCheckMessageSpam: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}

//No any leechers reported.
	std::cout << "No reported." << std::endl;

//Jump here to end.
JumpToEnd:

//Free library file and pause to show the result.
	FreeLibrary(LibraryInstance);
	PressReturnToEnd();

	return EXIT_SUCCESS;
}

//Function: Press "Return" to end.
static void PressReturnToEnd(
	void
)
{
	std::cout << std::endl << "Press \"Return\" to end." << std::endl;
	std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	std::cin.get();

	return;
}
