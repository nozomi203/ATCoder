#include "util/common.h"
#include "util/sparse_table.h"

/*
スライム1を飼うためには(1)直接捕まえる(2)魔法をk回唱える　のどちらかが必要
スライドを最大k回行う場合のことを考える(0<=k<n)
スライドにかかるコストは固定でk*x
あとは各スライムに何回スライドを適用したときに時間が最小になるか考える
→スライムiに対して[i-k,i]の範囲の最小値がわかればいい
*/

int main() {
  size_t n, x;
  cin >> n >> x;
  vector<size_t> as(n);
  for (size_t i{0}; i < n; ++i) cin >> as[i];
  util::sparse_table<size_t, [](size_t l, size_t r) { return min(l, r); }> st(
      as);

  size_t ans{numeric_limits<size_t>::max()};
  for (size_t i{0}; i < n; ++i) {
    size_t cost{i * x};
    for (size_t j{0}; j < n; ++j) {
      size_t add{0};
      if (j < i) {
        add += min(st.query(0, j), st.query(n - (i - j), n - 1));
      } else {
        add += st.query(j - i, j);
      }
      cost += add;
    }
    ans = min(ans, cost);
  }
  cout << ans << endl;
}