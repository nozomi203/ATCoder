#include <atcoder/math>

#include "util/common.h"
int main() {
  u64 p;
  cin >> p;
  u64 n;
  cin >> n;

  vector<u64> vs(p);
  for (u64 i = 0; i < p; ++i) vs[i] = atcoder::pow_mod(i, n, p);
  util::sort(vs);
}