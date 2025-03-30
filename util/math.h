#pragma once
#include <concepts>
#include <cstdint>

namespace util {
template <std::integral Int>
Int powi(Int value, uint64_t pow) {
  if (pow == 0) return 1;
  return value * powi(value, pow - 1);
}

uint64_t fact(uint64_t val) {
  if (val == 0) return 1;
  return val * fact(val - 1);
}
}  // namespace util