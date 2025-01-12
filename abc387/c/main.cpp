#include "util/common.h"
#include "util/digit.h"

s64 powi(s64 x, s64 y) {
  if (y == 1) return x;
  return x * pow(x, y - 1);
}

vector<s64> int_to_vec(s64 i) {
  vector<s64> ret;
  while (i > 0) {
    ret.push_back(i % 10);
    i /= 10;
  }
  std::reverse(ret.begin(), ret.end());
  return ret;
}

bool is_snake_num(const vector<s64>& vec) {
  const auto max_digit = vec.size() - 1;
  if (max_digit < 1) return false;
  const auto front = vec[max_digit];
  for (s64 digit = max_digit - 1; digit >= 0; --digit) {
    if (vec[digit] >= front) return false;
  }
  return true;
}

/// @brief get count of snake number less than equal {max}
/// @param max
/// @return
u64 get_snake_num_count(const vector<s64>& vec) {
  u64 ans{0};
  // snake_num == max
  if (is_snake_num(vec)) ++ans;
  // 先頭i桁が一致
  const auto max_digit = vec.size() - 1;
  const auto front = vec[max_digit];
  for (s64 i = max_digit; i >= 1; --i) {
    const auto v = vec[i];
    if (i < max_digit && v >= front) break;
    ans += std::min(vec[i - 1], front) * powi(front, i - 1);
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

  vector<s64> vec_l(int_to_vec(L - 1)), vec_r(int_to_vec(R));

  u64 ans = get_snake_num_count(vec_r) - get_snake_num_count(vec_l);
  cout << ans << endl;
}