#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

s64 get_quater(s64 r) {
  s64 ans{0};
  s64 len{r};
  const auto square_len = [](double a, double b) { return a * a + b * b; };
  for (s64 i = 1; i <= r - 1; ++i) {
    while (square_len((double)i + 0.5, (double)len + 0.5) > r * r) --len;
    ans += len;
  }
  return ans;
}

int main() {
  s64 R;
  cin >> R;
  s64 ans{0};
  ans += 1;
  ans += (R - 1) * 4;
  ans += get_quater(R) * 4;
  cout << ans << endl;
}
