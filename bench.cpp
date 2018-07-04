//#define BENCHPRESS_CONFIG_MAIN
//#include "benchpress/benchpress.hpp"
//#include "matrix.h"
//#include <chrono>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//Matrix mulWithoutTranspose() {
//  Matrix A(100, 100, 10);
//  Matrix B(100, 100, 100);
//  return A.multiply(B, false, 1);
//}
//
//Matrix mulWithTranspose() {
//  Matrix A(100, 100, 10);
//  Matrix B(100, 100, 100);
//  return A.multiply(B, true, 1);
//}
//
//BENCHMARK("Multiply without transpose", [](benchpress::context* ctx) {
//  for (size_t i = 0; i < ctx->num_iterations(); ++i) {
//    mulWithoutTranspose();
//  }
//});
//
//BENCHMARK("Multiply with transpose", [](benchpress::context* ctx) {
//  for (size_t i = 0; i < ctx->num_iterations(); ++i) {
//    mulWithTranspose();
//  }
//});