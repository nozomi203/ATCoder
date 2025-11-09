#include "util/common.h"

int main() {
  string s;
  cin >> s;
  s64 a = s[0] - '0';
  s64 b = s[2] - '0';

  if (b == 8) {
    ++a;
    b = 1;
  } else {
    ++b;
  }

  cout << a << '-' << b << endl;
}