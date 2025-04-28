// Strict DLP Chinese (SDC) is a set of strict DLP (Dynamic Leech Protection) DLLs based on the eMule Xtreme Mod's official version.
// Copyright (C) 2009-2025 SDC Team
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

//Global variable
//No variable

//Namespace definition
//No definition

//Function: Main
int main(
//	const int argc, 
//	const char * const argv[]
	void
)
{
//Set program environment.
	if (_set_errno(0);
		std::setlocale(LC_ALL, SDC_LOCALE_SETTING) == nullptr) [[unlikely]]
	{
		std::cout << "Set locale failed, error code is " << errno << "." << std::endl;
		PressReturnToEnd();

		return EXIT_FAILURE;
	}

//Load library file.
	const auto LibraryInstance{LoadLibraryExA(SDC_LIBRARY_NAME, nullptr, LOAD_LIBRARY_SEARCH_APPLICATION_DIR)};
	if (LibraryInstance == nullptr) [[unlikely]]
	{
		std::cout << "Load library file failed, error code is " << GetLastError() << "." << std::endl;
		PressReturnToEnd();

		return EXIT_FAILURE;
	}

//Load function from library.
	const auto GetDLPVersion{reinterpret_cast<const GETDLPVERSION>(GetProcAddress(LibraryInstance, "GetDLPVersion"))};
	const auto DLPCheckModstring_Hard{reinterpret_cast<const DLPCHECKMODSTRING_HARD>(GetProcAddress(LibraryInstance, "DLPCheckModstring_Hard"))};
	const auto DLPCheckModstring_Soft{reinterpret_cast<const DLPCHECKMODSTRING_SOFT>(GetProcAddress(LibraryInstance, "DLPCheckModstring_Soft"))};
	const auto DLPCheckUsername_Hard{reinterpret_cast<const DLPCHECKUSERNAME_HARD>(GetProcAddress(LibraryInstance, "DLPCheckUsername_Hard"))};
	const auto DLPCheckUsername_Soft{reinterpret_cast<const DLPCHECKUSERNAME_SOFT>(GetProcAddress(LibraryInstance, "DLPCheckUsername_Soft"))};
	const auto DLPCheckNameAndHashAndMod{reinterpret_cast<const DLPCHECKNAMEANDHASHANDMOD>(GetProcAddress(LibraryInstance, "DLPCheckNameAndHashAndMod"))};
	const auto DLPCheckMessageSpam{reinterpret_cast<const DLPCHECKMESSAGESPAM>(GetProcAddress(LibraryInstance, "DLPCheckMessageSpam"))};
	const auto DLPCheckHelloTag{reinterpret_cast<const DLPCHECKHELLOTAG>(GetProcAddress(LibraryInstance, "DLPCheckHelloTag"))};
	const auto DLPCheckInfoTag{reinterpret_cast<const DLPCHECKINFOTAG>(GetProcAddress(LibraryInstance, "DLPCheckInfoTag"))};
	if (GetDLPVersion == nullptr || DLPCheckModstring_Hard == nullptr || DLPCheckModstring_Soft == nullptr || 
		DLPCheckUsername_Hard == nullptr || DLPCheckUsername_Soft == nullptr || DLPCheckNameAndHashAndMod == nullptr || 
		DLPCheckMessageSpam == nullptr || DLPCheckHelloTag == nullptr || DLPCheckInfoTag == nullptr
	) [[unlikely]]
	{
		std::cout << "Load function from library failed, error code is " << GetLastError() << "." << std::endl;
		FreeLibrary(LibraryInstance);
		PressReturnToEnd();

		return EXIT_FAILURE;
	}

//Print library location.
	auto LocationBuffer(std::make_unique<wchar_t[]>(SDC_PATH_MAXSIZE + sizeof(std::uint8_t)));
	if (GetModuleFileNameW(LibraryInstance, LocationBuffer.get(), SDC_PATH_MAXSIZE) <= 0 || 
		wcsnlen(LocationBuffer.get(), SDC_PATH_MAXSIZE) <= 0) [[unlikely]]
	{
		std::cout << "Load module name from library failed, error code is " << GetLastError() << "." << std::endl;
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
	std::wstring StringClientVersion;
	std::wstring StringModVersion;
	std::wstring StringUserName;
	std::wstring StringUserHash;
	std::wstring StringMessageText;
	unsigned int TagNumber{0};
	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Example: " << std::endl;
	std::cout << "Client version == \"eMule v0.70a\"" << std::endl;
	std::cout << "Mod version == \"Xtreme 8.1\"" << std::endl;
	std::cout << "User name == \"Hello World!\"" << std::endl;
	std::cout << "User hash == \"0123456789ABCDE0123456789ABCDE01\"" << std::endl;
	std::cout << "Message text == \"Hello World!\"" << std::endl;
	std::cout << "Tag number == \"0\"" << std::endl;
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
	std::cout << "Client version == ";
	if (StringClientVersion.empty() == true)
	{
		StringClientVersion.clear();
		std::wcout << L"<empty>";
	}
	else {
		std::cout << "\"";
		std::wcout << StringClientVersion;
		std::cout << "\"";
	}
	std::cout << std::endl;
	std::cout << "Mod version == ";
	if (StringModVersion.empty() == true)
	{
		StringModVersion.clear();
		std::wcout << L"<empty>";
	}
	else {
		std::cout << "\"";
		std::wcout << StringModVersion;
		std::cout << "\"";
	}
	std::cout << std::endl;
	std::cout << "User name == ";
	if (StringUserName.empty() == true)
	{
		StringUserName.clear();
		std::wcout << L"<empty>";
	}
	else {
		std::cout << "\"";
		std::wcout << StringUserName;
		std::cout << "\"";
	}
	std::cout << std::endl;
	std::cout << "User hash == ";
	if (StringUserHash.empty() == true)
	{
		StringUserHash.clear();
		std::wcout << L"<empty>";
	}
	else {
		std::cout << "\"";
		std::wcout << StringUserHash;
		std::cout << "\"";
	}
	std::cout << std::endl;
	std::cout << "Message text == ";
	std::wcout << StringMessageText;
	if (StringMessageText.empty() == true)
	{
		StringMessageText.clear();
		std::wcout << L"<empty>";
	}
	else {
		std::cout << "\"";
		std::wcout << StringMessageText;
		std::cout << "\"";
	}
	std::cout << std::endl;
	std::cout << "Tag number == \"";
	std::cout << std::hex << "0x" << TagNumber;
	std::cout << "\"" << std::endl;
	std::cout << std::endl;

//Check parameter.
	LPCWSTR PointClientVersion{nullptr};
	LPCWSTR PointModVersion{nullptr};
	LPCWSTR PointUserName{nullptr};
	LPCWSTR PointUserHash{nullptr};
	LPCWSTR PointMessageText{nullptr};
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

//Start to test, order is from eMule Xtreme 8.1 sources.
	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	LPCWSTR Reason{nullptr};
	Reason = DLPCheckHelloTag(TagNumber);
	if (Reason != nullptr) [[unlikely]]
	{
		std::cout << "<Hard-Ban> DLPCheckHelloTag: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}
	Reason = DLPCheckInfoTag(TagNumber);
	if (Reason != nullptr) [[unlikely]]
	{
		std::cout << "<Hard-Ban> DLPCheckInfoTag: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}
	Reason = DLPCheckModstring_Hard(PointModVersion, PointClientVersion);
	if (Reason != nullptr) [[unlikely]]
	{
		std::cout << "<Hard-Ban> DLPCheckModstring_Hard: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}
	Reason = DLPCheckModstring_Soft(PointModVersion, PointClientVersion);
	if (Reason != nullptr) [[unlikely]]
	{
		std::cout << "<Soft-Ban> DLPCheckModstring_Soft: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}
	Reason = DLPCheckNameAndHashAndMod(PointUserName, PointUserHash, PointModVersion);
	if (Reason != nullptr) [[unlikely]]
	{
		std::cout << "<Soft-Ban> DLPCheckNameAndHashAndMod: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}
	Reason = DLPCheckUsername_Soft(PointUserName);
	if (Reason != nullptr) [[unlikely]]
	{
		std::cout << "<Soft-Ban> DLPCheckUsername_Soft: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}
	Reason = DLPCheckUsername_Hard(PointUserName);
	if (Reason != nullptr) [[unlikely]]
	{
		std::cout << "<Hard-Ban> DLPCheckUsername_Hard: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}
	Reason = DLPCheckMessageSpam(PointMessageText);
	if (Reason != nullptr) [[unlikely]]
	{
		std::cout << "<Spam-Ban> DLPCheckMessageSpam: Report \"";
		std::wcout << Reason << L"\"." << std::endl;
		goto JumpToEnd;
	}

//No any leechers reported.
	std::cout << "No reported." << std::endl;

//Jump here to end.
JumpToEnd:

//Free library file and pause to show result.
	FreeLibrary(LibraryInstance);
	PressReturnToEnd();

	return EXIT_SUCCESS;
}

//Function: Press "Return" to end.
static void PressReturnToEnd(
	void
)
{
	std::cout << std::endl;
	std::cout << "Press \"Return\" to end." << std::endl;
	std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), u8'\n');
	std::cin.get();

	return;
}
