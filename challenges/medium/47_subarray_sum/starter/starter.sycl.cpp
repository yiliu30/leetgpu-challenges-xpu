#include <sycl/sycl.hpp>

// input, output are device pointers
extern "C" void solve(const int* input, int* output, int N, int S, int E) {}
