@echo off
::关闭回显

title Copying
echo "使用bat脚本来复制文件夹和文件"
echo.

:: call 调用另一个脚本
:: set SrcPath = "D:\Qt5.12.0\5.12.0\mingw73_64\bin\libgcc_s_seh-1.dll"
:: 显示乱码的另存为ANSI编码
:: xcopy 有询问的拷贝

@echo on
::打开回显

copy D:\Qt5.12.0\5.12.0\mingw73_64\bin\Qt5Guid.dll                D:\Test_Code\QtMedia\debug
copy D:\Qt5.12.0\5.12.0\mingw73_64\bin\Qt5Cored.dll               D:\Test_Code\QtMedia\debug
copy D:\Qt5.12.0\5.12.0\mingw73_64\bin\Qt5OpenGLd.dll             D:\Test_Code\QtMedia\debug
copy D:\Qt5.12.0\5.12.0\mingw73_64\bin\Qt5Widgetsd.dll            D:\Test_Code\QtMedia\debug
copy D:\Qt5.12.0\5.12.0\mingw73_64\bin\Qt5Networkd.dll            D:\Test_Code\QtMedia\debug
copy "D:\Qt5.12.0\5.12.0\mingw73_64\bin\libstdc++-6.dll"         "D:\Test_Code\QtMedia\debug"
copy "D:\Qt5.12.0\5.12.0\mingw73_64\bin\Qt5Multimediad.dll"       D:\Test_Code\QtMedia\debug
copy D:\Qt5.12.0\5.12.0\mingw73_64\bin\libwinpthread-1.dll        D:\Test_Code\QtMedia\debug
copy D:\Qt5.12.0\5.12.0\mingw73_64\bin\libgcc_s_seh-1.dll         D:\Test_Code\QtMedia\debug
copy D:\Qt5.12.0\5.12.0\mingw73_64\bin\Qt5MultimediaWidgetsd.dll  D:\Test_Code\QtMedia\debug


::  copy第六行中，前后都需要双引号

::  目录中如果有特殊字符，大部分可以用^这个符号来进行转义，而%就要用%%代替
::  路径中出现符号或一些特殊字符可以进行转义，或用双引号把路径括起来（前后都需要双引号）。

::  如果【】这些中文字符的路径，在使用时出现文件不存在的提示。那么请检查路
::  径中是否有空格，如果存在空格，那么肯定出错。如果没有空格，那么给定的路
::  径是完整的绝对路径，还是不完整的相对路径，如果使用的是相对路径，那么就
::  要看看脚本运行目录是否不和相对路径的第一个文件夹在一起。

@echo off
echo 脚本执行完成
pause
