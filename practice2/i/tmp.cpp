#line 1 "main.cpp"
#include <atcoder/all>

#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 4 "main.cpp"

int main() {
  string S;
  cin >> S;
  const auto sa = atcoder::suffix_array(S);
  const auto lcp = atcoder::lcp_array(S, sa);

  s64 ans{S.size() * (S.size() + 1) / 2};
  for (auto v : lcp) {
    ans -= v;
  }

  cout << ans << endl;
}
