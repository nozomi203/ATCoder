#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  s64 x{0};
  s64 mul{1};
  for (s64 i{0}; i <= m; ++i) {
    x += mul;
    mul *= n;
    if (x > 1000000000) {
      cout << "inf" << endl;
      return 0;
    }
  }
  cout << x << endl;
}