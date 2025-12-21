#include <atcoder/dsu>

#include "util/common.h"

int main() {
  s64 n, q;
  cin >> n >> q;
  vector<tuple<s64, s64, s64>> queries(q);
  for (auto& [q0, q1, q2] : queries) {
    cin >> q0;
    if (q0 == 1) {
      cin >> q1 >> q2;
    } else {
      cin >> q1;
    }
  }
  vector<bool> bs(n + 1);
  vector<s64> cnts(n + 1);
  atcoder::dsu uf(n + 1);
  for (auto [q0, q1, q2] : queries) {
    if (q0 == 1) {
      auto p1 = uf.leader(q1);
      auto p2 = uf.leader(q2);
      if (p1 != p2) {
        auto p = uf.merge(q1, q2);
        if (p == p1) {
          cnts[p1] += cnts[p2];
          cnts[p2] = 0;
        } else {
          cnts[p2] += cnts[p1];
          cnts[p1] = 0;
        }
      }
    } else if (q0 == 2) {
      bs[q1] = !bs[q1];
      if (bs[q1]) {
        ++cnts[uf.leader(q1)];
      } else {
        --cnts[uf.leader(q1)];
      }
    } else {
      cout << (cnts[uf.leader(q1)] > 0 ? "Yes" : "No") << endl;
    }
  }
}