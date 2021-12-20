@echo off
mkdir %1
mkdir %1\\algem
mkdir %1\\mathAnalysis
mkdir %1\\BasicsOfProgramming
mkdir %1\\discreteMath
echo Преподаватель: Погожев Сергей Владимирович > %1\\algem\\readme.txt
echo Начало занятий: %date% >> %1\\algem\\readme.txt
rem 1
echo Преподаватель: Платонов Алексей Викторович. > %1\\mathanalysis\\readme.txt 
echo Начало занятий: %date% >> %1\\mathanalysis\\readme.txt
rem 2
echo Преподаватель: Погожев Сергей Владимирович. > %1\\BasicsOfProgramming\\readme.txt 
echo Начало занятий: %date% >> %1\\BasicsOfProgramming\\readme.txt
rem 3
echo Преподаватель: Погожев Сергей Владимирович. > %1\\discretemath\\readme.txt 
echo Начало занятий: %date% >> %1\\discreteMath\\readme.txt
rem 4
copy op.bat %1\\BasicsOfProgramming
rem 5
copy algem.bat %1\\algem
