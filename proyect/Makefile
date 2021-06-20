all: main.exe historial.exe leer-historial.exe

main.exe: main.cpp comunications.o
	g++ -o main.exe main.cpp comunications.o

comunications.o: comunications/comunications.hpp.gch comunications/comunications.cpp
	g++ -c comunications/comunications.cpp

comunications/comunications.hpp.gch: comunications/comunications.hpp
	g++ -c comunications/comunications.hpp

# historial.exe: historial.cpp
# 	g++ -o historial.exe historial.cpp

leer-historial.exe: leer-historial.cpp
	g++ -o leer-historial.exe leer-historial.cpp

clean:
	rm -f *.o */*.gch *.exe

