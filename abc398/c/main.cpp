#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  map<s64, vector<s64>> m;
  for (s64 i{1}; i <= n; ++i) {
    s64 a;
    cin >> a;
    m[a].push_back(i);
  }

  for (auto rit = m.rbegin(); rit != m.rend(); ++rit) {
    if (rit->second.size() == 1) {
      cout << rit->second.front() << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}