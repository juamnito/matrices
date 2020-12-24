#include "../src/matrix.hpp"
#include <iostream>

using namespace std;

void setByHand( Matrix & A );

int main( void ){
    
    Matrix B, A;

    A.Random( 4, 2, 10, 0, 7 );
    B.Random( 4, 2, 10, 0, 10 );

    cout << "This is your matrix A\n\n";
    A.Print( );
    cout << endl;
    
    cout << "This is your matrix B\n\n";
    B.Print( );
    cout << endl;


    char res = 's';
    cout << "\nMultiplica por si misma [ s / n (otro) ]: " ;

    cin >> res;
    cout << "Answer: " << res << endl;

    while( res == 's' ){
        Matrix C = ( A + B );
        C.Print( );
        cout << "\nMultiplica por si misma [ s / n (otro) ]: " ;
        cin >> res;
    }
    
    // A.Print( );

    cout << endl;

    // for( int i = 0; i < B.GetN( ); i ++ ){
    //     B = B * A;
    //     B.Print( );
    //     cout << endl ;
    // }
    return 0;
}

void setByHand( Matrix & A ){
    cout << "Setting Matrix by hand...\nGive me the values\n";
    
    int m = 0, n = 0;

    cout << "Give me m ( rows ) >> ";
    cin >> m;
    cout << "Give me n ( columns ) >> ";
    cin >> n;

    A.SetDimentions( m, n );

    double value = 0;

    for( int rows = 0; rows < A.GetM( ); rows ++ ){
        for( int columns = 0; columns < A.GetN( ); columns ++ ){
            cout << "\nColumn " << columns << "\nRow " << rows << endl;
            cout << "Value\n\t>> ";
            
            cin >> value;

            A.SetIndex( rows, columns, value );
        }
    }

    cout << "\n\nMatrix already set\n\n";
}
