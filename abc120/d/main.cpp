#include <bits/stdc++.h>

#include <atcoder/dsu>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> abs(m);
  for (s64 i{0}; i < m; ++i) cin >> abs[i].first >> abs[i].second;

  atcoder::dsu dsu(n + 1);
  vector<s64> cnts(n + 1, 1);
  vector<s64> answers(m);
  answers[m - 1] = n * (n - 1) / 2;
  for (s64 i{m - 2}; i >= 0; --i) {
    answers[i] = answers[i + 1];
    auto [a, b] = abs[i + 1];
    const auto la = dsu.leader(a);
    const auto lb = dsu.leader(b);
    if (la != lb) {
      const auto l = dsu.merge(a, b);
      answers[i] -= cnts[la] * cnts[lb];
      if (l == la) {
        cnts[la] += cnts[lb];
        cnts[lb] = 0;
      } else {
        cnts[lb] += cnts[la];
        cnts[la] = 0;
      }
    }
  }

  for (auto ans : answers) cout << ans << endl;
}