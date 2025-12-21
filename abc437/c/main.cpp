#include "util/common.h"

/*
最初全トナカイのせとく
P - W >
0となればいいから、Pをふやし、Wを減らさなければならない。これへの寄与が大きいものからおろしていく
Pi, Wi をおろしたとき、寄与はP + W.P+Wがおおきいものからおろす


*/
int main() {
  s64 t;
  cin >> t;
  vector<pair<s64, vector<pair<s64, s64>>>> cases(t);
  for (auto& [n, wps] : cases) {
    cin >> n;
    wps.resize(n);
    util::cin(wps);
  }

  for (auto& [n, wps] : cases) {
    sort(wps.begin(), wps.end(), [](auto lhs, auto rhs) {
      return lhs.first + lhs.second > rhs.first + rhs.second;
    });
    s64 sum = 0;
    for (auto [w, p] : wps) {
      sum -= w;
    }
    s64 cnt = n;
    for (auto [w, p] : wps) {
      if (sum >= 0) break;
      sum += p + w;
      --cnt;
    }
    cout << cnt << endl;
  }
}