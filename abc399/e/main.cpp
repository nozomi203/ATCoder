#include <atcoder/dsu>

#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  const auto get = [&]() -> s64 {
    vector<s64> to(26, -1);
    for (s64 i{0}; i < n; ++i) {
      s64 src_idx = s[i] - 'a';
      s64 dst_idx = t[i] - 'a';
      if (to[src_idx] < 0) {
        to[src_idx] = dst_idx;
      } else {
        if (to[src_idx] != dst_idx) return -1;
      }
    }

    atcoder::dsu dsu(26);
    for (s64 i{0}; i < 26; ++i) {
      dsu.merge()
    }
  };

  cout << get() << endl;
}