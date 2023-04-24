#pragma once
#include <cassert>
#include <iostream>
#include <memory>

/* 
Headerfile for implementation file "Matrix.cpp"
----------------------------------------------
Matrix class to produce any arbitrary (N x M) mathematical matrix 
and perform linear operations such as multiplication, addition, subtraction and divison.
*/


class Matrix
// Construct a (N x M matrix)
{
    // Private members
    private:
        int rows; // address M columns
        int columns; // address N columns
        double** matrix;  // double pointer to point on row and column element (matrix entry)

    // Public members
    public:
        // Default constructor (make a N x M Matrix)
        Matrix(int nRows, int nColumns) 
        {
            assert(nRows > 0 && nColumns > 0); // End program if invalid amount of rows
            assert(nRows <= 100 && nColumns <= 100); // Limit the size of matrix
            
            this->rows = nRows;
            this->columns = nColumns;
            
            matrix = new double*[static_cast<std::size_t>(nRows)];
            for (int i = 0; i < nRows; i++)
            {
                matrix[i] = new double[static_cast<std::size_t>(nColumns)];
                for (int j = 0; j < nColumns; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Delegating constructor for identity matrix
        explicit Matrix(int n) : Matrix{n, n}
        {
            assert(n > 0); // End program if invalid amount of rows
            
            this->rows = n;
            
            // Construct Identity matrix
            for (int i = 0; i < n; i++)
            {
                matrix[i][i] = 1;
            }
        }

        // Copy constructor - instantiate new matrix of same shape and same values as rhs
        Matrix(const Matrix &rhs) : rows{rhs.rows}, columns{rhs.columns}, matrix{nullptr}
        {
            // allocate memory for new matrix
            matrix = new double*[static_cast<std::size_t>(rows)]; // allocating rows
            for (int i = 0; i < rows; i++)
            {
                matrix[i] = new double[static_cast<std::size_t>(columns)]; // allocating columns
            }

            // copy values from original to rhs
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < columns; j++){
                    matrix[i][j] = rhs.matrix[i][j];
                }
            }
        } 

        // Destructor to free dynamically allocated memory
        ~Matrix() 
        {
            for (int i = 0; i < rows; i++) 
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        // set & get functions for the matrix
        double get(int row, int col) const {return static_cast<double>(matrix[row][col]);}
        void set(int row, int col, double value){this->matrix[row][col] = static_cast<double>(value);}
        int getRows() const{return rows;}
        int getColumns() const{return columns;}

        // Operator overloads declarations
        friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
    
        Matrix& operator=(const Matrix& rhs);
        Matrix& operator+=(const Matrix& rhs);
        Matrix operator+(const Matrix& rhs) const;
};
