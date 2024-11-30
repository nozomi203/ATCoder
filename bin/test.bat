@echo off
pushd %~dp0
python3 ./test.py
popd
exit /b