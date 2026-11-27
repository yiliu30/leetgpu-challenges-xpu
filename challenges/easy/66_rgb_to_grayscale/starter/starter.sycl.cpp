#include <sycl/sycl.hpp>

void rgb_to_grayscale_kernel(sycl::queue& q, sycl::nd_range<1> launchRange, const float* input,
                             float* output, int width, int height) {}

// input, output are device pointers (i.e. pointers to memory on the GPU)
extern "C" void solve(const float* input, float* output, int width, int height) {
    sycl::queue q{sycl::property::queue::in_order()};
    int total_pixels = width * height;
    int workGroupSize = 256;
    int numWorkGroups = (total_pixels + workGroupSize - 1) / workGroupSize;
    sycl::nd_range<1> launchRange(sycl::range<1>(numWorkGroups * workGroupSize),
                                  sycl::range<1>(workGroupSize));

    rgb_to_grayscale_kernel(q, launchRange, input, output, width, height);
    q.wait();
}
