#include "util/common.h"

int main() {
  const size_t num_case = 10;
  for (size_t i = 0; i < num_case; ++i) {
    const string fname_in = format("tests/sample_generated_{}.in", i);
    const string fname_out = format("tests/sample_generated_{}.out", i);
    ofstream fin(fname_in), fout(fname_out);

    random_device seed_gen;
    mt19937 engine(seed_gen());
    uniform_int_distribution<int32_t> dista(0, 5), distb(-10, 10);

    const size_t n = 5;

    fin << n << endl;
    vector<pair<int32_t, int32_t>> abs(n);
    for (size_t j = 0; j < n; ++j) {
      abs[j] = make_pair(dista(engine), distb(engine));
      fin << abs[j].first << " " << abs[j].second << endl;
    }

    int32_t ans = 0;
    for (size_t mask = 0; mask < (1 << n); ++mask) {
      int32_t cnt = 0;
      int32_t suma = 0;
      int32_t sumb = 0;
      for (size_t j = 0; j < n; ++j) {
        if (!(mask & 1 << j)) continue;
        ++cnt;
        suma += abs[j].first;
        sumb += abs[j].second;
      }
      if (suma - cnt >= 0) {
        ans = max(ans, sumb);
      }
    }

    fout << ans << endl;
  }
}