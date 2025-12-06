#include <atcoder/maxflow>

#include "util/common.h"

/*

S[0..N]は昇順に並んでいると考えて差し支えない
*/

int main() {
  s64 t;
  cin >> t;
  vector<pair<s64, vector<string>>> cases(t);
  for (auto& [n, ss] : cases) {
    cin >> n;
    ss.resize(n);
    util::cin(ss);
  }

  for (const auto& [n, ss] : cases) {
    sort(ss.begin(), ss.end());
  }
}