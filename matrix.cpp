#include <iostream>
// #include <algorithm>

#include <stdlib.h>
#include <time.h>

#include "matrix.hpp"

#define SEED time( NULL )
// #define SEED 2

using namespace std;

Matrix :: Matrix( int m_, int n_ ) : n( n_ ), m( m_ ){
    SetDimentions( m, n );
}

Matrix :: Matrix( ){
    A = NULL;
    n = 0;
    m = 0;
}

Matrix :: ~ Matrix( ){
    Delete( );
}

// DELETE

void Matrix :: Delete( void ){
    if( A != NULL ){
        for( int i = 0; i < n ; i ++ ){
            if( A[ i ] != NULL ){
                delete A[ i ];
            }
            A[ i ] = NULL;
        }
        delete A;
    }

    A = NULL;

    n = 0;
    m = 0;
}

// PRINT

void Matrix :: Print( void ){
    for( int i = 0; i < m; i ++ ){
        for( int j = 0; j < n; j ++ ){
            cout << " " << A[ j ][ i ] << " ";
        }
        cout << endl;
    }
}

// GETTERS & SETTERS

double Matrix :: GetIndex( int i, int j ){

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

void Matrix :: SetIndex( int i, int j, double val ){
    if( i < 0 )
        i = 0;
    else if( i >= m )
        i = m - 1;
    if( j < 0 )
        j = 0;
    else if( j >= n )
        j = n - 1;

    A[ j ][ i ] = val;
}

int Matrix :: GetN( ){
    return n;
}

int Matrix :: GetM( ){
    return m;
}

// SET MATRIX

void Matrix :: Identity( int m_, int n_ ){

    Delete( );
    n = n_;
    m = m_;

    A = new double * [ n ];

    for( int i = 0; i < n; i ++ ){
        A[ i ] = new double[ m ];
        for( int j = 0; j < m; j ++ ){
            if( i == j ){
                A[ i ][ j ] = 1;
            }
            else {
                A[ i ][ j ] = 0;
            }
        }
    }
}

void Matrix :: Zeros( int m_, int n_ ){

    Delete( );
    n = n_;
    m = m_;

    A = new double * [ n ];

    for( int i = 0; i < n; i ++ ){
        A[ i ] = new double[ m ];
        for( int j = 0; j < m; j ++ ){
            A[ i ][ j ] = 0;
        }
    }
}

void Matrix :: Random( int m_, int n_, unsigned int mod, int constant ){

    Delete( );
    n = n_;
    m = m_;

    if( n <= 0 || m <= 0 ){
        Zeros( 1, 1 );
        return;
    }

    srand( SEED );

    A = new double * [ n ];

    for( int i = 0; i < n; i ++ ){
        A[ i ] = new double[ m ];
        for( int j = 0; j < m; j ++ ){
            A[ i ][ j ] = ( rand( ) % mod ) + constant;
        }
    }
}

double ** Matrix :: GetMatrix( void ){
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

void Matrix :: Copy( Matrix & B ){
    Delete( );
    n = B.GetN( );
    m = B.GetM( );

    A = new double * [ n ];

    for( int column = 0; column < n; column ++ ){
        A[ column ] = new double [ m ];
        for( int row = 0; row < m; row ++ ){
            A[ column ][ row ] = B.GetIndex( row, column );
        }
    }
}

void Matrix :: Copy( double ** arr, int m_, int n_ ){
    Delete( );

    n = n_;
    m = m_;

    A = new double * [ n ];

    A = new double * [ n ];

    for( int column = 0; column < n_; column ++ ){
        A[ column ] = new double [ m ];
        for( int row = 0; row < m_; row ++ ){
            A[ column ][ row ] = arr[ column ][ row ];
        }
    }
}

void Matrix :: CopyIgnoringColumnsAndRows( Matrix & B, int ignore_col, int ignore_row ){
    if( ignore_col >= 0 and B.GetN( ) <= 1 ){
        cout << "[ ERROR: Cannot return empty Matrix ]" << endl;
        return;
    }

    if( ignore_row >= 0 and B.GetM( ) <= 1 ){
        cout << "[ ERROR: Cannot return empty Matrix ]" << endl;
        return;
    }

    if( B.GetM( ) == 0 or B.GetN( ) == 0 ){
        cout << "[ ERROR: Cannot return empty Matrix ]" << endl;
        return;
    }

    Delete( );

    if( ignore_col >= 0 ){
        n = B.GetN( ) - 1;
    }
    else {
        n = B.GetN( );
    }

    if( ignore_row >= 0 ){
        m = B.GetM( ) - 1;
    }
    else {
        m = B.GetM( );
    }
        
    if( ignore_row < 0 ){
        ignore_row = m;
    }
    if( ignore_col < 0 ){
        ignore_col = n;
    }

    A = new double * [ n ];

    int ign_col = 0;

    for( int column = 0; column < n; column ++ ){

        A[ column ] = new double [ m ];

        int ign_row = 0;
        
        if( column == ignore_col ){
            ign_col = 1;
        }

        for( int row = 0; row < m; row ++ ){
            if( row == ignore_row ){
                ign_row = 1;
            }
            
            A[ column ][ row ] = B.GetIndex( row + ign_row, column + ign_col );
        }
    }
}

void Matrix :: Inverse( Matrix & B ){

    if( B.GetN( ) != B.GetM( ) || B.GetM( ) <= 0 ){
        Zeros( 1, 1 );
        return;
    }

    n = B.GetN( );
    m = n;

    Matrix Id;
    Id.Copy( B );

    Identity( n, n );

    for( int diag = 0; diag < n; diag ++ ){
        if( Id.GetIndex( diag, diag ) == 0 ){
            for( int row = diag + 1; row < n; row ++ ){
                if( Id.GetIndex( row, diag ) != 0 ){
                    exchangeRow( row, diag );
                    Id.exchangeRow( row, diag );
                    break;
                }
            }
        }
        if( Id.GetIndex( diag, diag ) == 0 ){
            Zeros( 1, 1 );
            return;
        }

        multiplyRow( diag, 1 / Id.GetIndex( diag, diag ) );
        Id.multiplyRow( diag, 1 / Id.GetIndex( diag, diag ) );

        for( int row = 0; row < n; row ++ ){
            if( Id.GetIndex( row, diag ) != 0 && diag != row ){

                sumRow( diag, row, - Id.GetIndex( row, diag ) );
                Id.sumRow( diag, row, - Id.GetIndex( row, diag ) );
            }
        }
    }
}

// ELEMENTARY OPERATIONS

void Matrix :: sumRow( int i, int to_j, double constant ){
    if( i < 0 || i >= m || to_j < 0 || to_j >= m )
        return;

    for( int column = 0; column < n; column ++ ){
        A[ column ][ to_j ] += constant * A[ column ][ i ];
    }
}

void Matrix :: sumColumn( int i, int to_j, double constant ){
    if( i < 0 || i >= n || to_j < 0 || to_j >= n )
        return;

    for( int row = 0; row < m; row ++ ){
        A[ to_j ][ row ] += constant * A[ i ][ row ];
    }
}

void Matrix :: exchangeRow( int row_0, int row_1 ){
    if( row_0 < 0 || row_0 >= m || row_1 < 0 || row_1 >= m )
        return;

    double aux = 0;

    for( int column = 0; column < n; column ++ ){
        aux = A[ column ][ row_0 ];
        A[ column ][ row_0 ] = A[ column ][ row_1 ];
        A[ column ][ row_1 ] = aux;
    }
}

void Matrix :: exchangeColumn( int column_0, int column_1 ){
    if( column_0 < 0 || column_0 >= n || column_1 < 0 || column_1 >= n )
        return;

    double * aux = A[ column_0 ];
    A[ column_0 ] = A[ column_1 ];
    A[ column_1 ] = aux;
}

void Matrix :: multiplyRow( int row, double constant ){
    if( row < 0 || row >= m )
        return;

    for( int column = 0; column < n; column ++ )
        A[ column ][ row ] *= constant;
}

void Matrix :: multiplyColumn( int column, double constant ){
    if( column < 0 || column >= n )
        return;

    for( int row = 0; row < m; row ++ ){
        A[ column ][ row ] *= constant;
    }
}

long double Matrix :: Determinant( Matrix & B ){
    if( B.GetN( ) != B.GetM( ) ){
        return 1;
    }

    if( B.GetN( ) == 0 or B.GetM( ) == 0 ){
        return 1;
    }

    if( B.GetN( ) == 1 ){
        return B.GetIndex( 0, 0 );
    }

    // if( B.GetN( ) == 2 ){
    //     return B.GetIndex( 0, 0 ) * B.GetIndex( 1, 1 ) - B.GetIndex( 0, 1 ) * B.GetIndex( 1, 0 );
    // }

    Matrix copy;

    double sum = 0;

    for( int columns = 0; columns < B.GetN( ); columns ++ ){
        for( int rows = 0; rows < B.GetM( ); rows ++ ){
            
            // cout << endl << "call" << endl;
            
            copy.CopyIgnoringColumnsAndRows( B, columns, 0 );

            if( columns % 2 == 0 ){
                sum += B.GetIndex( rows, columns ) * Determinant( copy );
            }
            else {
                sum -= B.GetIndex( rows, columns ) * Determinant( copy );
            }
            // cout << endl << sum << endl;
        }
    }
    return sum;
}

// OVERLOAD OPERATIONS BETWEEN MATRICES

void Matrix :: Product( Matrix & A, Matrix & B ){

    if( A.GetN( ) != B.GetM( ) or A.GetN( ) <= 0 or A.GetM( ) <= 0 or B.GetN( ) <= 0 ){
        Zeros( 1, 1 );
        return;
    }

    SetDimentions( A.GetM( ), B.GetN( ) );

    for( int column = 0; column < n; column ++ ){
        for( int row = 0; row < m; row ++ ){
            double sum = 0;
            for( int i = 0; i < A.GetN( ); i ++ ){
                sum += A.GetIndex( row, i ) * B.GetIndex( i, column );
            }
            SetIndex( row, column, sum );
        }
    }
}

void Matrix :: Sum( Matrix & A, Matrix & B ){

}

void Matrix :: SetDimentions( int m_, int n_ ){
    Delete( );
    
    n = n_;
    m = m_;

    if( n <= 0 or m <= 0 ){
        n = 0;
        m = 0;
    
        A = NULL;
        return;
    }
    
    A = new double * [ n ];

    for( int i = 0; i < n; i ++ ){
        A[ i ] = new double [ m ];
    }
}

Matrix operator * ( Matrix & A, Matrix & B ){
    Matrix P( A.GetM( ), B.GetN( ) );

    if( A.GetN( ) != B.GetM( ) || A.GetN( ) <= 0 ){
        P.Zeros( 1, 1 );
        return P;
    }

    // for( int column = 0; column < P.GetN( ); column ++ ){
    //     for( int row = 0; row < P.GetM( ); row ++ ){
    //         double sum = 0;
    //         for( int i = 0; i < A.GetN( ); i ++ ){
    //             sum += A.GetIndex( i, row ) * B.GetIndex( column, i );
    //         }
    //         P.SetIndex( row, column, sum );
    //     }
    // }
    return P;
}

Matrix operator + ( Matrix & A, Matrix & B ){
    Matrix P( A.GetM( ), A.GetN( ) );

    // if( A.GetN( ) != B.GetN( ) || A.GetN( ) <= 0 || A.GetM( ) != B.GetM( ) ){
    //     P.Zeros( 1, 1 );
    //     return P;
    // }

    // for( int column = 0; column < P.GetN( ); column ++ ){
    //     for( int row = 0; row < P.GetM( ); row ++ ){
    //         P.SetIndex( row, column, A.GetIndex( row, column ) + B.GetIndex( row, column ) );
    //     }
    // }
    return P;
}