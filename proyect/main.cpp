// #include <iostream>
#include <string>
#include <vector>

// type of variable
#include <typeinfo>

#include "comunications/comunications.hpp"

int main( void ){
    
    std :: string command = "hi";

    Greetings( );
    ShowMainMenu( );

    do{
        GetCommand( command );

        if( ClearScreen( command ) ){
            continue;
        }
        else if( Exit( command ) ){
            std :: cout << "Adios\n";
            // return 0;
            break;
        }
        else if( command == "main-menu" or command == "help" or command == "h" ){
            ShowMainMenu( );
        }
        else if( command[ 0 ] == ':' ){
            command.erase( 0, 1 );
            system( command.c_str( ) );
        }
        else if( command == "" ){
            continue;
        }
        else {
            Error( command );
        }
    } while( true );
       
    return 0;
}
