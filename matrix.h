#pragma once
#include <vector>

class Matrix {
public:
  typedef std::vector<std::vector<double>> raw_matrix;

  Matrix() {};
  Matrix(const raw_matrix&);
  Matrix(const size_t, const size_t, const double);
  size_t getNumRows() const;
  size_t getNumColumns() const;
  Matrix getTransposeMatrix() const;
  //void row_multiply(const Matrix&, const Matrix&, const bool, const size_t, const size_t, raw_matrix&) const;
  Matrix multiply(const Matrix&, const bool, const int) const;
  bool operator==(const Matrix&) const;
private:
  raw_matrix matrix_;
  size_t num_rows_ = 0;
  size_t num_columns_ = 0;
};