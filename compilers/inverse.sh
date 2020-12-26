#!/bin/bash
# compiling the determinant program

cd ~/Proyectos/c++/matrices

if [ ! -d executables ] ; then
    mkdir executables
fi

echo -e "[COMPILING \e[33m\e[1mINVERSE\e[0m TEST]"
if g++ -o executables/inverse tests/inverse.cpp objects/* > logs/Inverse-Log.txt 2>&1 ; then
    cat logs/Inverse-Log.txt
    echo -e "[\e[34m\e[1mDONE\e[0m]"
else 
    cat logs/Inverse-Log.txt
    echo -e "[\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi
