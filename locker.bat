:: https://jingyan.baidu.com/article/6fb756ec98a317241858fbfe.html

::  1���ŵ���ӦĿ¼��
::  2����һ�����У�����privateĿ¼
::  3��������ļ��ŵ�privateĿ¼��
::  4���ڶ������У����ܣ������ļ���
::  5�����������У��������룬�ļ���ʾ������

::��ܰ��ʾ��
::��Private�ļ��б�����ʱ��ͨ���ļ���ѡ������
::���ѡ����ʾ���ص��ļ����ļ��к�������������ô���ļ����Ǵ��ڼ���״̬��
::���ȡ����ѡ�������ܱ�����ϵͳ�ļ�������ôPrivate�ļ��н����ٴ�������״̬��


cls
@ECHO OFF
title Folder Private
if EXIST "HTG Locker" goto UNLOCK
if NOT EXIST Private goto MDLOCKER
:CONFIRM
echo ��ȷ��Ҫ��������Private�ļ�����(Y/N)
set/p "cho=>"
if %cho%==Y goto LOCK
if %cho%==y goto LOCK
if %cho%==n goto END
if %cho%==N goto END
echo Invalid choice.
goto CONFIRM
:LOCK
ren Private "HTG Locker"
attrib +h +s "HTG Locker"
echo Folder locked
goto End
:UNLOCK
echo ���������������ļ���
set/p "pass=>"
if NOT %pass%== 1234567dcj goto FAIL
attrib -h -s "HTG Locker"
ren "HTG Locker" Private
echo Folder Unlocked successfully
goto End
:FAIL
echo Invalid password
goto end
:MDLOCKER
md Private
echo Private created successfully
goto End
:End