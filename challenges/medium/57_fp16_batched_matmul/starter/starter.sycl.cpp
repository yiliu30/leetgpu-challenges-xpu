#include <sycl/sycl.hpp>

// A, B, C are device pointers
extern "C" void solve(const sycl::half* A, const sycl::half* B, sycl::half* C, int BATCH, int M,
                      int N, int K) {}
