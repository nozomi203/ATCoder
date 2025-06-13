#include "util/common.h"

int main() {
  size_t n, m, x;
  cin >> n >> m >> x;
  vector<int32_t> ts(n);
  for (size_t i{0}; i < n; ++i) cin >> ts[i];
  vector<tuple<int32_t, int32_t, int32_t>> abds(m);
  for (size_t i{0}; i < m; ++i) cin_tuple(abds[i]);
  vector<vector<pair<int32_t, int32_t>>> g(n * (2 * x + 1));

  const auto get_idx = [&](int32_t i, int32_t t, int32_t xrem) -> int32_t {
    return (2 * x + 1) * i + xrem + (t == 2 ? x : 0);
  };

  const auto add_edge = [&](int32_t from, int32_t to, int32_t d) {
    if (ts[from] == 0) {
      if (ts[to] == 0) {
        g[get_idx(from, 0, x)].push_back(make_pair(d, get_idx(to, 0, x)));
      } else if (ts[to] == 1) {
        if (d >= x) {
          g[get_idx(from, 0, x)].push_back(make_pair(d, get_idx(to, 1, 0)));
        } else {
          g[get_idx(from, 0, x)].push_back(make_pair(d, get_idx(to, 0, x - d)));
        }
      } else {
        if (d >= x)
          g[get_idx(from, 0, x)].push_back(make_pair(d, get_idx(to, 2, x)));
      }
    } else if (ts[from] == 1) {
      if (ts[to] == 0) {
        g[get_idx(from, 1, 0)].push_back(make_pair(d, get_idx(to, 0, x)));
        for (int32_t xrem{1}; xrem <= x; ++xrem) {
          g[get_idx(from, 0, xrem)].push_back(make_pair(d, get_idx(to, 0, x)));
          if (xrem <= d) {
            g[get_idx(from, 2, xrem)].push_back(
                make_pair(d, get_idx(to, 0, x)));
          }
        }
      } else if (ts[to] == 1) {
        g[get_idx(from, 1, 0)].push_back(make_pair(d, get_idx(to, 1, 0)));
        for (int32_t xrem{1}; xrem <= x; ++xrem) {
          if (xrem <= d) {
            g[get_idx(from, 0, xrem)].push_back(
                make_pair(d, get_idx(to, 1, 0)));
            g[get_idx(from, 2, xrem)].push_back(
                make_pair(d, get_idx(to, 1, 0)));
          } else {
            g[get_idx(from, 0, xrem)].push_back(
                make_pair(d, get_idx(to, 0, xrem - d)));
            g[get_idx(from, 2, xrem)].push_back(
                make_pair(d, get_idx(to, 2, xrem - d)));
          }
        }
      } else {
        g[get_idx(from, 1, 0)].push_back(make_pair(d, get_idx(to, 2, x)));
        for (int32_t xrem{1}; xrem <= x; ++xrem) {
          g[get_idx(from, 2, xrem)].push_back(make_pair(d, get_idx(to, 2, x)));
          if (xrem <= d) {
            g[get_idx(from, 0, xrem)].push_back(
                make_pair(d, get_idx(to, 2, x)));
          }
        }
      }
    } else {
      if (ts[to] == 0) {
        if (d >= x)
          g[get_idx(from, 2, x)].push_back(make_pair(d, get_idx(to, 0, x)));
      } else if (ts[to] == 1) {
        if (d >= x) {
          g[get_idx(from, 2, x)].push_back(make_pair(d, get_idx(to, 1, 0)));
        } else {
          g[get_idx(from, 2, x)].push_back(make_pair(d, get_idx(to, 2, x - d)));
        }
      } else {
        g[get_idx(from, 2, x)].push_back(make_pair(d, get_idx(to, 2, x)));
      }
    }
  };

  for (auto& [a, b, d] : abds) {
    --a;
    --b;
    add_edge(a, b, d);
    add_edge(b, a, d);
  }

  using work = pair<int32_t, int32_t>;
  vector<int32_t> dists(n * (2 * x + 1), numeric_limits<int32_t>::max());
  priority_queue<work, vector<work>, greater<work>> works;
  works.push(make_pair(0, get_idx(0, 0, x)));
  while (!works.empty()) {
    auto [dist, idx] = works.top();
    works.pop();
    if (dist >= dists[idx]) continue;
    dists[idx] = dist;
    for (auto [d, nxt] : g[idx]) {
      if (dist + d >= dists[nxt]) continue;
      works.push(make_pair(dist + d, nxt));
    }
  }

  int32_t ans{numeric_limits<int32_t>::max()};
  for (size_t i{(2 * x + 1) * (n - 1)}; i < n * (2 * x + 1); ++i)
    ans = min(ans, dists[i]);

  cout << ans << endl;
}