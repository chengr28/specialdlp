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


Different between SDC and eMule Xtreme DLP (official)
* All SDC are based on eMule Xtreme DLP (official).
* VeryCD-Mod and VeryCD-EasyMule-Mod (1.0) are in SoftBan list because of GPL-Breaker, private network, and community clients.


Usage﻿
* Shutdown eMule first. Unpack the "antiLeech.dll.new" to the directory where original "antiLeech.dll" located, then run eMule.
  * This is the recommended. In this way, all new DLP features will be completely loaded.
* OR: Unpack the "antiLeech.dll.new" the directory where original "antiLeech.dll" located. Enter eMule - Options - AntiLeech and click "reload".


-------------------------------------------------------------------------------


About the real configuration folder
You can select one of below mode, which decides configuration folder location in eMule. The option is in eMule - Options - Extended.
* "Each user has its own configuration and downloads": %UserProfile%\AppData\Local\eMule\config ([System Drive]:\Users\[username]\AppData\Local\eMule\config)
* "Everyone has the same configuration and downloads": %AllUsersProfile%\eMule\config ([System Drive]:\ProgramData\eMule\config)
* "Store config and downloads in the program directory": The folder is in program folder.


-------------------------------------------------------------------------------


SDC versions
* bin: Binary files.
  * Architecture:
    * x86: 32-bit eMule version. Most of eMule are 32-bit, so you should use this one.
    * x64: 64-bit eMule version. It's only for 64-bit eMule.
    * arm: 32-bit ARM version.
    * arm64: 64-bit ARM version.
    * arm64ec: 64-bit ARM (EC) version.
  * Methods:
    * all-verycd: All VeryCD-Mod and VeryCD-EasyMule-Mod.
    * easymule: All VeryCD-EasyMule-Mod (not includes old VeryCD-Mod version).
    * lite: Lite version of SDC, only fixs some bugs.
    * verycd-nickname: All VeryCD-Mod and VeryCD-EasyMule-Mod whose nicknames are in the black dafault list.
    * verycd-tag: All clients whose nick name has "[VeryCD]".
* src: Source files.


-------------------------------------------------------------------------------


FAQ:

Q: How can I detect SDC was loaded successfully?
A: 
  * Check the antiLeech version in eMule - Options - Xtreme II/AntiLeech.
  * Please continue to read below if problem still appears.

Q: What can I do if SDC loads failed?
A: 
  * Please check the file name of "antiLeech.dll".
  * Please check the "antiLeech.dll" location.
  * Please check the platform of system and version of eMule (x86/x64/arm/arm64/arm64ec).

Q: It seems banned or reduce-score result is not expected.
A: 
  * Please check the SDC version whether you need.
  * Please turn "Anti-Banned" off or set it to "0".

Q: What is antiLeech.dll.old?
A: It's deprecated file and can be deleted.

Q: How can I do when SDC gets false positive?
A: 
  * Please check if the environment is in blacklist. You will get false positive if you use:
    * eMule v0.48a eXcalibur 1.85.3: It's not support the eMule Xtreme DLP (official).
    * eMule v0.49b CN-7 Build 191 Final: It's not support all the eMule Xtreme DLP (official) check.
  * Please share feedback to us.

Q: What is the "Ban" mode and the "Reduce Score" mode?
A: 
  * "Ban" mode: Ban all clients which is a leecher.
  * "Reduce Score" mode: Reduce the queue score of SoftBan leechers, not includes HardBan leechers.

Q: How to set "Ban" mode and "Reduce Score" mode?
A: 
  * "Ban" mode: eMule - Options - AntiLeech - All set "ban"
  * "Reduce Score" mode: eMule - Options - AntiLeech, then set the Community Mods to "reduce score" and other to "ban"

Q: Would the download speed be reduced when using SDC?
A: Sometimes "Ban" mode will and "Reduce Score" mode is never.

Q: Would the very bad leechers be passed or be false reduced score when using "Reduce Score" mode?
A: 
  * No. All leechers in HardBan list will be banned. No effect if it's in "Reduce Score" mode.
  * Notice: It will be unlikely happened because of eMule antiLeech sequence check.

Q: Why leechers appear in upload queue?
A: The "Reduce Score" mode does not ban all leechers﻿.

Q: Would SDC fix bugs in eMule Xtreme DLP (official)?
A: Yes, we will also report to eMule Xtreme developer team.


-------------------------------------------------------------------------------


Recommendation for using "Reduce Score" mode:

* Turn "One File One Queue" on.
The way to reducing score is a proportion method. This option is useful to remove leechers from queue.

* Set credit system to "Lovelace" and turn all the punishing rules on.
Please DO NOT set the credit system to eMule official, because there are not any punishment rules.

* Turn "Upload BAN" on.
It can refuse SoftBan leechers downloading from us, but we will not refuse their uploading.

* Change reducing score proportion to maximum.
It can remove SoftBan leechers from upload queue effectively.

* Turn "Anti-Banned" off or set it to "0".
It will remove some leechers from banned list, even in HardBan.

* Restart eMule if you change DLP mode.
AntiLeech is not running in connection life cycle. Some leechers which were connected will not be banned or reduced score after new DLP was loaded or changing mode ("Ban" and "Reduce Score") settings.
