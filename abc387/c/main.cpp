#include "util/common.h"

s64 get_count(s64 front, s64 digit, const string& l, const string& r, bool b) {}

s64 powi(s64 x, s64 y) {
  if (y == 1) return x;
  return x * pow(x, y - 1);
}

int main() {
  string L, R;
  cin >> L >> R;

  vector<s64> values_l(R.size(), 0), values_r(R.size(), 0);
  for (s64 i = 0; i < R.size(); ++i) {
    values_r[i] = R[R.size() - 1 - i] - '0';
  }
  for (s64 i = 0; i < L.size(); ++i) {
    values_l[i] = L[L.size() - 1 - i] - '0';
  }

  s64 ans{0};
  // i桁目が先頭の場合を列挙
  for (s64 i = R.size() - 1; i >= 1; --i) {
    const s64 front_l = values_l[i];
    const s64 front_r = values_r[i];
    const s64 diff = front_r - front_l;

    // front = 先頭の数(1以上)
    for (s64 front = max(front_l, 1LL); front <= front_r; ++front) {
      ans += powi(front, i);  // number ignoring limit
      // 条件に合わないものを切り落とす
      for (s64 j = i; j >= 1; --j) {
        const s64 l = values_l[j - 1];
        const s64 r = values_r[j - 1];
        const s64 n = std::max(0LL, (front - 1LL) - r) +
                      std::max(0LL, (front - 1LL) - l) + l;
        ans -= n * powi(front, j - 1);
      }
    }
  }

  cout << ans << endl;
}