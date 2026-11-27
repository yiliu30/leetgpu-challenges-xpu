#include <sycl/sycl.hpp>

void matrix_multiplication_kernel(sycl::queue& q, sycl::nd_range<2> launchRange, const float* A,
                                  const float* B, float* C, int M, int N, int K) {}

// A, B, C are device pointers (i.e. pointers to memory on the GPU)
extern "C" void solve(const float* A, const float* B, float* C, int M, int N, int K) {
    sycl::queue q{sycl::property::queue::in_order()};
    sycl::range<2> workGroupSize(16, 16);
    sycl::range<2> numWorkGroups((K + workGroupSize[0] - 1) / workGroupSize[0],
                                 (M + workGroupSize[1] - 1) / workGroupSize[1]);
    sycl::nd_range<2> launchRange(
        sycl::range<2>(numWorkGroups[0] * workGroupSize[0], numWorkGroups[1] * workGroupSize[1]),
        workGroupSize);

    matrix_multiplication_kernel(q, launchRange, A, B, C, M, N, K);
    q.wait();
}
