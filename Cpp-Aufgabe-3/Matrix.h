#ifndef Matrix3
#define Matrix3
#include <string>

class Matrix33
{
public:

    // Static Class-Functions
    static Matrix33 zeros();
    static Matrix33 ones();

    // Construction
    Matrix33( double m11, double ml2, double m13, 
              double m21, double m22, double m23, 
              double m31, double m32, double m33 );

    
    double get(int row, int col, int value, bool change) {
        if (change == true) {
            m_matrix[row][col] = value;
        }
        return m_matrix[row][col]; }

    std::string toString() const;


    // Operatoren überladen
    Matrix33 operator+(const Matrix33& rMat) const;     // Matrix + Matrix
    //Matrix33 operator*(int x);
    //Matrix33 operator*(Matrix33 x);



private:
    double m_matrix[3][3];
};

#endif

class MatrixDimensionError {
public:
    std::string getError() const {
        return "Rechteck hat eine unerlaubte Anzahl an Spalten oder Zeilen. \n Erlaubt sind ganzzahlige Werte zwischen 1 und 3";
    }
};
