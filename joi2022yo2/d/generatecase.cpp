#include "util/common.h"

int main() {
  const size_t num_case = 10;
  for (size_t i = 0; i < num_case; ++i) {
    const string fname_in = format("tests/sample_random_{}.in", i);
    const string fname_out = format("tests/sample_random_{}.out", i);
    ofstream ofin(fname_in), ofout(fname_out);

    const size_t n = 10;

    random_device dev;
    mt19937 mt(dev());
    uniform_int_distribution<size_t> distk(2, 10), dista(1, 10);

    const size_t k = distk(mt);

    ofin << n << " " << k << endl;

    vector<size_t> as(n);
    for (size_t j = 0; j < n; ++j) {
      as[j] = dista(mt);
      ofin << as[j];
      if (j < n - 1) ofin << " ";
    }
    ofin << endl;

    size_t ans = 0;
    for (size_t mask = 0; mask < (1 << n); ++mask) {
      bool valid = true;
      for (size_t j = 0; j <= n - k; ++j) {
        size_t cnt = 0;
        for (size_t l = 0; l < k; ++l)
          if (mask & (1 << (j + l))) ++cnt;

        if (cnt > 2) {
          valid = false;
          break;
        }
      }
      if (valid) {
        size_t sum = 0;
        for (size_t j = 0; j < n; ++j)
          if (mask & (1 << j)) sum += as[j];

        ans = max(ans, sum);
      }
    }

    ofout << ans << endl;
  }
}