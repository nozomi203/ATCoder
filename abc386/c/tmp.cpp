#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 6 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\string_distance.h"

namespace util {
uint64_t string_distance(const std::string& l, const std::string& r) {
  // dp[i][j] = lのi文字目までとrのj文字目までの編集距離
  // std::vector<std::vector<uint64_t>> dp(
  //     l.size() + 1, std::vector<uint64_t>(
  //                       r.size() + 1, std::numeric_limits<uint64_t>::max()));

  // for (uint64_t i = 0; i <= l.size(); ++i) dp[i][0] = i;
  // for (uint64_t i = 0; i <= r.size(); ++i) dp[0][i] = i;

  std::vector<uint64_t> curr(r.size() + 1),
      prev(r.size() + 1, std::numeric_limits<uint64_t>::max());
  for (uint64_t i = 0; i < r.size(); ++i) curr[i] = i;

  for (uint64_t i = 1; i <= l.size(); ++i) {
    prev.swap(curr);
    curr[0] = i;
    for (uint64_t j = 1; j <= r.size(); ++j) {
      if (l[i - 1] == r[j - 1]) {
        curr[j] = std::min(prev[j - 1], std::min(prev[j] + 1, curr[j - 1] + 1));
      } else {
        curr[j] =
            std::min(prev[j] + 1, std::min(curr[j - 1] + 1, prev[j - 1] + 1));
      }
    }
  }
  return curr[r.size()];
}
}  // namespace util
#line 3 "main.cpp"

int main() {
  s64 K;
  cin >> K;
  string S, T;
  cin >> S >> T;
  cout << (util::string_distance(S, T) <= K ? "Yes" : "No") << endl;
}
