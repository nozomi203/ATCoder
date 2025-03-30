#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 n;
  cin >> n;
  vector<s64> primes;
  vector<bool> isp(n + 1, true);
  for (s64 i{2}; i <= n; ++i) {
    if (isp[i]) primes.push_back(i);
    s64 v{i * 2};
    while (v <= n) {
      isp[v] = false;
      v += i;
    }
  }

  s64 ans{0};
  for (s64 i{1}; i <= n; ++i) {
    if (i % 2 == 0) continue;
    s64 val{i};
    s64 num_div{1};
    for (auto p : primes) {
      s64 cnt{0};
      while (val % p == 0) {
        val /= p;
        ++cnt;
      }
      num_div *= (cnt + 1);
    }

    if (num_div == 8) ++ans;
  }
  cout << ans << endl;
}
