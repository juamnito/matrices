#include <iostream>
#include "matrix.hpp"

#include <iomanip>
#include <sstream>

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

    // for( int i = 0; i < m; i ++ ){
    //     for( int j = 0; j < n; j ++ ){
    //         cout << " " << A[ i ][ j ] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ToString( );
}

string Matrix :: ToString( void ) const {
    string matrix_str;

    for( int i = 0; i < m; i ++ ){
        for( int j = 0; j < n; j ++ ){
            stringstream stream;
            if( A[ i ][ j ] == ( int ) A[ i ][ j ] ){
                stream << fixed << setprecision( 0 ) << A[ i ][ j ];
                matrix_str.append( " " + stream.str( ) + " " );
            }
            else {
                stream << fixed << setprecision( 3 ) << A[ i ][ j ];
                matrix_str.append( " " + stream.str( ) + " " );
                // auto val = A[ i ][ j ];
                // string linea = " " + to_string( val ) + " ";
                // matrix_str.append( linea );
            }
            // cout << to_string( A[ i ][ j ] );
        }
        matrix_str.append( "\n" );
    }
    return matrix_str;
}

// string Matrix :: ToLatex( ) const {
//     string matrix;
// 
//     matrix.append( "\\begin{pmatrix}\n\t" );
// 
//     for( int rows = 0; rows < GetM( ); rows ++ ){
//         for( int columns = 0; columns < GetN( ); columns ++ ){
//             
//             auto valor = GetIndex( rows, columns );
// 
//             matrix.append( to_string( valor ) );
// 
//             // matrix.append( to_string( ( int )( A.GetIndex( rows, columns ) ) ) );
//             if( columns != GetN( ) - 1 ){
//                 matrix.append( " & " );
//             }
//             else if( rows != GetM( ) - 1 ) {
//                 matrix.append( " \\\\ \n\t" );
//             }
//             else {
//                 matrix.append( " \n" );
//             }
//         }
//     }
//     matrix.append( "\\end{pmatrix}\n" );
//     
//     return matrix;
// }

/////////////////// SWAP ///////////////////////////////////////////

void Swap( Matrix & P, Matrix & Q ){
    using std :: swap;

    swap( P.A, Q.A );
    swap( P.n, Q.n );
    swap( P.m, Q.m );
}
