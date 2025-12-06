#include "util/common.h"

int main() {
  s64 x, y, z;
  cin >> x >> y >> z;

  const auto check = [&]() -> bool {
    if (x - z * y < 0) return false;
    if ((x - z * y) % (z - 1) != 0) return false;
    return true;
  };

  cout << (check() ? "Yes" : "No") << endl;
}