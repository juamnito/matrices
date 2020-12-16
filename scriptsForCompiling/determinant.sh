#!/bin/bash
# compiling the determinant program
g++ -o executables/determinant mainProyects/determinant.cpp src/matrix.hpp src/matrix.cpp src/settingMatrix.cpp src/gettersAndSetters.cpp src/elementaryOperations.cpp src/operations.cpp
exit 0

