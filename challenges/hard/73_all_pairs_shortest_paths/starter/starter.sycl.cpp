#include <sycl/sycl.hpp>

// dist, output are device pointers
extern "C" void solve(const float* dist, float* output, int N) {}
