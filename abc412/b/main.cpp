#include "util/common.h"

int main() {
  string s, t;
  cin >> s >> t;
  set<char> ms, mt;
  for (char c : s) ms.emplace(c);
  for (char c : t) mt.emplace(c);

  const auto check = [&]() -> bool {
    for (s64 i = 1; i < s.size(); ++i) {
      if (s[i] >= 'A' && s[i] <= 'Z') {
        if (!mt.contains(s[i - 1])) return false;
      }
    }
    return true;
  };
  cout << (check() ? "Yes" : "No") << endl;
}