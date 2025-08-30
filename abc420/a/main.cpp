#include "util/common.h"

int main() {
  s64 x, y;
  cin >> x >> y;
  cout << (x - 1 + y) % 12 + 1 << endl;
}