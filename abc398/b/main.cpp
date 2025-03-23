#include "util/common.h"

int main() {
  map<s64, s64> cnts;
  for (s64 i{0}; i < 7; ++i) {
    s64 a;
    cin >> a;
    ++cnts[a];
  }

  s64 num3{0}, num2{0};
  for (auto& [val, cnt] : cnts) {
    if (cnt >= 3) ++num3;
    if (cnt >= 2) ++num2;
  }

  cout << (num3 >= 1 && num2 >= 2 ? "Yes" : "No") << endl;
}