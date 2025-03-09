#include "util/common.h"

int main() {
  s64 N, Q;
  cin >> N >> Q;

  s64 ans{0};
  s64 pl{1}, pr{2};
  for (s64 i{0}; i < Q; ++i) {
    char H;
    s64 T;
    cin >> H >> T;
    auto& ps = H == 'L' ? pl : pr;
    auto& po = H == 'L' ? pr : pl;
    if (ps < T) {
      ans += (ps < po && po < T) ? N - (T - ps) : T - ps;
    } else if (ps > T) {
      ans += (T < po && po < ps) ? N - (ps - T) : ps - T;
    }
    ps = T;
  }
  cout << ans << endl;
}