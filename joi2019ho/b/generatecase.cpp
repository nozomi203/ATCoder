#include "util/common.h"

int main() {
  const size_t num_case = 10;
  for (size_t i = 0; i < num_case; ++i) {
    const string fname_in = format("tests/sample_random_{}.in", i);
    const string fname_out = format("tests/sample_random_{}.out", i);
    ofstream ofin(fname_in), ofout(fname_out);

    const size_t n = 5;
    const size_t m = 5;

    random_device dev;
    mt19937 mt(dev());

    uniform_int_distribution<size_t> dist_svc(1, 10);

    ofin << n << " " << m << endl;

    vector<pair<size_t, size_t>> svs(n);
    for (size_t j = 0; j < n; ++j) {
      auto& [s, v] = svs[j];
      s = dist_svc(mt);
      v = dist_svc(mt);
      ofin << s << " " << v << endl;
    }

    vector<size_t> cs(m);
    for (size_t j = 0; j < m; ++j) {
      auto& c = cs[j];
      c = dist_svc(mt);
      ofin << c << endl;
    }

    sort(svs.begin(), svs.end(),
         [](const auto& l, const auto& r) { return l.second < r.second; });
    sort(cs.begin(), cs.end());

    size_t ans = 0;
    for (size_t mask = 0; mask < (1 << n); ++mask) {
      vector<size_t> tmp;
      for (size_t j = 0; j < n; ++j) {
        if (!(mask & (1 << j))) continue;
        tmp.push_back(svs[j].first);
      }
      if (tmp.size() > m) continue;

      bool valid = true;
      for (s64 j = 0; j < tmp.size(); ++j) {
        if (cs[m - 1 - j] < tmp[tmp.size() - 1 - j]) {
          valid = false;
          break;
        }
      }
      if (valid) {
        ans = max(ans, tmp.size());
      }
    }

    ofout << ans << endl;
  }
}