#include "util/common.h"

int main() {
  s64 a, b, c, d;
  cin >> a >> b >> c >> d;
  const auto get = [&]() -> bool {
    if (a < c) return false;
    if (a > c) return true;
    return b > d;
  };
  cout << (get() ? "Yes" : "No") << endl;
}