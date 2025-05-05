#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  double a, b, x;
  cin >> a >> b >> x;

  const auto get = [&]() -> double {
    if (x < a * a * b * 0.5) {
      return atan((a * b * b) / (2 * x)) * 180.0 / numbers::pi;
    } else {
      double v = 2.0 * (a * a * b - x) / (a * a * a);
      return atan(v) * 180.0 / numbers::pi;
    }
  };
  cout << fixed << setprecision(16) << get() << endl;
}