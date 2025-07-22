#include "util/common.h"
#include "util/run_length_encoding.h"

/*
大きい額縁から順に、価値順に並べた絵を価値が高い順に見たときに額縁に入る最初の絵を
greedyに入れるのが最善？
額縁xに入る最初の絵aに対して、それより左にある絵bが実は最善だとする
その場合bをxに入れてbより左の絵をxより左の額縁に当てはめることになるが、
これはaをxに入れてbより左の絵をxより左の額縁にはてはめることとおなじ。
10 8 7
8 8 10
*/
int main() {
  size_t n, m;
  cin >> n >> m;
  vector<pair<size_t, size_t>> svs(n);
  util::cin(svs);
  vector<size_t> cs(m);
  util::cin(cs);

  sort(svs.begin(), svs.end(), [](const auto& l, const auto& r) {
    if (l.second != r.second) {
      return l.second > r.second;
    } else {
      return l.first > r.first;
    }
  });
  sort(cs.begin(), cs.end(), greater());

  size_t cnt = 0;
  for (size_t i = 0; i < n; ++i) {
    if (svs[i].first <= cs[cnt]) {
      if (++cnt == m) break;
    }
  }

  cout << cnt << endl;
}