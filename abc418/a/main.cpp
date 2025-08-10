#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  string s;
  cin >> s;

  const auto check = [&]() -> bool {
    if (s.size() < 3) return false;

    return s.substr(s.size() - 3, 3) == "tea";
  };

  cout << (check() ? "Yes" : "No") << endl;
}