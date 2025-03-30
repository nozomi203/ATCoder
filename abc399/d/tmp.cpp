#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 t;
  cin >> t;

  vector<s64> answers(t);

  for (s64 i{0}; i < t; ++i) {
    s64 n;
    cin >> n;
    vector<s64> a(n * 2);
    vector<pair<s64, s64>> idxs(n + 1, make_pair(-1, -1));

    for (s64 j{0}; j < n * 2; ++j) {
      cin >> a[j];
      idxs[a[j]].first < 0 ? idxs[a[j]].first = j : idxs[a[j]].second = j;
    }
    for (s64 j{0}; j < n * 2 - 1; ++j) {
      if (a[j] == a[j + 1]) continue;
      if (idxs[a[j]].first + 1 == idxs[a[j]].second) continue;
      if (idxs[a[j + 1]].first + 1 == idxs[a[j + 1]].second) continue;
      if (idxs[a[j]].first < j) continue;
      if (idxs[a[j + 1]].first < j + 1) continue;

      if (abs(idxs[a[j]].second - idxs[a[j + 1]].second) == 1) ++answers[i];
    }
  }

  for (auto ans : answers) cout << ans << endl;
}
