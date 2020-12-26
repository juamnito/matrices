#include <iostream>
#include <string>

// Lowercase string
#include <algorithm>
#include <cctype>

#include "../src/matrix.hpp"

bool Exit( const std :: string & command_ ){
    std :: string byes[ 10 ] = {
        "quit",
        "quit()",
        "q()",
        "q",
        "exit",
        "exit()",
        "break",
        "break",
        "bye",
        "adios"
    };

    for( int i = 0; i < 10; i ++ ){
        if( command_ == byes[ i ] ){
            return true;
        }
    }
    
    return false;
}

void Greetings( ){
    std :: cout << "Hello this is linux-matrix-calculator from ChicomeCipactli.\n" ;
    std :: cout << "-- GitHub: https://github.com/ChicomeCipactli/matrices.git\n\n" ;
    std :: cout << "I can help you to play with the math behind arrays\n\n" ;

}

bool ClearScreen( const std :: string & command_ ){
    std :: string clears[ 2 ] = {
        "clear",
        "cls"
    };
    for( int i = 0; i < 2; i ++ ){
        if( command_ == clears[ i ] ){
            std :: system( "clear" );
            return true;
        }
    }
    return false;
}

void MainMenu( ){
    std :: cout << "\t\t-- Main Menu --\n";
    std :: cout << "1. Print menu \t\t Command: main-menu\n";
    std :: cout << "2. Exit \t\t Command: exit\n";
    std :: cout << "3. Clear screen \t Command: clear\n";

    std :: cout << std :: endl;
}


/// Get Command and lower case

void GetCommand( std :: string & command_ ){
    std :: cout << "> ";
    std :: cin >> command_;

    std :: transform( command_.begin( ), command_.end( ), command_.begin( ), [ ]( unsigned char c ){ 
        return std::tolower( c ); 
    });
}

int main( void ){
    
    std :: string command = "hi";

    Greetings( );

    MainMenu( );

    do{
        GetCommand( command );

        if( ClearScreen( command ) ){
            continue;
        }
        else if( Exit( command ) ){
            std :: cout << "Adios\n";
        }
        else if( command == "main-menu" ){
            MainMenu( );
        }
        else {
            std :: cout << "[Error: command \"" << command << "\" unknown]\n";
        }
    } while( ! Exit( command ) );
       
    return 0;
}

