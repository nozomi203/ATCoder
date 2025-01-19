#include "util/binary_search.h"
#include "util/common.h"

int main() {
  s64 N, M;
  cin >> N >> M;
  vector<s64> P(N);
  for (s64 i = 0; i < N; ++i) cin >> P[i];

  const auto get_num = [&](s64 value) -> s64 {
    s64 num{0};
    for (s64 i = 0; i < N; ++i) {
      num += (value + P[i]) / (2LL * P[i]);
    }
    return num;
  };
  const auto get_sum = [&](s64 value) -> s64 {
    s64 sum{0};
    for (s64 i = 0; i < N; ++i) {
      s64 num = (value + P[i]) / (2LL * P[i]);
      sum += P[i] * num * num;
    }
    return sum;
  };

  auto [ok, ng] = util::binary_search<s64>(
      0, M + 1, [&](auto value) -> bool { return get_sum(value) <= M; });

  s64 ans = get_num(ok);
  s64 sum = get_sum(ok);
  for (s64 i = 0; i < N; ++i) {
    if (sum + ok + 1 > M) break;
    if ((ok + 1 + P[i]) % (2 * P[i]) == 0) {
      sum += P[i] * (ok + 1);
      ++ans;
    }
  }
  cout << ans << endl;
}