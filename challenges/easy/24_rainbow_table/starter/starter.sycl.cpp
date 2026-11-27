#include <sycl/sycl.hpp>

unsigned int fnv1a_hash(unsigned int input) {
    const unsigned int FNV_PRIME = 16777619;
    const unsigned int OFFSET_BASIS = 2166136261;

    unsigned int hash = OFFSET_BASIS;

    for (int byte_pos = 0; byte_pos < 4; byte_pos++) {
        unsigned char byte = (input >> (byte_pos * 8)) & 0xFFu;
        hash = (hash ^ byte) * FNV_PRIME;
    }

    return hash;
}

void fnv1a_hash_kernel(sycl::queue& q, sycl::nd_range<1> launchRange, const int* input,
                       unsigned int* output, int N, int R) {}

// input, output are device pointers (i.e. pointers to memory on the GPU)
extern "C" void solve(const int* input, unsigned int* output, int N, int R) {
    sycl::queue q{sycl::property::queue::in_order()};
    int workGroupSize = 256;
    int numWorkGroups = (N + workGroupSize - 1) / workGroupSize;
    sycl::nd_range<1> launchRange(sycl::range<1>(numWorkGroups * workGroupSize),
                                  sycl::range<1>(workGroupSize));

    fnv1a_hash_kernel(q, launchRange, input, output, N, R);
    q.wait();
}
