cd build
cmake -G "Visual Studio 14" ../
mkdir Debug
mkdir Release
copy ..\lib\_bin\ Debug
copy ..\lib\_bin\ Release
move ..\res res
