@echo off
setlocal enableextensions enabledelayedexpansion

set target_src_dir=../
set target=test_stb_ds
set target_include=
set target_src=
set target_lib=
set target_flags=
set compiler=cl
set configuration=debug
REM  set verbose=/VERBOSE
set verbose=

set target_c=!target_src_dir!\!target!.c
set target_exe=!target!.exe

if not exist bin mkdir bin

echo -------------------------------------------------
echo - Compiler:      %compiler%
echo - Include:       %include_dirs%
echo - Configuration: %configuration%
echo - Target C:      %target%.c
echo - Output:        bin\%target_exe%
echo -------------------------------------------------

rem MT for statically linked CRT, MD for dynamically linked CRT
set win_runtime_lib=MDd
set common_c=!target_c! !target_tests! !target_src! /Fe!target_exe! -nologo !target_flags! -FC -EHa- !target_include!
set common_l=!verbose! !target_lib!

echo.
echo Compiling...
pushd bin
    cl -TC !common_c! -!win_runtime_lib! -Od /Z7 /link !common_l!
    if "%ERRORLEVEL%" EQU "0" (
        goto good
    )
    if "%ERRORLEVEL%" NEQ "0" (
        goto bad
    )
:good
    echo.
    xcopy !target_exe! ..\build /i /y
    echo Running !target_exe!...
    echo.
    !target_exe!
    goto done
:bad
    echo FAILED
    goto done
:done

popd

:end
