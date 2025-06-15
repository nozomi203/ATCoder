#include "util/common.h"

void solve(s64 h, s64 w, const vector<string>& ss) {
  assert(h <= w);
  vector<size_t> cnts(w * h * 2 + 1, 0);
  const auto offset = w * h;
  size_t ans{0};
  for (size_t i{0}; i < h; ++i) {
    vector<s64> c(w, 0);
    for (size_t j{i}; j < h; ++j) {
      for (size_t k{0}; k < w; ++k) {
        ss[j][k] == '#' ? ++c[k] : --c[k];
      }

      cnts[offset] = 1;
      s64 sc{0};
      for (size_t k{0}; k < w; ++k) {
        sc += c[k];
        ans += cnts[offset + sc];
        ++cnts[offset + sc];
      }
      cnts[offset] = 0;
      sc = 0;
      for (size_t k{0}; k < w; ++k) {
        sc += c[k];
        cnts[offset + sc] = 0;
      }
    }
  }

  cout << ans << endl;
}

int main() {
  size_t t;
  cin >> t;
  vector<tuple<s64, s64, vector<string>>> cases(t);
  for (auto& [h, w, ss] : cases) {
    cin >> h >> w;
    ss.resize(h);
    for (s64 i{0}; i < h; ++i) cin >> ss[i];
    if (h > w) {
      vector<string> tmp(w, string(h, 'x'));
      for (size_t i{0}; i < h; ++i) {
        for (size_t j{0}; j < w; ++j) {
          tmp[j][i] = ss[i][j];
        }
      }
      swap(h, w);
      swap(ss, tmp);
    }
  }

  for (const auto& [h, w, ss] : cases) solve(h, w, ss);
}
