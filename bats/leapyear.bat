@echo off
set /a nul = 0
set /a B = %1
set /a four=%B% %% 4
set /a fourhun=%B% %% 400
set /a hun=%B% %% 100
if %four% equ %nul% (goto stage2) else (goto notleap)
:stage2
if %hun% neq %nul% (goto isleap) else (goto stage3)

:isleap
echo %1 is a leap year
goto break

:stage3
if %fourhun% equ %nul% (goto isleap) else (goto notleap)

:notleap
echo %1 is NOT a leap year
:break
