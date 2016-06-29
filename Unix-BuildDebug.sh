#This version of the build script is hardcoded to the debug version so
#it can be used by the Makefile
cd build
cmake -DCMAKE_BUILD_TYPE="Debug" ../
make -j 4
mv ../res/ ./
