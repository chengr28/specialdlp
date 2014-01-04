特别声明：

全部 Strict DLP Chinese（SDC）仅供学习交流，遵循 GUN GPL 通用公共许可证 (GNU General Public License) ，切勿将其用于任何非法用途！
使用前请自行估量是否有加载 Strict DLP Chinese 的需要，如果不能清楚判断而造成之不良后果，项目组所有成员均不承担一切责任！
使用SDC源代码前务必参阅 GNU-GPL-v2.0 以及 Source-License 通用公共许可证之内容！


-------------------------------------------------------------------------------


Strict DLP Chinese 项目的Blog：
http://blog.sdlpc.net/

Strict DLP Chinese 项目的SourceForge页面：
http://sourceforge.net/projects/specialdlp/

Strict DLP Chinese 项目的GitHub页面：
https://github.com/chengr28/specialdlp/


-------------------------------------------------------------------------------


SDC与官方DLP之间的主要差别：
所有SDC均是基于Xtreme官方DLP的严格版本。
在Xtreme官方DLP的基础上，SDC将VeryCD-Mod和VeryCD-EasyMule-Mod（第1版）中的部分或全部加入了SoftBan列表，原因是GPL-Breaker、私有网络和社区客户端等不良行为。


加载方法：
1.将eMule关闭，把解压出来的antiLeech.dll.new文件放到原来antiLeech.dll所在的目录，并重新启动eMule（强烈建议使用这种加载方法，因为这种方法可以把全部新版的检测加载到eMule中，第2种方法重新加载后已经连接成功的客户端不会被重新检测，且新版本的所有检测不一定都能使用。）
2.或者直接把解压出来的antiLeech.dll.new文件放到原来antiLeech.dll所在的目录，然后在反吸血选项（Xtreme II）中单击“Reload”


关于配置文件真实读取目录问题：
此设置可以在安装eMule的过程中进行选择，不过也可以在以后任何时候在『选项->扩展设置』里进行设置。请注意这个问题，否则可能会造成SDC未被正确加载。

1.在程序目录下保存配置和下载：程序目录下的Config文件夹内
2.每个用户的配置和下载是独立的：
 * Vista/7/8以及更新版本：%userprofile%\AppData\Local\eMule\config 也就是 System:\Users\[您的用户名]\AppData\Local\eMule\config
 * XP/2000等旧版本：%userprofile%\Application Data\eMule\config 也就是 System:\Documents and Settings\[您的用户名]\Application Data\eMule\config
3.所有的用户共用相同的配置和下载（仅限Vista/7/8以及更新版本）：%AllUsersProfile%\eMule\Config 也就是 System:\ProgramData\eMule\Config


-------------------------------------------------------------------------------

SDC版本介绍：

* bin：已编译的二进制程序，可直接在计算机上使用
* src：SDC的C++源代码
提醒1：SDC基于 Microsoft Visual C++ 2012 制作
提醒2：使用SDC的源代码前请认真阅读以下使用许可协议：
       * Source-License：eMule以及Xtreme DLP的使用许可
       * GNU-GPL-v2.0：GNU通用公共许可证v2的部分副本

* x86：用于32位（x86）计算机的SDC版本
提醒：多数家用计算机及使用的eMule程序均为32位，因此您一般应该使用x86版本而不是x64版本
* x64：用于64位（x64）计算机的SDC版本
提醒：适用于64位计算机及x64编译的eMule版本，x64的SDC版本只能用于64位计算机上
注意：SDC的x64版本是专门为原生x64的eMule程序编译的，因为现阶段绝大多数eMule程序的编译目标平台为x86，所以您应该使用x86版本的SDC而非x64版本的SDC！


* Lite：Xtreme官方DLP修补漏检版本。
* All-VeryCD-Mod：对所有VeryCD系列客户端进行检测的版本，其中所有 VeryCD Mod 和easyMule被加入了软性吸血列表。
* VeryCD-EasyMule-Mod：EasyMule被加入了软性吸血列表。
* VeryCD-Default-NickNames：所有昵称中含有VeryCD客户端默认昵称的 VeryCD Mod 和easyMule加入到软性吸血列表。


-------------------------------------------------------------------------------


常见问题FAQ

Q：如何查看SDC已经成功被eMule加载？
A：有2个查看方法：
* 查看反吸血选项中显示的DLP版本号是否为SDC的最新版本号，如果不是则说明加载失败；
* 如果SDC对应版本不能起到预期的效果，请浏览下面FAQ所列举的各种情况予以参考解决。

Q：加载失败如何解决？
A：有3种解决方案：
* 请检查文件名（antiLeech.dll.new）是否完全正确；
* 请检查antiLeech.dll.new所放置的位置是否正确，一般放置在原antiLeech.dll的目录内；
* 请检查对应的版本是否正确，x86/x64版本的SDC只能应用在其设计的环境内，版本之间并不通用。

Q：为何SDC的对应版本无法实现其对应的功能？
A：有2种解决方案：
* 请检查自己选择的版本和自己的设想是否相符；
* 请检查是否开启“防封禁”功能，已经开启的请关闭“防封禁限制”功能。

Q：antiLeech.dll.old 是什么文件？能否删除？
A：antiLeech.dll.old 是被替换的DLP，当eMule发现 antiLeech.dll.new 时会自动将 antiLeech.dll 改名为 antiLeech.dll.old ，而同时将 antiLeech.dll.new 改名为 antiLeech.dll 即应用新版本DLP。
注意：如果新版本DLP能被正常加载后，antiLeech.dll.old 即可被删除。

