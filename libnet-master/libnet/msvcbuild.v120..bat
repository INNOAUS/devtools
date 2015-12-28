@rem Script to build libnet under "Visual Studio .NET Command Prompt".
@rem Dependencies are:
@rem   winpcap, specifically, the winpcap developer pack

@setlocal
@set MYCOMPILE=cl /nologo /MD /O2 /W3 /c /D_CRT_SECURE_NO_DEPRECATE
@set MYLIB=LIB  /NOLOGO 
@set MYLINK=link /nologo
@set MYMT=mt /nologo

copy win32\libnet.h include\
copy win32\stdint.h include\libnet\
copy win32\config.h include\
copy win32\getopt.h include\

cd src
%MYCOMPILE% /I..\include /I%WPCAP_ROOT%\Include libnet_a*.c libnet_build_*.c libnet_c*.c libnet_dll.c libnet_error.c libnet_i*.c libnet_link_win32.c libnet_p*.c libnet_raw.c libnet_resolve.c libnet_version.c libnet_write.c
@REM  %MYLINK% /DLL /libpath:%WPCAP_ROOT%\Lib\x64  /out:libnet.dll *.obj Advapi32.lib
%MYLIB% /OUT:"..\lib\libnet.Win32.v120.lib" libnet_a*.obj libnet_build_*.obj libnet_c*.obj libnet_error.obj libnet_i*.obj libnet_link_win32.obj libnet_p*.obj libnet_raw.obj libnet_resolve.obj libnet_version.obj libnet_write.obj

@rem if exist libnet.dll.manifest^
@rem   %MYMT% -manifest libnet.dll.manifest -outputresource:libnet.dll;2
 
 
 @setlocal
@set MYCOMPILE=cl /nologo /MD /O2 /W3 /c /D_CRT_SECURE_NO_DEPRECATE /D_DEBUG
@set MYLIB=LIB  /NOLOGO 
@set MYLINK=link /nologo
@set MYMT=mt /nologo

%MYCOMPILE% /I..\include /I%WPCAP_ROOT%\Include libnet_a*.c libnet_build_*.c libnet_c*.c libnet_dll.c libnet_error.c libnet_i*.c libnet_link_win32.c libnet_p*.c libnet_raw.c libnet_resolve.c libnet_version.c libnet_write.c
@REM  %MYLINK% /DLL /libpath:%WPCAP_ROOT%\Lib\x64  /out:libnet.dll *.obj Advapi32.lib
%MYLIB% /OUT:"..\lib\libnetd.Win32.v120.lib" libnet_a*.obj libnet_build_*.obj libnet_c*.obj libnet_error.obj libnet_i*.obj libnet_link_win32.obj libnet_p*.obj libnet_raw.obj libnet_resolve.obj libnet_version.obj libnet_write.obj

@rem if exist libnet.dll.manifest^
@rem   %MYMT% -manifest libnet.dll.manifest -outputresource:libnet.dll;2



@setlocal
@set MYCOMPILE=cl /nologo /MD /O2 /W3 /c /D_CRT_SECURE_NO_DEPRECATE
@set MYLIB=LIB  /MACHINE:X64 /NOLOGO 
@set MYLINK=link /nologo
@set MYMT=mt /nologo


%MYCOMPILE% /I..\include /I%WPCAP_ROOT%\Include libnet_a*.c libnet_build_*.c libnet_c*.c libnet_dll.c libnet_error.c libnet_i*.c libnet_link_win32.c libnet_p*.c libnet_raw.c libnet_resolve.c libnet_version.c libnet_write.c
@REM  %MYLINK% /DLL /libpath:%WPCAP_ROOT%\Lib\x64  /out:libnet.dll *.obj Advapi32.lib
%MYLIB% /OUT:"..\lib\libnet.x64.v120.lib" libnet_a*.obj libnet_build_*.obj libnet_c*.obj libnet_error.obj libnet_i*.obj libnet_link_win32.obj libnet_p*.obj libnet_raw.obj libnet_resolve.obj libnet_version.obj libnet_write.obj

@rem if exist libnet.dll.manifest^
@rem   %MYMT% -manifest libnet.dll.manifest -outputresource:libnet.dll;2



@setlocal
@set MYCOMPILE=cl /nologo /MD /O2 /W3 /c /D_CRT_SECURE_NO_DEPRECATE /D_DEBUG
@set MYLIB=LIB  /MACHINE:X64 /NOLOGO 
@set MYLINK=link /nologo
@set MYMT=mt /nologo

%MYCOMPILE% /I..\include /I%WPCAP_ROOT%\Include libnet_a*.c libnet_build_*.c libnet_c*.c libnet_dll.c libnet_error.c libnet_i*.c libnet_link_win32.c libnet_p*.c libnet_raw.c libnet_resolve.c libnet_version.c libnet_write.c
@REM  %MYLINK% /DLL /libpath:%WPCAP_ROOT%\Lib\x64  /out:libnet.dll *.obj Advapi32.lib
%MYLIB% /OUT:"..\lib\libnetd.x64.v120.lib" libnet_a*.obj libnet_build_*.obj libnet_c*.obj libnet_error.obj libnet_i*.obj libnet_link_win32.obj libnet_p*.obj libnet_raw.obj libnet_resolve.obj libnet_version.obj libnet_write.obj

@rem if exist libnet.dll.manifest^
@rem   %MYMT% -manifest libnet.dll.manifest -outputresource:libnet.dll;2


cd ..

exit /b %errorlevel%

