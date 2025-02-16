#include "util/common.h"

int main() {
  s64 N, M;
  cin >> N >> M;
  size_t ans{0};
  set<pair<s64, s64>> e;
  for (s64 i = 0; i < M; ++i) {
    s64 v1, v2;
    cin >> v1 >> v2;
    if (v1 > v2) swap(v1, v2);
    if (v1 == v2 || e.contains(make_pair(v1, v2))) {
      ++ans;
    } else {
      e.emplace(make_pair(v1, v2));
    }
  }

  cout << ans << endl;
}