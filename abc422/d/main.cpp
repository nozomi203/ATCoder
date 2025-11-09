#include <atcoder/math>

#include "util/common.h"

int main() {
  s64 n, k;
  cin >> n >> k;

  const s64 len = atcoder::pow_mod(2, n, 1000000000);
  const s64 quot = k / len;
  const s64 rem = k % len;
}