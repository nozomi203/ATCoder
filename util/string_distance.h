#pragma once
#include <cstdint>
#include <limits>
#include <string>
#include <vector>

namespace util {
uint64_t string_distance(
    const std::string& l, const std::string& r,
    uint64_t dist_max = std::numeric_limits<uint64_t>::max()) {
  std::vector<uint64_t> curr(r.size() + 1),
      prev(r.size() + 1, std::numeric_limits<uint64_t>::max());
  for (uint64_t i = 0; i < r.size(); ++i) curr[i] = i;

  for (uint64_t i = 1; i <= l.size(); ++i) {
    prev.swap(curr);
    curr[0] = i;

    const uint64_t j_b = i - 1 < dist_max ? 1 : i - dist_max;

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