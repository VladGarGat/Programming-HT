@echo off
set /a i = 0
:begin
set /a i = i + 1
set /a sqr = i * i
set /a modulo = %sqr% %% 1000000
if %modulo% equ 269696 (goto end) else (goto begin)

:end
echo %i%
