#include <iostream>
#include <string>

#include <stdlib.h>

#include <fstream>      // Escritura de archivos de texto

using namespace std;


void SaveCommand( const string & command_ ){
    ofstream historial;

    const string existe_historial = 
        "                                           \
        if [ ! -d historial-comandos ] ; then       \
            mkdir historial-comandos                \
        fi                                          \n\
        if [ ! -f historial-comandos/historial-comandos.txt ] ; then    \
            touch historial-comandos/historial-comandos.txt             \
        fi                                                              \
        ";

    system( existe_historial.c_str( ) );

    historial.open( "historial-comandos/historial-comandos.txt", ios :: out | ios :: app );
                                                                // modo de adición al texto existente

    if( historial.fail( ) ){
        cout << "No se pudo crear el historial de comandos.\n";
        exit( 1 );
    }

    

    historial << command_.c_str( );
    historial.close( );
}

int main( void ){

    int u = 0;
    cout << u ; 
    string command = "Hola";

    while( command != "adios" ){
        getline( cin, command );

        SaveCommand( command );
    
    }

    return 0;
}

    
