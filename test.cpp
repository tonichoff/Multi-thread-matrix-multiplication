#define CATCH_CONFIG_MAIN
#include "matrix.h"
#include "catch.hpp"
#include <vector>

using namespace std;

TEST_CASE("Simple multiplication") {
  vector<vector<double>> row_matrix_A = { { 1, 3 },{ 1, 2 } };
  Matrix matrix_A(row_matrix_A);
  vector<vector<double>> row_matrix_B = { { 1, 2, 1 },{ 3, 1, 0 } };
  Matrix matrix_B(row_matrix_B);

  vector<vector<double>> row_expected_matrx = { { 10, 5, 1 },{ 7, 4, 1 } };
  Matrix expected_matrix(row_expected_matrx);

  SECTION("Without transpose") {
    Matrix result = matrix_A.multiply(matrix_B, false, 1);
    REQUIRE(result == expected_matrix);
  }

  SECTION("With transpose") {
    Matrix result = matrix_A.multiply(matrix_B, true, 1);
    REQUIRE(result == expected_matrix);
  }
}

TEST_CASE("Use constructor with default value") {
  Matrix matrix_A(10, 10, 10);
  Matrix matrix_B(10, 10, 100);
  Matrix expected_matrix(10, 10, 10000);

  SECTION("Without transpose") {
    Matrix result = matrix_A.multiply(matrix_B, false, 1);
    REQUIRE(result == expected_matrix);
  }

  SECTION("With transpose") {
    Matrix result = matrix_A.multiply(matrix_B, true, 1);
    REQUIRE(result == expected_matrix);
  }
}