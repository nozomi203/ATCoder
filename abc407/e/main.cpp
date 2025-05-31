#include "util/common.h"

int main() {
  s64 t;
  cin >> t;
  vector<vector<s64>> as(t);
  for (size_t i{0}; i < t; ++i) {
    s64 n;
    cin >> n;
    as[i].resize(2 * n);
    for (size_t j{0}; j < 2 * n; ++j) cin >> as[i][j];
  }
  for (size_t i{0}; i < t; ++i) {
    const auto& a{as[i]};
    priority_queue<s64> q;
    s64 ans{a[0]};
    for (s64 i{0}; i < a.size() / 2 - 1; ++i) {
      q.push(a[2 * i + 1]);
      q.push(a[2 * i + 2]);
      ans += q.top();
      q.pop();
    }
    cout << ans << endl;
  }
}