#include "util/common.h"

int main() {
  s64 ans{0};
  for (s64 i{1}; i <= 12; ++i) {
    string s;
    cin >> s;
    if (s.size() == i) ++ans;
  }
  cout << ans << endl;
}