#include "Matrix.h"

// Overload the = operator
Matrix& Matrix::operator=(const Matrix& rhs) 
{
    if (this == &rhs) {
        return *this;
    }

    // Free existing memory
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    // Allocate new memory and copy values
    rows = rhs.rows;
    columns = rhs.columns;
    matrix = new double*[static_cast<std::size_t>(rows)];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[static_cast<std::size_t>(columns)];
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = rhs.matrix[i][j];
        }
    }

    return *this;
}

// Overload the += operator
Matrix& Matrix::operator+=(const Matrix& rhs) 
{
    assert(rows == rhs.rows && columns == rhs.columns);

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
            matrix[i][j] += rhs.matrix[i][j];
        }
    }
    return *this;
}

// Overload the + operator
Matrix Matrix::operator+(const Matrix& rhs) const 
{
    assert(rows == rhs.rows && columns == rhs.columns);

    Matrix result(rows, columns);

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
            result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
        }
    }
    return result;
}

// Overload the << operator
std::ostream& operator<<(std::ostream& os, const Matrix& m) 
{
    int rows, columns;
    rows = m.getColumns();
    columns = m.getRows();

    // Formatting utilities
    for (int i = 0; i < rows; i++)
    {
        os << "\n";
        os << "[";
        for (int j = 0; j < columns; j++){
            os << " " << static_cast<double>(m.get(i,j)) << " ";
        
        }
        os << "]";
    }
    os << "\n";
    
    return os;
}
