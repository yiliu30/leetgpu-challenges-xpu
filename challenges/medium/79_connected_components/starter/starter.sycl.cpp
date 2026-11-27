#include <sycl/sycl.hpp>

// src, dst, labels are device pointers
extern "C" void solve(const int* src, const int* dst, int* labels, int N, int M) {}
