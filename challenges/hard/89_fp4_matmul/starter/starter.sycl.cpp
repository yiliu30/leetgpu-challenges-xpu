#include <cstdint>
#include <sycl/sycl.hpp>

// x_q, x_scales, w_q, w_scales, y are device pointers
extern "C" void solve(const uint8_t* x_q, const uint8_t* x_scales, const uint8_t* w_q,
                      const uint8_t* w_scales, float alpha, sycl::half* y, int M, int N, int K) {}
