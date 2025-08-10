#include "util/common.h"

int main() {
  random_device dev;
  mt19937 mt(dev());

  for (size_t i = 0; i < 10; ++i) {
    const string fnin = format("tests/sample_generated_{}.in", i);
    const string fnout = format("tests/sample_generated_{}.out", i);
    ofstream ofin(fnin), ofout(fnout);

    const size_t n = 10;
    const size_t m = 3;
    uniform_int_distribution<size_t> distpq(1, n);
    size_t p = distpq(mt), q = distpq(mt);
    if (p > q) swap(p, q);
    size_t r = distpq(mt);

    vector<pair<size_t, size_t>> xys(m);
    uniform_int_distribution<size_t> distx(1, n - 2);
    for (size_t j = 0; j < m; ++j) {
      const size_t x = distx(mt);
      uniform_int_distribution<size_t> disty(x + 1, n - 1);
      const size_t y = disty(mt);
      xys[j] = make_pair(x, y);
    }

    ofin << n << endl;
    ofin << m << endl;
    ofin << p << " " << q << " " << r << endl;
    for (size_t j = 0; j < m; ++j) {
      ofin << xys[j].first << " " << xys[j].second << endl;
    }

    vector<size_t> vs(n);
    iota(vs.begin(), vs.end(), 1);
    for (auto [x, y] : xys) {
      --x;
      --y;
      vector<size_t> tmp;
      tmp.reserve(n);
      for (size_t j = y + 1; j < n; ++j) tmp.push_back(vs[j]);
      for (size_t j = x + 1; j <= y; ++j) tmp.push_back(vs[j]);
      for (size_t j = 0; j <= x; ++j) tmp.push_back(vs[j]);
      swap(tmp, vs);
    }

    size_t cnt = 0;
    for (size_t i = p - 1; i < q; ++i)
      if (vs[i] <= r) ++cnt;

    ofout << cnt << endl;
  }
}