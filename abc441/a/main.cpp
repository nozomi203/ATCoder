#include "util/common.h"

int main() {
  s64 p, q, x, y;
  cin >> p >> q >> x >> y;
  const auto check = [&]() -> bool {
    if (x < p) return false;
    if (x >= p + 100) return false;
    if (y < q) return false;
    if (y >= q + 100) return false;
    return true;
  };
  cout << (check() ? "Yes" : "No") << endl;
}