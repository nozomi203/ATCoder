#line 1 "main.cpp"
#include <atcoder/all>

#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 4 "main.cpp"

int main() {
  size_t N;
  cin >> N;
  vector<size_t> a(1000001, 0);
  for (size_t i = 0; i < N; ++i) {
    size_t S;
    cin >> S;
    a[S] = 1;
  }
  const auto c = atcoder::convolution(a, a);

  size_t ans{0};
  for (size_t i = 1; i < 1000001; ++i) {
    if (a[i]) {
      ans += (c[2 * i] - 1) / 2;
    }
  }
  cout << ans << endl;
}
