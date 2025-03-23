#include <cstdint>
#include <string>
#include <vector>

namespace util {

/// @brief get the palindrome radius of <s> with manachar's
/// method[https://snuke.hatenablog.com/entry/2014/12/02/235837]
/// @param s
/// @param filler
/// @return
inline std::vector<std::pair<size_t, size_t>> palindrome_radius(
    const std::string& s, char filler = '#') {
  std::string s2(s.size() * 2, filler);  // augmented to even length
  for (size_t i{0}; i < s.size(); ++i) s2[2 * i] = s[i];
  std::vector<size_t> rs(s2.size());
  size_t c{0}, r{0};
  while (c < s2.size()) {
    while (c >= r && c + r < s2.size() && s[c - r] == s[c + r]) ++r;
    rs[c] = r;

    size_t k{1};
    while (k <= c && k + rs[c - k] < r) {
      rs[c + k] = rs[c - k];
      ++k;
    }
    c += k;
    r -= k;
  }

  for (size_t i{0}; i < s2.size(); ++i) {
    if (i) }

  std::vector<std::pair<size_t, size_t>> ret(s.size());
  for (size_t i{0}; i < s.size(); ++i) {
    ret[i].first = rs[2 * i];
    ret[i].second = rs[2 * i + 1];
  }
  return ret;
}
}  // namespace util