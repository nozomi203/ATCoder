#include "util/common.h"

int main() {
  size_t n, q;
  cin >> n >> q;
  vector<tuple<size_t, size_t, string>> queries(q);
  for (auto& [i, p, s] : queries) {
    cin >> i >> p;
    --p;
    if (i == 2) cin >> s;
  }

  pair<size_t, size_t> server{0, 0};
  using record = tuple<size_t, size_t, string>;
  vector<vector<record>> pcs(n + 1, vector<record>(1));

  for (const auto& [i, p, s] : queries) {
    if (i == 1) {
      pcs[p].push_back(make_tuple(server.first, server.second, ""));
    } else if (i == 2) {
      pcs[p].push_back(make_tuple(p, pcs[p].size(), s));
    } else {
      server = make_pair(p, pcs[p].size() - 1);
    }
  }

  vector<string> ans;
  pair<size_t, size_t> pos = server;
  while (pos.first != 0 || pos.second != 0) {
    auto [idx0, idx1, s] = pcs[pos.first][pos.second];
    while (idx0 != pos.first || idx1 != pos.second) {
      pos.first = idx0;
      pos.second = idx1;
      tie(idx0, idx1, s) = pcs[pos.first][pos.second];
    }
    ans.push_back(s);
    if (idx0 == 0 && idx1 == 0) break;
    pos = make_pair(idx0, idx1 - 1);
  }
  reverse(ans.begin(), ans.end());
  for (const auto& s : ans) cout << s;
  cout << endl;
}