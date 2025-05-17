#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

template <typename Tuple, std::size_t... I>
void cin_tuple_impl(Tuple& t, std::index_sequence<I...>) {
  ((std::cin >> std::get<I>(t)), ...);
}

template <typename... Ts>
void cin_tuple(tuple<Ts...>& t) {
  cin_tuple_impl(t, index_sequence_for<Ts...>{});
}
#line 2 "main.cpp"

int main() {
  s64 h, w, n;
  cin >> h >> w >> n;
  vector<set<s64>> xs(w + 1), ys(h + 1);
  for (s64 i{0}; i < n; ++i) {
    s64 x, y;
    cin >> x >> y;
    xs[y].emplace(x);
    ys[x].emplace(y);
  }
  s64 q;
  cin >> q;
  vector<pair<s64, s64>> queries(q);
  for (s64 i{0}; i < q; ++i) cin >> queries[i].first >> queries[i].second;

  for (auto [q1, q2] : queries) {
    if (q1 == 1) {
      cout << ys[q2].size() << endl;
      for (auto y : ys[q2]) {
        xs[y].erase(q2);
      }
      ys[q2].clear();
    } else {
      cout << xs[q2].size() << endl;
      for (auto x : xs[q2]) {
        ys[x].erase(q2);
      }
      xs[q2].clear();
    }
  }
}
