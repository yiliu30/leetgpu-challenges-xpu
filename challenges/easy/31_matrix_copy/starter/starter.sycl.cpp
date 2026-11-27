#include <sycl/sycl.hpp>

void copy_matrix_kernel(sycl::queue& q, sycl::nd_range<1> launchRange, const float* A, float* B,
                        int total) {}

// A, B are device pointers (i.e. pointers to memory on the GPU)
extern "C" void solve(const float* A, float* B, int N) {
    sycl::queue q{sycl::property::queue::in_order()};
    int total = N * N;
    int workGroupSize = 256;
    int numWorkGroups = (total + workGroupSize - 1) / workGroupSize;
    sycl::nd_range<1> launchRange(sycl::range<1>(numWorkGroups * workGroupSize),
                                  sycl::range<1>(workGroupSize));

    copy_matrix_kernel(q, launchRange, A, B, total);
    q.wait();
}
