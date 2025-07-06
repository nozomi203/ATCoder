#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> as(n);
  util::cin(as);
  vector<pair<s64, s64>> uvs(m);
  util::cin(uvs);
}