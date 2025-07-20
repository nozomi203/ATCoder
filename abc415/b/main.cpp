#include "util/common.h"

int main() {
  string s;
  cin >> s;
  s64 i = 0;
  s64 cnt = 0;
  array<s64, 2> idxs;
  while (i < s.size()) {
    if (s[i] == '#') {
      idxs[cnt++] = i;
    }
    if (cnt == 2) {
      cout << idxs[0] + 1 << "," << idxs[1] + 1 << endl;
      cnt = 0;
    }
    ++i;
  }
}