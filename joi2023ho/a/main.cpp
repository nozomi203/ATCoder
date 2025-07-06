#include "util/common.h"
/*
1
1 2
1 2 3
1 2 3 2
1 2 2 2
1 2 2 2 3
1 2 2 2 3 4
*/
int main() {
  s64 n;
  cin >> n;
  vector<s64> as(n);
  util::cin(as);

  using work = tuple<s64, s64>;  // value, count
  vector<work> ws;
  ws.reserve(n);
  set<s64> s;
  for (auto a : as) {
    if (s.contains(a)) {
      s64 sum = 1;
      while (true) {
        auto& [v, cnt] = ws.back();
        if (v == a) {
          cnt += sum;
          break;
        } else {
          sum += cnt;
          s.erase(v);
          ws.pop_back();
        }
      }
    } else {
      s.emplace(a);
      ws.push_back(make_tuple(a, 1));
    }
  }

  for (auto [v, cnt] : ws) {
    for (s64 i = 0; i < cnt; ++i) cout << v << endl;
  }
}