#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> p(n), q(n), perm(n);
  for (s64 i{0}; i < n; ++i) cin >> p[i];
  for (s64 i{0}; i < n; ++i) cin >> q[i];
  s64 a{0}, b{0};
  s64 idx{0};
  iota(perm.begin(), perm.end(), 1);
  do {
    bool p_same{true};
    for (s64 i{0}; i < n; ++i) {
      if (perm[i] != p[i]) {
        p_same = false;
        break;
      }
    }
    if (p_same) a = idx;

    bool q_same{true};
    for (s64 i{0}; i < n; ++i) {
      if (perm[i] != q[i]) {
        q_same = false;
        break;
      }
    }
    if (q_same) b = idx;

    ++idx;
  } while (next_permutation(perm.begin(), perm.end()));

  cout << abs(a - b) << endl;
}