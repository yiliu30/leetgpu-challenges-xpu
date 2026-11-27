#include <sycl/sycl.hpp>

void reverse_array(sycl::queue& q, sycl::nd_range<1> launchRange, float* input, int N) {}

// input is a device pointer (i.e. pointer to memory on the GPU)
extern "C" void solve(float* input, int N) {
    sycl::queue q{sycl::property::queue::in_order()};
    int workGroupSize = 256;
    int numWorkGroups = (N + workGroupSize - 1) / workGroupSize;
    sycl::nd_range<1> launchRange(sycl::range<1>(numWorkGroups * workGroupSize),
                                  sycl::range<1>(workGroupSize));

    reverse_array(q, launchRange, input, N);
    q.wait();
}