Q：发现了某些不应出现的误伤或漏检怎么办？
A：有2种方案：
* 请首先确认是否应用“失效搭配方案黑名单”中的搭配，应用者请更换eMule客户端或其它系列的DLP；
 * 注意：如果使用以下搭配，将使SDC无法实现其应有正常的功能或者造成漏检，切记不要采用以下的失效搭配（这里提到的均为该 eMule Mod 的最新版本，其它旧版本同样不能保证可以正常工作）：
  * eMule v0.48a eXcalibur 1.85.3 加载所有版本的SDC
    * 后果：无法成功加载DLP
    * 原因：eXcalibur不支持Xtreme官方版DLP
  * eMule v0.49b CN-7 Build 191 Final 加载所有版本的SDC
    * 后果：漏检吸血客户端
    * 原因：CN Mod 对Xtreme官方版DLP支持不佳造成漏检
 * 请联系SDC开发小组寻求解决方法：
  * SDC开发小组的博客： http://blog.sdlpc.net/
  * SDC开发小组的开发邮箱 dev[AT]sdlpc.net 或直接联系核心代码开发人员 chengr28[AT]gmail.com

Q：何谓“屏蔽模式”和“减分模式”？
A：“屏蔽模式”是将对象全部屏蔽的意思，也就是常说的彻底封杀所有吸血骡；“减分模式”是将被定义为SoftBan的对象减少其积分的意思。

Q：如何应用“屏蔽模式”和“减分模式”？
A：应用方法：
* 屏蔽模式：请把反吸血的惩罚方式选项中全部选中“ban”或者“屏蔽”；
* 减分模式：请把反吸血的惩罚方式选项中的“社区客户端”选为“reduce score”或者“减少积分”，其它选项均为“ban”或者“屏蔽”。

Q：使用SDC会不会影响到eMule的下载？
A：使用“屏蔽模式”时可能会有一定的影响，而使用“减分模式”时则完全不会影响eMule的下载。

Q：如果使用“减分模式”是否会错误对某些行为恶劣的吸血客户端进行减分？
A：不会，因为DLP中分为“HardBan”和“SoftBan”的机制。被定义为HardBan的对象，无论反吸血参数如何设置，都会被彻底屏蔽而不会被错误减分
提示：受限于eMule客户端调用DLP的顺序问题，某些本应被彻底屏蔽的客户端可能被错误减少积分，这个问题暂时无法解决。

Q：为何使用SDC的“减分模式”后发现上传队列依然存在大量被减分的客户端？
A：首先需要说明的是，“减分模式”并不同于“屏蔽模式”，仅仅是依照应用DLP的eMule客户端的初始设定来对吸血骡进行减分，并不是完全封禁。

Q：SDC会修补官方DLP的漏检吗？
A：当然会，只要收到官方DLP漏检的报告，SDC小组会尽快升级以修补漏检，同时也会通知Xtreme官方DLP的维护者尽快修复。

Q：哪里能看到SDC完整的更新日志？
A：从43002开始SDC就不再在编译文件(bin)里附带提供更新日志(Changelog)，如果需要浏览更新日志，可以在SDC的源代码(src)里查看，或者移步SDC的项目主页及 SDC Blog。


应用减分模式特别技巧：

* 如果eMule客户端拥有“每个文件一个队列（多队列）”功能，请将其开启；
说明：“每个文件一个队列（多队列）”功能会适当对一些请求稀有文件上传的客户端的进行加分，因为上传队列得分是按比例扣减的，所以上传队列得分越高扣减的幅度也越大。

* 如果eMule客户端支持多积分系统，建议使用“Lovelace”积分系统，然后将所有惩罚吸血骡的选项打开；
说明：选择一个合适的积分系统有利于eMule的文件交换及对吸血客户端的惩罚。
注意：切勿选择使用官方积分系统！
 * 原因：官方积分系统只有奖励机制而没有惩罚机制，故不建议使用。

* 如果eMule客户端拥有“不上传给吸血客户端”(Upload BAN)功能，请将其开启，已开启者请立即将其关闭；
说明：这个功能可以阻止对被减少积分的客户端的上传。
提示：部分eMule客户端的这个功能的含义是将其上传队列得分清零，但这并不能有效阻止对其的上传。

* 如果应用的是“减分模式”同时eMule客户端的减少积分幅度可以调整，请将其调整至最大；
说明：最大限度的减分幅度能有效遏制一些社区加分客户端
提醒：一般可以调整减少积分幅度的eMule客户端中，上传队列得分是按比例扣减的，所以应该将减分幅度调整为×“1”时扣减幅度最大。

* 如果eMule客户端拥有“防封禁限制”功能，切勿将其开启；
说明：“防封禁限制”功能是对“有贡献”的被屏蔽客户端解封的功能，绝不能开启。
后果：可能导致SDC部分甚至全部失效。

* 如果需要转换检测模式（屏蔽模式、减分模式），设置完成后请马上重启eMule；
说明：被屏蔽的客户端有屏蔽时间限制，而从“屏蔽模式”转到“减分模式”时，被屏蔽的客户端不会立刻释放；从“减分模式”转到“屏蔽模式”时，被减分的客户端则不会被重新检测而造成漏检，故设置完成后请马上重启eMule。