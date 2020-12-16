#include <iostream>
#include "matrix.hpp"

using namespace std;

// CONSTRUCTORS

Matrix :: Matrix( int m_, int n_ ) {
    SetDimentions( m_, n_ );
}

Matrix :: Matrix( ){
    A = NULL;
    n = 0;
    m = 0;
}

// DESTRUCTOR

Matrix :: ~ Matrix( ){
    Delete( );
}

// PRINT

void Matrix :: Print( void ) const {
    for( int i = 0; i < m; i ++ ){
        for( int j = 0; j < n; j ++ ){
            cout << " " << A[ j ][ i ] << " ";
        }
        cout << endl;
    }
}
