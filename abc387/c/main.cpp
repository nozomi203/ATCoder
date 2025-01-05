#include "util/common.h"
#include "util/digit.h"

s64 powi(s64 x, s64 y) {
  if (y == 1) return x;
  return x * pow(x, y - 1);
}

vector<s64> itovec(s64 i) {
  vector<s64> ret;
  while (i > 0) {
    s64 d = i % 10;
    i /= 10;
    ret.push_back(d);
  }
  std::reverse(ret.begin(), ret.end());
  return ret;
}

bool is_snake_num(u64 num) {
  const auto max_digit = util::get_max_digit(num);
  if (max_digit < 1) return false;
  const auto front = util::get_value_at(num, max_digit);
  for (auto digit = max_digit - 1; digit >= 0; --digit) {
    if (util::get_value_at(num, digit) >= front) return false;
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
  for (u64 i = max_digit; i >= 0; --i) {
    const auto v = util::get_value_at(max, i);
    if (i < max_digit && v >= front) break;
    ans += std::min(v, front) * powi(front, i);
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