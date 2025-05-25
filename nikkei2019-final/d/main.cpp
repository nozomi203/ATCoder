#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  const s64 sqrtn{(s64)ceil(sqrt(n))};
  n = sqrtn * sqrtn;
  vector<s64> t(m), l(m), r(m);
  for (s64 i{0}; i < m; i++) {
    cin >> t[i] >> l[i] >> r[i];
    --l[i];
    --r[i];
  }

  s64 sum{0};
  vector<s64> last_b(sqrtn);
  vector<s64> last_i(n);
  vector<s64> sub_b(sqrtn);
  for (s64 i{0}; i < m; ++i) {
    s64 j{l[i]};
    for (; j % sqrtn && j <= r[i]; ++j) {
      s64 last = max(last_i[j], last_b[j / sqrtn]);
      s64 add = t[i] - last;
      sum += add;
      sub_b[j / sqrtn] += add;
      last_i[j] = t[i];
    }
    while (j + sqrtn - 1 <= r[i]) {
      s64 add = (t[i] - last_b[j / sqrtn]) * sqrtn - sub_b[j / sqrtn];
      sum += add;
      last_b[j / sqrtn] = t[i];
      sub_b[j / sqrtn] = 0;
      j += sqrtn;
    }
    for (; j <= r[i]; ++j) {
      s64 last = max(last_i[j], last_b[j / sqrtn]);
      s64 add = t[i] - last;
      sum += add;
      sub_b[j / sqrtn] += add;
      last_i[j] = t[i];
    }
  }
  cout << sum << endl;
}