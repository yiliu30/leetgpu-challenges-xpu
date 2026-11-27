#include <sycl/sycl.hpp>

void matrix_add(sycl::queue& q, sycl::nd_range<1> launchRange, const float* A, const float* B,
                float* C, int N) {}

// A, B, C are device pointers (i.e. pointers to memory on the GPU)
extern "C" void solve(const float* A, const float* B, float* C, int N) {
    sycl::queue q{sycl::property::queue::in_order()};
    int workGroupSize = 256;
    int numWorkGroups = (N * N + workGroupSize - 1) / workGroupSize;
    sycl::nd_range<1> launchRange(sycl::range<1>(numWorkGroups * workGroupSize),
                                  sycl::range<1>(workGroupSize));

    matrix_add(q, launchRange, A, B, C, N);
    q.wait();
}
