#pragma once


//Add by SDC team.
#if defined(SPECIAL_DLP_VERSION)
	#define DLPVERSION		44005
	#define DETACH_VERSION	44,0,0,5
#else //Official
	#define DLPVERSION		44
#endif


class CantiLeech 
{
public:
	BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD,LPVOID);
	DWORD	__declspec(dllexport) GetDLPVersion(){return DLPVERSION;}
	//old versions to keep compatible
	/* //drop old version support
	LPCTSTR __declspec(dllexport) DLPCheckModstring(LPCTSTR modversion, LPCTSTR clientversion);
	LPCTSTR __declspec(dllexport) DLPCheckUsername(LPCTSTR username);
	LPCTSTR __declspec(dllexport) DLPCheckNameAndHash(CString username, CString& userhash);
	*/
	//new versions
	LPCTSTR __declspec(dllexport) DLPCheckModstring_Hard(LPCTSTR modversion, LPCTSTR clientversion);
	LPCTSTR __declspec(dllexport) DLPCheckModstring_Soft(LPCTSTR modversion, LPCTSTR clientversion);
	LPCTSTR __declspec(dllexport) DLPCheckUsername_Hard(LPCTSTR username);
	LPCTSTR __declspec(dllexport) DLPCheckUsername_Soft(LPCTSTR username);
	LPCTSTR __declspec(dllexport) DLPCheckNameAndHashAndMod(CString username, CString& userhash, CString& modversion);
	LPCTSTR __declspec(dllexport) DLPCheckMessageSpam(LPCTSTR messagetext);


	LPCTSTR __declspec(dllexport) DLPCheckUserhash(const PBYTE userhash);


	LPCTSTR __declspec(dllexport) DLPCheckHelloTag(UINT tagnumber);
	LPCTSTR __declspec(dllexport) DLPCheckInfoTag(UINT tagnumber);

	void __declspec(dllexport)  TestFunc();


private:
	const bool IsTypicalHex (CString& addon) const;
};

//<<< new tags from eMule 0.04x
#define CT_UNKNOWNx0			0x00 // Hybrid Horde protocol
#define CT_UNKNOWNx12			0x12 // http://www.haspepapa-welt.de (DodgeBoards)
#define CT_UNKNOWNx13			0x13 // http://www.haspepapa-welt.de (DodgeBoards)
#define CT_UNKNOWNx14			0x14 // http://www.haspepapa-welt.de (DodgeBoards)
#define CT_UNKNOWNx15			0x15 // http://www.haspepapa-welt.de (DodgeBoards) & DarkMule |eVorte|X|
#define CT_UNKNOWNx16			0x16 // http://www.haspepapa-welt.de (DodgeBoards)
#define CT_UNKNOWNx17			0x17 // http://www.haspepapa-welt.de (DodgeBoards)
#define CT_UNKNOWNx4D			0x4D // pimp my mule (00de)
#define CT_UNKNOWNxE6			0xE6 // http://www.haspepapa-welt.de
#define CT_UNKNOWNx22			0x22 // DarkMule |eVorte|X|
#define CT_UNKNOWNx5D			0x5D // md4 
#define CT_UNKNOWNx63			0x63 // ?
#define CT_UNKNOWNx64			0x64 // ?
#define CT_UNKNOWNx69			0x69 // eMuleReactor //Xman don't use this, it's webcache!
#define CT_UNKNOWNx6B			0x6B // md4
#define CT_UNKNOWNx6C			0x6C // md4
#define CT_UNKNOWNx74			0x74 // md4
#define CT_UNKNOWNx76			0x76 // www.donkey2002.to
#define CT_UNKNOWNx79			0x79 // Bionic
#define CT_UNKNOWNx7A			0x7A // NewDarkMule
#define CT_UNKNOWNx83			0x83 // Fusspi
#define CT_UNKNOWNx87			0x87 // md4
#define CT_UNKNOWNx88			0x88 // DarkMule v6 |eVorte|X|
#define CT_UNKNOWNx8c			0x8c // eMule v0.27c [LSD7c] 
#define CT_UNKNOWNx8d			0x8d // unknown Leecher - (client version:60)
#define CT_UNKNOWNx94			0x94 // 00.de community  //Xman 20.08.05
#define CT_UNKNOWNx97			0x97 // Emulereactor Community Mod
#define CT_UNKNOWNx98			0x98 // Emulereactor Community Mod
#define CT_UNKNOWNx99			0x99 // eMule v0.26d [RAMMSTEIN 8b]
#define CT_UNKNOWNx9C			0x9C // Emulereactor Community Mod
#define CT_UNKNOWNxbb			0xbb // emule.de (client version:60)
#define CT_UNKNOWNxc4			0xc4 // MD5 Community from new bionic - hello
#define CT_UNKNOWNxC8			0xc8 // MD5 Community from new bionic - hello //Xman x4
#define CT_UNKNOWNxCA			0xCA // NewDarkMule
#define CT_UNKNOWNxCD			0xCD // www.donkey2002.to
#define CT_UNKNOWNxCE			0xCE // FRZ community  //Xman 20.08.05
#define CT_UNKNOWNxCF			0xCF // FRZ community  //Xman 20.08.05
#define CT_UNKNOWNxDA			0xDA // Emulereactor Community Mod
#define CT_UNKNOWNxEC			0xec // SpeedMule and clones	//Xman x4
#define CT_UNKNOWNxF0			0xF0 // Emulereactor Community Mod
#define CT_UNKNOWNxF4			0xF4 // Emulereactor Community Mod
#define CT_UNKNOWNxD2			0xD2 // Chinese Leecher //SquallATF
//#define CT_UNKNOWNx85			0x85 // viper-israel.org and eChanblardNext  //zz_fly, viper become good

