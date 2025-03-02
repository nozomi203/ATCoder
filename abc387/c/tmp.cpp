#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\digit.h"

#line 4 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\digit.h"
#include <concepts>
#line 6 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\digit.h"
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

s64 powi(s64 val, s64 pow) {
  if (pow == 0) return 1;
  if (pow == 1) return val;
  return powi(val, pow / 2) * powi(val, pow - pow / 2);
}

s64 get_snake_num_count(s64 val) {
  vector<s64> v;
  while (val) {
    v.push_back(val % 10);
    val /= 10;
  }

  s64 ret{0};
  {  // iまでの数が一致している場合
    const s64 max_num = v.back();
    for (s64 i = v.size() - 1; i >= 0; --i) {
      if (i < v.size() - 1 && v[i] >= max_num) break;
      if (i > 0) {
        ret += min(max_num, v[i - 1]) * powi(max_num, max<s64>(0, i - 1));
      } else {
        ret += 1;
      }
    }
  }
  {  // 先頭が正の異なる数の場合
    for (s64 max_num = v.back() - 1; max_num >= 1; --max_num) {
      ret += powi(max_num, v.size() - 1);
    }
  }
  {
    for (s64 i = v.size() - 1; i >= 1; --i) {
      for (s64 j = 9; j >= 1; --j) {
        ret += powi(j, i - 1);
      }
    }
  }

  return ret;
}

int main() {
  u64 L, R;
  cin >> L >> R;
  cout << get_snake_num_count(R) - get_snake_num_count(L - 1) << endl;
}
