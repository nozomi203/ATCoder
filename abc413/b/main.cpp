#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<string> ss(n);
  util::cin(ss);
  set<string> sset;
  for (s64 i = 0; i < n; ++i) {
    for (s64 j = 0; j < n; ++j) {
      if (i == j) continue;
      sset.emplace(ss[i] + ss[j]);
    }
  }
  cout << sset.size() << endl;
}