#define CT_FRIENDSHARING		0x66 // eWombat  [SNAFU]
#define CT_DARK					0x54 // eWombat [SNAFU]
#define FRIENDSHARING_ID 0x5F73F1A0  // Magic Key, DO NOT CHANGE!

// unknown eMule tags
#define ET_MOD_UNKNOWNx12		0x12 // http://www.haspepapa-welt.de
#define ET_MOD_UNKNOWNx13		0x13 // http://www.haspepapa-welt.de
#define ET_MOD_UNKNOWNx14		0x14 // http://www.haspepapa-welt.de
#define ET_MOD_UNKNOWNx17		0x17 // http://www.haspepapa-welt.de
#define ET_MOD_UNKNOWNx2F		0x2F // eMule v0.30 [OMEGA v.07 Heiko]
#define ET_MOD_UNKNOWNx30		0x30 // aMule 1.2.0
#define ET_MOD_UNKNOWNx36		0x36 // eMule v0.26
#define ET_MOD_UNKNOWNx3C		0x3C // enkeyDev.6 / LamerzChoice 9.9a
#define ET_MOD_UNKNOWNx41		0x41 // CrewMod (pre-release mod based on Plus) identification
#define ET_MOD_UNKNOWNx42		0x42 // CrewMod (pre-release mod based on Plus) key verification
#define ET_MOD_UNKNOWNx43		0x43 // CrewMod (pre-release mod based on Plus) version info
#define ET_MOD_UNKNOWNx50		0x50 // Bionic 0.20 Beta]
#define ET_MOD_UNKNOWNx59		0x59 // emule 0.40 / eMule v0.30 [LSD.12e]
#define ET_MOD_UNKNOWNx5B		0x5B // eMule v0.26
#define ET_MOD_UNKNOWNx60		0x60 // eMule v0.30a Hunter.6 + eMule v0.26
#define ET_MOD_UNKNOWNx64		0x64 // LSD.9dT / Athlazan(0.29c)Alpha.3
#define ET_MOD_UNKNOWNx76		0x76 // http://www.haspepapa-welt.de (DodgeBoards)
#define ET_MOD_UNKNOWNx84		0x84 // eChanblardv3.2
#define ET_MOD_UNKNOWNx85		0x85 // ? 
#define ET_MOD_UNKNOWNx86		0x86 // ? 
#define ET_MOD_UNKNOWNx93		0x93 // ?
#define ET_MOD_UNKNOWNxA6		0xA6 // eMule v0.26
#define ET_MOD_UNKNOWNxB1		0xB1 // Bionic 0.20 Beta]
#define ET_MOD_UNKNOWNxB4		0xB4 // Bionic 0.20 Beta]
#define ET_MOD_UNKNOWNxC8		0xC8 // Bionic 0.20 Beta]
#define ET_MOD_UNKNOWNxC9		0xC9 // Bionic 0.20 Beta]
#define ET_MOD_UNKNOWNxDA		0xDA // Rumata (rus)(Plus v1f) - leecher mod?
//>>> eWombat [SNAFU_V3]
