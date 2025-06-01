#include <atcoder/maxflow>

#include "util/common.h"

int main() {
  size_t n;
  cin >> n;
  vector<tuple<size_t, size_t, size_t>> xyzs(n);
  for (size_t i{0}; i < n; ++i) cin_tuple(xyzs[i]);

  map<size_t, size_t> m;
  for (auto [x, y, z] : xyzs) {
    for (size_t i{1}; i < x; ++i) m.emplace(i * y * z, 0);
    for (size_t i{1}; i < y; ++i) m.emplace(i * z * x, 0);
    for (size_t i{1}; i < z; ++i) m.emplace(i * x * y, 0);
  }
  size_t idx{0};
  for (auto& [k, v] : m) {
    v = idx;
    ++idx;
  }

  size_t cnt{0};
  size_t cnt2{0};
  cnt += 1;
  cnt += 1;
  cnt += n;
  for (auto [x, y, z] : xyzs) {
    cnt2 += x - 1;
    cnt2 += y - 1;
    cnt2 += z - 1;
    cnt += cnt2;
  }
  cnt += m.size();
  cnt += 1;

  size_t cap_l{0};
  size_t cap_r{2 * m.size()};
  while (cap_r - cap_l > 1) {
    const size_t cap_m{(cap_r + cap_l) / 2};
    constexpr size_t inf = 100000000;
    atcoder::mf_graph<size_t> mfg(cnt);
    mfg.add_edge(0, 1, 2 * cap_m);

    size_t idx{n + 2};
    for (size_t i{0}; i < n; ++i) {
      mfg.add_edge(1, i + 2, inf);
      const auto [x, y, z] = xyzs[i];
      for (size_t j{1}; j < x; ++j) {
        mfg.add_edge(i + 2, idx, 2);
        mfg.add_edge(idx, 2 + n + cnt2 + m.at(j * y * z), 1);
        mfg.add_edge(idx, 2 + n + cnt2 + m.at((x - j) * y * z), 1);
        ++idx;
      }
      for (size_t j{1}; j < y; ++j) {
        mfg.add_edge(i + 2, idx, 2);
        mfg.add_edge(idx, 2 + n + cnt2 + m.at(x * j * z), 1);
        mfg.add_edge(idx, 2 + n + cnt2 + m.at(x * (y - j) * z), 1);
        ++idx;
      }
      for (size_t j{1}; j < z; ++j) {
        mfg.add_edge(i + 2, idx, 2);
        mfg.add_edge(idx, 2 + n + cnt2 + m.at(x * y * j), 1);
        mfg.add_edge(idx, 2 + n + cnt2 + m.at(x * y * (z - j)), 1);
        ++idx;
      }
    }
    for (const auto& [k, v] : m) {
      mfg.add_edge(2 + n + cnt2 + v, cnt - 1, 2);
    }

    if (mfg.flow(0, cnt - 1) == 2 * m.size()) {
      cap_r = cap_m;
    } else {
      cap_l = cap_m;
    }
  }

  cout << cap_r << endl;
}