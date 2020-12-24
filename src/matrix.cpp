#include <iostream>
#include "matrix.hpp"

using namespace std;

/////////////////// CONSTRUCTORS ////////////////////////////////////

Matrix :: Matrix( const Matrix & copy ) {
    SetDimentions( copy.GetM( ), copy.GetN( ) );

    for( int column = 0; column < n; column ++ ){
        for( int row = 0; row < m; row ++ ){
            SetIndex( row, column, copy.GetIndex( row, column ) );
        }
    }
 
}

Matrix :: Matrix( const int m_, const int n_ ) {
    SetDimentions( m_, n_ );
}

Matrix :: Matrix( ){
    A = NULL;
    n = 0;
    m = 0;
}

/////////////////// DESTRUCTOR //////////////////////////////////////

Matrix :: ~ Matrix( ){
    Delete( );
}

/////////////////// PRINT ///////////////////////////////////////////

void Matrix :: Print( void ) const {

    for( int i = 0; i < m; i ++ ){
        for( int j = 0; j < n; j ++ ){
            cout << " " << A[ i ][ j ] << " ";
        }
        cout << endl;
    }
}

/////////////////// SWAP ///////////////////////////////////////////

void Swap( Matrix & P, Matrix & Q ){
    using std :: swap;

    swap( P.A, Q.A );
    swap( P.n, Q.n );
    swap( P.m, Q.m );
}
