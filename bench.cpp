#define BENCHPRESS_CONFIG_MAIN
#include "benchpress/benchpress.hpp"
#include "matrix.h"
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

Matrix mul(bool transpose, int num_threads) {
  Matrix A(32, 32, 10);
  Matrix B(32, 32, 100);
  return A.multiply(B, transpose, num_threads);
}

BENCHMARK("Multiply without transpose. 1 thread", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(false, 1);
});

BENCHMARK("Multiply with transpose. 1 thread", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(true, 1);
});

BENCHMARK("Multiply without transpose. 2 threads", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(false, 2);
});

BENCHMARK("Multiply with transpose. 2 threads", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(true, 2);
});

BENCHMARK("Multiply without transpose. 3 threads", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(false, 3);
});

BENCHMARK("Multiply with transpose. 3 threads", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(true, 3);
});

BENCHMARK("Multiply without transpose. 4 threads", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(false, 4);
});

BENCHMARK("Multiply with transpose. 4 threads", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(true, 4);
});

BENCHMARK("Multiply without transpose. 5 threads", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(false, 5);
});

BENCHMARK("Multiply with transpose. 5 threads", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(true, 5);
});

BENCHMARK("Multiply without transpose. 8 threads", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(false, 8);
});

BENCHMARK("Multiply with transpose. 8 threads", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(true, 8);
});

BENCHMARK("Multiply without transpose. 10 threads", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(false, 10);
});

BENCHMARK("Multiply with transpose. 10 threads", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(true, 10);
});

BENCHMARK("Multiply without transpose. 15 threads", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(false, 15);
});

BENCHMARK("Multiply with transpose. 15 threads", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(true, 15);
});

BENCHMARK("Multiply without transpose. 20 threads", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(false, 20);
});

BENCHMARK("Multiply with transpose. 20 threads", [](benchpress::context* ctx) {
  for (size_t i = 0; i < ctx->num_iterations(); ++i)
    mul(true, 20);
});