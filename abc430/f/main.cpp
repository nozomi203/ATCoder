#include "util/common.h"
#include "util/topological_sort.h"

/*
自分より前に来る必要のある数に対して辺を張り、グラフを構築する。
グラフから辿ることのできる頂点の数を数えると、その数がその頂点が配置されうるマス目の最小値となる。

*/

int main() {
  s64 t;
  cin >> t;
  vector<pair<s64, string>> nss(t);
  util::cin(nss);
  for (auto [n, s] : nss) {
    vector<vector<size_t>> g_nxt(n + 1), g_prv(n + 1);
    for (s64 i = 0; i < n - 1; ++i) {
      s64 from = i + 1;
      s64 to = i + 2;
      if (s[i] == 'L') swap(from, to);

      g_nxt[from].push_back(to);
      g_prv[to].push_back(from);
    }

    const auto [b_nxt, tsnxts] = util::topological_sort(g_nxt);
    const auto [b_prv, tsprvs] = util::topological_sort(g_prv);

    vector<s64> cnts_nxt(n + 1), cnts_prv(n + 1);

    for (auto tsnxt : tsnxts) {
      for (auto prv : g_prv[tsnxt]) {
        cnts_prv[tsnxt] += cnts_prv[prv] + 1;
      }
    }
    for (auto tsprv : tsprvs) {
      for (auto nxt : g_nxt[tsprv]) {
        cnts_nxt[tsprv] += cnts_nxt[nxt] + 1;
      }
    }

    vector<s64> cnts_imos(n + 2);
    for (s64 i = 1; i <= n; ++i) {
      const s64 cnt_prv = cnts_prv[i];
      const s64 cnt_nxt = cnts_nxt[i];
      const s64 cnt_rem = n - cnt_nxt - cnt_prv - 1;
      ++cnts_imos[1 + cnt_prv];
      --cnts_imos[1 + cnt_prv + cnt_rem + 1];
    }
    for (s64 i = 1; i <= n; ++i) {
      cnts_imos[i] += cnts_imos[i - 1];
    }

    for (s64 i = 1; i <= n; ++i) {
      cout << cnts_imos[i];
      if (i < n) cout << " ";
    }
    cout << endl;
  }
}