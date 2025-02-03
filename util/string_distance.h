#pragma once
#include <cstdint>
#include <limits>
#include <string>
#include <vector>

namespace util {
uint64_t string_distance(
    const std::string& l, const std::string& r,
    uint64_t dist_max = std::numeric_limits<uint64_t>::max() - 1) {
  if (l.size() > r.size()) return string_distance(r, l, dist_max);
  dist_max = min(dist_max, r.size());
  std::vector<std::vector<uint64_t>> dp(
      l.size() + 1, std::vector<uint64_t>(dist_max * 2 + 3,
                                          numeric_limits<uint64_t>::max() - 1));
  for (uint64_t i = 0; i <= min(dist_max, r.size()); ++i) {
    dp[0][dist_max + 1 + i] = i;
  }
  for (uint64_t i = 1; i <= min(dist_max, l.size()); ++i) {
    dp[i][dist_max + 1 - i] = i;
  }

  for (int64_t i = 1; i <= l.size(); ++i) {
    const auto j_b = i - 1 > dist_max ? i - dist_max : 1;
    const auto j_e = r.size() - i > dist_max ? i + dist_max : r.size();
    for (uint64_t j = j_b; j <= j_e; ++j) {
      const int64_t curr_offset = dist_max + 1 - i;
      const int64_t prev_offset = dist_max + 1 - i + 1;
      if (l[i - 1] == r[j - 1]) {
        dp[i][j + curr_offset] =
            std::min(dp[i - 1][j - 1 + prev_offset],
                     std::min(dp[i - 1][j + prev_offset] + 1,
                              dp[i][j - 1 + curr_offset] + 1));
      } else {
        dp[i][j + curr_offset] =
            std::min(dp[i - 1][j - 1 + prev_offset] + 1,
                     std::min(dp[i - 1][j + prev_offset] + 1,
                              dp[i][j - 1 + curr_offset] + 1));
      }
    }
  }
  return dp[l.size()][r.size() + dist_max + 1 - l.size()];
}
}  // namespace util