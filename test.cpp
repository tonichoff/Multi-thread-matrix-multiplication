#define CATCH_CONFIG_MAIN
#include "matrix.h"
#include "catch.hpp"
#include <vector>
#include <exception>

using namespace std;

TEST_CASE("Comparison") {
  SECTION("Not equal with unequal dimension") {
    vector<vector<double>> raw_matrix_A = { { 1, 3 },{ 1, 2 } };
    Matrix matrix_A(raw_matrix_A);
    vector<vector<double>> raw_matrix_B = { { 1, 3 },{ 1, 2 },{ 1, 5 } };
    Matrix matrix_B(raw_matrix_B);
    REQUIRE((matrix_A == matrix_B) == false);
  }

  SECTION("Not equal") {
    vector<vector<double>> raw_matrix_A = { { 1, 3 },{ 1, 2 } };
    Matrix matrix_A(raw_matrix_A);
    vector<vector<double>> raw_matrix_B = { { 1, 4},{ 1, 2} };
    Matrix matrix_B(raw_matrix_B);
    REQUIRE((matrix_A == matrix_B) == false);
  }
}

TEST_CASE("Creating") {
  SECTION("Different column size") {
    vector<vector<double>> raw_matrix = { {2, 4},{5, 6, 7} };
    REQUIRE_THROWS_AS(Matrix(raw_matrix), length_error);
  }

  SECTION("Empty") {
    vector<vector<double>> raw_matrix = {};
    Matrix matrix(raw_matrix);
    REQUIRE(matrix.getNumRows() == 0);
    REQUIRE(matrix.getNumColumns() == 0);
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

TEST_CASE("Simple multiplication") {
  vector<vector<double>> raw_matrix_A = { { 1, 3 },{ 1, 2 } };
  Matrix matrix_A(raw_matrix_A);
  vector<vector<double>> raw_matrix_B = { { 1, 2, 1 },{ 3, 1, 0 } };
  Matrix matrix_B(raw_matrix_B);

  vector<vector<double>> raw_expected_matrx = { { 10, 5, 1 },{ 7, 4, 1 } };
  Matrix expected_matrix(raw_expected_matrx);

  SECTION("Without transpose") {
    Matrix result = matrix_A.multiply(matrix_B, false, 0);
    REQUIRE(result == expected_matrix);
  }

  SECTION("With transpose") {
    Matrix result = matrix_A.multiply(matrix_B, true, 0);
    REQUIRE(result == expected_matrix);
  }
}

TEST_CASE("Wrong multiply") {
  vector<vector<double>> raw_matrix_A = { { 1, 3, 4 },{ 1, 2, 5 }};
  Matrix matrix_A(raw_matrix_A);
  vector<vector<double>> raw_matrix_B = { { 1, 2, 1 },{ 3, 1, 0 } };
  Matrix matrix_B(raw_matrix_B);

  REQUIRE_THROWS_AS(matrix_A.multiply(matrix_B, false, 0), invalid_argument);
}

TEST_CASE("Two threads") {
  Matrix matrix_A(10, 10, 10);
  Matrix matrix_B(10, 10, 100);
  Matrix expected_matrix(10, 10, 10000);

  SECTION("Without transpose") {
    Matrix result = matrix_A.multiply(matrix_B, false, 2);
    REQUIRE(result == expected_matrix);
  }

  SECTION("With transpose") {
    Matrix result = matrix_A.multiply(matrix_B, true, 2);
    REQUIRE(result == expected_matrix);
  }
}