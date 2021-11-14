WARNING

Strict DLP Chinese (SDC) is only for academic exchange, which is following the license.
Using SDC via illegal ways are prohibited. Please also confirm you are really need to use SDC.
If you get troublesome results or law problems about using SDC, at your own risk.
Please read the license before using the source from SDC project.


-------------------------------------------------------------------------------


Strict DLP Chinese in GitHub
https://github.com/chengr28/specialdlp

Strict DLP Chinese in GitLab
https://gitlab.com/chengr28/specialdlp

Strict DLP Chinese in Sourceforge
https://sourceforge.net/projects/specialdlp


-------------------------------------------------------------------------------


Different between SDC and eMule Xtreme (official) DLP
* All SDC are based on eMule Xtreme (official) DLP.
* VeryCD-Mod and VeryCD-EasyMule-Mod (1.0) are in SoftBan list because of GPL-Breaker, private network and community clients.

Usage﻿
* Shutdown eMule, then export "antiLeech.dll.new" to the directory where original "antiLeech.dll" located. Restart the eMule.
  * This way is highly recommended, because all latest DLP version will be completely loaded.
* OR: Export "antiLeech.dll.new" the directory where original "antiLeech.dll" located. Then enter eMule - Options - AntiLeech and click "reload".


-------------------------------------------------------------------------------


About the real configuration folder
You can select one of below mode, which decides the configuration folder in eMule. The option is in eMule - Options - Extended.
* "Each user has its own configuration and downloads": %UserProfile%\AppData\Local\eMule\config ([System Drive]:\Users\[username]\AppData\Local\eMule\config)
* "Everyone has the same configuration and downloads": %AllUsersProfile%\eMule\config (System:\ProgramData\eMule\config)
* "Store config and downloads in the program directory": The folder is in program folder.


-------------------------------------------------------------------------------


SDC versions

* bin: Binary files.
  * Architecture:
    * x86: 32-bit eMule version. Most of eMule version are 32-bit, so you should usually use this one.
    * x64: 64-bit both system & eMule version. It's only for 64-bit Windows and 64-bit eMule.
    * arm: 32-bit ARM version.
    * arm64: 64-bit ARM version.
    * arm64ec: 64-bit ARM EC version.
  * Methods:
    * all-verycd: All VeryCD-Mod and VeryCD-EasyMule-Mod.
    * easymule: All VeryCD-EasyMule-Mod (not includes old VeryCD-Mod version).
    * lite: Lite version of SDC, only fixs some bugs.
    * verycd-nickname: All VeryCD-Mod and VeryCD-EasyMule-Mod whose nicknames are in the black dafault list.
    * verycd-tag: All clients whose nick name has "[VeryCD]".
* src: Source files.


-------------------------------------------------------------------------------


FAQ:

Q: How do I detect the SDC is loaded successfully?
A: 
  * Check the antiLeech version in eMule - Options - Xtreme II/AntiLeech.
  * Please continue to read this FAQ if problem still not able to solved.

Q: What can I do if the SDC loads failed?
A: 
  * Please check the file name of "antiLeech.dll".
  * Please check the "antiLeech.dll" folder.
  * Please check the platform of system and version of eMule (x86/x64/arm/arm64/arm64ec).

Q: It seems I could not detect the result which be needed.
A: 
  * Please check the SDC version whether you need.
  * Please turn "Anti-Banned" off or set to "0".

Q: What is antiLeech.dll.old?
A: It's deprecated DLP and can be removed.

Q: What can you do when you has found lost checks?
A: 
  * Please check if the environment is in blacklist. You will get troubles if you use those combinations between eMule and DLP version:
    * eMule v0.48a eXcalibur 1.85.3: It's not support eMule Xtreme (official) DLP.
    * eMule v0.49b CN-7 Build 191 Final: It's not support all the eMule Xtreme (official) DLP check.
  * Please contact with us.

Q: What is the "Ban" mode or "Reduce Score" mode?
A: 
  * "Ban" mode: Ban all clients which is a leecher.
  * "Reduce Score" mode: Reduce the SoftBan leechers, not includes HardBan leechers.

Q: How to use the "Ban" mode or "Reduce Score" mode?
A: 
  * "Ban" mode: eMule - Options - AntiLeech - All set "ban"
  * "Reduce Score" mode: eMule - Options - AntiLeech - Community set "reduce score" and other set "ban"

Q: Would download speed drop down after using SDC?
A: Sometimes using "Ban" mode will drop the download speed, but "Reduce Score" mode should never do that.

Q: Would some very bad leechers are passed or reduced score when using "Reduce Score" mode?
A: 
  * No, because they are in HardBan list and there is no effect in "Reduce Score" mode.
  * Sometimes it will be happened because of eMule antiLeech sequence check. It cannot be solved now.

Q: Why leechers appear in upload queue?
A: The "Reduce Score" mode is different from "Ban" mode. It does not ban all leechers﻿.

Q: Would SDC fix bugs in the eMule Xtreme (official) DLP?
A: Yes, we will also report to Xtreme Project team.


-------------------------------------------------------------------------------


Some advices for using "Reduce Score" mode:

* Please turn "One File One Queue" on.
The way to reducing score is a proportion method and this option is useful to remove leechers from queue.

* Please set the credit system to "Lovelace" and turn all the punishing rules on.
Please DO NOT set the credit system to eMule official, because there are not any punishment rules.

* Please turn "Upload BAN" on.
It can refuse the SoftBan leechers downing from us, but we will not refuse their uploading.

* Please change the reducing score proportion to maximum.
It can remove the SoftBan leecher from upload queue effectively.

* Please turn "Anti-Banned" off or set to "0".
It will remove some leecher from banned list, even in HardBan.

* Please reboot eMule if you change the mode.
AntiLeech is not running in whole connection life cycle. Some leechers which were connected will not be banned or reduced score after new DLP was loaded or changing mode ("Ban" and "Reduce Score") settings.
