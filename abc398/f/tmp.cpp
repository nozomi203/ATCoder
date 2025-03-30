#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 4 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\palindrome.h"

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
#line 3 "main.cpp"

int main() {
  string s;
  cin >> s;

  size_t len_max{0};
  auto ls = util::palindrome_lengths(s);
  for (s64 i{s.size() - 1}; i >= 0; --i) {
    auto l = ls[i];
    if (i + (l.first - 1) / 2 == s.size() - 1) len_max = max(len_max, l.first);
    if (i + l.second / 2 == s.size() - 1) len_max = max(len_max, l.second);
  }

  cout << s;
  for (s64 i{s.size() - 1 - len_max}; i >= 0; --i) cout << s[i];
  cout << endl;
}
