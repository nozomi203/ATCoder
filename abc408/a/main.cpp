#include "util/common.h"

int main() {
  size_t n, s;
  cin >> n >> s;
  vector<size_t> ts(n + 1);
  for (size_t i{1}; i <= n; ++i) cin >> ts[i];

  const auto check = [&]() -> bool {
    for (size_t i{1}; i <= n; ++i) {
      if (ts[i] - ts[i - 1] > s) return false;
    }
    return true;
  };
  cout << (check() ? "Yes" : "No") << endl;
}