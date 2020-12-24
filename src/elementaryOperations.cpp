#include "matrix.hpp"

void Matrix :: sumRow( const int i, const int to_j, const double constant ){
    if( i < 0 || i >= m || to_j < 0 || to_j >= m || constant == 0 )
        return;

    for( int column = 0; column < n; column ++ ){
        A[ to_j ][ column ] += constant * A[ i ][ column ];
    }
}

void Matrix :: sumColumn( const int i, const int to_j, const double constant ){
    if( i < 0 || i >= n || to_j < 0 || to_j >= n || constant == 0 )
        return;

    for( int row = 0; row < m; row ++ ){
        A[ row ][ to_j ] += constant * A[ row ][ i ];
    }
}

void Matrix :: exchangeColumn( const int column_0, const int column_1 ){
    if( column_0 < 0 || column_0 >= n || column_1 < 0 || column_1 >= n )
        return;

    double aux = 0;

    for( int row = 0; row < m; row ++ ){
        aux = A[ row ][ column_0 ];
        A[ row ][ column_0 ] = A[ row ][ column_1 ];
        A[ row ][ column_1 ] = aux;
    }
}

void Matrix :: exchangeRow( const int row_0, const int row_1 ){
    if( row_0 < 0 || row_0 >= m || row_1 < 0 || row_1 >= m )
        return;

    double * aux = A[ row_0 ];
    A[ row_0 ] = A[ row_1 ];
    A[ row_1 ] = aux;
}

void Matrix :: multiplyRow( const int row, const double constant ){
    if( row < 0 || row >= m )
        return;

    for( int column = 0; column < n; column ++ )
        A[ row ][ column ] *= constant;
}

void Matrix :: multiplyColumn( const int column, const double constant ){
    if( column < 0 || column >= n )
        return;

    for( int row = 0; row < m; row ++ ){
        A[ row ][ column ] *= constant;
    }
}
