#include <atcoder/fenwicktree>

#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  string s;
  cin >> s;

  vector<s64> sumas(n), sumbs(n), sumasbs(n);
  sumas[0] = s[0] == 'A' ? 1 : 0;
  sumbs[0] = s[0] == 'B' ? 1 : 0;
  sumasbs[0] = sumas[0] - sumbs[0];
  for (s64 i = 1; i < n; ++i) {
    sumas[i] = sumas[i - 1] + (s[i] == 'A' ? 1 : 0);
    sumbs[i] = sumbs[i - 1] + (s[i] == 'B' ? 1 : 0);
    sumasbs[i] = sumas[i] - sumbs[i];
  }

  const s64 offset = n;
  atcoder::fenwick_tree<s64> ft(2 * n + 1);
  for (s64 i = 0; i < n; ++i) {
    ft.add(sumasbs[i] + offset, 1);
  }

  s64 ans = 0;
  ans += ft.sum(1 + offset, 2 * n + 1);
  ft.add(sumasbs[0] + offset, -1);
  for (s64 i = 1; i < n; ++i) {
    s64 val = ft.sum(1 + offset + sumasbs[i - 1], 2 * n + 1);
    ans += val;
    ft.add(sumasbs[i] + offset, -1);
  }
  cout << ans << endl;
}