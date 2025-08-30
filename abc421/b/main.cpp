#include "util/common.h"

int main() {
  s64 x, y;
  cin >> x >> y;

  const auto calc = [&](auto self, s64 n) -> s64 {
    if (n == 1) return x;
    if (n == 2) return y;
    s64 v = self(self, n - 1) + self(self, n - 2);
    vector<s64> ds;
    while (v) {
      ds.push_back(v % 10);
      v /= 10;
    }

    s64 ret = 0;
    for (auto d : ds) {
      ret = ret * 10 + d;
    }
    return ret;
  };

  cout << calc(calc, 10) << endl;
}