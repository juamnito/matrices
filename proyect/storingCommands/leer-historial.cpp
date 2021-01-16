#include <iostream>
#include <stdlib.h>

#include <fstream>      // Escritura de archivos de texto

using namespace std;

void lectura( ){
    ifstream historial;

    historial.open( "historial-comandos/historial-comandos.txt", ios :: in ); 
                                                                // modo lectura
    
    if( historial.fail( ) ){
        cout << "Archivo no se pudo leer";
        exit( 1 );
    }

    string texto_del_historial;

    while ( ! historial.eof( ) ){
        getline( historial, texto_del_historial );

        cout << texto_del_historial;

    }


}

int main( void ){
    lectura( );

    return 0;
}
