@echo off
::�رջ���

title Copying
echo "ʹ��bat�ű��������ļ��к��ļ�"
echo.

:: call ������һ���ű�
:: set SrcPath = "D:\Qt5.12.0\5.12.0\mingw73_64\bin\libgcc_s_seh-1.dll"
:: ��ʾ��������ΪANSI����
:: xcopy ��ѯ�ʵĿ���

@echo on
::�򿪻���

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


::  copy�������У�ǰ����Ҫ˫����

::  Ŀ¼������������ַ����󲿷ֿ�����^�������������ת�壬��%��Ҫ��%%����
::  ·���г��ַ��Ż�һЩ�����ַ����Խ���ת�壬����˫���Ű�·����������ǰ����Ҫ˫���ţ���

::  ���������Щ�����ַ���·������ʹ��ʱ�����ļ������ڵ���ʾ����ô����·
::  �����Ƿ��пո�������ڿո���ô�϶��������û�пո���ô������·
::  ���������ľ���·�������ǲ����������·�������ʹ�õ������·������ô��
::  Ҫ�����ű�����Ŀ¼�Ƿ񲻺����·���ĵ�һ���ļ�����һ��

@echo off
echo �ű�ִ�����
pause
