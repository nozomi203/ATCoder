#include "util/common.h"
#include "util/sparse_table.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> as(n), bs(n), cs(n);
  util::cin(as);
  util::cin(bs);
  util::cin(cs);

  vector<s64> sumas(n), sumbs(n), sumcs(n), sumds(n);
  sumas[0] = as[0];
  sumbs[0] = bs[0];
  sumcs[0] = cs[0];
  sumds[0] = sumbs[0] - sumcs[0];
  for (s64 i = 1; i < n; ++i) {
    sumas[i] = sumas[i - 1] + as[i];
    sumbs[i] = sumbs[i - 1] + bs[i];
    sumcs[i] = sumcs[i - 1] + cs[i];
    sumds[i] = sumbs[i] - sumcs[i];
  }

  util::sparse_table<s64, [](s64 s0, s64 s1) -> s64 { return max(s0, s1); }> st(
      sumds);

  s64 ans = 0;
  for (s64 i = 0; i < n - 2; ++i) {
    s64 val = 0;
    val += sumas[i];
    val += sumcs.back() - sumcs[i];
    val += st.query(i + 1, n - 2) - sumds[i];
    ans = max(ans, val);
  }
  cout << ans << endl;
}