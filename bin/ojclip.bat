@echo off

oj-bundle -I %VSCODE_WORKSPACE_ROOT% main.cpp | clip

@echo source is copied to clipboard.

exit /b