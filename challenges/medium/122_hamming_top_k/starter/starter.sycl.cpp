#include <sycl/sycl.hpp>

// codes, query, output are device pointers
extern "C" void solve(const int* codes, const int* query, int* output, int N, int k) {}
