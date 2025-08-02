#include "util/common.h"

/*
幸福度の高い紅茶から順に同じブランドのケーキのうち幸福度の高いものから順にあてがう。
同じブランドのケーキが無かった場合は一旦架空のブランドの幸福度0のケーキをあてがう
あてがい終わったら、残ったケーキを幸福度の高い順に置き換えようとする。
あてがう先は、幸福度の小さい方から確認する
置き換えができなくなったら、それ以上先を見ても意味がない。交換の可能性があるのは、ブランドが違うが幸福度めちゃ高なケーキ
 */

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> bas(n), dcs(m);
  for (auto& [b, a] : bas) cin >> a;
  for (auto& [b, a] : bas) cin >> b;
  for (auto& [d, c] : dcs) cin >> c;
  for (auto& [d, c] : dcs) cin >> d;

  sort(bas.begin(), bas.end(), greater());
  sort(dcs.begin(), dcs.end(), greater());

  vector<queue<s64>> bss(n + 1);
  for (auto [b, a] : bas) bss[a].push(b);

  priority_queue<s64, vector<s64>, greater<s64>> sels;
  for (auto [d, c] : dcs) {
    if (!bss[c].empty()) {
      sels.push(d + bss[c].front());
      bss[c].pop();
    }
  }

  priority_queue<s64> rembs;
  for (auto& bs : bss) {
    while (!bs.empty()) {
      rembs.push(bs.front());
      bs.pop();
    }
  }

  s64 ans = 0;
  for (s64 i = 0; i < m - sels.size(); ++i) {
    ans += rembs.top();
    rembs.pop();
  }

  while (!sels.empty()) {
    if (!rembs.empty() && sels.top() < rembs.top()) {
      ans += rembs.top();
      rembs.pop();
      sels.pop();
    } else {
      ans += sels.top();
      sels.pop();
    }
  }

  cout << ans << endl;
}