#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> as(n);
  util::cin(as);

  s64 ans = 0;
  for (s64 i = 0; i < n; ++i) {
    for (s64 j = i; j < n; ++j) {
      s64 suma = 0;
      for (s64 k = i; k <= j; ++k) {
        suma += as[k];
      }
      const auto check = [&]() -> bool {
        for (s64 k = i; k <= j; ++k) {
          if (suma % as[k] == 0) return false;
        }
        return true;
      };

      if (check()) ++ans;
    }
  }
  cout << ans << endl;
}