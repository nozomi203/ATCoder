#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace util {

/// @brief get the palindrome length of <s> with manachar's
/// method[https://snuke.hatenablog.com/entry/2014/12/02/235837]
/// @param s
/// @param filler
/// @return
inline std::vector<std::pair<size_t, size_t>> palindrome_lengths(
    const std::string& s, char filler = '#') {
  std::string s2(s.size() * 2 + 1, filler);
  for (size_t i{0}; i < s.size(); ++i) s2[2 * i + 1] = s[i];
  std::vector<size_t> rs(s2.size());
  size_t c{0}, r{0};
  while (c < s2.size()) {
    while (c >= r && c + r < s2.size() && s2[c - r] == s2[c + r]) ++r;
    rs[c] = r;

    size_t k{1};
    while (k <= c && k + rs[c - k] < r) {
      rs[c + k] = rs[c - k];
      ++k;
    }
    c += k;
    r -= k;
  }

  std::vector<std::pair<size_t, size_t>> ret(s.size());
  for (size_t i{0}; i < s.size(); ++i) {
    ret[i].first = (rs[2 * i + 1] / 2) * 2 - 1;
    ret[i].second = ((rs[2 * i + 2] - 1) / 2) * 2;
  }
  return ret;
}
}  // namespace util