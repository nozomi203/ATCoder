#include "util/common.h"

/*
辺の追加前は駅tへk分以内に移動することは不可能とする
iを固定したとき、
i<j
and
sdists[i] + l + tdists[j] < k
or
tdists[i] + l + sdists[j] < k
の条件を満たすjの数を数えたい。
これがどちらも満たされることはあるか？どちらも満たされるとき
tdists[i] > tdists[j]
tdists[j] > tdists[i]
がいずれも成り立つ。これは明らかに矛盾なので、条件はどちらか一方しか満たされない。
つまり、かならずi→jの順に辺を通行するとしてi,jの大小を気にせず数え上げた場合の数がそのまま答え
iを固定したとき、
sdists[i] + l + tdists[j] <= kを満たすようなjの数を数える。
あらかじめtdists[j]の値が昇順になるようにjをソートしておけばbinary searchできる
*/

constexpr s64 inf = numeric_limits<s64>::max();

int main() {
  s64 n, m;
  s64 s, t, l, k;
  cin >> n >> m;
  cin >> s >> t >> l >> k;
  --s;
  --t;
  vector<tuple<s64, s64, s64>> abcs(m);
  util::cin(abcs);

  vector<vector<pair<s64, s64>>> g(n);
  for (auto& [a, b, c] : abcs) {
    --a;
    --b;
    g[a].push_back(make_pair(c, b));
    g[b].push_back(make_pair(c, a));
  }

  const auto djikstra = [&](s64 from, s64 to) -> vector<s64> {
    vector<s64> dists(n, inf);
    using elem_t = pair<s64, s64>;
    priority_queue<elem_t, vector<elem_t>, greater<elem_t>> pq;
    pq.push(make_pair(0, from));
    while (!pq.empty()) {
      auto [d, cur] = pq.top();
      pq.pop();

      if (dists[cur] <= d) continue;

      dists[cur] = d;

      for (auto [cnxt, nxt] : g[cur]) {
        const auto dnxt = d + cnxt;
        if (dists[nxt] <= dnxt) continue;
        pq.push(make_pair(dnxt, nxt));
      }
    }
    return dists;
  };

  const auto sdists = djikstra(s, t);
  const auto tdists = djikstra(t, s);

  auto tdists_sorted = tdists;
  sort(tdists_sorted.begin(), tdists_sorted.end());

  const auto get = [&]() -> s64 {
    /*すでにK分以内に到達できる場合は早期リターン*/
    if (sdists[t] <= k) return n * (n - 1) / 2;

    /* 新しい鉄道の端点iを全探索。
    これによってk分以内に到達できるようになる場合、
    その経路はかならず新しく追加した鉄道を通る
     */
    s64 cnt = 0;
    for (s64 i = 0; i < n; ++i) {
      const auto sdist = sdists[i];
      if (sdist == inf) continue;
      auto it = upper_bound(tdists_sorted.begin(), tdists_sorted.end(),
                            k - sdist - l);
      cnt += distance(tdists_sorted.begin(), it);
    }
    return cnt;
  };

  cout << get() << endl;
}