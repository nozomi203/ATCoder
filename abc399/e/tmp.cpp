#line 1 "main.cpp"
#include <atcoder/dsu>

#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 4 "main.cpp"

int main() {
  s64 n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  const auto get = [&]() -> s64 {
    map<char, char> table;  // replace table
    for (s64 i{0}; i < n; ++i) {
      char src = s[i];
      char dst = t[i];
      if (table.count(src)) {
        if (table[src] != dst) return -1;
      } else {
        table[src] = dst;
      }
    }

    const s64 rem = 26 - table.size();
    for (auto it = table.begin(); it != table.end();) {
      auto [src, dst] = *it;
      if (src == dst) {
        it = table.erase(it);
      } else {
        ++it;
      }
    }

    vector<pair<s64, s64>> loops;
    atcoder::dsu dsu(26);
    for (auto [src, dst] : table) {
      s64 src_idx{src - 'a'};
      s64 dst_idx{dst - 'a'};
      if (dsu.leader(src_idx) == dsu.leader(dst_idx))
        loops.push_back(make_pair(src_idx, dst_idx));
      dsu.merge(src_idx, dst_idx);
    }
    map<s64, s64> num_loop_per_group;
    for (auto [src_idx, dst_idx] : loops) {
      assert(dsu.leader(src_idx) == dsu.leader(dst_idx));
      num_loop_per_group[dsu.leader(src_idx)]++;
    }
    for (auto [leader, num_loop] : num_loop_per_group) {
      if (num_loop > rem) return -1;
    }
    return table.size() + loops.size();
  };

  cout << get() << endl;
}
