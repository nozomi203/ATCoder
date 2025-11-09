#include "util/common.h"

int main() {
  s64 h, b;
  cin >> h >> b;

  cout << max<s64>(0, h - b) << endl;
}