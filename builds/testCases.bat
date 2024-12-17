@echo off
cd /d "%~dp0"
LogCleaner.exe .\test\test.log ./cleaned/defaultTest.log
LogCleaner.exe .\test\test.log ./cleaned/hashTest.log -h
LogCleaner.exe .\test\test.log ./cleaned/jobTest.log -j
LogCleaner.exe ./test/test.log ./cleaned/shareTest.log -s
LogCleaner.exe ./test/test.log test.log
LogCleaner.exe test.log test2.log test3.log test4.log
LogCleaner.exe test.log test2.log test
LogCleaner.exe test.log test.log
LogCleaner.exe test.log