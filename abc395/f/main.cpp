#include "util/binary_search.h"
#include "util/common.h"

int main() {
  s64 N, X;
  cin >> N >> X;
  vector<pair<s64, s64>> teeth(N);
  s64 num_teeth{0};
  s64 h_max{numeric_limits<s64>::max()};
  for (s64 i{0}; i < N; ++i) {
    cin >> teeth[i].first >> teeth[i].second;
    h_max = min(h_max, teeth[i].first + teeth[i].second);
    num_teeth += teeth[i].first;
    num_teeth += teeth[i].second;
  }
  const auto [h_ok, h_ng] =
      util::binary_search<s64>(0, h_max + 1, [&](s64 h) -> bool {
        s64 u_min{0}, u_max{h};
        for (const auto [u, d] : teeth) {
          u_min = max<s64>({u_min - X, h - d, 0});
          u_max = min<s64>({u_max + X, u});
          if (u_min > u_max) return false;
        }
        return true;
      });

  s64 num_drill = num_teeth - h_ok * N;
  cout << num_drill << endl;
}