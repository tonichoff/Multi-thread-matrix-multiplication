#include "matrix.h"
#include <exception>
#include <utility>

Matrix::Matrix(const raw_matrix& matrix) : matrix_(matrix) {
  num_rows_ = matrix_.size();
  if (!matrix_.empty()) {
    size_t num_columns = matrix_[0].size();
    for (int i = 1; i < num_rows_; i++) {
      if (num_columns != matrix_[i].size()) {
        throw std::length_error("Different columns size");
      }
    }
    num_columns_ = num_columns;
  }
  else {
    num_columns_ = 0;
  }
}

Matrix::Matrix(const size_t num_rows, const size_t num_col, const double val) : num_rows_(num_rows), num_columns_(num_col) {
  matrix_ = std::vector<std::vector<double>>(num_rows_);
  for (size_t i = 0; i < num_rows_; i++) {
    matrix_[i].resize(num_columns_, val);
  }
}

size_t Matrix::getNumRows() const {
  return num_rows_;
}

size_t Matrix::getNumColumns() const {
  return num_columns_;
}

Matrix Matrix::getTransposeMatrix() const {
  raw_matrix transposed_matrix(this->num_columns_);
  for (int i = 0; i < this->num_columns_; i++) {
    transposed_matrix[i].resize(this->num_rows_);
    for (int j = 0; j < this->num_rows_; j++) {
      transposed_matrix[i][j] = this->matrix_[j][i];
    }
  }
  return Matrix(transposed_matrix);
}

Matrix Matrix::multiply(const Matrix& matrix_B, const bool transpose, const int num_threads) const {
  if (this->num_columns_ != matrix_B.num_rows_) {
    throw std::invalid_argument("Number of columns matrix A not equal number of rows matrix B");
  }

  Matrix right_matrix = (transpose) ? matrix_B.getTransposeMatrix() : matrix_B;
  raw_matrix result(this->num_rows_);
  for (int i = 0; i < this->num_rows_; i++) {
    result[i].resize(matrix_B.num_columns_);
    for (int j = 0; j < matrix_B.num_columns_; j++) {
      for (int k = 0; k < this->num_columns_; k++) {
        if (transpose)
          result[i][j] += this->matrix_[i][k] * right_matrix.matrix_[j][k];
        else
          result[i][j] += this->matrix_[i][k] * right_matrix.matrix_[k][j];
      }
    }
  }
  return Matrix(result);
}

bool Matrix::operator==(const Matrix& other) const {
  if (this->num_rows_ != other.num_rows_ || this->num_columns_ != other.num_columns_) {
    return false;
  }
  for (int i = 0; i < this->num_rows_; i++) {
    for (int j = 0; j < this->num_columns_; j++) {
      if (this->matrix_[i][j] != other.matrix_[i][j]) {
        return false;
      }
    }
  }
  return true;
}