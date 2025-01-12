#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\digit.h"

#line 4 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\digit.h"
#include <concepts>
#line 6 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\digit.h"
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
#line 3 "main.cpp"

s64 powi(s64 x, s64 y) {
  if (y == 1) return x;
  return x * pow(x, y - 1);
}

bool is_snake_num(u64 num) {
  const auto max_digit = util::get_max_digit(num);
  if (max_digit < 1) return false;
  const auto front = util::get_value_at(num, max_digit);
  for (s64 digit = max_digit - 1; digit >= 0; --digit) {
    if (util::get_value_at(num, static_cast<u64>(digit)) >= front) return false;
  }
  return true;
}

/// @brief get count of snake number less than equal {max}
/// @param max
/// @return
u64 get_snake_num_count(u64 max) {
  u64 ans{0};
  // snake_num == max
  if (is_snake_num(max)) ++ans;
  // 先頭i桁が一致
  const auto max_digit = util::get_max_digit(max);
  const auto front = util::get_value_at(max, max_digit);
  for (s64 i = max_digit; i >= 1; --i) {
    const auto v = util::get_value_at(max, static_cast<u64>(i));
    if (i < max_digit && v >= front) break;
    ans += std::min(util::get_value_at(max, static_cast<u64>(i - 1)), front) *
           powi(front, i - 1);
  }
  // 先頭が小さい
  for (u64 i = 1; i < front; ++i) {
    ans += powi(i, max_digit);
  }
  // 桁が小さい
  for (u64 digit = max_digit - 1; digit >= 1; --digit) {
    for (u64 i = 1; i <= 9; ++i) {
      ans += powi(i, digit);
    }
  }

  return ans;
}

int main() {
  u64 L, R;
  cin >> L >> R;

  u64 ans = get_snake_num_count(R) - get_snake_num_count(L - 1);
  cout << ans << endl;
}
