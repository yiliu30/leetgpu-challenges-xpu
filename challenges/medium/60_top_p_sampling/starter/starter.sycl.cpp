#include <sycl/sycl.hpp>

// logits, p, seed, sampled_token are device pointers
extern "C" void solve(const float* logits, const float* p, const int* seed, int* sampled_token,
                      int vocab_size) {}
