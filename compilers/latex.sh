#!/bin/bash
#+ Command to compile c++ program.

cd ~/Proyectos/c++/matrices

echo -e "[COMPILING \e[33m\e[1mLATEX\e[0m TEST]"
if g++ -o executables/latex tests/latexMain.cpp tests/latex.cpp tests/latex.hpp src/matrix.hpp src/matrix.cpp src/elementaryOperations.cpp src/gettersAndSetters.cpp src/operations.cpp src/settingMatrix.cpp > logs/Latex-Log.txt 2>&1 ; then
    cat logs/Latex-Log.txt
    echo -e "[\e[34m\e[1mDONE\e[0m]"
else 
    cat logs/Latex-Log.txt
    echo -e "[\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi


