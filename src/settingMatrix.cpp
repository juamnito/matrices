#include "matrix.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

void Matrix :: Identity( const int m_, const int n_ ){

    Delete( );
    n = n_;
    m = m_;

    A = new double * [ m ];

    for( int i = 0; i < m; i ++ ){

        A[ i ] = new double[ n ];
        for( int j = 0; j < m; j ++ ){

            if( i == j ){
                A[ i ][ j ] = 1;
            }
            else{
                A[ i ][ j ] = 0;
            }

        }
    }
}

void Matrix :: Zeros( const int m_, const int n_ ){

    Delete( );
    n = n_;
    m = m_;

    A = new double * [ m ];

    for( int i = 0; i < m; i ++ ){
        A[ i ] = new double[ n ];
        for( int j = 0; j < n; j ++ ){
            A[ i ][ j ] = 0;
        }
    }
}

void Matrix :: Random( const int m_, const int n_, const unsigned int mod, const int constant, const int seed ){

    srand( seed );
        
    Delete( );
    n = n_;
    m = m_;

    if( n <= 0 or m <= 0 ){
        Zeros( 1, 1 );
        return;
    }


    A = new double * [ m ];

    for( int i = 0; i < m; i ++ ){
        A[ i ] = new double[ n ];
        for( int j = 0; j < n; j ++ ){
            int value = ( ( rand( ) % mod ) + constant );
            A[ i ][ j ] = ( double ) value; 
        }
    }
}

void Matrix :: Inverse( const Matrix & B ){

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
            if( Id.GetIndex( row, diag ) != 0 and diag != row ){

                sumRow( diag, row, - Id.GetIndex( row, diag ) );
                Id.sumRow( diag, row, - Id.GetIndex( row, diag ) );
            }
        }
    }
}

void Matrix :: Copy( const Matrix & B ){
    SetDimentions( B.GetM( ), B.GetN( ) );

    for( int column = 0; column < GetN( ); column ++ ){
        for( int row = 0; row < GetM( ); row ++ ){
            SetIndex( row, column, B.GetIndex( row, column ) );
        }
    }
}

void Matrix :: Copy( const double ** arr, const int m_, const int n_ ){
    Delete( );

    n = n_;
    m = m_;

    A = new double * [ m ];

    for( int column = 0; column < m; column ++ ){
        A[ column ] = new double [ n ];
        for( int row = 0; row < n; row ++ ){
            A[ row ][ column ] = arr[ row ][ column ];
        }
    }
}

void Matrix :: CopyIgnoringColumnsAndRows( const Matrix & B, int ignore_col, int ignore_row ){
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

    if( ignore_col >= 0 and ignore_col < n ){
        n = B.GetN( ) - 1;
    }
    else {
        n = B.GetN( );
    }

    if( ignore_row >= 0 and ignore_row < m ){
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

    A = new double * [ m ];

    int ign_row = 0;

    for( int row = 0; row < m; row ++ ){

        A[ row ] = new double [ n ];

        int ign_col = 0;
        
        if( row == ignore_row ){
            ign_row = 1;
        }

        for( int column = 0; column < n; column ++ ){
            if( column == ignore_col ){
                ign_col = 1;
            }
            
            A[ row ][ column ] = B.GetIndex( row + ign_row, column + ign_col );
        }
    }
}

void Matrix :: Delete( void ){
    if( A != NULL ){
        for( int i = 0; i < m ; i ++ ){
            if( A[ i ] != NULL ){
                delete A[ i ];
                A[ i ] = NULL;
            }
        }
        delete A;
    }

    A = NULL;

    n = 0;
    m = 0;
}

void Matrix :: SetDimentions( const int m_, const int n_ ){
    Delete( );
    
    n = n_;
    m = m_;

    if( n <= 0 or m <= 0 ){
        n = 0;
        m = 0;
    
        A = NULL;
        return;
    }
    
    A = new double * [ m ];

    for( int row = 0; row < m; row ++ ){
        A[ row ] = new double [ n ];
    }
}

int Matrix :: TriangularSuperior( ){
    int exchanges = 0;

    for( int columns = 0; columns < n; columns ++ ){
        for( int rows = columns; rows < m; rows ++ ){
            if( A[ columns ][ columns ] == 0 and A[ rows ][ columns ] != 0 ){
                exchangeRow( columns, rows );
                exchanges ++;
            }
            else if( A[ rows ][ columns ] != 0 and rows != columns ) {
                sumRow( columns, rows, - A[ rows ][ columns ] / A[ columns ][ columns ] );    
            }
        }
    }
    return exchanges;
}

void Matrix :: SetByHand( ){
    Delete( );
    
    cout << "\n\t[SET-BY-HAND]\n";
    cout << "ROWS >> ";
    cin >> m;
    cout << "COLS >> ";
    cin >> n;

    SetDimentions( m, n );

    double value = 0;

    for( int rows = 0; rows < GetM( ); rows ++ ){
        for( int columns = 0; columns < GetN( ); columns ++ ){
            cout << "\n(Row: " << rows << ", Column: " << columns << ")" << endl;
            cout << "VALUE >> ";
            
            cin >> value;

            SetIndex( rows, columns, value );
        }
    }

    cout << "\n[Matrix already set]\n";
}
