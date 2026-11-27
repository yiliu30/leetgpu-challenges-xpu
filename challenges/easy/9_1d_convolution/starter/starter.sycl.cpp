#include <sycl/sycl.hpp>

void convolution_1d_kernel(sycl::queue& q, sycl::nd_range<1> launchRange, const float* input,
                           const float* kernel, float* output, int input_size, int kernel_size) {}

// input, kernel, output are device pointers (i.e. pointers to memory on the GPU)
extern "C" void solve(const float* input, const float* kernel, float* output, int input_size,
                      int kernel_size) {
    sycl::queue q{sycl::property::queue::in_order()};
    int output_size = input_size - kernel_size + 1;
    int workGroupSize = 256;
    int numWorkGroups = (output_size + workGroupSize - 1) / workGroupSize;
    sycl::nd_range<1> launchRange(sycl::range<1>(numWorkGroups * workGroupSize),
                                  sycl::range<1>(workGroupSize));

    convolution_1d_kernel(q, launchRange, input, kernel, output, input_size, kernel_size);
    q.wait();
}
