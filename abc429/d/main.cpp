#include "util/common.h"

int main() {
  s64 n, m, c;
  cin >> n >> m >> c;
  vector<s64> as(n);
  util::cin(as);

  map<s64, s64> cnts;
  cnts[0] = 0;
  cnts[m] = 0;
  for (auto a : as) ++cnts[a == 0 ? m : a];
  const s64 np = cnts.size();
  vector<pair<s64, s64>> sumcnts;
  sumcnts.reserve(np * 2);
  for (s64 i = 0; i < 2; ++i) {
    for (auto [pos, cnt] : cnts) sumcnts.push_back(make_pair(cnt, pos + m * i));
  }
  for (s64 i = 1; i < sumcnts.size(); ++i) {
    sumcnts[i].first += sumcnts[i - 1].first;
  }

  s64 ans = 0;
  for (s64 i = 0; i < np; ++i) {
    // iの直前からスタートするときのことを考える
    auto [pcnt, ppos] = i > 0 ? sumcnts[i - 1] : make_pair<s64, s64>(0, 0);
    auto [scnt, spos] = sumcnts[i];
    // iの直前の個数
    const s64 numpos = spos - ppos;

    auto it = lower_bound(sumcnts.begin(), sumcnts.end(),
                          make_pair<s64, s64>(c + pcnt, 0));
    assert(it != sumcnts.end());
    auto [gcnt, gpos] = *it;
    ans += (gcnt - pcnt) * numpos;
  }
  cout << ans << endl;
}