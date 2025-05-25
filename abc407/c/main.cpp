#include "util/common.h"

u64 ctoi(char c) {
  assert(c >= '0');
  return c - '0';
}

int main() {
  string s;
  cin >> s;
  size_t ans{0};
  for (size_t i{0}; i < s.size() - 1; ++i) {
    ans += (1 + (ctoi(s[i]) + 10 - ctoi(s[i + 1])) % 10);
  }
  ans += (1 + ctoi(s[s.size() - 1]));

  cout << ans << endl;
}