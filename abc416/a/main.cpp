#include "util/common.h"

int main() {
  s64 n, l, r;
  cin >> n >> l >> r;
  string s;
  cin >> s;
  cout << (all_of(s.begin() + l - 1, s.begin() + r,
                  [](char c) { return c == 'o'; })
               ? "Yes"
               : "No")
       << endl;
}