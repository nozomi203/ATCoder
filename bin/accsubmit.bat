@echo off

oj-bundle -I %VSCODE_WORKSPACE_ROOT% main.cpp > tmp.cpp
acc submit tmp.cpp
del tmp.cpp

exit /b