#include <string>
#include <sstream>
#include <iomanip>

#include "Matrix.h"
#include <iostream>


// ----------------------------------------------------------------------------

Matrix33 Matrix33::zeros()
{
    return Matrix33(0,0,0  ,0,0,0  ,0,0,0);
}


// ----------------------------------------------------------------------------

Matrix33 Matrix33::ones()
{
    return Matrix33(1,1,1  ,1,1,1  ,1,1,1);
}


// ----------------------------------------------------------------------------

Matrix33::Matrix33( double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33)
{
    m_matrix[0][0] = m11;
    m_matrix[0][1] = m12;
    m_matrix[0][2] = m13;
    m_matrix[1][0] = m21;
    m_matrix[1][1] = m22;
    m_matrix[1][2] = m23;
    m_matrix[2][0] = m31;
    m_matrix[2][1] = m32;
    m_matrix[2][2] = m33;
}


// ----------------------------------------------------------------------------

std::string Matrix33::toString() const
{
    std::stringstream s;
    s << "----------------------------\n";
    s << "| "  <<std::setw(6) << m_matrix[0][0];
    s << " | " <<std::setw(6) << m_matrix[0][1];
    s << " | " <<std::setw(6) << m_matrix[0][2] << " |";
    s << "\n----------------------------\n";
    s << "| "  <<std::setw(6) << m_matrix[1][0];
    s << " | " <<std::setw(6) << m_matrix[1][1];
    s << " | " <<std::setw(6) << m_matrix[1][2] << " |";
    s << "\n----------------------------\n";
    s << "| "  <<std::setw(6) << m_matrix[2][0];
    s << " | " <<std::setw(6) << m_matrix[2][1];
    s << " | " <<std::setw(6) << m_matrix[2][2] << " |";
    s << "\n----------------------------\n";
    return s.str();
}



// ----------------------------------------------------------------------------

// Operatoren überladen

// Matrix + Matrix
Matrix33 Matrix33::operator+(const Matrix33& rMat) const
{
    return Matrix33(m_matrix[0][0] + rMat.m_matrix[0][0],
                    m_matrix[0][1] + rMat.m_matrix[0][1],
                    m_matrix[0][2] + rMat.m_matrix[0][2],
                    m_matrix[1][0] + rMat.m_matrix[1][0],
                    m_matrix[1][1] + rMat.m_matrix[1][1],
                    m_matrix[1][2] + rMat.m_matrix[1][2],
                    m_matrix[2][0] + rMat.m_matrix[2][0],
                    m_matrix[2][1] + rMat.m_matrix[2][1],
                    m_matrix[2][2] + rMat.m_matrix[2][2]);
}


// Matrix * Matrix
Matrix33 Matrix33::operator*(const Matrix33& rMat) const
{
    Matrix33 product = Matrix33(0, 0, 0, 0, 0, 0, 0, 0, 0);
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            // Zeilen von m_matrix mit den Spalten von rMat.m_matrix multiplizieren, um Spalte/Zeile des Produkts zu erhalten
            for (int inner = 0; inner < 3; inner++) {
                product.m_matrix[row][col] += m_matrix[row][inner] * rMat.m_matrix[inner][col];
            }
        }
    }
    return product;
}


// Matrix * Zahl
Matrix33 Matrix33::operator*(int x)
{
    Matrix33 product = Matrix33(0, 0, 0, 0, 0, 0, 0, 0, 0);
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            product.m_matrix[row][col] = m_matrix[row][col] * x;
        }
    }
    return product;
}



//// Matrix += Matrix
Matrix33 Matrix33::operator+=(const Matrix33& rMat) const
{
    Matrix33 sum = Matrix33(0, 0, 0, 0, 0, 0, 0, 0, 0);
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            sum.m_matrix[row][col] += rMat.m_matrix[row][col] + 10;
        }
    }
    return sum;
}

