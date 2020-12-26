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
        
echo -e "[MAKING \e[35m\e[1;4mOBJECT FILES\e[0m]"
echo -e "\e[1m-- matrix.o\e[0m"
if g++ -c src/matrix.hpp src/matrix.cpp > logs/src/Matrix-Log.txt 2>&1 ; then
    cat logs/src/Matrix-Log.txt
    echo -e "   [\e[34m\e[1mDONE\e[0m]"
 else 
    cat logs/src/Matrix-Log.txt
    echo -e "   [\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi

echo -e "\e[1m-- gettersAndSetters.o\e[0m"
if g++ -c src/matrix.hpp src/gettersAndSetters.cpp > logs/src/GettersAndSetters-Log.txt 2>&1 ; then
    cat logs/src/GettersAndSetters-Log.txt
    echo -e "   [\e[34m\e[1mDONE\e[0m]"
 else 
    cat logs/src/GettersAndSetters-Log.txt
    echo -e "   [\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi

echo -e "\e[1m-- elemetaryOperations.o\e[0m"
if g++ -c src/matrix.hpp src/elementaryOperations.cpp > logs/src/ElementaryOperations-Log.txt 2>&1 ; then
    cat logs/src/ElementaryOperations-Log.txt
    echo -e "   [\e[34m\e[1mDONE\e[0m]"
 else 
    cat logs/src/ElementaryOperations-Log.txt
    echo -e "   [\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi

echo -e "\e[1m-- operations.o\e[0m"
if g++ -c src/matrix.hpp src/operations.cpp > logs/src/Operations-Log.txt 2>&1 ; then
    cat logs/src/Operations-Log.txt
    echo -e "   [\e[34m\e[1mDONE\e[0m]"
 else 
    cat logs/src/Operations-Log.txt
    echo -e "   [\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi

echo -e "\e[1m-- settingMatrix.o\e[0m"
if g++ -c src/matrix.hpp src/settingMatrix.cpp > logs/src/SettingMatrix-Log.txt 2>&1 ; then
    cat logs/src/SettingMatrix-Log.txt
    echo -e "   [\e[34m\e[1mDONE\e[0m]"
 else 
    cat logs/src/SettingMatrix-Log.txt
    echo -e "   [\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi

mv *.o objects/ob-src
