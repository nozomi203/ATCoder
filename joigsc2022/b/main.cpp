#include "util/common.h"

/*
あるJにたどりついたとき、次に向かうOは右方向にある最も近いOか、左方向にある最も近いOのどちらか
なぜなら、それより遠いOに向かおうとしてもすでにOを通り過ぎてしまっているため。
Jの選択肢→2
Oの選択肢→4
Iの選択肢→8
Gの選択肢→16
これを総当たりする
*/

s64 toidx(char c) {
  switch (c) {
    case 'J':
      return 0;
    case 'O':
      return 1;
    case 'I':
      return 2;
    case 'G':
      return 3;
    default:
      assert(false);
      return -1;
  }
}

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, char>> acs(n);
  util::cin(acs);
  s64 q;
  cin >> q;
  vector<pair<s64, s64>> sts(q);
  util::cin(sts);

  vector<array<s64, 4>> dpl(n, {-1, -1, -1, -1}), dpr(n, {-1, -1, -1, -1});
  dpl[0][toidx(acs[0].second)] = 0;
  for (s64 i = 1; i < n; ++i) {
    for (s64 j = 0; j < 4; ++j) {
      dpl[i][j] = toidx(acs[i].second) == j ? i : dpl[i - 1][j];
    }
  }
  dpr[n - 1][toidx(acs[n - 1].second)] = n - 1;
  for (s64 i = n - 2; i >= 0; --i) {
    for (s64 j = 0; j < 4; ++j) {
      dpr[i][j] = toidx(acs[i].second) == j ? i : dpr[i + 1][j];
    }
  }

  for (auto [s, t] : sts) {
    array<set<s64>, 4> cands;
    auto it = lower_bound(acs.begin(), acs.end(), s,
                          [](const auto& ac, s64 s) { return ac.first < s; });
    if (it == acs.end()) {
      const auto idx = distance(acs.begin(), it - 1);
      cands[0].emplace(dpl[idx][0]);
    } else {
      const auto idx = distance(acs.begin(), it);
      if (acs[idx].first == s) {
        if (dpl[idx][0] >= 0) cands[0].emplace(dpl[idx][0]);
        if (dpr[idx][0] >= 0) cands[0].emplace(dpr[idx][0]);
      } else {
        if (idx > 0 && dpl[idx - 1][0] >= 0) cands[0].emplace(dpl[idx - 1][0]);
        if (dpr[idx][0] >= 0) cands[0].emplace(dpr[idx][0]);
      }
    }

    for (s64 i = 1; i < 4; ++i) {
      for (s64 j : cands[i - 1]) {
        if (dpr[j][i] >= 0) cands[i].emplace(dpr[j][i]);
        if (dpl[j][i] >= 0) cands[i].emplace(dpl[j][i]);
      }
    }

    s64 mindist = numeric_limits<s64>::max();
    for (auto c0 : cands[0]) {
      for (auto c1 : cands[1]) {
        for (auto c2 : cands[2]) {
          for (auto c3 : cands[3]) {
            s64 dist = 0;
            // assert(acs[c0].second == 'J');
            // assert(acs[c1].second == 'O');
            // assert(acs[c2].second == 'I');
            // assert(acs[c3].second == 'G');
            dist += abs(acs[c0].first - s);
            dist += abs(acs[c1].first - acs[c0].first);
            dist += abs(acs[c2].first - acs[c1].first);
            dist += abs(acs[c3].first - acs[c2].first);
            dist += abs(t - acs[c3].first);
            mindist = min(mindist, dist);
          }
        }
      }
    }
    cout << mindist << endl;
  }
}