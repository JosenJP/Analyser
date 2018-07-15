set ProjectDir=H:\Coding\C++\Analyser\Analyser\Debug

set DatabaseDir=%ProjectDir%\Data\DependencyLib.db
set FileList=%ProjectDir%\Data\FileList.txt
set OutputFile=%ProjectDir%\Data\OutputFile.txt

set path=%ProjectDir%;%path%

Analyser.exe -D%DatabaseDir% -F%FileList% -O%OutputFile%
pause