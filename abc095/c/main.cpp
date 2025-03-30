#include "util/common.h"

int main() {
  s64 a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  const auto get = [&]() -> size_t {
    return min({a * x + b * y, max(x, y) * 2 * c,
                min(x, y) * 2 * c + ((x > y) ? (x - y) * a : (y - x) * b)});
  };

  cout << get() << endl;
}