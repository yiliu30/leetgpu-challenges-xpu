#include <sycl/sycl.hpp>

// input, output are device pointers
extern "C" void solve(const float* input, float* output, int H, int W) {}
