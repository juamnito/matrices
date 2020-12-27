SRC_OBJECTS = objects/ob-src/*

# Compilación de tests
tests: test-inverse test-determinant test-latex test-product

# Reglas para compilación de tests
test-product: making-objects tests/mainProduct.cpp compilers/tests/product.sh
	@./compilers/tests/product.sh

test-latex: making-objects tests/latex.cpp tests/latex.hpp tests/latexMain.cpp compilers/tests/latex.sh
	@./compilers/tests/latex.sh

test-inverse: making-objects tests/inverse.cpp compilers/tests/inverse.sh
	@./compilers/tests/inverse.sh

test-determinant: making-objects tests/determinant.cpp compilers/tests/determinant.sh
	@./compilers/tests/determinant.sh

# Compilación de objetos
making-objects: matrix-header.sh settingMatrix.o operations.o gettersAndSetters.o elementaryOperations.o matrix.o clean

# Reglas para compilación de cada objeto
settingMatrix.o: src/settingMatrix.cpp src/matrix.hpp compilers/objs/settingMatrix.sh
	@./compilers/objs/settingMatrix.sh

operations.o: src/operations.cpp src/matrix.hpp compilers/objs/operations.sh
	@./compilers/objs/operations.sh

gettersAndSetters.o: src/gettersAndSetters.cpp src/matrix.hpp compilers/objs/gettersAndSetters.sh
	@./compilers/objs/matrix.sh

elementaryOperations.o: src/elementaryOperations.cpp src/matrix.hpp compilers/objs/elementaryOperations.sh
	@./compilers/objs/elementaryOperations.sh

matrix.o: src/matrix.cpp src/matrix.hpp compilers/objs/matrix.sh
	@./compilers/objs/matrix.sh

matrix-header.sh: src/matrix.hpp compilers/objs/matrix-header.sh
	@./compilers/objs/matrix-header.sh

clean:
	@./compilers/objs/move-objects.sh
