#include <sycl/sycl.hpp>

void matrix_transpose_kernel(sycl::queue& q, sycl::nd_range<2> launchRange, const float* input,
                             float* output, int rows, int cols) {}

// input, output are device pointers (i.e. pointers to memory on the GPU)
extern "C" void solve(const float* input, float* output, int rows, int cols) {
    sycl::queue q{sycl::property::queue::in_order()};
    sycl::range<2> workGroupSize(16, 16);
    sycl::range<2> numWorkGroups((cols + workGroupSize[0] - 1) / workGroupSize[0],
                                 (rows + workGroupSize[1] - 1) / workGroupSize[1]);
    sycl::nd_range<2> launchRange(
        sycl::range<2>(numWorkGroups[0] * workGroupSize[0], numWorkGroups[1] * workGroupSize[1]),
        workGroupSize);

    matrix_transpose_kernel(q, launchRange, input, output, rows, cols);
    q.wait();
}
