goto start_summ_tests
-----------------------------
Данила Зыкин ИУ7-33
1) Функциональное тестирование суммирования, умножения матриц и нахождения определителя матрицы
2) Bat-файл написан под Windows 10 x64. 
3) К моменту запуска функциональных тестов, многофаловый проект должен быть собран утилитой make
-----------------------------
Positive tests
-----------------------------
  Тестирование суммы матриц
    Классы эквивалентности
    test_1. Сложение обычных матриц
    test_2. Матрица + нулевая матрица
    test_3. Матрица + обратная матрица
    test_4. Сложение прямоугольных матриц
    test_5. Сложение квадратных матриц
    test_6. Отрицательные матрицы
    test_7. Смешанные матрицы
-----------------------------
:start_summ_tests
@echo off
Setlocal EnableDelayedExpansion
set /a result = 0
set /a errors = 0
set /a memory_errors = 0
xcopy "%CD%\..\app.exe" "%CD%" /y
for /L %%i in (1,1,7) do (
    app.exe a in_%%i1.txt in_%%i2.txt out_%%i.txt
    if %errorlevel% NEQ 0 (
        set /a errors += 1
    )
	drmemory -batch -exit_code_if_errors <-9> -quiet -logdir %CD% -- ./app.exe a in_%%i1.txt in_%%i2.txt out_%%i.txt
    if %errorlevel% NEQ 0 (
      set /a memory_errors += 1
    )
    fc /B "out_%%i.txt" "res_%%i.txt"
    rem echo %%i - OK || echo %%i - FAIL //показывает какие именно тесты прошли
)
if (%errors% EQU 0) (
    echo Test summ ERROR 
) else (
    echo Test summ passed. 
    set /a result += 1
)
goto start_mult_tests
-----------------------------
Positive tests
-----------------------------
  Тестирование умножения матриц
    Классы эквивалентности
    test_8. Матрица[1][1] * матрица[1][1]
    test_9. Матрица * нулевая матрица
    test_10. Матрица * обратная матрица
    test_11. Разноразмерные матрицы
    test_12. Матрица * вектор
    test_13. Вектор * вектор...
-----------------------------
:start_mult_tests

set /a errors = 0
for /L %%i in (8,1,12) do (
    app.exe m in_%%i1.txt in_%%i2.txt out_%%i.txt
    if %errorlevel% NEQ 0 (
        set /a errors += 1
    )
	drmemory -batch -exit_code_if_errors <-9> -quiet -logdir %CD% -- ./app.exe m in_%%i1.txt in_%%i2.txt out_%%i.txt
    if %errorlevel% NEQ 0 (
      set /a memory_errors += 1
    )
    fc /B "out_%%i.txt" "res_%%i.txt"
)
if (%errors% EQU 0) (
    echo Test multiplication ERROR 
) else (
    echo Test multiplication passed. 
    set /a result += 1
)

goto start_determ_tests
-----------------------------
Positive tests
-----------------------------
  Тестирование умножения матриц
    Классы эквивалентности
    test_13. Матрица[2][2]
    test_14. Единичная матрица
    test_15. Матрица[N][N]
    test_16. Транспонированная матрица [N][N]
    test_17. Матрица первого порядка
    test_18. Нулевая матрица
// 4. NxM - невозможно по вызову функции
// 6. 0x0
-----------------------------
:start_determ_tests

set /a errors = 0
for /L %%i in (13,1,18) do (
    app.exe o in_%%i1.txt out_%%i.txt
    if %errorlevel% NEQ 0 (
        set /a errors += 1
    )
	drmemory -batch -exit_code_if_errors <-9> -quiet -logdir %CD% -- ./app.exe a in_%%i1.txt out_%%i.txt
    if %errorlevel% NEQ 0 (
      set /a memory_errors += 1
    )
    fc /B "out_%%i.txt" "res_%%i.txt"
)
if (%errors% EQU 0) (
    echo Test determination ERROR 
) else (
    echo Test determination passed
    set /a result += 1
)

