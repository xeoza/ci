goto start_positive_tests
-----------------------------
Данила Зыкин ИУ7-33
1) Функциональное тестирование моей реализации функции getdelim и str_replace
2) Bat-файл написан под Windows 10 x64. 
3) К моменту запуска функциональных тестов, многофаловый проект должен быть собран утилитой make
-----------------------------
Positive tests
-----------------------------
  Классы эквивалентности
    test_1. Замена aa на bbb в 1 строке
    test_2. Замена aa на bbb в нескольких строках
    test_3. Замена 123 на 000
    test_4. Замена точки на запятую

-----------------------------
:start_positive_tests
@echo off
Setlocal EnableDelayedExpansion
set /a result = 0
set /a errors = 0
set /a memory_errors = 0
xcopy "%CD%\..\app.exe" "%CD%" /y
for /L %%i in (1,1,2) do (
    app.exe in_%%i.txt out_%%i.txt –s aa –r bbb 
    if %errorlevel% NEQ 0 (
        set /a errors += 1
    )
	drmemory -batch -exit_code_if_errors <-9> -quiet -logdir %CD% -- ./app.exe in_%%i.txt out_%%i.txt –s aa –r bbb 
    if %errorlevel% NEQ 0 (
      set /a memory_errors += 1
    )
    fc /B "out_%%i.txt" "res_%%i.txt"
    rem echo %%i - OK || echo %%i - FAIL //показывает какие именно тесты прошли
)
for /L %%i in (3,1,2) do (
    app.exe in_%%i.txt out_%%i.txt –s 123 –r 000 
    if %errorlevel% NEQ 0 (
        set /a errors += 1
    )
	drmemory -batch -exit_code_if_errors <-9> -quiet -logdir %CD% -- ./app.exe in_%%i.txt out_%%i.txt –s 123 –r 000 
    if %errorlevel% NEQ 0 (
      set /a memory_errors += 1
    )
    fc /B "out_%%i.txt" "res_%%i.txt"
    rem echo %%i - OK || echo %%i - FAIL //показывает какие именно тесты прошли
)
for /L %%i in (5,1,2) do (
    app.exe in_%%i.txt out_%%i.txt –s . –r , 
    if %errorlevel% NEQ 0 (
        set /a errors += 1
    )
	drmemory -batch -exit_code_if_errors <-9> -quiet -logdir %CD% -- ./app.exe in_%%i.txt out_%%i.txt –s . –r , 
    if %errorlevel% NEQ 0 (
      set /a memory_errors += 1
    )
    fc /B "out_%%i.txt" "res_%%i.txt"
    rem echo %%i - OK || echo %%i - FAIL //показывает какие именно тесты прошли
)
cls
if (%errors% EQU 0) (
    echo Positive test ERROR 
) else (
    echo Positive test passed. 
    set /a result += 1
)
echo Start negative tests...

goto start_negative_tests
-----------------------------
Negative tests
-----------------------------
  Классы эквивалентности
    test_1. Кол-во аргументов меньше 7
    test_2. Файл 1 не может быть открыт
    test_3. Файл 2 не может быть открыт
    test_4. Считывание пустого файла №1

-----------------------------
:start_negative_tests
set /a errors = 0
rem test_1: Кол-во аргументов меньше 7
app.exe  in_1.txt 
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe in_1.txt 
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_2: Файл 1 не может быть открыт
app.exe in_00.txt out_6.txt 
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe in_00.txt out_6.txt 
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_3: Файл 2 не может быть создан
app.exe in_1.txt out 
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe in_1.txt out  
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_4: Считывание пустого файла №1
app.exe in_6.txt out_6.txt
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe in_6.txt out_6.txt
if %errorlevel% NEQ 0 (set /a memory_errors += 1)
cls
echo -----------------------------
if "%result%" == "1" (echo Positive tests OK) else (echo Positive tests FAIL) 
if "%errors%" == "4" (echo Negative tests OK) else (echo Negative tests: %errors% of 18)
echo -----------------------------

echo -----------------------------
if "%memory_errors%" == "0" (echo Memory tests OK) else (echo Memory tests FAIL. Count memory errors: %memory_errors%)
echo -----------------------------

pause

call start_clean.bat


	