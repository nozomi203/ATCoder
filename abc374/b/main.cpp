#include "util/common.h"

int main() {
  string s, t;
  cin >> s >> t;
  const auto get = [&]() -> size_t {
    for (size_t i{0}; i < max(s.size(), t.size()); ++i) {
      if (i >= s.size() || i >= t.size()) return i + 1;
      if (s[i] != t[i]) return i + 1;
    }
    return 0;
  };

  cout << get() << endl;
}