@echo off
REM RMDIR /S /Q "win_build"
call mkdir win_build
call cd win_build
call cmake -G"Visual Studio 16 2019" ../
call cd ..
PAUSE