#include "util/common.h"

int main() {
  string s;
  cin >> s;
  size_t ans{0};
  size_t r{0};
  for (size_t l{0}; l < s.size(); ++l) {
    r = max(r, l);
    while (r < s.size() &&
           (s[r] == 'A' || s[r] == 'C' || s[r] == 'G' || s[r] == 'T'))
      ++r;
    ans = max(ans, r - l);
  }

  cout << ans << endl;
}