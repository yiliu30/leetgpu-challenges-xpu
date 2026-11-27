#include <sycl/sycl.hpp>

// A, B, result are device pointers
extern "C" void solve(const float* A, const float* B, float* result, int N) {}
