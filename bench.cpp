//#define BENCHPRESS_CONFIG_MAIN
//#include "benchpress/benchpress.hpp"
//#include "matrix.h"
//#include <chrono>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//Matrix mul(bool transpose, int num_threads) {
//  Matrix A(100, 100, 10);
//  Matrix B(100, 100, 100);
//  return A.multiply(B, transpose, num_threads);
//}
//
//BENCHMARK("Multiply without transpose. 1 thread", [](benchpress::context* ctx) {
//  for (size_t i = 0; i < ctx->num_iterations(); ++i) {
//    mul(false, 1);
//  }
//});
//
//BENCHMARK("Multiply with transpose. 1 thread", [](benchpress::context* ctx) {
//  for (size_t i = 0; i < ctx->num_iterations(); ++i) {
//    mul(true, 1);
//  }
//});
//
//BENCHMARK("Multiply without transpose. 2 threads", [](benchpress::context* ctx) {
//  for (size_t i = 0; i < ctx->num_iterations(); ++i) {
//    mul(false, 2);
//  }
//});
//
//BENCHMARK("Multiply with transpose. 2 threads", [](benchpress::context* ctx) {
//  for (size_t i = 0; i < ctx->num_iterations(); ++i) {
//    mul(true, 2);
//  }
//});
//
//BENCHMARK("Multiply without transpose. 3 threads", [](benchpress::context* ctx) {
//  for (size_t i = 0; i < ctx->num_iterations(); ++i) {
//    mul(false, 3);
//  }
//});
//
//BENCHMARK("Multiply with transpose. 3 threads", [](benchpress::context* ctx) {
//  for (size_t i = 0; i < ctx->num_iterations(); ++i) {
//    mul(true, 3);
//  }
//});
//
//BENCHMARK("Multiply without transpose. 5 threads", [](benchpress::context* ctx) {
//  for (size_t i = 0; i < ctx->num_iterations(); ++i) {
//    mul(false, 5);
//  }
//});
//
//BENCHMARK("Multiply with transpose. 5 threads", [](benchpress::context* ctx) {
//  for (size_t i = 0; i < ctx->num_iterations(); ++i) {
//    mul(true, 5);
//  }
//});
//
//BENCHMARK("Multiply without transpose. 10 threads", [](benchpress::context* ctx) {
//  for (size_t i = 0; i < ctx->num_iterations(); ++i) {
//    mul(false, 10);
//  }
//});
//
//BENCHMARK("Multiply with transpose. 10 threads", [](benchpress::context* ctx) {
//  for (size_t i = 0; i < ctx->num_iterations(); ++i) {
//    mul(true, 10);
//  }
//});