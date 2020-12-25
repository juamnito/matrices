// #include "latex.hpp"
#include <stdio.h>
#include "../src/matrix.hpp"
#include <iostream>
#include <string>

using namespace std;

    string toString_LaTeX_matrix( const Matrix & A );

    void LaTeX_matrix( const Matrix & A, std :: string filename ); 

int floor( float val ){
    return val;
}

string toString_LaTeX_matrix( const Matrix & A ){
    string matrix;

    matrix.append( "\\begin{pmatrix}\n\t" );

    for( int rows = 0; rows < A.GetM( ); rows ++ ){
        for( int columns = 0; columns < A.GetN( ); columns ++ ){
            
            auto valor = A.GetIndex( rows, columns );

            matrix.append( to_string( valor ) );

            // matrix.append( to_string( ( int )( A.GetIndex( rows, columns ) ) ) );
            if( columns != A.GetN( ) - 1 ){
                matrix.append( " & " );
            }
            else if( rows != A.GetM( ) - 1 ) {
                matrix.append( " \\\\ \n\t" );
            }
            else {
                matrix.append( " \n" );
            }
        }
    }
    matrix.append( "\\end{pmatrix}\n" );
    
    return matrix;
}

// void LaTeX_matrix( Matrix & A, string filename ){
//     FILE * fp;
// 
//     fp = fopen( filename, "w" );
// 
//     
// 
//     fclose( fp ); 
// }
