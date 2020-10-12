WARNING

Strict DLP Chinese (SDC) is only for academic exchange, which is following the license.
Using SDC via illegal ways are prohibited. Please also confirm you are really need to use SDC.
If you get troublesome results or law problems about using SDC, at your own risk.
Please read the license before using the source from SDC project.


-------------------------------------------------------------------------------


Strict DLP Chinese on GitHub
https://github.com/chengr28/specialdlp

Strict DLP Chinese on GitLab
https://gitlab.com/chengr28/specialdlp

Strict DLP Chinese on Sourceforge
https://sourceforge.net/projects/specialdlp


-------------------------------------------------------------------------------


Different between SDC and eMule Xtreme (official) DLP
* All SDC are based on eMule Xtreme (official) DLP.
* VeryCD-Mod and VeryCD-EasyMule-Mod (1.0) are in SoftBan list because of GPL-Breaker, private network and community clients.

Usage﻿
* Shutdown eMule first, export "antiLeech.dll.new" to the directory where original "antiLeech.dll" in. Then restart eMule.
  * Highly recommended since all latest DLP version will be loaded.
  * The second method (as below) may not be loaded all check progress.
* OR: Export the antiLeech.dll.new into the folder which contains the original antiLeech.dll, then: eMule - Options - AntiLeech and click "reload".


-------------------------------------------------------------------------------


About eMule real configuration folder
* You can select one of below mode, which decides the configuration folder in eMule. The option is in eMule - Options - Extended.
  * "Each user has its own configuration and downloads": %UserProfile%\AppData\Local\eMule\config ([System Drive]:\Users\[username]\AppData\Local\eMule\config)
  * "Everyone has the same configuration and downloads": %AllUsersProfile%\eMule\config (System:\ProgramData\eMule\config)
  * "Store config and downloads in the program directory": The folder is in the program folder.


-------------------------------------------------------------------------------


SDC versions

* bin: The binary files.
  * Architecture:
    * x86: 32-bit eMule version. Most of eMule version are 32-bit, so you should use this one.
    * x64: 64-bit Windows & eMule version. It's only for 64-bit Windows and 64-bit eMule.
      * Pay attention of x64 version, it's only for x64 eMule program which targeted platform is x64.
    * arm: 32-bit ARM version.
    * arm64: 64-bit ARM version.
  * Operations:
    * Lite: Lite version of SDC, only fixs some bugs.
    * All-VeryCD-Mod: All VeryCD-Mod and VeryCD-EasyMule-Mod.
    * VeryCD-Tag: All clients whose nick name has "[VeryCD]".
    * VeryCD-EasyMule-Mod: All VeryCD-EasyMule-Mod (not includes old VeryCD-Mod version).
    * VeryCD-Default-NickNames: All VeryCD-Mod and VeryCD-EasyMule-Mod whose nicknames are in the black dafault list.
* src: The source files.


-------------------------------------------------------------------------------


FAQ:

Q: How do I detect the SDC is loaded successfully?
A: 
  * Check the antiLeech version in eMule - Options - Xtreme II/AntiLeech.
  * Please continue to read this FAQ if problem still not able to fix.

Q: What can I do if the SDC loads failed?
A: 
  * Please check the file name of antiLeech.dll.
  * Please check the antiLeech.dll folder.
  * Please check the platform of system and version of eMule(x86/x64).

Q: Seem could not detect the result which be needed.
A: 
  * Please check the SDC version whether you need.
  * Please turn "Anti-Banned" off or set to "0".

Q: What is antiLeech.dll.old?
A: 
  * It's the old file of DLP, it can be removed.

Q: What can you do when you has found lost checks?
A: 
  * Please check if the environment is the blacklist as below. You will get troubles if you use those combinations between eMule and DLP version:
    * eMule v0.48a eXcalibur 1.85.3
      * eMule eXcalibur is not support eMule Xtreme (official) DLP.
    * eMule v0.49b CN-7 Build 191 Final
      * eMule CN-Mod is not support all the eMule Xtreme (official) DLP check.
  * Please contact with us.

Q: What is the "Ban" mode or "Reduce Score" mode?
A: 
  * "Ban" mode: Ban all clients which is a leecher.
　* "Reduce Score" mode: Reduce the SoftBan leechers, but it still bans all HardBan leechers.

Q: How to use the "Ban" mode or "Reduce Score" mode?
A: 
  * "Ban" mode: eMule - Options - AntiLeech - All set "ban"
  * "Reduce Score" mode: eMule - Options - AntiLeech - Community set "reduce score" and other set "ban"

Q: Will the download speed dropping down after using SDC?
A: 
  * Sometimes using "Ban" mode will drop the download speed, but "Reduce Score" mode should never do that.

Q: Will the very bad leechers be passed or be reduced score when using "Reduce Score" mode?
A: 
  * No, because of the eMule rules between HardBan and SoftBan.
  * Sometimes it will be happened because of eMule antiLeech sequence check. It cannot be solved now.

Q: Why leechers appear in upload queue?
A: 
  * The "Reduce Score" mode is different from "Ban" mode. It does not ban all leechers﻿.

Q: Will SDC fix bugs in the eMule Xtreme (official) DLP?
A: 
  * Yes, we will also report to Xtreme Project team.


-------------------------------------------------------------------------------


Some advices for using "Reduce Score" mode:

* Please turn "One File One Queue" on.
  * The way to reducing score is a proportion method and this option is useful to remove leechers from queue.

* Please set the credit system to "Lovelace" and turn all the punishing rules on.
  * Warning: Please DO NOT set the credit system to eMule official credit system, because there are not any punishment rules in it!

* Please turn "Upload BAN" on.
  * It can refuse the SoftBan leechers downing from us, but we will not refuse their uploading.

* Please change the reducing score proportion to maximum.
  * It can remove the SoftBan leecher from upload queue effectively.

* Please turn "Anti-Banned" off or set to "0".
  * It will remove some leecher from banned list, even it is HardBan!

* Please reboot the eMule if you change the mode.
  * Notice: AntiLeech is not banning someone all the time. Leechers which passed the check before will NOT be removed after the change of mode if you change from "Ban" mode to "Reduce Score" mode.
  * Leechers which in upload queue could not be checked again if you changed from Reduce Score Mode to Ban Mode.
