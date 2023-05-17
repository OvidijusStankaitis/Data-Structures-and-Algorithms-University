@echo off
if "%USERDOMAIN%" == "DESKTOP-RKG7LUC" goto savasPC
REM MIF kompiuteris
set PATH=C:\PROGRA~2\Dev-Cpp\MinGW64\bin\;%PATH%
make run
goto :eof

:savasPC
make run
goto :eof
