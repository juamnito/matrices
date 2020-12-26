#!/bin/bash

cd ~/Proyectos/c++/matrices

if [ ! -d objects ] ; then
    mkdir objects
fi

echo -e "[MAKING \e[35m\e[1;4mOBJECT FILES\e[0m]"
echo -e "\e[1m-- matrix.o\e[0m"
if g++ -c src/matrix.hpp src/matrix.cpp > logs/Matrix-Log.txt 2>&1 ; then
    cat logs/Matrix-Log.txt
    echo -e "\t[\e[34m\e[1mDONE\e[0m]"
 else 
    cat logs/Matrix-Log.txt
    echo -e " \t[\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi

echo -e "\e[1m-- gettersAndSetters.o\e[0m"
if g++ -c src/matrix.hpp src/gettersAndSetters.cpp > logs/GettersAndSetters-Log.txt 2>&1 ; then
    cat logs/GettersAndSetters-Log.txt
    echo -e "\t[\e[34m\e[1mDONE\e[0m]"
 else 
    cat logs/GettersAndSetters-Log.txt
    echo -e "\t[\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi

echo -e "\e[1m-- elemetaryOperations.o\e[0m"
if g++ -c src/matrix.hpp src/elementaryOperations.cpp > logs/ElementaryOperations-Log.txt 2>&1 ; then
    cat logs/ElementaryOperations-Log.txt
    echo -e "\t[\e[34m\e[1mDONE\e[0m]"
 else 
    cat logs/ElementaryOperations-Log.txt
    echo -e "\t[\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi

echo -e "\e[1m-- operations.o\e[0m"
if g++ -c src/matrix.hpp src/operations.cpp > logs/Operations-Log.txt 2>&1 ; then
    cat logs/Operations-Log.txt
    echo -e "\t[\e[34m\e[1mDONE\e[0m]"
 else 
    cat logs/Operations-Log.txt
    echo -e "\t[\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi

echo -e "\e[1m-- settingMatrix.o\e[0m"
if g++ -c src/matrix.hpp src/settingMatrix.cpp > logs/SettingMatrix-Log.txt 2>&1 ; then
    cat logs/SettingMatrix-Log.txt
    echo -e "\t[\e[34m\e[1mDONE\e[0m]"
 else 
    cat logs/SettingMatrix-Log.txt
    echo -e "\t[\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi

mv *.o objects
