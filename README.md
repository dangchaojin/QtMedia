a Demo of QtCamera

	mainwindow.cpp中写着
    后续任务：

    1、设置监听端口！！！  设置配置文件！！！ 设置api查看静态信息！！！
	   配置是否可以使用telnet进后台
	
    2、使窗口等比缩放拉伸！！！！！！！！

    3、目前cameraWidget是连同mainWidget创建而一起创建
       后续看看可不可以放到goCameraWidget()中构造？？？？？？？？？？？
	
	4、优化日志模块
	
	5、增加一个页面，把日志动态显示在页面上

    6、是否要做成选项统一在左边的，窗口右边展开的样式？？


如需直接运行，到Qt5.12.0\5.12.0\mingw73_64\bin中拷贝以下几个动态链接库文件：

git:    git clone https://github.com/dangchaojin/QtMedia

Qt5Guid.dll
Qt5Cored.dll
Qt5OpenGLd.dll
Qt5Networkd.dll
Qt5Widgetsd.dll
libstdc++-6.dll
libgcc_s_seh-1.dll
Qt5Multimediad.dll
libwinpthread-1.dll
Qt5MultimediaWidgetsd.dll