#include "util/common.h"

int main() {
  s64 n, m, k;
  cin >> n >> m >> k;
  vector<pair<s64, s64>> abs(k);
  util::cin(abs);
  vector<s64> cnts(n + 1);
  vector<s64> ans;
  for (auto [a, b] : abs) {
    if (++cnts[a] == m) {
      ans.push_back(a);
    }
  }

  if (!ans.empty()) {
    for (s64 i = 0; i < ans.size(); ++i) {
      cout << ans[i];
      if (i < ans.size() - 1) cout << " ";
    }
  }
  cout << endl;
}