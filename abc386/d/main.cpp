#include "util/common.h"
#include "util/segment_tree.h"

int main() {
  s64 N, M;
  cin >> N >> M;

  using S = s64;
  constexpr S maximum = numeric_limits<S>::max();
  constexpr auto get_min = [](S l, S r) -> S { return min(l, r); };

  util::segment_tree<S, maximum, get_min> wxmin(N), wymin(N);
  vector<pair<s64, s64>> bpos;
  for (s64 i = 0; i < M; ++i) {
    s64 X, Y;
    char C;
    cin >> X >> Y >> C;
    --X;
    --Y;
    if (C == 'B') {
      bpos.emplace_back(make_pair(X, Y));
    } else {
      wxmin.apply(Y, X);
      wymin.apply(X, Y);
    }
  }

  const auto check = [&]() -> bool {
    for (auto [bx, by] : bpos) {
      if (wxmin.query(0, by + 1) <= bx) return false;
      if (wymin.query(0, bx + 1) <= by) return false;
    }
    return true;
  };

  cout << (check() ? "Yes" : "No") << endl;
}