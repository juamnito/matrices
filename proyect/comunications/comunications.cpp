#include "comunications.hpp"

bool Exit( const std :: string & command_ ){
    std :: vector <std :: string> byes = {
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

    for( std :: vector <std :: string> :: iterator  bye = byes.begin( ); bye != byes.end( ); ++ bye ){
        if( command_ == * bye ){
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

void ShowMainMenu( ){
    std :: cout << "\t\t-- Main Menu --\n";
    std :: cout << "1. Print menu \t\t Command: main-menu\n";
    std :: cout << "2. Exit \t\t Command: exit\n";
    std :: cout << "3. Clear screen \t Command: clear\n";

    std :: cout << std :: endl;
}

/// Get Command and lower case

void GetCommand( std :: string & command_ ){
    std :: cout << prompt.normalString;
    getline( std :: cin, command_ );

    std :: transform( command_.begin( ), command_.end( ), command_.begin( ), [ ]( unsigned char c ){ 
        return std::tolower( c ); 
    });
}

void Error( std :: string & command ){
    std :: cout << "[Error: command \"" << command << "\" unknown]\n";
    // std :: cout << "Do you want to run it in the shell? [ y / N ] ";
    // std :: string ans;
    // 
    // getline( std :: cin, ans );

    //     // Convierte a toda la cadena en minúsculas
    //     
    // std :: transform( ans.begin( ), ans.end( ), ans.begin( ), [ ]( unsigned char c ){ 
    //     return std::tolower( c ); 
    // });

    // if( ans == "y" or ans == "yes" ){
    //     system( command.c_str( ) );
    // }
    // else if( ans != "n" or ans != "no" ){
    //     std :: cout << "Booo bitch!\n";
    // }
}
