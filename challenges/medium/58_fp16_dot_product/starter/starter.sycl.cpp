#include <sycl/sycl.hpp>

// A, B, result are device pointers
extern "C" void solve(const sycl::half* A, const sycl::half* B, sycl::half* result, int N) {}
