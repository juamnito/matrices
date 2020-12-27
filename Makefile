# Compilación de tests
executables/tests: executables/tests/product.exe executables/tests/latex.exe executables/tests/inverse.exe executables/tests/determinant.exe

# Reglas para compilación de tests
executables/tests/product.exe: objects/ob-src/ tests/mainProduct.cpp compilers/tests/product.sh
	@./compilers/tests/product.sh

executables/tests/latex.exe: objects/ob-src/ tests/latex.cpp tests/latex.hpp tests/latexMain.cpp compilers/tests/latex.sh
	@./compilers/tests/latex.sh

executables/tests/inverse.exe: objects/ob-src/ tests/inverse.cpp compilers/tests/inverse.sh
	@./compilers/tests/inverse.sh

executables/tests/determinant.exe: objects/ob-src/ tests/determinant.cpp compilers/tests/determinant.sh
	@./compilers/tests/determinant.sh

# Compilación de objetos
objects/ob-src/: src/matrix.hpp.gch objects/ob-src/matrix.o objects/ob-src/elementaryOperations.o objects/ob-src/gettersAndSetters.o objects/ob-src/operations.o objects/ob-src/settingMatrix.o 

# Reglas para compilación de cada objeto
objects/ob-src/settingMatrix.o: src/settingMatrix.cpp src/matrix.hpp compilers/ob-src/settingMatrix.sh
	@./compilers/ob-src/settingMatrix.sh

objects/ob-src/operations.o: src/operations.cpp src/matrix.hpp compilers/ob-src/operations.sh
	@./compilers/ob-src/operations.sh

objects/ob-src/gettersAndSetters.o: src/gettersAndSetters.cpp src/matrix.hpp compilers/ob-src/gettersAndSetters.sh
	@./compilers/ob-src/gettersAndSetters.sh

objects/ob-src/elementaryOperations.o: src/elementaryOperations.cpp src/matrix.hpp compilers/ob-src/elementaryOperations.sh
	@./compilers/ob-src/elementaryOperations.sh

objects/ob-src/matrix.o: src/matrix.cpp src/matrix.hpp compilers/ob-src/matrix.sh
	@./compilers/ob-src/matrix.sh

# Precompiled header
src/matrix.hpp.gch: src/matrix.hpp compilers/ob-src/matrix-header.sh
	@./compilers/ob-src/matrix-header.sh

# clean stuff
clean:
	rm -rf executables/ objects/
