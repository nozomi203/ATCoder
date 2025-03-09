#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  string s;
  cin >> s;
  // alp_cnt[i][j] = count of alphabet <j>(regard 'A' as 0) which exists
  // leftward of <i>th element of s(includes <i>th element itself)
  vector<vector<s64>> alp_cnt(s.size(), vector<s64>(26));
  ++alp_cnt[0][s[0] - 'A'];
  for (s64 i{1}; i < s.size(); ++i) {
    for (s64 j{0}; j < 26; ++j) {
      alp_cnt[i][j] = alp_cnt[i - 1][j];
    }
    ++alp_cnt[i][s[i] - 'A'];
  }

  s64 ans{0};
  {
    for (s64 i{1}; i < s.size() - 1; ++i) {
      for (s64 j{0}; j < 26; ++j) {
        ans += alp_cnt[i - 1][j] * (alp_cnt[s.size() - 1][j] - alp_cnt[i][j]);
      }
    }
  }
  cout << ans << endl;
}
