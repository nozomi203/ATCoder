#include "util/common.h"

int main() {
  size_t n;
  cin >> n;
  string t, a;
  cin >> t >> a;
  const auto check = [&]() -> bool {
    for (size_t i{0}; i < n; ++i)
      if (t[i] == 'o' && a[i] == 'o') return true;
    return false;
  };
  cout << (check() ? "Yes" : "No") << endl;
}