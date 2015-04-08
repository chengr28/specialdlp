WARNING: Strict DLP Chinese(SDC) can be only used for academic exchanges witch follow GNU GPL License. Please do NOT use it for illegal ways in your country(ies).
　　　　Confirm your need before using SDC. If you get some troublesome results or law problems about using SDC, at your own risk.
　　　　See GNU-GPL-v2.0 and Source-License before using source from SDC project.


-------------------------------------------------------------------------------


Strict DLP Chinese Project on SourceForge:
http://sourceforge.net/projects/specialdlp

Strict DLP Chinese Project on GitHub:
https://github.com/chengr28/specialdlp


-------------------------------------------------------------------------------


Difference from Xtreme official DLP version:
All SDC version are based on Xtreme official DLP version.
VeryCD-Mod and VeryCD-EasyMule-Mod(1.0) adds to SoftBan list in SDC, because of GPL-Breaker, private network and community client.

Usage﻿:
1.Close the eMule, then extract "antiLeech.dll.new" from the compressed file and move it to the directory where the original "antiLeech.dll" is. Then restart eMule. (This method is highly recommanded since all the latest check would be loaded with emule. On the contrary, the second method won't assure you that the latest check would be in use.)
2.Or extract the 7z archive and take the antiLeech.dll.new which you need into the folder that there is an antiLeech.dll. Then go to eMule - Options - AntiLeech and click "reload".

About the true config folder of eMule
You can select the modes which decide the config folder in eMule. The option is in eMule - Options - Extended.
1."Each user has its own configuration and downloads", the folder is in:
 * Windows Vista/7/8 or other new version: %userprofile%\AppData\Local\eMule\config (System:\Users\[UserName]\AppData\Local\eMule\config)
 * Windows 2000/XP or the other old one: %userprofile%\Application Data\eMule\config (System:\Documents and Settings\[UserName]\Application Data\eMule\config)
2."Everyone has the same configuration and downloads" (Only Windows Vista/7/8 or other new version), the folder is in %AllUsersProfile%\eMule\config (System:\ProgramData\eMule\config)
3."Store config and downloads in the program directory", the folder is in the program folder.


-------------------------------------------------------------------------------


SDC versions:

* bin：Binary, it can be used in Windows.
* src：C++ source.
 * It is based on Microsoft Visual C++ 2013.

* x86：It is the 32-bit Windows&eMule version.
 * Most of computer and eMule version are 32-bit now, so you should use this version.
* x64：It is the 64-bit Windows&eMule version.
 * It could be only used for 64-Bit Windows&eMule, not in 32-Bit Windows%eMule version.
 * Pay attention of the SDC x64 version, it can be only run in x64 eMule program which targeted platform is x64.

* Lite：It fixed the Xtreme official DLP.
* All-VeryCD-Mod：It can check all VeryCD-Mod and VeryCD-EasyMule-Mod.
* VeryCD-EasyMule-Mod：It can check all VeryCD-EasyMule-Mod without old VeryCD-Mod version.
* VeryCD-Default-NickNames：It can check all VeryCD-Mod and VeryCD-EasyMule-Mod whose nickname is in the black dafault list.


-------------------------------------------------------------------------------


FAQ:

Q: How do I know the SDC is loaded successfully.
A:
* Check the AntiLeech version in eMule - Options - Xtreme II/AntiLeech.
* If no match results is found, please continue to read this FAQ.

Q: What can I do if the SDC loading failed.
A:
* Please check the file name of antiLeech.dll.
* Please check the antiLeech.dll folder.
* Please check the version about platform of system&eMule(x86/x64).

Q: Could not find the result which you need.
A:
* Please check the SDC version whether you need.
* Please turn Anti-Banned off or set "0".

Q: What is antiLeech.dll.old?
A: It is old version of DLP, you can delete it anytime.

Q: What can you do when you has found lost checks?
A: 
* Please check the black list:
 * You will find this problem if you use those combinations between eMule and DLP version.
  * eMule v0.48a eXcalibur 1.85.3
    * eMule eXcalibur is not suppost Xtreme official DLP.
  * eMule v0.49b CN-7 Build 191 Final
    * eMule CN Mod is not suppost all the Xtreme official DLP check.
 * Please make contact with us:
  * SDC Blog: http://blog.sdlpc.net/
  * Report to exploitation mail dev[AT]sdlpc.net or SDC Project owner's email: chengr28[AT]gmail.com

Q: What is the Ban mode or Reduce Score mode?
A: Ban mode means ban all clients that SDC find it is a leecher.
　Reduce Score mode means reduce the SoftBan leechers, but also it can ban all HardBan leechers.

Q: How to use the Ban mode or Reduce Score mode?
A: 
* Ban mode: eMule - Options - AntiLeech - All set "ban"
* Reduce Score mode: eMule - Options - AntiLeech - Community set "reduce score" and other set "ban"

Q: Will the download speed drop after using SDC?
A: Sometimes using Ban mode will drop the download speed, but Reduce Score mode never has this problem.

Q: Will the very bad leechers be passed or be reduced score when using Reduce Score mode?
A: No, because of the eMule rules between HardBan and SoftBan.
 * Sometimes it will appear, because of the eMule antiLeech sequence check. It cannot be solved now.

Q: Why leechers appear in upload queue?
A: The Reduce Score mode is different from Ban mode. It does NOT ban all leechers﻿.

Q: Will SDC fix the Xtreme official DLP?
A: Of course, also we will report problems to Xtreme Project Develop Team.

Q: Where can you see the Changelog?
A: It is in source archive, SDC Project website and SDC Blog.

-------------------------------------------------------------------------------


Some advice for using Reduce Score mode:

* Please turn "One File One Queue" on.
 * The way to reducing score is a proportion method, and this option is useful to remove leechers from queue.
 
* Please set the credit system to "Lovelace", and turn all the punishing rules on.
 Warning: Do NOT set the credit system to eMule official credit system, because there are not any punishing rules in it!

* Please turn "Upload BAN" on.
 * It can refuse the SoftBan leechers downing from us, but not refuse their uploading.

* Please change the reducing score proportion to maximum.
 * It can remove the SoftBan leecher from upload queue effectively.

* Please turn "Anti-Banned" OFF or set "0".
 * It will remove some leecher from banned list including HardBan!

* Please reboot the eMule if you change the mode.
 Notice: AntiLeech is not banning someone all the time. If you change from Ban mode to Reduce Score mode, leechers which passed the check before will NOT be removed after the change of mode. If you changed from Reduce Score Mode to Ban Mode, leechers which in upload queue could not be rechecked.