#include <atcoder/segtree>

#include "util/common.h"

/*
3行固定なことから、最短距離が存在するとき列jから列j-1に移動することはない。
*/
constexpr s64 inf = numeric_limits<s64>::max();
int main() {
  s64 n;
  cin >> n;
  vector<string> ss(3);
  util::cin(ss);
  s64 q;
  cin >> q;
  vector<pair<s64, s64>> queries(q);
  util::cin(queries);

  // elem_t[i][j]=区間[l,r)に対し、ss[i][l]からss[j][r-1]に至る最短距離
  using elem_t = array<array<s64, 3>, 3>;
  using optelem_t = optional<elem_t>;
  atcoder::segtree<optelem_t,
                   [](optelem_t s0, optelem_t s1) -> optelem_t {
                     if (s0 == nullopt) return s1;
                     if (s1 == nullopt) return s0;
                     elem_t ret{};
                     ret[0].fill(inf);
                     ret[1].fill(inf);
                     ret[2].fill(inf);
                     for (s64 i = 0; i < 3; ++i) {
                       for (s64 j = 0; j < 3; ++j) {
                         for (s64 k = 0; k < 3; ++k) {
                           if ((*s0)[i][k] == inf || (*s1)[k][j] == inf)
                             continue;
                           ret[i][j] =
                               min(ret[i][j], (*s0)[i][k] + (*s1)[k][j]);
                         }
                       }
                     }
                     return ret;
                   },
                   []() -> optelem_t { return nullopt; }>
      st(n);

  const auto update = [&](s64 k) {
    elem_t e{};
    e[0].fill(inf);
    e[1].fill(inf);
    e[2].fill(inf);
    if (ss[0][k] == '.') e[0][0] = 1;
    if (ss[0][k] == '.' && ss[1][k] == '.') e[0][1] = e[1][0] = 2;
    if (ss[0][k] == '.' && ss[1][k] == '.' && ss[2][k] == '.')
      e[0][2] = e[2][0] = 3;
    if (ss[1][k] == '.') e[1][1] = 1;
    if (ss[1][k] == '.' && ss[2][k] == '.') e[1][2] = e[2][1] = 2;
    if (ss[2][k] == '.') e[2][2] = 1;
    st.set(k, e);
  };

  for (s64 k = 0; k < n; ++k) update(k);

  for (auto [r, c] : queries) {
    ss[r - 1][c - 1] = ss[r - 1][c - 1] == '.' ? '#' : '.';
    update(c - 1);
    optelem_t e = st.prod(0, n);
    cout << ((*e)[0][2] == inf ? -1 : (*e)[0][2] - 1) << endl;
  }
}