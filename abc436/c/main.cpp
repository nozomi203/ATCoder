#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> rcs(m);
  util::cin(rcs);
  set<pair<s64, s64>> s;
  s64 cnt = 0;
  for (auto [r, c] : rcs) {
    if (s.contains(make_pair(r, c))) continue;
    if (s.contains(make_pair(r, c + 1))) continue;
    if (s.contains(make_pair(r + 1, c))) continue;
    if (s.contains(make_pair(r + 1, c + 1))) continue;
    s.emplace(make_pair(r, c));
    s.emplace(make_pair(r, c + 1));
    s.emplace(make_pair(r + 1, c));
    s.emplace(make_pair(r + 1, c + 1));
    cnt++;
  }

  cout << cnt << endl;
}