#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\math.h"
#include <concepts>
#line 4 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\math.h"

namespace util {
template <std::integral Int>
Int powi(Int value, uint64_t pow) {
  if (pow == 0) return 1;
  return value * powi(value, pow - 1);
}

uint64_t fact(uint64_t val) {
  if (val == 0) return 1;
  return val * fact(val - 1);
}
}  // namespace util
#line 3 "main.cpp"

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> xys(n);
  for (s64 i{0}; i < n; ++i) cin >> xys[i].first >> xys[i].second;

  vector<s64> idxs(n);
  iota(idxs.begin(), idxs.end(), 0);

  const auto count = util::fact(n);
  double sum{0.0};
  do {
    for (size_t i{0}; i < n - 1; ++i) {
      auto to = idxs[i + 1];
      auto from = idxs[i];
      auto dx = xys[to].first - xys[from].first;
      auto dy = xys[to].second - xys[from].second;
      sum += sqrt(dx * dx + dy * dy);
    }
  } while (next_permutation(idxs.begin(), idxs.end()));

  cout << fixed << setprecision(15) << sum / count << endl;
}
