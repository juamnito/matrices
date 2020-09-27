#include <iostream>
#include <algorithm>

using namespace std;

#include "matrix.hpp"

#define PRODUCT_TEST main
#define DETERMINANT_TEST main
#define INVERSE_TEST main
#define SUM_TEST main 

/* Inverse
    int INVERSE_TEST( void ){
        // A.Identity( 5, 4 );
        // A.Print( ); 
        // cout << endl;

        Matrix B;
        // B.Zeros( 2, 2 );
        // B.SetIndex( 0, 1, 3 );
        // B.SetIndex( 1, 0, 2 );
        // B.SetIndex( 1, 1, 3 );
        // B.Identity( 4, 4 );
        B.Random( 5, 5, 10, 0 );
        B.Print( );
        // cout << B.GetM( ) << "x" << B.GetN( ) << endl << endl;
        cout << endl;

        Matrix A;
        A.Inverse( & B );
        // A.Random( 5, 5, 11, 0 );
        A.Print( );
        cout << endl;
        
        // ( B * A ).Print( );
        cout << endl;

        ( B ).Print( );
        return 0;
    } 
*/

/* Determinant
    int DETERMINANT_TEST( void ){

    Matrix A;

    
    int dim;

    cout << "n = ";
    cin >> dim;

    A.Random( dim, dim, 10, 1 );


    // double ** arr = new double * [ dim ];

    // for( int i = 0; i < dim; i ++ ){
    //     arr[ i ] = new double [ dim ];

    //     for( int j = 0; j < dim; j ++ ){
    //         cin >> arr[ i ][ j ];
    //     }
    // }

    cout << endl;

    // A.Copy( arr, dim, dim );

    A.Print( );

    Matrix determinant; 

    int t1 = clock( );

    cout << "\n Determinant: " << determinant.Determinant( A ) << endl;

    int t2 = clock( );

    double time = ( double )( t2 - t1 ) / CLOCKS_PER_SEC;

    // for( int j = 0; j < dim; j ++ ){
    //     delete arr[ j ];
    // }
    // delete arr;

    cout << "time of execution: " << time << " secs" << endl;

    return 0;

}
*/

// Product

int PRODUCT_TEST( void ){

    Matrix A, B, Prod;

    A.Random( 2, 4, 10, 1 );
    B.Random( 4, 2, 10, 1 );

    A.Print( );

    // cout << "      * " << endl;

    cout << endl;

    B.Print( ); 
    
    // cout << "Equals" << endl;

    cout << endl;


    Prod.Product( A, B );

    Prod.Print( );

    return 0;
}

/* Sum */

// int SUM_TEST( void ){



//     return 0;
// }