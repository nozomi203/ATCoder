#include "util/common.h"

int main() {
  u64 a, n;
  cin >> a >> n;

  const auto check = [&](size_t v) -> bool {
    vector<size_t> seq;
    while (v) {
      seq.push_back(v % a);
      v /= a;
    }

    for (s64 i = 0; i < seq.size() / 2; ++i) {
      if (seq[i] != seq[seq.size() - 1 - i]) return false;
    }
    return true;
  };

  size_t sum = 0;
  constexpr auto powmax = 12;
  vector<vector<size_t>> vss(powmax + 1);
  vss[0].push_back(0);
  vss[1].push_back(0);
  for (size_t i = 1; i < 10; ++i) {
    vss[0].push_back(i);
    if (i <= n && check(i)) {
      sum += i;
    }
    vss[1].push_back(i * 10 + i);
    if (i * 10 + i <= n && check(i * 10 + i)) {
      sum += i * 10 + i;
    }
  }

  vector<size_t> pow10s(powmax + 1);
  pow10s[0] = 1;
  for (size_t i = 1; i <= powmax; ++i) pow10s[i] = pow10s[i - 1] * 10;

  for (size_t pow = 2; pow <= powmax; ++pow) {
    if (pow10s[pow] > n) break;
    for (s64 ppow = pow - 2; ppow >= 0; ppow -= 2) {
      for (const auto v : vss[ppow]) {
        for (size_t j = 1; j < 10; ++j) {
          const size_t nxt = j * pow10s[pow] + v * pow10s[(pow - ppow) / 2] + j;
          if (nxt > n) break;
          vss[pow].push_back(nxt);
          if (check(nxt)) {
            sum += nxt;
          }
        }
      }
    }
  }

  cout << sum << endl;
}