#include "util/common.h"

int main() {
  s64 a, b, c;
  cin >> a >> b >> c;
  const auto check = [&]() -> bool { return (a == b) || (b == c) || (c == a); };
  cout << (check() ? "Yes" : "No") << endl;
}