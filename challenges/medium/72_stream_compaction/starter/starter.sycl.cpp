#include <sycl/sycl.hpp>

// A, out are device pointers
extern "C" void solve(const float* A, int N, float* out) {}
