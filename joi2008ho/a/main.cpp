#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> cnts;
  for (s64 i{0}; i < n; ++i) {
    s64 c;
    cin >> c;
    if (i % 2) {
      if (cnts.back().first != c) {
        if (cnts.size() == 1) {
          cnts.back().first = c;
        } else {
          const auto cnt = cnts.back().second;
          cnts.pop_back();
          cnts.back().second += cnt;
        }
      }
      ++cnts.back().second;
    } else {
      if (cnts.empty() || cnts.back().first != c) {
        cnts.push_back(make_pair(c, 1));
      } else {
        ++cnts.back().second;
      }
    }
  }
  s64 ans{0};
  for (auto [c, cnt] : cnts) {
    if (c == 0) ans += cnt;
  }
  cout << ans << endl;
}