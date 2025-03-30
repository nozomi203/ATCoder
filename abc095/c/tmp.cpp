#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  const auto get = [&]() -> size_t {
    return min({a * x + b * y, max(x, y) * 2 * c,
                min(x, y) * 2 * c + ((x > y) ? (x - y) * a : (y - x) * b)});
  };

  cout << get() << endl;
}
