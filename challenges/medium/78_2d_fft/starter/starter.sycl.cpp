#include <sycl/sycl.hpp>

// signal, spectrum are device pointers
extern "C" void solve(const float* signal, float* spectrum, int M, int N) {}
