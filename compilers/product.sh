#!/bin/bash
# compiling the determinant program

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

echo -e "[COMPILING \e[33m\e[1mPRODUCT\e[0m TEST]"
if g++ -o executables/tests/product.exe tests/mainProduct.cpp objects/ob-src/* > logs/tests/Product-Log.txt 2>&1 ; then
    cat logs/tests/Product-Log.txt
    echo -e "[\e[34m\e[1mDONE\e[0m]"
else 
    cat logs/tests/Product-Log.txt
    echo -e "[\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi
