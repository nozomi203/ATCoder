#include "util/common.h"

int main() {
  size_t m, k;
  cin >> m >> k;
  using elem_t = pair<size_t, size_t>;

  struct functor {
    bool operator()(const elem_t& l, const elem_t& r) {
      return l.first * r.second > r.first * l.second;
    }
  };

  priority_queue<elem_t, vector<elem_t>, functor> pq;

  for (size_t i = 2; i <= m; ++i) pq.push(make_pair(1, i));
  while (!pq.empty()) {
    auto [numer, denom] = pq.top();
    pq.pop();
    if (gcd(numer, denom) == 1) {
      if (--k == 0) {
        cout << numer << " " << denom << endl;
        return 0;
      }
    }
    if (numer + 1 < denom) pq.push(make_pair(numer + 1, denom));
  }

  cout << -1 << endl;
}