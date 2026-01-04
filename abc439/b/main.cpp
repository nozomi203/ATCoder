#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  const auto check = [&]() -> bool {
    vector<bool> bs(2027, false);
    while (!bs[n]) {
      bs[n] = true;
      s64 m = 0;
      while (n) {
        s64 k = n % 10;
        m += k * k;
        n /= 10;
      }
      n = m;
      if (n == 1) return true;
    }
    return false;
  };
  cout << (check() ? "Yes" : "No") << endl;
}