#include <cstdint>
#include <sycl/sycl.hpp>

// x, w_q, scales, y are device pointers
extern "C" void solve(const sycl::half* x, const uint8_t* w_q, const sycl::half* scales,
                      sycl::half* y, int M, int N, int K, int group_size) {}
