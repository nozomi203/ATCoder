#include <atcoder/math>

#include "util/common.h"
int main() {
  s64 x, y;
  cin >> x >> y;
  cout << x * atcoder::pow_mod(2, y, 1000) << endl;
}