#include "util/common.h"
#include "util/string_distance.h"

int main() {
  s64 N, M;
  cin >> N >> M;
  constexpr auto inf = numeric_limits<u64>::max();
  vector<vector<u64>> dists(N + 1, vector<u64>(N + 1, inf));
  for (s64 i = 0; i < M; ++i) {
    s64 A, B, C;
    cin >> A >> B >> C;
    dists[A][B] = C;
  }
  for (s64 i = 1; i <= N; ++i) dists[i][i] = 0;

  u64 ans{0};
  for (u64 k = 1; k <= N; ++k) {
    for (u64 i = 1; i <= N; ++i) {
      for (u64 j = 1; j <= N; ++j) {
        if (dists[i][k] < inf && dists[k][j] < inf)
          dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
        if (dists[i][j] < inf) ans += dists[i][j];
      }
    }
  }

  cout << ans << endl;
}