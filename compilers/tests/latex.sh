#!/bin/bash
#+ Command to compile c++ program.

cd ~/Proyectos/c++/matrices

if [ ! -d executables ] ; then
    mkdir executables
fi

if [ ! -d executables/tests ] ; then
    mkdir executables/tests
fi

if [ ! -d logs ] ; then 
    mkdir logs
fi
if [ ! -d logs/tests ] ; then
    mkdir logs/tests
fi


echo -e "[COMPILING \e[33m\e[1mLATEX\e[0m TEST]"
if g++ -o executables/tests/latex.exe tests/latexMain.cpp tests/latex.cpp tests/latex.hpp objects/ob-src/* > logs/tests/Latex-Log.txt 2>&1 ; then
    cat logs/tests/Latex-Log.txt
    echo -e "[\e[34m\e[1mDONE\e[0m]"
else 
    cat logs/tests/Latex-Log.txt
    echo -e "[\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi


