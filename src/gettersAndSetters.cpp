#include "matrix.hpp"

double Matrix :: GetIndex( int i, int j ) const {

    if( i >= m )
        i = m - 1;
    else if( i < 0 )
        i = 0;
    if( j >= n )
        j = n - 1;
    else if( j < 0 )
        j = 0;

    if( n == 0 or m == 0 ){
        return 0;
    }

    return A[ j ][ i ];
}

void Matrix :: SetIndex( int i, int j, const double val ){
    if( i < 0 or i > m - 1 ){
        return;
    }
    
    if( j < 0 or j > n - 1 ){
        return;
    }
    A[ j ][ i ] = val;
}

int Matrix :: GetN( ) const {
    return n;
}

int Matrix :: GetM( ) const {
    return m;
}

double ** Matrix :: GetMatrix( void ) const {
    double ** arr = new double * [ n ];

    arr = new double * [ n ];

    for( int column = 0; column < n; column ++ ){
        arr[ column ] = new double [ m ];
        for( int row = 0; row < m; row ++ ){
            arr[ column ][ row ] = A[ column ][ row ];
        }
    }

    return arr;
}
