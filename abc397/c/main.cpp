#include "util/common.h"

int main() {
  s64 n;
  cin >> n;

  vector<s64> a(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];

  map<s64, s64> l, r;
  l[a[0]]++;
  for (s64 i{1}; i < n; ++i) r[a[i]]++;

  s64 ans{l.size() + r.size()};
  for (s64 i{1}; i < n - 1; ++i) {
    r[a[i]]--;
    if (r[a[i]] == 0) r.erase(a[i]);
    l[a[i]]++;
    ans = max<s64>(ans, l.size() + r.size());
  }

  cout << ans << endl;
}