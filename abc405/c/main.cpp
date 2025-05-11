#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> a(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];
  vector<s64> suma(n);
  suma[0] = a[0];
  for (s64 i{1}; i < n; ++i) {
    suma[i] = suma[i - 1] + a[i];
  }

  s64 ans{0};
  for (s64 i{0}; i < n - 1; ++i) {
    ans += a[i] * (suma[n - 1] - suma[i]);
  }
  cout << ans << endl;
}