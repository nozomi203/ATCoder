#include "util/common.h"

int main() {
  size_t t;
  cin >> t;
  vector<string> cases(t);
  for (size_t i{0}; i < t; ++i) {
    size_t n;
    cin >> n;
    cin >> cases[i];
  }

  for (const auto& s : cases) {
    bool found{false};
    for (size_t l{0}; l < s.size() - 1; ++l) {
      if (s[l] > s[l + 1]) {
        size_t r{l};
        while (r + 1 < s.size() && s[l] >= s[r + 1]) ++r;
        for (size_t i{0}; i < l; ++i) cout << s[i];
        for (size_t i{l + 1}; i <= r; ++i) cout << s[i];
        cout << s[l];
        for (size_t i{r + 1}; i < s.size(); ++i) cout << s[i];
        cout << endl;
        found = true;
        break;
      }
    }
    if (!found) cout << s << endl;
  }
}