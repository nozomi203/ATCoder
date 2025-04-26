#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;
using s16 = int16_t;

using namespace std;

int main() {
  s32 n, k;
  cin >> n >> k;
  vector<s32> c(n), r(n);
  for (s32 i{0}; i < n; ++i) cin >> c[i] >> r[i];
  vector<vector<s16>> g(n);
  for (s32 i{0}; i < k; ++i) {
    s16 a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }

  vector<vector<pair<s16, s16>>> g2(n);

  for (s16 i{0}; i < n; ++i) {
    g2[i].reserve(n);
    vector<bool> opn(n);
    queue<pair<s16, s16>> s;
    s.push(make_pair(i, 0));
    while (!s.empty()) {
      auto [cur, d] = s.front();
      s.pop();
      opn[cur] = true;
      if (d >= r[i]) continue;
      for (s16 nxt : g[cur]) {
        if (opn[nxt]) continue;
        s.push(make_pair(nxt, d + 1));
        g2[i].push_back(make_pair(c[i], nxt));
      }
    }
    g2[i].shrink_to_fit();
  }

  g.clear();

  vector<s32> costs(n, numeric_limits<s32>::max());
  using dnp = pair<s32, s32>;
  priority_queue<dnp, deque<dnp>, greater<dnp>> pq;
  pq.push(make_pair(0, 0));
  costs[0] = 0;
  while (!pq.empty()) {
    auto [c_cur, cur] = pq.top();
    pq.pop();
    for (auto [c, nxt] : g2[cur]) {
      auto c_nxt = c_cur + c;
      if (c_nxt >= costs[nxt]) continue;
      costs[nxt] = c_nxt;
      pq.push(make_pair(c_nxt, nxt));
    }
  }

  cout << costs[n - 1] << endl;
}