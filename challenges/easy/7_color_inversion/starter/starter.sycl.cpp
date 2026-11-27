#include <sycl/sycl.hpp>

void invert_kernel(sycl::queue& q, sycl::nd_range<1> launchRange, unsigned char* image, int width,
                   int height) {}

// image is a device pointer (i.e. pointer to memory on the GPU)
extern "C" void solve(unsigned char* image, int width, int height) {
    sycl::queue q{sycl::property::queue::in_order()};
    int workGroupSize = 256;
    int numWorkGroups = (width * height + workGroupSize - 1) / workGroupSize;
    sycl::nd_range<1> launchRange(sycl::range<1>(numWorkGroups * workGroupSize),
                                  sycl::range<1>(workGroupSize));

    invert_kernel(q, launchRange, image, width, height);
    q.wait();
}
