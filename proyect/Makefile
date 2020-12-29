all: main.exe historial.exe leer-historial.exe

main.exe: main.cpp comunications.o
	g++ -o main.exe main.cpp comunications.o

comunications.o: comunications.hpp.gch comunications.cpp
	g++ -c comunications.cpp

comunications.hpp.gch: comunications.hpp
	g++ -c comunications.hpp

historial.exe: historial.cpp
	g++ -o historial.exe historial.cpp

leer-historial.exe: leer-historial.cpp
	g++ -o leer-historial.exe leer-historial.cpp

clean:
	rm *.o *.gch

