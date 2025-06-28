#include "util/common.h"

size_t toidx(char c) {
  switch (c) {
    case 'J':
      return 0;
    case 'O':
      return 1;
    case 'I':
      return 2;
    default:
      assert(false);
  }
}

int main() {
  size_t n;
  cin >> n;
  string s;
  cin >> s;

  using joicnt = array<int64_t, 3>;

  vector<joicnt> cnts(n);
  for (size_t i = 0; i < n; ++i) ++cnts[i][toidx(s[i])];
  for (size_t i = 1; i < n; ++i) {
    for (size_t j = 0; j < 3; ++j) cnts[i][j] += cnts[i - 1][j];
  }
  for (size_t i = 0; i < n; ++i) {
    // make count of O and I relative to count of J
    cnts[i][1] -= cnts[i][0];
    cnts[i][2] -= cnts[i][0];
    cnts[i][0] = 0;
  }

  map<joicnt, vector<size_t>> midxs;
  for (size_t i = 0; i < n; ++i) midxs[cnts[i]].push_back(i);

  size_t ans = 0;
  for (size_t i = 0; i < n; ++i) {
    if (all_of(cnts[i].begin(), cnts[i].end(),
               [](size_t cnt) { return cnt == 0; })) {
      ans = max(ans, i + 1);
      continue;
    }
    auto& idxs = midxs[cnts[i]];
    if (idxs.empty()) continue;
    if (idxs.front() >= i) continue;
    ans = max(ans, i - idxs.front());
  }
  cout << ans << endl;
}