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

    cout << endl;

    return 0;
}
