#include "util/binary_search.h"
#include "util/common.h"
int main() {
  s64 n;
  cin >> n;
  s64 ans{0};
  for (s64 a{2}; a <= n; a *= 2) {
    auto [ok, ng] =
        util::binary_search<s64>(0, (s64)sqrt(n) + 1, [&](s64 val) -> bool {
          return (val * 2 + 1) * (val * 2 + 1) <= n / a;
        });
    ans += ok + 1;
  }

  cout << ans << endl;
}