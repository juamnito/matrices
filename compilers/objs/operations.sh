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
        
echo -e "\e[1m-- operations.o\e[0m"
if g++ -H -c src/operations.cpp > logs/src/Operations-O-Log.txt 2>&1 ; then
    # cat logs/src/Operations-O-Log.txt
    echo -e "   [\e[34m\e[1mDONE\e[0m]"
 else 
    cat logs/src/Operations-O-Log.txt
    echo -e "   [\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi

mv operations.o objects/ob-src/
