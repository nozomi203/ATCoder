#include "util/common.h"

int main() {
  s64 n, w;
  cin >> n >> w;
  vector<s64> vs(n), ws(n);
  for (s64 i{0}; i < n; ++i) cin >> vs[i] >> ws[i];

  const s64 vmax = *max_element(vs.begin(), vs.end());
  const s64 wmax = *max_element(ws.begin(), ws.end());
  if (wmax <= 1000) {
    vector<vector<s64>> dp(n, vector<s64>(200001));
    dp[0][ws[0]] = vs[0];
    for (s64 i{1}; i < n; ++i) {
      for (s64 j{0}; j < 200001; ++j) {
        dp[i][j] = dp[i - 1][j];
        if (j >= ws[i]) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - ws[i]] + vs[i]);
        }
      }
    }
    s64 ans{0};
    for (s64 i{0}; i <= w; ++i) {
      ans = max(ans, dp[n - 1][i]);
    }
    cout << ans << endl;
  } else if (vmax <= 1000) {
    constexpr auto inf = numeric_limits<s64>::max();
    vector<vector<s64>> dp(n, vector<s64>(200001, inf));
    dp[0][0] = 0;
    dp[0][vs[0]] = ws[0];
    for (s64 i{1}; i < n; ++i) {
      for (s64 j{0}; j < 200001; ++j) {
        dp[i][j] = dp[i - 1][j];
        if (j >= vs[i] && (dp[i - 1][j - vs[i]] != inf)) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j - vs[i]] + ws[i]);
        }
      }
    }

    s64 ans{0};
    for (s64 i{0}; i < 200001; ++i) {
      if (dp[n - 1][i] <= w) {
        ans = i;
      }
    }
    cout << ans << endl;
  } else {
    if (n == 1) {
      cout << (ws[0] <= w ? vs[0] : 0) << endl;
      return 0;
    }
    const size_t n1{n / 2}, n2{n - n / 2};
    vector<pair<s64, s64>> wvp1, wvp2;
    for (s64 b{0}; b < (1 << n1); ++b) {
      s64 sumw{0}, sumv{0};
      for (s64 i{0}; i < n1; ++i) {
        if (b & (1 << i)) {
          sumw += ws[i];
          sumv += vs[i];
        }
      }
      wvp1.push_back(make_pair(sumw, sumv));
    }

    for (s64 b{0}; b < (1 << n2); ++b) {
      s64 sumw{0}, sumv{0};
      for (s64 i{0}; i < n2; ++i) {
        if (b & (1 << i)) {
          sumw += ws[n1 + i];
          sumv += vs[n1 + i];
        }
      }
      wvp2.push_back(make_pair(sumw, sumv));
    }
    sort(wvp2.begin(), wvp2.end());
    for (s64 i{1}; i < wvp2.size(); ++i) {
      wvp2[i].second = max(wvp2[i].second, wvp2[i - 1].second);
    }
    s64 ans{0};
    for (s64 i{0}; i < wvp1.size(); ++i) {
      auto it = lower_bound(
          wvp2.begin(), wvp2.end(), wvp1[i].first,
          [w](const auto& wvp, s64 w1) { return wvp.first + w1 <= w; });
      if (it == wvp2.begin()) continue;
      ans = max(ans, wvp1[i].second + prev(it)->second);
    }

    cout << ans << endl;
  }
}