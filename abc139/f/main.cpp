#include "util/common.h"

using vec2 = pair<int64_t, int64_t>;
int main() {
  size_t n;
  cin >> n;
  vector<vec2> xys(n);
  for (size_t i{0}; i < n; ++i) cin_pair(xys[i]);
}