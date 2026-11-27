#include <sycl/sycl.hpp>

// A, B, C are device pointers
extern "C" void solve(const float* A, const float* B, float* C, int M, int N) {}
