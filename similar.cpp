#include <iostream>
#include <string>

#include "matrix.hpp"

using namespace std;

#define SUM_COLUMN -1
#define SUM_ROW 1
#define EXCHANGE_COLUMN -2
#define EXCHANGE_ROW 2
#define MULTIPLY_COLUMN -3
#define MULTIPLY_ROW 3

void OperationSilimar( Matrix & A, int regla, double constant, int lineFrom, int lineTo );
void Opera( Matrix & A );

int main( void ){

    string seguir;

    Matrix A;
    A.Random( 3, 3, 1, 1);

    A.SetIndex( 0, 0, -9 );
    A.SetIndex( 0, 1, 4 );
    A.SetIndex( 0, 2, 4 );

    A.SetIndex( 1, 0, -8 );
    A.SetIndex( 1, 1, 3 );
    A.SetIndex( 1, 2, 4 );


    A.SetIndex( 2, 0, -16 );
    A.SetIndex( 2, 1, 8 );
    A.SetIndex( 2, 2, 7 );

    A.Print( );

    do {
        cout << endl;

        Opera( A );
        getchar( );
        system( "cls" );

        cout << "\n Seguir? ";
        cin >> seguir;

    } while( seguir == "S" or seguir == "s" );

    return 0;
}

// Reglas posibles.

void OperationSilimar( Matrix & A, int regla, double constant, int lineFrom, int lineTo ){
    if( regla == EXCHANGE_COLUMN ){
        A.exchangeColumn( lineFrom, lineTo );
        A.Print( );
        cout << endl << endl;        
        A.exchangeRow( lineFrom, lineTo );
        A.Print( );
        cout << endl << endl;
        return;
    }
    if( regla == EXCHANGE_ROW ){
        A.exchangeRow( lineFrom, lineTo );
        A.Print( );
        cout << endl << endl;
        A.exchangeColumn( lineFrom, lineTo );
        A.Print( );
        cout << endl << endl;
        return;
    }

    if( regla == SUM_COLUMN ){
        A.sumColumn( lineFrom, lineTo, constant );
        A.Print( );
        cout << endl << endl;
        A.sumRow( lineTo, lineFrom, - constant );
        A.Print( );
        cout << endl << endl;
        return;
    }
    if( regla == SUM_ROW ){
        A.sumRow( lineFrom, lineTo, constant );
        A.Print( );
        cout << endl << endl;
        A.sumColumn( lineTo, lineFrom, - constant );
        A.Print( );
        cout << endl << endl;
        return;
    }

    if( constant == 0 ){
        return;
    }

    if( regla == MULTIPLY_COLUMN ){
        A.multiplyColumn( lineTo, constant );
        A.Print( );
        cout << endl << endl;
        A.multiplyRow( lineTo, 1 / constant );
        A.Print( );
        cout << endl << endl;
        return;
    }
    if( regla == MULTIPLY_ROW ){
        A.multiplyRow( lineTo, constant );
        A.Print( );
        cout << endl << endl;
        A.multiplyColumn( lineTo, 1 / constant );
        A.Print( );
        cout << endl << endl;
        return;
    }
}

void Opera( Matrix & A ){

    int rule = 1;

    cout << "Regla: sum 1, exchange 2, multiply 3, column -, row + \n";
    cin >> rule;

    if( rule == SUM_ROW ){
        int from, to;
        double constant = 1;

        cout << "Row from: ";
        cin >> from;

        cout << "Row to: ";
        cin >> to;

        cout << "Constant: ";
        cin >> constant;

        OperationSilimar( A, rule, constant, from, to );
    }
    else if( rule == SUM_COLUMN ){
        int from, to;
        double constant = 1;

        cout << "Column from: ";
        cin >> from;

        cout << "Column to: ";
        cin >> to;

        cout << "Constant: ";
        cin >> constant;

        OperationSilimar( A, rule, constant, from, to );
    }
    else if( rule == EXCHANGE_COLUMN ){
        int from, to;

        cout << "Column from: ";
        cin >> from;

        cout << "Column to: ";
        cin >> to;

        OperationSilimar( A, rule, 1, from, to );
    }
    else if( rule == EXCHANGE_ROW ){
        int from, to;

        cout << "Row from: ";
        cin >> from;

        cout << "Row to: ";
        cin >> to;

        OperationSilimar( A, rule, 1, from, to );
    }
    else if( rule == MULTIPLY_ROW ){
        int row;

        cout << "Row: ";
        cin >> row;

        OperationSilimar( A, rule, 1, row, row );
    }
    else if( rule == MULTIPLY_COLUMN ){
        int column;

        cout << "Column: ";
        cin >> column;

        OperationSilimar( A, rule, 1, column, column );
    }
}