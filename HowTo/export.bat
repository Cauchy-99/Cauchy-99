echo %~dp0

set HowTo_DEBUG=debug_vc141_64
set HOWTo_RELEAS=releas_vx141_64

echo Export pulic headers
if not exist %HowTo_ROOT%\include\howto (
	md %HowTo_ROOT%\include\howto
)

echo copy %~dp0include\*.h
cd %~dp0include
copy /y *.h %HowTo_ROOT%\include\howto