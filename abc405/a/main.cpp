#include "util/common.h"

int main() {
  s64 r, x;
  cin >> r >> x;
  const auto get = [&]() -> bool {
    if (x == 1) {
      return 1600 <= r && r <= 2999;
    } else {
      return 1200 <= r && r <= 2399;
    }
  };
  cout << (get() ? "Yes" : "No") << endl;
}