#include <sycl/sycl.hpp>

// input, output are device pointers
extern "C" void solve(const float* input, float* output, int N, int C, int H, int W,
                      int kernel_size, int stride, int padding) {}
