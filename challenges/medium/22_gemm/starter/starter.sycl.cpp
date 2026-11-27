#include <sycl/sycl.hpp>

// A, B, and C are device pointers
extern "C" void solve(const sycl::half* A, const sycl::half* B, sycl::half* C, int M, int N, int K,
                      float alpha, float beta) {}
