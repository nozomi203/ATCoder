#pragma once

#include <string>
#include <vector>

/*

ababc
pmt[0]=-1
pmt[1]=0
pmt[2]=0
pmt[3]=1

*/
namespace util {
inline std::vector<size_t> kmp(const std::string& s, const std::string& t) {
  if (s.size() < t.size()) return {};
  std::vector<size_t> pmt(t.size());
  pmt[0] = -1;
  for (size_t i{1}; i < t.size(); ++i) {
  }

  std::vector<size_t> ret;
  size_t j_offset{0};
  for (size_t i{0}; i < s.size() - t.size() + 1; ++i) {
    for (size_t j{j_offset}; j < t.size(); ++j) {
      if (s[i + j] != t[j]) {
        j_offset = pmt[j - 1];
        i += j - pmt[j - 1];
        break;
      }
    }
    ret.push_back(i);
  }

  return ret;
}
}  // namespace util