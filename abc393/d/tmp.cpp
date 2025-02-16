#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 N;
  cin >> N;
  string S;
  cin >> S;

  s64 one_cnt{0};
  vector<s64> one_indices;
  for (s64 i = 0; i < N; ++i) {
    if (S[i] == '1') {
      one_indices.push_back(i);
      ++one_cnt;
    }
  }
  s64 ans{0};
  const s64 center_idx{one_indices[one_cnt / 2]};
  for (s64 i = 0; i < one_cnt; ++i) {
    ans += abs(center_idx - one_indices[i]) - abs(one_cnt / 2 - i);
  }
  cout << ans << endl;
}
