#pragma once

#include <cassert>
#include <concepts>
#include <cstdint>
#include <type_traits>

namespace util {

template <std::unsigned_integral UInt>
inline constexpr UInt get_max_digit(UInt value) {
  UInt digit{0};
  while (value / 10 > 0) {
    ++digit;
    value /= 10;
  }
  return digit;
}

template <std::unsigned_integral UInt>
inline constexpr UInt get_value_at(UInt value, UInt digit) {
  for (s64 d = digit; d > 0; --d) {
    value /= 10;
  }
  return value % 10;
}

}  // namespace util