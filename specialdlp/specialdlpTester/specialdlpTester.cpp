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


#include "specialdlpTester.h"

//Main function
int main(const int argc, const char * argv[])
{
//Environment setting
	setlocale(LC_ALL, ".UTF-8");

//Load library file.
#if (defined(WIN_X86) && !defined(WIN_X64))
	const auto LibraryInstance = LoadLibraryExW(L"antiLeech.dll", NULL, LOAD_LIBRARY_SEARCH_APPLICATION_DIR);
#elif defined(WIN_X64)
	const auto LibraryInstance = LoadLibraryExW(L"antiLeechx64.dll", NULL, LOAD_LIBRARY_SEARCH_APPLICATION_DIR);
#elif (defined(WIN_ARM32) && !defined(WIN_ARM64))
	const auto LibraryInstance = LoadLibraryExW(L"antiLeecharm.dll", NULL, LOAD_LIBRARY_SEARCH_APPLICATION_DIR);
#elif (defined(WIN_ARM64) && !defined(WIN_ARM64EC))
	const auto LibraryInstance = LoadLibraryExW(L"antiLeecharm64.dll", NULL, LOAD_LIBRARY_SEARCH_APPLICATION_DIR);
#elif defined(WIN_ARM64EC)
	const auto LibraryInstance = LoadLibraryExW(L"antiLeecharm64ec.dll", NULL, LOAD_LIBRARY_SEARCH_APPLICATION_DIR);
#else
	const auto LibraryInstance = LoadLibraryExW(L"antiLeech.dll", NULL, LOAD_LIBRARY_SEARCH_APPLICATION_DIR);
#endif
	if (LibraryInstance == NULL)
	{
		std::cout << "Error code: " << GetLastError() << std::endl;

		std::cout << std::endl;
		std::system("pause");
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
	const auto DLPCheckUserhash = reinterpret_cast<DLPCHECKUSERHASH>(GetProcAddress(LibraryInstance, "DLPCheckUserhash"));
	const auto DLPCheckHelloTag = reinterpret_cast<DLPCHECKHELLOTAG>(GetProcAddress(LibraryInstance, "DLPCheckHelloTag"));
	const auto DLPCheckInfoTag = reinterpret_cast<DLPCHECKINFOTAG>(GetProcAddress(LibraryInstance, "DLPCheckInfoTag"));
	if (GetDLPVersion == nullptr || DLPCheckModstring_Hard == nullptr || DLPCheckModstring_Soft == nullptr || 
		DLPCheckUsername_Hard == nullptr || DLPCheckUsername_Soft == nullptr || DLPCheckNameAndHashAndMod == nullptr || 
		DLPCheckMessageSpam == nullptr || DLPCheckUserhash == nullptr || DLPCheckHelloTag == nullptr || 
		DLPCheckInfoTag == nullptr
	)
	{
		std::cout << "Error code: " << GetLastError() << std::endl;
		FreeLibrary(LibraryInstance);

		std::cout << std::endl;
		std::system("pause");
		return EXIT_FAILURE;
	}
	else {
	//Print library location.
		auto LocationBuffer(std::make_unique<wchar_t[]>(PATH_MAX_SIZE));
		size_t LocationLength = GetModuleFileNameW(LibraryInstance, LocationBuffer.get(), PATH_MAX_SIZE - 1U);
		if (LocationLength <= 0 || wcsnlen(LocationBuffer.get(), PATH_MAX_SIZE) <= 0)
		{
			std::cout << "Error code: " << GetLastError() << std::endl;
			FreeLibrary(LibraryInstance);

			std::cout << std::endl;
			std::system("pause");
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
	}

//Enter parameters.
	std::wstring StringClientVersion(L"");
	std::wstring StringModVersion(L"");
	std::wstring StringUserName(L"");
	std::wstring StringUserHash(L"");
	std::wstring StringMessageText(L"");
	unsigned int TagNumber = 0;
	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Example: " << std::endl;
	std::cout << "Client version = \"eMule v0.60d\"" << std::endl;
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
	std::wcin >> TagNumber;
	std::cout << std::endl;

//Print parameters.
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

//Prepare parameters.
	LPCWSTR PointClientVersion = nullptr;
	LPCWSTR PointModVersion = nullptr;
	LPCWSTR PointUserName = nullptr;
	LPCWSTR PointUserHash = nullptr;
	LPCWSTR PointMessageText = nullptr;
	if (!StringClientVersion.empty())
		PointClientVersion = StringClientVersion.c_str();
	if (!StringModVersion.empty())
		PointModVersion = StringModVersion.c_str();
	if (!StringUserName.empty())
		PointUserName = StringUserName.c_str();
	if (!StringUserHash.empty())
		PointUserHash = StringUserHash.c_str();
	if (!StringMessageText.empty())
		PointMessageText = StringMessageText.c_str();

//Run the test with parameters, the order is from eMule Xtreme 8.1 sources.
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
	Reason = DLPCheckUserhash(nullptr); //No more AJ check.
	if (Reason != nullptr)
	{
		std::cout << "<AJ-Ban> DLPCheckUserhash: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}
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
	std::cout << "No any leechers reported." << std::endl;

//Jump here to end.
JumpToEnd:

//Free library file.
	FreeLibrary(LibraryInstance);

//Pause and exit.
	std::cout << std::endl;
	std::system("pause");
	return EXIT_SUCCESS;
}
