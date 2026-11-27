#include <sycl/sycl.hpp>

// signal and spectrum are device pointers
extern "C" void solve(const float* signal, float* spectrum, int N) {}
