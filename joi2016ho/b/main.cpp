#include "util/common.h"

/*
すべて
*/
int main() {
  s64 n;
  cin >> n;
  string s;
  cin >> s;

  const auto ctoi = [](char c) -> int64_t {
    switch (c) {
      case 'J':
        return 0;
      case 'O':
        return 1;
      case 'I':
        return 2;
      default:
        assert(false);
        return -1;
    }
  };

  vector<array<s64, 3>> cntss(n + 2);
  for (size_t i = 0; i < n; ++i) cntss[i + 1][ctoi(s[i])]++;
  for (size_t i = 0; i <= n; ++i) {
    cntss[i + 1][0] += cntss[i][0];
    cntss[i + 1][1] += cntss[i][1];
    cntss[i + 1][2] += cntss[i][2];
  }

  int64_t cnt = 0;
  for (int64_t i = 1; i <= n; ++i) {
    if (s[i - 1] == 'O') cnt += cntss[i - 1][0] * (cntss[n][2] - cntss[i][2]);
  }

  int64_t add = 0;
  {
    int64_t oi = 0;
    for (int64_t i = 1; i <= n; ++i) {
      if (s[i - 1] == 'I') oi += cntss[i - 1][1];
    }
    add = max(add, oi);
  }
  {
    int64_t jo = 0;
    for (int64_t i = 1; i <= n; ++i) {
      if (s[i - 1] == 'O') jo += cntss[i - 1][0];
    }
    add = max(add, jo);
  }
  {
    for (size_t i = 0; i <= n; ++i) {
      add = max(add, cntss[i][0] * (cntss[n][2] - cntss[i][2]));
    }
  }

  cout << cnt + add << endl;
}