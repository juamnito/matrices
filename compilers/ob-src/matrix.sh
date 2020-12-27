#!/bin/bash

cd ~/Proyectos/c++/matrices

if [ ! -d objects ] ; then
    mkdir objects
fi
if [ ! -d objects/ob-src ] ; then
    mkdir objects/ob-src
fi

if [ ! -d logs ] ; then
    mkdir logs
fi
if [ ! -d logs/src ] ; then
    mkdir logs/src
fi
 
# echo -e "[MAKING \e[35m\e[1;4mOBJECT FILES\e[0m]"
echo -e "\e[1m-- matrix.o\e[0m"
if g++ -H -c src/matrix.cpp -o objects/ob-src/matrix.o > logs/src/Matrix-O-Log.txt 2>&1 ; then
    # cat logs/src/Matrix-O-Log.txt
    echo -e "   [\e[34m\e[1mDONE\e[0m]"
 else 
    cat logs/src/Matrix-O-Log.txt
    echo -e "   [\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi

