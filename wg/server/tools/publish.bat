@echo off

:menu
cls
echo -----------------------------------------------------------------
echo 1  -  �����ͻ���
echo 2  -  ����������
echo 3  -  ȫ������
echo -----------------------------------------------------------------
set /p input=��ѡ��: 
cls
if "%input%"=="1" call :execute publish\publish_client.cmd
if "%input%"=="2" call :execute publish\publish_server.cmd
if "%input%"=="3" call :execute publish\publish_all.cmd

:execute
if exist %1 (call %1 && goto :eof) else echo %1 ������. & pause & exit
