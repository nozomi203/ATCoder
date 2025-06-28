#include "util/common.h"

/*
場合分け
(1)現時点で上位1/12にいる
(2)いない

*/

int main() {
  size_t k, n, m;
  cin >> k >> n >> m;
  vector<size_t> ps(k);
  util::cin(ps);

  if (k == 1) {
    cout << 1 << endl;
    cout << "--------" << endl;
    cout << 1 << endl;
    return 0;
  }

  vector<pair<size_t, size_t>> pis(k);
  for (size_t i = 0; i < k; ++i) {
    pis[i].first = ps[i];
    pis[i].second = i;
  }
  sort(pis.begin(), pis.end(), greater());
  vector<size_t> ranks(k);
  {
    ranks[0] = 0;
    size_t cnt = 1;
    for (size_t i = 1; i < k; ++i) {
      if (pis[i - 1].first == pis[i].first) {
        ++cnt;
        ranks[i] = ranks[i - 1];
      } else {
        ranks[i] = ranks[i - 1] + cnt;
        cnt = 1;
      }
    }
  }

  size_t border = (k + 11) / 12;

  vector<size_t> as, bs;

  for (size_t i = 0; i < k; ++i) {
    auto [p, idx] = pis[i];
    auto rank = ranks[i];
    if (rank < border) {
      if (pis[rank].first >= pis[border].first + 100 * (n - m)) {
        as.push_back(idx);
      }
      bs.push_back(idx);
    } else {
      if (pis[rank].first + 100 * (n - m) >= pis[border - 1].first) {
        bs.push_back(idx);
      }
    }
  }

  sort(as.begin(), as.end());
  sort(bs.begin(), bs.end());
  for (auto a : as) cout << a + 1 << endl;
  cout << "--------" << endl;
  for (auto b : bs) cout << b + 1 << endl;
}