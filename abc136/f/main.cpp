#include <atcoder/fenwicktree>
#include <atcoder/math>
#include <atcoder/modint>

#include "util/common.h"

using mint = atcoder::modint998244353;

int main() {
  size_t n;
  cin >> n;
  vector<pair<int64_t, int64_t>> xys(n);
  for (size_t i{0}; i < n; ++i) cin_pair(xys[i]);
  // 座標圧縮
  {
    map<int64_t, int64_t> xs, ys;
    for (auto [x, y] : xys) {
      xs.emplace(x, 0);
      ys.emplace(y, 0);
    }
    int64_t idx_x{0}, idx_y{0};
    for (auto& [k, v] : xs) v = idx_x++;
    for (auto& [k, v] : ys) v = idx_y++;

    for (auto& [x, y] : xys) {
      x = xs[x];
      y = ys[y];
    }
    // xで昇順ソート
    sort(xys.begin(), xys.end());
  }
  // f(T)の総和を求める
  // 点Pが長方形内に含まれるような部分集合Tの集合Uを考える。|U| = g(P)とする
  // 部分集合TがUに含まれるにはPよりも[x座標 | y座標]の[小さい |
  // 大きい]点がそれぞれ最低1つ以上存在する必要がある
  // もしくは、余事象を考えるか。Uに含まれない集合部分集合Tの集合V
  // V = {xがすべてP.xより大きい点} + {xがすべてP.xより小さい点} +
  // {yがすべてP.yより大きい点} + {yがすべてP.yより小さい点} -
  // {x>P.x&&y>P.y} - {x>P.x&&y<P.y} - {x<P.x&&y>P.y} - {x<P.x&&y<P.y}
  mint ans = 0;

  atcoder::fenwick_tree<int64_t> ftl(n), ftr(n);
  for (auto [x, y] : xys) ftr.add(y, 1);
  for (size_t i{0}; i < n; ++i) {
    const auto [x, y] = xys[i];
    ftr.add(y, -1);
    ftl.add(y, 1);

    mint cmp = 0;
    const size_t yld{y ? ftl.sum(0, y) : 0};
    const size_t yrd{y ? ftr.sum(0, y) : 0};
    const size_t ylu{y < n - 1 ? ftl.sum(y + 1, n) : 0};
    const size_t yru{y < n - 1 ? ftr.sum(y + 1, n) : 0};

    cmp += atcoder::pow_mod(2, i, mint::mod()) - 1;
    cmp += atcoder::pow_mod(2, n - i - 1, mint::mod()) - 1;
    cmp += atcoder::pow_mod(2, yld + yrd, mint::mod()) - 1;
    cmp += atcoder::pow_mod(2, ylu + yru, mint::mod()) - 1;

    cmp -= atcoder::pow_mod(2, yld, mint::mod()) - 1;
    cmp -= atcoder::pow_mod(2, yrd, mint::mod()) - 1;
    cmp -= atcoder::pow_mod(2, ylu, mint::mod()) - 1;
    cmp -= atcoder::pow_mod(2, yru, mint::mod()) - 1;

    ans += (atcoder::pow_mod(2, n, mint::mod()) - 1) - cmp;
  }

  cout << ans.val() << endl;
}

/*

*/