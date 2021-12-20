@echo off
set /a nul = 0
set /a B = %1
set /a four=%B% %% 4
set /a fourhun=%B% %% 400
set /a hun=%B% %% 100
if %four% equ %nul% (goto step2) else (goto notleap)

:step2
if %hun% neq %nul% (goto isleap) else (goto step3)

:step3
if %fourhun% equ %nul% (goto isleap) else (goto notleap)

:isleap
echo %1 is a leap year
goto stop

:notleap
echo %1 is NOT a leap year
:stop
