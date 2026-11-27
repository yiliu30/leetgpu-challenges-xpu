#include <sycl/sycl.hpp>

void interleave_kernel(sycl::queue& q, sycl::nd_range<1> launchRange, const float* A,
                       const float* B, float* output, int N) {}

// A, B, output are device pointers (i.e. pointers to memory on the GPU)
extern "C" void solve(const float* A, const float* B, float* output, int N) {
    sycl::queue q{sycl::property::queue::in_order()};
    int workGroupSize = 256;
    int numWorkGroups = (N + workGroupSize - 1) / workGroupSize;
    sycl::nd_range<1> launchRange(sycl::range<1>(numWorkGroups * workGroupSize),
                                  sycl::range<1>(workGroupSize));

    interleave_kernel(q, launchRange, A, B, output, N);
    q.wait();
}
