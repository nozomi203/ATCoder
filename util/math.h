#pragma once
#include <cstdint>

namespace util {
uint64_t powi(uint64_t value, uint64_t pow) {
  if (pow == 0) return 1;
  return value * powi(value, pow - 1);
}
}  // namespace util