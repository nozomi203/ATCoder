#include "util/common.h"

/*
kこの文字列を選択してその順番につなげる
*/

s64 pow(s64 n, s64 p) {
  if (p == 0) return 1;
  return n * pow(n, p - 1);
}

int main() {
  s64 n, k, x;
  cin >> n >> k >> x;
  --x;
  vector<string> ss(n);
  util::cin(ss);

  const size_t cnt = pow(n, k);
  vector<string> cands(cnt);
  for (size_t mask = 0; mask < cnt; ++mask) {
    string s;
    size_t tmp = mask;
    for (size_t i = 0; i < k; ++i) {
      size_t idx = tmp % n;
      s += ss[idx];
      tmp /= n;
    }
    cands[mask] = move(s);
  }
  sort(cands.begin(), cands.end());
  cout << cands[x] << endl;
}