#include <iostream>
#include "matrix.hpp"
#include "latex.hpp"

using namespace std;

int main( void ){
    
    Matrix A;
    A.Random( 3, 3, 10, 1 );

    A.Print( );

    cout << endl << toString_LaTeX_matrix( A );

    return 0;
}

