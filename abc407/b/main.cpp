#include "util/common.h"

int main() {
  s64 x, y;
  cin >> x >> y;
  s64 cnt{0};
  for (s64 i{1}; i <= 6; ++i) {
    for (s64 j{1}; j <= 6; ++j) {
      if (i + j >= x || abs(i - j) >= y) ++cnt;
    }
  }

  cout << fixed << setprecision(16) << cnt / 36.0 << endl;
}