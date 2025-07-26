#include "util/common.h"

int main() {
  size_t h, w;
  cin >> h >> w;
  vector<vector<size_t>> ass(h, vector<size_t>(w));
  util::cin(ass);
  for (size_t i = 1; i < h; ++i) {
    for (size_t j = 0; j < w; ++j) {
      ass[i][j] += ass[i - 1][j];
    }
  }
  for (size_t j = 1; j < w; ++j) {
    for (size_t i = 0; i < h; ++i) {
      ass[i][j] += ass[i][j - 1];
    }
  }

  size_t cnt = 0;
  for (size_t i = 0; i < h; ++i) {
    const size_t sum = ass[i][w - 1];
    vector<size_t> xs;
    for (size_t j = i; j < h; ++j) {
      if (ass[j][w - 1] == sum * (xs.size() + 1)) xs.push_back(j);
    }
    if (xs.back() != h - 1) continue;

    const auto check = [&](size_t j) -> bool {
      const size_t sum2 = ass[i][j];
      vector<size_t> ys;
      for (size_t k = j; k < w; ++k) {
        bool valid = true;
        for (size_t l = 0; l < xs.size(); ++l) {
          const size_t value = sum2 * (l + 1) * (ys.size() + 1);
          if (ass[xs[l]][k] != value) {
            valid = false;
            break;
          }
        }
        if (valid) ys.push_back(k);
      }
      if (ys.empty()) return false;
      if (ys.back() != w - 1) return false;
      if (xs.size() == 1 && ys.size() == 1) return false;
      return true;
    };

    for (size_t j = 0; j < w; ++j) {
      if (check(j)) {
        ++cnt;
      }
    }
  }
  cout << cnt << endl;
}