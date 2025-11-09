#include <atcoder/lazysegtree>

#include "util/common.h"

int main() {
  s64 q;
  cin >> q;

  vector<tuple<s64, s64, s64>> queries(q);
  for (auto& [q0, q1, q2] : queries) {
    cin >> q0;
    if (q0 == 1) {
      cin >> q1;
    } else {
      cin >> q1 >> q2;
    }
  }

  vector<s64> nxts(q + 1, -1);
  for (s64 i = 0; i < q; ++i) {
    auto [q0, q1, q2] = queries[i];
    if (q0 == 1) {
      if (nxts[q1] == -1) {
        nxts[q1] = i + 1;
      } else {
        nxts[i + 1] = nxts[q1];
        nxts[q1] = i + 1;
      }
    } else {
      s64 i1 = nxts[q1];
      s64 i2 = nxts[q2];
      s64 sum1 = 0;
      s64 sum2 = 0;
      while (i1 != q2 && i2 != q1) {
        if (i1 != -1) {
          sum1 += i1;
          i1 = nxts[i1];
        }
        if (i2 != -1) {
          sum2 += i2;
          i2 = nxts[i2];
        }
      }

      if (i1 == q2) {
        cout << sum1 << endl;
        nxts[q1] = q2;
      } else {
        cout << sum2 << endl;
        nxts[q2] = q1;
      }
    }
  }
}