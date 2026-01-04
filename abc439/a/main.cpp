#include <atcoder/math>

#include "util/common.h"
int main() {
  s64 n;
  cin >> n;
  cout << atcoder::pow_mod(2, n, 10000001) - 2 * n << endl;
}