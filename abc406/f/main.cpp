#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> uvs(n);
  for (s64 i{0}; i < n; ++i) cin_pair(uvs[i]);
}