#pragma once

#include <cassert>
#include <concepts>
#include <cstdint>
#include <type_traits>

namespace util {

/// @brief get the most significant bit of 64bit integer v
template <std::unsigned_integral Int>
constexpr Int msb(Int v) {
  for (Int shift = 1; shift < sizeof(Int); shift <<= 1) v |= (v >> shift);
  return v ^ (v >> 1);
}

constexpr uint32_t bit_reverse(uint32_t v) {
  v = (v & 0x55555555) << 1 | (v >> 1 & 0x55555555);
  v = (v & 0x33333333) << 1 | (v >> 1 & 0x33333333);
  v = (v & 0x0f0f0f0f) << 1 | (v >> 1 & 0x0f0f0f0f);
  v = (v & 0x00ff00ff) << 1 | (v >> 1 & 0x00ff00ff);
  v = (v & 0x0000ffff) << 1 | (v >> 1 & 0x0000ffff);
  return v;
}

constexpr uint64_t bit_reverse(uint64_t v) {
  v = (v & 0x5555555555555555) << 1 | (v >> 1 & 0x5555555555555555);
  v = (v & 0x3333333333333333) << 1 | (v >> 1 & 0x3333333333333333);
  v = (v & 0x0f0f0f0f0f0f0f0f) << 1 | (v >> 1 & 0x0f0f0f0f0f0f0f0f);
  v = (v & 0x00ff00ff00ff00ff) << 1 | (v >> 1 & 0x00ff00ff00ff00ff);
  v = (v & 0x0000ffff0000ffff) << 1 | (v >> 1 & 0x0000ffff0000ffff);
  v = (v & 0x00000000ffffffff) << 1 | (v >> 1 & 0x00000000ffffffff);
  return v;
}

template <std::unsigned_integral Int>
constexpr Int bit_count(Int v) {
  assert(false);
  return {};
}

template <>
constexpr uint32_t bit_count(uint32_t v) {
  v = (v & 0x55555555) + (v >> 1 & 0x55555555);
  v = (v & 0x33333333) + (v >> 2 & 0x33333333);
  v = (v & 0x0f0f0f0f) + (v >> 4 & 0x0f0f0f0f);
  v = (v & 0x00ff00ff) + (v >> 8 & 0x00ff00ff);
  v = (v & 0x0000ffff) + (v >> 16 & 0x0000ffff);
  return v;
}

template <>
constexpr uint64_t bit_count(uint64_t v) {
  v = (v & 0x5555555555555555) + (v >> 1 & 0x5555555555555555);
  v = (v & 0x3333333333333333) + (v >> 2 & 0x3333333333333333);
  v = (v & 0x0f0f0f0f0f0f0f0f) + (v >> 4 & 0x0f0f0f0f0f0f0f0f);
  v = (v & 0x00ff00ff00ff00ff) + (v >> 8 & 0x00ff00ff00ff00ff);
  v = (v & 0x0000ffff0000ffff) + (v >> 16 & 0x0000ffff0000ffff);
  v = (v & 0x00000000ffffffff) + (v >> 32 & 0x00000000ffffffff);
  return v;
}

}  // namespace util