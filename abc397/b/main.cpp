#include "util/common.h"

int main() {
  string s;
  cin >> s;
  s64 ans{0};
  bool i{true};
  for (char c : s) {
    if (i) {
      if (c != 'i') {
        ++ans;
      } else {
        i = !i;
      }
    } else {
      if (c != 'o') {
        ++ans;
      } else {
        i = !i;
      }
    }
  }
  if ((ans + s.size()) % 2) ++ans;
  cout << ans << endl;
}