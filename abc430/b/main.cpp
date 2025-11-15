#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<string> ss(n);
  util::cin(ss);

  set<string> sset;
  for (s64 i = 0; i < n - m + 1; ++i) {
    for (s64 j = 0; j < n - m + 1; ++j) {
      string s;
      for (s64 k = 0; k < m; ++k) {
        s += ss[i + k].substr(j, m);
      }
      sset.emplace(s);
    }
  }
  cout << sset.size() << endl;
}