#line 2 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\bit.h"

#include <cassert>
#include <concepts>
#include <cstdint>
#include <type_traits>

namespace util {

/// @brief get the most significant bit of 64bit integer v
template <std::unsigned_integral Int>
constexpr uint64_t msb(uint64_t v) {
  for (Int shift = 1; shift < sizeof(Int); shift <<= 1) v |= (v >> shift);
  return v ^ (v >> 1);
}

template <std::unsigned_integral Int>
constexpr Int bit_reverse(Int v) {
  assert(false);
  return {};
}

template <>
constexpr uint32_t bit_reverse(uint32_t v) {
  v = (v & 0x55555555) << 1 | (v >> 1 & 0x55555555);
  v = (v & 0x33333333) << 1 | (v >> 1 & 0x33333333);
  v = (v & 0x0f0f0f0f) << 1 | (v >> 1 & 0x0f0f0f0f);
  v = (v & 0x00ff00ff) << 1 | (v >> 1 & 0x00ff00ff);
  v = (v & 0x0000ffff) << 1 | (v >> 1 & 0x0000ffff);
  return v;
}

template <>
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
#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 3 "main.cpp"

int main() {
  s64 n, k;
  cin >> n >> k;
  vector<s64> a(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];

  s64 ans{numeric_limits<s64>::max()};
  for (u64 b{0}; b < (1 << n); ++b) {
    if (util::bit_count(b) != k) continue;
    s64 cost{0};
    s64 max_height{0};
    for (s64 i{0}; i < n; ++i) {
      if (b & (1 << i)) {
        if (a[i] <= max_height) {
          cost += (max_height + 1) - a[i];
          ++max_height;
        } else {
          max_height = a[i];
        }
      } else {
        max_height = max(max_height, a[i]);
      }
    }

    ans = min(ans, cost);
  }

  cout << ans << endl;
}
