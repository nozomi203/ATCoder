#include "util/common.h"

int main() {
  size_t n;
  util::cin(n);
  vector<s64> as(n);
  util::cin(as);
  for (size_t i{0}; i < n - 1; ++i) as[i + 1] += as[i];
  map<s64, size_t> m;
  m[0] = 1;
  size_t ans{0};
  for (size_t i{0}; i < n; ++i) {
    ans += m[as[i]];
    ++m[as[i]];
  }
  cout << ans << endl;
}