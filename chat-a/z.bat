cls
::@echo off

@set SOURCES=main.c trx_socket_low.c
@set OUT_EXE=zz.exe
@set DEFINES=
@set LIBS=
@set LIBDIR=
@set INCLUDEDIR=
@set OPTIONS=-Wall -Wextra -Wpedantic -O2

del zz.exe
gcc -o %OUT_EXE% %SOURCES% -I%INCLUDEDIR% -L%LIBDIR% %INCLUDES% %LIBS% %OPTIONS% -lwsock32
zz.exe


