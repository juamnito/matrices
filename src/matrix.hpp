#ifndef MATRIX_H
#define MATRIX_H

    # include <algorithm>

    class Matrix {
    
        public:
            Matrix( const Matrix & copy );
            Matrix( const int m_, const int n_ );
            Matrix( );
            ~ Matrix( );
    
            friend void Swap( Matrix & P, Matrix & Q );
            
            // PRINT
    
            void Print( void ) const;
    
            // SET MATRIX
    
            void Identity( const int m_, const int n_ );
            void Zeros( const int m_, const int n_ );
            void Random( const int m_, const int n_, const unsigned int mod, const int constant, const int seed );
            void Inverse( const Matrix & B );
    
            void Copy( const Matrix & B );
            void Copy( const double ** arr, const int m_, const int n_ );
            void CopyIgnoringColumnsAndRows( const Matrix & B, int ignore_col, int ignore_row );

            void SetByHand( );

            void Delete( void ); 
            void SetDimentions( const int m_, const int n_ );
            
            int TriangularSuperior( );

            // GETTERS & SETTERS
    
            double GetIndex( int i, int j ) const;
            void SetIndex( int i, int j, const double val );
    
            int GetN( void ) const;
            int GetM( void ) const;

            double ** GetMatrix( ) const;
        
            // ELEMENTARY OPERATIONS
    
            void sumRow( const int i, const int to_j, const double constant );
            void sumColumn( const int i, const int to_j, const double constant );
    
            void exchangeRow( const int row_0, const int row_1 );
            void exchangeColumn( const int column_0, const int column_1 );
    
            void multiplyRow( const int row, const double constant );
            void multiplyColumn( const int column, const double constant );
            
            // OPERATIONS 
            Matrix operator = ( const Matrix & B );
            Matrix operator * ( const Matrix & B );
            Matrix operator + ( const Matrix & B );

            long double Determinant( const Matrix & B ) const; 
 
        private:
            double ** A;
            int n,      // columns
                 m;     // rows
    };

#endif
