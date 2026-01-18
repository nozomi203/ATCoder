#include "util/common.h"

u64 f(u64 x) {
  u64 ret = 0;
  while (x) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}

int main() {
  s64 n;
  cin >> n;

  vector<u64> as(n + 1);
  as[0] = 1;
  for (u64 i = 1; i <= n; ++i) {
    for (u64 j = 0; j < i; ++j) {
      as[i] += f(as[j]);
    }
  }
  cout << as[n] << endl;
}