goto start
-----------------------------
Данила Зыкин ИУ7-33
1) Удаление файлов resfile.* от DrMemory
2) Удаление папок с отчетами DrMemory
-----------------------------
:start

@echo off
DEL /Q /F %CD%\resfile.*
for /d %%i in ("%CD%\*") do rmdir /s /q "%%i"
for /L %%i in (1,1,19) do (
    DEL "out_%%i.txt"
)
