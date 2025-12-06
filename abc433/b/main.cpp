#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> as(n);
  util::cin(as);
  for (s64 i = 0; i < n; ++i) {
    bool found = false;
    for (s64 j = i - 1; j >= 0; --j) {
      if (as[i] < as[j]) {
        cout << j + 1 << endl;
        found = true;
        break;
      }
    }
    if (!found) {
      cout << -1 << endl;
    }
  }
}