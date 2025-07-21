#include "util/common.h"

/*

*/

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> as(n);
  util::cin(as);
  vector<pair<s64, s64>> lrs(m);
  util::cin(lrs);
  sort(lrs.begin(), lrs.end());

  vector<s64> heads(n);
  {
    vector<vector<s64>> imos_begin(n), imos_end(n);
    for (s64 i = 0; i < m; ++i) {
      auto& [l, r] = lrs[i];
      --l;
      --r;
      imos_begin[l].push_back(i);
      imos_end[r].push_back(i);
    }

    map<s64, s64> s;
    for (s64 i = 0; i < n; ++i) {
      for (auto idx : imos_begin[i]) ++s[lrs[idx].first];
      heads[i] = s.empty() ? i : s.begin()->first;
      for (auto idx : imos_end[i])
        if (--s[lrs[idx].first] == 0) s.erase(lrs[idx].first);
    }

    /*dp[i]=iまでのイルミを考慮したときの美しさの総和の最大値*/
    vector<s64> dp(n, 0);
    dp[0] = as[0];
    for (s64 i = 1; i < n; ++i) {
      dp[i] = dp[i - 1];
      dp[i] = max(dp[i], heads[i] ? dp[heads[i] - 1] + as[i] : as[i]);
    }
    cout << dp[n - 1] << endl;
  }
}