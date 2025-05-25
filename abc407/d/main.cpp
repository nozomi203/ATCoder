#include "util/common.h"

int main() {
  u64 h, w;
  cin >> h >> w;
  vector<vector<u64>> a(h, vector<u64>(w));
  for (u64 i{0}; i < h; ++i) {
    for (u64 j{0}; j < w; ++j) {
      cin >> a[i][j];
    }
  }
  vector<pair<s64, s64>> hors;
  for (u64 i{0}; i < h; ++i) {
    for (u64 j{0}; j < w - 1; ++j) {
      hors.push_back(make_pair(i, j));
    }
  }

  u64 valmax{0};
  const u64 bhm = (1ULL << hors.size());
  for (u64 bh{0}; bh < bhm; ++bh) {
    vector<vector<bool>> fill(h, vector<bool>(w));
    bool invalid_h{false};
    for (size_t i{0}; i < hors.size(); ++i) {
      if (!(bh & (1ULL << i))) continue;
      if (fill[hors[i].first][hors[i].second]) {
        invalid_h = true;
        break;
      }
      fill[hors[i].first][hors[i].second] =
          fill[hors[i].first][hors[i].second + 1] = true;
    }
    if (invalid_h) {
      continue;
    }

    vector<pair<u64, u64>> vers;
    for (u64 j{0}; j < w; ++j) {
      for (u64 i{0}; i < h - 1; ++i) {
        if (fill[i][j] || fill[i + 1][j]) continue;
        vers.push_back(make_pair(i, j));
      }
    }
    const u64 bvm{1ULL << vers.size()};
    for (u64 bv{0}; bv < bvm; ++bv) {
      bool invalid_v{false};
      for (size_t i{1}; i < vers.size(); ++i) {
        if (!(bv & (1ULL << i))) continue;

        if ((bv & (1ULL << (i - 1))) &&
            vers[i - 1].first == vers[i].first - 1 &&
            vers[i - 1].second == vers[i].second) {
          invalid_v = true;
          break;
        }
      }
      if (invalid_v) {
        continue;
      } else {
        for (size_t i{0}; i < vers.size(); ++i) {
          if (!(bv & (1ULL << i))) continue;
          fill[vers[i].first][vers[i].second] =
              fill[vers[i].first + 1][vers[i].second] = true;
        }

        u64 val{0};
        for (u64 i{0}; i < h; ++i) {
          for (u64 j{0}; j < w; ++j) {
            if (!fill[i][j]) val ^= a[i][j];
          }
        }
        valmax = max(valmax, val);

        for (size_t i{0}; i < vers.size(); ++i) {
          if (!(bv & (1ULL << i))) continue;
          fill[vers[i].first][vers[i].second] =
              fill[vers[i].first + 1][vers[i].second] = false;
        }
      }
    }
  }
  cout << valmax << endl;
}