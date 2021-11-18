#include <iostream>

#include "exceptions.h"
#include "matrix.h"


namespace prep {

Matrix::Matrix(size_t rows, size_t cols)
    : matrix_rows(rows), matrix_cols(cols),
      matrix_arr(rows, std::vector<double> (cols)) {
}

Matrix::Matrix(std::istream& is) {

}

size_t Matrix::getRows() const {

}

size_t Matrix::getCols() const {

}

double Matrix::operator()(size_t i, size_t j) const {
 
}

double& Matrix::operator()(size_t i, size_t j) {

}


bool Matrix::operator==(const Matrix& rhs) const {


}

bool Matrix::operator!=(const Matrix& rhs) const {

}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    
}

Matrix Matrix::operator+(const Matrix& rhs) const {
  
}

Matrix Matrix::operator-(const Matrix& rhs) const {
   
}

Matrix Matrix::operator*(const Matrix& rhs) const {
  
}

Matrix Matrix::transp() const {
 
}

Matrix Matrix::operator*(double val) const {
  
}

Matrix operator*(double val, const Matrix& matrix) {
   
}

double Matrix::det() const {

}

Matrix Matrix::adj() const {
   
}

Matrix Matrix::inv() const {
   
}

}  // namespace prep