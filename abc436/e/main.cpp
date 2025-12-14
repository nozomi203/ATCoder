
#include "util/common.h"

/*
iからiに本来あるべき数がある場所jに対して辺を貼る。
この時、グラフ全体はサイクルの集合となる。
理由
各場所の次数は2であるため。
同じサイクルの中で入れ替えを行うとサイクルの数が1つ増える。
サイクルの数がnになった＝＝整列が終わった。
同じサイクルの要素間での交換を、サイクルの数がnになるまで繰り替えるのが最短
したがって、1回目の操作としては同じサイクルの中から2つの要素を選ぶ場合の数を数えればいい
*/

int main() {
  s64 n;
  cin >> n;
  vector<s64> ps(n);
  util::cin(ps);

  vector<s64> cycles;
  vector<s64> idxs(n, -1);
  for (s64 i = 0; i < n; ++i) {
    if (idxs[i] != -1) continue;
    const s64 idx = cycles.size();
    s64 cnt = 0;
    s64 q = i;
    do {
      q = ps[q] - 1;
      ++cnt;
      idxs[q] = idx;
    } while (q != i);
    cycles.push_back(cnt);
  }

  s64 ans = 0;
  for (s64 cnt : cycles) {
    ans += cnt * (cnt - 1) / 2;
  }
  cout << ans << endl;
}