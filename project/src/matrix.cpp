#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>


#include "exceptions.h"
#include "matrix.h"


namespace prep {

Matrix::Matrix(size_t rows, size_t cols)
    :matrix_rows(rows),
    matrix_cols(cols),
    matrix_arr(rows, std::vector<double> (cols)) {}

Matrix::Matrix(std::istream& is) {
    if (!is) {
        throw InvalidMatrixStream();
    }

    is >> matrix_rows;
    is >> matrix_cols;

    if (matrix_rows < 1 || matrix_cols < 1 ) {
        throw InvalidMatrixStream();
    }

    matrix_arr.resize(matrix_rows);

        for (auto& rows : matrix_arr) {
            rows.resize(matrix_cols);

            for (auto& target : rows) {
                is >> target;

                if (!is) {
                    throw InvalidMatrixStream();
                }
            }
        }
}

size_t Matrix::getRows() const {
    return matrix_rows;
}

size_t Matrix::getCols() const {
    return matrix_cols;
}

double Matrix::operator()(size_t i, size_t j) const {
    
    return matrix_arr[i][j];
}

double& Matrix::operator()(size_t i, size_t j) {
    return matrix_arr[i][j];
}


bool Matrix::operator==(const Matrix& rhs) const {

    if (this->matrix_rows != rhs.matrix_rows || this->matrix_cols != rhs.matrix_cols) {
        return false;
    }

    for (size_t i = 0; i < this->matrix_rows; i++) {
        for (size_t j = 0; j < this->matrix_cols; j++) {
            if (std::fabs(rhs.matrix_arr[i][j] - (this->matrix_arr[i][j]) > 
            std::numeric_limits<double>::epsilon() * 10e-07)) {
                return false;
            }
        }
    }


    return true;

}

bool Matrix::operator!=(const Matrix& rhs) const {
     return !(*this == rhs);
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    os << matrix.matrix_rows << " " << matrix.matrix_cols << std::endl;

    for (size_t i = 0; i < matrix.matrix_rows; i++) {
        for (size_t j = 0; j < matrix.matrix_cols; j++) {
            os << std::setprecision(std::numeric_limits<double>::max_digits10) 
            << matrix.matrix_arr[i][j] << " ";
        }
        os << std::endl;
    }

    return os;
}

Matrix Matrix::operator+(const Matrix& rhs) const {
    if (this->matrix_cols != rhs.matrix_cols || this->matrix_rows != rhs.matrix_rows) {
        throw DimensionMismatch(rhs);
    }

    Matrix matrix_sum(this->matrix_rows, this->matrix_cols);

    for (size_t i = 0; i < matrix_sum.matrix_rows; i++) {
        for (size_t j = 0; j < matrix_sum.matrix_cols; j++) {
            matrix_sum.matrix_arr[i][j] = this->matrix_arr[i][j] + rhs.matrix_arr[i][j];
        }
    }
    return matrix_sum;
}

Matrix Matrix::operator-(const Matrix& rhs) const {
    if (this->matrix_cols != rhs.matrix_cols || this->matrix_rows != rhs.matrix_rows) {
        throw DimensionMismatch(rhs);
    }

    Matrix matrix_sub(this->matrix_rows, this->matrix_cols);

    for (size_t i = 0; i < matrix_sub.matrix_rows; i++) {
        for (size_t j = 0; j < matrix_sub.matrix_cols; j++) {
            matrix_sub.matrix_arr[i][j] = 
            this->matrix_arr[i][j] - rhs.matrix_arr[i][j];
        }
    }

    return matrix_sub;
}

Matrix Matrix::operator*(const Matrix& rhs) const {
   Matrix matrix_sum(rhs.matrix_rows, rhs.matrix_cols);
   return matrix_sum;
}

Matrix Matrix::transp() const {
    Matrix matrix_transp(this->matrix_cols, this->matrix_rows);
    return matrix_transp;
}

Matrix Matrix::operator*(double val) const {
  Matrix matrix_transp(this->matrix_cols, this->matrix_rows);
return matrix_transp * val;
}

Matrix operator*(double val, const Matrix& matrix) {
   return matrix * val;
}

double Matrix::det() const {
    throw DimensionMismatch(*this);
}

Matrix Matrix::adj() const {
    throw DimensionMismatch(*this);
}

Matrix Matrix::inv() const {
    throw DimensionMismatch(*this);
}

}  // namespace prep