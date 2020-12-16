#include <iostream>
#include "../src/matrix.hpp"

using namespace std;

int main( void ){

    unsigned int module = 1, dimentions = 1;
    int constant = 0;

    Matrix A;

    // cout << "Give me the dimentions \n>> ";
    // cin >> dimentions;
    // cout << "Give me the module \n>> ";
    // cin >> module;
    // cout << "Give me the constant \n>> ";
    // cin >> constant;
    
    A.Random( 5, 5, 1, 1 );

    A.SetIndex( 0, 0, -0.9 );
    A.SetIndex( 0, 1, 0.3 );
    A.SetIndex( 0, 2, 0.2 );
    A.SetIndex( 0, 3, 0 );
    A.SetIndex( 0, 4, 0.1 );

    A.SetIndex( 1, 0, 0.2 );
    A.SetIndex( 1, 1, -0.9 );
    A.SetIndex( 1, 2, 0.3 );
    A.SetIndex( 1, 3, 0 );
    A.SetIndex( 1, 4, 0 );

    A.SetIndex( 2, 0, 0.3 );
    A.SetIndex( 2, 1, 0 );
    A.SetIndex( 2, 2, -0.97 );
    A.SetIndex( 2, 3, 0 );
    A.SetIndex( 2, 4, 0 );

    A.SetIndex( 3, 0, 0.15 );
    A.SetIndex( 3, 1, 0.4 );
    A.SetIndex( 3, 2, 0.27 );
    A.SetIndex( 3, 3, -0.5 );
    A.SetIndex( 3, 4, 0 );

    A.SetIndex( 4, 0, 0.25 );
    A.SetIndex( 4, 1, 0.2 );
    A.SetIndex( 4, 2, 0.2 );
    A.SetIndex( 4, 3, 0.5 );
    A.SetIndex( 4, 4, -0.1 );

    if( dimentions <= 0 ){
        dimentions = 1;
    }
    if( module <= 0 ){
        module = 1;
    }

    // A.Random( dimentions, dimentions, module, constant );

    cout << endl;

    A.Print( );

    cout << "\nThe determinant of your matrix is: " 
        << A.Determinant( A ) << endl << endl;

    return 0;
}


