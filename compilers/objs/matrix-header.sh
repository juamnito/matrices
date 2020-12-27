#!/bin/bash

cd ~/Proyectos/c++/matrices

echo -e "\e[1m-- matrix.hpp.gch\e[0m"
if g++ -H -c src/matrix.hpp > logs/src/Matrix-Header-Log.txt 2>&1 ; then
    # cat logs/src/Matrix-Header-Log.txt
    echo -e "   [\e[34m\e[1mDONE\e[0m]"
 else 
    cat logs/src/Matrix-Header-Log.txt
    echo -e "   [\e[31m\e[1mFINISHED WITH ERROR\e[0m]" 
fi
