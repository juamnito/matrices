#!/bin/bash
# compiling the determinant program

cd ~/Proyectos/c++/matrices

echo -e "[COMPILING \e[33m\e[1mDETERMINANT\e[0m TEST]"
if g++ -o executables/determinant tests/determinant.cpp src/matrix.hpp src/matrix.cpp src/settingMatrix.cpp src/gettersAndSetters.cpp src/elementaryOperations.cpp src/operations.cpp > logs/Determinant-Log.txt 2>&1 ; then
    cat logs/Determinant-Log.txt
    echo -e "[\e[34m\e[1mDONE\e[0m]"
else 
    cat logs/Determinant-Log.txt
    echo -e "[\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi
