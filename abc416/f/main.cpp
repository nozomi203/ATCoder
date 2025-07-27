#include "util/common.h"

int main() {
  s64 n, k;
  cin >> n >> k;
  vector<s64> as(n);
  util::cin(as);
  vector<pair<s64, s64>> uvs(n - 1);
  util::cin(uvs);

  vector<vector<s64>> g(n);
  for (auto& [u, v] : uvs) {
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<s64> ps(n, -1);
  vector<s64> idxs(n, -1);
  {
    queue<s64> q;
    q.push(0);
    while (!q.empty()) {
      const s64 cur = q.front();
      for (s64 i = 0; i < g[cur].size(); ++i) {
        const auto nxt = g[cur][i];
        if (ps[nxt] < 0) {
          ps.push_back(nxt);
          idxs[nxt] = i;
        } else {
          ps[cur] = nxt;
        }
      }
    }
  }
  vector<bool> used(n, false);

  for (s64 i = 0; i < k; ++i) {
    stack<s64> s;
    for (s64 j = 0; j < n; ++j)
      if (ps[j] < 0 || used[ps[j]]) s.push(j);

    vector<vector<s64>> sumamaxs(n); /*頂点iのj番目の辺の先のaの合計の最大*/
    vector<bool> visited(n);
    while (!s.empty()) {
      auto cur = s.top();
      if (visited[cur]) {
        for (s64 j = 0; j < g[cur].size(); ++j) {
          auto nxt = g[cur][j];
          if (used[nxt]) continue;
          if (nxt == ps[cur]) continue;

          s64 sumamax = 0;
          for (auto j2 = 0; j2 < g[nxt].size(); ++j2) {
            sumamax = max(sumamax, sumamaxs[nxt][j2]);
          }
          sumamaxs[cur][j] = sumamax + as[nxt];
        }
      } else {
        visited[cur] = true;
        for (auto nxt : g[cur]) {
          if (used[nxt]) continue;
          if (nxt == ps[cur]) continue;
          s.push(nxt);
        }
      }
    }

    for (s64 j = 0; j < n; ++j)
      if (ps[j] < 0 || used[ps[j]]) s.push(j);
    while (!s.empty()) {
      const auto cur = s.top();
      s.pop();

      for (size_t j = 0; j < g[cur].size(); ++j) {
        const auto nxt = g[cur][j];
        if (used[nxt]) continue;
        if (nxt == ps[cur]) {
          s64 sumamax = 0;
          for (size_t j2 = 0; j2 < g[ps[cur]].size(); ++j2) {
            if (j2 == idxs[cur]) continue;
            sumamax = max(sumamax, sumamaxs[ps[cur]][j2]);
          }
          sumamaxs[cur][j] = sumamax + as[ps[cur]];
        } else {
          s.push(nxt);
        }
      }
    }
  }
}