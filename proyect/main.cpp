#include <iostream>
#include <string>
#include <vector>

// type of variable
#include <typeinfo>

#include "comunications.hpp"

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
            return 0;
        }
        else if( command == "main-menu" ){
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
            std :: cout << "[Error: command \"" << command << "\" unknown]\n";
            std :: cout << "Do you want to run it in the shell? [ y / N ] ";

            std :: string ans;
            
            getline( std :: cin, ans );

            std :: transform( ans.begin( ), ans.end( ), ans.begin( ), [ ]( unsigned char c ){ 
                return std::tolower( c ); 
            });

            if( ans == "y" or ans == "yes" ){
                system( command.c_str( ) );
            }
            else if( ans != "n" and ans != "no" ){
                std :: cout << "Booo bitch!\n";
            }
        }
    } while( true );
       
    return 0;
}

