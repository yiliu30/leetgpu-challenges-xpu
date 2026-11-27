#include <sycl/sycl.hpp>

// positions, masses, forces are device pointers
extern "C" void solve(const float* positions, const float* masses, float* forces, int N) {}
