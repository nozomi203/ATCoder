#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> b(n), w(m);
  for (s64 i{0}; i < n; ++i) cin >> b[i];
  for (s64 i{0}; i < m; ++i) cin >> w[i];
  sort(b.begin(), b.end(), greater());
  sort(w.begin(), w.end(), greater());

  const auto get = [&]() {
    s64 b_idx{0}, w_idx{0};
    s64 ans{0};
    while (b_idx < n && b[b_idx] >= 0) {
      ans += b[b_idx];
      ++b_idx;
    }
    while (w_idx < m && w_idx < b_idx && w[w_idx] >= 0) {
      ans += w[w_idx];
      ++w_idx;
    }

    if (w_idx < b_idx) return ans;
    while (b_idx < n && w_idx < m && b[b_idx] + w[w_idx] >= 0) {
      ans += b[b_idx] + w[w_idx];
      ++b_idx;
      ++w_idx;
    }
    return ans;
  };

  cout << get() << endl;
}
