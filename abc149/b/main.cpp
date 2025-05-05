#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 a, b, k;
  cin >> a >> b >> k;
  if (a <= k) {
    k -= a;
    a = 0;
  } else {
    a -= k;
    k = 0;
  }
  if (b <= k) {
    k -= b;
    b = 0;
  } else {
    b -= k;
    k = 0;
  }

  cout << a << " " << b << endl;
}