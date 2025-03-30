#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> a(n), b(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];
  for (s64 i{0}; i < n; ++i) cin >> b[i];
  cout << *max_element(a.begin(), a.end()) + *max_element(b.begin(), b.end())
       << endl;
}