goto start_negative_tests
-----------------------------
Negative tests
-----------------------------
  Классы эквивалентности
    test_1. Кол-во аргументов меньше 4-х
    test_2. Кол-во аргументов меньше 5-х
    test_3. Несуществующая операция
    test_4. При суммировании матриц кол-во аргументов != 5
    test_5. При умножении матриц кол-во аргументов != 5
    test_6. Файл 1 не может быть открыт
    test_7. Файл 2 не может быть открыт
    test_8. Файл 3 не может быть создан
    test_9. Считывание пустого файла №1
    test_10. Считывание пустого файла №2
    test_11. В файле №1 считалось меньше значений, чем размер матрицы
    test_12. В файле №2 считалось меньше значений, чем размер матрицы
    test_13. Матрицы разного порядка (сложение)
    test_14. Матрицы, где число столбцов != числу строк (умножение)
    test_15. При вычислении определителя кол-во аргументов != 4
    test_16. Файл 1 не может быть открыт
    test_17. В файле считалось меньше значений, чем размер матрицы
    test_18. Размер матрицы < 1
	test_19. Вектор * вектор
-----------------------------
:start_negative_tests
set /a errors = 0

rem test_1: Кол-во аргументов меньше 4-х
app.exe o in_11.txt 
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe o in_11.txt 
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_2:Кол-во аргументов меньше 5-х
app.exe m a o in_11.txt in_12.txt 
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe m a o in_11.txt in_12.txt  
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_3: Несуществующая операция
app.exe e in_11.txt in_12.txt res.txt
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe e in_11.txt in_12.txt res.txt
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_4: При суммировании матриц кол-во аргументов != 5
app.exe a in_11.txt in_12.txt res.txt res2.txt
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe a in_11.txt in_12.txt res.txt res2.txt
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_5: При умножении матриц кол-во аргументов != 5
app.exe m in_11.txt in_12.txt res.txt res2.txt
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe m in_11.txt in_12.txt res.txt res2.txt
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_6: Файл 1 не может быть открыт
app.exe m in_00.txt in_12.txt res.txt 
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe m in_00.txt in_12.txt res.txt  
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_7: Файл 2 не может быть открыт
app.exe m in_11.txt in_00.txt res.txt 
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe m in_11.txt in_00.txt res.txt  
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_8: Файл 3 не может быть создан
app.exe m in_11.txt in_11.txt res_19 
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe m in_11.txt in_11.txt res_19 
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_9: Считывание пустого файла №1
app.exe m in_191.txt in_11.txt res.txt
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe m in_191.txt in_11.txt res.txt
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_10. Считывание пустого файла №2
app.exe m in_11.txt in_191.txt res.txt
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe m in_11.txt in_191.txt res.txt
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_11. В файле №1 считалось меньше значений, чем размер матрицы
app.exe m in_201.txt in_11.txt res.txt
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe m in_201.txt in_11.txt res.txt 
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_12. В файле №2 считалось меньше значений, чем размер матрицы
app.exe m in_201.txt in_11.txt res.txt
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe m in_201.txt in_11.txt res.txt
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_13. Матрицы разного порядка (сложение)
app.exe a in_211.txt in_212.txt res.txt
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe a in_211.txt in_212.txt res.txt
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_14. Матрицы, где число столбцов != числу строк (умножение)
app.exe m in_221.txt in_222.txt res.txt
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe m in_221.txt in_222.txt res.txt
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_15. При вычислении определителя кол-во аргументов != 4
app.exe o in_211.txt in_212.txt res.txt
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe o in_211.txt in_212.txt res.txt
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_16.  Файл 1 не может быть открыт
app.exe o in_00.txt in_212.txt
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe o in_00.txt in_212.txt 
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_17. В файле считалось меньше значений, чем размер матрицы
app.exe o in_201.txt out_19.txt
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe o in_201.txt out_19.txt
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_18. Размер матрицы < 1
app.exe o in_231.txt out_19.txt
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe o in_231.txt out_19.txt
if %errorlevel% NEQ 0 (set /a memory_errors += 1)

rem test_19. Вектор * вектор
app.exe m in_241.txt in_242.txt out_19.txt
if %errorlevel% NEQ 0 (set /a errors += 1)
drmemory -batch -summary -results_to_stderr -exit_code_if_errors 2 -crash_at_error -crash_at_unaddressable  -quiet -logdir %CD% -- ./app.exe m in_241.txt in_242.txt out_19.txt
if %errorlevel% NEQ 0 (set /a memory_errors += 1)
cls
echo -----------------------------
if "%result%" == "3" (echo Positive tests OK) else (echo Positive tests FAIL) 
if "%errors%" == "19" (echo Negative tests OK) else (echo Negative tests: %errors% of 18)
echo -----------------------------

echo -----------------------------
if "%memory_errors%" == "0" (echo Memory tests OK) else (echo Memory tests FAIL. Count memory errors: %memory_errors%)
echo -----------------------------

DEL app.exe res_19 res.txt

pause

call start_clean.bat


	