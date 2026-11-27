#include <sycl/sycl.hpp>

// input, output are device pointers
extern "C" void solve(const unsigned int* input, unsigned int* output, int N) {}
