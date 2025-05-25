#include "util/common.h"

int main() {
  s64 a, b;
  cin >> a >> b;
  s64 c = a % b;
  cout << (c * 2 < b ? a / b : a / b + 1) << endl;
}