#include <sycl/sycl.hpp>

void swiglu_kernel(sycl::queue& q, sycl::nd_range<1> launchRange, const float* input, float* output,
                   int halfN) {}

// input, output are device pointers (i.e. pointers to memory on the GPU)
extern "C" void solve(const float* input, float* output, int N) {
    sycl::queue q{sycl::property::queue::in_order()};
    int halfN = N / 2;
    int workGroupSize = 256;
    int numWorkGroups = (halfN + workGroupSize - 1) / workGroupSize;
    sycl::nd_range<1> launchRange(sycl::range<1>(numWorkGroups * workGroupSize),
                                  sycl::range<1>(workGroupSize));

    swiglu_kernel(q, launchRange, input, output, halfN);
    q.wait();
}
