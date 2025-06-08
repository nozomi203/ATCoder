#include <atcoder/dsu>

#include "util/common.h"

using pos = pair<int64_t, int64_t>;

int64_t dist(const pos& p0, const pos& p1) {
  return abs(p0.first - p1.first) + abs(p0.second - p1.second);
}

int main() {
  size_t n, q;
  cin >> n >> q;
  vector<pos> xys(n);
  for (size_t i{0}; i < n; ++i) cin_pair(xys[i]);

  size_t cnt1{0};
  vector<tuple<size_t, int64_t, int64_t>> queries(q);
  for (size_t i{0}; i < q; ++i) {
    size_t a;
    cin >> a;
    get<0>(queries[i]) = a;
    if (a == 1) {
      ++cnt1;
      size_t b, c;
      cin >> b >> c;
      get<1>(queries[i]) = b;
      get<2>(queries[i]) = c;
    } else if (a == 2) {
    } else {
      cin >> get<1>(queries[i]) >> get<2>(queries[i]);
    }
  }

  using elem = tuple<size_t, size_t, size_t>;
  priority_queue<elem, vector<elem>, greater<elem>> dists;
  for (size_t i{0}; i < n - 1; ++i) {
    for (size_t j{i + 1}; j < n; ++j) {
      dists.push(make_tuple(dist(xys[i], xys[j]), i, j));
    }
  }

  atcoder::dsu dsu(n + cnt1);

  size_t num_group{n};
  for (auto [a, b, c] : queries) {
    if (a == 1) {
      for (size_t i{0}; i < n; ++i) {
        dists.push(make_tuple(dist(xys[i], make_pair(b, c)), i, n));
      }
      xys.push_back(make_pair(b, c));
      ++n;
      ++num_group;
    } else if (a == 2) {
      if (num_group == 1) {
        cout << -1 << endl;
      } else {
        while (!dists.empty()) {
          auto [d, u, v] = dists.top();
          if (!dsu.same(u, v)) break;
          dists.pop();
        }
        size_t k{get<0>(dists.top())};
        while (!dists.empty()) {
          auto [d, u, v] = dists.top();
          if (d > k) break;
          if (!dsu.same(u, v)) {
            --num_group;
            dsu.merge(u, v);
          }
          dists.pop();
        }
        cout << k << endl;
      }
    } else {
      cout << (dsu.same(b - 1, c - 1) ? "Yes" : "No") << endl;
    }
  }
}