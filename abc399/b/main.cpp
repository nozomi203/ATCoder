#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  map<s64, vector<s64>, greater<s64>> m;
  for (s64 i{0}; i < n; ++i) {
    s64 p;
    cin >> p;
    m[p].push_back(i);
  }

  vector<s64> ranks(n);
  s64 rank{1};
  for (auto& [p, vec] : m) {
    for (auto idx : vec) ranks[idx] = rank;
    rank += vec.size();
  }

  for (auto rank : ranks) cout << rank << endl;
}