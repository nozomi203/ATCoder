#include "util/common.h"

int main() {
  random_device dev;
  mt19937 engine(dev());
  uniform_int_distribution<int> distnm(1, 4);

  for (s64 t = 0; t < 10; ++t) {
    const int n = distnm(engine);
    const int m = distnm(engine);
    vector<int> as(n * m);
    iota(as.begin(), as.end(), 1);
    shuffle(as.begin(), as.end(), engine);

    vector<int> xs(n), ys(m);
    for (s64 i = 0; i < n; ++i) {
      for (s64 j = 0; j < n; ++j) {
        const s64 idx = i * m + j;
        xs[i] = max(xs[i], as[idx]);
        ys[j] = max(ys[j], as[idx]);
      }
    }

    auto ofin = ofstream(format("./test/sample_generated_{}.in", t));
    auto ofout = ofstream(format("./test/sample_generated_{}.out", t));
    ofin << endl;
    ofin << n << " " << m << endl;
    for (s64 i = 0; i < n; ++i) {
      ofin << xs[i];
      if (i < n - 1) ofin << " ";
    }
    ofin << endl;
    for (s64 i = 0; i < m; ++i) {
      ofin << ys[i];
      if (i < m - 1) ofin << " ";
    }
    ofin << endl;
  }
}