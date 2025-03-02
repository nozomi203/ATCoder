#include "util/common.h"
#include "util/digit.h"

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