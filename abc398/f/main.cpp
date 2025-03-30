#include "util/common.h"
#include "util/palindrome.h"

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