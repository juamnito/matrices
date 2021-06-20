#ifndef STD
#define STD

    #include <iostream>
    #include <vector>

    // Lowercase string
    #include <algorithm>
    #include <cctype>

#endif

#ifndef MATRIX_H
#define MATRIX_H

    #include "../../src/matrix.hpp"

#endif

#ifndef CONFIG
#define CONFIG
    
    #include "prompt.hpp"
    Prompt prompt;

#endif

#ifndef COMUNICATIONS_H
#define COMUNICATIONS_H

    bool Exit( const std :: string & command_ );
    void Greetings( );

    bool ClearScreen( const std :: string  & command_ );
    void ShowMainMenu( );
    void GetCommand( std :: string & command_ );
    void Error( std :: string & command );

#endif
