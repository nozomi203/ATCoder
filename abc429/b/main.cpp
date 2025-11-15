#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> as(n);
  util::cin(as);

  const auto check = [&]() -> bool {
    const s64 suma = accumulate(as.begin(), as.end(), 0ULL);
    for (auto a : as) {
      if (suma == m + a) return true;
    }
    return false;
  };

  cout << (check() ? "Yes" : "No") << endl;
}