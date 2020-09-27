class Matrix {

    public:
        Matrix( int m_, int n_ );
        Matrix( );
        ~ Matrix( );

        // PRINT

        void Print( void );

        // SET MATRIX

        void Identity( int m_, int n_ );
        void Zeros( int m_, int n_ );
        void Random( int m_, int n_, unsigned int mod, int constant );
        void Inverse( Matrix & B );

        void Copy( Matrix & B );
        void Copy( double ** arr, int m_, int n_ );
        void Product( Matrix & A, Matrix & B );
        void Sum( Matrix & A, Matrix & B );

        // GETTERS & SETTERS

        double GetIndex( int i, int j );
        void SetIndex( int i, int j, double val );

        int GetN( void );
        int GetM( void );

        long double Determinant( Matrix & B ); 

        double ** GetMatrix( );
      
        // OVERLOAD OPERATORS BETWEEN MATRICES

        void CopyIgnoringColumnsAndRows( Matrix & B, int ignore_col, int ignore_row );
    
        // ELEMENTARY OPERATIONS

        void sumRow( int i, int to_j, double constant );
        void sumColumn( int i, int to_j, double constant );

        void exchangeRow( int row_0, int row_1 );
        void exchangeColumn( int column_0, int column_1 );

        void multiplyRow( int row, double constant );
        void multiplyColumn( int column, double constant );


    protected:
        void Delete( void );

            
        friend Matrix operator * ( Matrix & A, Matrix & B );
        friend Matrix operator + ( Matrix & A, Matrix & B );

    private:
        double ** A;
        int n, m;
        
        void SetDimentions( int m_, int n_ );
};