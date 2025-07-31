#include "util/common.h"

int main() {
  size_t n;
  cin >> n;
  vector<s64> as(n), bs(n);
  util::cin(as);
  util::cin(bs);
  as.resize(n * 2);
  bs.resize(n * 2);
  copy(as.begin(), as.begin() + n, as.begin() + n);
  copy(bs.begin(), bs.begin() + n, bs.begin() + n);
  for (size_t i = 1; i < n * 2; ++i) bs[i] += bs[i - 1];

  const auto bfn = std::bit_floor(n);
  const auto pown = std::countr_zero(bfn);

  /*dp[i] = i以降のモンスターを2^j体倒すのに必要な強さの最小値*/
  vector<vector<s64>> dp(n * 2, vector<s64>(pown + 1));

  for (s64 i = n * 2 - 1; i >= 0; --i) {
    dp[i][0] = as[i];
    for (size_t j = 1; j <= pown; ++j) {
      const size_t ioffst = (1 << (j - 1));
      if (i + ioffst >= n * 2) break;
      const s64 boffst = bs[i + ioffst - 1] - (i ? bs[i - 1] : 0);
      dp[i][j] = max(dp[i][j - 1], dp[i + ioffst][j - 1] - boffst);
    }
  }

  s64 ans = numeric_limits<s64>::max();
  for (size_t i = 0; i < n; ++i) {
    s64 val = 0;
    size_t curi = i;
    for (size_t j = 0; j <= pown; ++j) {
      if (!(n & (1 << j))) continue;
      const s64 boffst = (curi ? bs[curi - 1] : 0) - (i ? bs[i - 1] : 0);
      val = max(val, dp[curi][j] - boffst);
      curi += (1 << j);
    }
    ans = min(ans, val);
  }
  cout << ans << endl;
}