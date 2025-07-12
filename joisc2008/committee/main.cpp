#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> sas(n);
  util::cin(sas);
  for (auto& [s, a] : sas) --s;

  s64 root = -1;
  vector<vector<s64>> g(n);
  for (s64 i = 0; i < n; ++i) {
    auto [s, a] = sas[i];
    if (s == -1) {
      root = i;
    } else {
      g[s].push_back(i);
    }
  }

  vector<s64> maxsuma(n, 0);
  vector<bool> opened(n, false);
  stack<s64> s;
  s.push(root);
  while (!s.empty()) {
    auto idx = s.top();
    if (opened[idx]) {
      s64 suma = sas[idx].second;
      {
        vector<s64> sumcas(g[idx].size());
        for (s64 i = 0; i < g[idx].size(); ++i) {
          sumcas[i] = maxsuma[g[idx][i]];
        }
        sort(sumcas.begin(), sumcas.end(), greater());
        for (auto sumca : sumcas) {
          if (sumca < 0) break;
          suma += sumca;
        }
      }
      maxsuma[idx] = suma;

      s.pop();
    } else {
      opened[idx] = true;
      for (auto nxt : g[idx]) s.push(nxt);
    }
  }

  cout << *max_element(maxsuma.begin(), maxsuma.end()) << endl;
}