#include <iostream>
#include "../src/matrix.hpp"

int main( ){
    
    Matrix A;
    // Matrix InvA;

    A.Random( 3, 3, 10, 0, 10 );
    InvA.Inverse( A );

    A.Print( );
    InvA.Print( );

    ( A * InvA ).Print( );
        
    
    return 0;
}
